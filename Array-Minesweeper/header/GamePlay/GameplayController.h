#pragma once
namespace Gameplay {

	class GameplayController {

	public:
		GameplayController();
		void Intialize();
		void update();
		void render();
		void reset();
		~GameplayController();
};
}