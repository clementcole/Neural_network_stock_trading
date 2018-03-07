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
	// std::transform(std::begin(temp, first), std::end(temp,first),
	// 				std::begin(temp.second),
	// 				std::inserter(new_map, std::begin(new_map))
	// 				,[] (int i, double d) {return std::make_pair(i, d); });

	//system("wget -nd https://stooq.com/q/d/l/?s=AAPL.US&i=d -O appl.csv");
	
	std::string test_symbols("test_apple_stocks");
	std::cout << "It works\n" << std::endl;
	Cell testNeurons;
	std::map<string, string> indicator_stocks;
	std::vector<float> target_prices;
	std::string target = "symb_test3";
	string indicator_file("indicators_prices");
	string symbols = {"AAPL", "AMZN", "BRK-A", "FB", "GBTC", "GOOG", "HD", "JNJ", "MSFT", "V"};
	string symbols_indicators = {"AAPL_IND", "AMZN_IND", "BRK-A_IND", "FB_IND", "GBTC_IND", "HD_IND", "JNJ_IND", "MSFT_IND", "V_IND"};
	string results = {"AAPL.rst", "AMZN.rst", "BRK.rst", "FB.rst", "GBTC.rst", "HD.rst", "JNJ.rst", "MSFT.rst", "V.rst"};


	for(auto i=0; i < symbols.size(); i++ )
	{
		set_target(target_prices, symbols[i]);
		trainCells(testNeurons, target_prices, symbols_indicators[i], results[i]);

	}
	// std::vector<std::string> test_indicators = {"test_indicators_0","test_indicators_1","test_indicators_2","test_indicators_3",
	// 											"test_indicators_4","test_indicators_5","test_indicators_6","test_indicators_7",
	// 											"test_indicators_8","test_indicators_9"};
	// std::vector<std::string> results = {"test0", "test1", "test2", "test3", "test4", "test5", "test6", "test7", "test8", "test9"};
	// std::vector<string>::iterator i = test_indicators.begin();
	// std::vector<string>::iterator j =  results.begin();
	// for(i(test_indicators.begin()), j(results.begin()); i != test_indicators.end() && j != results.end(); ++i, ++j)
	// {
	// 	//Make pair
	// 	indicator_stocks.insert(std::pair<string, string>(i, j));
	// }
	 
	//std::for_each(test_indicators, results, [](string a, string b){
	//	cout << a << "  " << b << endl;
	//});

	
	//set_target_size(target_prices, NUM_OF_DAYS);
	set_target(target_prices, target);
	std::cout << "Before Training" << std::endl;
	//set_Neurons(testNeurons, indicator_file);
	trainCells(testNeurons, target_prices,indicator_file, test_indicators, results);

	//test_Neurons(testNeurons);
	std::cout << " After Training Cells" <<std::endl;
	cout << target_prices.size() << endl;
	return 0;
	//test_Neurons(testNeurons);
}

