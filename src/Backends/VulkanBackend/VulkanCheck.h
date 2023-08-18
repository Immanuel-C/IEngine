#pragma once

#include <ILog.h>

#include <vulkan/vulkan.h>
#include <vulkan/vk_enum_string_helper.h>

#define VK_CHECK(x)															\
	VkResult err = x;														\
	if (err) I_LOG_FATAL_ERROR("Vulkan Error: %s", string_VkResult(err));