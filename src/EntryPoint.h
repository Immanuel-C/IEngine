#pragma once

#include "Application.h"


extern IEngine::Application* IEngine::CreateApplication();


int main(int argc, char** argv) {
	IEngine::Application* app{ IEngine::CreateApplication() };
	app->Run(argc, argv);
	return 0;
}
