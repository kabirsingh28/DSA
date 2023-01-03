#include<bits/stdc++.h>
using namespace std;

string table(int k){
    switch (k)
    {
    case 2:
        return "abc";
        break;
    case 3:
        return "def";
        break;
    case 4:
        return "ghi";
        break;
    case 5:
        return "jkl";
        break;
    case 6:
        return "mno";
        break;
    case 7:
        return "pqrs";
        break;
    case 8:
        return "tuv";
        break;
    case 9:
        return "wxyz";
        break;
    }
}

int keypad(int n, string output[]){
    if(n==0){
        output[0]='\0';
        return 1;
    }
    int size = keypad(n/10,output);
    string a = table(n%10);
    int t = a.size(),k=0;
    string * temp = new string[1000];
    for(int i=0; i<t; i++){
        for(int j=0; j<size; j++){
            temp[k]=output[j]+a[i];
            k++;
    }
}
     for(int i=0; i<t*size; i++){
        output[i]=temp[i];
     }
    return t*size;

}

int main()
{   int n;
    cin>>n;
    string * output = new string[1000];
    int size = keypad(n, output);
    for(int i=0; i<size; i++){
        cout<<output[i]<<endl;
    }

    return 0;
}