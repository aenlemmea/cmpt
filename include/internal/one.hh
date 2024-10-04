#ifndef ONE_H
#define ONE_H

#include <string_view>

#include "httplib.h"
#include "json.hpp"

struct one {
    bool do_fetch_one();
    void show_data() const;

  private:
    bool isFetched = false;
    std::string_view contest_id, id_char;
    nlohmann::json data_one;
    void fetch_one(httplib::Server &svr);
    bool write_test_case(std::string_view file_name);
    bool copy_template();
    [[nodiscard]] bool create_directory();
    [[nodiscard]] bool place_files();
};

#endif
