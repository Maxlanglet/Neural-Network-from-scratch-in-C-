#ifndef IMG_READER
#define IMG_READER

#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

class Image_Reader
{
    public:
    Image_Reader();
    float* get_im(string file_path);
    string get_path();
    int get_r();
    int get_c();
    ~Image_Reader();

    private:
    string path; //Pas de using namespace std, il faut donc mettre std:: devant string
    int rows;
    int cols;
    Mat img;
};

#endif