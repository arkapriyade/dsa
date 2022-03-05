#include<bits/stdc++.h>
using namespace std;
void bubble(int arr[],int n){
for(int i=0;i<n;i++){
  
    for(int j=0;j<n;j++){
        if(arr[j]>arr[j+1]){
      swap(arr[i],arr[j]);
        }
    }
    
}

}



int main(){
    int arr[5]={5,4,2,3,1};
    bubble(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}