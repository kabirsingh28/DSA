class student{
    private:
    int age;
    int rollno;
    public:
    void show(){
        cout<<age<<" "<<rollno<<endl;
    }
    student(){
        cout<<"constructor 1 is called!!"<<endl;
    }
    student(int rollno){
         cout<<"constructor 2 is called!!"<<endl;
        this->rollno=rollno;
    }
    student(int a,int b){
        cout<<"constructor 3 is called!!"<<endl;
        age=a;
        rollno=b;
    }

    ~student(){
        cout<<"Destructor activated!"<<endl;
    }
};