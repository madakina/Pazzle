#ifndef _TITLE_H_
#define _TITLE_H_

const int TG_NUM = 8;	// TitleGraphicNumber�̗�
enum eTG_INDEX {
	TG_BACK,
	TG_Stage1, TG_Stage1View,
	TG_Stage2, TG_Stage2View,
	TG_Stage3, TG_Stage3View,
};
struct STitle {
	int Graphic[TG_NUM];

	void Process();		// ���̒��Ń��[�v����
	void Init();		// ������
	void FirstInit();	// �R���X�g���N�^
	void Load();		// ���[�h
	void Draw();		// �`��n�������ɂ܂Ƃ߂�
};

#endif