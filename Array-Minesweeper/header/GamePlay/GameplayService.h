#pragma once
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
	};



}