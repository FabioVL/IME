#include <bits/stdc++.h>
using namespace std;

int main()
{

	FILE *fp;
	int prod,soma,valor;
	prod = 1;
	soma = 0;
	fp = fopen("ex3.txt","r");
	if (fp == NULL) printf("Não é possível abrir o arquivo");
	else
	{
		while(fscanf(fp,"%d",&valor)!=EOF)
		{
			if (valor%2) soma += valor;
			else prod *= valor;
		}
		free(fp);
	}	
	cout << prod << endl << soma << endl;

}