#ifndef FILETILS_H
#define FILETILS_H

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

static const std::string& getCurrentWorkingDirectory() {
	static std::string cwd;
	try {
		cwd = fs::current_path().string();
	} catch (const fs::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << "\n";
		cwd.clear();
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		cwd.clear();
	}
	return cwd;
}

#endif
