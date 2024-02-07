#include "tutorial.h"
#include "main.h"
#include "fade.h"
#include "input.h"
#include "ready.h"
#define NUM_TUTORIAL_TEX (1)
LPDIRECT3DTEXTURE9 g_pTextureTutorial = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTutorial = NULL;
NumPlayer g_NumPlayer;

//����������
void InitTutorial(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4* NUM_TUTORIAL_TEX, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffTutorial, NULL);

	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\tutorial.png", &g_pTextureTutorial);


	VERTEX_2D* pVtx;
	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffTutorial->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

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

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffTutorial->Unlock();


}

//�I������
void UninitTutorial(void)
{
	for (int nCnt = 0; nCnt < NUM_TUTORIAL_TEX; nCnt++)
	{
		//�e�N�X�`���̔j��
		
		g_pTextureTutorial->Release();
		g_pTextureTutorial = NULL;
		
	}
	
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffTutorial != NULL)
	{
		g_pVtxBuffTutorial->Release();
		g_pVtxBuffTutorial = NULL;
	}
}

//�X�V����
void UpdateTutorial(void)
{
	/*if (g_NumPlayer.I_NumPlayer > 4)
	{
		g_NumPlayer.I_NumPlayer = 1;
	}
	if (g_NumPlayer.I_NumPlayer < 1)
	{
		g_NumPlayer.I_NumPlayer = 4;
	}
	if (GetKeyboardTrigger(DIK_UP) == true)
	{
		g_NumPlayer.I_NumPlayer++;
	}
	else if (GetKeyboardTrigger(DIK_DOWN) == true)
	{
		g_NumPlayer.I_NumPlayer--;
	}
	if (g_NumPlayer.I_NumPlayer == 1)
	{
		SetReady(D3DXVECTOR3(1280.0f, 0.0f, 0.0f), 0);
	}
	if (g_NumPlayer.I_NumPlayer == 2)
	{
		SetReady(D3DXVECTOR3(1280.0f, 0.0f, 0.0f), 0);
		SetReady(D3DXVECTOR3(1280.0f, 500.0f, 0.0f), 1);
	}
	if (g_NumPlayer.I_NumPlayer == 3)
	{
		SetReady(D3DXVECTOR3(1280.0f, 0.0f, 0.0f), 0);
		SetReady(D3DXVECTOR3(1280.0f, 500.0f, 0.0f), 1);
		SetReady(D3DXVECTOR3(1280.0f, 700.0f, 0.0f), 2);
	}
	if (g_NumPlayer.I_NumPlayer == 4)
	{
		SetReady(D3DXVECTOR3(1280.0f, 0.0f, 0.0f), 0);
		SetReady(D3DXVECTOR3(1280.0f, 500.0f, 0.0f), 1);
		SetReady(D3DXVECTOR3(1280.0f, 700.0f, 0.0f), 2);
		SetReady(D3DXVECTOR3(500.0f, 500.0f, 0.0f), 3);
	}*/
	
	
	UpdateReady();
	//�`���[�g���A���I���t���O
	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		SetFade(MODE_GAME);
	}
}

//�`�揈��
void DrawTutorial(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();
	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffTutorial, 0, sizeof(VERTEX_2D));
	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);
	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureTutorial);

	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

}

NumPlayer* GetNumPlayer(void)
{
	return &g_NumPlayer;
}