#ifndef DEF_PAZZLE_H
#define DEF_PAZZLE_H

#include"DxLib.h"
#include"Define.h"
#include"Fps.h"
#include"GameClear.h"
#include"GameMain.h"
#include"Map.h"
#include"MapConts.h"
#include"MapData.h"
#include"Sound.h"
#include"Title.h"
#include"Global.h"

// Main�̊֐�
// �ŏ��Ɉ�x��������������֐�
void FirstInit();
// �Q�[���𖳌����[�v�ŕ\������������֐�
void MainLoop();

// Systen�̊֐�
// �L�[�̓��͏�Ԃ��X�V����֐�(�L�[�������ꂽ�u�Ԃ��擾���邽�߂ɕK�v�Ȋ֐�)
void KeyCount(int *KeyBuf);
// �t�@�C����ǂݍ��ފ֐�
void LoadFiles();
// �Q�[���̏�Ԃ�ύX����֐�
void ChangeGameState(int NewGameState);
// ���[�v���ɍs���K�v�̂��鏈�����s���֐��A�e�����ŃG���[�����������ꍇ-1��Ԃ�(�ُ�I��)
int ProcessLoop();
// ������𒆉��ɕ\������
int CalcCenterX(const char *str);


#endif