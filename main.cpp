#include <iostream>
#include <filesystem>
#include <stdio.h>
#include <vector>
#include "Image_Reader/Image_Reader.hpp"
#include "Image_Reader/Path_Loader.hpp"
#include "NN/Layer.hpp"
#include "NN/Neural_Network.hpp"
#include "NN/Timer.hpp"

#include <algorithm>
#include <random>

using namespace std;
using namespace cv;


string root_test = "/Users/langletmaxime/Desktop/MNIST/test";
string root_train = "/Users/langletmaxime/Desktop/MNIST/train";


struct Image{
    float* image;
    float* label;
    string path;
};



// Manual extraction of labels
int get_label(string path){

    string lab = path.substr(41,1);// in our use case

    // float vec[] = {0,0,0,0,0,0,0,0,0,0};

    int pos = stoi(lab);
    // vec[pos] = 1.0;

    // float* label = vec;

    return pos;
}


int main()
{

    Image_Reader image_reader;

    float* img = image_reader.get_im("/Users/langletmaxime/Desktop/NN_C++/1.jpg");

    int rows = image_reader.get_r();
    int cols = image_reader.get_c();

    cout << "\n"<< endl;

    // // Pixel values for image as float* (flatten image)
    // for (int x=0;x<rows*cols;x++){
    //     cout << img[x]<<endl;
    // }

    // // Pixel values for image as Mat
    // for (int x=0;x<rows;x++){
    //     for (int y = 0; y < cols; y++)
    //     {
    //         cout << img[x][y]<<endl;;
    //         // if (img[x][y]!= 0)
    //         // {
    //         //     cout << img[x][y]<<endl;;
    //         // }
    //     }
    // }


    Path_Loader paths_loader = Path_Loader(root_train);

    vector<string> paths = paths_loader.get_paths();

    // Shuffle 
    auto rng = std::default_random_engine {};
    shuffle(begin(paths), end(paths), rng);


    vector<float*> images;
    vector<float*> labels;
    vector<int> pos;




    int sizes[] = {rows*cols,100,10}; // inputs and output sizes included
    int* lay_sizes = sizes;
    Neural_Network nnet;

    nnet.BuildNN(lay_sizes,sizeof(sizes) / sizeof(int));

    for (int i = 0; i < paths.size(); ++i)
    {

        // Loading the images with their labels


        // cout << paths[i] << endl;

        // Pixel values for image as float* (flatten image)
        images.push_back(image_reader.get_im(paths[i]));


        pos.push_back(get_label(paths[i]));
        float* lab = new float[10];

        for (int j = 0; j < 10; ++j)
        {
            lab[j]=0;
        }
        lab[pos[i]] = 1;
        labels.push_back(lab);

        // for (int j = 0; j < 10; ++j)
        // {
        //     if (lab[j]!=0 && lab[j]!=1)
        //     {   
        //         cout << paths[j] << endl;
        //         cout << lab[j] << endl;
        //     }
        //     if (labels[i][j]!=0 && labels[i][j]!=1)
        //     {   
        //         cout << "labels" << endl;
        //         cout << paths[j] << endl;
        //         cout << labels[i][j] << endl;
        //     }
        // }

        // if (i>4000)
        // {
        //     break;
        // }
    }


    cout << "Total cost : " << nnet.Cost(images, labels) << endl;
    cout << "Learn " << endl;
    for (int i = 0; i < 100; ++i)
    {

        cout << i;

        int average = 0;
        int batch_nbr = 0;

        for (int batch = 0; batch < images.size()/32; ++batch)
        {
            Timer timer;
            // Taking by batch
            vector<float*>::const_iterator first_im = images.begin() + 32*i;
            vector<float*>::const_iterator last_im = images.begin() + 32*(i+1);
            vector<float*> new_im(first_im, last_im);

            vector<float*>::const_iterator first_lab = labels.begin() + 32*i;
            vector<float*>::const_iterator last_lab = labels.begin() + 32*(i+1);
            vector<float*> new_lab(first_lab, last_lab);


            nnet.learn(new_im, new_lab, 0.00001);   

            timer.Stop();
            batch_nbr++;
            average+=timer.getDuration(); 
        }
        nnet.predict(images, labels);
        cout << " Cost : " << nnet.Cost(images, labels) << " average time per batch : " << average/batch_nbr << endl;
    }


    cout << "Learning or not ? " << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << nnet.calculate_output(images[0])[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < 10; ++i)
    {
        cout << nnet.calculate_output(images[1])[i] << " ";
    }

    cout << endl;

    // // Pixel values for image as float* (flatten image)
    // cout << "image 1:" << endl;
    // for (int x=0;x<rows*cols;x++){
    //     cout << images[0][x]<< " ";
    // }

    // cout << endl;

    // cout << "image 2:" << endl;
    // for (int x=0;x<rows*cols;x++){
    //     cout << images[1][x] << " ";
    // }
    // cout << endl;



    // Other construction of nnet
    // Neural_Network nnet2;
    // nnet2.add(Layer(rows*cols, 4, "relu"));
    // nnet2.add(Layer(4, 10, "softmax"));

    // float label[10] = {0,0,0,0,0,0,0,0,0,0};
    // get_label(image_reader.get_path(), label);

    // float* lab = label;

    // float* inputs2 = image_reader.get_im(paths[10]);
    // float* output2 = nnet2.calculate_output(inputs2);

    // cout << "\noutputs2" << endl;
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << output2[i] << endl;
    // }

    // cout << "Max index " << nnet2.classify(inputs2) << endl;
    // cout << "Cost : " << nnet.Cost(inputs2, lab) << endl;

    return 0;

}


    // cout << "Done loading images" << endl;
    // cout << "Total cost : " << nnet.Cost(images, labels) << endl;
    
    // cout << "Learn " << endl;
    // for (int i = 0; i < 100; ++i)
    // {

    //     cout << i;

    //     int average = 0;
    //     int batch_nbr = 0;

    //     for (int batch = 0; batch < images.size()/32; ++batch)
    //     {
    //         Timer timer;
    //         // Taking by batch
    //         vector<float*>::const_iterator first_im = images.begin() + 32*i;
    //         vector<float*>::const_iterator last_im = images.begin() + 32*(i+1);
    //         vector<float*> new_im(first_im, last_im);

    //         vector<float*>::const_iterator first_lab = labels.begin() + 32*i;
    //         vector<float*>::const_iterator last_lab = labels.begin() + 32*(i+1);
    //         vector<float*> new_lab(first_lab, last_lab);


    //         nnet.learn(new_im, new_lab, 0.0001);  

    //         timer.Stop();
    //         batch_nbr++;
    //         average+=timer.getDuration(); 
    //     }
    //     nnet.predict(images, labels);
    //     cout << " Cost : " << nnet.Cost(images, labels) << " average time : " << average/batch_nbr << endl;
    // }