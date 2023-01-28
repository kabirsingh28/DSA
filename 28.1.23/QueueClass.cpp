#include <climits>

class Queue{
    int *data;
    int nextIndex;
    int size;

    public:

    Queue(){
        int * data = new int[5];
        nextIndex=0;
        size=5;
    }

    int getsize(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex==0;
    }

    void enqueue(int element){
      if(nextIndex==size){
        cout<<"queue is full";
      }
      data[nextIndex]=element;
      nextIndex++;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"queue is empty";
            return INT_MIN;
        }
        int firstElement = data[0];
        for(int i=0; i<nextIndex-1; i++){
           data[i]=data[i+1];
        }
        nextIndex--;
        return firstElement;

    }

    int first(){
        if(isEmpty()){
            cout<<"queue is empty";
            return INT_MIN;
        }
        return data[0];
    }
};