#include <iostream>

using namespace std;



//마방진 프로르램 만들기

void right(int Number, int MS[][21], int i, int j, int n){
  while (Number <= n*n){
    if ((Number-1)%n == 0){	// 이전에 사용한 Number가 입력한 n의 배수이면 그다음 숫자는 바로 아래에 써준다.
      i++;
      MS[i][j] = Number;
      Number++;
    }

else{
  if (i - 1 < 1){
    i = n;
    j++;
    MS[i][j] = Number;
    Number++;
  }//bottom right

else if (j + 1 > n){
  i--;
  j = 1;
  MS[i][j] = Number;
  Number++;
}//top left

else{
  i--;
  j++;
  MS[i][j] = Number;
  Number++;
}


}

}

for (i = 1; i <= n;i++){
  for (j = 1; j <= n;j++){
    cout << MS[i][j]<< " ";

  }
  cout << endl;

  }
}


void left(int Number, int MS[][21], int i, int j, int n){while (Number <= n*n){
  if ((Number-1)%n == 0){	// 이전에 사용한 Number가 입력한 n의 배수이면 그다음 숫자는 바로 아래에 써준다.
    i++;
    MS[i][j] = Number;
    Number++;
  }

else{
if (i - 1 < 1){
  i = n;
  j--;
  MS[i][j] = Number;
  Number++;
}//bottom right

else if (j - 1 < 1){
i--;
j = n;
MS[i][j] = Number;
Number++;
}//top left

else{
i--;
j--;
MS[i][j] = Number;
Number++;
}


}

}

for (i = 1; i <= n;i++){
for (j = 1; j <= n;j++){
  cout << MS[i][j]<< " ";

}
cout << endl;

}









}

int main(){
  int Number, MS[21][21] = {0, }, i, j;
  int n;
  cin >> n;

  Number = 1;
  i = 1;
  j = (n / 2) + 1;

  MS[i][j] = Number;	// 초기 1값은 맨 윗줄 중앙에 넣어준다.
  Number++;

  cout << "magic square size is " << " " << n << endl;

  right(Number, MS, i, j, n);
  left(Number, MS, i, j, n);



return 0;

}
