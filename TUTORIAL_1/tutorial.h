#ifndef TUTORIAL_H_
#define TUTORIAL_H_


typedef struct
{
	int I_NumPlayer;
}NumPlayer;

//プロトタイプ宣言
void InitTutorial(void);
void UninitTutorial(void);
void UpdateTutorial(void);
void DrawTutorial(void);
NumPlayer* GetNumPlayer();
#endif // !TUTORIAL_H_

