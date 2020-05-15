
/************************************************************************************************* 
1)	Main Heading
    Name : 류희재
    Student ID : 20191587
    Program ID : HW1 – ARRAY EXERCISE
    Description : 배열을 활용하여 행렬을 구성하고 전치행렬을 구하는 것
    Algorithm :
    1) 희소 행렬의 전치
    void transpose( SMarray a[], SMarray b[]) { // a를 전치시켜 b를 생성, 예:(0,3,22) -> (3,0,22)
    int i, j, currentb; // 6 6 8
    b[0].row = a[0].col; b[0].col = a[0].row; b[0].value = a[0].value;
    if (a[0].value > 0) { /* 0이 아닌 행렬
        currentb = 1;
    for (i = 0; i <a[0].col; i++) // a에서 열별로 전치
        for (j = 1; j ≤ a[0].value; j++) //현재의 열로부터 원소를 찾는다. 
    if (a[j].col == i) {
        //현재 열에 있는 원소를 b에 첨가 
        b[currentb].row = a[j].col;
        b[currentb].col = a[j].row;
        b[currentb].value = a[j].value;
        currentb++;
       } }}

    2) 희소 행렬의 전치 - 개선된 알고리즘
    void fast_transpose(term a[], term b[]) {
    //a를 전치시켜 b에 저장 
    int row_terms[MAX_COL], starting_pos[MAX_COL];
    int i, j, num_cols = a[0].col, num_terms = a[0].value;
        b[0].row = num_cols; //6
        b[0].col = a[0].row; //6
        b[0].value = num_terms; //8
    if (num_terms > 0) { // 0이 아닌 행렬 
    for (i = 0; i < num_cols; i++)
        row_terms[i] = 0; // number of terms 초기화
    for (i = 1; i ≤num_terms; i++) // 각 row terms위한 값
    row_terms[a[i].col]++;
    starting_pos[0] = 1; /* 각 row terms시작점 구함
    for(i = 1; i < num_cols; i++)
    starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
    for(i = 1; i ≤ num_terms; i++) { /* A를 B로 옮김
    j = starting_pos[a[i].col]++;
    b[j].row = a[i].col; b[j].col = a[i].row;
    b[j].value = a[i].value;
    }
    } }


    Variable :
        1. void original(Matrix matrix[], int size, int cnt_row) >> 일반행렬 구하는  함수
        2. void transposeMatrix(Matrix matrix[], int cnt_col, int cnt_row) >> 열과 행을 바꾼 행렬을 구하는 함수
        3. void rowmajor(Matrix matrix[], int cnt_value) >> 희소행렬을 구하는 함수
        4. void columnmajor(Matrix matrix[], int cnt_col, int cnt_value) >> 희소행렬의 전치행렬을 구하는 함수
        5. void fasttranspose(Matrix matrix[], int cnt_col, int cnt_value) >> 희소행렬의 전치행렬을 빠르게 구하는 함수
        6. int main(void) >> 데이터 화일을 입력받아 결괏값을 출력하는 함수
*/








#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
#define MAX 100




class Matrix{
//friend class SparseMatrix;
public:
  int row, col, value;

  /*
  function : void original(Matrix matrix[], int size, int cnt_row)
  description : 일반 행렬을 구하기 위해서 사용을 했다. 
  variables:
    n = 배열의 열의 위치를 나타낸다
    matrix : class Matrix의 배열로 row, col, value를 가지고 있다
    size : 행렬의 크기를 나타냄으로 main 함수에서 col의 수와 row의 수를 곱하여 도출하였다
    cnt_row : 행렬의 row의 갯수를 나타낸다. cnt_row를 통해서 열의 끝을 알려주며, 다음 열로 넘어갈 수 있도록 도와준다. 
  */

