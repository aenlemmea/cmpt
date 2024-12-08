#ifndef CMPT_FETCHERS_ONE_HH
#define CMPT_FETCHERS_ONE_HH

#include <optional>
#include "../../crow_include/crow.h"
#include "models/problem_model.hh"
#include "contest.hh"

namespace cmpt {
    class one {
    public:
        std::optional<bool> get_data();
        void show() const noexcept;

        const std::string get_full_dirname();

        const problem& expose_prob() const noexcept {
            return prob;
        }

        friend class contest;
    private:
        std::optional<bool> wrangle(const crow::json::rvalue& json_data);
        constexpr static bool is_one = true;
        problem prob;
    };
};

#endif
