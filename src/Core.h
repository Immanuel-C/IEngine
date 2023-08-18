#pragma once

#ifdef IENGINE_DLL
#ifdef IENGINE_BUILD_DLL
#define IENGINE_API __declspec(dllexport)
#else
#define IENGINE_API __declspec(dllimport)
#endif
#else
#define IENGINE_API
#endif