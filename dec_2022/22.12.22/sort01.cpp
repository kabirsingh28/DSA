#include<bits/stdc++.h>
using namespace std;

void sortZeroesAndOne(int input[], int size)
{
    for(int i=0, j=size-1; i<j; ){
        if(input[i]==1 && input[j]==0){
            input[i]=0;
            input[j]=1;
            i++;
            j--;
            
        }
        else if(input[i]==0 && input[j]==1){
            i++;
            j--;
            
        }
        else if(input[i]==1 && input[j]==1){
            j--;
            
        }
         else if(input[i]==0 && input[j]==0){
            i++;
        
         }   
    }
    for(int i=0; i<size; i++){
        cout<<input[i]<<" ";
    } 
}

int main(){
   int size;
   cin >> size;
   int input[size];
   for(int i=0; i<size; i++){
    cin>>input[i];
   }
   sortZeroesAndOne(input,size);
}