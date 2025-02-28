#include"../../header/GamePlay/Board/BoardService.h"
#include<iostream>
namespace Gameplay
{
	namespace Board
	{
		
		BoardService::BoardService()
		{
			boardController = nullptr;
			boardController = new BoardController();
			
		}
		BoardService::~BoardService()
		{
			destroy();
		}
		void BoardService::Intialize()
		{
			
			boardController->initialize();
		}
		void BoardService::Update()
		{
			boardController->Update();
		}
		void BoardService::Render()
		{
			boardController->Render();
		}
		void BoardService::ResetBoard()
		{
			boardController->Reset();
		}

		void BoardService::destroy()
		{
			delete(boardController);
		}

		
	}
}