
#ifndef _GAMEMAIN_H_
#define _GAMEMAIN_H_

const int MG_NUM = 10;		 //MAIN_GRAPHIC_NUM�̗�
enum eMG_INDEX {
	//MG_BACK,
	MG_RESET,
};

struct SGameMain {
	int Graphic[MG_NUM];	// �O���t�B�b�N

	void Process();			// ���̒��Ń��[�v����
	void Init();			// ������
	void FirstInit();		// �R���X�g���N�^
	void Load();			// ���[�h
	void Draw();			// �`��n�������ɂ܂Ƃ߂�
};

#endif