#pragma once
#include<chrono>
namespace Time {
	class TimeService {
	private:
		std::chrono::steady_clock::time_point previousTime;
		float deltaTime;
		void UpdateDeltaTime();
		float CalculateDeltaTime();
		void UpdatePreviousTime();
	public:
		void initialize();
		void update();
		float getDeltaTime();
	};
}