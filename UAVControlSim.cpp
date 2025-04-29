// UAVControlSim.cpp : Defines the entry point for the application.
//



#include "HardwareAbstractionLayer.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <thread>
#include <chrono>
#include <string>  // for string, allocator, basic_string
#include <vector>  // for vector

#include "ftxui/component/captured_mouse.hpp"      // for ftxui



#include <iostream>

using namespace std;
using namespace ftxui;

Component DummyWindowContent() {
	class Impl : public ComponentBase {
	private:
		bool checked[3] = { false, false, false };
		float slider = 50;

	public:
		Impl() {
			Add(Container::Vertical({
				Checkbox("Check me", &checked[0]),
				Checkbox("Check me", &checked[1]),
				Checkbox("Check me", &checked[2]),
				Slider("Slider", &slider, 0.f, 100.f),
				}));
		}
	};
	return Make<Impl>();
}

int main(void)
{

	//   HardwareAbstractionLayer hal;

	//   std::cout << "Starting UAV Control Simulation..." << std::endl;

	//   for (int i = 0; i < 20; ++i) { // Run 20 iterations
	//       SensorData data = hal.sensor.readSensors();
	//       ControlCommand cmd = hal.control.computeControl(data);
	//       hal.command.sendCommand(cmd);

	//       std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 2Hz loop
	//   }

	//   std::cout << "Simulation ended." << std::endl;
	   //cout << "Hello CMake." << endl;



	int window_1_left = 0;
	int window_1_top = 0;
	int window_1_width = 35;
	int window_1_height = 15;
	WindowOptions opt;
	opt.inner = DummyWindowContent();
	opt.title = "First window";
	opt.left = &window_1_left;
	opt.top = &window_1_top;
	opt.width = &window_1_width;
	opt.height = &window_1_height;

	WindowOptions opt2;
	opt2.inner = DummyWindowContent();
	opt2.title = "My window";
	opt2.left = 60;
	opt2.top = 30;


	auto window_1 = Window({

	   opt
		});

	auto window_2 = Window({
	   opt2
		});

	auto window_container = Container::Stacked({
	  window_1,
	  window_2

		});

	auto display_win_1 = Renderer([&] {
		return text("window_1: " +  //
			std::to_string(window_1_width) + "x" +
			std::to_string(window_1_height) + " + " +
			std::to_string(window_1_left) + "," +
			std::to_string(window_1_top));
		});

	auto layout = Container::Vertical({
	 display_win_1,
	 window_container,
		});

	auto screen = ScreenInteractive::Fullscreen();
	screen.Loop(layout);

	return EXIT_SUCCESS;

	//return 0;
}
