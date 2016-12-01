#include <iostream>
#include "pwgen.h"
#include <boost/program_options.hpp>
#include <boost/exception/all.hpp>
#include <exception>
#include <math.h>

#include "version.h"

const string AUTHOR="Krzysztof Grzempa";
const string LICENCE="GNU GPLv3";
const int YEAR=2016;

using namespace std;


int main(int argc, char** argv) {

  PassCounter HowMany = { 4, 3, 3, -1 };
  namespace po = boost::program_options;
  po::options_description desc("Available options");
  bool letters_defined = false;


  try {
    desc.add_options()
      ("about", "Authors and licences")
      ("help,h", "produce help message")
      ("version,v", "print version informations")
      ("count,c", po::value<int>(), "produce given amount of passwords")
      ("numbers,n", po::value<int>(), "how many numbers in password")
      ("letters,l", po::value<int>(), "how many letters in password")
      ("specials,s", po::value<int>(), "how many special characters in password")
      ("uppercase,u", po::value<int>(), "how many letters should be uppercase");
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
      using AutoVersion::BUILD;
      using AutoVersion::REVISION;
      using AutoVersion::STATUS;
      using AutoVersion::STATUS_SHORT;
      cout <<  MAJOR << "." << MINOR << "." << BUILD << STATUS_SHORT << " rev: " << REVISION << endl;
      return 0;
    }

    if (vm.count("about")) {
      cout << "Author: " << AUTHOR << " " << YEAR << "\n"
      << "Under licence: " << LICENCE << "\n";
      return 0;
    }

    if (vm.count("count")) {
      pass_count = abs(vm["count"].as<int>());
    }

    if (vm.count("numbers")) {
      HowMany.numbers = abs(vm["numbers"].as<int>());
    }

    if (vm.count("letters")) {
      letters_defined = true;
      HowMany.letters = abs(vm["letters"].as<int>());
    }

    if (vm.count("specials")) {
      HowMany.specials = abs(vm["specials"].as<int>());
    }

    if (vm.count("uppercase")) {
      HowMany.uppercase = abs(vm["uppercase"].as<int>());
    }

    if (HowMany.uppercase > HowMany.letters && letters_defined == true) {
      cout << "Uppercase letters amount cannot exceed overall letters number";
      return 0;
    } else if (HowMany.uppercase > HowMany.letters && letters_defined == false) {
      HowMany.letters = HowMany.uppercase;
    }

    PasswordGenerator Generator;
    Generator.produce_pass(pass_count, HowMany);
    return 0;

  } catch(po::error & ba) {

    cout << "ERROR: " << ba.what();

  }

}
