/*
1) Main Heading
*********************************************************
* Name:  류희재
* Student ID : 20191587
* Program ID : HW2
* Description : 데이터 파일로 입력받은  식을 출력하고 그 식을 infix ? postfix 에 의해 conversion 한 후 postfix form을 출력한 후 postfix evaluation algorithm 을 이용하여 최종 값을 출력한다.
* Algorithm :
? Algo rithm :
1. 1. Initialize stack Initialize stack Initialize stack Initialize stack Initialize stack Initialize stack
2. 2. Repeat until end Repeat until end Repeat until end -of -expressionexpression expressionexpression
. Get next token. Get next token . Get next token . Get next token. Get next token . Get next token . Get next token. Get next token
. If . If “token = operand “token = operand “token = operand “token = operand “token = operand “token = operand ” then PUSHthen PUSH then PUSH onto Stack onto Stackonto Stack onto Stackonto Stack onto Stackonto Stack
else “ else “ token=operator” token=operator” token=operator” token=operator” token=operator” token=operator” token=operator”
. POP two operands from stack . POP two operands from stack. POP two operands from stack. POP two operands from stack . POP two operands from stack . POP two operands from stack. POP two operands from stack . POP two operands from stack. POP two operands from stack (OP2 & OP1)(OP2 & OP1) (OP2 & OP1) (OP2 & OP1)
. Apply the operator to these . Apply the operator to these. Apply the operator to these . Apply the operator to these. Apply the operator to these . Apply the operator to these . Apply the operator to these . Apply the operator to these . Apply the operator to these (OP1 OP O(OP1 OP O (OP1 OP O(OP1 OP O(OP1 OP O P2)
. Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack. Push the results onto stack . Push the results onto stack .

/*
int eval(void) {
int op1,op2;
int n = 0; /* 수식 string을 위한 counter
int top = -1;
token = get_token(&symbol, &n);
while (token != eos) {  not end of string
    if (“token == operand”) Push(&top, symbol - '0'); convert to num.
    else {  if operator, then, 연산수행 후, 결과를 stack에 push
    op2 = POP(&top);  스택 삭제 (POP)
    op1 = POP(&top);
    switch (token) {
    case ‘ + ’: PUSH(&top, op1 + op2); break;
    case ‘ - ‘: PUSH(&top, op1 - op2); break;
    case ‘* ’: PUSH(&top, op1 * op2); break;
    case ‘ / ’: PUSH(&top, op1 / op2); break;
    }
}
token = get_token(&symbol, &n);
}
return POP(&top);
}



* Variables :
    클래스 Stack a, typedef enum {}precedure, void postfix(char input[]),
    Static int isp[], static int icp[], precedure getToken, char getValue(char s), int eval(char a[])
    등의 변수와 함수를 사용하였다.
    *************************************************************************/

#include <iostream> //cin,cout을 위한 해더파일
#include <fstream> //파일 입출력을 위한 해더파일
#include <cstring>
using namespace std;
const int StackSize = 100; //stacksize

//구조체를 활용하여 연산자 사이에 가중치를 정해주는 배열을 정의한다.
typedef enum { lparen, rparen, pluss, minuss, times, divide } precedure;
static int isp[] = { 0, 3, 1, 1, 2, 2 };
static int icp[] = { 4, 3, 1, 1, 2, 2 };

void postfix(char* buffer); //후위표기식으로 바꾸는 함수
void eval(char target[]);  //후위표기식을 계산하는 함수


//stack class
class Stack {
private: //스택의 크기와 top을 지정
    char stack[StackSize];
    int top; //top
public:
    Stack() {
        top = -1;	//stack 생성자
    }
    void push(int val) {
        stack[++top] = val; //stack에 값을 넣어주고 top의 값을 증가시킨다.
    }
    char pop() {
        return stack[top--];	//stack의 값을 빼주고 top의 값을 감소시킨다
    }
    int isEmpty() { //stack이 비어있는지를 확인한다.
        return top == -1;
    }
    int isFull() {
        return top == StackSize - 1;	//stack이 가득 찼는지 확인한다.
    }
    int get_stack_top() {
        return stack[top]; //top에 위치에 있는 stack값을 가져온다.
    }
};

// precedure getToken(char s)과 char getValue(precdure p)는 연산자 가중치 비교 와 출력을 자유롭게 하기 위해서 만들었다.

precedure getToken(char s) {
    switch (s) {
    case '(': return lparen;
    case ')': return rparen;
    case '+': return pluss;
    case '-': return minuss;
    case '*': return times;
    case '/': return divide;

    }
}