    void original(Matrix matrix[], int size, int cnt_row){
      cout << "1)  original Matrix: A" << endl;
      int n = 0;
      for(int i = 0; i < size; i++){
        cout << matrix[i].value << " "; //n을 통해서 행의 끝을 정해준다
        n++;
        if(n == cnt_row){
          cout << endl;
          n = 0; // 다음 열로 넘어가면 n = 0으로 초기화 시켜준다.
        }
      }
    }
  /*
   function : void transposeMatrix(Matrix matrix[], int cnt_col, int cnt_row)
   description : 일반 행렬의 열과 행을 바꾼 행렬을 구하기 위해 사용을 했다.
   variables:
   n = 배열의 열의 위치를 나타낸다
   matrix : class Matrix의 배열로 row, col, value를 가지고 있다
   size : 행렬의 크기를 나타냄으로 main 함수에서 col의 수와 row의 수를 곱하여 도출하였다
   cnt_row : 행렬의 row의 갯수를 나타낸다. cnt_row를 통해서 열의 끝을 알려주며, 다음 열로 넘어갈 수 있도록 도와준다.
  */
    void transposeMatrix(Matrix matrix[], int cnt_col, int cnt_row){
      cout << "2) Transpose of Original matrix A" <<  endl;
      int n = 0;
      for(int i = 0; i < cnt_col; i++){
        for(int j = 0; j < cnt_row; j++){
          cout << matrix[n].value << " ";
          n = n + cnt_col;
        }
        cout << endl;
        n = i+1;
      }
    }
  /*
   function : void rowmajor(Matrix matrix[], int cnt_value)
   description : 희소행렬을 구하기 위해서 사용했다.
   variables:
   matrix : class Matrix의 배열로 row, col, value를 가지고 있다. main함수에서 value가 0인 값을 제외하고 배열에 담았다
   cnt_value : matrix의 value값의 개수를 나타낸다. 
  */

      void rowmajor(Matrix matrix[], int cnt_value){
      cout << "3) Sparse matrix of A - row major" << endl;
      for(int i = 0; i < cnt_value; i++){
          cout << matrix[i].row << " " <<  matrix[i].col << " " << matrix[i].value << endl;
    }
  }


  /*
   function :  void columnmajor(Matrix matrix[], int cnt_col, int cnt_value)
   description : 희소행렬의 전치행렬을 구하는 함수
   variables:
   n = 배열의 열의 위치를 나타낸다
   matrix : class Matrix의 배열로 row, col, value를 가지고 있다. main함수에서 value가 0인 값을 제외하고 배열에 담았다
   cnt_value : matrix의 value값의 개수를 나타낸다.
   cnt_row : 행렬의 row의 갯수를 나타낸다.
   rematrix : 전치된 행렬을 저장할 배열이다.
   currentm : 전치를 하는 과정 중 rematrix의 인덱스를 결정해주는 변수이다.
  */
    void columnmajor(Matrix matrix[], int cnt_col, int cnt_value){
      cout << "4)Transpose of Sprase matrix A - column major" << endl;
      Matrix rematrix[MAX];
      if (cnt_value > 0){
        int currentm = 0;
        for(int i = 0; i < cnt_col; i++){
          for(int j = 0; j < cnt_value; j++){
            if(matrix[j].col == i){
              rematrix[currentm].row = matrix[j].col;
              rematrix[currentm].col = matrix[j].row;
              rematrix[currentm].value = matrix[j].value;
              currentm++;
            }
          }
        }


      }
      for(int k = 0; k < cnt_value; k++){
          cout << rematrix[k].row << " " << rematrix[k].col << " " << rematrix[k].value << endl;
      }

}

