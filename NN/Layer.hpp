#ifndef LAYER
#define LAYER

#include <iostream>
#include <math.h>


using namespace std;

class Layer
{
    public:
    Layer(int n_in, int n_out, string acti="relu");
    float* calculate_output(float* inputs);
    void apply_gradiant(float lr);
    int get_nodes_out();
    int get_nodes_in();
    float NodeCost(float expectedOutput, float predictedOutput);
    float NodeCostDerivate(float expectedOutput, float predictedOutput);
    float* CalculateOutputLayerNode(float* labels);

    float* CalculateHiddenLayerNode(Layer oldLayer, float* oldNodeValues, int oldNbrNodes);

    void updateGradiants(float* nodeValues, bool out);
    void clearCostGradiants();

    float sigmoid(float weightedInput);
    float sigmoidDerivative(float weightedInput);
    float ReLU(float weightedInput);
    float ReLUDerivative(float weightedInput);
    float softmax(float* input, int index, int size);
    float softmaxDerivative(float* input, int index, int size);

    float get_Weight(int i, int j);
    ~Layer();

    float** weights;
	float* biais;
	float** costGradientW;
	float* costGradientB;


    private:
    	void InitRandomValues();

    	// float (Layer::*acti_func)(float);	//No optimization advantage from if else
    	// float (Layer::*acti_deriv)(float);

    	string activation;
       	int nodes_in;
    	int nodes_out;

    	float* Inputs;
    	float* weightedInputs;
    	float* activations;

};

#endif