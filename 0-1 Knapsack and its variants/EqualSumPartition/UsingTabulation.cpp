  
#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same.
*/
bool isSubsetSum(int arr[], int n, int sum) {
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++) {
        dp[i][0] = true;
    }
    for(int j=1;j<=sum;j++) {
        dp[0][j] = false;
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum;j++) {
            if(arr[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

bool isEqualSumPartition(int arr[], int n) {
    long long int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
    }
    
    if(sum % 2 != 0) {
        return false;
    }
    else {
        return isSubsetSum(arr, n, sum/2);
    }
}

int main() {
    int arr[] = {1, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(isEqualSumPartition(arr, n)) {
        cout<<"Yes"<<endl;
    }    
    else {
        cout<<"No"<<endl;
    }
    return 0;
}
