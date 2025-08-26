#pragma once

#include "lve_device.hpp"

#include <string>
#include <vector>

namespace lve
{
	struct PipelineConfigInfo 
	{
		
	};
	class LvePipeline
	{
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo configInfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		LveDevice& lveDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;

	public:
		LvePipeline(LveDevice &device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo configInfo);
		~LvePipeline() {};

		LvePipeline(const LvePipeline&) = delete;
		void operator=(const LvePipeline&) = delete;

		static PipelineConfigInfo deafultPipelineConfigInfo(uint32_t width, uint32_t heigth);
	};
}