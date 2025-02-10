#pragma once

namespace Gameplay {


	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController {
	private:
		float maxDuration = 100.0f;
		float remainingTime;
		float gameOverTime = 11.f;
		GameResult gameresult;

	public:
		GameplayController();
		void Intialize();
		void update();
		void render();
		void reset();
		void UpdateRemainingTime();
		float GetRemainingTime();
		int GetMinesCount();
		void EndGame(GameResult result);
		void GameWon();
		void GameLost();
		void BeginGameOvertime();
		void ShowCredits();
		bool istimeover();
		~GameplayController();
};
}