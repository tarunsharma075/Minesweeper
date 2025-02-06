#include"../../header/GamePlay/Cell/CellView.h"
#include"../../header/Global/Config.h"
#include"../../header/GamePlay/Cell/CellController.h"
#include"../../header/GamePlay/Cell/CellModel.h"
#include"../../header/Global/\ServiceLocator.h"
#include<iostream>
using namespace Global;
using namespace UI::UIElement;
using namespace sf;
using namespace std;
class  CellController;
namespace Gameplay
{
	using namespace sf;
	namespace Cell

		
	{

		CellView::CellView(CellController* Controller)
		{
			cellController = Controller;
			cellButton = new ButtonView();
		}
		void CellView::Intialize(float width, float height)
		{
			initializeButtonImage( width,  height);
		}
		void CellView::initializeButtonImage(float width, float height)

		{
			
			sf::Vector2f cell_screen_position = GetCellScreenPosition(width,height);
			cellButton->initialize("Cell", Config::cells_texture_path, width * sliceCount, height,cell_screen_position);
			RegisterCellButton();
		}
		
		void CellView::Update()
		{
			
			cellButton->update();
			SetTexture();
		}
		void CellView::Render()
		{
			
			cellButton->render();
			SetTexture();
		}
		void CellView::SetTexture()
		{
			int index = static_cast<int>(cellController->GetCellValue());

			switch (cellController->GetCellState()) {
			case::Gameplay::Cell::CellState::HIDDEN:
				cellButton->setTextureRect(sf::IntRect(10 * tile_size, 0, tile_size, tile_size));
				break;
			case::Gameplay::Cell::CellState::OPEN:
				cellButton->setTextureRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
				
				break;
				case::Gameplay::Cell::CellState::FLAGGED:
					cellButton->setTextureRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
					break;
			}
		}
		Vector2f CellView::GetCellScreenPosition(float width, float height)
		{
			Vector2i cellIndex = cellController->GetCellPosition();
			float xPosition = cellLeftOffset+cellIndex.y*width;
			float yPosition = cellTopOffset+cellIndex.x*height;
			return Vector2f(xPosition,yPosition);
		}
		void CellView::RegisterCellButton()
		{
			cellButton->registerCallbackFuntion(bind(&CellView::CellButtonCallBack, this, std::placeholders::_1));
		}
		void CellView::CellButtonCallBack(buttonType button)
		{
			
			ServiceLocator::getInstance()->getBoardService()->processInput(cellController, button);
		}
		CellView::~CellView()
		{
			delete cellButton;
		}
	}
}