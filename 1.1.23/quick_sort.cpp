#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int si, int ei){
  int count = 0;
    for(int i=si+1; i<=ei; i++){ // counting how many no. are less than the first element
         if(a[si]>=a[i]){
          count++;
         }
    }
    swap(a[si],a[si+count]);//placing the 1st element at its right place
    
    //now placing all the no. lesser or equal to reference element on left side and greter on right side
    int i=si, j=ei;
    while(i<(si+count)&&j>(si+count)){
      if(a[i]>a[si+count]&&a[j]<=a[si+count]){
        swap(a[i],a[j]);
        i++;
        j--;
      }
      else if(a[i]>a[si+count]&&a[j]>a[si+count]){
        j--;
      }
      else if(a[i]<=a[si+count]&&a[j]<a[si+count]){
        i++;
      }
    }
    return si+count;
}

void QS(int a[], int si, int ei){
    if(si>=ei) return; //checking if the string contains only 1 element or no element at all
    int c = partition(a,si,ei); //now by this function the first element is placed at its right position
                                //and elements less than that elemnt are placed towards its left and 
                                //greater on the right side
    QS(a,si,c-1);
    QS(a,c+1,ei);//now calling Q.S on 2 arrays independently 
}

int main()
{   
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    QS(a,0,n-1);
    for(int i=0; i<n; i++){
      cout<<a[i]<<" ";
    }
    return 0;
}