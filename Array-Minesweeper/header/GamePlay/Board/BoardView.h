#pragma once
#include"../../header/UI/UIElement/ImageView.h"
using namespace UI::UIElement;
namespace Gameplay
{
	namespace Board
	{


		class BoardController;
	
		class BoardView {
		private:
			BoardController* board_controller;

			//background characterstics
			ImageView* backgroundImage;
			const float background_alpha = 85.f;

			// board characterstics

			ImageView* boardImage;
			const float boardWidth = 866.f;
			const float boardHeight = 1080.f;

			const float boardWidthOffset = 115.f;
			const float boardHeightoffset = 329.f;



			void CreateBackGroundImages();
			void CreateBoardImage();
		public:
			BoardView(BoardController* controller);
			~BoardView();
			
			void initialize();
			void update();
			void render();
			float GetCellWidth();
			float GetCellHeight();
		};
	}
}