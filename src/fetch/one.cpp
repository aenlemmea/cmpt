// Comp Comp POST to listener.
// For open -> Grab last two part of url (E.g, /954/G)
// Turn it into a directory (E.g, G954) || Maybe allow h by ###
// Write test_case.out; Put tests.input(s). Delimit each by ###
// Copy default template to sol.cpp

#include "internal/one.hh"
#include <filesystem>

void one::fetch_one(httplib::Server& svr) {
                svr.Post("/", [&](const httplib::Request& req, httplib::Response& res) {
                        // cout << req.body << "\n";
                        data_one = nlohmann::json::parse(req.body);
                        res.status = 200;
                        return true;
                });
                svr.listen("0.0.0.0", 10043);
        }

bool one::create_directory() {
        namespace fs = std::filesystem;
  
        fs::path cwd = fs::current_path();
        fs::path new_dir = cwd / contest_id / id_char;

	if (fs::exists(new_dir)) {
	  return false;
	}

	try {
	  fs::create_directory(new_dir);
	} catch (const fs::filesystem_error& e) {
	  return false;
	}
  
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
