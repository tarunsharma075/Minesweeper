#include"../../header/GamePlay/Board/BoardController.h"

namespace Gameplay
{
	
	namespace Board
	{
		using namespace sf;
		using namespace Gameplay::Cell;
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
		BoardController::~BoardController()
		{
			Destroy();
		}
	}
}