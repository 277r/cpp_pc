// permutation idea:
/*
	fast all permutations:

	get data (any type)
	int data[8];
	start with 8, for i < 8; do get value from data[i];
	call recursively, with value from data[i], and with new list and new length that exclude data[i]


	memory cheap next permutation: use a value to store the permutation values (just a list of indexes, and list size)



*/

#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <thread>

// factorial function which returns in!
int factorial(int in){
	int res = 1;
	while (in > 1){
		res *= in;
		in--;
	}
	return res;
}


int recursive_perm_str(std::string data, std::string *flist, std::string &current, int &index){
	
	// check if at deepest part
	if (data.size() == 1){		
		current[data.size() -1] = data[0];

		flist[index] = current;
		index++;
		return 0;
	}

	// else
	for (int i = 0; i < data.size(); i++){
		// create new alphabet and recurse 
		std::string a = data;
		current[data.size() - 1] = a[i];
		a.erase(i, 1);
		recursive_perm_str(a, flist, current, index);
	}
	return 0;
}

// returns all permutations, with returnsize = factorial(in.size());
std::string *get_all_permutations_str(std::string in){
	// initialize all variables
	int final_list_size = factorial(in.size());
	std::string *flist = new std::string[final_list_size];

	int index = 0;

	std::string cw;
	cw.resize(in.size());

	recursive_perm_str(in, flist, cw, index);	

	// reverse every word in flist
	// or don't, because every permutation reversed is still every permutation

	return flist;
}

struct pcl_t {
	int size;
	int *positions;
};

std::string get_next_permutation_str(std::string base, pcl_t &x){
	int *max_positions = new int[base.size()];
	for (int i = 0; i < base.size(); i++){
		max_positions[i] = base.size() - i - 1;
	}

	// increment position
	x.positions[x.size - 1]++;

	// set all positions good
	for (int i = base.size() -1; i > 0; i--){
		if (x.positions[i] > max_positions[i]){
			x.positions[i] = 0;
			x.positions[i - 1]++;
		}
	}
	
	
	std::string res;
	for (int i = 0; i < x.size; i++){
		res += base[x.positions[i]];
		base.erase(x.positions[i],1);
	}
	delete[] max_positions;
	

	return res;
}

