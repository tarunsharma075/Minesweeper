#pragma once
#include"../../header/GamePlay/Cell/CellController.h"
#include"../../header/GamePlay/Board/BoardView.h"
#include"SFML/Graphics.hpp"
#include"../../header/GamePlay/Board/BoardView.h"
#include"../../header/UI/UIElement/ButtonView.h"
#include<random>
namespace Gameplay
{
	namespace Board
	{
		enum class BoardState
		{
			FIRST_CELL,       // The state when the player opens first cell.
			PLAYING,          // The game is in progress.
			COMPLETED,    // The game is over.
		};

		class BoardController {
		private:
			
			std::default_random_engine randomEngine;
			std::random_device randomDevice;
			BoardView* boardView;
			void CreateBoards();
			void DeleteBoard();
			void Destroy();
			void resetBoard();
			BoardState boardState;

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
			void SetBoardstate(BoardState state);
			BoardState GetBoardstate();
			void PopulateBoard(sf::Vector2i cellposition); 
			int countMinesAround(sf::Vector2i cellposition);
			bool isValidCellPosition(sf::Vector2i cellposition);
			void PopulateCells();
			void OpenAllCells();
			void ProcessCellValue(sf::Vector2i CellPosition);
			void OpenEmptyCells(sf::Vector2i CellPosition);
			void ProcessemptyCell(sf::Vector2i cellPosition);
			~BoardController();
		};



	}
}