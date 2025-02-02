#pragma once
#include"SFML/Graphics.hpp"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Sound/SoundService.h"
namespace Gameplay
{
	using namespace Global;
	using namespace Sound;
	namespace Cell
	{
		class CellView;
		class CellModel;
		enum class CellState;
		enum class CellValue;
		class CellController {
		private:
			CellView* cellView;
			CellModel* cellModel;
			void destroy();
		public:
			CellController(sf::Vector2i position);
			~CellController();

			void initialize(float cellWidth,float cellHeight);
			void update();
			void render();
			void reset();
			CellValue GetCellValue();
			CellState GetCellState();
			sf::Vector2i GetCellPosition();
			void OpenCell();
			
		};
	}
}