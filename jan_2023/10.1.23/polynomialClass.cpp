class polynomial{

    int * degCoeff;
    int capacity;

    public:

    //default constructor
    polynomial(int *degree, int *coeff, int size){
        capacity = 5;
        degCoeff = new int[5];
        if(capacity<size+1){
            int * new_degCoeff = new int[capacity*2];
            capacity*=2;
            delete [] degCoeff;
            degCoeff=new_degCoeff;            
        }
        
            for(int i=0;i<capacity;i++){
                degCoeff[i]=0;
            }
        int a=0;
        for(int i=0; i<=size+1; i++){
             if(i==degree[a]){
                degCoeff[i]=coeff[a];
                a++;
             }
        }



    }

    //setcoefficient
    void setCoefficient(int d, int c){
        if(d>capacity){
            int * new_degCoeff = new int[capacity*2];
            capacity*=2;
            for(int i=0;i<capacity;i++){
                new_degCoeff[i]=0;
            }
            for(int i=0;i<capacity;i++){
                new_degCoeff[i]=degCoeff[i];
            }
            delete [] degCoeff;
            degCoeff=new_degCoeff;

        }
        degCoeff[d]=c;
    }

    //copy constructor
    polynomial(polynomial const &p){
         this->capacity = p.capacity;
         //shallow copy
         //this->degCoeff = p.degCoeff;
         //deep copy
         for(int i=0; i<capacity; i++){
            this->degCoeff[i]=p.degCoeff[i];
         }
         
    }

    //copy assignment operator
    void operator=(polynomial const &p){
        this->capacity = p.capacity;
        for(int i=0; i<capacity; i++){
            this->degCoeff[i]=p.degCoeff[i];
         }
    }

    //print
    void print() const{
        for(int i=0; i<capacity; i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    

    //+
    polynomial operator+(polynomial const &p){
          polynomial pnew=p;
          for(int i=0; i<max(pnew.capacity,this->capacity)+1; i++){
            pnew.degCoeff[i]+= this->degCoeff[i];
          }

          return pnew;
          
    }

    //-

    //*
     
};