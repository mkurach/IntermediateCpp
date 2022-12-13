#include "script.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <boost/lexical_cast.hpp>


Script::Script(char *name, Piec &piec) : name_(name), piec_(piec) {

}

Script::~Script() {

}

void Script::readScript() {
    std::ifstream file(name_);
    std::string line;
    std::smatch match;

    std::regex wzorzec0_("([a-zA-Z]+)");
    std::regex wzorzec1_("([a-zA-Z]+)\\s(\\d+)");
    std::regex wzorzec2_("([a-zA-Z]+)\\s(\\d+)\\s(\\d+)");
    std::regex wzorzec3_("([a-zA-Z]+)\\s(\\d+)\\s(\\d+)\\s(\\d+)");

    while(std::getline(file,line)) {
        if(std::regex_search(line, match, wzorzec3_)) { // 3 parametry
            if(match.str(1) == "rampa") 
                piec_.rampa(boost::lexical_cast <int> (match.str(2)),boost::lexical_cast <int> (match.str(3)),boost::lexical_cast <int> (match.str(4)));

        }
        else{
            if(std::regex_search(line, match, wzorzec2_)) { //2 parametry
                //nie ma takiej funkcji

            }
            else {
                if(std::regex_search(line, match, wzorzec1_)) { //1 parametr
                    if(match.str(1) == "izotermiczne") 
                        piec_.izoterm(boost::lexical_cast <int> (match.str(2)));
                    else if(match.str(1) == "skocz")  
                        piec_.skocz(boost::lexical_cast <int> (match.str(2))); 
                    else if(match.str(1) == "start")  
                        piec_.start(boost::lexical_cast <int> (match.str(2)));          
                }
                else {
                    if(std::regex_search(line, match, wzorzec0_)) { //0 parametrów
                        if(match.str(1) == "end") 
                            piec_.end();

                    }
                }
            }
        }


    }



}

