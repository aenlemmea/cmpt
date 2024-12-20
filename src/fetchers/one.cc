#include "fetchers/one.hh"
#include <stdexcept>
#include <ranges>

namespace cmpt {

    std::optional<bool> one::get_data() {
        crow::SimpleApp app;

        CROW_ROUTE(app, "/").methods("POST"_method)([this, &app](const crow::request& req) {
            auto t_data = crow::json::load(req.body);
            if (!t_data) {
                std::cerr << "Invalid JSON data" << std::endl;
                return crow::response(400, "Invalid JSON data");
            }

            app.stop();
            wrangle(t_data);
            return crow::response(200);
        });
        std::cout << "Server is running on port 1327..." << std::endl;
        app
        .loglevel(crow::LogLevel::Critical)
        .multithreaded()
        .port(1327)
        .run();

        if (is_one && prob.batch.size > 1) throw std::runtime_error("You tried fetching a contest with --fetch-one (cry fo), use --fetch-contest (cry fc) instead. Did you Ctrl-C abruptly?");

        std::cout << "Server stopped" << std::endl;

        return std::optional<bool>{true};
    }


    // TODO: Experiment with rejecting early any thing other than the last char (problem id) and the numeric contest id. So prob.url_vec can be reserved to size 2.
    void one::process_url(std::string& url) {
        // https://stackoverflow.com/a/68121694
        auto split = url | std::ranges::views::split('/')
        | std::ranges::views::transform([](auto&& str) { return std::string_view(&*str.begin(),        std::ranges::distance(str)); });

        for(auto&& word : split) {
            prob.url_vec.push_back(std::string(word));
        }
    };

    std::optional<bool> one::wrangle(const crow::json::rvalue& json_data) {
        prob.name = json_data["name"].s();
        prob.group = json_data["group"].s();
        prob.url = json_data["url"].s();
        process_url(prob.url);
        prob.testType = json_data["testType"].s();
        prob.batch.id = json_data["batch"]["id"].s();
        prob.batch.size = json_data["batch"]["size"].i(); // We know that this will be one because of this class but still parse it for later use.

        for (auto& test : json_data["tests"]) {
            prob.tests.emplace_back(test["input"].s(), test["output"].s());
        }
        prob.numTestCases = prob.tests.size();
        return std::optional<bool> { true };
    }

    // Alternate way to get the dirname.
    const std::string one::get_contest_num() {

        auto isNumber = [](const std::string& str) -> bool {
            if(str.empty()) return false;
            size_t i = 0;
            if (str[0] == '+' || str[0] == '-') i = 1;

            bool hasDigits = false, hasDecimalPoint = false;
            for (; i < str.size(); ++i) {
                if (std::isdigit(str[i])) {
                    hasDigits = true;
                } else if (str[i] == '.' && !hasDecimalPoint) {
                    hasDecimalPoint = true;
                } else {
                    return false;
                }
            }
            return hasDigits;
        };

        for (const auto& st : prob.url_vec) {
            if (isNumber(st)) {
                // ul + penul
                return st;
            }
        }
        return "E69420";
    }

    // I know I know I should define this in problem.hh but doing so gives weird linker errors.
    // BUG Investigate why the linker errors happen.
    std::ostream& operator<<(std::ostream& os, const problem& p) {
        os << "{ \n\tname: " << p.name
        << ", \n\tgroup: " << p.group
        << ", \n\turl: " << p.url
        << ", \n\ttestType: " << p.testType
        << ", \n\tnumTestCases: " << p.numTestCases
        << ", \n\ttests: [";
        // If you are seeing borked tests output, don't fix it. Fixing it would break dumping into file.
        for (const auto& a : p.tests) {
            os << " \n\t\tinput: " << a.input << "\n";
            os << " \n\t\toutput: " << a.output << "\n";
        }
        os << "\t]"
        << ", \n\tbatch.id: " << p.batch.id
        << ", \n\tbatch.size: " << p.batch.size
        << " \n}";
        return os;
    }


    void one::show() const noexcept {
        std::cout << prob << "\n";
    }
};
