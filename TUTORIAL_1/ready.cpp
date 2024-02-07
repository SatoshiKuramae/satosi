//=====================================
//
//READYマーク表示用
//
//=====================================

#include "main.h"
#include "input.h"
#include "ready.h"
#define NUM_READY (4)
#define MAX_COLOR (100.0f)
//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureReady = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffReady = NULL;
float g_aPosTexReady[NUM_READY];

Ready g_Ready[NUM_READY];

//初期化処理
void InitReady(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * NUM_READY, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffReady, NULL);

	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\ready_font_3.png", &g_pTextureReady);

	VERTEX_2D* pVtx;

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffReady->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_READY; nCnt++)
	{
		g_Ready[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Ready[nCnt].bUse = false;
		g_Ready[nCnt].number = 0;

		pVtx[0].pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f,0.0f,0.0f);

		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		pVtx += 4;
	}

	SetReady(D3DXVECTOR3(1280.0f, 0.0f, 0.0f), 0);
	SetReady(D3DXVECTOR3(1280.0f, 500.0f, 0.0f), 1);
	SetReady(D3DXVECTOR3(1280.0f, 700.0f, 0.0f), 3);
	SetReady(D3DXVECTOR3(500.0f, 500.0f, 0.0f), 4);

	//頂点バッファをアンロック
	g_pVtxBuffReady->Unlock();
}

//終了処理
void UninitReady(void)
{
	if (g_pTextureReady != NULL)
	{
		g_pTextureReady->Release();
		g_pTextureReady = NULL;
	}

	//頂点バッファの破棄
	if (g_pVtxBuffReady != NULL)
	{
		g_pVtxBuffReady->Release();
		g_pVtxBuffReady = NULL;
	}
}

//更新処理
void UpdateReady(void)
{
	
	if (GetKeyboardTrigger(DIK_1) == true)
	{
		if (g_Ready[0].bUse == false)
		{
			g_Ready[0].bUse = true;
		}
		else
		{
			g_Ready[0].bUse = false;
		}
	}
	if (GetKeyboardTrigger(DIK_2) == true)
	{
		if (g_Ready[1].bUse == false)
		{
			g_Ready[1].bUse = true;
		}
		else
		{
			g_Ready[1].bUse = false;
		}
	}
	if (GetKeyboardTrigger(DIK_3) == true)
	{
		if (g_Ready[2].bUse == false)
		{
			g_Ready[2].bUse = true;
		}
		else
		{
			g_Ready[2].bUse = false;
		}
	}
	if (GetKeyboardTrigger(DIK_4) == true)
	{
		if (g_Ready[3].bUse == false)
		{
			g_Ready[3].bUse = true;
		}
		else
		{
			g_Ready[3].bUse = false;
		}
	}
}

//描画処理
void DrawReady(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	//デバイスの取得
	pDevice = GetDevice();
	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffReady, 0, sizeof(VERTEX_2D));
	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	for (int nCnt = 0; nCnt < NUM_READY; nCnt++)
	{
		if (g_Ready[nCnt].bUse == true)
		{
			pDevice->SetTexture(0, g_pTextureReady);
			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCnt * 4, 2);
		}
	}
}

//Readyの配置
void SetReady(D3DXVECTOR3 pos,int nNumber)
{
	VERTEX_2D* pVtx;
	//頂点バッファをロックし、頂点座標へのポインタを取得
	g_pVtxBuffReady->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_READY; nCnt++)
	{
		if (g_Ready[nCnt].bUse == false)
		{
			g_Ready[nCnt].pos = pos;
			g_Ready[nCnt].number = nNumber;

			pVtx[0].pos = D3DXVECTOR3(g_Ready[nCnt].pos.x - 100.0f, g_Ready[nCnt].pos.y - 50.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_Ready[nCnt].pos.x + 100.0f, g_Ready[nCnt].pos.y - 50.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_Ready[nCnt].pos.x - 100.0f, g_Ready[nCnt].pos.y + 50.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_Ready[nCnt].pos.x + 100.0f, g_Ready[nCnt].pos.y + 50.0f, 0.0f);

			g_Ready[nCnt].bUse = true;
			break;
		}
		pVtx += 4;
	}
	//頂点バッファをアンロック
	g_pVtxBuffReady->Unlock();
}


Ready* GetReady(void)
{
	return &g_Ready[0];
}