#include<iostream>
using namespace std;

void triangle(string type, int w, int h);
void rectangle(string type, int w, int h);
void circle(string type, int r);

struct Angle{
  string type;
  int width;
  int height;
  int round;
  double area;
};


int main(void)
{
  Angle angle[7];

  int idx = 0;
  string type;
  while(idx < 7){
    cin >> type;
    if(type == "triangle"){
      angle[idx].type = "triangle";
      cin >> angle[idx].width;
      cin >> angle[idx].height;
      triangle(angle[idx].type, angle[idx].width,  angle[idx].height);
    }
    else if(type == "rectangle"){
      angle[idx].type = "rectangle";
      cin >> angle[idx].width;
      cin >> angle[idx].height;
      rectangle(angle[idx].type, angle[idx].width,  angle[idx].height);
    }
    else{
      angle[idx].type = "circle";
      cin >> angle[idx].round;
      circle(angle[idx].type, angle[idx].round);
    }
    idx++;
  }

}
void triangle(string type, int w, int h)
{

  double area = (double)w * (double)h * 1/2;
  cout << type << " " << (double)w << " " << (double)h << " " << (double)area << endl;
}

void rectangle(string type, int w, int h)
{
  double area = (double)w * (double)h;
  cout << type << " "  << (double)w << " " << (double)h << " " << (double)area << endl;
}

void circle(string type, int r)
{
  double area = (double)r * (double)r * 3.14;
  cout << type << " " << (double)r << " " << (double)area << endl;
}
