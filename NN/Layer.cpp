#include "Layer.hpp"

using namespace std;

float** make_2d_weights(int r, int c) 
{
    float** arr = new float*[r];
    for(int i = 0; i < r; i++)
        arr[i] = new float[c];

    return arr;
}

float Layer::sigmoid(float weightedInput){
    return 1/(1+exp(-weightedInput));
}

float Layer::sigmoidDerivative(float weightedInput){
    float acti = sigmoid(weightedInput);

    // cout << "Sigmoid derivative : " << acti * (1-acti) << endl;
    return acti * (1-acti);
}

float Layer::ReLU(float weightedInput){

    if (weightedInput<0)
    {
        return 0;
    }
    else{
        return weightedInput;
    }
}

float Layer::ReLUDerivative(float weightedInput){

    float value=0;
    if (weightedInput>0)
    {
        value = 1;
    }

    // cout << "ReLU derivative : " << value << endl;
    return value;
}

float Layer::softmax(float* input, int index, int size){
    
    float expSum=0;

    for (int i = 0; i < size; ++i) {
        expSum+=exp(input[i]);
    }

    float res = exp(input[index])/expSum;

    return res;
}

float Layer::softmaxDerivative(float* input, int index, int size){
    float expSum = 0;

    // cout << size << endl;

    for (int i = 0; i < size; i++)
    {
        // cout << input[i] << endl;
        expSum += exp(input[i]);
    }

    // cout << expSum << endl;

    float ex = exp(input[index]);

    return (ex * expSum - ex * ex) / (expSum * expSum);
}



Layer::Layer(int n_in, int n_out, string acti){
    nodes_in = n_in;
    nodes_out = n_out;
    activation = acti;

    Inputs = new float[nodes_in];
    weightedInputs = new float[nodes_out];
    activations = new float[nodes_out];

    costGradientW = make_2d_weights(nodes_in,nodes_out);
    costGradientB = new float[nodes_out];

    weights = make_2d_weights(nodes_in,nodes_out);
    biais = new float[nodes_out];

    InitRandomValues();

    // //Sigmoid if not last layer, else its softmax
    // if (activation=="relu")
    // {
    //     acti_func = &Layer::ReLU;
    //     acti_deriv = &Layer::ReLUDerivative;
    // }
    // else if (activation=="sigmoid")
    // {
    //     acti_func = &Layer::sigmoid;
    //     acti_deriv = &Layer::sigmoidDerivative;
    // }
    // // else if (activation == "softmax"){
    // //     acti = &softmax;
    // //     acti_deriv = &softmaxDerivative;
    // // }

    for (int j = 0; j < nodes_out; ++j)
    {
        costGradientB[j]=0;
        for (int i = 0; i < nodes_in; ++i)
        {
            costGradientW[i][j]=0;
        }
    }

}

void Layer::InitRandomValues(){
    for (int j = 0; j < nodes_out; ++j)
    {
        // biais[j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2))-1;// between -1 and 1
        biais[j] = 0.0;
        for (int i = 0; i < nodes_in; ++i)
        {
            weights[i][j] = (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2))-1)/sqrt(nodes_in);
            // between -1 and 1, but scaled down for sigmoid function
        }
    }
}

void Layer::apply_gradiant(float lr){

    for (int j = 0; j < nodes_out; ++j)
    {
        // cout << "\n\nbiais j : " << biais[j] << " costGradientB j : " << costGradientB[j] << endl;
        biais[j] -= costGradientB[j]*lr;

        for (int i = 0; i < nodes_in; ++i)
        {
            weights[i][j] -= costGradientW[i][j]*lr;
            // cout << "weights i j : " << weights[i][j] << " costGradientW i j : " << costGradientW[i][j] << endl;
        }
    }
}

void Layer::clearCostGradiants(){

    for (int j = 0; j < nodes_out; ++j)
    {
        costGradientB[j]=0;
        for (int i = 0; i < nodes_in; ++i)
        {
            costGradientW[i][j]=0;
        }
    }
}

float Layer::NodeCost(float expectedOutput, float predictedOutput){

    float loss = predictedOutput- expectedOutput;
    return loss*loss;

}

float Layer::NodeCostDerivate(float expectedOutput, float predictedOutput){
    // cout << predictedOutput - expectedOutput << endl;
    return  predictedOutput - expectedOutput;

}

