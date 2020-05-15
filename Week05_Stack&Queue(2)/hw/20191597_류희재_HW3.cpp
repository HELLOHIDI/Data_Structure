/*
1) Main Heading
*********************************************************
* Name:  류희재
* Student ID : 20191587
* Program ID : HW3
* Description : 주어진 Matrix 안에서 stack을 이용하여 길을 찾는 문제(시작점과 도착점을 제공)
* Algorithm :
    1. 미로를 표시하는 maze라는 이차원 배열과 지나간 것을 표시하는 mark라는 이차원배열을 생성한다
    2. 8방향(남, 남동, 동, 북동, 북, 북서, 서, 남서)를 표시하는 구조체인 offsets을 생성한다.
    3. 현재 위치를 표시하기 위해서 현재의 행, 열 그리고 방향을 표시하는 구조체인 element를 생성한다
    4. 지나온 위치를 저장하기 위해 element 속성의 stack을 생성한다.
    5. stack의 top의 값이 - 1이 아니고 도착점을 찾지 못했으면 stack에서 이전 위치를 pop한다.
    6. 방향을 한번씩 돌리면서 다음 위치를 더해서 길이 있으면(0이면) stack의 위치를 저장한다
    7. 만약 도착점에 도착한다면 found의 값을 true로 바꿔준다.
    8. 도착점까지의 길을 저장한 stack의 값들을 출력한다
    9. 도착점까지의 경로인 mark 배열을 출력한다.


    * Variables:
클래스: Stack
구조체 : element, offsets
함수 : void push(element position), element pop(), bool isEmpty(), bool isFull(), intgetTop()
void displayStack();



*************************************************************************/

#include <iostream>
using namespace std;

const int StackSize = 100; //stacksize

typedef struct{
  int row;
  int col;
  int dir;
}element;



typedef struct{
  int vert;
  int horiz;
}offsets;
int maze[6][6] = {{0,1,1,1,1,1},
                  {1,0,1,1,1,1},
                  {1,0,0,0,0,1},
                  {1,1,0,1,1,1},
                  {1,0,1,0,0,1},
                  {1,1,1,1,1,0}
                };
int mark[6][6] = {{0,0,0,0,0,0},
                  {0,0,0,0,0,0},
                  {0,0,0,0,0,0},
                  {0,0,0,0,0,0},
                  {0,0,0,0,0,0},
                  {0,0,0,0,0,0}
                };


class Stack{
private:
  element stack[StackSize];
  int top;
public:
/****************************************************************************
function : Stack() 생성자 함수
description : stack의 초기값을 설정
variables : row : 행
            col : 열
            dir : 방향(0으로 한 이유는 북쪽부터 시계방향으로 돌리기 위함)

****************************************************************************/

  Stack(){
    top = 0;
    stack[0].row = 0;
    stack[0].col = 0;
    stack[0].dir = 0;
  }

  /****************************************************************************
function : void push(element position)
description : stack의 현재 위치값을 더해주기 위한 함수
****************************************************************************/
  void push(element position){
    if(isFull()){ cout << "Stack is full" << endl;
  }else{ stack[++top] = position;}
  }
  /****************************************************************************
function : element pop()
description : stack의 이전 위치값을 빼주기 위한 함수
****************************************************************************/
  element pop(){
    if(isEmpty()){  cout << "Stack is Empty" << endl;
    }else{
        return stack[top--]; }
  }
  /****************************************************************************
function : bool isEmpty()
description : stack이 비었는지 확인해주는 함수
****************************************************************************/
  bool isEmpty(){
    if(top == -1){  return true;
    }else{  return false; }
  }
  /****************************************************************************
function : bool isFull()
description : stack의 꽉 찼는지 확인해주는 함수
****************************************************************************/
  bool isFull(){
    if(top == StackSize -1){ return true;
    }else{  return false; }
  }
  /****************************************************************************
function : int getTop()
description : stack의 top값을 반환해주는 함수
****************************************************************************/
  int getTop(){
    return top;
  }
  void displayStack();
};
/****************************************************************************
function : void Stack::displayStack()
description : stack의 모든 값을 출력해주는 함수
****************************************************************************/
void Stack::displayStack(){
  for(int i = 0; i < top; i++){
    cout << stack[i].row << " " << stack[i].col << endl;
  }
}


/****************************************************************************
function : int main()  메인 함수
description : 반복문을 통해서 길을 찾는 프로그램
variables : int maze : 미로
            int mark: 지나간 경로 표시
            bool found: 도착점을 찾았는지를 구분해주는 역할
            element position: 현재위치를 나타내는 변수
            offsets move: 방향을 알려주는 구조체 변수

****************************************************************************/

int main(void){
  Stack s1;
  bool found = false;
  offsets move[8];
  move[0].vert = -1; move[0].horiz = 0;
  move[1].vert = -1; move[1].horiz = 1;
  move[2].vert = 0; move[2].horiz = 1;
  move[3].vert = 1; move[3].horiz = 1;
  move[4].vert = 1; move[4].horiz = 0;
  move[5].vert = 1; move[5].horiz = -1;
  move[6].vert = 0; move[6].horiz = -1;
  move[7].vert = -1; move[7].horiz = -1;

  mark[0][0] = 1;
  element position;
  int row, col, dir, next_row, next_col = 0;


  while(s1.getTop() != -1 &&!found){
    position = s1.pop();
    row = position.row;
    col = position.col;
    dir = position.dir;

    while(dir < 8 && !found){
      int next_row = row + move[dir].vert;
      int next_col = col + move[dir].horiz;
      if(next_row == 6 && next_col == 6){
        found = true;
      }else if(!maze[next_row][next_col] && !mark[next_row][next_col]){
        mark[next_row][next_col] = 1;
        position.row = row;
        position.col = col;
        position.dir = ++dir;
        s1.push(position);
        row = next_row;
        col = next_col;
        dir = 0;
      }else{
        dir++;
      }
    }
  }
  if(found){
    cout << "The path is" << endl;
    s1.displayStack();
    cout << endl;
    cout << "Marked Matrix" << endl;
    for(int i = 0; i < 6; i++){
      for(int j = 0; j < 6; j++){
        cout << mark[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
