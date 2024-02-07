//===================================
//
//title.h
//
//===================================
#ifndef _TITLE_H_
#define _TITLE_H_

#include "main.h"


typedef enum
{
	TITLEMENU_START = 0,
	TITLEMENU_TUTORIAL,
	TITLEMENU_MAX
}TITLEPICK;


typedef struct
{
	D3DXVECTOR3 pos;		//位置
	bool bUse;				//使用しているかどうか
}Title;

//プロトタイプ宣言
void InitTitle(void);
void UninitTitle(void);
void UpdateTitle(void);
void DrawTitle(void);
void SetTitle(void);

#endif // !_TITLE_H_

