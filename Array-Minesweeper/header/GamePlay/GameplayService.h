#pragma once
#include"../../header/GamePlay/GameplayController.h"
namespace Gameplay
{
	class GameplayService{
	private:
		GameplayController* gameplayController;
	public:
		GameplayService();
		void Intialize();
		void Update();
		void Render();
		void StartGame();
	};



}