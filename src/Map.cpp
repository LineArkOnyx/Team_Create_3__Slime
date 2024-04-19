#include"Map/Map.h"
#include"DxLib.h"
int MapHandle[16] = { 0 };									//マップチップデータを入れる配列
int MapChipData1[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];		//一つ目のマップ
Map map;
void Map::InitMap()
{
	//0にメインブロック//1が消えるブロック2とげ3がゴール
	LoadDivGraph("Data/マップチップ.png", 16, 4, 4, 32, 32, MapHandle);
}
void Map::ReadFilemap()
{
	FILE* fp;
	fopen_s(&fp, "Data/MapDeta.csv", "r");

	int mapIndexX = 0;
	int mapIndexY = 0;

	while (true) {
		// 数値部分を読み込む
		fscanf_s(fp, "%d", &MapChipData1[mapIndexY][mapIndexX]);
		mapIndexX++;

		// 「,」を飛ばすために読み込みを実行
		char c = fgetc(fp);



		// EOFの場合は読み込み終了
		if (c == EOF)
		{
			break;
		}

		// 改行コードの場合は保存先を変更する
		if (c == '\n')
		{
			mapIndexY++;
			mapIndexX = 0;
		}
	}

	fclose(fp);
}
void Map::DrawMap()
{
	for (int y = 0; y < MAP_CHIP_Y_NUM;y++)
	{
		for (int x = 0; x < MAP_CHIP_Y_NUM;x++)
		{
			if (MapChipData1[y][x] == 0 || MapChipData1[y][x] == 1 || MapChipData1[y][x] == 2 || MapChipData1[y][x] == 3 || MapChipData1[y][x] == 4)
			{
				DrawGraph(x * 32 , y * 32 , MapHandle[MapChipData1[y][x]], true);
			}
		}
	}
}