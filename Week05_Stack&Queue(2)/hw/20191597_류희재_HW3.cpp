/*
1) Main Heading
*********************************************************
* Name:  ������
* Student ID : 20191587
* Program ID : HW3
* Description : �־��� Matrix �ȿ��� stack�� �̿��Ͽ� ���� ã�� ����(�������� �������� ����)
* Algorithm :
    1. �̷θ� ǥ���ϴ� maze��� ������ �迭�� ������ ���� ǥ���ϴ� mark��� �������迭�� �����Ѵ�
    2. 8����(��, ����, ��, �ϵ�, ��, �ϼ�, ��, ����)�� ǥ���ϴ� ����ü�� offsets�� �����Ѵ�.
    3. ���� ��ġ�� ǥ���ϱ� ���ؼ� ������ ��, �� �׸��� ������ ǥ���ϴ� ����ü�� element�� �����Ѵ�
    4. ������ ��ġ�� �����ϱ� ���� element �Ӽ��� stack�� �����Ѵ�.
    5. stack�� top�� ���� - 1�� �ƴϰ� �������� ã�� �������� stack���� ���� ��ġ�� pop�Ѵ�.
    6. ������ �ѹ��� �����鼭 ���� ��ġ�� ���ؼ� ���� ������(0�̸�) stack�� ��ġ�� �����Ѵ�
    7. ���� �������� �����Ѵٸ� found�� ���� true�� �ٲ��ش�.
    8. ������������ ���� ������ stack�� ������ ����Ѵ�
    9. ������������ ����� mark �迭�� ����Ѵ�.


    * Variables:
Ŭ����: Stack
����ü : element, offsets
�Լ� : void push(element position), element pop(), bool isEmpty(), bool isFull(), intgetTop()
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
function : Stack() ������ �Լ�
description : stack�� �ʱⰪ�� ����
variables : row : ��
            col : ��
            dir : ����(0���� �� ������ ���ʺ��� �ð�������� ������ ����)

****************************************************************************/

  Stack(){
    top = 0;
    stack[0].row = 0;
    stack[0].col = 0;
    stack[0].dir = 0;
  }

  /****************************************************************************
function : void push(element position)
description : stack�� ���� ��ġ���� �����ֱ� ���� �Լ�
****************************************************************************/
  void push(element position){
    if(isFull()){ cout << "Stack is full" << endl;
  }else{ stack[++top] = position;}
  }
  /****************************************************************************
function : element pop()
description : stack�� ���� ��ġ���� ���ֱ� ���� �Լ�
****************************************************************************/
  element pop(){
    if(isEmpty()){  cout << "Stack is Empty" << endl;
    }else{
        return stack[top--]; }
  }
  /****************************************************************************
function : bool isEmpty()
description : stack�� ������� Ȯ�����ִ� �Լ�
****************************************************************************/
  bool isEmpty(){
    if(top == -1){  return true;
    }else{  return false; }
  }
  /****************************************************************************
function : bool isFull()
description : stack�� �� á���� Ȯ�����ִ� �Լ�
****************************************************************************/
  bool isFull(){
    if(top == StackSize -1){ return true;
    }else{  return false; }
  }
  /****************************************************************************
function : int getTop()
description : stack�� top���� ��ȯ���ִ� �Լ�
****************************************************************************/
  int getTop(){
    return top;
  }
  void displayStack();
};
/****************************************************************************
function : void Stack::displayStack()
description : stack�� ��� ���� ������ִ� �Լ�
****************************************************************************/
void Stack::displayStack(){
  for(int i = 0; i < top; i++){
    cout << stack[i].row << " " << stack[i].col << endl;
  }
}


/****************************************************************************
function : int main()  ���� �Լ�
description : �ݺ����� ���ؼ� ���� ã�� ���α׷�
variables : int maze : �̷�
            int mark: ������ ��� ǥ��
            bool found: �������� ã�Ҵ����� �������ִ� ����
            element position: ������ġ�� ��Ÿ���� ����
            offsets move: ������ �˷��ִ� ����ü ����

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
