#include "Image_Reader.hpp"

using namespace std;
using namespace cv;

//TODO: Add size of im

Image_Reader::Image_Reader(){}

Image_Reader::~Image_Reader(){}


float** make_2d_array(int r, int c) 
{
    float** arr = new float*[r];
    for(int i = 0; i < r; i++)
        arr[i] = new float[c];

    return arr;
}


string Image_Reader::get_path(){
    return path;
}


float* Image_Reader::get_im(string file_path){

	//std::string image_path = samples::findFile(file_path);
    //cout << file_path << " " << image_path << endl;
    // Mat img = imread(image_path, cv::IMREAD_COLOR);

    path = file_path;

    img = imread(file_path, cv::COLOR_BGR2GRAY);
    if(img.empty())
    {
        cout << "Could not read the image: " << file_path << endl;
        return 0;
    }

    // Mat image_gray;
    // cvtColor(img, image_gray, cv::COLOR_BGR2GRAY);
    // float** array = make_2d_array(img.rows, img.cols);

    float* array = new float[img.rows*img.cols];

    rows = img.rows;
    cols = img.cols;

    int i =0;
    for(int x=0;x<img.rows;x++)
    {
        for(int y=0;y<img.cols;y++)
        {
            // array[x][y] = img.at<uchar>(Point(x,y));//image_gray.at<uchar>(Point(x,y));
            array[i] = img.at<uchar>(Point(x,y));
            i++;
            // if (array[x][y]!= 0)
            // {
            //     cout << array[x][y];
            // }
        }
    }


	return array;
}


int Image_Reader::get_r(){
    return rows;
}

int Image_Reader::get_c(){
    return cols;
}