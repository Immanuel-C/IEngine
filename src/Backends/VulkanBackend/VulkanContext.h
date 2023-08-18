#pragma once

#include <vulkan/vulkan.h>
#include <IWindow.h>
#include <IWindowVk.h>

#include "VulkanCheck.h"
#include "Core.h"

namespace IEngine {
	namespace Vk {
		class IENGINE_API Context {
		public:


			static Context& Get(IWindow::Window& window);

			~Context();

			void operator=(const Context&) = delete;
			Context(Context&) = delete;
		private:
			Context(IWindow::Window& window);

			// Vulkan Handles
			VkInstance m_vkInstance;
			// Create Functions
			void CreateVkInstance(IWindow::Window& window);

			static Context* m_instance;
		};
	}
}

