#include"../../header/GamePlay/Cell/CellController.h"
#include"../../header/GamePlay/Cell/CellView.h"
#include"../../header/GamePlay/Cell/CellModel.h"

namespace Gameplay
{

	namespace Cell
	{
	
		using namespace sf;
		
		void CellController::destroy()
		{
			delete(cellView);
			delete(cellModel);
		}
		CellController::CellController(Vector2i position)
		{
			cellView = new CellView(this);
			cellModel = new CellModel(position);
		}
		CellController::~CellController()
		{
			destroy();
		}
		void CellController::initialize(float cellWidth, float cellHeight)
		{

			cellView->Intialize(cellWidth,cellHeight);
		}
		void CellController::update()
		{
			cellView->Update();
		}
		void CellController::render()
		{
			cellView->Render();
		}
		void CellController::reset()
		{
			cellModel->reset();
		}
		CellValue CellController::GetCellValue()
		{
			return cellModel->GetCellValue();
		}
		CellState CellController::GetCellState()
		{
			return cellModel->GetCellState();
		}
		sf::Vector2i CellController::GetCellPosition()
		{
			return cellModel->GetPosition();
		}

		void CellController::OpenCell()
		{
			if (cellModel->GetCellState() != CellState::HIDDEN) {
				cellModel->SetCellState(CellState::OPEN);
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			}
		}
		
	}
}
