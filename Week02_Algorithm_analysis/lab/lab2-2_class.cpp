#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

class Angle {
private:
  int type;
public:
  int width;
  int height;
  int round;

  Angle(){//basic constructor
    type = '\0'; //?
    width = 0; height = 0; round = 0;
  }
  Angle(int type, int round){ //circle constructor
    this->type = type; this->round = round;
    width = 0; height = 0;
  }
  Angle(int type, int width, int height){ //triangle and retangle constructor
    this->type = type; this->width = width; this->height = height;
    round = 0;
  }

  int getType(){
    return type;
  }

  double calculate(){
    double area;
    switch (type) {
      case 1:
        area = width*height/2; //triangle area
        break;
      case 2:
        area = width*height; //retangle area
        break;
      case 3:
        area = pow(round,2); //circle area
        break;
    }
    return area;
  }
};

int main() {
  map<string,int> m; // map -> key,value : dictionary feeling
  m["triangle"] = 1; //case 1
  m["rectangle"] = 2; // case 2
  m["circle"] = 3; // case 3
  Angle angle[7]; // we make 7 object to solve this problem!

  ifstream inFile("lab2-2_class_infile.txt");
  if(!inFile.is_open()){
    cerr << "error : Lab2-2_class_infile.txt can't open" << endl;
    return 1;
  }

  char delim =' ';
  vector<string> words; //string dynamic array
  string s;
  while(!inFile.eof()){//eof = end of file , the constant that represent the file end = -1
    string line;
    getline(inFile,line); //getline 함수는 입력 스트림에서 문자들을 읽어서, 인자로 받은 문자열에 저장합니다.
    //입력 스트림에서 문자를 읽다가 delim 문자를 읽게되면, 해당 문자를 버리고, 읽어들이기를 종료합니다. 만약에 delim 문자를 설정하지 않았다면, 디폴트로 개행 문자('\n')로 설정됩니다.
    stringstream f(line); //stringstream은, 주어진 문자열에서 필요한 정보를 .push빼낼 때 유용하게 사용된다.
    while(getline(f, s, delim)){
      words.push_back(s);//멤버 함수 push_back은 vector의 끝에 요소를 추가할때 사용하는 함수
    }
  }

  int pos = 0, idx = 0;
  while(pos <  words.size()){
    if(words[pos] != "circle") {
      angle[idx] = Angle(m[words[pos]], stoi(words[pos+1]), stoi(words[pos+2])); //stoi : string to int
      idx++;
      pos += 3;
    }else{
      angle[idx] = Angle(m[words[pos]], stoi(words[pos+1]));
      idx++;
      pos += 2;
    }
  }

ofstream outFile("lab2-2_class_outfile.txt");
if(!outFile.is_open()){
  cerr << "error : Lab2-2_class_outfile.txt can't open" << endl;
  return 1;
}
else{
  for(int i = 0; i < 7; i++){
    switch (angle[i].getType()) {
      case 1:
        cout << "triangle" << " " << angle[i].width << " " << angle[i].height << " " << angle[i].calculate() << endl;
        break;
      case 2:
        cout << "rectangle" << " " << angle[i].width << " " << angle[i].height << " " << angle[i].calculate() << endl;
        break;
      case 3:
        cout << "circle" << " " << angle[i].round << " " << angle[i].calculate() << endl;
        break;
      default:
        break;
    }


  }

}
}
