#include"../../header/Time/TimeService.h"
using namespace std::chrono;
namespace Time {
	void TimeService::UpdateDeltaTime()
	{
		deltaTime = CalculateDeltaTime();
		UpdatePreviousTime();
	}
	void TimeService::initialize()
	{
		previousTime = steady_clock::now();
		deltaTime = 0;
	}
	void TimeService::update()
	{
		UpdateDeltaTime();
	}
	float TimeService::getDeltaTime()
	{
		return deltaTime ;
	}
	float TimeService::CalculateDeltaTime()
	{
		int delta = duration_cast<microseconds>(steady_clock::now() - previousTime).count();
		return static_cast<float>(delta) / 1000000.0f;
	}
	void TimeService::UpdatePreviousTime()
	{
		previousTime = steady_clock::now();
	}
}