#include<bits/stdc++.h>
using namespace std;

class Stack{
    vector<int>v;
    int size1=0;
    public:
    void push(int i){
        v.push_back(i);
        size1++;
    }
    void pop(){
        v.pop_back();
        size1--;
    }
    int top(){
        return v.back();
    }
    int size(){
        return size1;
    }
    bool is_empty(){
        return v.empty();
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
s.pop();
s.pop();

cout<<s.is_empty()<<endl;
return 0;
}
