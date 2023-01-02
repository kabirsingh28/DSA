#include<bits/stdc++.h>
using namespace std;

string table(int a){
    switch (a)
    {
    case 2: 
          return "abc";
    case 3: 
          return "def";
    case 4: 
          return "ghi";
    case 5: 
          return "jkl";
    case 6: 
          return "mno";
    case 7: 
          return "pqrs";
    case 8: 
          return "tuv";
    case 9: 
          return "wxyz";
    
    }
}

int keypad(int n, string output[]){
    if(n==0){
        output[0]="";// base case agr n=0 then output[0] vich sirf "" stroe hovega
        return 1;    // te ess naal bakki characthers append honge
        
    }

    int count = keypad(n/10,output); // example n=234 te hunn me 234/10=23 te recursion call kitte 
    // now appending charachter corssponding to last digit
    string s = table(n%10); //eg "abc"
    int k=0;
    string output1[1000];
    for(int j=0; j<s.size(); j++){
    for(int i=0; i<count; i++){
        output1[k] = output[i] + s[j];
        k++;
    }
    for(int i=0; i<count*(s.size()); i++){
       output[i] = output1[k];
    }
}
    return (s.size())*count;
}

int main()
{   int n;
    cin>>n;
    string * output = new string[1000];
    int count = keypad(n, output);
    for(int i=0; i<count; i++){
     cout<<output[i]<<endl;
    }
    return 0;
}