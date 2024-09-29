#include <iostream>
#include "httplib.h"
#include "internal/one.hh"

auto main() -> int {
	httplib::Server svr;
	
	one on;
	on.fetch_one(svr);

}
