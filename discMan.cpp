#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Manager.h"





bool manager::stop()
{
    discMan create; // new discMan object create

    create.write(bandMem, "bandInfo.txt"); // write all new student objects from vector bandMem into a txt file


    return true;
}

manager::manager()
{
    discMan start; // discMan object start 

    bandMem = start.read("bandInfo.txt"); // takes all student objects perviously saved in txt file, and puts them back in vector bandMem to be accessed

}

manager::~manager()
{
    bandMem.clear();
}

discMan::discMan() {}

void discMan::write(std::vector<student>& in, std::string file)
{                                               // writes  catalog, name, genre into the txt file for later

    std::ofstream txt;

    //txt.open("bandInfo.txt");
    txt.open(file); 
    for (int i{ 0 }; i < in.size(); i++)
    {
        MusicGenre gen = in[i].getGenre();
        std::string gs = genreString(gen);
        if (in[i].getRemoved() == false)
        {
            txt << in[i].getCatalog() << "\t" << in[i].getName() << "\t" << gs << std::endl;
        }
    }
    txt.close();
}

std::vector<student> discMan::read(std::string file)
{
    std::vector<char> separators{ ' ', '\t' };
    parser parser{ separators };
    std::vector<student> bandVec;
    std::ifstream myFile(file);
    std::string sen;

    if (myFile.is_open())
    {
        while (getline(myFile, sen))
        {
            std::vector<std::string> t = parser(sen);
            unsigned int catalog = std::stoul(t[0], nullptr, 10);
            MusicGenre genre;
            if (t[2] == "Pop") genre = MusicGenre::Pop;
            if (t[2] == "Rock") genre = MusicGenre::Rock;
            if (t[2] == "Metal") genre = MusicGenre::Metal;
            if (t[2] == "Blues") genre = MusicGenre::Blues;

            student bandRegistry = student(catalog, t[1], genre);

            bandVec.push_back(bandRegistry);
        }
    }
    return bandVec;
}

discMan::~discMan() {}


