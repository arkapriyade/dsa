#include<bits/stdc++.h>
using namespace std;



class Queue{
    list<int>l;
    int size1=0;
    public:
    void push(int i){
        l.push_back(i);
        size1++;
    }
    void pop(){
        l.pop_front();
        size1--;
    }
    int peek(){
        return l.front();
    }
    int size(){
        return size1;
    }
    bool is_empty(){
        return l.empty();
    }
};

int main(){
Queue s;
s.push(1);
s.push(2);
s.push(3);
s.pop();
cout<<s.peek()<<endl;
s.push(4);
cout<<s.peek()<<endl;
cout<<s.size()<<endl;
s.pop();
s.pop();

cout<<s.is_empty()<<endl;

return 0;
}
