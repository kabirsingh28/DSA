class student{
    public:
     int rollno;  
    private:
     int age;
    public:
     void display(){
        cout<<age<<" "<<rollno;
     } 
     int getage(){
        return age;
     }
     int setage(int t){
        age=t;

     }
};