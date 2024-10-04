// Turn it into a directory (E.g, G954) || Maybe allow h by ###
// Write test_case.out; Put tests.input(s). Delimit each by ###
// Copy default template to sol.cpp

#include "internal/one.hh"
#include <cstdlib>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void one::fetch_one(httplib::Server &svr) {
    svr.Post("/", [&](const httplib::Request &req, httplib::Response &res) {
        std::cout << req.body << "\n";
        data_one = nlohmann::json::parse(req.body);
        res.status = 200;
        return true;
    });
    svr.listen("0.0.0.0", 10043);
}

bool one::create_directory() {
    const fs::path new_dir = fs::current_path() / contest_id / id_char;

    if(fs::exists(new_dir)) {
        return false;
    }
    try {
        fs::create_directory(new_dir);
    } catch(const fs::filesystem_error &e) { return false; }

    return true;
}

bool one::write_test_case(std::string_view file_name) {
    const fs::path c_file
      = fs::current_path() / contest_id / id_char / file_name;

    std::ofstream file(c_file);
    if(file.is_open()) {
        // Write to file based on the type
        if(file_name == "in") {
            // file << test_case_input;
        } else if(file_name == "out") {
        } else {
            return false;
        }
        file.close();
        return true;
    }
    return false;
}

bool one::copy_template() { return true; }

bool one::place_files() {
    // Call write_test_case("in");
    // Call write_test_case("out");
    // Call copy_template();
    if(this->create_directory()) {
        write_test_case("in");
        write_test_case("out");
        copy_template();
        return true;
    } else
        return false;
}

bool one::do_fetch_one() {
  // if(place_files()) {
  //   return true;
  // } else {
  //   return false;
  // }
  httplib::Server svr;

  fetch_one(svr);
}
