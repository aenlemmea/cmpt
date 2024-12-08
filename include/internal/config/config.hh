#ifndef CMPT_CONFIG_HH
#define CMPT_CONFIG_HH

#include "template_manager.hh"
#include "../filetils.hh"
#include "../../crow_include/crow.h"

namespace cmpt {
    class config {
    public:

        config() {
            deserialize();
        }

        void serialize(); // TODO Will do this when I want to support additional templates additions.
        void deserialize();

        templ& get_template() const {
            if(!tmplmng.default_templ) throw std::runtime_error("Template not available");
            return *tmplmng.default_templ;
        }
        const std::string& get_compile_flags() const {
            if (compile_flags.empty()) throw std::runtime_error("Cannot fetch compile_flags");
            return compile_flags;
        }

        void show() const {
            std::cout << "compile_flags: " << compile_flags
            << " \ntmplmng.default_templ.path: " << tmplmng.default_templ->path << " \ntmplmng.default_templ.alias: " << tmplmng.default_templ->alias << "\n";
        }

    private:
        bool set_template();
        const std::string json_path = ::getHomeDirectory() + "/.cmptconf.json";
        template_manager tmplmng;
        std::string compile_flags;
    };
};


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


#endif
