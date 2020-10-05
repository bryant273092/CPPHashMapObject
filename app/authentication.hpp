#include<string>
#include "HashMap.hpp"


#ifndef AUTHENTICATION_HPP
#define AUTHENTICATION_HPP



class Authentication
{
public:
    Authentication();
private:
    void parseCommand(std::string command);
    void create(std::string combination);
    void login(std::string combination);
    void remove(std::string combination);
    void invalid();
    bool debug_state = false;
    HashMap map;
    bool active = true;

};


#endif