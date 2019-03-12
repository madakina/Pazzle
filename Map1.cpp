#include "Pazzle.h"

// ���ۂ̃Q�[���ł͎g�p���Ȃ��_�~�[�}�b�v
static int Map[MAP_HEIGHT][MAP_WIDTH] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,2,3,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};
// �֐��𓮂������߂̃_�~�[�f�[�^
BlockInit static Red1 =		 { 1,1,2 };	BlockInit static Red2 =		  { 0,0,0 }; BlockInit static Red3 =	{ 0,0,0 };
BlockInit static Blue1 =	 { 2,2,3 };	BlockInit static Blue2 =	  { 0,0,0 }; BlockInit static Blue3 =	{ 0,0,0 };
BlockInit static Green1 =	 { 0,0,0 };	BlockInit static Green2 =	  { 0,0,0 }; BlockInit static Green3 =	{ 0,0,0 };
BlockInit static Yellow1 =	 { 0,0,0 };	BlockInit static Yellow2 =	  { 0,0,0 }; BlockInit static Yellow3 = { 0,0,0 };
BlockInit static RedLook =	 { 0,0,0 };	BlockInit static BlueLook =	  { 0,0,0 };
BlockInit static GreenLook = { 0,0,0 };	BlockInit static YellowLook = { 0,0,0 };
BlockCnt  static Count = { 1,1,0,0 };
//---------------------���̃t�@�C�����ł����g���Ȃ��O���[�o���ϐ�------------------------------
// �e�u���b�N�̎c����̔���
static int RedBlockCnt = Count.RedBlockCnt;
static int BlueBlockCnt = Count.BlueBlockCnt;
static int GreenBlockCnt = Count.GreenBlockCnt;
static int YellowBlockCnt = Count.YellowBlockCnt;
// ��x�����u���b�N�̏����ʒu�����߂鎞�Ɏg���i�F���Ɏg�p����ϐ����قȂ�j
//static int RedBlockInitLookCnt = 0;
// �u���b�N�̃T�C�Y�����߂�
static const int cip_size = 32;
// ���̈ʒu�𐮂���
static int justx = 2;
static int justy = 2;
// �u���b�N�̕\����؂�ւ���
static int display = 0;
//---------------------------------------------------------------------------------------------
//----------------------�}�E�X����p�O���[�o���ϐ���Global.h�Ɉړ�-----------------------------
// �}�E�X�̍��W����
//int Mousex, Mousey;
// �}�E�X�̍��E����
//int input_RIGHT = 0;
//int input_LEFT = 0;
// Move��1�̎��A�u���b�N�𓮂����Ȃ����߂̔���
//static int RIGHT_Move = 0;
//static int LEFT_Move = 0;
//---------------------------------------------------------------------------------------------

// �摜�̏�����
void SMapData::Load()
{
	// �e�摜�����[�h
	Graphic[MDG_GroundBlock] = LoadGraph("picture/�n�ʃu���b�N.png");
	Graphic[MDG_Block1] = LoadGraph("picture/�p�Y���u���b�N1.png");
	Graphic[MDG_Block2] = LoadGraph("picture/�p�Y���u���b�N2.png");
	Graphic[MDG_Block3] = LoadGraph("picture/�p�Y���u���b�N3.png");
	Graphic[MDG_Block4] = LoadGraph("picture/�p�Y���u���b�N4.png");
	Graphic[MDG_Block5] = LoadGraph("picture/�p�Y���u���b�N5.png");
	Graphic[MDG_Look1] = LoadGraph("picture/���O1.png");
	Graphic[MDG_Look2] = LoadGraph("picture/���O2.png");
	Graphic[MDG_Look3] = LoadGraph("picture/���O3.png");
}
// �}�b�v�̃f�[�^���m�F
void SMapData::Map1()
{
	// �e�u���b�N�̐F�̔���
	int BlockColor = 0;

	//�摜��\�����邽�߂̃f�[�^��MapData_BlockDisplay�֐��ɑ���
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			BlockColor = Map[i][j];
			// �u���b�N�̕\���֐�
			BlockDisplay(BlockColor, i, j);
			// �e�u���b�N�̍��W
			MousePosition(BlockColor, i, j);
			// �u���b�N�̐F���֐��ɑ���
			BlockLookDelete(BlockColor, i, j);
			//�f�o�b�O�p�R�}���h�B�����N���A��GameClear.cpp�Ɉڍs
			if (Key[KEY_INPUT_RETURN] != 0)
			{
				// �S�Ẵu���b�N���ꎞ�I�ɏ�������
				BlockDelete(BlockColor, i, j);
//				display = 1;
			}
			// �}�E�X�̏����擾
			GetMousePoint(&Mousex, &Mousey);
			// �}�E�X�̌��ݍ��W�ƃu���b�N�̍��W���v�Z
			if (Mousex >= 608 && Mousey >= 448 && Mousex <= 640 && Mousey <= 480)
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)

				{
					// �S�Ẵu���b�N���ꎞ�I�ɏ�������
					BlockDelete(BlockColor, i, j);
					display = 1;
				}
			}
		}
	}
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 1 && RedBlockCnt == 0 && BlueBlockCnt == 0 &&
		GreenBlockCnt == 0 && YellowBlockCnt == 0)
	{
		display = 1;
		ChangeGameState(GS_CLEAR);
	}
