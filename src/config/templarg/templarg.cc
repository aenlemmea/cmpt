// TODO: Add support for multi templates saving. Currently we restrict to saving only one template.
#include <json.hpp>

class templarg {
	

	private:
		nlohmann::json templates;
		uint8_t default_template;
};
