#include <iostream>
using namespace std;

void updateValue(int *p){
    *p = 160;
}

int main(){
    char ch = 'A';
    updateValue((int*)&ch);
    cout << ch;
    cout<<(610%255);
}