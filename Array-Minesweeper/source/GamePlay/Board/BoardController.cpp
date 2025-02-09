#include"../../header/GamePlay/Board/BoardController.h"
#include"../../header/GamePlay/Cell/CellModel.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Sound/SoundService.h"
#include"../../header/GamePlay/Cell/CellModel.h"
namespace Gameplay
{
	
	namespace Board
	{
		using namespace sf;
		using namespace Gameplay::Cell;
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Sound;
		void BoardController::CreateBoards()
		{
			for (int i = 0; i < NumberOfRows; i++) {
				for (int j = 0; j < NumberOFColums; j++) {
					board[i][j] = new CellController(Vector2i(i, j));
				}
			}
		}
		void BoardController::DeleteBoard()
		{
			for (int a = 0; a < NumberOfRows; a++)
			{
				for (int b = 0; b < NumberOFColums; b++)
				{
					delete board[a][b];
				}
			}
		}
		void BoardController::Destroy()
		{
			DeleteBoard();
			delete(boardView);
		}
		void BoardController::resetBoard()
		{
		}
		BoardController::BoardController() :randomEngine(randomDevice())
		{
			boardView = new BoardView(this);
			CreateBoards();
		}
		void BoardController::initialize()
		{
			intializeCell();
			boardView->initialize();

		}
		void BoardController::Update()
		{
			boardView->update();
			for (int i = 0; i < NumberOfRows; i++) {
				for (int j = 0; j < NumberOFColums; j++) {
					board[i][j]->update();
				}
			}
		}
		void BoardController::Render()
		{
			boardView->render();
			for (int i = 0; i < NumberOfRows; i++) {
				for (int j = 0; j < NumberOFColums; j++) {
					board[i][j]->render();
				}
			}
		}
		void BoardController::Reset()
		{
			ResetBoard();
			flagged_cell = 0;
			boardState = BoardState::FIRST_CELL;
		}
		void BoardController::intializeCell()
		{
			float cellWidth = boardView->GetCellWidth();
			float cellHeight = boardView->GetCellHeight();
			for (int i = 0; i < NumberOfRows; i++) {
				for (int j = 0; j < NumberOFColums; j++) {
					board[i][j]->initialize(cellWidth, cellHeight);
				}
			}
		}
		void BoardController::ResetBoard()
		{
			for (int row = 0; row < NumberOfRows; ++row)
			{
				for (int col = 0; col < NumberOFColums; ++col)
				{
					board[row][col]->reset();
				}
			}

		}
		int BoardController::GetMineCount()
		{
			return NumberOFMines - flagged_cell;
		}
		void BoardController::OpenCell(sf::Vector2i cell_position)
		{
			if (board[cell_position.x][cell_position.y]->CanOpenCell())
			{
				if (boardState == BoardState::FIRST_CELL) {
					PopulateBoard(cell_position);
					boardState = BoardState::PLAYING;
				}
				board[cell_position.x][cell_position.y]->OpenCell();
			}
		}
		void BoardController::ProcessCellInput(CellController* cellController, UI::UIElement::buttonType button)
		{
			switch (button) {
			case::buttonType::LeftMouseButton:
				OpenCell(cellController->GetCellPosition());
				break;
			case::buttonType::RightMouseButton:

				flagCell(cellController->GetCellPosition());
				break;
			}
		}
		void BoardController::flagCell(sf::Vector2i cell_position)
		{
			switch (board[cell_position.x][cell_position.y]->GetCellState()) {
			case::Gameplay::Cell::CellState::FLAGGED:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::Flag);

				flagged_cell--;
				if (flagged_cell <= 0) {
					flagged_cell = 0;
				}
				break;
			case CellState::HIDDEN:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::Flag);
				flagged_cell++;
				if (flagged_cell >= GetMaxMineCount()) {
					flagged_cell = GetMaxMineCount();
				}
				break;
			}
			board[cell_position.x][cell_position.y]->FlagCell();
		}
		int BoardController::GetMaxMineCount()
		{
			return NumberOFMines;
		}
		void BoardController::SetBoardstate(BoardState state)
		{
			boardState = state;
		}
		BoardState BoardController::GetBoardstate()
		{
			return boardState;
		}
		void BoardController::PopulateBoard(sf::Vector2i cellposition)
		{
			std::uniform_int_distribution<int>x_distribution(0, NumberOFColums - 1);
			std::uniform_int_distribution<int>y_distribution(0, NumberOfRows - 1);
			for (int a = 0; a < NumberOFMines; a++) {
			int i = static_cast<int>(x_distribution(randomEngine));
			int j = static_cast<int>(y_distribution(randomEngine));
			if (board[a][j]->GetCellValue() == CellValue::MINE | (cellposition.x == a && cellposition.y == j))a--;
			else board[i][j]->SetCellvalue(Gameplay::Cell::CellValue::MINE);
		}
			PopulateCells();
	}
		int BoardController::countMinesAround(sf::Vector2i cellposition)
		{
			int mines_around = 0;

			for (int a = -1; a < 2; a++)
			{
				for (int b = -1; b < 2; b++)
				{
					//If its the current cell, or cell position is not valid, then the loop will skip once
					if ((a == 0 && b == 0) || !isValidCellPosition(sf::Vector2i(cellposition.x + a, cellposition.y + b))) continue;

					if (board[a + cellposition.x][b + cellposition.y]->GetCellValue() == CellValue::MINE) mines_around++;
				}
			}

			return mines_around;
		}
		bool BoardController::isValidCellPosition(sf::Vector2i cellposition)
		{
			return(cellposition.x >= 0 && cellposition.y >= 0 && cellposition.x < NumberOFColums && cellposition.y < NumberOfRows);
		}
		void BoardController::PopulateCells()
		{
			for (int a = 0; a < NumberOfRows; a++)
			{
				for (int b = 0; b < NumberOFColums; b++)
				{
					if (board[a][b]->GetCellValue() != CellValue::MINE)
					{
						CellValue value = static_cast<CellValue>(countMinesAround(sf::Vector2i(a, b)));
						board[a][b]->SetCellvalue(value);
					}
				}
			}
		}
		BoardController::~BoardController()
		{
			Destroy();
		}
	}
}