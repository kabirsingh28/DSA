class complexnumber{
    private:
      int real;
      int imaginary;

    public:

      complexnumber(int real, int imaginary){
        this->real = real;
        this->imaginary = imaginary;
      }  

      void print(){
        cout<<real<<" + i"<<imaginary<<endl;
      }

      void plus(complexnumber c){
        real = real +c.real;
        imaginary = imaginary +c.imaginary;
      }

      void multiply(complexnumber c){
        int t = real;
        int s = imaginary;
        real = real*c.real - imaginary*c.imaginary;
        imaginary = t*c.imaginary + s*c.real;
      }
};