#include "crow_include/crow.h"

#include "internal/fetchers/one.hh"
#include "internal/fetchers/contest.hh"

int main() {
    // cmpt::one one;
    // one.get_data();
    // one.show();

    cmpt::contest cont;
    cont.get_data_contest();
    cont.show();
}
