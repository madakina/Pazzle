#include"Pazzle.h"

/*	マップの中身を決める
	0=移動可能な空間 1=壁・地面 2=赤ブロック 3=青ブロック 4=緑ブロック 5=黄ブロック
	6=錠前付赤ブロック 7=錠前付青ブロック 8=錠前付緑ブロック 9=錠前付黄ブロック
*/
static int Map[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,5,1 },
	{ 1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,5,1 },
	{ 1,5,4,0,0,0,0,0,0,0,0,0,0,0,0,0,3,4,2,1 },
	{ 1,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1 },
	{ 1,8,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,6,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

BlockInit static Red1 =      { 3,17,2 }; BlockInit static Red2 =	   { 4, 1,2 }; BlockInit static Red3 =    { 5,18,2 };
BlockInit static Blue1 =     { 3,16,3 }; BlockInit static Blue2 =	   { 4,17,3 }; BlockInit static Blue3 =   { 5,16,3 };
BlockInit static Green1 =    { 4,16,4 }; BlockInit static Green2 =	   { 5, 2,4 }; BlockInit static Green3 =  { 5,17,4 };
BlockInit static Yellow1 =   { 3,18,5 }; BlockInit static Yellow2 =	   { 4,18,5 }; BlockInit static Yellow3 = { 5, 1,5 };
BlockInit static RedLook =   {11,18,6 }; BlockInit static BlueLook =   { 9, 4,7 };
BlockInit static GreenLook = { 9, 1,8 }; BlockInit static YellowLook = { 6,10,9 };
BlockCnt  static Count = { 3,3,3,3 };
//---------------------このファイル内でしか使えないグローバル変数------------------------------
// 各ブロックの残り個数の判定
static int RedBlockCnt = Count.RedBlockCnt;
static int BlueBlockCnt = Count.BlueBlockCnt;
static int GreenBlockCnt = Count.GreenBlockCnt;
static int YellowBlockCnt = Count.YellowBlockCnt;
// ブロックのサイズを決める
static const int cip_size = 32;
// 錠の位置を整える
static int justx = 2;
static int justy = 2;
// ブロックの表示を切り替える
static int display = 0;
void SMapData::Map3()
{
	// 各ブロックの色の判定
	int BlockColor = 0;

	//画像を表示するためのデータをMapData_BlockDisplay関数に送る
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			BlockColor = Map[i][j];
			// ブロックの表示関数
			BlockDisplay3(BlockColor, i, j);
			// 各ブロックの座標
			MousePosition3(BlockColor, i, j);
			// ブロックの色を関数に送る
			BlockLookDelete3(BlockColor, i, j);
			//デバッグ用コマンド。強制クリアでGameClear.cppに移行
			if (Key[KEY_INPUT_RETURN] != 0)
			{
				// 全てのブロックを一時的に消去する
				BlockDelete3(BlockColor, i, j);
//				display = 1;
			}
			// マウスの情報を取得
			GetMousePoint(&Mousex, &Mousey);
			// マウスの現在座標とブロックの座標を計算
			if (Mousex >= 608 && Mousey >= 448 && Mousex <= 640 && Mousey <= 480)
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)

				{
					// 全てのブロックを一時的に消去する
					BlockDelete3(BlockColor, i, j);
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
}
// ブロック画像の描画
void SMapData::BlockDisplay3(int blockcolor, int blockx, int blocky)
{
	BlockInitPosition3();
	if (display == 0)
	{
		// bcloknumberの数字によって地面またはパズルのブロックを描画
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
// 各マップにおけるブロックを初期位置に再配置する
void SMapData::BlockInitPosition3()
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
// マウスの位置を計算
void SMapData::MousePosition3(int blockcolor, int blockx, int blocky)
{
	// 同色のブロックと錠前付ブロックの判定を紐付ける
	int RedBlock = 0;		if (blockcolor == 2)RedBlock = 6;
	int BlueBlock = 0;		if (blockcolor == 3)BlueBlock = 7;
	int GreenBlock = 0;		if (blockcolor == 4)GreenBlock = 8;
	int YellowBlock = 0;	if (blockcolor == 5)YellowBlock = 9;

	// マウスの情報を取得
	GetMousePoint(&Mousex, &Mousey);
	// マウスの現在座標とブロックの座標を計算
	if (Mousex >= blocky * cip_size && Mousey >= blockx * cip_size &&
		Mousex <= blocky * cip_size + cip_size && Mousey <= blockx * cip_size + cip_size)
	{
		// 右に何も無く、右クリックが押されていなければ右クリックで右座標移動
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
			// クリックしたブロックを右へ動かす
			BlockRightMove3(blockx, blocky);
		}
		// 右が各色に応じた錠前付ブロックであり、右クリックが押されていなければ
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
			// 現在クリックしたブロックを消去する
			BlockDelete3(blockcolor, blockx, blocky);
		}

		// 左へ何も無ければ左クリックで左へ座標移動
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
			// クリックしたブロックを左へ動かす
			BlockLeftMove3(blockx, blocky);
		}
		// 左が各色に応じた錠前付ブロックなら
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
			// 現在クリックしたブロックを消去する
			BlockDelete3(blockcolor, blockx, blocky);
		}
	}
	// 下に何も無ければブロックが下へ落ちる
	if (Map[blockx][blocky] >= 2 && Map[blockx][blocky] <= 5 &&
		Map[blockx + 1][blocky] != 1 && Map[blockx + 1][blocky] != 2 &&
		Map[blockx + 1][blocky] != 3 && Map[blockx + 1][blocky] != 4 &&
		Map[blockx + 1][blocky] != 5 && Map[blockx + 1][blocky] != 6 &&
		Map[blockx + 1][blocky] != 7 && Map[blockx + 1][blocky] != 8 &&
		Map[blockx + 1][blocky] != 9)
	{
		BlockFallMove3(blockx, blocky);
	}
	// 下が各色に応じた錠前付ブロックなら
	if (Map[blockx][blocky] >= 2 && Map[blockx][blocky] <= 5 &&
		RedBlock == 6 && Map[blockx + 1][blocky] == 6 ||
		BlueBlock == 7 && Map[blockx + 1][blocky] == 7 ||
		GreenBlock == 8 && Map[blockx + 1][blocky] == 8 ||
		YellowBlock == 9 && Map[blockx + 1][blocky] == 9)
	{
		// 落下しているブロックを消去する
		BlockDelete3(blockcolor, blockx, blocky);
	}
}

