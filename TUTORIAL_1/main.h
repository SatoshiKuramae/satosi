//=======================
//
//�E�B���h�E�\������:main.h
//Author: Kuramaesatoshi
//
//=======================
#ifndef _MAIN_H_
#define _MAIN_H_

#include <Windows.h>
#include "d3dx9.h"
#define DIRECTINPUT_VERSION (0x0800)	//�x���Ώ��p
#include "dinput.h"
#include "d3dx9.h" //�`�揈���ɕK�v"
#include "Xinput.h"//�W���C�p�b�h
#include "xaudio2.h"

//�}�N����`
#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)
#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define RED (255)
#define GREEN (255)
#define BLUE (255)
#define A (255)


//���C�u�����̃����N
#pragma comment(lib, "d3d9.lib")		//�`�揈���ɕK�v
#pragma	comment(lib, "d3dx9.lib")	//[d3d9.lib]�̊g�����C�u����
#pragma comment(lib, "dxguid.lib")	//DirectX�R���|�[�l���g�g�p�ɕK�v
#pragma comment(lib, "winmm.lib")	//�V�X�e�������擾���ɕK�v
#pragma comment(lib, "dinput8.lib")	//���͏����ɕK�v
#pragma comment(lib,"xinput.lib") //�W���C�p�b�h

typedef struct
{
	D3DXVECTOR3 pos;	//���_���
	float rhw;			//���W�ϊ��p�W��
	D3DCOLOR col;		//���_�J���[
	D3DXVECTOR2 tex;
}VERTEX_2D;

//��ʁi���[�h�j�̎��
typedef enum
{
	MODE_TITLE = 0,
	MODE_GAME,
	MODE_RESULT,
	MODE_TUTORIAL,
	MODE_MAX
}MODE;

//�v���g�^�C�v�錾
LPDIRECT3DDEVICE9 GetDevice(void);
void SetMode(MODE mode);
//MODE GetMode(void);
void DrawFPS(void);

#endif
