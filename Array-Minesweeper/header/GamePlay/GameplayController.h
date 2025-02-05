#pragma once
#include"../../header/Global/ServiceLocator.h"
namespace Gameplay {

	class GameplayController {
	private:
		float maxDuration = 100.0f;
		float remainingTime;
	public:
		GameplayController();
		void Intialize();
		void update();
		void render();
		void reset();
		void UpdateRemainingTime();
		float GetRemainingTime();
		int GetMinesCount();
		~GameplayController();
};
}