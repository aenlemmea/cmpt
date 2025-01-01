#ifndef CMPT_EXECF_HH
#define CMPT_EXECF_HH

#include "config/config.hh"
#include "fetchers/one.hh"
#include "fetchers/contest.hh"

/**
 * Ultimate executor class
 * Mostly responsible for file manip.
 *
 * Maybe this can be deprecated in favour of a anon namespace directly in the impl.
 */
namespace cmpt {
    class execf {
    public:
        void execute_one_ult(config& cnf, one& o, const bool isContest);
        void execute_contest_ult(config& cnf);

    };
};

#endif
