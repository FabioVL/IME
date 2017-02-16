#include <bits/stdc++.h>
using namespace std;

// int f[100];

int fibonacci(int n)
{
	if (n==0 or n==1) return 1;
	else return fibonacci(n-1)+fibonacci(n-2);
}

/*
int fibonacciDP(int n)
{
	if (n==0 or n==1) return 1;
	if (f[n]!=0) return f[n];
	else return f[n] = fibonacciDP(n-1) + fibonacciDP(n-2);
}
*/

int main()
{
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;
	// cout << fibonacciDP(n) << endl;
}