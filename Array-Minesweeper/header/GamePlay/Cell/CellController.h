#pragma once
#include"../../header/GamePlay/Cell/CellModel.h"
#include"../../header/GamePlay/Cell/CellView.h"
namespace Gameplay
{
	namespace Cell
	{
		class CellController {

		private:
			CellModel* cellView;
			CellModel& cellModel;
		public:
			CellController();
			~CellController();

		};

	}
}