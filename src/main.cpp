#include <iostream>
#include "httplib.h"
#include "internal/one.hh"
#include "internal/filetils.hh"

auto main() -> int {
//	httplib::Server svr;
	
//	one on;
//	on.fetch_one(svr);
	
	using std::cout;
	cout << "Current Working Directory is: " <<  ::getCurrentWorkingDirectory() << "\n";

}
