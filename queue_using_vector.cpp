#include<bits/stdc++.h>
using namespace std;



class Queue{
    vector<int>v;
    int size1=0;
    public:
    void push(int i){
        v.push_back(i);
        size1++;
    }
    void pop(){
    if (!v.empty()) {
        v.erase(v.begin());
        size1--;
    }
    else{
        cout<<"queue is empty";
    }

    }
    int peek(){
        return *v.begin();
    }
    int size(){
        return size1;
    }
    bool is_empty(){
        return v.empty();
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
