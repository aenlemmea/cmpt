#ifndef CMPT_TEMPLATE_HH
#define CMPT_TEMPLATE_HH

#include <string>
#include <vector>
#include <memory>

namespace cmpt {

    struct templ {
        std::string path {};
        std::string alias {};
    };

    class template_manager {
    public:
        template_manager() {
            default_templ = std::make_unique<templ>();
        }
        void show_available_templates() const;
        friend class config;
    private:
        std::unique_ptr<templ> default_templ;
        std::vector<templ> available;
    };
}

#endif
