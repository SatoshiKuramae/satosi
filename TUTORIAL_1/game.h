#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"

//
//typedef struct
//{
//	D3DXVECTOR3 pos;	//位置
//	int nType;			//種類
//	bool bUse;
//}BlockInfo;


//プロトタイプ宣言
void InitGame(void);
void UninitGame(void);
void UpdateGame(void);
void DrawGame(void);
//void LoadBlock(void);
//void SetModeByPause(MODE mode);

#endif // !_GAME_H_
