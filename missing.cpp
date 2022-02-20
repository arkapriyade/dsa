#include <bits/stdc++.h>
using namespace std;

// Function to get the missing number
int getMissingNo(int a[], int n)
{
sort(a,a+n);
int j=0;
for( j=0;j<n;j++){
    
        if(a[j+1]==a[j]+1){
            continue;
        }
        else{
            break;
        }
    }
    return a[j]+1;

}

// Driver Code
int main()
{
	int arr[] = { 4, 5, 6,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	int miss = getMissingNo(arr, n);
	cout << miss;
}