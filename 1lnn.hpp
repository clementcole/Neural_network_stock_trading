#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <map>
#include <random>



using namespace std;





// typedef struct Cell Cell;
// typedef struct Layer Layer;




// struct Cell{
// 	double weight_0; 
// 	double weight_1;
// 	double weight_2;
// 	double weight_3;
// 	double weight_4;
// 	double prices;
// 	double indicator_0;
// 	double indicator_1;
// 	double indicator_2;
// 	double indicator_3;
// 	double indicator_4;
// 	double output;
// };

struct Layer{
	vector<Cell> cells; 
};
float sigmoid(double output);

void create_Neurons(Cell &cell);