#include<bits/stdc++.h>
using namespace std;

string unique_char(string str){
      string output = "";
      unordered_map<char,bool> seen;

      for(int i=0; i<str.size(); i++){
            if(seen.count(str[i])==0){
                seen[str[i]]++;
                output += str[i];
            }
      }

      return output;
}

int longest_seq(int* a,int n){
    unordered_map<int,bool> seen;
    vector<int> output;
    for(int i=0; i<n; i++){
        seen[a[i]]=true;
    }
    
    int maxLength = 0;
   
    for(int i=0; i<n; i++){
        int start = a[i];
        int len = 0;
        int begin = start;
        int end = start;
        if(seen[start]==true){
            len = 1;
            seen[start] = false;
         while(seen.count(start-1)>0){
            seen[start-1] = false;
            len++;
            begin = --start;
         }
         
         start = a[i];
         while(seen.count(start+1)>0){
            seen[start+1] = false;
            len++;
            end = ++start;
         }
         

         if(maxLength<=len){
            maxLength = len;
           cout<<begin<<endl;
           cout<<end<<endl;
         }

    }
 }

    return maxLength;
    
}

int pairWDK(int* a,int n,int d){
    int count = 0;
    unordered_map<int,int> seen;
    for(int i=0; i<n; i++){
        seen[a[i]]++;
    }
    if(d==0){
    for(int i=0; i<n; i++){
        if(seen[a[i]]>1){
            int t = seen[a[i]];
            count+= (t*(t-1))/2;
            seen.erase(a[i]);
        }
    }
    }
    else{
    for(int i=0; i<n; i++){
    if(seen.count(a[i]-d)){
        count+= seen[a[i]]*seen[a[i]-d];
    }
    if(seen.count(a[i]+d)){
        count+= seen[a[i]]*seen[a[i]+d];
    }
    seen.erase(a[i]);
   }
    }
   return count;
}


int main()
{   
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int d;
    cin>>d;
    cout<<pairWDK(a,n,d);




    
    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0; i<n; i++){
    //     cin>>a[i];
    // }
    
    // cout<<longest_seq(a,n);

    
    // string str;
    // cin>>str;
    // cout<<unique_char(str);
    return 0;
}