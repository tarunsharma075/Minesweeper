#include"../../header/GamePlay/Board/BoardController.h"
#include"../../header/GamePlay/Cell/CellModel.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Sound/SoundService.h"
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
			for (int i = 0; i <NumberOfRows; i++) {
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
		BoardController::BoardController()
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
			return NumberOFMines-flagged_cell;
		}
		void BoardController::OpenCell(sf::Vector2i cell_position)
		{
			if (board[cell_position.x][cell_position.y]->CanOpenCell())
			{
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
		BoardController::~BoardController()
		{
			Destroy();
		}
	}
}