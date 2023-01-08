class fraction{
     private:
     int numinator;
     int denominator;
     public:

     fraction(int numinator, int denominator){
        this->numinator = numinator;
        this->denominator = denominator;
     }

     void print() const{
        cout<<numinator<<"/"<<denominator<<endl;
     }

     fraction operator+(fraction const &f2) const{
        int lcm = (this->denominator)*f2.denominator;
        int x= lcm/(this->denominator);
        int y= lcm/(f2.denominator);
        int num = x*(this->numinator) + y*(f2.numinator);
        fraction fnew(num,lcm);
        fnew.simplify();
        return fnew;
        
     }

     fraction operator*(fraction const &f2) const{
        int num= numinator*(f2.numinator);
        int deno = denominator*(f2.denominator);
        fraction fnew(num,deno);//fnew da scope bs iss function tk aa
                                             //so it can be declared agian in some other function
        fnew.simplify();
        return fnew;
     }
     
     bool operator==(fraction const &f2) const{
        return (this->numinator==f2.numinator&&f2.denominator==this->denominator);
     }
      
    fraction& operator++(){
        numinator=numinator+denominator;
        simplify();
        return *this;
    }

    fraction operator++(int){
        fraction fnew(numinator,denominator);
        numinator = numinator + denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }

    fraction& operator+=(fraction const &f){
        int lcm = (this->denominator)*f.denominator;
        int x= lcm/(this->denominator);
        int y= lcm/(f.denominator);
        int num = x*(this->numinator) + y*(f.numinator);
        numinator=num;
        denominator=lcm;
        simplify();
        return *this;
    }

     void simplify(){
        int gcd=1;
        int j = min(this->numinator,this->denominator);
        for(int i=1;i<=j;i++){
            if(this->numinator%i==0 && this->denominator%i==0){
                gcd=i;
            }
        }
        numinator/=gcd;
        denominator/=gcd;
     }
};