char getValue(precedure p) {
    switch (p) {
    case lparen: return '(';
    case rparen: return ')';
    case pluss: return '+';
    case minuss: return '-';
    case times: return '*';
    case divide: return '/';

    }
}

/****************************************************************************
function : int main()  메인 함수
description : 데이터파일(“jaguhw2inputfile.txt”)을  받아 들여서 postfix함수
    거쳐 변환, 계산을 수행하여 이를 출력한다.
variables : char buffer[100] 은 입력 하기 위한 배열..
****************************************************************************/


int main(void) {
    char buffer[100];
    Stack stack;
    ifstream inFile("jaguhw2inputfile.txt");
    if (!inFile.is_open()) { //만약 파일이 열리지 않는다면
        cerr << "error : inputfile.txt can't open" << endl;
        return 1;
        //열리지 않는다는 메시지를 남기고 프로그램을 끝낸다
    }
    else {
        while (inFile.getline(buffer, 100)) {
            //입력한 데이터를 출력한다.
            cout << "Echo Data : " << buffer << endl;
            //후위표기식을 출력한다
            cout << "Conversion : ";
            postfix(buffer);
            //cout << target << endl;
        }
    }
}


/****************************************************************************
function : void postfix(char buffer[]) infix에서 postfix로 변환하는
    함수이다.
description : 입력받은 식을 postfix 함수로 후위표기 식으로 바꿔준다.
variables : char input[] 위에서 입력 받은식, char target[100] 은 후위표기 저장할 배열
****************************************************************************/

void postfix(char buffer[]) {
    Stack stack; //연산자들을 담기 위한 stack
    char target[100] = { 0 }; //후위표기식
    int n = 0; //target의 위치를 count하는 수
    int len = strlen(buffer); // 입력데이터의 길이
    for (int i = 0; i < len; i++) {
        //만약 숫자라면
        if ('0' <= buffer[i] && buffer[i] <= '9') {
            target[n++] = buffer[i];
            cout << buffer[i];
        }
        //만약 왼쪽 괄호라면
        else if (buffer[i] == '(') {
            //그냥 push한다
            stack.push(lparen);
        }
        //만약 오른쪽 괄호라면
        else if (buffer[i] == ')') {
            precedure tmp;
            //stack안에 왼쪽 괄호를 만나기 전까지 모든 연산자를 출력
            while (((tmp = (precedure)stack.pop()) != lparen)) {
                target[n++] = getValue(tmp);
                cout << getValue(tmp);
            }

        }
        else {
            //만약 연산자라면
            while (!stack.isEmpty() && (isp[stack.get_stack_top()] >= icp[getToken(buffer[i])])) {
                //연산자의 가중치를 따져서 pop해준다
                precedure tmp = (precedure)stack.pop();
                target[n++] = getValue(tmp);
                cout << getValue(tmp);
            }
            stack.push(getToken(buffer[i]));
        }
    }


    while (!stack.isEmpty()) {
        //stack이 비어있지 않는다면 target에 추가한다
        precedure tmp = (precedure)stack.pop();
        cout << getValue(tmp);
        target[n++] = getValue(tmp);

    }
    cout << endl;
    target[n++] = '\0';
    eval(target);

}

/****************************************************************************
function : int eval(char target[])
description : 후위표기식 저장된 target[]을 eval 함수에 의해 계산.
variables : char target[] ? 후위표기식 저장된 배열
****************************************************************************/


void eval(char target[]) {
    Stack stack2;
    int len = strlen(target);
    for (int i = 0; i < len; i++) {
        //만약 숫자라면
        if (target[i] >= '0' && target[i] <= '9') {
            stack2.push(target[i] - 48);
            //아스키코드를 따라서 값을 char -> int로 하여 stack에 추가한다
        }
        else {
            //연산자라면 
            //stack안에 두 숫자를pop해서
            int op2 = stack2.pop();
            int op1 = stack2.pop();

            switch (target[i]) {
                //연산자에 따라서 계산한다
            case '+':
                stack2.push(op1 + op2);
                break;

            case '-':
                stack2.push(op1 - op2);
                break;

            case '*':
                stack2.push(op1 * op2);
                break;

            case '/':
                stack2.push(op1 / op2);
                break;
            }


        }
    }
    //계산값을 프린트한다
    cout << "Result : ";
    cout << stack2.get_stack_top() << endl;
}



