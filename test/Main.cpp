#include <IEngine.h>


class TestApp : public IEngine::Application {
public:
	TestApp() = default;
	~TestApp() = default;

	IWindow::Window* window = nullptr;

	void Start(const IEngine::CommandLineArguments& args, IWindow::Window* window) override {
		I_LOG_INFO("Created IEngine Application!");
		this->window = window;
	}

	void Update(double deltaTime) override {
	}

	void End() override {
		I_LOG_INFO("Destroyed IEngine Application!");
	}

};


// Client entry point
IEngine::Application* IEngine::CreateApplication() {
	return new TestApp;
}

