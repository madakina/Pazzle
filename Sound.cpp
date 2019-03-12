#include"Pazzle.h"

//	BGM-----------------------------------------
// �S�̏���
void SBgmControl::Process() {
	if (PlayFlag == true) {							// �Đ����Ȃ�
		Bgm[NowPlayIndex].Count++;					// �Đ����Ԃ��X�V
	}
}

// �Đ��a�f�l��ς���A�Ƃ߂�
void SBgmControl::ChangePlay(int HandleIndex) {
	if (HandleIndex == -1) {						// �����̎w�肪�������
		PlayFlag = false;							// �Đ���~
		StopSoundMem(Bgm[NowPlayIndex].Handle);		// �������~�߂�
		return;
	}
	else {
		if (PlayFlag == true)							// ���܂ŉ����Đ����Ă�����
			StopSoundMem(Bgm[NowPlayIndex].Handle);		// �Đ����Ă����̂Ȃ��~����
		PlayFlag = true;								// �Đ���
		NowPlayIndex = HandleIndex;						// �V�����n���h�����i�[
		PlaySoundMem(Bgm[NowPlayIndex].Handle, DX_PLAYTYPE_BACK);	// �Đ�
		Bgm[NowPlayIndex].Count = 0;					// �Đ����Ԃ�������
	}
}

// �ŏ��̏�����
void SBgmControl::FirstInit() {
	memset(this, 0, sizeof(SBgmControl));
}

// ���y�t�@�C�������[�h����
void SBgmControl::Load() {
	Bgm[BGM_TITLE].Handle = LoadSoundMem("music/title.mp3");
	SetLoopPosSoundMem(0, Bgm[BGM_TITLE].Handle);

	Bgm[BGM_GAMEMAIN].Handle = LoadSoundMem("music/game_main.mp3");
	SetLoopPosSoundMem(0, Bgm[BGM_GAMEMAIN].Handle);

	Bgm[BGM_GAMECLEAR].Handle = LoadSoundMem("music/game_clear.mp3");
	SetLoopPosSoundMem(0, Bgm[BGM_GAMECLEAR].Handle);

}



// SE------------------------------------------------
// �S�̏���
void SSeControl::Process() {
	for (int i = 0; i < SE_NUM; i++) {					// �S�Ă̌��ʉ�
		if (Se[i].Count != 0) {							// �Đ������̂Ȃ�
			Se[i].Count--;								// �C���^�[�o���X�V
		}
	}

//	DrawString(20, 20, "�P�`�S���������ƂŌ��ʉ�����܂�", Black);
	if (Key[KEY_INPUT_1] == 1) {
		Play(SE_PIPIPI);
	}
	if (Key[KEY_INPUT_2] == 1) {
		Play(SE_BELL);
	}
	if (Key[KEY_INPUT_3] == 1) {
		Play(SE_BOM_LONG);
	}
	if (Key[KEY_INPUT_4] == 1) {
		Play(SE_BOM_SHORT);
	}
}

// �ŏ��̏�����
void SSeControl::FirstInit() {
	memset(this, 0, sizeof(SSeControl));				// �S�Ă̕ϐ����O�ɂ���
}

// �Đ�����
void SSeControl::Play(int HandleIndex) {
	if (Se[HandleIndex].Count == 0) {					// �Đ��\���ԂȂ�
		PlaySoundMem(Se[HandleIndex].Handle, DX_PLAYTYPE_BACK);		// �Đ�
		Se[HandleIndex].Count = Se[HandleIndex].Interval;	// �ŏ��҂����Ԃ��w��
	}
}

// ���y�t�@�C�������[�h����
void SSeControl::Load() {
	Se[SE_PIPIPI].Handle = LoadSoundMem("music/pipipi.wav");	// ���[�h
	Se[SE_PIPIPI].Interval = 5;									// �Œ�҂�����

	Se[SE_BELL].Handle = LoadSoundMem("music/bell.wav");
	Se[SE_BELL].Interval = 5;

	Se[SE_BOM_LONG].Handle = LoadSoundMem("music/bom_long.wav");
	Se[SE_BOM_LONG].Interval = 5;

	Se[SE_BOM_SHORT].Handle = LoadSoundMem("music/bom_short.wav");
	Se[SE_BOM_SHORT].Interval = 5;
}

