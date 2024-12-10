#include "execf.hh"
#include <args.hxx>
#include <iostream>

int main(int argc, char **argv)
{
    cmpt::one aprob; // TODO: Remove this. See if execute_one_ult can be done with without an iterator approach.
    cmpt::config cnf;
    cmpt::execf exe;

    args::ArgumentParser parser("A tool to grab metadata from codeforces and manage them locally.", "Planned support: leetcode, dmoj.");
    args::Group commands(parser, "Available Commands:", args::Group::Validators::Xor);
    args::Command fo(commands, "fo", "Fetch a single problem.");
    args::Command fc(commands, "fc", "Fetch an entire contest. Note: Not for single problem contests");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    parser.helpParams.optionsString = ">COMMAND<:";
    parser.helpParams.proglineCommand = ">COMMAND<";
    parser.helpParams.proglineOptions = "";

    try
    {
        parser.ParseCLI(argc, argv);
        if (fo) {
            exe.execute_one_ult(cnf, aprob, false);
        } else if (fc) {
            exe.execute_contest_ult(cnf);
        }
    }
    catch (args::Help)
    {
        std::cout << parser;
        return 0;
    }
    catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << parser;
        return 1;
    }
    return 0;
}