    /*
   function :  void fasttranspose(Matrix matrix[], int cnt_col, int cnt_value)
   description : 희소행렬의 전치행렬을 빠르게 구하는 함수
   variables:
   starting_pos = rematrix의 시작점을 알려주는 배열이다
   row_terms = 각 index의 col의 갯수를 구한다.
   matrix : class Matrix의 배열로 row, col, value를 가지고 있다. main함수에서 value가 0인 값을 제외하고 배열에 담았다
   cnt_value : matrix의 value값의 개수를 나타낸다.
   cnt_row : 행렬의 row의 갯수를 나타낸다.
   rematrix : 전치된 행렬을 저장할 배열이다.
   
  */
  void fasttranspose(Matrix matrix[], int cnt_col, int cnt_value){
    cout << "5)Fast transpose of Sprase matrix A" << endl;
    Matrix rematrix[MAX];

    int row_terms[MAX];
    int starting_pos[MAX];
    int i, j;

    if(cnt_value > 0){
      for(i = 0; i < cnt_col; i++){
        row_terms[i] = 0;
      }
      for(i = 0; i < cnt_col; i++){
        int cnt = 0;
        for(int k = 0; k < cnt_value; k++){
          if(matrix[k].col == i){
            cnt++;
          }
        row_terms[i] = cnt;
      }
      //cout << row_terms[i] << endl;
    }
      starting_pos[0] = 0;
      for(i = 0; i < cnt_col; i++){
        starting_pos[i+1] = starting_pos[i] + row_terms[i];
        //cout << starting_pos[i] << endl;
      }

      for(i = 0; i < cnt_value; i++){
        j = starting_pos[matrix[i].col]++;
        rematrix[j].row = matrix[i].col;
        rematrix[j].col = matrix[i].row;
        rematrix[j].value = matrix[i].value;
      }



    for(int k = 0; k < cnt_value; k++){
      cout << rematrix[k].row << " " << rematrix[k].col << " " << rematrix[k].value << endl;
    }
  }
}




Matrix(){
  row = 0; col = 0; value = 0;
}
Matrix(int col, int row, int value){
  this->row = row; this->col = col;
  this->value = value;
  }
};

int main(void){
  Matrix original[MAX]; //일반 행렬을 위한 matrix
  Matrix smArray[MAX]; //희소행렬을 위한 matrix
  int size;
  int cnt_row = 0; int cnt_col = 0; int cnt_value = 0;
  ifstream inFile("jaguhwinputfile.txt");
  if(!inFile.is_open()){ //데이터 파일 열리지 않으면
    cerr << "error : inputfile.txt can't open" << endl; //에러메세지 보냄
    return 1;
  }
  else{
    char delim = ' ';
    int pos_c = 0; int pos_r = 0;
    string s;
    int idx = 0; int sidx = 0; //idx->일반행렬의 인덱스값 sidx ->희소행렬의 인덱스값
    while(!inFile.eof()){
      string line;
      getline(inFile,line);
      stringstream f(line);
      while(getline(f, s, delim)){
        original[idx] =  Matrix(pos_c, pos_r, stoi(s));//string으로 읽어오기 때문에 stoi함수를 통해 s를 int형으로 변환시켜준다
        if(stoi(s) != 0){
          smArray[sidx] = Matrix(pos_c, pos_r, stoi(s));
          cnt_value++;
          sidx++;
        }
        pos_c++;
        idx++;
        cnt_row++;
      }
      pos_c = 0;
      pos_r++;
      cnt_col++;


    }

    cnt_col = cnt_col - 1; //실질적 col의 갯수는 읽어오는 라인값의 1을 빼줘야 한다
    cnt_row = cnt_row/cnt_col; //row의 실질적 값은 전체 idx값에서 cnt_col로 나눠줘야한다
    size = cnt_col * cnt_row; //sizw는 행의 개수와 열의 개수를 곱한것이다

}






  ofstream outFile("jaguhwoutfile.txt");
  if(!outFile.is_open()){
    cerr << "error : outfile.txt can't open" << endl;
    return 1;
  }
  else{
      Matrix m;
      m.original(original, size, cnt_row);
      cout << endl;
      m.transposeMatrix(original, cnt_col, cnt_row);
      cout << endl;
      m.rowmajor(smArray, cnt_value);
      cout << endl;
      m.columnmajor(smArray,cnt_col,cnt_value);
      cout << endl;
      m.fasttranspose(smArray,cnt_col,cnt_value);
      cout << endl;
    }
  }







