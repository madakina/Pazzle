#ifndef _MAPCONTS_H_
#define _MAPCONTS_H_

// �e�}�b�v�ɂ�����u���b�N�̏����z�u�����Ă����\����
typedef struct {
	int BlockY;
	int BlockX;
	int BlockColor;
}BlockInit;
// �e�}�b�v�ɂ�����u���b�N�̌������Ă����\����
typedef struct {
	// �e�u���b�N�̎c����̔���
	int RedBlockCnt;
	int BlueBlockCnt;
	int GreenBlockCnt;
	int YellowBlockCnt;
}BlockCnt;

#endif