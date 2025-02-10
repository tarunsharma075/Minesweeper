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
	float  GameplayService::RemainingTime()
	{
		return gameplayController->GetRemainingTime();
	}
	int GameplayService::GetMinesCount()
	{
		return gameplayController->GetMinesCount();
	}
	void GameplayService::endgame(GameResult result)
	{
		gameplayController->EndGame(result);
	}
	

}