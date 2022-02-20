#include<bits/stdc++.h>
using namespace std;

// No STL
// Doubly linked list
class Data{
    public:
    int ele;
    Data* next;
    Data* prev;

    Data(int ele){
        this->ele = ele;
        next = prev = nullptr;
    }
};
Data* head;
class List{
    int size1=0;
    public:
    List(){
        
    }
    void push_front(int ele){
        Data* data1 = new Data(ele);
        if(size1 == 0){
            head = data1;
            size1++;
            return;
        }
       data1->next=head;
       head->prev=data1;
       head= data1;
        size1++;
    }
    int pop_front(){
        if(size1 == 0){
            return -1;
        }

        if(size1 == 1){
            head= nullptr;
            size1--;
            return 0;
        }
        head=head->next;
        head->prev=nullptr;
        size1--;
        return 0;
    }
    void push_back(int ele){
         Data* d = new Data(ele);
        if(size1 == 0){
            head= d;
            size1++;
            return;
        }
        Data* curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next = d;
        d->prev = curr;
        size1++;
    }
    int pop_back(){
         if(size1 == 0){
            return -1;
        }

        if(size1 == 1){
            head= nullptr;
            size1--;
            return 0;
        }
        Data* curr=head;
        while(curr->next->next!=nullptr){
            curr=curr->next;
        }
        curr->next=nullptr;
        size1--;
    }

    int peek_front(){
        return head->ele;
    }
    int peek_back(){
       Data* curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
        } 
        return curr->ele;
    }

    void display( Data*head){
         Data* temp = head;

        while(temp!=nullptr){
            cout<<temp->ele<<" ";
            temp = temp->next;
        }
    }

    int size(){
        return size1;
    }
    bool is_empty(){
        if(size1==0){
            return true;
        }
        else{
            return false;
        }
    }

    // Extra credit
    //idx starts at 1
    void insert_at(int ele, int pos){
        Data* data1 = new Data(ele);
        if(size1<pos){
            cout<<"not possible"<<endl;
        }
       else if(pos==1){
        data1->next=head;
        head->prev=data1;
        head=data1;
       size1++;
        return;
      }
      else{
      Data* curr=head;
      int i=1;
      
      while(curr->next!=NULL&&i!=pos-1){
          curr=curr->next;
          i++;
      }
      if(curr->next==NULL && i==pos-1){
         
          data1->next=curr->next;
       curr->next=data1;
       data1->prev=curr;
        size1++;
      }
      else{
      data1->next=curr->next;
      data1->prev=curr;
      curr->next->prev=data1;
      curr->next=data1;
       size1++;
      }
     
      
    }
        
    }
    int delete_from(int pos){
        Data* curr=head;
        if(size1==0){
            cout<<"no element";
        }
       else if(pos==1){
        Data* temp=head;
        head = head->next;
        head->prev=nullptr;
         size1--;
        return 0;
       }
       else{
       int i=1;
       while(i!=pos-1){
          curr=curr->next;
          i++;
      }
      if(curr->next->next==NULL){
          curr->next=NULL;
      }
      else{
      curr->next->next->prev=curr;
      curr->next=curr->next->next;
      }
       size1--;
}
      return 0;
    }
};

int main(){
    head=nullptr;
    List obj;
obj.push_back(1);
obj.push_back(2);
obj.insert_at(5,2);
obj.insert_at(6,3);
obj.insert_at(7,4);
obj.delete_from(1);
obj.display(head);

    return 0;
}