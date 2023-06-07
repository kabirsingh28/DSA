#include<bits/stdc++.h>

//pirority queues are visualized as CBT but stored as vector
class priorityQueue{
     vector<int> pq;

     public:

     priorityQueue(){

     }
     
     int removeMin(){
      if(isEmpty()) return -1;
      int ans = pq[0];
      pq[0] = pq[pq.size()-1];
      pq.pop_back();
      int parentIndex = 0;
      int leftChildIndex = 2*parentIndex + 1;
      int rightChildIndex = 2*parentIndex + 2;
      
      while(leftChildIndex<pq.size()){
         int minIndex = parentIndex;
         if(pq[minIndex]>pq[leftChildIndex]){
            minIndex = leftChildIndex;
         }
         if(rightChildIndex<pq.size() && pq[minIndex]>pq[rightChildIndex]){
            minIndex = rightChildIndex;
         }
         if(parentIndex==minIndex) break;
         int temp = pq[minIndex];
         pq[minIndex] = pq[parentIndex];
         pq[parentIndex] = temp;

         parentIndex = minIndex;
         leftChildIndex = 2*parentIndex + 1;
         rightChildIndex = 2*parentIndex + 2;
      }


      // now we have to satisfy heap order property
      // int parentIndex = 0;
      // int childIndex1 = 2*parentIndex + 1;
      // int childIndex2 = 2*parentIndex + 2;
      // while((pq[parentIndex]>pq[childIndex1] || pq[parentIndex] >pq[childIndex2]) && (childIndex1 <= pq.size()-1 && childIndex2 <= pq.size()-1)){
      //    if(pq[childIndex1]<pq[childIndex2]){
      //    swap(pq[parentIndex],pq[childIndex1]);
      //       parentIndex = childIndex1;
      //    }
      //    else{
      //    swap(pq[parentIndex],pq[childIndex2]);
      //       parentIndex = childIndex2;
      //    }
      //    childIndex1 = 2*parentIndex + 1;
      //    childIndex2 = 2*parentIndex + 2;
         
      // }

      return ans;
     }


     void insert(int element){
        pq.push_back(element); 
      // doing so CBT property is satisfied
      //now we need to put the element at the correct position
      //for that we need to compare the newelement with it's parent element
      //if newelement>parent -> swap
      int childIndex = pq.size() - 1;
      int parentIndex = (childIndex - 1)/2;
      while(pq[parentIndex]>pq[childIndex] && childIndex!=0){
      swap(pq[childIndex], pq[parentIndex]);
      childIndex = parentIndex;
      parentIndex = (childIndex - 1)/2;
      }
     }

     bool isEmpty(){
        return pq.size() == 0;
     }

     int getSize(){
        return pq.size();
     }

     int getMin(){
        if(isEmpty()) return -1; //empty priority queue
        else return pq[0]; 
     }
};