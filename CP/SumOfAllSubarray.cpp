/* contribution technique*/
// 5 10 15
// [5], [5,10], [5,10,15], [10], [10,15], [15] -> 5 + 15 + 30 + 10 + 25 + 15 = 100

// | 5 | 10 | 15 |   -> total number of subarray = 4c2 = 4*5/2 = 10  , (n+1)C2
//   0    1    2
// number 10 appears in how many subarray, 2c1 * 2c1 = 2*2 = 4
// frequency of appearing of ith element in all subarray = (i+1)*(n-1)
#include<bits/stdc++.h>
using namespace std;

int helper(int*arr, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i]*(i+1)*(n-i); // number of times arr[i] element comes in all subarray = (i+1)*(n-i)
    }
    return sum;
}
int main(){
    int arr[5]={5,10,15,20,12};
    cout<<helper(arr,5);
}