/*
1) Main Heading
*********************************************************
* Name:  류희재
* Student ID : 20191587
* Program ID : HW6
* Description : 인접리스트로 DFS 구현
* Algorithm : 함수들을 테스트 하는 것임으로 각각 함수 설명에서 알고리즘 개별적 설명 진행
* Variables:
클래스: Node - 노드 클래스
		Tree - 트리 클래스
함수 :
    Tree()
    void build_tree(int p, int c);
    void print_node();
    void dfs(int v)

************************************************************************/


#include <iostream>
#include <fstream>
#include <string.h>
#define MAX 8 //visited, graph의 크기
using namespace std;

class Node{
private:
    int data;
    Node *link;
    Node(int value) {data = value; link = 0;}
friend class Tree;
};
/*********************************************************************************************************
*function : Tree()
*Description : Tree클래스 default 생성자. 
	           방문배열과 graph배열을 초기화 해준다.
*********************************************************************************************************/

class Tree{
private:
    Node* graph[MAX];
    bool visited[MAX];
public:
    Tree();
    void build_tree(int p, int c);
    void print_node();
    void dfs(int v);
};

Tree::Tree(){
	for (int i = 0; i < MAX; i++){
		visited[i] = false;
	}
	for (int i = 0; i < MAX; i++){
		graph[i] = NULL;
	}
}
/*********************************************************************************************************
*function : build(int p, int c)
*Description : 인접 리스트를 만드는 함수
*Variables : 
	   Node *temp_P : 부모노드를 만드는 노드
	   Node *temp_C : 자식노드를 만드는 노드
*Algorithm : 1. 들어온 노드들이 graph에 없는경우 새로운 노드를 만들어 graph배열에 담는다.
			 2. p를 부모노드로 하여, p노드 끝에 c노드를 연결한다. 
			 3. 인접리스트를 생성한다.
*********************************************************************************************************/
void Tree::build_tree(int p, int c){
    if (graph[p] == NULL){
		Node *temp_P = new Node(p);
		graph[p] = temp_P;
	}
	if (graph[c] == NULL){
		Node *temp_C = new Node(c);
		graph[c] = temp_C;
	}

	Node *P = graph[p];
	Node *C = new Node(c);
	while (P->link != NULL) P = P->link;
	P->link = C;
}


/*********************************************************************************************************
*function : print_graph()
*Description : graph를 전체 출력하는 함수. 
*Algorithm : 1. graph배열을 돌면서 각 노드가 link되어있는 노드를 모두 출력한다. 
			 2. graph 원소가 비어있으면 출력하지 않는다.
*Variables : Node *w - 그래프를 탐색하기 위한 포인터 변수
*********************************************************************************************************/
void Tree::print_node(){
    Node *w;
	for (int i = 0; i < MAX; i++){
		if (graph[i] != NULL){
			cout << "Graph[" << i << "]   ->  ";
			for (w = graph[i]->link; w != NULL; w = w->link){
				cout << w->data << " ";
			}
			cout << endl;
		}
	}
}

/*********************************************************************************************************
*function : dfs(int v)
*Description : DFS를 하기 위한 함수. 
*Algorithm : 1. v는 그래프의 초기 root인 0을 의미한다. 
             2. 루트의 visited를 true로 설정한다. 
			 3. v를 출력한다. 
			 4. null값이 나올때 까지 root노드를 계속 link하여 반복한다
			 5. 인접한 노드의 visited가 0인 노드이면 다시 dfs를 호출하고 인자는 노드의 데이터값으로 한다.
*Variables : Node *w - 그래프를 탐색하기위한 포인터 변수
*********************************************************************************************************/

void Tree::dfs(int v){
	Node *w;
	visited[v] = true;
	cout << "V" << v;
	for (w = graph[v]; w != NULL; w = w->link){
		if (!visited[w->data]) {
			cout << " -> ";
			dfs(w->data);
		}
	}
}
 
    
int main(){
	Tree t1, t2;
	ifstream in("hw9.txt");
	int num1, num2;

	for (int i = 0; i < 20; i++){
		in >> num1 >> num2; //파일을 읽어들여 그 값을 num1, num2에 할당
		t1.build_tree(num1, num2);
	}
	cout << "Graph Data #1: \n";
	t1.print_node();
	cout << "\nOutput : \n";
	t1.dfs(0);
	cout << endl;

	for (int i = 0; i < 16; i++){
		in >> num1 >> num2;
		t2.build_tree(num1, num2);
	}
	cout << "Graph Data #2: \n";
	t2.print_node();
	cout << "\nOutput : \n";
	t2.dfs(0);
	cout << endl;
}
