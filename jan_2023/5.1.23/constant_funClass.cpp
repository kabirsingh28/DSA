class fraction{
     private:
     int numinator;
     int denominator;     
     public:
     void setnum(int numinator){
          this->numinator = numinator;
     }
     void setdino(int denominator){
          this->denominator = denominator;
     }
     int getnum() const{
          return numinator;
     }
     int getdeno() const{
          return denominator;
     }

     fraction(int numinator, int denominator){
        this->numinator = numinator;
        this->denominator = denominator;
     }

     void print() const{
        cout<<numinator<<"/"<<denominator<<endl;
     }
     void add(fraction f2){
        int lcm = (this->denominator)*f2.denominator;
        int x= lcm/(this->denominator);
        int y= lcm/(f2.denominator);
        int num = x*(this->numinator) + y*(f2.numinator);
        this->numinator = num;
        this->denominator = lcm;
        simplify();
     }
     void multiply(fraction const &f2){
        numinator = numinator*(f2.numinator);
        denominator = denominator*(f2.denominator);
        simplify();
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