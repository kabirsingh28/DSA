#include<bits/stdc++.h>
using namespace std;
#include "NodeClass.cpp"

class Pair{
    public:
    node * head;
    node * tail;
};

node* take_input(){
    int data;
    cin>>data;
    node * head = NULL;
    node * tail = NULL;
    while(data!=-1){
        node * newNode = new node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next = newNode;
            tail=tail->next;
        }
        cin>>data;

    }
    return head;
}

void print(node * head){
    node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int return_index(int x, node * head){
    node * temp = head;
    int count = 0;
    while(temp->data!=x){
        temp=temp->next;
        if(temp==NULL){
            return -1;
        }
        count++;
    }
    
        return count;
}

node* even_odd(node * head){
    node * temp = head;
    node * p1h = NULL;
    node * p2h = NULL;
    node * p1t = NULL;
    node * p2t = NULL;
    int flag_odd=0;
    int flag_even=0;
    while(temp!=NULL){
        if(temp->data%2==0){
            flag_even++;
            if(p2h==NULL){
                p2h=temp;
                p2t=temp;
                
            }
            else{
                p2t->next=temp;
                p2t=temp;
                
            }
        }
        else{
            flag_odd++;
            if(p1h==NULL){
                p1h=temp;
                p1t=temp;
                
            }
            else{
                p1t->next=temp;
                p1t=temp;
                
            }
        }
        temp=temp->next;
    }
    if(flag_odd==0){
        return p2h;
    }
    else if(flag_even==0){
        return p1h;
    }
    p1t->next=NULL;
    p2t->next=NULL;
    if(head->data%2==0){
        p2t->next=p1h;
        return p2h;
    }
    else{
        p1t->next=p2h;
        return p1h;
    }
    
}

node* delete_MN(int n, int m, node * head){
    node * temp = head;
    if(n==0){
        return NULL;
    }
    while(1){
        int a=n-1,b=m+1;
        while(a>0){
            temp=temp->next;
            if(temp==NULL) return head;
            a--;
        }
        node * p = temp->next;
        while(b--){
            temp->next = p;
            if(p==NULL) return head;
            p=p->next;
            delete temp->next;
        }
        temp=temp->next;
    }
}

node* swap_ij(int i, int j, node * head){
    node * temp = head;
    int count = 0;
    if(i==0 && j==1){
         node * c1 = head;
         node * c2 = head->next;
         c1->next = c2->next;
         c2->next = c1;
         return c2;
    }
    if(i==0){
        node * c1 = head;
        while(count!=j-1){
         temp=temp->next;
         count++;
        }
        node * p2 = temp, * c2 = temp->next;
        node * t = c2->next;
        c2->next=c1->next;
        c1->next=t;
        p2->next=c1;
        return c2;

    }
    while(count!=i-1){
        temp=temp->next;
        count++;
    }
    node * p1 = temp, * c1 = temp->next;
    while(count!=j-1){
        temp=temp->next;
        count++;
    }
    node * p2 = temp, * c2 = temp->next;
    p1->next=c2;
    p2->next=c1;
    node * t = c2->next;
    c2->next=c1->next;
    c1->next=t; 

    return head;
}

Pair reversell_better(node * head){
    if(!head || !head->next){//if only 1 or no element is present
       Pair ans;
       ans.head=head;
       ans.tail=head;
       return ans;

    }

    Pair smallans = reversell_better(head->next); //head and tail of samll reversed ll gets saved in smallans
    smallans.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallans.head;
    ans.tail=head;
    return ans;
}

node* k_reverse(int k, node * head){
    node * temp = head;
    node * h1 = head;
    node * t1 = head;
    int count = 0;
    if(k==0){
        return head;
    }
    if(temp==NULL){
        return NULL;
    }
    while(count!=k-1&&temp->next!=NULL){
       temp=temp->next;
       count++;
    }
    t1=temp;
    node * h2 = t1->next;
    t1->next = NULL;

    Pair smallans = reversell_better(h1);
    h1 = smallans.head;
    t1 = smallans.tail;

    t1->next=k_reverse(k,h2);
    return h1;

}

int len(node * head){
    node * temp = head;
    int count=1;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

node* b_sort(node * head){
   node * temp = head;
   int i = 0;
   for(int j=0; j<len(head);j++){
   while(temp->next!=NULL){
   if(temp->data>temp->next->data){
     temp=temp->next;
     head = swap_ij(i,i+1,head);
   }
   temp=temp->next;
   i++;
   }
   temp = head;
   i=0;
}
return head;
}

int main()
{   node * head = take_input();
    // int x;
    // cin>>x;
    // cout<<return_index(x,head);
    //head = even_odd(head);
    // int n,m;
    // cin>>n>>m;
    //head = delete_MN(n,m,head);
    //head = swap_ij(0,1,head);
    // int k;
    // cin>>k;
    // head = k_reverse(k,head);
    head = b_sort(head);
    
    print(head);
    return 0;
}