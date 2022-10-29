// permutation idea:
/*
	fast all permutations:

	get data (any type)
	int data[8];
	start with 8, for i < 8; do get value from data[i];
	call recursively, with value from data[i], and with new list and new length that exclude data[i]


	memory cheap next permutation: use a value to store the permutation values (just a list of indexes, and list size)



*/

#include <string>

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
	if (data.length() == 1){		
		current[data.length() -1] = data[0];

		flist[index] = current;
		index++;
		return 0;
	}

	// else
	for (int i = 0; i < data.length(); i++){
		// create new alphabet and recurse 
		std::string a = data;
		current[data.length() - 1] = a[i];
		a.erase(i, 1);
		recursive_perm_str(a, flist, current, index);
	}
	return 0;
}

// returns 0 on success
std::string *get_all_permutations_str(std::string in){
	// initialize all variables
	int final_list_size = factorial(in.length());
	std::string *flist = new std::string[final_list_size];

	int index = 0;

	std::string cw;
	cw.resize(in.length());

	recursive_perm_str(in, flist, cw, index);	

	// reverse every word in flist
	// or don't, because every permutation reversed is still every permutation

	return flist;
}

