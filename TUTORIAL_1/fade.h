//=======================
//
//フェード処理:explosion.h
//Author Kuramaesatoshi
//
//=======================
#ifndef  _FADE_H_
#define _FADE_H_

#include "main.h"

//フェードの状態
typedef enum
{
	FADE_NONE = 0,	//何もしていない状態
	FADE_IN,		//フェードイン状態
	FADE_OUT,		//フェードアウト状態
	FADE_MAX
}FADE;


//プロトタイプ宣言
void InitFade(void);
void UninitFade(void);
void UpdateFade(void);
void DrawFade(void);
void SetFade(MODE modeNext);
FADE GetFade(void);

#endif // ! _FADE_H_

