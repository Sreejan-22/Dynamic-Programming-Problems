// Top-Down method with memoization 

int fibonacci(int n, vector<int> &dp) {
	if(n < 2) {
		return n;
	}

	// if the subproblem is already solved
	if(dp[n] != -1) {
		return dp[n];
	}
	else {
		dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
		return dp[n];
	}
}

int main() {
  int n = 10;
  vector<int> dp(n+1, -1);
  cout << fibonacci(n, dp) << endl;
}
