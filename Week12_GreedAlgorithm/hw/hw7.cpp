

/*
1) Main Heading
*********************************************************
* Name:  류희재
* Student ID : 20191587
* Program ID : HW7
* Description : 인접리스트로 Kruskal's MST 구현
* Algorithm : 함수들을 테스트 하는 것임으로 각각 함수 설명에서 알고리즘 개별적 설명 진행
* Variables:
클래스: Node - 노드 클래스
		Edge - 트리 클래스
		Graph - 그래프 클래스
************************************************************************/
#include <iostream> 
#include <algorithm>
#include <fstream>
#define MAX 6
using namespace std;


/*********************************************************************************************************
*class : Node
*Description : 노드 클래스
*fucntion 1) Node()  :노드 생성자
		  2) ~Node() : 노드 소멸자
*********************************************************************************************************/
class Node{
public:
	int vertex;
	Node *p;

	Node() {vertex = 0; p = this;}
	~Node(){}
};

/*********************************************************************************************************
*class : Edge
*Description : 그래프의 Edge에 관련된 클래스
*varialbe  : 1) start : 노드의 시작점
             2) end : 노드의 끝점
			 3) weight : 노드의 비용
			 4) isAdded : cycle 방지용
*fucntion  : 1) Edge() : Edge 생성자
			 2) ~Edge() : Edge 소멸자
			 3)	void showEdge(Edge *e, char alpabet[]) : Edge를 출력해준다.
			 4) void AddtoMST() : cycle을 하지 않도록 방문했음을 표시하는 함수
*********************************************************************************************************/
class Edge{
public:
	int start, end, weight;
	bool isAdded;

	Edge(){ start=0; end =0; weight=0; isAdded = false;}
	~Edge(){}
	void showEdge(Edge *e,char alpabet[]){
		
		for(int i = 0; i < 10; i++){
			cout << alpabet[e[i].start] << " " << e[i].weight << " " << alpabet[e[i].end] << " " << endl;
		}
		
	}
	
	void AddtoMST() {isAdded = true;}
};

/*********************************************************************************************************
*class : Graph
*Description : 
*varialbe  : 1) Node *graph : graph를 표현할 노드
             2) int V = 배열의 크기
*fucntion  : 1) Graph(int V) : graph를 만들기 위한 생성자
			 2) ~Graph() : graph를 소멸하기 위한 소멸자
			 3) int FindSet(int u) : start의 값과 맞을때까지 재귀적으로 다음 데이터를 찾는다.
			 4)	void Union(int u, int v) : 찾은 노드를 이전와 합쳐준다
*********************************************************************************************************/
class Graph{
public:
	Node *graph;
	int V;

	Graph(int V){
		this->V = V;
		graph = new Node[V+1];
		for(int i = 0; i <= V; i++){
			graph[i].vertex = i;
		}
	}
	int FindSet(int start);
	void Union(int start, int end);
	~Graph(){
	delete []graph;
	for(int i = 0; i <= V; i++){
		graph[i].p = NULL;
		}
	}
};

int Graph::FindSet(int start){
	int x = graph[start].p->vertex;
	if(x == start) return x;
	else return FindSet(x);
}

void Graph::Union(int start, int end){
	int x = FindSet(start);
	int y = FindSet(end);
	graph[x].p = &graph[y];
}

/*********************************************************************************************************
*function : bool SortBy(const Edge &e1, const Edge &e2)
*Description : weight의 크기를 비교해주는 함수
*********************************************************************************************************/
bool SortBy(const Edge &e1, const Edge &e2){
	return e1.weight < e2.weight ;
}

/*********************************************************************************************************
*function : main
*Description : 
*variable : 1)start, end, weight : 시작, 끝, 비용
			2) Graph k(MAX) : 그래프
			3) Edge *e : edge의 배열
			4) TotalCost : 최종최소비용
*algorithm : 
1) 입력을 숫자로 해줄것이기 때문에 그에 맞는 알파벳 배열 생성
2) 파일 입력을 통해서 Edge를 생성한다
3) input data를 showEdge함수를 활용하여 출력한다
4) alrogithm 헤더의 함수인 sort를 활용하여 edge를 weight에 기준으로 정렬한다
5) sorted data를 showEdge함수를 활용하여 출력한다
6) Edge 배열을 반복하면서 처음값과 끝값이 다르고 만약 방문하지 않은 노드이면 합쳐준다
7) 최종적은 mst를 출력해준다
8) 최종적인 최소비용을 출력해준다
*********************************************************************************************************/
int main(void){
	ifstream in("hw7.txt");
	int start, end, weight;
	char alpabet[MAX] = {'A','B','C','D','E','F'};
	cout << "<< HW7 MST by Kruskal's >>" << endl;


	Graph k(MAX);
	Edge *e = new Edge[10];
    
	cout << "1. Input Data : " << endl;
	for(int i = 0; i < 10; i++){
		in >> e[i].start >> e[i].end >> e[i].weight;
	}
	e->showEdge(e,alpabet);
	cout << endl;

	cout << "Sorted Data: " << endl;
	sort(e, e+10, SortBy); //
	e->showEdge(e,alpabet);
	cout << endl;
	

	for(int i = 0; i < 10; i++){
		start = e[i].start;
		end = e[i].end;
		if(k.FindSet(start)!= k.FindSet(end)){
			e[i].AddtoMST();
			k.Union(start,end);
		}
	}
	
	cout << "3. Kruskal's MST: " << endl;
	int TotalCost;
	int order = 1;
	for(int i = 0; i < 10; i++){
		if(e[i].isAdded){
			cout << "Edge" << order << ": ";
			cout << alpabet[e[i].start] << " " << e[i].weight << " " << alpabet[e[i].end] << endl;
			TotalCost += e[i].weight;
			order+=1;

		}
	}
	cout << endl;
	cout << "4. Final cost for Kruskal is a " << TotalCost << endl;

}
