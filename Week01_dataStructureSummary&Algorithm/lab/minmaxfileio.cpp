
#include <iostream>
#include <fstream>    //  
#include <stdlib.h>     // for exit 
using namespace std;

int findMin(int data[], int n);
int findMax(int data[], int n);
int pos = 0;


int main() {
	ifstream infile;
	int data[10]; 	int count = 0;  int ch;

	infile.open("lab03.txt", ios::in);
	if (infile.fail()) { cout << "can't open the input file" << endl; 	exit(1); }

	while (infile >> ch) {
		data[count++] = ch;
	}
	infile.close();

	int minnum = findMin(data, count);
	cout << "Minimum number is " << minnum << " at position " << pos << endl;
	
	pos = 0;

	int maxnum = findMax(data, count); if (pos == 0) pos++;
	cout << "Maximum number is " << maxnum << " at position " << pos << endl;

}


int findMin(int data[], int n) {
	int min = data[0];

	for (int i = 1; i < n; i++)
		if (data[i] < min) { min = data[i];  	pos = i + 1;  }
		return min;
	}

	int findMax(int data[], int n) {
		int max = data[0];

		for (int i = 1; i < n; i++)
			if (data[i] > max) { max = data[i];  pos = i + 1; }
    	return max;
	}
