#pragma once
#include"../../header/UI/UIElement/ButtonView.h"
#include"../../header/GamePlay/Cell/CellController.h"
namespace Gameplay
{
	namespace Cell
	{
		class CellView {

		private:
			UI::UIElement::ButtonView* cellButton;
			CellController* cellController;
		public:
			CellView(CellController* controller);
			void intilaize();
			void update();
			void render();
			
				


		};

	}

}