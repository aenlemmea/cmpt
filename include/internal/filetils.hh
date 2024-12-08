#ifndef FILETILS_H
#define FILETILS_H

#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

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

static const std::string getHomeDirectory() {
	if (const char* homedir = std::getenv("HOME")) {
		return std::string(homedir);
	}
	if (struct passwd* pw = getpwuid(getuid())) {
		return std::string(pw->pw_dir);
	}

	throw std::runtime_error("Unable to determine home directory");
}

static const std::string readJsonToString(const std::string& path) {
	std::ifstream inpfile(path);
	if(!inpfile) throw std::runtime_error("Cannot open file to read");
	std::string content((std::istreambuf_iterator<char>(inpfile)),
						std::istreambuf_iterator<char>());

	return content;
}


#endif
