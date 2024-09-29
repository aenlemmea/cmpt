#ifndef ONE_H
#define ONE_H

#include "httplib.h"
#include "json.hpp"

struct one {
	bool do_fetch_one();
private:
	bool isFetched = false;
	nlohmann::json data_one;
	void fetch_one(httplib::Server& svr);
	bool create_directory(std::string& last_two);
	bool place_files();
	bool write_test_case(std::string& file_name);
	bool copy_template();
};


#endif
