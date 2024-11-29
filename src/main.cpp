#include "crow_include/crow.h"

#include "internal/fetchers/one.hh"

int main() {
    cmpt::one one;
    one.get_data();
    one.show();
}
