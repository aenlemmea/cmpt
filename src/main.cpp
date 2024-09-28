#include <iostream>
#include "httplib.h"

auto main() -> int {
	using std::cout;
	cout << "Hello, World" << "\n";
	
	httplib::Server svr;

	svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
		res.set_content("Hello World!", "text/plain");
	});

	svr.listen("0.0.0.0", 8080);
}
