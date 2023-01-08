class student{
    private:
    int age;
        
    public:  

    char * name;// always create your own copy constructor if one of the data member is array

    student(int age, char * name){ //address name is catched in *name i.e a pointer
        this->age = age;
        this->name=name; //now this name contains the address of name
    }

    student(student &s){ // called by student s2(s1) => s2.student(s1)
        this->age = s.age;
        this->name = new char[strlen(s.name)+1]; //new array with different address
        strcpy(this->name,s.name);
    }

     void print() {
        cout<<name<<" "<<age<<endl;
    }
};