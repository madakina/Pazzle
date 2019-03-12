#include"Pazzle.h"

// ���C���Q�[���̏���
void SGameMain::Process() {

	switch (StageFlag) {
	case 0: ChangeGameState(GS_TITLE); break;
	case 1:	MapData.Map1(); break;
	case 2:	MapData.Map2(); break;
	case 3:	MapData.Map3(); break;
	case 4: ChangeGameState(GS_TITLE); break;
	}
	Draw();
}

// ���C���Q�[���̏���������
void SGameMain::Init() {
	BgmControl.ChangePlay(BGM_GAMEMAIN);
}

// �ŏ��̕ϐ��̏�����
void SGameMain::FirstInit() {
	memset(this, 0, sizeof(SGameMain));
}

// ���[�h
void SGameMain::Load() {
	// �epicture�����[�h
	//	Graphic[MG_BACK] = LoadGraph("picture/�Q�[����ʔw�ipicture����.png");
	Graphic[MG_RESET] = LoadGraph("picture/���Ȃ���.png");
}

// �`��
void SGameMain::Draw() {
	DrawGraph(608, 448, Graphic[MG_RESET], TRUE);
//	DrawFormatString(10, 40, GetColor(255, 255, 255), "%d", StageFlag);
}
