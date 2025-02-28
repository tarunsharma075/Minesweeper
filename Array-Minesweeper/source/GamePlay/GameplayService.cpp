#include"../../header/GamePlay/GameplayService.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
	}
	void GameplayService::Intialize()
	{
		gameplayController->Intialize();
	}
	void GameplayService::Update()
	{
		gameplayController->update();
	}
	void GameplayService::Render()
	{
		gameplayController->render();
	}
	void GameplayService::StartGame()
	{
		gameplayController->reset();
	}
}