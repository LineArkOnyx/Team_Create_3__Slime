#include "Play.h"

Play::Play()
{
	BackGroundHndl = -1;
}
Play::~Play()
{

}
void Play::InitPlay()
{
	BackGroundHndl = LoadGraph("Data/OIP.png");
}
void Play::StepPlay()
{
	
}
void Play::DrawPlay()
{
	DrawRotaGraph(SCREEN_SIZE_X/2, DEFAULT_SCREEN_SIZE_Y/2, 3.0, 0.0, BackGroundHndl, true);
}
void Play::FinPlay()
{
	DeleteGraph(BackGroundHndl);
	BackGroundHndl = -1;
}
Play play;