#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node{
    public:
    T data;
    Node<T> * next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{
    Node<T> * head;
    int size;
    
    public:
    Stack(){
        head=NULL;
        size=0;
    }

    int getsize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    void push(T element){
        Node<T> * newNode = new Node<T>(element); //Node * newNode = new Node(data);
        // if(head==NULL){
        //     head = newNode;
        // }
        // else{
        //     Node<T> * temp = head;
        //     head = newNode;
        //     head->next = temp;
        // }
        //beter way
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<" ";
            return 0;
        }
        T ans = head->data;
        Node<T> * temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
        
    }

    T top(){
        if(isEmpty()){
            cout<<"stack is empty"<<" ";
            return 0;
        }
        return head->data;
    }
};

int main()
{   
    Stack<int> s1;
    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);
    s1.push(105);

    cout<<s1.getsize()<<endl;
    cout<<s1.isEmpty()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.getsize()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.isEmpty()<<endl;
    return 0;
}