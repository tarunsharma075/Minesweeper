#include"../../header/GamePlay/GameplayController.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Main/GameService.h"
using namespace Global;
using namespace Main;
namespace Gameplay{
	GameplayController::GameplayController()
	{
	}
	void GameplayController::Intialize()
	{
		
	}
	void GameplayController::update()
	{
		UpdateRemainingTime();
		if (istimeover()) {
			EndGame(GameResult::LOST);
		}
	}
	void GameplayController::render()
	{
	}
	void GameplayController::reset()
	{
		gameresult = GameResult::NONE;
		remainingTime = maxDuration;
		ServiceLocator::getInstance()->getBoardService()->ResetBoard();
	}
	void GameplayController::UpdateRemainingTime()
	{
		remainingTime -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
	float GameplayController::GetRemainingTime()
	{
		return remainingTime;
	}
	int GameplayController::GetMinesCount()
	{
		return ServiceLocator::getInstance()->getBoardService()->GetMines();
	}
	void GameplayController::EndGame(GameResult result)
	{
		switch (result) {
		case GameResult::WON:
			GameWon();
			break;
		case GameResult::LOST:
			GameLost();
			break;
		default:
			break;
		}
	}
	void GameplayController::GameWon()
	{
		gameresult = GameResult::WON;
		ServiceLocator::getInstance()->getBoardService()->flagallmines();
		
		
	}
	void GameplayController::GameLost()
	{
		if (gameresult == GameResult::NONE) {
			gameresult = GameResult::LOST;
			BeginGameOvertime();
			ServiceLocator::getInstance()->getBoardService()->ShowBoard();
			ServiceLocator::getInstance()->getBoardService()->setBoardState(Board::BoardState::COMPLETED);
		}
		else {
			ShowCredits();
		}
	}
	void GameplayController::BeginGameOvertime()
	{
		remainingTime = gameOverTime;
	}
	void GameplayController::ShowCredits()
	{
		GameService::setGameState(GameState::CREDITS);
	}
	bool GameplayController::istimeover()
	{
		return (remainingTime<=1);
	}
	GameplayController::~GameplayController()
	{
		ServiceLocator::getInstance()->getBoardService()->ResetBoard();
	}
}