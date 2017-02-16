#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Método bubblesort(?)
	int a[10000],n,b;
	cout << "Entre com n: " << endl;
	cin >> n;

	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	for (int i=0;i<n;i++)
		for (int j=0;j<i;j++)
		{
			if (a[j+1] < a[j])
			{
				b = a[j];
				a[j] = a[j+1];
				a[j+1] = b;
			}
		}
	for (int i=0;i<n;i++) cout << a[i] << " ";
	cout << endl;
}