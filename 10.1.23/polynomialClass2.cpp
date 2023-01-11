class polynomial{
    int * degCoeff;
    int capacity;

    public:

    //default constructor
    polynomial(){
        capacity = 5;
        degCoeff = new int[5];
        for(int i=0; i<5; i++){
            degCoeff[i]=0;
        }
    }

    //parameterized constructor
    polynomial(int size){
        capacity = size;
        degCoeff = new int[capacity];
        for(int i=0; i<capacity; i++){
            degCoeff[i]=0;
    }
    }

    //copy constructor
    polynomial(polynomial const &p){
        this->capacity = p.capacity;
        this->degCoeff = new int[p.capacity];
        for(int i=0; i<=capacity;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
    }

    //copy assignment operator
      void operator=(polynomial const &p){
        this->capacity = p.capacity;
        this->degCoeff = new int[p.capacity];
        for(int i=0; i<=capacity;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
    }

    //print
    void print() const{
        for(int i=0;i<capacity;i++){
            if(degCoeff[i]!=0){
            cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }

    //set coefficient
    void setCoeff(int d, int c){
        if(d>capacity-1){
            int * temp = new int[d+1];
            for(int i=0;i<d+1;i++){
             temp[i]=0;
            }
            for(int i=0;i<capacity;i++){
             temp[i]=degCoeff[i];
            }
            for(int i=0;i<d+1;i++){
             cout<<temp[i]<<"x"<<i<<" ";
            }
            delete [] degCoeff;
            degCoeff = temp;
            capacity=d+1;
        }
        degCoeff[d]=c;

    } 

    //+
    polynomial operator+(polynomial &p){
        polynomial a(max(this->capacity,p.capacity));
        if(this->capacity>=p.capacity){
          for(int i=0; i<p.capacity; i++){
            a.degCoeff[i]=this->degCoeff[i]+p.degCoeff[i];
          }
          for(int i=p.capacity; i<this->capacity; i++){
            a.degCoeff[i]=this->degCoeff[i];
          }
        }
        else{
            for(int i=0; i<this->capacity; i++){
            a.degCoeff[i]=this->degCoeff[i]+p.degCoeff[i];
          }
          for(int i=this->capacity; i<p.capacity; i++){
            a.degCoeff[i]=p.degCoeff[i];
          }

        }

        return a;

    }

    //-
    polynomial operator-(polynomial &p){
        polynomial a(max(this->capacity,p.capacity));
        if(this->capacity>=p.capacity){
          for(int i=0; i<p.capacity; i++){
            a.degCoeff[i]=this->degCoeff[i]-p.degCoeff[i];
          }
          for(int i=p.capacity; i<this->capacity; i++){
            a.degCoeff[i]=this->degCoeff[i];
          }
        }
        else{
            for(int i=0; i<this->capacity; i++){
            a.degCoeff[i]=this->degCoeff[i]-p.degCoeff[i];
          }
          for(int i=this->capacity; i<p.capacity; i++){
            a.degCoeff[i]=-p.degCoeff[i];
          }

        }

        return a;


    }

    //*
    polynomial operator*(polynomial &p){
        polynomial b(this->capacity+p.capacity);
        for(int i=0; i<this->capacity; i++){
            for(int j=0; j<p.capacity; j++){
                if(this->degCoeff[i]*p.degCoeff[j]!=0){
                    b.degCoeff[i+j]+=this->degCoeff[i]*p.degCoeff[j];

                }
            }
        }
        return b;
    }
};
