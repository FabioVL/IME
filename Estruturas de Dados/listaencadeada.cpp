#include <bits/stdc++.h>
using namespace std;


// Essa lista possui asa opções de incluir no início e no final, e retirar do início e do final.
// Logo, pode funcionar como uma fila ou como uma pila, basta restringir as inclusões e exclusões.

struct Node 
{
	int i;
	Node *prox;
};

typedef struct Node node ;

void iniciar(node *lista)
{	
	lista->prox = NULL;
}

void inserirInicio(node *lista, int n)
{
	node *novo = (node*)malloc(sizeof(node));
	if(!novo)
	{
		cout << "Sem memória disponível!" << endl;
		exit(1);
	}
	novo->i = n;
	node *antigo = lista->prox;
	lista->prox = novo;
	novo->prox = antigo;
}

void inserirFinal(node *lista, int n)
{
	node *novo = (node*)malloc(sizeof(node));
	novo->i = n;
	if (lista->prox == NULL) lista->prox = novo;
	else
	{
		node *temp = lista->prox;
		while(temp->prox != NULL) temp = temp->prox;
		temp->prox = novo;
		novo->prox = NULL;
	}
}

void exibir(node *lista)
{
	if(lista->prox == NULL) 
	{
		cout << "Lista vazia!" << endl;
		return;
	}
	node *temp;
	temp = lista->prox;
	while (temp!=NULL)
	{
		cout << temp->i << " ";
		temp = temp->prox;
	}
	cout << endl;
}

void liberarLista(node *lista)
{
	if(lista->prox != NULL)
	{
		node *proximo,*atual;
		atual = lista->prox;
		while(atual != NULL)
		{
			proximo = atual->prox;
			free(atual);
			atual = proximo;
		}
	}
}

void retirarInicio(node *lista)
{
	if(lista->prox == NULL) cout << "Lista vazia" << endl;
	else
	{
		node *temp = lista->prox;
		lista->prox = temp->prox;
		free(temp);
	}
}

void retirarFinal(node *lista)
{

	if(lista->prox == NULL) cout << "Lista vazia" << endl;
	else
	{
		node *ultimo, *penultimo;
		ultimo = lista->prox;
		while(ultimo->prox != NULL)
		{
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		penultimo->prox = NULL;
	}
}

int main()
{

	int n,valor;
	node *lista = (node*)malloc(sizeof(node));
	iniciar(lista);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&valor);
		inserirFinal(lista,valor);
	}
	exibir(lista);
	liberarLista(lista);
	
}
