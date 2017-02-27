#include <bits/stdc++.h>
using namespace std;

float calculaMedia(float *vetor, int n)
{
	float soma = 0;
	for(int i=0;i<n;i++) soma += *vetor, vetor++; 
	return soma/n;
}

// Podemos fazer assim também:
float calculaMedia2(float *vetor, int n)
{
	float soma = 0;
	for(int i=0;i<n;i++) soma += vetor[i];
	return soma/n;
}

int main()
{
	float *notas, valor, media;
	int n;
	cin >> n;
	notas = (float *) malloc(n*sizeof(float));
	if (notas == NULL)
	{
		cout << "Memória insuficiente!" << endl;
		return 0;
	}
	// Calcula usando prefix sum
	for (int i=0;i<n;i++) scanf("%f",notas+i);
	cout << "Média: " << calculaMedia(notas,n) << endl;
	cout << "Média: " << calculaMedia2(notas,n) << endl;
}