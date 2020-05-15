#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int mystrcmp1(char[], char[]);
void printresult(int);
void mystrconcat(char s1[], char s2[]);

int main() {
	char mystring1[80], mystring2[80]; int size; 
 	cout << " 1) Enter a string: ";  	
	cin >> mystring1;	
	size = strlen(mystring1);
	cout << "     Length of the string 1 is : " << size << endl;

	cout << "     Enter another string: "; 	
	cin >> mystring2;  
	size = strlen(mystring2);
	cout << "     Length of the string 2 is : " << size << endl << endl;
	
	string str1 = "Hello world";  
	cout << "     Echo data :" << str1  << endl;
	size = str1.length();  
	cout << "     length of string :" << size << endl;
		
	cout <<endl<< " 2) Comparison of Two strings..  " << endl;
    int result = mystrcmp1(mystring1, mystring2); 	
	printresult(result); cout << endl;
	
    cout << endl<< " 3) Concatenation of Two strings..  " << endl;
	mystrconcat(mystring1, mystring2);
	cout << "    Concatenated strings is  :" << mystring1 << endl << endl;
}

void mystrconcat(char s1[], char s2[]) {
	int i = 0, j; 

	while (s1[i] != NULL) 		i++;
	j = 0;

	while (s2[j] != NULL) {
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = NULL;
}


void printresult(int result)  {
	if (result >= 1)  		cout << "    string1 > string2";
	else if (result == 0)  	cout << "    string1 == string2";
	else            		cout << "    string1 < string2";
	cout << endl;
}

int mystrcmp1(char s1[], char s2[]) {
	int i=0, result;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;     // if they are the same, ,,,
	if (s1[i] > s2[i])     result = 1;
	else if (s1[i] < s2[i]) 	result = -1;
	else		result = 0;
	return result;
}
