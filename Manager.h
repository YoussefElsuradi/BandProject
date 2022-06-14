#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <typeinfo>
#include <cctype>
#include <algorithm>
#include <map>



enum class MusicGenre {
    Pop, Rock, Metal, Blues  
};

class student 
{
    private:

    unsigned int catalog;
    std::string name;
    MusicGenre genre;
    bool isRemoved;

    public:
    student(unsigned int catalogParam, std::string nameParam, MusicGenre genreParam);
    student();
    
    
    unsigned int getCatalog()const;
    std::string getName()const;
    MusicGenre getGenre()const;
    //std::string getGenString()const;d

    bool getRemoved()const;
    void removed();

    ~student();



};

class parser
{
    public:

    std::vector<char> token;
    std::vector<std::string> operator()(std::string &str);
    bool qCheck(std::string str);

    ~parser();
};

class discMan 
{
public:
    discMan();
    void write(std::vector<student>&, std::string);
    std::vector <student> read(std::string);
    ~discMan();
    std::string genreString(MusicGenre&);
};




class manager : discMan
{
    protected:
    

    public:
    std::vector<student> bandMem;
    bool process(std::vector<std::string>);
    void add(unsigned int&, std::string&, MusicGenre&);
    void findCatalog(std::string&, unsigned int&);
    void findGenre(MusicGenre&);
    void findName(std::string&);
    void deleteCatalog(std::string&, unsigned int&);
    void deleteGenre(MusicGenre&);
    void deleteName(std::string&);
    bool stop();
    bool numCheck(std::string&);
    
    manager();
    ~manager();


};


