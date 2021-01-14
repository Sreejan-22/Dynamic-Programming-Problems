#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
*/

bool isSubsetSum(int arr[], int n, int sum) {
	bool dp[n+1][sum+1];
	// if "sum" for a subproblem is zero then, regardless of the value of elements, ans will be true 
	for(int i=0;i<=n;i++) {
		dp[i][0] = true;
	}
	// if there are zero elements for a subproblem and corresponding "sum" is greater than 0 then ans will be false
	for(int j=1;j<=sum;j++) {
		dp[0][j] = false;
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sum;j++) {
			if(arr[i-1] > sum) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}
	return dp[n][sum];
}

int main() {
  int arr1[] = { 2, 3, 7, 8, 10 };
  int sum1 = 11; 
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int arr2[] = {3, 34, 4, 12, 5, 2};
  int sum2 = 30;
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << (isSubsetSum(arr1, n1, sum1) ? "yes" : "no") << endl;
  cout << (isSubsetSum(arr2, n2, sum2) ? "yes" : "no") << endl;
}
