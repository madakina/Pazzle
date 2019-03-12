#include"Pazzle.h"

// �Q�[���N���A��ʂ̏���
void SGameClear::Process() {
	Draw();
	// �}�E�X�̏����擾
	GetMousePoint(&Mousex, &Mousey);
	// �}�E�X�̌��ݍ��W�ƃu���b�N�̍��W���v�Z
	if (Mousex >= 120 && Mousey >= 300 && Mousex <= 280 && Mousey <= 320)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag--;	ChangeGameState(GS_MAIN);	}
	if (Mousex >= 380 && Mousey >= 300 && Mousex <= 540 && Mousey <= 320)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag++;	ChangeGameState(GS_MAIN);	}
	if (Mousex >= 250 && Mousey >= 350 && Mousex <= 410 && Mousey <= 370)
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{	StageFlag = 0;	ChangeGameState(GS_MAIN);	}
}

// �Q�[���N���A��ʂ̏�����
void SGameClear::Init() {
	BgmControl.ChangePlay(BGM_GAMECLEAR);
}

// �ŏ��̕ϐ��̏�����
void SGameClear::FirstInit() {
	memset(this, 0, sizeof(SGameClear));
}

// ���[�h
void SGameClear::Load() {
	Graphic[CG_CLEAR] = LoadGraph("picture/GAME CLEAR.png");
	Graphic[CG_BACK] = LoadGraph("picture/BACK.png");
	Graphic[CG_NEXT] = LoadGraph("picture/NEXT.png");
	Graphic[CG_TOP] = LoadGraph("picture/TOP.png");
	Graphic[CG_MAP1] = LoadGraph("picture/�X�e�[�W�N���A(1-1).png");
	Graphic[CG_MAP2] = LoadGraph("picture/�X�e�[�W�N���A(1-2).png");
	Graphic[CG_MAP3] = LoadGraph("picture/�X�e�[�W�N���A(1-3).png");
}

// �`��
void SGameClear::Draw() {
	if (StageFlag == 1) DrawGraph(0, 0, Graphic[CG_MAP1], TRUE);
	if (StageFlag == 2) DrawGraph(0, 0, Graphic[CG_MAP2], TRUE);
	if (StageFlag == 3) DrawGraph(0, 0, Graphic[CG_MAP3], TRUE);
	DrawGraph(75, 200, Graphic[CG_CLEAR], TRUE);
	DrawGraph(120, 300, Graphic[CG_BACK], TRUE);
	DrawGraph(380, 300, Graphic[CG_NEXT], TRUE);
	DrawGraph(250, 350, Graphic[CG_TOP], TRUE);

//	DrawFormatString(10, 10, GetColor(255, 255, 255), "%d", Mousex);
//	DrawFormatString(10, 25, GetColor(255, 255, 255), "%d", Mousey);
//	DrawFormatString(10, 40, GetColor(255, 255, 255), "%d", StageFlag);
}