#include <iostream>
#include "pwgen.h"
#include <boost/program_options.hpp>
#include "version.h"

const string AUTHOR="Krzysztof Grzempa";
const string LICENCE="GNU GPLv3";
const string VERSION="0.0.1";
const int YEAR=2016;

using namespace std;


int main(int argc, char** argv) {

    PassCounter HowMany = { 4, 3, 3 };
    namespace po = boost::program_options;
    po::options_description desc("Available options");
    desc.add_options()
                    ("about", "Authors and licences")
                    ("help,h", "produce help message")
                    ("version,v", "print version informations")
                    ("count,c", po::value<int>(), "produce given amount of passwords")
                    /*("letters,t", po::value<int>(), "amount of letters")
                    ("numbers,n", po::value<int>(), "amount of numbers")
                    ("specials,s", po::value<int>(), "amount of special characters")*/
                    ("numbers,n", po::value<int>(), "how many numbers in password")
                    ("letters,l", po::value<int>(), "how many letters in password")
                    ("specials,s", po::value<int>(), "how many special characters in password")
                    /*("uppercase,u", po::value<int>(), "uppercase only")
                    ("lowercase,o", po::value<int>(), "lowercase only")*/;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    int pass_count = 10;


    if (vm.count("help")) {
        cout << desc << "\n";
        return 0;
    }

    if (vm.count("version")) {
        using AutoVersion::MINOR;
        using AutoVersion::MAJOR;
;       cout <<  MAJOR << "." << MINOR << endl;
        return 0;
    }

    if (vm.count("about")) {
        cout << "Author: " << AUTHOR << " " << YEAR << "\n"
        << "Under licence: " << LICENCE << "\n";
        return 0;
    }

    if (vm.count("count")) {
        pass_count = vm["count"].as<int>();
    }

    if (vm.count("numbers")) {
        HowMany.numbers = vm["numbers"].as<int>();
    }

    if (vm.count("letters")) {
        HowMany.letters = vm["letters"].as<int>();
    }

    if (vm.count("specials")) {
        HowMany.specials = vm["specials"].as<int>();;
    }

    PasswordGenerator Generator;
    Generator.produce_pass(pass_count, HowMany);
    return 0;
}
