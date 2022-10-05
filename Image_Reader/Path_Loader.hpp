#ifndef PATH_LOADER
#define PATH_LOADER

#include <iostream>
#include <filesystem>
#include <stdio.h>
#include <vector>


using namespace std;
namespace fs = std::__fs::filesystem;

class Path_Loader
{
    public:
    Path_Loader(string roots);
    vector<string> get_paths();
    ~Path_Loader();

    private:
    string root;
    vector<string> arr;

};

#endif