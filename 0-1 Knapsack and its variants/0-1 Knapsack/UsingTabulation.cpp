#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given weights and values of n items, put these items in a knapsack of capacity w to get the 
maximum total value in the knapsack. Note that we are allowed to have only one quantity of each item.
*/

// Bottom Up Approach
// Using tabulation

int knapsack(int w, int wt[], int val[], int n) 
{
	int dp[n+1][w+1];
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=w;j++) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if(wt[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}
		}
	}

	return dp[n][w];
}

int main() {
  int val[] = { 4, 5, 3, 7 }; 
  int wt[] = { 2, 3, 1, 4 }; 
  int w = 5; 
  int n = sizeof(val) / sizeof(val[0]); 
  cout << knapsack(w, wt, val, n); 
}
