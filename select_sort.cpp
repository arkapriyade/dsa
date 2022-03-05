#include<bits/stdc++.h>
using namespace std;
void select(int arr[],int n){
for(int i=0;i<n;i++){
    int min1=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min1])
       min1=j;

    }
    
    swap(arr[min1],arr[i]);
   
}

}



int main(){
    int arr[5]={5,4,2,3,1};
    select(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}