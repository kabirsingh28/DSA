template <typename T>

class Queue{
    T *data;
    int nextIndex;
    int firstIndex;
    int capacity;
    int size;

    public:

    Queue(int totalsize){
        data = new T[totalsize]; //no need to write T* data, array was alreday initialized
        size=0;
        firstIndex=-1;
        nextIndex=0;
        capacity=totalsize;
        
    }

    int getsize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    void enqueue(T element){
      if(size==capacity){
        T * newData = new T[2*capacity];
        int j=0;
        for(int i=firstIndex; i<capacity; i++){
          newData[j] = data[i];
          j++;
      }
        for(int i=0; i<firstIndex; i++){
          newData[j] = data[i];
          j++;
        }
        firstIndex=0;
        nextIndex=capacity;
        capacity*=2;
        delete [] data;
        data=newData;
      }
      
      data[nextIndex]=element;
      nextIndex = (nextIndex + 1)%capacity; // jdon capacity nu reach krn di koshish kreka nextIndex osdi value reset hojegi to 0, nalle increment vi hundi rhegi nextIndex di value
      if(firstIndex==-1){
        firstIndex = 0;
      }
      size++;

    }

    T dequeue(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
       T firstelement = data[firstIndex];
       //first index should also move circularly
       firstIndex = (firstIndex + 1)%capacity;
       size--;
       return firstelement;

    }

    T front(){
        if(isEmpty()){
            cout<<"queue is empty";
            return 0;
        }
        return data[firstIndex];
    }
};