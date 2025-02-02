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
	}
	void GameplayController::render()
	{
	}
	void GameplayController::reset()
	{
		ServiceLocator::getInstance()->getBoardService()->ResetBoard();
	}
	GameplayController::~GameplayController()
	{
		ServiceLocator::getInstance()->getBoardService()->ResetBoard();
	}
}