#include"../../header/GamePlay/Board/BoardController.h"
namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		void  BoardController::CreateBoards()
		{
		}
		void BoardController::DeleteBoard()
		{
		}
		void BoardController::Destroy()
		{
		}
		BoardController::BoardController()
		{
			boardView = new BoardView(this);
		}
		void BoardController::initialize()
		{
			boardView->initialize();
		}
		void BoardController::Update()
		{
			boardView->update();
		}
		void BoardController::Render()
		{
			boardView->render();
		}
		void BoardController::Reset()
		{
		}
		BoardController::~BoardController()
		{
			delete(boardView);
		}
	}
}