float* Layer::calculate_output(float* inputs){

    // Copy of inputs
    Inputs = inputs;
    

    for (int i = 0; i < nodes_out; ++i)
    {
        float weightedInput = biais[i];
        for (int j = 0; j < nodes_in; ++j)
        {
            weightedInput += inputs[j]*get_Weight(j,i);
        }
        weightedInputs[i] = weightedInput;
        // activations[i] = (*this.*acti_func)(weightedInputs[i]);
    }


    for (int i = 0; i < nodes_out; ++i)
    {
        //Sigmoid if not last layer, else its softmax
        if (activation=="relu")
        {
            activations[i] = ReLU(weightedInputs[i]);
        }
        else if (activation=="sigmoid")
        {
            activations[i] = sigmoid(weightedInputs[i]);
        }
        else if (activation == "softmax"){
            activations[i] = softmax(weightedInputs, i, nodes_out);
            // cout << "activations : " << activations[i] << endl;
        }
    }

    return activations;
}

float* Layer::CalculateOutputLayerNode(float* labels){
    float* nodeValues = new float[nodes_out];

    for (int i = 0; i < nodes_out; ++i)
    {
        // cout << "Activation : " << activations[i] << endl;
        float costDerivative = NodeCostDerivate(labels[i],activations[i]);
        float activationDerivate=0;
        // cout << "Cost derivate : " << costDerivative << endl;

        // activationDerivate = (*this.*acti_deriv)(weightedInputs[i]);

        if (activation=="sigmoid")
        {
            activationDerivate = sigmoidDerivative(weightedInputs[i]);
            // cout << "activationDerivate : " << activationDerivate << endl;
        }
        else if (activation=="relu")
        {
            activationDerivate = ReLUDerivative(weightedInputs[i]);
            // cout << "\nactivationDerivate : " << activationDerivate << endl;
        }
        else if (activation=="softmax"){
            activationDerivate = softmaxDerivative(weightedInputs, i ,nodes_out);
            // cout << "activationDerivate : " << activationDerivate << endl;
        }

        nodeValues[i]=activationDerivate*costDerivative;
        
    }

    return nodeValues;

}


float Layer::get_Weight(int i, int j){
    return weights[i][j];
}


float* Layer::CalculateHiddenLayerNode(Layer oldLayer, float* oldNodeValues, int oldNbrNodes){

    float* newNodeValues = new float[nodes_out];

    // cout << endl;

    for (int newNodeIndex = 0; newNodeIndex < nodes_out; ++newNodeIndex)
    {
        float newNodeValue = 0;

        for (int oldNodeIndex = 0; oldNodeIndex < oldNbrNodes; ++oldNodeIndex)
        {

            float weightedInputDerivative = oldLayer.get_Weight(newNodeIndex, oldNodeIndex);//see if it's the right indexes

            // if (isnan(weightedInputDerivative))
            // {
            //     cout << "OLD LAYER WEIGHTS NAN " << oldLayer.weights[newNodeIndex][oldNodeIndex] << endl;
            // }

            newNodeValue += weightedInputDerivative * oldNodeValues[oldNodeIndex];


            // cout << "weightedInputDerivative : " << weightedInputDerivative << " Old node value : " << oldNodeValues[oldNodeIndex] << " new node incremental "<< newNodeValue << endl;
        }


        if (activation=="sigmoid")
        {
            newNodeValue *=  sigmoidDerivative(weightedInputs[newNodeIndex]);
        }
        else if (activation=="relu")
        {
            newNodeValue *=  ReLUDerivative(weightedInputs[newNodeIndex]);
        }
        else if (activation=="softmax"){ // Technically not necessary because of softmax won't be inside model
            // cout << "New node value 1: " << newNodeValue << endl;
            newNodeValue *=  softmaxDerivative(weightedInputs, newNodeIndex, oldNbrNodes);
            // cout << "\nNew node value 2: " << newNodeValue << endl;
        }

        // newNodeValue *= (*this.*acti_deriv)(weightedInputs[newNodeIndex]);

        newNodeValues[newNodeIndex] = newNodeValue;
    }

    return newNodeValues;
}

void Layer::updateGradiants(float* nodeValues, bool out){

    // cout << "nodes out : " << nodes_out << endl;
    for (int j = 0; j < nodes_out; ++j)
    {
        for (int i = 0; i < nodes_in; ++i)
        {
            float derivativeCostWeights = Inputs[i]*nodeValues[j];
            costGradientW[i][j] += derivativeCostWeights;
        }
    }

    for (int i = 0; i < nodes_out; ++i)
    {
        float derivativeCostBiais = 1*nodeValues[i];
        // cout << "before derivate cost gradiant B : " << costGradientB[i] << " NodeVal : " << nodeValues[i] << endl;
        costGradientB[i] += derivativeCostBiais;

        if (out){
            // cout << "NodeVal B : " << nodeValues[i] << endl;
            // cout << "derivate cost gradiant B : " << costGradientB[i] << endl;
        }
    }
}

int Layer::get_nodes_out(){
    return nodes_out;
}

int Layer::get_nodes_in(){
    return nodes_in;
}

Layer::~Layer(){}