//	DrawFormatString(10, 10, GetColor(255, 255, 255), "�ԃu���b�N�͎c��%d�ł��B", RedBlockCnt);
//	DrawFormatString(10, 25, GetColor(255, 255, 255), "�u���b�N�͎c��%d�ł��B", BlueBlockCnt);
//	DrawFormatString(10, 40, GetColor(255, 255, 255), "�΃u���b�N�͎c��%d�ł��B", GreenBlockCnt);
//	DrawFormatString(10, 55, GetColor(255, 255, 255), "���u���b�N�͎c��%d�ł��B", YellowBlockCnt);
//	DrawFormatString(10, 130, GetColor(255, 255, 255), "%d", RedBlockInitLookCnt);
}

// �u���b�N�摜�̕`��
void SMapData::BlockDisplay(int blockcolor, int blockx, int blocky)
{
	BlockInitPosition();
	if (display == 0)
	{
		// bcloknumber�̐����ɂ���Ēn�ʂ܂��̓p�Y���̃u���b�N��`��
		switch (blockcolor)
		{
		case 1:	DrawGraph(blocky * cip_size, blockx * cip_size, Graphic[MDG_GroundBlock], TRUE); break;
		case 2: DrawGraph(blocky * cip_size, blockx * cip_size, Graphic[MDG_Block1], TRUE); break;
		case 3:	DrawGraph(blocky * cip_size, blockx * cip_size, Graphic[MDG_Block2], TRUE); break;
		case 4:	DrawGraph(blocky * cip_size, blockx * cip_size, Graphic[MDG_Block3], TRUE); break;
		case 5:	DrawGraph(blocky * cip_size, blockx * cip_size, Graphic[MDG_Block4], TRUE); break;
		case 6: DrawGraph(blocky * cip_size, blockx * cip_size, Graphic[MDG_Block1], TRUE);
				DrawGraph(blocky * cip_size + justx, blockx * cip_size + justy, Graphic[MDG_Look1], TRUE); break;
		case 7: DrawGraph(blocky * cip_size, blockx * cip_size, Graphic[MDG_Block2], TRUE);
				DrawGraph(blocky * cip_size + justx, blockx * cip_size + justy, Graphic[MDG_Look1], TRUE); break;
		case 8: DrawGraph(blocky * cip_size, blockx * cip_size, Graphic[MDG_Block3], TRUE);
				DrawGraph(blocky * cip_size + justx, blockx * cip_size + justy, Graphic[MDG_Look1], TRUE); break;
		case 9: DrawGraph(blocky * cip_size, blockx * cip_size, Graphic[MDG_Block4], TRUE);
				DrawGraph(blocky * cip_size + justx, blockx * cip_size + justy, Graphic[MDG_Look2], TRUE); break;
		default:	break;
		}
	}
}
// �e�}�b�v�ɂ�����u���b�N�������ʒu�ɍĔz�u����
void SMapData::BlockInitPosition()
{/*
		if (RedBlockLook == 0 && blockcolor == 2)
		{
			Red1.BlockX = blockx; Red1.BlockY = blocky; Red1.BlockColor = blockcolor;
		}
		if (RedBlockLook == 1 && blockcolor == 2)
		{
			Red2.BlockX = blockx; Red2.BlockY = blocky; Red2.BlockColor = blockcolor;
		}
		if (RedBlockLook == 2 && blockcolor == 2)
		{
			Red3.BlockX = blockx; Red3.BlockY = blocky; Red3.BlockColor = blockcolor;
		}
		*/
	if (display == 1)
	{
		Map[Red1.BlockY][Red1.BlockX] = Red1.BlockColor;
		Map[Red2.BlockY][Red2.BlockX] = Red2.BlockColor;
		Map[Red3.BlockY][Red3.BlockX] = Red3.BlockColor;
		Map[Blue1.BlockY][Blue1.BlockX] = Blue1.BlockColor;
		Map[Blue2.BlockY][Blue2.BlockX] = Blue2.BlockColor;
		Map[Blue3.BlockY][Blue3.BlockX] = Blue3.BlockColor;
		Map[Green1.BlockY][Green1.BlockX] = Green1.BlockColor;
		Map[Green2.BlockY][Green2.BlockX] = Green2.BlockColor;
		Map[Green3.BlockY][Green3.BlockX] = Green3.BlockColor;
		Map[Yellow1.BlockY][Yellow1.BlockX] = Yellow1.BlockColor;
		Map[Yellow2.BlockY][Yellow2.BlockX] = Yellow2.BlockColor;
		Map[Yellow3.BlockY][Yellow3.BlockX] = Yellow3.BlockColor;
		RedBlockCnt = Count.RedBlockCnt;
		BlueBlockCnt = Count.BlueBlockCnt;
		GreenBlockCnt = Count.GreenBlockCnt;
		YellowBlockCnt = Count.YellowBlockCnt;
		Map[RedLook.BlockY][RedLook.BlockX] = RedLook.BlockColor;
		Map[BlueLook.BlockY][BlueLook.BlockX] = BlueLook.BlockColor;
		Map[GreenLook.BlockY][GreenLook.BlockX] = GreenLook.BlockColor;
		Map[YellowLook.BlockY][YellowLook.BlockX] = YellowLook.BlockColor;
		display = 0;
	}
}

