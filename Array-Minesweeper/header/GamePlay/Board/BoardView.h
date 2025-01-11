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
			const float board_width = 866.f;
			const float board_height = 1080.f;


			void CreateBackGroundImages();
			void CreateBoardImage();
		public:
			BoardView(BoardController* controller);
			~BoardView();
			
			void initialize();
			void update();
			void render();
		};
	}
}