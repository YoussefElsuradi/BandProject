#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Manager.h"




void manager::add(unsigned int& catalog, std::string& name, MusicGenre& genre)
{
    student band = student(catalog, name, genre); //new student object band with the 3 params
    bandMem.push_back(band);        //pushes back pbject band to vector bandMem
}

std::string discMan::genreString(MusicGenre& genre) // converts type MusicGenre to string because i wasnt able to cout MusicGenre Types
{
    std::string result = "";
    if (genre == MusicGenre::Blues)
        result = "Blues";
    if (genre == MusicGenre::Pop)
        result = "Pop";
    if (genre == MusicGenre::Rock)
        result = "Rock";
    if (genre == MusicGenre::Metal)
        result = "Metal";
    return result;
}

void manager::findCatalog(std::string& sign, unsigned int& catalog)
{
    for (int i{ 0 }; i < bandMem.size(); i++) 
    {
        MusicGenre gen = bandMem[i].getGenre();
        if (sign == "<")
        {
            if ((bandMem[i].getCatalog() < catalog) && (bandMem[i].getRemoved() == false)) // if the catalog is larger than catalog AND the entry hasnt been removed it will go thru 
            {
                std::cout << bandMem[i].getCatalog() << "\t" << bandMem[i].getName() << "\t" << genreString(gen) << std::endl;
            }
        }
        else if (sign == ">")
        {
            if ((bandMem[i].getCatalog() > catalog) && (bandMem[i].getRemoved() == false))
            {
                std::cout << bandMem[i].getCatalog() << "\t" << bandMem[i].getName() << "\t" << genreString(gen) << std::endl;
            }
        }
        else if (sign == "=")
        {
            if ((bandMem[i].getCatalog() == catalog) && (bandMem[i].getRemoved() == false))
            {
                std::cout << bandMem[i].getCatalog() << "\t" << bandMem[i].getName() << "\t" << genreString(gen) << std::endl;
            }
        }
    }
}

void manager::findName(std::string& name)
{
    for (int i{ 0 }; i < bandMem.size(); i++)
    {
        MusicGenre gen = bandMem[i].getGenre();
        if ((bandMem[i].getName() == name) && (bandMem[i].getRemoved() == false)) // if the name matches and entry still exists , return entry
        {
            std::cout << bandMem[i].getCatalog() << "\t" << bandMem[i].getName() << "\t" << genreString(gen) << std::endl;
        }
    }
}

void manager::findGenre(MusicGenre& genre)
{
    for (int i{ 0 }; i < bandMem.size(); i++)
    {
        MusicGenre gen = bandMem[i].getGenre();
        if ((bandMem[i].getGenre() == genre) && (bandMem[i].getRemoved() == false))     // same as findName 
        {
            std::cout << bandMem[i].getCatalog() << "\t" << bandMem[i].getName() << "\t" << genreString(gen) << std::endl;
        }
    }
}

void manager::deleteCatalog(std::string& sign, unsigned int& catalog)
{
    for (int i{ 0 }; i < bandMem.size(); i++)
    {
        if (sign == "<")
        {
            if (bandMem[i].getCatalog() < catalog)
            {
                bandMem[i].removed();           // if condition is met, entry is removed from vector bandMem
            }
        }
        else if (sign == ">")
        {
            if (bandMem[i].getCatalog() > catalog)
            {
                bandMem[i].removed();
            }
        }
        else if (sign == "=")
        {
            if (bandMem[i].getCatalog() == catalog)
            {
                bandMem[i].removed();
            }
        }
    }
}

void manager::deleteName(std::string& name)
{
    for (int i{ 0 }; i < bandMem.size(); i++)
    {
        if (bandMem[i].getName() == name) //  if name matches, entry is deleted from vector bandMem
        {
            bandMem[i].removed();
        }
    }
}

void manager::deleteGenre(MusicGenre& genre)
{
    for (int i{ 0 }; i < bandMem.size(); i++)
    {
        if (bandMem[i].getGenre() == genre) //  same as name delete
        {
            bandMem[i].removed();
        }
    }
}