// �}�E�X�̈ʒu���v�Z
void SMapData::MousePosition(int blockcolor, int blockx, int blocky)
{
	// ���F�̃u���b�N�Ə��O�t�u���b�N�̔����R�t����
	int RedBlock = 0;		if (blockcolor == 2)RedBlock = 6;
	int BlueBlock = 0;		if (blockcolor == 3)BlueBlock = 7;
	int GreenBlock = 0;		if (blockcolor == 4)GreenBlock = 8;
	int YellowBlock = 0;	if (blockcolor == 5)YellowBlock = 9;

	// �}�E�X�̏����擾
	GetMousePoint(&Mousex, &Mousey);
	// �}�E�X�̌��ݍ��W�ƃu���b�N�̍��W���v�Z
	if (Mousex >= blocky * 32 && Mousey >= blockx * 32 &&
		Mousex <= blocky * 32 + 32 && Mousey <= blockx * 32 + 32)
	{
		// �E�ɉ��������A�E�N���b�N��������Ă��Ȃ���ΉE�N���b�N�ŉE���W�ړ�
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && RIGHT_Move == 0 &&
			Map[blockx][blocky] >= 2 && Map[blockx][blocky] <= 5 &&
			Map[blockx][blocky + 1] != 1 && Map[blockx][blocky + 1] != 2 &&
			Map[blockx][blocky + 1] != 3 && Map[blockx][blocky + 1] != 4 &&
			Map[blockx][blocky + 1] != 5 && Map[blockx][blocky + 1] != 6 &&
			Map[blockx][blocky + 1] != 7 && Map[blockx][blocky + 1] != 8 &&
			Map[blockx][blocky + 1] != 9)
		{
			input_RIGHT++;
			RIGHT_Move++;
		}
		else input_RIGHT = 0;
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) == 0) RIGHT_Move = 0;
		if (input_RIGHT == 1)
		{
			// �N���b�N�����u���b�N���E�֓�����
			BlockRightMove(blockx, blocky);
		}
		// �E���e�F�ɉ��������O�t�u���b�N�ł���A�E�N���b�N��������Ă��Ȃ����
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && Map[blockx][blocky] == 2 &&
			RedBlock == 6 && Map[blockx][blocky + 1] == 6 && RIGHT_Move == 0 ||
			(GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && Map[blockx][blocky] == 3 &&
			BlueBlock == 7 && Map[blockx][blocky + 1] == 7 && RIGHT_Move == 0 ||
			(GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && Map[blockx][blocky] == 4 &&
			GreenBlock == 8 && Map[blockx][blocky + 1] == 8 && RIGHT_Move == 0 ||
			(GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && Map[blockx][blocky] == 5 &&
			YellowBlock == 9 && Map[blockx][blocky + 1] == 9 && RIGHT_Move == 0)
		{
			input_RIGHT++;
			RIGHT_Move++;
		}
		else input_RIGHT = 0;
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) == 0) RIGHT_Move = 0;
		if (input_RIGHT == 1)
		{
			// ���݃N���b�N�����u���b�N����������
			BlockDelete(blockcolor, blockx, blocky);
		}

		// ���։���������΍��N���b�N�ō��֍��W�ړ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && LEFT_Move == 0 &&
			Map[blockx][blocky] >= 2 && Map[blockx][blocky] <= 5 &&
			Map[blockx][blocky - 1] != 1 && Map[blockx][blocky - 1] != 2 &&
			Map[blockx][blocky - 1] != 3 && Map[blockx][blocky - 1] != 4 &&
			Map[blockx][blocky - 1] != 5 && Map[blockx][blocky - 1] != 6 &&
			Map[blockx][blocky - 1] != 7 && Map[blockx][blocky - 1] != 8 &&
			Map[blockx][blocky - 1] != 9)
		{
			input_LEFT++;
			LEFT_Move++;
		}
		else input_LEFT = 0;
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0) LEFT_Move = 0;
		if (input_LEFT == 1)
		{
			// �N���b�N�����u���b�N�����֓�����
			BlockLeftMove(blockx, blocky);
		}
		// �����e�F�ɉ��������O�t�u���b�N�Ȃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && Map[blockx][blocky] == 2 &&
			RedBlock == 6 && Map[blockx][blocky - 1] == 6 && LEFT_Move == 0 ||
			(GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && Map[blockx][blocky] == 3 &&
			BlueBlock == 7 && Map[blockx][blocky - 1] == 7 && LEFT_Move == 0 ||
			(GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && Map[blockx][blocky] == 4 &&
			GreenBlock == 8 && Map[blockx][blocky - 1] == 8 && LEFT_Move == 0 ||
			(GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && Map[blockx][blocky] == 5 &&
			YellowBlock == 9 && Map[blockx][blocky - 1] == 9 && LEFT_Move == 0)
		{
			input_LEFT++;
			LEFT_Move++;
		}
		else input_LEFT = 0;
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0) LEFT_Move = 0;
		if (input_LEFT == 1)
		{
			// ���݃N���b�N�����u���b�N����������
			BlockDelete(blockcolor, blockx, blocky);
		}
	}
	// ���ɉ���������΃u���b�N�����֗�����
	if (Map[blockx][blocky] >= 2 && Map[blockx][blocky] <= 5 &&
		Map[blockx + 1][blocky] != 1 && Map[blockx + 1][blocky] != 2 &&
		Map[blockx + 1][blocky] != 3 && Map[blockx + 1][blocky] != 4 &&
		Map[blockx + 1][blocky] != 5 && Map[blockx + 1][blocky] != 6 &&
		Map[blockx + 1][blocky] != 7 && Map[blockx + 1][blocky] != 8 &&
		Map[blockx + 1][blocky] != 9)
	{
		BlockFallMove(blockx, blocky);
	}
	// �����e�F�ɉ��������O�t�u���b�N�Ȃ�
	if (Map[blockx][blocky] >= 2 && Map[blockx][blocky] <= 5 &&
		RedBlock == 6 && Map[blockx + 1][blocky] == 6 ||
		BlueBlock == 7 && Map[blockx + 1][blocky] == 7 ||
		GreenBlock == 8 && Map[blockx + 1][blocky] == 8 ||
		YellowBlock == 9 && Map[blockx + 1][blocky] == 9)
	{
		// �������Ă���u���b�N����������
		BlockDelete(blockcolor, blockx, blocky);
	}
}

