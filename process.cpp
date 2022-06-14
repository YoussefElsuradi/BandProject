#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Manager.h"



bool manager::numCheck(std::string& j)
{
    for (int i{ 0 }; i < j.size(); i++)
    {
        if (isdigit(j[i]))
        {
            return true;
        }
    }
    return false;
}

bool manager::process(std::vector<std::string> param)
{
    unsigned int catalog = 0;
    MusicGenre genre;

    if (param.size() != 0)
    {
        if (param[0] == "ADD")
        {
            catalog = std::stoul(param[1], nullptr, 10);
            if (param[2][0] == '\"')
            {
                param[2].erase(std::remove(param[2].begin(), param[2].end(), '\"'), param[2].end());
            }

            if (param[3] == "Pop") genre = MusicGenre::Pop;
            if (param[3] == "Rock") genre = MusicGenre::Rock;
            if (param[3] == "Metal") genre = MusicGenre::Metal;
            if (param[3] == "Blues") genre = MusicGenre::Blues;

            add(catalog, param[2], genre);
            std::cout << "Band Successfully Added!" << std::endl;
        }
        else if (param[0] == "FIND")
        {
            if (param[1] == "catalog")
            {
                if ((param[2] == ">") || (param[2] == "<") || (param[2] == "="))
                {
                    if (numCheck(param[3]))
                    {
                        catalog = std::stoul(param[3], nullptr, 10);
                        findCatalog(param[2], catalog);
                    }
                    else
                    {
                        std::cout << "Invalid Command" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Invalid Command" << std::endl;
                }
            }
            else if (param[1] == "genre")
            {
                if ((param[2] == ">") || (param[2] == "<") || (param[2] == "="))
                {
                    if (param[3] == "Pop")
                    {
                        genre = MusicGenre::Pop;
                        findGenre(genre);
                    }
                    else if (param[3] == "Rock")
                    {
                        genre = MusicGenre::Rock;
                        findGenre(genre);
                    }
                    else if (param[3] == "Metal")
                    {
                        genre = MusicGenre::Metal;
                        findGenre(genre);
                    }

                    else if (param[3] == "Blues")
                    {
                        genre = MusicGenre::Blues;
                        findGenre(genre);
                    }
                    else
                        std::cout << "Invalid Command" << std::endl;
                }
                else
                {
                    std::cout << "Invalid Command" << std::endl;
                }
            }
            else if (param[1] == "name")
            {
                if (param[2] == "=")
                {
                    findName(param[3]);
                }
                else
                {
                    std::cout << "Invalid Command" << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid Command" << std::endl;
            }
        }
        else if (param[0] == "REMOVE")
        {
            if (param[1] == "catalog")
            {
                if ((param[2] == ">") || (param[2] == "<") || (param[2] == "="))
                {
                    if (numCheck(param[3]))
                    {
                        catalog = std::stoul(param[3], nullptr, 10);
                        deleteCatalog(param[2], catalog);
                    }
                    else
                    {
                        std::cout << "Invalid Command" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Invalid Command" << std::endl;
                }
            }
            else if (param[1] == "genre")
            {
                if ((param[2] == ">") || (param[2] == "<") || (param[2] == "="))
                {
                    if (param[3] == "Pop")
                    {
                        genre = MusicGenre::Pop;
                        deleteGenre(genre);
                    }
                    else if (param[3] == "Rock")
                    {
                        genre = MusicGenre::Rock;
                        deleteGenre(genre);
                    }
                    else if (param[3] == "Metal")
                    {
                        genre = MusicGenre::Metal;
                        deleteGenre(genre);
                    }
                    else if (param[3] == "Blues")
                    {
                        genre = MusicGenre::Blues;
                        deleteGenre(genre);
                    }
                    else
                        std::cout << "Invalid Command" << std::endl;
                }
                else
                {
                    std::cout << "Invalid Command" << std::endl;
                }
            }
            else if (param[1] == "name")
            {
                if (param[2] == "=")
                {
                    deleteName(param[3]);
                }
                else
                {
                    std::cout << "Invalid Command" << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid Command" << std::endl;
            }
        }
        else if (param[0] == "STOP")
        {
            return stop();
        }
        else
        {
            std::cout << "Invalid Command" << std::endl;
        }

    }
    else
    {
        std::cout << "Invalid Command" << std::endl;
    }
    return false;
}