// 右への動きの計算
void SMapData::BlockRightMove3(int blockx, int blocky)
{
	int tmp = Map[blockx][blocky];
	Map[blockx][blocky] = Map[blockx][blocky + 1];
	Map[blockx][blocky + 1] = tmp;
}
// 左への動きの計算
void SMapData::BlockLeftMove3(int blockx, int blocky)
{
	int tmp = Map[blockx][blocky];
	Map[blockx][blocky] = Map[blockx][blocky - 1];
	Map[blockx][blocky - 1] = tmp;
}
// 落下の計算
void SMapData::BlockFallMove3(int blockx, int blocky)
{
	int tmp = Map[blockx][blocky];
	Map[blockx][blocky] = Map[blockx + 1][blocky];
	Map[blockx + 1][blocky] = tmp;
}
// ブロックのデリートの制御
void SMapData::BlockDelete3(int blockcolor, int blockx, int blocky)
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

void SMapData::BlockLookDelete3(int blockcolor, int blockx, int blocky)
{
	if (RedBlockCnt == 0 && Map[blockx][blocky] == 6)BlockDelete3(blockcolor, blockx, blocky);
	if (BlueBlockCnt == 0 && Map[blockx][blocky] == 7)BlockDelete3(blockcolor, blockx, blocky);
	if (GreenBlockCnt == 0 && Map[blockx][blocky] == 8)BlockDelete3(blockcolor, blockx, blocky);
	if (YellowBlockCnt == 0 && Map[blockx][blocky] == 9)BlockDelete3(blockcolor, blockx, blocky);
}