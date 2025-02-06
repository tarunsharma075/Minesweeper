#pragma once
#include"../../header/GamePlay/Cell/CellController.h"
#include"../../header/GamePlay/Board/BoardView.h"
#include"SFML/Graphics.hpp"
#include"../../header/GamePlay/Board/BoardView.h"
#include"../../header/UI/UIElement/ButtonView.h"
namespace Gameplay
{
	namespace Board
	{
		class BoardController {
		private:
		
			BoardView* boardView;
			void CreateBoards();
			void DeleteBoard();
			void Destroy();
			void resetBoard();

		public:

			
			static const int NumberOfRows = 9;
			static const int NumberOFColums = 9;
			static const int NumberOFMines = 8;
			Cell::CellController* board[NumberOfRows][NumberOFColums];
			BoardController();
			void initialize();
			void Update();
			void Render();
			void Reset();
			void intializeCell();
			void ResetBoard();
			int GetMineCount();
			void OpenCell(sf::Vector2i cell_position);
			int flagged_cell;
			void ProcessCellInput(Cell::CellController * cellController, UI::UIElement::buttonType button);
			void flagCell(sf::Vector2i cell_position);
			int GetMaxMineCount();
			~BoardController();
		};



	}
}