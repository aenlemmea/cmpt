#include "fetchers/one.hh"

namespace cmpt {
    std::optional<bool> one::get_data() {
        crow::SimpleApp app;

        CROW_ROUTE(app, "/").methods("POST"_method)([this, &app](const crow::request& req) {
            auto t_data = crow::json::load(req.body);
            if (!t_data) {
                std::cerr << "Invalid JSON data" << std::endl;
                return crow::response(400, "Invalid JSON data");
            } else {
                json_data = std::move(t_data);
            }

            app.stop();
            return crow::response(200);
        });
        std::cout << "Server is running on port 1327..." << std::endl;
        app
        .loglevel(crow::LogLevel::Critical)
        .port(1327)
        .run();

        std::cout << "Server stopped" << std::endl;
        return std::optional<bool>{true};
    }

    void one::show() const noexcept {
        std::cout << json_data.dump(4) << "\n";;
    }
};
