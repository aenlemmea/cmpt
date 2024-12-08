#include "internal/config/config.hh"

void cmpt::config::deserialize() {
    try {
        auto data = crow::json::load(::readJsonToString(json_path));
        if (data) {
            if (data.has("default_template")) {
                const auto& def_template = data["default_template"];
                if (def_template.has("path") && def_template.has("name")) {
                    tmplmng.default_templ->path = def_template["path"].s();
                    tmplmng.default_templ->alias = def_template["name"].s();
                }
            }

            if (data.has("compile_flags")) {
                const auto& compile_flags_igot = data["compile_flags"];
                if (compile_flags_igot.has("g++")) {
                    compile_flags = compile_flags_igot["g++"]["base"].s();
                }
            }
        } else {
            throw std::runtime_error("Json config is missing or corrupted. Serialization failed.");
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Error during deserialization. Make sure the install script copied the template to ~/.cmptconf.json and the json is valid.");
    }
}
