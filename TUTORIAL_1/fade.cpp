//=======================
//
//フェード処理:fade.cpp
//Author Kuramaesatoshi
//
//=======================
#include "fade.h"
#include "main.h"
#include "game.h"
#include"result.h"

//=======================
//マクロ定義
//=======================
#define FADECOLOR_A (1.0f)

//=======================
//グローバル変数
//=======================
LPDIRECT3DTEXTURE9 g_pTextureFade = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffFade = NULL;

FADE g_fade;
float g_colorFade;
MODE g_modeNext;

//==============================
//初期化処理
//==============================
void InitFade(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	g_fade = FADE_NONE;
	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "", &g_pTextureFade);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffFade, NULL);

	VERTEX_2D* pVtx;

	g_colorFade = 0.0f;

	//頂点バッファをロックし頂点データへのポインタを取得
	g_pVtxBuffFade->Lock(0, 0, (void**)&pVtx, 0);


	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);


	//頂点バッファをアンロックする
	g_pVtxBuffFade->Unlock();
}

//========================
//終了処理
//========================
void UninitFade(void)
{
	//テクスチャの破棄
	if (g_pTextureFade != NULL)
	{
		g_pTextureFade->Release();
		g_pTextureFade = NULL;
	}

	//頂点バッファの破棄
	if (g_pVtxBuffFade != NULL)
	{
		g_pVtxBuffFade->Release();
		g_pVtxBuffFade = NULL;
	}
}

//==============================
//更新処理
//==============================
void UpdateFade(void)
{
	VERTEX_2D* pVtx;
	//頂点バッファをロックし頂点データへのポインタを取得
	g_pVtxBuffFade->Lock(0, 0, (void**)&pVtx, 0);

	if (g_fade != FADE_NONE)
	{
		if (g_fade == FADE_IN)
		{//フェードイン状態
			g_colorFade += 0.08f;		//ポリゴンを透明にしていく

			if (g_colorFade > 1.0f)
			{
				g_colorFade = 1.0f;
				g_fade = FADE_OUT;		//何もしていない状態にする

				//モード設定
				SetMode(g_modeNext);
			}
		}
		else if (g_fade == FADE_OUT)
		{//フェードアウト状態
			g_colorFade -= 0.05f;

			if (g_colorFade < 0.0f)
			{
				g_colorFade = 0.0f;
				g_fade = FADE_NONE;
			}
		}
	}

	//頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorFade);
	pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorFade);
	pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorFade);
	pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorFade);

	//頂点バッファをアンロックする
	g_pVtxBuffFade->Unlock();
}

//==============================
//描画処理
//==============================
void DrawFade(void)
{
	if (g_fade == FADE_NONE)
	{
		return;
	}

	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffFade, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureFade);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//==============================
//Enterキーが押された時
//==============================
void SetFade(MODE modeNext)
{
	g_modeNext = modeNext;
	g_fade = FADE_IN;
}

//==============================
//フェードのアルファ値取得
//==============================
float GetFadeAlpha(void)
{
	return g_colorFade;
}
