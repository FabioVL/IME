#include <bits/stdc++.h>
using namespace std;

void pares(int n, int i)
{
	if (n%2==1) n=n-1;
	if (i<=n)
	{
		printf("%d ",i);
		pares(n, i+2);
	}
}

int main()
{
	int n;
	cin >> n;
	pares(n,0);
	cout << endl;
}