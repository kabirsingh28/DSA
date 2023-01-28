template <typename T>

class Stack{
    private:
    T *data; //array  T * data = new T[...]
    int nextIndex;
    int capacity;

    public:
    //constructor
    Stack(){
        data = new T[5];
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
          T * newdata = new T[2*capacity];
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
    T pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //to read top element
    T top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1]; //nextIndex-- nhi krange cause it'll update nextIndex
    }

};