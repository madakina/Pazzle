#include "Pazzle.h"

//�L�[�̓��͏�Ԃ��X�V����֐�(�L�[�������ꂽ�u�Ԃ��擾���邽�߂ɕK�v�Ȋ֐�)
void KeyCount(int *KeyBuf)
{
	char tmpKey[256];				//���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey);		//�S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++)
	{

		if (tmpKey[i] != 0)			//i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			KeyBuf[i]++;			//���Z
		else               			//������Ă��Ȃ����
			KeyBuf[i] = 0;			//0�ɂ���
	}
}

// �t�@�C����ǂݍ��ފ֐�
void LoadFiles() {
	Title.Load();
	GameMain.Load();
	GameClear.Load();
	MapData.Load();

	BgmControl.Load();
	SeControl.Load();
}

// �Q�[���̏�Ԃ�ύX����֐�
void ChangeGameState(int NewGameState) {
	GameState = NewGameState;			// �Q�[���̏�Ԃ��X�V
	switch (GameState) {				// �V�����Q�[���̏�Ԃ̏��������s�����߂̕���
	case GS_TITLE:Title.Init();		break;
	case GS_MAIN: GameMain.Init();	break;
	case GS_CLEAR:GameClear.Init();	break;
	}
}
//���[�v���ɍs���K�v�̂��鏈�����s���֐��A�e�����ŃG���[�����������ꍇ-1��Ԃ�(�ُ�I��)
int ProcessLoop()
{
	if (ScreenFlip() != 0)	return -1;		//����ʂ�\��ʂɔ��f���܂�
	if (ProcessMessage() != 0)	return -1;	//���b�Z�[�W�������s���܂�
	if (ClearDrawScreen() != 0) return -1;	//��ʂ��������܂�

	return 0;	//�S�Ă̏���������ɏI�������ꍇ0��Ԃ�(����I��)
}
// ������𒆉��ɕ\������
int CalcCenterX(const char *str)
{
	const int x1 = 0;
	const int x2 = 640;
	int StrLen, StrWidth;

	StrLen = (int)strlen(str);
	StrWidth = GetDrawStringWidth(str, StrLen);
	return (int)((x1 + ((x2 - x1) / 2)) - (StrWidth / 2));
}