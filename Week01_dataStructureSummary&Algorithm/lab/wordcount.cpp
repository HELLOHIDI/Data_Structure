
#include <iostream>
#include <fstream>    // for ifstream, open
#include <stdlib.h>     // for exit 

using namespace std;


void main()
{
	void countWord(char buffer[], int &wc);

	ifstream infile;

	char buffer[80]; 	int wc;  int total = 0;

	infile.open("lab1.txt", ios::in);        
											 
	if (infile.fail()) {
		cout << "can't open the input file" << endl;
		exit(1);
	}

	while (infile.getline(buffer, 80)) {
		cout << buffer << endl;
		countWord(buffer, wc);
		cout << "The number of words : " << wc << endl;
		total = total + wc;
	}
	cout << endl<<endl<<"The total number of words: " << total << endl<<endl;
}

void countWord(char buffer[], int &wc)
{

	const int IN = 1;                // 단어가 시작되면 status = IN 이 됨
	const int OUT = 0;               // 단어 밖이면 status = OUT 가 됨

	int i = 0;
	int state = OUT;      // 단어가 시작되지 않았다는 뜻

	wc = 0;

	while (buffer[i] != '\0') {
		if (isalpha(buffer[i])) {
			if (state == OUT) {
				++wc;
				state = IN;
			}                   // 문자이고 state = IN 이면 do nothing 
		}
		else if (buffer[i] == ' ')
			state = OUT;
		i++;
	}
}