#include "execf.hh"

int main() {
    cmpt::one aprob;
    cmpt::config cnf;
    cmpt::execf exe;
    // exe.execute_one_ult(cnf, aprob, false);
    exe.execute_contest_ult(cnf);
}
