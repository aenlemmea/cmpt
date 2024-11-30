#ifndef CMPT_FETCHERS_ONE_HH
#define CMPT_FETCHERS_ONE_HH

#include <optional>
#include "../../crow_include/crow.h"
#include "models/problem_model.hh"

namespace cmpt {
    class one {
    public:
        std::optional<bool> get_data();
        std::optional<bool> wrangle(const crow::json::rvalue& json_data);
        void show() const noexcept;
    private:
        constexpr static bool is_one = true;
        problem prob;
    };
};

#endif
