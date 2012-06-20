#include <iostream>
#include <cassert>
#include <string.h>
#include "csc_matrix.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 4 && argc != 5) {
		std::cout << "Too many or too few arguments." << std::endl
				  << "Program usage: ./ldl_driver [lfil] [tol] [in.mtx] [-yn]" << std::endl;
		return 0;
	}
	
	csc_matrix<int, double> A, L;
	vector<double> D;
	
	assert( A.load(argv[3]) );
	//cout << A << endl;
	
	A.ildl(L, D, atof(argv[1]), atof(argv[2]));
	
	if (argc > 4 && strcmp(argv[4], "-y") == 0) {
	    cout << L << endl;
	    cout << D << endl;
	}
	
	return 0;
}
