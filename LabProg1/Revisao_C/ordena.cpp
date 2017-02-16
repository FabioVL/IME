#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Método bubblesort(?)
	int *a,n,b;
	
	cout << "Entre com n: " << endl;
	cin >> n;
	
	a = (int *) malloc(n* (sizeof(int)));
	
	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	for (int i=0;i<n;i++)
		for (int j=0;j<n-1;j++)
		{
			if (a[j+1] < a[j])
			{
				b = a[j];
				a[j] = a[j+1];
				a[j+1] = b;
			}
		}
	
	for (int i=0;i<n;i++) cout << a[i] << " ";
	
	free(a);
	cout << endl; //a[i] = p[1]
	// nome = &nome[0] p[i] = p+i 
}