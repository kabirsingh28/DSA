#include <climits>
class Stack{
    private:
    int *data; //array  int * data = new int[...]
    int nextIndex;
    int capacity;

    public:
    //constructor
    Stack(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
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
          int * newdata = new int[2*capacity];
          for(int i=0; i<capacity; i++){
            newdata[i]=data[i];
          }
          capacity*=2;
          delete [] data;
          data = newdata;
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