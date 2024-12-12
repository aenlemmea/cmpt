#ifndef CMPT_FETCHERS_ONE_HH
#define CMPT_FETCHERS_ONE_HH

#include <optional>
#include "../../crow_include/crow.h"
#include "models/problem_model.hh"
#include "contest.hh"

namespace cmpt {
    /**
     * One plays a dual role, it represents a single problem item "fully" as well as an container to store problem without needing to fetch it itself. It can fetch if using "fully".
     *
     * This allows contest class to use one has a building block.
     */
    class one {
    public:
        std::optional<bool> get_data();

        void show() const noexcept;

        const std::string get_contest_num();

        const std::string& get_prob_name() {
            return prob.url_vec.back();
        }

        const std::vector<__test>& get_prob_tests() {
            return prob.tests;
        }

        friend class contest;
    private:
        void process_url(std::string& url);
        std::optional<bool> wrangle(const crow::json::rvalue& json_data);
        constexpr static bool is_one = true;
        problem prob;
    };
};

#endif
