#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int num;
	Node *prox;
};

typedef struct Node node;

void iniciar(node *fila)
{
	fila->prox = NULL;
}

void retirarInicio(node *fila)
{
	if (fila->prox == NULL) cout << "Fila vazia!" << endl;
	else 
	{
		node *temp = fila->prox;
		fila->prox = temp->prox;
		free(temp);
	}
}

void inserirFinal(node *fila, int n)
{
	node *novo = (node *)malloc(sizeof(node));
	novo->num = n;
	if (fila->prox == NULL) fila->prox = novo;
	else
	{
		node *temp = fila->prox;
		while(temp->prox != NULL) temp = temp->prox;
		temp->prox = novo;
	}
}

void exibir(node *fila)
{
	if(fila->prox == NULL) cout << "Fila vazia" << endl;
	else
	{
		node *temp = fila->prox;
		while(temp != NULL)
		{
			cout << temp->num << " ";
			temp = temp->prox;
		}
	}
	cout << endl;
}

void liberarFila(node *fila)
{
	if (fila->prox != NULL) 
	{
		node *proximo,*atual;
		atual = fila->prox;
		while(atual != NULL)
		{
			proximo = atual->prox;
			free(atual);
			atual = proximo;
		}
	}
}

int tamanho(node *fila)
{
	int tam = 0;
	if(fila->prox != NULL)
	{
		node *temp = fila->prox;
		while(temp != NULL)
		{
			tam++;
			temp = temp->prox;
		}
	}
	return tam;
}

int main()
{
	int n,valor;
	node *fila = (node *)malloc(sizeof(node));
	iniciar(fila);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> valor;
		inserirFinal(fila, valor);
	}
	exibir(fila);
	cout << "A fila tem " << tamanho(fila) << " elementos" << endl;
	retirarInicio(fila);
	exibir(fila);
	cout << "A fila tem " << tamanho(fila) << " elementos" << endl;
	liberarFila(fila);
}