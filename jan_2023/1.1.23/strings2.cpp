#include<bits/stdc++.h>
using namespace std;

int subs(string input, string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    int count = subs(input.substr(1),output);
    for(int i=0;i<count;i++){
        output[count+i]=input[0]+output[i];
            }
        return 2*count;
}

int main()
{   string input;
    cin >> input;
    string * output = new string[1000];
    int count = subs(input, output);//mtlb this is the input w.r.t that output array fill krdo
    for(int i = 0; i < count; i++){
        cout<<output[i]<<endl;
    }

    return 0;
}