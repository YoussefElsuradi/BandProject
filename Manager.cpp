#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Manager.h"



student::student(unsigned int catalogParam, std::string nameParam, MusicGenre genreParam)
{
    catalog = catalogParam;
    name = nameParam;
    genre = genreParam;
    isRemoved = false;
}


student::student(){}

unsigned int student::getCatalog()const
{
    return catalog;
}

std::string student::getName()const
{
    return name;
}


MusicGenre student::getGenre()const
{
    // std::string result = "";
    // if(genre == MusicGenre::Blues)
    //     result = "Blues";
    // if(genre == MusicGenre::Pop)
    //     result = "Pop";
    // if(genre == MusicGenre::Rock)
    //     result = "Rock";
    // if(genre == MusicGenre::Metal)
    //     result = "Metal";    

    return genre;
}
bool student:: getRemoved()const
{
    return isRemoved;       // returns if an entry has been removed
}
void student:: removed()
{
    isRemoved = true;   // sets IsRemoved to true when you remove an entry
}

student::~student(){} //destructor

bool parser::qCheck(std::string str) //checks for quotes
{
    for(int i = 0; i < str.size(); i++)
    {
        int j = count(str.begin(), str.end(), '\"');
        if(j != 2)
        {
            return false;
        }
    }
    return true;
}





