#include <iostream>
#include "httplib.h"

auto main() -> int {
	using std::cout;
	cout << "Hello, World" << "\n";
	
	httplib::Server svr;


	svr.Post("/", [&](const httplib::Request& req, httplib::Response& res) {
		cout << req.body << "\n";
		res.status = 200;
		return true;
	});
	svr.listen("0.0.0.0", 10043);
}
