#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n,a,b,fib;
	a=1;
	b=1;
	cin >> n;
	for (int i=0; i<n-1; i++ )
	{
		fib = a+b;
		a = b;
		b = fib;
	}
	cout << fib << endl;
}