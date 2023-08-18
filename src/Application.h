#pragma once

#include "Core.h"
#include "Backends/VulkanBackend/VulkanContext.h"

#include <vector>
#include <IWindow.h>
#include <ILog.h>
#include <iostream>



namespace IEngine {
	typedef std::vector<const char*> CommandLineArguments;

	class IENGINE_API Application {
	public:
		Application() {}
		~Application() {}

		virtual void Start(const CommandLineArguments& args, IWindow::Window* window) {}
		virtual void Update(double deltaTime) {}
		virtual void End() {}

		void Run(int argc, char** argv);
	};

	// Defined in Client
	Application* CreateApplication();
}