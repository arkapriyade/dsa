#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a<=b;
}
int partition(int arr[], int a, int b){
    int pivot = arr[b];
    int i = a-1;

    for(int j = a ; j < b ; j++){
        if(cmp(arr[j],pivot)){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[b]);

    return i+1;
}
void quick_sort(int arr[],int i,int j){
if(i>=j)return;
int p=partition(arr,i,j);
quick_sort(arr,i,p-1);
quick_sort(arr,p+1,j);
}
void display(int arr[],int n){
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[5]={5,4,2,3,1};
    quick_sort(arr,0,4);
    display(arr,4);
    return 0;
}