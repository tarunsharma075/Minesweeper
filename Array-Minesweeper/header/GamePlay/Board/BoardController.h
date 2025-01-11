#pragma once
#include"../../header/GamePlay/Board/CellController.h"
#include"../../header/GamePlay/Board/BoardView.h"
#include"SFML/Graphics.hpp"
#include"../../header/GamePlay/Board/BoardView.h"
namespace Gameplay
{
	namespace Board
	{
		class BoardController {
		private:
			static const int NumberOfRows = 9;
			static const int NumberOFColums = 9;
			static const int NumberOFMines = 8;

			BoardView* boardView;
			void CreateBoards();
			void DeleteBoard();
			void Destroy();

		public:
			BoardController();
			void initialize();
			void Update();
			void Render();
			void Reset();
			~BoardController();
		};



	}
}