class Dequeue{
    vector<int>v;
    int size1=0;
    public:

    void push_front(int ele){
       v[0]=ele;
       for(int i=1;i<v.size();i++){
           v[i+1]=v[i];
       }
       size1++;
    }
    void pop_front(){
        if (!v.empty()) {
        v.erase(v.begin());
        size1--;
    }
    else{
        cout<<"queue is empty";
    }
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
        return *v.begin();
    }
    int peek_back(){
        return *v.end();
    }

    void display(){
        vector<int>::iterator it;
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
        v.insert(v.begin()+idx,ele);
    }
    void delete_from(int idx){
        v.erase(v.begin()+idx);
    }

    int peek_at(int idx){
        return v[idx];
    }
};

int main(){
    Dequeue d;
    d.push_back(1);
    d.push_back(2);
    d.insert_at(3,1);
    cout<<d.size()<<endl;
   //d.delete_from(1);
    d.display();

    return 0;
}
