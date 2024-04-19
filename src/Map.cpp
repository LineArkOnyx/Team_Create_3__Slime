#include"Map/Map.h"
#include"DxLib.h"
int MapHandle[16] = { 0 };									//�}�b�v�`�b�v�f�[�^������z��
int MapChipData1[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];		//��ڂ̃}�b�v
Map map;
void Map::InitMap()
{
	//0�Ƀ��C���u���b�N//1��������u���b�N2�Ƃ�3���S�[��
	LoadDivGraph("Data/�}�b�v�`�b�v.png", 16, 4, 4, 32, 32, MapHandle);
}
void Map::ReadFilemap()
{
	FILE* fp;
	fopen_s(&fp, "Data/MapDeta.csv", "r");

	int mapIndexX = 0;
	int mapIndexY = 0;

	while (true) {
		// ���l������ǂݍ���
		fscanf_s(fp, "%d", &MapChipData1[mapIndexY][mapIndexX]);
		mapIndexX++;

		// �u,�v���΂����߂ɓǂݍ��݂����s
		char c = fgetc(fp);



		// EOF�̏ꍇ�͓ǂݍ��ݏI��
		if (c == EOF)
		{
			break;
		}

		// ���s�R�[�h�̏ꍇ�͕ۑ����ύX����
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