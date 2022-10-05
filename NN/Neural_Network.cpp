#include "Neural_Network.hpp"
#include "Timer.hpp"

using namespace std;

int MaxIndex(float* inputs, int num_layers, vector<int> layerSizes){

    int index=-1;
    float max=-340282346638528859811704183484516925440.0;
    for (int i = 0; i < layerSizes[num_layers]; ++i)
    {
        if (inputs[i]>max)
        {
            index=i;
            max=inputs[i];
        }
    }
    return index;
}

Neural_Network::Neural_Network(){
    num_layers=0;
}


void Neural_Network::BuildNN(int* lay_size, int num_lay){

    num_layers=num_lay-1;


    for (int i = 0; i < num_lay; ++i)
    {
        layerSizes.push_back(lay_size[i]);
    }

    for (int i = 0; i < num_layers; ++i)
    {
        if (i==num_layers-1)
        {   
            // layers.push_back(Layer(layerSizes[i], layerSizes[i+1], "softmax"));   //In order to use softmax as last activation function of last layer
            layers.push_back(Layer(layerSizes[i], layerSizes[i+1], "sigmoid"));
        }
        else{
            layers.push_back(Layer(layerSizes[i], layerSizes[i+1]));
        }
    }
}


void Neural_Network::add(Layer layer){
    layers.push_back(layer);
    num_layers+=1;

    if (!layerSizes.empty())
    {
        if (layerSizes.back() != layer.get_nodes_in())
        {
            cout << "ATTENTION: Wrong number of parameters for layers input and output, missing some connections" << endl;
        }
        else{
            layerSizes.push_back(layer.get_nodes_out());
        }
    }
    else{
        layerSizes.push_back(layer.get_nodes_in());
        layerSizes.push_back(layer.get_nodes_out());
    }
}


float* Neural_Network::calculate_output(float* inputs){

    // data = inputs;
    for (int i = 0; i < layers.size(); ++i)
    {
        inputs = layers[i].calculate_output(inputs);
    }

    return inputs;
}

int Neural_Network::classify(float* inputs){
    return MaxIndex(calculate_output(inputs), num_layers, layerSizes);

}


float Neural_Network::Cost_Indiv(float* inputs, float* label){

    float* output = calculate_output(inputs);

    // cout << endl;
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << output[i] << " ";
    // }
    // cout << endl;


    Layer outputLayer = layers[layers.size()-1];
    float cost=0;

    for (int i = 0; i < outputLayer.get_nodes_out(); ++i)
    {
        cost+= outputLayer.NodeCost(label[i], output[i]);
        // cout << "c : " << cost << " label : " << label[i] << " output : " << output[i] << endl;
    }

    return cost/2;
}

float Neural_Network::Cost(vector<float*> images, vector<float*> labels){

    float total_cost=0;

    for (int i = 0; i < images.size(); ++i)
    {
        total_cost+= Cost_Indiv(images[i], labels[i]);
        // cout << "tc : " << total_cost << "\n"<< endl;
    }

    return total_cost/images.size();
}

void Neural_Network::predict(vector<float*> images, vector<float*> labels){

    float acc=0;
    for (int i = 0; i < images.size(); ++i)
    {
        acc+=pred(images[i], labels[i]);
    }

    cout << " Accuracy : " << float(acc/float(images.size())) << " " << acc;
}

int Neural_Network::pred(float* inputs, float* label){

    int index = classify(inputs);
    // cout << "Index : " << index << " " << label[index] << endl;
    int value=0;

    if (label[index]>=0.5)
    {
        value=1;
    }

    return value;
}

void Neural_Network::learn(vector<float*> images, vector<float*> labels,float learn_rate){
    lr = learn_rate;

    for (int i = 0; i < images.size(); ++i)
    {
        UpdateAllGradients(images[i], labels[i]);
    }

    for (int i = 0; i < layers.size(); ++i)
    {
        // cout << "New layer " << endl;
        layers[i].apply_gradiant(lr);///images.size());
        layers[i].clearCostGradiants();
    }


    // // -----------------------------------------
    // const float h=0.0001;

    // float originalCost = Cost(images, labels);

    // for (int i = 0; i < layers.size(); ++i)
    // {
    //     for (int nodeIn = 0; nodeIn < layers[i].get_nodes_in(); ++nodeIn)
    //     {
    //         for (int nodeOut = 0; nodeOut < layers[i].get_nodes_out(); ++nodeOut)
    //         {
    //             layers[i].weights[nodeIn][nodeOut]+=h;

    //             float deltaCost = Cost(images, labels) - originalCost;
    //             layers[i].weights[nodeIn][nodeOut]-=h;
    //             layers[i].costGradientW[nodeIn][nodeOut] = deltaCost/h;
    //         }
    //     }

    //     for (int nodeOut = 0; nodeOut < layers[i].get_nodes_out(); ++nodeOut)
    //     {
    //         layers[i].biais[nodeOut]+=h;
    //         float deltaCost = Cost(images, labels) - originalCost;
    //         layers[i].biais[nodeOut]-=h;
    //         layers[i].costGradientB[nodeOut] = deltaCost / h;
    //     }

    //     layers[i].apply_gradiant(lr);
    // }

    // cout << " Original Cost : " << originalCost << " Cost :" << Cost(images, labels) << endl;
}


void Neural_Network::UpdateAllGradients(float* inputs, float* labels){


    // Timer timer;
    // int time=0;

    // Slowest as of now : 75-80
    calculate_output(inputs);

    // timer.Stop();
    // time=timer.getDuration();

    // cout << "Time calculate_output :" << time << endl;

    // for (int i = 0; i < layers.size(); i++)
    // {
    //     inputsToNextLayer = layers[i].calculate_output(inputsToNextLayer);
    // }

    Layer outputLayer = layers.back();
    float* node_values = outputLayer.CalculateOutputLayerNode(labels);

    // cout << "\nnode val output : " << endl;
    // for (int i = 0; i < outputLayer.get_nodes_out(); ++i)
    // {
    //     cout << node_values[i] << " ";
    // }
    // cout << endl;

    outputLayer.updateGradiants(node_values, false);


    int oldNbrNodes = outputLayer.get_nodes_out();


    //41
    for (int hiddenLayerIndex = layers.size()-2; hiddenLayerIndex>=0; hiddenLayerIndex--)
    {
        Layer hiddenLayer = layers[hiddenLayerIndex];
        // copy_old_nodes = node_values;
        node_values = hiddenLayer.CalculateHiddenLayerNode(layers[hiddenLayerIndex+1], node_values, oldNbrNodes);
        oldNbrNodes = hiddenLayer.get_nodes_out();

        // cout << "\nNode val output : " << endl;
        // for (int i = 0; i < hiddenLayer.get_nodes_out(); ++i)
        // {
        //     cout << node_values[i] << " ";
        // }
        // cout << endl;


        hiddenLayer.updateGradiants(node_values, false);
    }
}

Neural_Network::~Neural_Network(){}