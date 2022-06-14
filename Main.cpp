#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Manager.h"








int main()
{
    manager engine;

    std::vector<char>  separators{' ', '\t'};
    parser  parser{separators}; 
    std::string userInput;
    bool  isStop = false;
    while(!isStop)
    {
        
        std::getline(std::cin, userInput); 
        isStop = engine.process(parser((userInput)));
    }

   return 0;
}