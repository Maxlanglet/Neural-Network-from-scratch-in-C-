#include "Path_Loader.hpp"

using namespace std;

Path_Loader::Path_Loader(string roots){
    root = roots;
}

Path_Loader::~Path_Loader(){}


vector<string> Path_Loader::get_paths(){

    for (fs::recursive_directory_iterator i(root), end; i != end; ++i) {
        if (!is_directory(i->path())){
            if ((i->path()).u8string().find("jpg") != string::npos) {
                arr.push_back(i->path());
            }
            else{
                cout << "\nNot image file :" << (i->path()).u8string() << endl;
            }
            // cout << i->path().filename() << "\n";
        }
    }

    cout << "\nNmbr of paths Loaded " << arr.size() << endl;


    return arr;
}