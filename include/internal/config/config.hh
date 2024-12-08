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
        const std::string json_path = ::getHomeDirectory() + "/.cmpt/cmptconf.json";
        template_manager tmplmng;
        std::string compile_flags;
    };
};


#endif
