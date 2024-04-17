#include "Play.h"

Play::Play()
{
	
}
Play::~Play()
{

}
void Play::InitPlay()
{
	player.InitPlayer();
}
void Play::StepPlay()
{
	player.StepPlayer();
}
void Play::DrawPlay()
{
	player.DrawPlayer();
}
void Play::FinPlay()
{
	player.FinPlayer();
}