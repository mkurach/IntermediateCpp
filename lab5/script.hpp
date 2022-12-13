#ifndef _script_hpp_
#define _script_hpp_
#include "piec.hpp"
#include <regex>

class Script {
    public: 
        Script(char *name, Piec &piec);
        ~Script();
        void readScript();
    private:
        char *name_;
        Piec &piec_;

        
        



};

#endif