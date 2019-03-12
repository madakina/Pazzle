#ifndef _MAPDATA_H_
#define _MAPDATA_H_

const int MDG_NUM = 10;	// MapDataGraphicNumber�̗�
// �e�摜�p�̕ϐ�
enum eMDG_INDEX {
	MDG_GroundBlock,
	MDG_Block1, MDG_Block2, MDG_Block3, MDG_Block4, MDG_Block5,
	MDG_Look1, MDG_Look2, MDG_Look3,
};
// MapData.cpp�t�@�C���Ŏg�p����֐��̍\����
struct SMapData {
	int Graphic[MG_NUM];

	// �摜�̏�����
	void Load();
	// �}�b�v�̃f�[�^���m�F
	void Map1();
	void Map2();
	void Map3();
	// �u���b�N�̏����ʒu���L��
	void BlockInitPosition();
	// �u���b�N�摜�̕\��
	void BlockDisplay(int blockcolor, int blockx, int blocky);
	// �e�摜�̗�������
	void BlockFallMove(int blockx, int blocky);
	// �e�摜�̍��̈ړ�����
	void BlockLeftMove(int blockx, int blocky);
	// �e�摜�̉E�̈ړ�����
	void BlockRightMove(int blockx, int blocky);
	// �e�摜�Ə��O�t�u���b�N�̏Փ˂������Ƀu���b�N����������
	void BlockDelete(int blockcolor, int blockx, int blocky);
	// �Ή�����u���b�N���S�ď�������ɏ��O�t�u���b�N����������
	void BlockLookDelete(int blockccolor, int blockx, int blocky);
	// �}�b�v�ɔz�u���ꂽ�e�u���b�N�̍��W��T��
	void MousePosition(int blockcolor, int blockx, int blocky);

	// �u���b�N�̏����ʒu���L��
	void BlockInitPosition2();
	// �u���b�N�摜�̕\��
	void BlockDisplay2(int blockcolor, int blockx, int blocky);
	// �e�摜�̗�������
	void BlockFallMove2(int blockx, int blocky);
	// �e�摜�̍��̈ړ�����
	void BlockLeftMove2(int blockx, int blocky);
	// �e�摜�̉E�̈ړ�����
	void BlockRightMove2(int blockx, int blocky);
	// �e�摜�Ə��O�t�u���b�N�̏Փ˂������Ƀu���b�N����������
	void BlockDelete2(int blockcolor, int blockx, int blocky);
	// �Ή�����u���b�N���S�ď�������ɏ��O�t�u���b�N����������
	void BlockLookDelete2(int blockccolor, int blockx, int blocky);
	// �}�b�v�ɔz�u���ꂽ�e�u���b�N�̍��W��T��
	void MousePosition2(int blockcolor, int blockx, int blocky);

	// �u���b�N�̏����ʒu���L��
	void BlockInitPosition3();
	// �u���b�N�摜�̕\��
	void BlockDisplay3(int blockcolor, int blockx, int blocky);
	// �e�摜�̗�������
	void BlockFallMove3(int blockx, int blocky);
	// �e�摜�̍��̈ړ�����
	void BlockLeftMove3(int blockx, int blocky);
	// �e�摜�̉E�̈ړ�����
	void BlockRightMove3(int blockx, int blocky);
	// �e�摜�Ə��O�t�u���b�N�̏Փ˂������Ƀu���b�N����������
	void BlockDelete3(int blockcolor, int blockx, int blocky);
	// �Ή�����u���b�N���S�ď�������ɏ��O�t�u���b�N����������
	void BlockLookDelete3(int blockccolor, int blockx, int blocky);
	// �}�b�v�ɔz�u���ꂽ�e�u���b�N�̍��W��T��
	void MousePosition3(int blockcolor, int blockx, int blocky);
};
#endif