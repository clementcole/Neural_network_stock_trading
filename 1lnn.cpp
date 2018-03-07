#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <map>
#include <random>
#include <algorithm>
#include <utility>
#include <iterator>


using namespace std;

typedef struct Cell Cell;
typedef struct Layer Layer;
typedef struct Topology Topology;
const float LEARNING_RATE = 0.00002;
const float NUM_OF_DAYS = 50;


struct Cell{
	vector<float> weights; //
	vector<float> inputs;
	float weight_prices;
	float weight_0;
	float weight_1;
	float weight_2;
	float weight_3;
	float weight_4;
	float prices;
	float indicator_0;
	float indicator_1;
	float indicator_2;
	float indicator_3;
	float indicator_4;
	float bias;
	float output; 		//
};

struct Layer{
	std::vector<Cell> cells;
};

struct Topology{
	std::vector<Layer> Layers;
};

float sigmoid(float output)
{
	//return (1/ (1 + exp(-output)));
	return 0.0;
}



void set_number_inputs_neuron(Cell &cell, int number_of_inputs)
{
	cell.inputs.resize(number_of_inputs);
	cell.weights.resize(number_of_inputs);
}

void set_Neurons(Cell &cell, string &filename)
{
	Cell thiscell;
	ifstream indicator(filename);
	string indicator0, indicator1, indicator2, indicator3, indicator4, price;
	vector<string> indicator_0;
	vector<string> indicator_1;
	vector<string> indicator_2;
	vector<string> indicator_3;
	vector<string> indicator_4;
	vector<string> prices;
	float test_in0;
	if(!indicator.is_open()) std::cout << "ERROR : file open" <<"\n";
	while (indicator.good())
	{
		getline(indicator,indicator0, ',');
		getline(indicator,indicator1, ',');
		getline(indicator,indicator2, ',');
		getline(indicator,indicator3, ',');
		getline(indicator,indicator4, ',');
		getline(indicator,price, '\n');

		cell.indicator_0 = strtof((indicator0).c_str(),0);
		cell.indicator_1 = strtof((indicator1).c_str(),0);
		cell.indicator_2 = strtof((indicator2).c_str(),0);
		cell.indicator_3 = strtof((indicator3).c_str(),0);
		cell.indicator_4 = strtof((indicator4).c_str(),0);
		cell.prices = strtof((price).c_str(),0);

	}
	//for (auto &partial_cell : cell)
		cell.weight_prices = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
		cell.weight_0	= (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
		cell.weight_1	= (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
		cell.weight_2	= (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
		cell.weight_3	= (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
		cell.weight_4	= (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
		cell.bias = 98.46;

}

float get_error(Cell &neuron, float actual_price)
{
	neuron.prices = actual_price;
	return (actual_price - neuron.output);
}

void updateCellWeights(Cell &neuron, float err)
{
	neuron.weight_prices += LEARNING_RATE * neuron.prices * err;
	neuron.weight_0 += LEARNING_RATE * neuron.indicator_4 * err;
	neuron.weight_1 += LEARNING_RATE * neuron.indicator_4 * err;
	neuron.weight_2 += LEARNING_RATE * neuron.indicator_4 * err;
	neuron.weight_3 += LEARNING_RATE * neuron.indicator_4 * err;
	neuron.weight_4 += LEARNING_RATE * neuron.indicator_4 * err;
}

void cal_cell_output(Cell &neuron)
{
	//neuron.output = (neuron.prices * neuron.weight_prices) +
	neuron.output = (neuron.prices * neuron.weight_prices) + (neuron.indicator_0 * neuron.weight_0) + (neuron.indicator_1 * neuron.weight_1) +
	(neuron.indicator_2 * neuron.weight_2) + (neuron.indicator_3 * neuron.weight_3) + (neuron.indicator_4 * neuron.weight_4);// + neuron.bias;
}


void test_Neurons(Cell  &neuron)
{
		cout << neuron.indicator_0 <<" | "<<neuron.weight_0<< " | " << neuron.indicator_1 << " | " <<neuron.weight_1<< " | " << neuron.indicator_2 <<" | "<<neuron.weight_2<< " | " <<
						neuron.indicator_3 <<" | "<<neuron.weight_3<< " | " << neuron.indicator_4 << " | " << neuron.weight_4<<" | " << neuron.prices      <<" | " <<neuron.output<< endl;
}

void set_target_size(std::vector<float> &target_prices, int size)
{
	target_prices.resize(size);
}

void set_target(std::vector<float> &target_prices, string target_file)
{
	ifstream target(target_file);
	string target_price;
	string target0(" ");
	string target1(" ");
	string target2(" ");
	string target3(" ");
	string target4(" ");
	string target5(" ");
	string target6(" ");
	if(!target.is_open()) std::cout << "ERROR : file open" <<"\n";
	while (target.good())
	{
		getline(target,target0, ',');
		getline(target,target1, ',');
		getline(target,target2, ',');
		getline(target,target3, ',');
		getline(target,target4, ',');
		getline(target,target5, '\n');
		//getline(target, target_price, '\n');
		target_prices.push_back(strtof((target1).c_str(),0));
	}
	//for(auto &price : target_prices)


}

void trainCells(Cell &neuron, std::vector<float> target_prices, 
				string &indicator_file, 
				string &results)
{
	int i =0;
	ofstream results_stream(results);
	set_Neurons(neuron, indicator_file);
	cout << neuron.weight_prices << " " << neuron.weight_0 << " " << neuron.weight_1 << " " << neuron.weight_2 << " " << neuron.weight_3 << " "<< neuron.weight_4 << " "<< neuron.output << endl;
	for (auto target : target_prices)
	{
		cal_cell_output(neuron);
		auto error = get_error(neuron, target);
		updateCellWeights(neuron, error);
		results_stream << neuron.weight_prices << "  " << neuron.weight_0 << "  "<< neuron.weight_1 << "  " << neuron.weight_2 << "  " << neuron.weight_3 << "  "<< neuron.weight_4 << "  "<< neuron.output<<endl;
		i++;
	}
	test_Neurons(neuron);

}

void testCells(Cell &neurons)
{
	cout << neurons.weight_prices << "  " << neurons.weight_0 << "  "<< neurons.weight_1 << "  " << neurons.weight_2 << "  " << neurons.weight_3 << "  "<< neurons.weight_4 << "  "
				<< neurons.output<<endl;
}
