#include <iostream>

//stack STL을 사용하기 위해서는 <stack> 헤더파일을 포함해야 됨.
#include <stack>
using namespace std;

int main(void){
    
    // 스택선언 : stack<데이터 타입> 이름;
    stack<int> st;
    stack<int> st2;
    
    // 스택 데이터 추가 : stack.push(element);
    st.push(1);
    st.push(2);
    st.push(3);
    
    st2.push(10);
    st2.push(20);
    st2.push(30);
    
    // 스택 데이터 삭제 : stack.pop();
    st.pop();
    
    // 스택 top 데이터 반환 : stack.top();
    st.top();
    
    // 스택 사이즈 반환 : stack.size();
    st.size();
    
    // 스택 비어있는지 확인 : stack.empty()
    st.empty();
    
    // 스택 swap : swap(stack1,stack2);
    swap(st,st2);
    
    return 0;
}
