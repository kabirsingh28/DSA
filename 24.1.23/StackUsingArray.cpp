#include <climits>
class Stack{
    private:
    int *data; //array  int * data = new int[...]
    int nextIndex;
    int capacity;

    public:
    //constructor
    Stack(int TotalSize){
        data = new int[TotalSize];
        nextIndex = 0;
        capacity = TotalSize;
    }
    //size of stack
    int size(){
        return nextIndex;
    }

    //is stack empty
    bool isEmpty(){
        return nextIndex==0;
    }

    //to insert element in stack
    void push(int element){
        if(nextIndex==capacity){
          cout<<"stack is full"<<endl;
          return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    //delete element
    int pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //to read top element
    int top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1]; //nextIndex-- nhi krange cause it'll update nextIndex
    }

};