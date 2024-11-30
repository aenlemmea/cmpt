#include "fetchers/contest.hh"

namespace cmpt {
    // GARBAGE WAY TO DO THIS.
    // TODO Extract this and one::get_data to one interface and modify runtime behaviour.
    // The fundamental difference is handling the wragling hence it cannot be done with a interface with this control flow.

    std::optional<bool> contest::get_data_contest() {
        crow::SimpleApp app;


        CROW_ROUTE(app, "/").methods("POST"_method)([this, &app](const crow::request& req) {
            auto t_data = crow::json::load(req.body);
            if (!t_data) {
                std::cerr << "Invalid JSON data" << std::endl;
                return crow::response(400, "Invalid JSON data");
            }

            // Yes in theory, fetch contest can fetch only one problem as well but we don't do it to ensure SoP.
            // t_data["batch"]["size"] is fixed per json so we can query it in runtime.
            // Don' ask. Yes I am NOT proud of this.
            if (is_many && t_data["batch"]["size"].i() == 1) {
                std::cout << ("You tried fetching a single problem with --fetch-contest (cry fc), use --fetch-one (cry fo) instead.") << "\n";
                exit(EXIT_FAILURE);
            }

            if (received_blocks >= t_data["batch"]["size"].i()) {
                app.stop();
            }
            received_blocks += 1;
            wrangle_contest(t_data, received_blocks);
            return crow::response(200);
        });
        std::cout << "Server is running on port 1327..." << std::endl;

        app
        .loglevel(crow::LogLevel::Critical)
        .multithreaded()
        .port(1327)
        .run();


        std::cout << "Server stopped" << std::endl;
        return std::optional<bool>{true};
    }

    std::optional<bool> contest::wrangle_contest(crow::json::rvalue& t_data, uint16_t& received_blocks) {
        one o;
        o.wrangle(t_data);
        cntst_problems.emplace_back(o);
        return std::optional<bool>{ true };
    }

    void contest::show() const noexcept {
        for (const auto& o : cntst_problems) {
            o.show();
        }
    }
};
