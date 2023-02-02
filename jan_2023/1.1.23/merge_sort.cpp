#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int mid, int si, int ei){
   int size1 = mid-si+1;  // calculating number of elements
   int size2 = ei-mid; // right - (mid +1) +1

   int *b = new int[size1];// initializing new arrays with reqiuerd sizes
   int *c = new int[size2];

   for(int i=0; i<size1; i++){ // storing it in a new array
     b[i] = a[si+i]; // si+1 cause part of array from si to ei is passed
   }

   for(int j=0; j<size2; j++){ // storing it in a new array
     c[j] = a[mid+1+j]; // mid+j+1 cause 2nd part is from mid +1 to ei
   }

   //now gonna store the mereged array in array 'a' itself
   int x=0,y=0,k=si;
   // k=si cause its the initial index of merged array
   // remeber array starts from si and ends at ei
   while(x<size1&&y<size2){
    if(b[x]>=c[y]){
       a[k]=c[y];
       k++;
       y++;
    }
    else{
        a[k]=b[x];
        k++;
        x++;
    }
   }

   if(x<size1){
    for(int i=x;i<size1;i++){
        a[k]=b[i];
        k++;
    }
   }
   if(y<size2){
    for(int i=y;i<size1;i++){
        a[k]=c[i];
        k++;
    }
   }
   
   delete [] b;
   delete [] c;


}

void merge_sort(int a[], int si, int ei){
    if(si>=ei) return;
    int mid = (si + ei)/2;
    merge_sort(a,si,mid);
    merge_sort(a,mid+1,ei);
    merge(a,mid,si,ei);
    
}

int main()
{   int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }    
    merge_sort(a,0,n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}