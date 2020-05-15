/*
1) Main Heading
*********************************************************
* Name:  ������
* Student ID : 20191587
* Program ID : HW2
* Description : ������ ���Ϸ� �Է¹���  ���� ����ϰ� �� ���� infix ? postfix �� ���� conversion �� �� postfix form�� ����� �� postfix evaluation algorithm �� �̿��Ͽ� ���� ���� ����Ѵ�.
* Algorithm :
? Algo rithm :
1. 1. Initialize stack Initialize stack Initialize stack Initialize stack Initialize stack Initialize stack
2. 2. Repeat until end Repeat until end Repeat until end -of -expressionexpression expressionexpression
. Get next token. Get next token . Get next token . Get next token. Get next token . Get next token . Get next token. Get next token
. If . If ��token = operand ��token = operand ��token = operand ��token = operand ��token = operand ��token = operand �� then PUSHthen PUSH then PUSH onto Stack onto Stackonto Stack onto Stackonto Stack onto Stackonto Stack
else �� else �� token=operator�� token=operator�� token=operator�� token=operator�� token=operator�� token=operator�� token=operator��
. POP two operands from stack . POP two operands from stack. POP two operands from stack. POP two operands from stack . POP two operands from stack . POP two operands from stack. POP two operands from stack . POP two operands from stack. POP two operands from stack (OP2 & OP1)(OP2 & OP1) (OP2 & OP1) (OP2 & OP1)
. Apply the operator to these . Apply the operator to these. Apply the operator to these . Apply the operator to these. Apply the operator to these . Apply the operator to these . Apply the operator to these . Apply the operator to these . Apply the operator to these (OP1 OP O(OP1 OP O (OP1 OP O(OP1 OP O(OP1 OP O P2)
. Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack . Push the results onto stack. Push the results onto stack . Push the results onto stack .

/*
int eval(void) {
int op1,op2;
int n = 0; /* ���� string�� ���� counter
int top = -1;
token = get_token(&symbol, &n);
while (token != eos) {  not end of string
    if (��token == operand��) Push(&top, symbol - '0'); convert to num.
    else {  if operator, then, ������� ��, ����� stack�� push
    op2 = POP(&top);  ���� ���� (POP)
    op1 = POP(&top);
    switch (token) {
    case �� + ��: PUSH(&top, op1 + op2); break;
    case �� - ��: PUSH(&top, op1 - op2); break;
    case ��* ��: PUSH(&top, op1 * op2); break;
    case �� / ��: PUSH(&top, op1 / op2); break;
    }
}
token = get_token(&symbol, &n);
}
return POP(&top);
}



* Variables :
    Ŭ���� Stack a, typedef enum {}precedure, void postfix(char input[]),
    Static int isp[], static int icp[], precedure getToken, char getValue(char s), int eval(char a[])
    ���� ������ �Լ��� ����Ͽ���.
    *************************************************************************/

#include <iostream> //cin,cout�� ���� �ش�����
#include <fstream> //���� ������� ���� �ش�����
#include <cstring>
using namespace std;
const int StackSize = 100; //stacksize

//����ü�� Ȱ���Ͽ� ������ ���̿� ����ġ�� �����ִ� �迭�� �����Ѵ�.
typedef enum { lparen, rparen, pluss, minuss, times, divide } precedure;
static int isp[] = { 0, 3, 1, 1, 2, 2 };
static int icp[] = { 4, 3, 1, 1, 2, 2 };

void postfix(char* buffer); //����ǥ������� �ٲٴ� �Լ�
void eval(char target[]);  //����ǥ����� ����ϴ� �Լ�


//stack class
class Stack {
private: //������ ũ��� top�� ����
    char stack[StackSize];
    int top; //top
public:
    Stack() {
        top = -1;	//stack ������
    }
    void push(int val) {
        stack[++top] = val; //stack�� ���� �־��ְ� top�� ���� ������Ų��.
    }
    char pop() {
        return stack[top--];	//stack�� ���� ���ְ� top�� ���� ���ҽ�Ų��
    }
    int isEmpty() { //stack�� ����ִ����� Ȯ���Ѵ�.
        return top == -1;
    }
    int isFull() {
        return top == StackSize - 1;	//stack�� ���� á���� Ȯ���Ѵ�.
    }
    int get_stack_top() {
        return stack[top]; //top�� ��ġ�� �ִ� stack���� �����´�.
    }
};

