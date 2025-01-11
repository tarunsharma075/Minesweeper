#pragma once
#include"../../header/GamePlay/Board/BoardController.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardService {

		private:
			BoardController* boardController;
			
			void  destroy();

		public:
			BoardService();
			~BoardService();
			void Intialize();
			void Update();
			void Render();
			void ResetBoard();
		
		};
		
	}
}