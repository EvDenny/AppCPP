#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int main () {
	int delay;
	cout<<"Enter delay in seconds: "<<flush;
	cin>>delay;
	delay *= CLOCKS_PER_SEC;
	clock_t now = clock();
	while (clock() - now < delay) {
		cout << flush;
	}
	cout << "Done!" << endl;

	return 0;
}