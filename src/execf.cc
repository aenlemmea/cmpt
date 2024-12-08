#include "execf.hh"


namespace cmpt {

    void execf::execute_one_ult() {
        config cnf;
        one o;
        o.get_data();
        const auto full_dir_name = o.get_full_dirname();
        std::string dir_path = ::getCurrentWorkingDirectory() + "/" + full_dir_name.substr(1) + "/" + full_dir_name;

        // I know i know, i should use std::cerr so i can manip but don't need that ability right now.
        if (!fs::exists(dir_path)) {
            if (fs::create_directories(dir_path)) std::cout << "Directory created\n";
            else std::cout << "Failed creating directories @: " << dir_path << "\n";
        } else {
            std::cout << "Directory already exists.\n" << "\n";
        }

        try {
          fs::copy_file((::getHomeDirectory() + cnf.get_template().path.substr(1)), dir_path + "/sol.cpp");
        } catch (fs::filesystem_error& e) {
            std::cerr << "Could not copy templates. Make sure sol.cpp exists in config directory" << "\n" << e.what() << "\n";
        }


        std::ofstream testin(dir_path + "/test.in");
        std::ofstream testout(dir_path + "/test.out");
        for (const auto& e : o.expose_prob().tests) {
            testin << e.input;
            testout << e.output;

            testin << "\n###\n";
            testout << "\n###\n";
        };
        testout.close();
        testin.close();

    }

    void execf::execute_contest_ult() {
        // TODO
    }
};