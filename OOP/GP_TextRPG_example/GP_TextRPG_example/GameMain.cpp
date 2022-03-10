#include "Game.h"

void main()
{
	GameManager cGameManager;
	cGameManager.Init();
	while (cGameManager.GetStage() != GameManager::E_STAGE::EXIT)
	{
		cGameManager.Update();
	}
}