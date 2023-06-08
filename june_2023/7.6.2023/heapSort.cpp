#include<bits/stdc++.h>
using namespace std;

void inplaceHeapSort(int pq[],int n){
    //building heap from unsorted array
    for(int i=1; i<n; i++){
      int childIndex = i;
      int parentIndex = (childIndex - 1)/2;
      while(pq[parentIndex]>pq[childIndex] && childIndex!=0){
      swap(pq[childIndex], pq[parentIndex]);
      childIndex = parentIndex;
      parentIndex = (childIndex - 1)/2;
      }
    }

    //removing elements
      int size = n;
      while(size>1){
      swap(pq[0],pq[size-1]);
      size--;
    //    int parentIndex = 0;
    //   int childIndex1 = 2*parentIndex + 1;
    //   int childIndex2 = 2*parentIndex + 2;
    //   while((pq[parentIndex]>pq[childIndex1] || pq[parentIndex] >pq[childIndex2]) && childIndex1<size && childIndex2<size){
    //      if(pq[childIndex1]<pq[childIndex2]){
    //      swap(pq[parentIndex],pq[childIndex1]);
    //         parentIndex = childIndex1;
    //      }
    //      else{
    //      swap(pq[parentIndex],pq[childIndex2]);
    //         parentIndex = childIndex2;
    //      }
    //      childIndex1 = 2*parentIndex + 1;
    //      childIndex2 = 2*parentIndex + 2;

    //      if(childIndex1==size && pq[parentIndex]>pq[childIndex1]){
    //         swap(pq[parentIndex],pq[childIndex1]);
    //      }
         
      int parentIndex = 0;
      int leftChildIndex = 2*parentIndex + 1;
      int rightChildIndex = 2*parentIndex + 2;
      
      while(leftChildIndex<size){
         int minIndex = parentIndex;
         if(pq[minIndex]>pq[leftChildIndex]){
            minIndex = leftChildIndex;
         }
         if(rightChildIndex<size && pq[minIndex]>pq[rightChildIndex]){
            minIndex = rightChildIndex;
         }
         if(parentIndex==minIndex) break;
         swap(pq[minIndex],pq[parentIndex]);

         parentIndex = minIndex;
         leftChildIndex = 2*parentIndex + 1;
         rightChildIndex = 2*parentIndex + 2;
      }
      }
}


int main()
{  int input[] = {5,1,2,0,8,14,100,28};
   inplaceHeapSort(input,8);
   for(int i=0; i<8; i++){
    cout<<input[i]<<" ";
   }
    return 0;
}