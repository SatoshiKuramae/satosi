//=======================
//
//�E�B���h�E�\������:input1.h
//Author Kuramaesatoshi
//
//=======================
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"

//�v���g�^�C�v�錾
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd);
void UninitKeyboard(void);
void UpdateKeyboard(void);
bool GetKeyboardpress(int nKey);
bool GetKeyboardTrigger(int nKey);
bool GetKeyboardRelease(int nKey);

#endif
