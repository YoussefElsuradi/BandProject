#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Manager.h"




std::vector<std::string> parser:: operator() (std::string& str)
{
    std::vector <std::string> result;
    std::string t = "";
    std::string t1 = "";

    if (qCheck(str))                                 //quote check
    {
        size_t f = str.find("\"");
        size_t f1 = str.find("\"", f + 1);

        for (int i{ 0 }; i < str.size(); i++)
        {
            bool sep = false;              //separators == false

            for (char j : token)   //separator check 
            {
                if (str[i] == j)
                {
                    sep = true;
                }
            }
            if (str[i] == '\"')
            {
                t.push_back(str[i]);
                for (int j = i + 1; j < f1 + 1; j++)
                {
                    t.push_back(str[j]);
                    i = j + 1;
                }

                result.push_back(t);
                t = "";
            }
            if ((str[i] == '>') || (str[i] == '<') || (str[i] == '='))
            {
                if (t.size() != 0)
                {
                    result.push_back(t);
                    t = "";
                }
            }
            if (!sep)
            {
                t += str[i];
            }
            else
            {
                if (t.size() != 0)
                {
                    result.push_back(t);
                    t = "";
                }
            }
        }
    }
    else
    {
        for (int i{ 0 }; i < str.size(); i++)
        {
            bool sep = false;
            for (char j : token)
            {
                if (str[i] == j)
                {
                    sep = true;
                }
            }

            if ((str[i] == '>') || (str[i] == '<') || (str[i] == '='))
            {
                if (t.size() != 0)
                {
                    result.push_back(t);
                    t = "";
                }
            }
            if (!sep)
            {
                t += str[i];
            }
            else
            {
                if (t.size() != 0)
                {
                    result.push_back(t);
                    t = "";
                }
            }
        }
    }
    if (t.size() != 0)
    {
        result.push_back(t);
        t = "";
    }
    return result;
}

parser::~parser()
{
    token.clear();
}