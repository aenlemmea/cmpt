#ifndef CMPT_FETCHERS_CONTEST_HH
#define CMPT_FETCHERS_CONTEST_HH

#include <optional>
#include <cstdint>
#include <vector>
#include "fetchers/one.hh"

namespace cmpt {
    class one;
}

namespace cmpt {
    class contest {
    public:
        void show() const noexcept;

        std::vector<one>& expose_contest() {
            return cntst_problems;
        }


        std::optional<bool> get_data_contest();
    private:
        std::optional<bool> wrangle_contest(crow::json::rvalue& json_data, uint16_t& received_blocks);
        std::vector<one> cntst_problems;
        constexpr static bool is_many { true };
        uint16_t received_blocks { 1 };
    };
};

#endif
