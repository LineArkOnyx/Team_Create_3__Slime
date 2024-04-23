#include"Map.h"
#include"DxLib.h"
int MapHandle[16] = { 0 };									//�}�b�v�`�b�v�f�[�^������z��
int MapChipData1[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];		//��ڂ̃}�b�v
bool toumei[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = {false};
int mapFramecount[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = {0};
Map map;
void Map::InitMap()
{
	//0�Ƀ��C���u���b�N
	LoadDivGraph("Data/�X�}�b�v�`�b�v.png", 16, 4, 4, 32, 32, MapHandle);
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

	if (Maplevel == 2)
	{
		FILE* fp;
		fopen_s(&fp, "Data/MapDeta2.csv", "r");
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
	if (Maplevel == 3)
	{
		FILE* fp;
		fopen_s(&fp, "Data/MapDeta3.csv", "r");
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
}
void Map::DrawMap()
{
	for (int y = 0; y < MAP_CHIP_Y_NUM;y++)
	{
		for (int x = 0; x < MAP_CHIP_X_NUM;x++)
		{
			if (MapChipData1[y][x] == 11)		//0�Ԗڂ��������蔻������
				continue;

			{
				DrawGraph(x * 32 , y * 32 , MapHandle[MapChipData1[y][x]], true);
			}
		}
	}
}