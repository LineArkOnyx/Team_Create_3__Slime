#pragma once
#include"DxLib.h"
#define MAPCHIP_SIZW		(32)		//マップチップの幅
#define MAPCHIP_SIZH		(32)		//マップチップの縦
const int MAP_CHIP_X_NUM = 25;		//マップチップの横
const int MAP_CHIP_Y_NUM = 23;		//マップチップの縦
class Map
{
private:
	int Maplevel = 0;
public:
	
	void InitMap();			
	void ReadFilemap();
	void DrawMap();
	int GetMaplevel() { return Maplevel; }
};
extern Map map;
extern int MapChipData1[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];		//一つ目のマップ
extern bool toumei[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];		//一つ目のマップ
extern int mapFramecount[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM];
