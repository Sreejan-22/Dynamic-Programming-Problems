#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
	if(n < 2) {
		return n;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    cout<<fibonacci(1)<<endl;
    cout<<fibonacci(2)<<endl;
    cout<<fibonacci(5)<<endl;
    cout<<fibonacci(8)<<endl;
}
