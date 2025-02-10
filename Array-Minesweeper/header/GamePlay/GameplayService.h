#pragma once
#include"../../header/GamePlay/GameplayController.h"

namespace Gameplay
{
	class GameplayController;
	class GameplayService{
	private:
		GameplayController* gameplayController;
	public:
		GameplayService();
		void Intialize();
		void Update();
		void Render();
		void StartGame();
		float RemainingTime();
		int GetMinesCount();
		void endgame(GameResult result);
	};



}