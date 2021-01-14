#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given weights and values of n items, put these items in a knapsack of capacity w to get the 
maximum total value in the knapsack. Note that we are allowed to have only one quantity of each item.
*/

// Using recursion
int knapsack(int w, int wt[], int val[], int n) 
{ 
   // base condition
	if(w == 0 || n == 0) {
		return 0;
	}

	if(wt[n-1] > w) {
		return knapsack(w, wt, val, n-1);
	}
	else if(wt[n-1] <= w) {
		return max(val[n-1] + knapsack(w - wt[n-1], wt, val, n-1), knapsack(w, wt, val, n-1));
	}
}

int main() {
  int val[] = { 60, 100, 120 }; 
  int wt[] = { 10, 20, 30 }; 
  int w = 50; 
  int n = sizeof(val) / sizeof(val[0]); 
  cout << knapsack(w, wt, val, n); 
}
