#include"../../header/GamePlay/GameplayController.h"
using namespace Global;
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
	}
	void GameplayController::render()
	{
	}
	void GameplayController::reset()
	{
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
	GameplayController::~GameplayController()
	{
		ServiceLocator::getInstance()->getBoardService()->ResetBoard();
	}
}