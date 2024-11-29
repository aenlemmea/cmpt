#ifndef CMPT_FETCHERS_ONE_HH
#define CMPT_FETCHERS_ONE_HH

#include <optional>
#include "../../crow_include/crow.h"

namespace cmpt {
    class one {
    public:
        std::optional<bool> get_data();
        std::optional<bool> wrangle() const;
        void show() const noexcept;
    private:
        crow::json::wvalue json_data;
    };
};

#endif