// �E�ւ̓����̌v�Z
void SMapData::BlockRightMove(int blockx, int blocky)
{
	int tmp = Map[blockx][blocky];
	Map[blockx][blocky] = Map[blockx][blocky + 1];
	Map[blockx][blocky + 1] = tmp;
}
// ���ւ̓����̌v�Z
void SMapData::BlockLeftMove(int blockx, int blocky)
{
	int tmp = Map[blockx][blocky];
	Map[blockx][blocky] = Map[blockx][blocky - 1];
	Map[blockx][blocky - 1] = tmp;
}
// �����̌v�Z
void SMapData::BlockFallMove(int blockx, int blocky)
{
	int tmp = Map[blockx][blocky];
	Map[blockx][blocky] = Map[blockx + 1][blocky];
	Map[blockx + 1][blocky] = tmp;
}
// �u���b�N�̃f���[�g�̐���
void SMapData::BlockDelete(int blockcolor, int blockx, int blocky)
{
	if (blockcolor != 1)
	{
		if (blockcolor == 2)RedBlockCnt--;
		if (blockcolor == 3)BlueBlockCnt--;
		if (blockcolor == 4)GreenBlockCnt--;
		if (blockcolor == 5)YellowBlockCnt--;
		Map[blockx][blocky] = 0;
	}
}

void SMapData::BlockLookDelete(int blockcolor, int blockx, int blocky)
{
	if (RedBlockCnt == 0 && Map[blockx][blocky] == 6)BlockDelete(blockcolor, blockx, blocky);
	if (BlueBlockCnt == 0 && Map[blockx][blocky] == 7)BlockDelete(blockcolor, blockx, blocky);
	if (GreenBlockCnt == 0 && Map[blockx][blocky] == 8)BlockDelete(blockcolor, blockx, blocky);
	if (YellowBlockCnt == 0 && Map[blockx][blocky] == 9)BlockDelete(blockcolor, blockx, blocky);
}