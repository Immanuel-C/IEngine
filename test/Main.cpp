#include <IEngine.h>


class TestApp : public IEngine::Application {
public:
	TestApp() = default;
	~TestApp() = default;

	IWindow::Window* window = nullptr;

	void Start(const IEngine::CommandLineArguments& args, IWindow::Window* window) override {
		I_LOG_INFO("Created IEngine Application!");
		this->window = window;
		IWindow::Monitor monitor = window->GetPrimaryMonitor();

		//window->Fullscreen(true, monitor);
		window->SetTitle("IEngine Test Application");
		window->SetWindowSize(1280, 720);
	}

	void Update(double deltaTime) override {
		I_LOG_INFO("Delta Time: %f", deltaTime);
	}

	void End() override {
		I_LOG_INFO("Destroyed IEngine Application!");
	}

};


// Client entry point
IEngine::Application* IEngine::CreateApplication() {
	return new TestApp;
}

