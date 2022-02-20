#include<bits/stdc++.h>
using namespace std;

class Stack{
    list<int>l;
    int size1=0;
    public:
    void push(int i){
        l.push_back(i);
        size1++;
    }
    void pop(){
        l.pop_back();
        size1--;
    }
    int top(){
        return l.back();
    }
    int size(){
        return size1;
    }
    bool is_empty(){
        return l.empty();
    }
};

int main(){
Stack s;
s.push(1);
s.push(2);
s.push(3);
s.pop();
cout<<s.top()<<endl;
s.push(4);
cout<<s.top()<<endl;
cout<<s.size()<<endl;
return 0;
}
