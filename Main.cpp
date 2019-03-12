#define _GLOBAL_SET_
#include"Pazzle.h"
#include"MapConts.h"
// DX���C�u�����̃v���O������WinMain����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�p�Y��");						// �E�B���h�E�^�C�g��
	ChangeWindowMode(TRUE); SetGraphMode(640, 480, 16);	// �E�B���h�E���[�h�ɕύX
	if (DxLib_Init() == -1)return -1;					// DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);						// �`����ʂ𗠉�ʂɃZ�b�g

	FirstInit();										// �N�����Ɉ�x����������;

	MainLoop();											// ���C�����[�v

	InitGraph();										// �ǂݍ��񂾉摜�f�[�^���폜����
	InitSoundMem();										// �ǂݍ��񂾉����f�[�^���폜����

	DxLib_End();										// DX���C�u�����I������

	return 0;											// �v���O�������I������
}

void FirstInit()
{
	// �ϐ��̏�����
	Title.FirstInit();
	GameMain.FirstInit();
	GameClear.FirstInit();
	BgmControl.FirstInit();
	SeControl.FirstInit();

	FpsControl.FirstInit();

	LoadFiles();										// �摜�A�����f�[�^�Ȃǂ�ǂݍ���

	FpsControl.PreCount = GetNowCount();
	ChangeGameState(GS_TITLE);							// �ŏ��̃Q�[����Ԃ��^�C�g���ɃZ�b�g
}

void MainLoop()
{
	// ���C�����[�v�AProcessLoop�֐����ُ�I�����邩ESC�L�[���������ƃ��[�v���甲����
	while (ProcessLoop() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();							// ��ʂ�������
		KeyCount(Key);								// �L�[�{�[�h�̉����󋵂𒲂ׂ�

		// �Q�[���X�e�[�g�ɂ���ď�������֐���I������
		switch (GameState) {
		case GS_TITLE:	Title.Process();	break;
		case GS_MAIN:	GameMain.Process();	break;
		case GS_CLEAR:	GameClear.Process();break;
		}
		BgmControl.Process();						// BGM�̊Ǘ�
		SeControl.Process();						// ���ʉ��̊Ǘ�
		FpsControl.Process();

		ScreenFlip();								// ����ʂ̏�����\�ɔ��f
	}
}