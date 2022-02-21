#include<bits/stdc++.h>
using namespace std;
class Dequeue{
    list<int>v;
    int size1=0;
    public:

    void push_front(int ele){
     
      //cout<<v.size()<<endl;
      //int k=v.size();
     //  for(int i=k-1;i>=0;i--){
          // cout<<"y"<<v[i]<<endl;
          // v.insert(v.begin()+i+1,v[i]);
          // remove(v.begin(),v.end(),v[i]);
       //}
       
     // v[0]=ele;
      
      //cout<<v.size()<<"j";
       v.push_front(ele);
        
      size1++;
      
    }
    void pop_front(){
        v.pop_front();
    size1--;
    }
    void push_back(int ele){
        v.push_back(ele);
        size1++;
    }
    void pop_back(){
        v.pop_back();
        size1--;
    }

    int peek_front(){
        return v.front();
    }
    int peek_back(){
        return v.back();
    }

    void display(){
        list<int>::iterator it;
        for(it=v.begin();it!=v.end();it++){
            cout<<*it<<" ";
        }
    }

    int size(){
        return size1;
    }
    bool is_empty(){
        return v.empty();
    }

    
    void insert_at(int ele, int idx){
        list<int>::iterator it=v.begin();
        advance(it,idx);
        v.insert(it,ele);
        size1++;
    }
    void delete_from(int idx){
       list<int>::iterator it=v.begin();
        advance(it,idx);
        v.erase(it);
        size1++;
    }

    int peek_at(int idx){
         list<int>::iterator it=v.begin();
        advance(it,idx);
        return *it;
    }
};

int main(){
    Dequeue d;
    d.push_back(1);
    d.push_front(7);
    d.push_back(2);
    d.insert_at(3,1);
    cout<<d.size()<<endl;
   //d.delete_from(1);
    d.display();

    return 0;
}