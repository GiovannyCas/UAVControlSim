// UAVControlSim.cpp : Defines the entry point for the application.
//



#include "HardwareAbstractionLayer.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <chrono>
#include <string>  // for string, allocator, basic_string
#include <vector>  // for vector

#include "ftxui/component/captured_mouse.hpp"      // for ftxui



#include <iostream>

using namespace std;
using namespace ftxui;

Component DroneWindowContent() {
	class Impl : public ComponentBase {

	private:
		HardwareAbstractionLayer hal;
		SensorData data;
		bool checked[3] = { false, false, false };
		float slider = 50;


	public: 


		Impl() {
			SensorData data = hal.sensor.readSensors();
			auto lorel_ipsum = Renderer([&] {
				return vbox({
					hbox({text("Latitude"), separatorLight(), text(to_string(data.latitude))}) | borderLight,
					hbox({text("Altitude"), separatorLight(), text(to_string(data.altitude))}) | borderLight,
					hbox({text("Longitude"), separatorLight(), text(to_string(data.longitude))}) | borderLight,
					hbox({text("Velocity"), separatorLight(), text(to_string(data.velocity))}) | borderLight,
					});
				});
			Add(Container::Vertical({
				lorel_ipsum,

				Slider("Slider", &slider, 0.f, 100.f),
				}));
		}
	};
	return Make<Impl>();
}

Component ControlWindowContent() {
	class Impl : public ComponentBase {
	private:

		bool checked[3] = { false, false, false };
		float slider = 50;

	public:
		Impl() {
			auto cell = [](const char* t) { return text(t) | border; };
			auto lorel_ipsum = Renderer([&] {
				return vbox({
					gridbox({
						{
							/*cell(""),
							cell("north"),
							cell(""),*/
							filler(),
						},
						{
							//cell(""),
							gridbox({
							{
								cell(""),
								cell("     W"),
								cell(""),
							},
							{
								cell("     A"),
								cell("center"),
								cell("     D"),
								
							},
							{
								cell(""),
								cell("     S"),
								cell(""),
							},
							}),
							//cell(""),
						},
						{
						/*	cell(""),
							cell("south"),
							cell(""),*/
							filler(),
						},
					}),

					});
				});
			Add(Container::Vertical({
				lorel_ipsum,

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


	//window 1
	int window_1_left = 0;
	int window_1_top = 0;
	int window_1_width = 45;
	int window_1_height = 15;
	//window 2
	int window_2_left = 46;
	int window_2_top = 13;
	int window_2_width = 59;
	int window_2_height = 17;

	WindowOptions opt;
	opt.inner = DroneWindowContent();
	opt.title = "Drone"; 
	opt.left = &window_1_left;
	opt.top = &window_1_top;
	opt.width = &window_1_width;
	opt.height = &window_1_height;

	WindowOptions opt2;
	opt2.inner = ControlWindowContent();
	opt2.title = "Control";
	opt2.left = &window_2_left;
	opt2.top = &window_2_top;
	opt2.width = &window_2_width;
	opt2.height = &window_2_height;


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
			std::to_string(window_2_width) + "x" +
			std::to_string(window_2_height) + " + " +
			std::to_string(window_2_left) + "," +
			std::to_string(window_2_top));
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
