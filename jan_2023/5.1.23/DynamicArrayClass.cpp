class dynamic{
    int * data;
    int index;
    int size;

    public:
    
    dynamic(){
        data = new int[7];
        index = 0;
        size=7;
    }


    dynamic(dynamic const &d){ //have to deep copy d1 into d2=this
      this->size = d.size;
      this->index = d.index;
      this->data = new int[d.size];
      for(int i=0; i<d.index; i++){
        this->data[i]=d.data[i];
      }
    }
    
    void operator=(dynamic const &d){
        this->size = d.size;
      this->index = d.index;
      this->data = new int[d.size];
      for(int i=0; i<d.index; i++){
        this->data[i]=d.data[i];
      }
    }

    void add(int element){
        if(index==size){
            int * new_data = new int[2*size];
            for(int i=0; i<size; i++){
                new_data[i]=data[i];
            }
            delete [] data;
            data=new_data;
            size*=2;
        }
        data[index]=element;
        index++;
    }

    void add(int i, int element){
        if(i<index){
            data[i]=element;
        }
        else if(i==index){
            add(element);
        }
        else{
            return;
        }
    }

    int get(int i){
        if(i<index){
            return data[i];
        }
        else{
            return -1;
        }
    }

    void print(){
        for(int i=0; i<index; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }





};