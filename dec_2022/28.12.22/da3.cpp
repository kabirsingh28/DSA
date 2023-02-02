#include <iostream>
using namespace std;

#define square(x) (x*x)

int main(){
    int x = 36 / square(6);
    cout << x;

    return 0;
}