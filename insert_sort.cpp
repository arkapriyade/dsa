#include<bits/stdc++.h>
using namespace std;
void insertion(int arr[],int n){

for(int i=1;i<n;i++){
int curr=arr[i];
int j;
for(j=i-1;j>=0;j--){
    if(arr[j]>curr){
        arr[j+1]=arr[j];
    }
    else{
        break;
    }
   
}
 arr[j+1]=curr;
}


}
int main(){
    int arr[5]={5,4,2,3,1};
    insertion(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}