// precedure getToken(char s)�� char getValue(precdure p)�� ������ ����ġ �� �� ����� �����Ӱ� �ϱ� ���ؼ� �������.

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
function : int main()  ���� �Լ�
description : ����������(��jaguhw2inputfile.txt��)��  �޾� �鿩�� postfix�Լ�
    ���� ��ȯ, ����� �����Ͽ� �̸� ����Ѵ�.
variables : char buffer[100] �� �Է� �ϱ� ���� �迭..
****************************************************************************/


int main(void) {
    char buffer[100];
    Stack stack;
    ifstream inFile("jaguhw2inputfile.txt");
    if (!inFile.is_open()) { //���� ������ ������ �ʴ´ٸ�
        cerr << "error : inputfile.txt can't open" << endl;
        return 1;
        //������ �ʴ´ٴ� �޽����� ����� ���α׷��� ������
    }
    else {
        while (inFile.getline(buffer, 100)) {
            //�Է��� �����͸� ����Ѵ�.
            cout << "Echo Data : " << buffer << endl;
            //����ǥ����� ����Ѵ�
            cout << "Conversion : ";
            postfix(buffer);
            //cout << target << endl;
        }
    }
}


/****************************************************************************
function : void postfix(char buffer[]) infix���� postfix�� ��ȯ�ϴ�
    �Լ��̴�.
description : �Է¹��� ���� postfix �Լ��� ����ǥ�� ������ �ٲ��ش�.
variables : char input[] ������ �Է� ������, char target[100] �� ����ǥ�� ������ �迭
****************************************************************************/

void postfix(char buffer[]) {
    Stack stack; //�����ڵ��� ��� ���� stack
    char target[100] = { 0 }; //����ǥ���
    int n = 0; //target�� ��ġ�� count�ϴ� ��
    int len = strlen(buffer); // �Էµ������� ����
    for (int i = 0; i < len; i++) {
        //���� ���ڶ��
        if ('0' <= buffer[i] && buffer[i] <= '9') {
            target[n++] = buffer[i];
            cout << buffer[i];
        }
        //���� ���� ��ȣ���
        else if (buffer[i] == '(') {
            //�׳� push�Ѵ�
            stack.push(lparen);
        }
        //���� ������ ��ȣ���
        else if (buffer[i] == ')') {
            precedure tmp;
            //stack�ȿ� ���� ��ȣ�� ������ ������ ��� �����ڸ� ���
            while (((tmp = (precedure)stack.pop()) != lparen)) {
                target[n++] = getValue(tmp);
                cout << getValue(tmp);
            }

        }
        else {
            //���� �����ڶ��
            while (!stack.isEmpty() && (isp[stack.get_stack_top()] >= icp[getToken(buffer[i])])) {
                //�������� ����ġ�� ������ pop���ش�
                precedure tmp = (precedure)stack.pop();
                target[n++] = getValue(tmp);
                cout << getValue(tmp);
            }
            stack.push(getToken(buffer[i]));
        }
    }


    while (!stack.isEmpty()) {
        //stack�� ������� �ʴ´ٸ� target�� �߰��Ѵ�
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
description : ����ǥ��� ����� target[]�� eval �Լ��� ���� ���.
variables : char target[] ? ����ǥ��� ����� �迭
****************************************************************************/


void eval(char target[]) {
    Stack stack2;
    int len = strlen(target);
    for (int i = 0; i < len; i++) {
        //���� ���ڶ��
        if (target[i] >= '0' && target[i] <= '9') {
            stack2.push(target[i] - 48);
            //�ƽ�Ű�ڵ带 ���� ���� char -> int�� �Ͽ� stack�� �߰��Ѵ�
        }
        else {
            //�����ڶ�� 
            //stack�ȿ� �� ���ڸ�pop�ؼ�
            int op2 = stack2.pop();
            int op1 = stack2.pop();

            switch (target[i]) {
                //�����ڿ� ���� ����Ѵ�
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
    //��갪�� ����Ʈ�Ѵ�
    cout << "Result : ";
    cout << stack2.get_stack_top() << endl;
}



