#include <iostream>
#include <string>
#include "main.cpp"
int main(){
	// create a string 
	std::string x = "abcd";
	// create a pcl_t variable, only needed if we use get_first_permutation_str in combination with get_next_permutation_str
	pcl_t y;



	// get permutations one by one
	// get_first_permutation_str initializes y (the pcl_t struct) with information from x("abcd"), y contains a list of indexes, max indexes, and index count (no need to ever touch the insides of y)
	// this function also gives the first permutation 
	std::cout << get_first_permutation_str(x, y) << "\n";
	// loop through the rest, factorial(strlen("abcd")) is used because that mathematically gives the needed combinations 
	for (int i = 1; i < factorial(x.size()); i++){
		// iterate and keep getting next permutation
		std::cout << get_next_permutation_str(x,y) << "\n";
	}

	std::cout << "\n\n\n";

	// get all permutations at once
	std::string *p = get_all_permutations_str(x);
	// loop through everything received
	for (int i = 0; i < factorial(x.size()); i++){
		// iterate through all permutations
		std::cout << p[i] << "\n";
	}
	

}