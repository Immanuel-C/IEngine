#pragma once

#ifdef IE_BUILD_DLL
#define IENGINE_API __declspec(dllexport)
#else
#define IENGINE_API __declspec(dllimport)
#endif