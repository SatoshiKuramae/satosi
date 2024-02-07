//=======================
//
//ウィンドウ表示処理:main.h
//Author: Kuramaesatoshi
//
//=======================
#ifndef _MAIN_H_
#define _MAIN_H_

#include <Windows.h>
#include "d3dx9.h"
#define DIRECTINPUT_VERSION (0x0800)	//警告対処用
#include "dinput.h"
#include "d3dx9.h" //描画処理に必要"
#include "Xinput.h"//ジョイパッド
#include "xaudio2.h"

//マクロ定義
#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)
#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define RED (255)
#define GREEN (255)
#define BLUE (255)
#define A (255)


//ライブラリのリンク
#pragma comment(lib, "d3d9.lib")		//描画処理に必要
#pragma	comment(lib, "d3dx9.lib")	//[d3d9.lib]の拡張ライブラリ
#pragma comment(lib, "dxguid.lib")	//DirectXコンポーネント使用に必要
#pragma comment(lib, "winmm.lib")	//システム時刻取得時に必要
#pragma comment(lib, "dinput8.lib")	//入力処理に必要
#pragma comment(lib,"xinput.lib") //ジョイパッド

typedef struct
{
	D3DXVECTOR3 pos;	//頂点情報
	float rhw;			//座標変換用係数
	D3DCOLOR col;		//頂点カラー
	D3DXVECTOR2 tex;
}VERTEX_2D;

//画面（モード）の種類
typedef enum
{
	MODE_TITLE = 0,
	MODE_GAME,
	MODE_RESULT,
	MODE_TUTORIAL,
	MODE_MAX
}MODE;

//プロトタイプ宣言
LPDIRECT3DDEVICE9 GetDevice(void);
void SetMode(MODE mode);
//MODE GetMode(void);
void DrawFPS(void);

#endif
