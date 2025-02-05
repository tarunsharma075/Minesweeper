#include"../../header/UI/GamePlay/GameplayUIController.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Global/Config.h"
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
		void GameplayUIController::createButton()
		{
			restart_button = new ButtonView();
		}
		void GameplayUIController::initializeTexts()
		{
			initializeTimeText();
			intializeMineText();
		}
		void GameplayUIController::intializeButton()
		{
			intializeRestartButton();
		}
		void GameplayUIController::initializeTimeText()
		{
			time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset), FontType::ROBOTO, font_size, text_color);
		}
		void GameplayUIController::intializeMineText()
		{
			mine_text->initialize("000", sf::Vector2f(mine_text_left_offset, mine_text_top_offset), FontType::ROBOTO, font_size, text_color);
		}
		void GameplayUIController::intializeRestartButton()
		{
			restart_button->initialize("Restart Button",
				Config::restart_button_texture_path,
				button_width, button_height,
				sf::Vector2f(restart_button_left_offset, restart_button_top_offset));
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
		void GameplayUIController::registerButtonCallback()
		{
			restart_button->registerCallbackFuntion(std::bind(&GameplayUIController::restartButtonCallback, this));
		}
		void GameplayUIController::restartButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getGameplayService()->StartGame();
		}
		void GameplayUIController::destroy()
		{
			delete(time_text);
			delete(mine_text);
			delete(restart_button);
		}
		GameplayUIController::GameplayUIController()
		{
			createTexts();
			createButton();
		}
		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}
		void GameplayUIController::initialize()
		{
			initializeTexts();
			intializeButton();
		}
		void GameplayUIController::update()
		{
			updateTimeText();
			updateMineText();
			restart_button->update();
		}
		void GameplayUIController::render()
		{
			mine_text->render();
			time_text->render();
			restart_button->render();
		}
		void GameplayUIController::show()
		{
			mine_text->show();
			time_text->show();
			restart_button->show();
		}
	}
}