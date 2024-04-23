#include"Map.h"
#include"DxLib.h"
int MapHandle[16] = { 0 };									//マップチップデータを入れる配列
int MapChipData1[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];		//一つ目のマップ
bool toumei[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = {false};
int mapFramecount[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = {0};
Map map;
void Map::InitMap()
{
	//0にメインブロック
	LoadDivGraph("Data/氷マップチップ.png", 16, 4, 4, 32, 32, MapHandle);
}
void Map::ReadFilemap()
{
	int mapIndexX = 0;
	int mapIndexY = 0;
	Maplevel++;
	if (Maplevel == 1)
	{
		FILE* fp;
		fopen_s(&fp, "Data/MapDeta.csv", "r");
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

	if (Maplevel == 2)
	{
		FILE* fp;
		fopen_s(&fp, "Data/MapDeta2.csv", "r");
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
	if (Maplevel == 3)
	{
		FILE* fp;
		fopen_s(&fp, "Data/MapDeta3.csv", "r");
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
}
void Map::DrawMap()
{
	for (int y = 0; y < MAP_CHIP_Y_NUM;y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM;x++)
		{
			if (MapChipData1[y][x] == 11)		//0番目だけ当たり判定を取る
				continue;

			{
				DrawGraph(x * 32 , y * 32 , MapHandle[MapChipData1[y][x]], true);
			}
		}
	}
}