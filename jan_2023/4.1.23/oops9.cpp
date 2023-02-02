class student{
    private:
    int age;
    public:
    void show(){
        cout<<"age: "<<age;
    }
    student(int age){
        cout<<"constructor activated"<<endl;
        cout<<this<<endl; //tis will hold the memory address of the current object, hence its a pointer
        this->age=age; //this->age is interpreted as s1.age (say if current object is s1)
    }

};