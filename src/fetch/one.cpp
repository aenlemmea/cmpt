// Comp Comp POST to listener.
// For open -> Grab last two part of url (E.g, /954/G)
// Turn it into a directory (E.g, G954) || Maybe allow a config setting to have the directory style as 954->G i.e a directory 954 (the contest id) and then G in it as a separate directory. 
// The config would allow easier grouping for later added fo problems.
// Create two files test_case.in & test_case.out in that directory 
// Write test_case.in; Put tests.input(s). Delimit each by ###
// Write test_case.out; Put tests.input(s). Delimit each by ###
// Copy default template to sol.cpp

#include "internal/one.hh"

void one::fetch_one(httplib::Server& svr) {
		svr.Post("/", [&](const httplib::Request& req, httplib::Response& res) {
			// cout << req.body << "\n";
			data_one = nlohmann::json::parse(req.body);
			res.status = 200;
			return true;
		});
		svr.listen("0.0.0.0", 10043);
	}

bool one::create_directory(std::string_view last_two) {
	// Grab context of where we are currently in directory path.
	// Directory name already exists (E.g, 954) -> Go inside, directory with problem hash_num (E.g, G) already exists -> WARN user. Exit.
	// Else create directory (E.g, 954) -> Create hash_num directory (E.g, G)
	return true;
}

bool one::place_files() {
	// Call write_test_case("in");
	// Call write_test_case("out");
	// Call copy_template();
	return true;
}

bool one::write_test_case(std::string_view file_name) {
	
	return true;
}

bool one::copy_template() {

	return true;
}
