#ifndef _GAMECLEAR_H_
#define _GAMECLEAR_H_

const int CG_NUM = 8; //CLEAR_GRAPHIC_NUM�̗�
enum eCG_INDEX {
	CG_CLEAR,
	CG_BACK,CG_NEXT, CG_TOP,
	CG_MAP1, CG_MAP2, CG_MAP3,
};

struct SGameClear {
	int Graphic[CG_NUM];	// �O���t�B�b�N

	void Process();			// ���̒��Ń��[�v����
	void Init();			// ������
	void FirstInit();		// �R���X�g���N�^
	void Load();			// ���[�h
	void Draw();			// �`��n�������ɂ܂Ƃ߂�
};

#endif