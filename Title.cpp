#include"Pazzle.h"

// �S�̂̏���
void STitle::Process() 
{
	Draw();							// �`�������
	// �}�E�X�̏����擾
	GetMousePoint(&Mousex, &Mousey);
	// �}�E�X�̌��ݍ��W�ƃu���b�N�̍��W���v�Z
	if (Mousex >= 110 && Mousey >= 110 && Mousex <= 160 && Mousey <= 160)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag = 1;	ChangeGameState(GS_MAIN);	}
	if (Mousex >= 290 && Mousey >= 110 && Mousex <= 340 && Mousey <= 160)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag = 2;	ChangeGameState(GS_MAIN);	}
	if (Mousex >= 470 && Mousey >= 110 && Mousex <= 520 && Mousey <= 160)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag = 3;	ChangeGameState(GS_MAIN);	}
}

// �^�C�g����ʂ̏���������
void STitle::Init() 
{
	BgmControl.ChangePlay(BGM_TITLE);
}

// �ŏ��̕ϐ��̏�����
void STitle::FirstInit() 
{
	memset(this, 0, sizeof(STitle));
}

void STitle::Load() 
{
	Graphic[TG_BACK] = LoadGraph("picture/�w�i�摜����.png");	// �^�C�g���̔w�i�摜�����[�h
	Graphic[TG_Stage1] = LoadGraph("picture/�X�e�[�W1-1.png");	// �X�e�[�W1-1
	Graphic[TG_Stage2] = LoadGraph("picture/�X�e�[�W1-2.png");	// �X�e�[�W1-2
	Graphic[TG_Stage3] = LoadGraph("picture/�X�e�[�W1-3.png");	// �X�e�[�W1-3
	Graphic[TG_Stage1View] = LoadGraph("picture/�X�e�[�W1-1View.png");	// �X�e�[�W1-1�̏������J
	Graphic[TG_Stage2View] = LoadGraph("picture/�X�e�[�W1-2View.png");	// �X�e�[�W1-2�̏������J
	Graphic[TG_Stage3View] = LoadGraph("picture/�X�e�[�W1-3View.png");	// �X�e�[�W1-3�̏������J
}

// �`��
void STitle::Draw() 
{
	DrawGraph(0, 0, Graphic[TG_BACK], FALSE);

	DrawGraph(100, 100, Graphic[TG_Stage1], TRUE);
	DrawGraph(280, 100, Graphic[TG_Stage2], TRUE);
	DrawGraph(460, 100, Graphic[TG_Stage3], TRUE);
	// �}�E�X�̏����擾
	GetMousePoint(&Mousex, &Mousey);
	// �}�E�X�̌��ݍ��W�ƃu���b�N�̍��W���v�Z
	if (Mousex >= 110 && Mousey >= 110 && Mousex <= 160 && Mousey <= 160)
	{
		const char *lv = "���񂽂�";
		centerx = CalcCenterX(lv);
		DrawFormatString(centerx, 25, White, lv);
		DrawGraph(50, 50, Graphic[TG_Stage1View], TRUE);
	}
	if (Mousex >= 290 && Mousey >= 110 && Mousex <= 340 && Mousey <= 160)
	{
		const char *lv = "�ӂ�";
		centerx = CalcCenterX(lv);
		DrawFormatString(centerx, 25, White, lv);
		DrawGraph(50, 50, Graphic[TG_Stage2View], TRUE);
	}

	if (Mousex >= 470 && Mousey >= 110 && Mousex <= 520 && Mousey <= 160)
	{
		const char *lv = "�ނ�������";
		centerx = CalcCenterX(lv);
		DrawFormatString(centerx, 25, White, lv);
		DrawGraph(50, 50, Graphic[TG_Stage3View], TRUE);
	}

	// �e�X�e�[�W�I���̑I��͈͊m�F�p
//	DrawFormatString(10, 10, GetColor(255, 255, 255), "%d", Mousex);
//	DrawFormatString(10, 25, GetColor(255, 255, 255), "%d", Mousey);
//	DrawFormatString(10, 40, GetColor(255, 255, 255), "%d", StageFlag);
}