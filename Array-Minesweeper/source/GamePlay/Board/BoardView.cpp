#include"../../header/GamePlay/Board/BoardView.h"
#include"../../header/GamePlay/Board/BoardController.h"
#include"../../header/Global/Config.h"
#include"../../header/Global/ServiceLocator.h"
namespace Gameplay
{
	namespace Board
	{
		void BoardView::CreateBackGroundImages()
		{
			sf::RenderWindow* gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			backgroundImage->initialize(Global::Config::background_texture_path,
				gameWindow->getSize().x,
				gameWindow->getSize().y,
				sf::Vector2f(0, 0));

			backgroundImage->setImageAlpha(background_alpha);
		}
		void BoardView::CreateBoardImage()
		{
			boardImage->initialize(Global::Config::board_texture_path,
				boardWidth,
				boardHeight,
				sf::Vector2f(0, 0));
			boardImage->setCentreAlinged();
		}
		BoardView::BoardView(BoardController* controller)
		{
			board_controller = controller;
			backgroundImage = new ImageView();
			boardImage = new ImageView();
			

		}
		BoardView::~BoardView()
		{
			delete(backgroundImage);
			delete(boardImage);
			
		}

		void BoardView::initialize()
		{
			CreateBackGroundImages();
			CreateBoardImage();
		}

		void BoardView::update()
		{
			backgroundImage->update();
			boardImage->update();
		}

		void BoardView::render()
		{
			backgroundImage->render();
			boardImage->render();
		}

		float BoardView::GetCellWidth()
		{
			return (boardWidth - boardWidthOffset) / static_cast<float>(BoardController::NumberOFColums);
		}

		float BoardView::GetCellHeight()
		{
			return (boardHeight - boardHeightoffset) / static_cast<float>(BoardController::NumberOfRows);
		}
		
	
	}
}