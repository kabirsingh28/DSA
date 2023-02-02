class student{
    public:
    int age;
    const int rollno;
    int &x;
    
    //constructor
    student (int r, int age) : rollno(r), age(age), x(this->age){ //initialization list, i.e function vich jaan to pehla vi rollno=r;
    }
    void print(){
        cout<<age<<" "<<rollno<<" "<<x<<endl;
    }
};