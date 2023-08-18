#include "Application.h"


namespace IEngine {
	void Application::Run(int argc, char** argv) {
		CommandLineArguments args{};

		for (int i = 0; i < argc; i++) 
			args.push_back(argv[i]);

		IWindow::Window window{};

		I_ASSERT_FATAL_ERROR(!window.Create(800, 600, "IEngine::Application"), "Failed to create window!");

		Vk::Context& context = Vk::Context::Get(window);

		Start(args, &window);
		double currTime = window.GetTime(), prevTime = 0.0;
		while (window.IsRunning()) { 
			currTime = window.GetTime();
			window.Update();
			Update(currTime - prevTime); 
			prevTime = currTime;
		}
		End();

	}
}