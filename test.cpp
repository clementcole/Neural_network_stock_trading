#include "1lnn.cpp"



int main()
{
  /*
    AAPL
    GOOG
    MSFT
    AMZN
    BRK-A
    FB
    JNJ
    V
    UNH
    HD
  */

	//system("wget -nd https://stooq.com/q/d/l/?s=AAPL.US&i=d -O appl.csv");
	std::string test_symbols("test_apple_stocks");
	std::cout << "It works\n" << std::endl;
	Cell testNeurons;
	std::vector<float> target_prices;
	std::string target = "symb_test3";
	string indicator_file("indicators_prices");
	ifstream indicator(indicator_file);
	std::vector<std::string> results = {"test1", "test2", "test3", "test4", "test5", "test6", "test7", "test8", "test9", "test10"};
	//set_target_size(target_prices, NUM_OF_DAYS);
	set_target(target_prices, target);
	std::cout << "Before Training" << std::endl;
	//set_Neurons(testNeurons, indicator_file);
	trainCells(testNeurons, target_prices,indicator_file, results);

	//test_Neurons(testNeurons);
	std::cout << " After Training Cells" <<std::endl;
	cout << target_prices.size() << endl;
	return 0;
	//test_Neurons(testNeurons);
}
