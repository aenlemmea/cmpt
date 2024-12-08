#include "internal/config/config.hh"
#include "internal/fetchers/one.hh"
#include "internal/fetchers/contest.hh"


/**
 * Ultimate executor class
 * Mostly responsible for file manip.
 *
 */
namespace cmpt {
    class execf {
        /** Flow (fo) : fetch the problem. Create the first directory with url's penultimate parameter (name: rdir).
         * Go inside that directory. Create another directory with rdir + url's ultimate parameter.
         * Go inside that directory. Copy file sol.cpp from config's default template path.
         *
         * Make two files test.in and test.out. Dump prob.__test.input and prob.__test.output in them.
         */
        void execute_one_ult() {
            one o;
            o.get_data();

        }

        void execute_contest_ult() {

        }
    };
};
