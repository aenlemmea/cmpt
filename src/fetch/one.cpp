// Comp Comp POST to listener.
// For open -> Grab last two part of url (E.g, /954/G)
// Turn it into a directory (E.g, G954) || Maybe allow a config setting to have the directory style as 954->G i.e a directory 954 (the contest id) and then G in it as a separate directory. 
// The config would allow easier grouping for later added fo problems.
// Create two files test_case.in & test_case.out in that directory 
// Write test_case.in; Put tests.input(s). Delimit each by ###
// Write test_case.out; Put tests.input(s). Delimit each by ###
// Copy default template to sol.cpp

#include "httplib.h"
#include "json.hpp"
#include "internal/one.hh"

void one::fetch_one(httplib::Server& svr) {
		svr.Post("/", [&](const httplib::Request& req, httplib::Response& res) {
			// cout << req.body << "\n";
			using json = nlohmann::json;
			json data = json::parse(req.body);
			std::cout << data.dump(4) << std::endl;
			res.status = 200;
			return true;
		});
		svr.listen("0.0.0.0", 10043);
	}
