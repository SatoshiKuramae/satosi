//=======================
//
//�^�C�g����ʕ\������:title.cpp
//Author Kuramaesatoshi
//
//=======================
#include "input.h"
#include "title.h"
#include "main.h"
#include "fade.h"

#define NUM_TITLE (3)
#define MAX_COLOR (100.0f)
//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureTitle[NUM_TITLE] = {};
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTitle = NULL;
float g_aPosTexTitleU[NUM_TITLE];
Title g_Title[NUM_TITLE];
int g_nCountAnimTitlebg;			//�A�j���[�V�����J�E���^�[
int g_nPatternAnimTitlebg;		//�A�j���[�V�����p�^�[��NO.
int T_g_nSelect = 0;	// ���ݑI�����Ă���I����

//==============================
//�^�C�g����ʂ̏���������
//==============================
void InitTitle(void)
{
	T_g_nSelect = TITLEMENU_START;

	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * NUM_TITLE, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffTitle, NULL);

	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\title1.png", &g_pTextureTitle[0]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\START_word.png", &g_pTextureTitle[1]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\TUTORIAL_word.png", &g_pTextureTitle[2]);



	VERTEX_2D* pVtx;
	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntTitle = 0; nCntTitle < NUM_TITLE; nCntTitle++)
	{

		//���_���W�̐ݒ�
		
		g_Title[nCntTitle].pos = { 0.0f, 0.0f, 0.0f };
		g_Title[nCntTitle].bUse = false;

		float fSizeX, fSizeY, fSize1X, fSize1Y;
		fSizeX = 0.0f;
		fSizeY = 0.0f;
		fSize1X = 0.0f;
		fSize1Y = 0.0f;

		if (nCntTitle == 0)
		{
			fSize1X = 0.0f;
			fSize1Y = 0.0f;
			fSizeX = 1280.0f;
			fSizeY = 720.0f;
		}
		else if (nCntTitle == 1)
		{
			fSize1X = 400.0f;
			fSize1Y = 200.0f;
			fSizeX = 870.0f;
			fSizeY = 350.0f;
		}
		else if (nCntTitle == 2)
		{
			fSize1X = 400.0f;
			fSize1Y = 350.0f;
			fSizeX = 870.0f;
			fSizeY = 500.0f;
		}
		
		pVtx[0].pos = D3DXVECTOR3(fSize1X, fSize1Y, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(fSizeX, fSize1Y, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(fSize1X, fSizeY, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(fSizeX, fSizeY, 0.0f);

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

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffTitle->Unlock();
}

//===============================
//�^�C�g����ʂ̏I������
//===============================
void UninitTitle(void)
{
	//�e�N�X�`���̔j��
	for (int nCount = 0; nCount < NUM_TITLE; nCount++)
	{
		if (g_pTextureTitle[nCount] != NULL)
		{
			g_pTextureTitle[nCount]->Release();
			g_pTextureTitle[nCount] = NULL;
		}
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffTitle != NULL)
	{
		g_pVtxBuffTitle->Release();
		g_pVtxBuffTitle = NULL;
	}
}

//==========================
//�^�C�g����ʂ̍X�V����
//==========================
void UpdateTitle(void)
{
	SetTitle();

	VERTEX_2D* pVtx;

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffTitle->Unlock();

	if (GetKeyboardTrigger(DIK_UP) == true)
	{
		if (T_g_nSelect == TITLEMENU_START)
		{
			T_g_nSelect = TITLEMENU_TUTORIAL;
		}
		else if (T_g_nSelect == TITLEMENU_TUTORIAL)
		{
			T_g_nSelect = TITLEMENU_START;
		}
	}
	if (GetKeyboardTrigger(DIK_DOWN) == true)
	{
		if (T_g_nSelect == TITLEMENU_START)
		{
			T_g_nSelect = TITLEMENU_TUTORIAL;
		}
		else if (T_g_nSelect == TITLEMENU_TUTORIAL)
		{
			T_g_nSelect = TITLEMENU_START;
		}
	}

	if (T_g_nSelect == TITLEMENU_START)
	{
		pVtx[4].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		pVtx[5].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		pVtx[6].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		pVtx[7].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);

		pVtx[8].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[9].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[10].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[11].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}
	if (T_g_nSelect == TITLEMENU_TUTORIAL)
	{
		pVtx[4].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[5].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[6].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[7].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		pVtx[8].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		pVtx[9].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		pVtx[10].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		pVtx[11].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	}
	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		switch (T_g_nSelect)
		{
		case TITLEMENU_START:
			SetFade(MODE_GAME);
			break;
		case TITLEMENU_TUTORIAL:
			SetFade(MODE_TUTORIAL);
			break;

		default:
			break;
		}
	}


}

//======================
//�^�C�g����ʂ̕`�揈��
//======================
void DrawTitle(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();
	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffTitle, 0, sizeof(VERTEX_2D));
	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	for (int nCnt = 0; nCnt < NUM_TITLE; nCnt++)
	{
		if (g_Title->bUse == true)
		{
			pDevice->SetTexture(0, g_pTextureTitle[nCnt]);
			//�|���S���̕`��

			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCnt * 4, 2);
		}
	}
}

//=========================
//�^�C�g����ʂ̐ݒ菈��
//=========================
void SetTitle(void)
{
	for (int nCntTitle = 0; nCntTitle < NUM_TITLE; nCntTitle++)
	{
		if (g_Title->bUse == false)
		{
			g_Title->bUse = true;
		}
	}
}