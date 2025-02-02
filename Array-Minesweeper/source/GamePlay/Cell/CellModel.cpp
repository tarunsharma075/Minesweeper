#include"../../header/GamePlay/Cell/CellModel.h"


namespace Gameplay
{
	namespace Cell
	{
        using namespace sf;
      
        CellModel::CellModel(Vector2i Position)
        {
            this->cellposition = Position;
        }

        CellState CellModel::GetCellState()
        {
            return cellState;
        }
        void CellModel::SetCellState(CellState state)
        {
            cellState = state;
        }
        CellValue CellModel::GetCellValue()
        {
            return cellValue;
        }
        void CellModel::SetCellValue(CellValue value)
        {
            cellValue = value;
        }
        sf::Vector2i CellModel::GetPosition()
        {
            return cellposition;
        }
        void CellModel::SetCellPosition(sf::Vector2i gridPosition)
        {
            cellposition = gridPosition;
        }
        void CellModel::reset()
        {
           cellState = CellState::HIDDEN;
           cellValue = CellValue::EMPTY;
        }
       
       
    }
}