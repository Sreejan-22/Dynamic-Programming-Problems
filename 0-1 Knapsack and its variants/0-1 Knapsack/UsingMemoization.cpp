#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given weights and values of n items, put these items in a knapsack of capacity w to get the 
maximum total value in the knapsack. Note that we are allowed to have only one quantity of each item.
*/

// Using memoization

int solveKnapsack(int w, int wt[], int val[], int i, vector<vector<int>> &dp) {
	if(i < 0) {
		return 0;
	}
	if(dp[i][w] != -1) {
		return dp[i][w];
	}
	if(wt[i] > w) {
		return dp[i][w] = solveKnapsack(w, wt, val, i-1, dp);
	}
	else { // i.e. if(wt[i] <= w)
		return dp[i][w] = max(val[i] + solveKnapsack(w-wt[i], wt, val, i-1, dp), solveKnapsack(w, wt, val, i-1, dp));
	}
}

int knapsack(int w, int wt[], int val[], int n) 
{ 
   // base condition
	if(w == 0 || n == 0) {
		return 0;
	}
	// int dp[n+1][w+1];
	// memset(dp, -1, sizeof(dp));
	vector<vector<int>> dp(n+1, vector<int> (w+1, -1));
	return solveKnapsack(w, wt, val, n-1, dp);
}

int main() {
  int val[] = { 4, 5, 3, 7 }; 
  int wt[] = { 2, 3, 1, 4 }; 
  int w = 5; 
  int n = sizeof(val) / sizeof(val[0]); 
  cout << knapsack(w, wt, val, n); 
}
