class student{
    public:
    int rollno;
    private:
    int age;
    public:
    void dispaly(){
        cout<<rollno<<" "<<age<<endl;
    }
    //called once in the lifetime of the every object i.e when its created
     student(){ 
         cout<<"constructor called"<<endl;
     }

    student(int r){
        cout<<"parameterized constructor called"<<endl;
        rollno=r;
    }

    student(int x, int y){
        cout<<"parameterized constructor 2 called"<<endl;
        rollno=x;
        age=y;
    }
};