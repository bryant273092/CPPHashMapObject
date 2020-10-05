#include "authentication.hpp"
#include<iostream>
#include<sstream>

Authentication::Authentication(){
    while (active){
        
        std::string command;
        std::getline(std::cin, command);
        if (command != ""){
            parseCommand(command);
        }
        

        
    }
}
void Authentication::parseCommand(std::string input)
{


    std::string command = input.substr(0, input.find_first_of(" "));

    if (command == "CREATE")
    {
        std::string combination = input.substr(input.find_first_of(" "), input.length());
        create(combination);
    }
    else if (command == "LOGIN")
    {
        login(input);
    }
    else if (command == "REMOVE")
    {
        std::string combination = input.substr(input.find_first_of(" "), input.length());
        remove(combination);
    }
    else if (command == "CLEAR")
    {
        map.~HashMap();
        std::cout << "CLEARED" <<std::endl;
    }
    else if (input == "QUIT")
    {
        active = false;
        std::cout << "GOODBYES" << std::endl;
    }
    else if (command == "DEBUG")
    {
        std::istringstream combo_stream{input};
        std::string command;
        std::string command2;
        combo_stream >> command >> command2;
        if (command2 == "ON")
        {
            if (debug_state)
            {
                std::cout << "ON ALREADY" << std::endl;
            }
            else
            {
                debug_state = true;
                std::cout << "ON NOW" << std::endl;
            }
        }
        else if (command2 == "OFF")
        {
            if (debug_state)
            {
                debug_state = false;
                std::cout << "OFF NOW" << std::endl;
            }
            else
            {
                
                std::cout << "OFF ALREADY" << std::endl;
            }
        }
    }
    else if (input == "LOAD FACTOR" && debug_state)
    {
        std::cout << map.loadFactor() << std::endl;
    }
    else if (input == "BUCKET COUNT" && debug_state)
    {
       std::cout << map.bucketCount() << std::endl;
    }
    else if(input == "MAX BUCKET SIZE" && debug_state)
    {
        std::cout << map.maxBucketSize() << std::endl;
    }
    
    
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void Authentication::create(std::string combination)
{
    std::istringstream combo_stream{combination};
    std::string username;
    std::string password;
    if (combo_stream >> username)
    {
        if (combo_stream >> password)
        {
            if (!map.contains(username))
        {

            map.add(username, password);
            std::cout << "CREATED" << std::endl;
        }
        else
        {
            std::cout << "EXISTS" << std::endl;
        }
        }
        
    }
}



void Authentication::login(std::string combination){
    std::istringstream combo_stream{combination};
    std::string command;
    std::string username; 
    std::string password;
    combo_stream >> command;
    if (combo_stream >> username && combo_stream >> password)
    {
        if (map.contains(username))
        {
                if (map.value(username) == password)
                {
                    std::cout << "SUCCEEDED" << std::endl;
                }
                else
                {
                    std::cout << "FAILED" << std::endl;
                }
        }
        else
        {
            std::cout << "FAILED" << std::endl;
        }
    }
    else if(username == "COUNT" && debug_state){
        std::cout << map.size() << std::endl;
        
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}





void Authentication::remove(std::string combination)
{
    std::istringstream combo_stream{combination};
    std::string username;
    if (combo_stream >> username)
    {
        if (map.remove(username))
        {
            std::cout << "REMOVED" << std::endl;
        }
        else
        {
            std::cout << "NONEXISTANT" << std::endl;
        }
    }
    else{
        std::cout << "INVALID USERNAME FOR: " << combination << std::endl;
    }
}

void Authentication::invalid()
{
    std::cout << "INVALID" << std::endl;
}
