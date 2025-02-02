#pragma once
#include"../../header/UI/UIElement/ButtonView.h"
#include"SFML/Graphics.hpp"
namespace Gameplay
{
	namespace Cell
	{

		class  CellController;
		class CellView {
		private:
			UI::UIElement::ButtonView* cellButton;
			CellController* cellController ;
			int tile_size = 32;
			int sliceCount = 12;
			const float cellTopOffset = 274.f;
			const float cellLeftOffset = 583.f;
		public:

			CellView(CellController* cellController);
			void Intialize(float width, float height);
			void initializeButtonImage(float width, float height);
			void Update();
			void Render();
			void SetTexture();
			sf::Vector2f GetCellScreenPosition(float width, float height);
			~CellView();


	};
	}
}