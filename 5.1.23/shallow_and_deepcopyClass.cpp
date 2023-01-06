class student{
    int age;
    char * name; //vese heep vich bnan lyi we have to char * name = new char[size], but size is not known
                 //so we just declared it
    public:
    student(int age, char * name){
        this->age = age;
        // this->name = name; //shallow coping i.e not all the array is being copied but only the address of
        //                    //0th index
        this->name = new char[strlen(name)+1]; //deep coping;
        strcpy(this->name,name);
        
    }
 
    void show(){
        cout<<age<<" "<<name<<endl;
    }
};