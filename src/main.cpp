#include "internal/fetchers/one.hh"
#include "internal/fetchers/contest.hh"

#include "internal/config/config.hh"

int main() {
    cmpt::one one;
    one.get_data();
    one.show();
/*
    cmpt::contest cont;
    cont.get_data_contest();
    cont.show();*/

    cmpt::config cnf;

    cnf.show();

}
