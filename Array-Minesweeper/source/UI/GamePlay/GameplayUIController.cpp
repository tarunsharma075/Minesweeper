#include"../../header/UI/GamePlay/GameplayUIController.h"
#include"../../header/Global/ServiceLocator.h"
#include<sstream>
#include<iomanip>
namespace UI {
	namespace GameplayUI {
		using namespace UI::UIElement;
		using namespace Global;
		void GameplayUIController::createTexts()
		{
			time_text = new UI::UIElement::TextView();
			mine_text = new UI::UIElement::TextView();
		}
		void GameplayUIController::initializeTexts()
		{
			initializeTimeText();
			intializeMineText();
		}
		void GameplayUIController::initializeTimeText()
		{
			time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset), FontType::ROBOTO, font_size, text_color);
		}
		void GameplayUIController::intializeMineText()
		{
			mine_text->initialize("000", sf::Vector2f(mine_text_left_offset, mine_text_top_offset), FontType::ROBOTO, font_size, text_color);
		}
		void GameplayUIController::updateTimeText()
		{
			int remainingTime = ServiceLocator::getInstance()->getGameplayService()->RemainingTime();

			std::stringstream stream;
			stream << std::setw(3) << std::setfill('0') << remainingTime;
			std::string string_remaining_time = stream.str();

			time_text->setText(string_remaining_time);
			time_text->update();
		}
		void GameplayUIController::updateMineText()
		{
			int mines_count = ServiceLocator::getInstance()->getGameplayService()->GetMinesCount();

			std::stringstream stream;
			stream << std::setw(3) << std::setfill('0') << mines_count;
			std::string string_mine_count = stream.str();

			mine_text->setText(string_mine_count);
			mine_text->update();
		}
		void GameplayUIController::destroy()
		{
			delete(time_text);
			delete(mine_text);
		}
		GameplayUIController::GameplayUIController()
		{
			createTexts();
		}
		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}
		void GameplayUIController::initialize()
		{
			initializeTexts();
		}
		void GameplayUIController::update()
		{
			updateTimeText();
			updateMineText();
		}
		void GameplayUIController::render()
		{
			mine_text->render();
			time_text->render();
		}
		void GameplayUIController::show()
		{
			mine_text->show();
			time_text->show();
		}
	}
}