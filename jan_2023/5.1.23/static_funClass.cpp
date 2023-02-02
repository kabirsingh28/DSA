class student{
    static int TotalStudents; // the data member which is common to all the objects
    public:
    int age;
    int rollno;
   

    student(){
      
       TotalStudents++;
    }

    static int getTS(){
       return TotalStudents;
    }

    void print() const{
        cout<<age<<" "<<rollno<<endl;
    }
};

int student::TotalStudents = 0;