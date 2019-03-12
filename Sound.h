#ifndef _SOUND_H_
#define _SOUND_H_

enum eBGM_INDEX {
	BGM_TITLE, BGM_GAMEMAIN, BGM_GAMECLEAR, BGM_GAMEOVER
};

// BGM�R���g���[��
const int BGM_NUM = 16;						// BGM�̐�
struct SBgmControl {
	bool PlayFlag;							// �Đ������ǂ���
	int NowPlayIndex;						// �Đ����̓Y����
	struct {
		int Handle;							// �n���h��
		int Count;							// �Đ�����(�t���[��)
	}Bgm[BGM_NUM];							// BGM�̐������p�ӂ���

	void Process();							// �S�̏���
	void FirstInit();						// �ŏ��̏�����
	void ChangePlay(int HandleIndex = -1);	// ������BGM���Đ�����B
	void Load();							// �t�@�C�����[�h
};

enum eSE_INDEX {
	SE_PIPIPI, SE_BELL, SE_BOM_LONG, SE_BOM_SHORT
};

// SE�R���g���[��
const int SE_NUM = 16;						// SE�̐�
struct SSeControl {
	struct {
		int Handle;
		int Interval;
		int Count;
	}Se[SE_NUM];
	void Process();							// �S�̏���
	void FirstInit();						// �ŏ��̏�����
	void Play(int HandleIndex);
	void Load();							// �t�@�C�����[�h
};

#endif