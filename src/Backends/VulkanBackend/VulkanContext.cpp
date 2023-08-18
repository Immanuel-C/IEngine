#include "VulkanContext.h"



namespace IEngine {
	namespace Vk {
		Context* Context::m_instance;

		Context& Context::Get(IWindow::Window& window) {
			if (m_instance == nullptr)
				m_instance = new Context(window);


			return *m_instance;
		}

		Context::~Context() {
			delete m_instance;
		}

		Context::Context(IWindow::Window& window) {
			CreateVkInstance(window);
		}

		void Context::CreateVkInstance(IWindow::Window& window) {
			// Application info for debugging and set Vulkan version
			VkApplicationInfo appInfo{};
			appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
			appInfo.pApplicationName = "IEngine::Application";
			appInfo.applicationVersion = VK_MAKE_API_VERSION(1, 0, 0, 0);
			appInfo.pEngineName = "IEngine";
			appInfo.engineVersion = VK_MAKE_API_VERSION(1, 0, 0, 0);
			appInfo.apiVersion = VK_API_VERSION_1_3;


			VkInstanceCreateInfo instanceCreateInfo{};
			instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			instanceCreateInfo.pApplicationInfo = &appInfo;

			std::vector<const char*> instanceExtensions{};

			IWindow::Vk::GetRequiredInstanceExtensions(instanceExtensions);

			instanceCreateInfo.enabledExtensionCount = instanceExtensions.size();
			instanceCreateInfo.ppEnabledExtensionNames = instanceExtensions.data();

			instanceCreateInfo.enabledLayerCount = 0;

			VK_CHECK(vkCreateInstance(&instanceCreateInfo, nullptr, &m_vkInstance));


		}
	}
}