#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include <iostream>
#include <vector>
#include "Layer.hpp"


using namespace std;

class Neural_Network
{
    public:
	    Neural_Network();
	    void BuildNN(int* lay_size, int num_layers);
	    float* calculate_output(float* inputs);
	    void add(Layer layer);
	    void learn(vector<float*> images, vector<float*> labels,float learn_rate);
	    float Cost_Indiv(float* inputs, float* label);
	    float Cost(vector<float*> images, vector<float*> labels);
	    int classify(float* inputs);
	    int pred(float* inputs, float* label);
	    void predict(vector<float*> images, vector<float*> labels);
	    void UpdateAllGradients(float* inputs, float* labels);
	    ~Neural_Network();

    private:
    	vector<int> layerSizes;
    	int num_layers;
    	float* data;
    	vector<Layer> layers;
    	float lr;



};

#endif