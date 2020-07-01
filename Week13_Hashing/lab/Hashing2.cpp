#include <iostream>
using namespace std;
const int HASH_SIZE = 7;

struct Node{
    int key;
    int data;
    Node* link;
public:
    Node();
    Node(int data) {
        this -> key = 0;
        this -> data = data;
        this -> link = 0;
    }
    Node(int key, int data){
            this -> data = data;
            this -> key = key;
            this -> link = 0;
        }
};

class SLL
{
    private:
        Node *head;
        friend class Hash;
    public:
        SLL() { head = 0; }
        ~SLL()
        {
            Node *p;
            while(head != 0)
            {
                p = head;
                head = head -> link;
                delete p;
            }
        }
        void insert_node(int data, int key);
        void delete_node(int data);
        bool isEmpty() {return head == 0; }
        bool search(int data);
        void print_node();
};
void SLL::insert_node(int data, int key){
    Node *temp = new Node(key, data);
    if (head == 0) head = temp;
    else{
    Node *p = head;
    while(p -> link != 0) p = p -> link;
    p -> link = temp;
    }    
}
void SLL::delete_node(int data){
    Node *p, *q;

    if (head -> data == data){
        p = head;
        head = head -> link;
        delete p;
    }
    if(true){
        p = head;
        while(p != 0 && p -> data != data)
        {
            q = p;
            p = p -> link;
        }
        if (p != 0)
        {
            q -> link = p -> link;
            delete p;
        }
        else cout << data << " is not in Hash.\n";
    }
}
void SLL::print_node(){
    Node *p;
    if (!isEmpty()){
    p = head;
    while(p -> link != 0){
        cout << p -> data << " -> ";
        p = p -> link;
    }
    cout << p -> data;
    }
}
bool SLL::search(int data){
    Node *p;
    if (head != 0){
        p = head;
        while(p != 0 && p -> data != data) p = p -> link;
        if (p) return true;
        else return false;
    }
}



class Hash{
private:
    SLL* Htable;
    int key_num;
public:
    Hash() {
    Htable = new SLL[HASH_SIZE];
    key_num = 0;
}
    int hash_function(int data){
    return data % 7;
    }
    bool isEmpty(){
        return key_num == 0;
    }
    void insertKey(int data);
    void DeleteKey(int data);
    bool findKey(int data);
    void print();
};

void Hash::insertKey(int data){
    int key = hash_function(data);
    (Htable + key) -> insert_node(data, key);
    key_num++;
}
void Hash::DeleteKey(int data){
    if (findKey(data) == true){
        int key = hash_function(data);
        (Htable + key) -> delete_node(data);
        key_num--;
    }
    else cout << data << " is not found\n";
}
bool Hash::findKey(int data){
    int key = hash_function(data);
    if ((Htable + key) -> isEmpty()) return false;
    else {
        if ((Htable + key) -> search(data)) return true;
        else return false;
    }
}
void Hash::print() {
    cout << "-------------------------" << endl;
    for (int i = 0 ; i < HASH_SIZE ; i++){
        cout << "Htable[" << i << "] : ";
        (Htable + i) -> print_node();
        cout << endl;
    }
    cout << "-------------------------" << endl;
}



int main()
{
    char c;
    int n;
    Hash hash;
    
    while(true){
        cout << "Enter command. (i, d, f, q)" << endl;
        cin >> c;
        if(c == 'i'){
            cout << "Enter key to insert    : "; 
            cin >> n;
            hash.insertKey(n);
        }
        else if(c == 'f'){
            cout << "Enter key to find   : ";
            cin >> n;
            if(hash.findKey(n) == true) cout << "key found" << endl;
            else cout << "key not found" << endl;
        }
        else if(c == 'd'){
            cout << "Enter key to delete    : ";
            cin >> n;
            hash.DeleteKey(n);
        }
        else if(c == 'q') break;
        else cout << "잘못된 명령어 입니다. 다시 입력하세요." << endl;
        hash.print();
    }
    return 0;
}