#include"../../header/GamePlay/Cell/CellController.h"
#include"../../header/GamePlay/Cell/CellView.h"
#include"../../header/GamePlay/Cell/CellModel.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Sound/SoundService.h"
#include<iostream>
namespace Gameplay
{
	namespace Cell
	{
		using namespace sf;
		using namespace Global;
		using namespace Sound;
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
			std::cout << "Open cell is called" << std::endl;
			if (cellModel->GetCellState() !=CellState::FLAGGED) {

				cellModel->SetCellState(CellState::OPEN);
				
				std::cout << "Opening Cell! Value: " << static_cast<int>(cellModel->GetCellValue()) <<std::endl;
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			}
		}

		void CellController::FlagCell()
		{
			
			switch (cellModel->GetCellState()) {
			case::Gameplay::Cell::CellState::FLAGGED:
				cellModel->SetCellState(CellState::HIDDEN);
				break;
			case::Gameplay::Cell::CellState::HIDDEN:
				cellModel->SetCellState(CellState::FLAGGED);
				break;
			}
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::Flag);
		}
		
	}
}
