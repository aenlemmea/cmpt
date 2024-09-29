#ifndef ONE_H
#define ONE_H

#include <string_view>

#include "httplib.h"
#include "json.hpp"

struct one {
	bool do_fetch_one();
private:
	bool isFetched = false;
	nlohmann::json data_one;
	void fetch_one(httplib::Server& svr);
	[[nodiscard]] bool create_directory(std::string_view last_two);
	[[nodiscard]] bool place_files();
	[[nodiscard]] bool write_test_case(std::string_view file_name);
	[[nodiscard]] bool copy_template();
};


#endif
