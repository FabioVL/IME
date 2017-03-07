#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int num;
	Node *prox;
};
typedef struct Node node;

void iniciar(node *pilha)
{
	pilha->prox = NULL;
}

void push(node *pilha, int n)
{
	node *novo = (node*)malloc(sizeof(node));
	novo->num=n;
	if(pilha->prox == NULL) pilha->prox = novo;
	else
	{
		node *temp = pilha->prox;
		while(temp->prox != NULL)	temp = temp->prox;
		temp->prox = novo;
	}
}

void pop(node *pilha)
{
	if(pilha->prox == NULL) cout << "Pilha vazia!" << endl;
	else
	{
		node *penultimo, *ultimo;
		ultimo = pilha->prox;
		while(ultimo->prox != NULL)
		{
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		penultimo->prox = NULL;
	}
}

void show(node *pilha)
{
	if(pilha->prox == NULL)
	{
		cout << "Pilha vazia!" << endl;
		return;
	}
	node *temp = pilha->prox;
	while(temp!=NULL)
	{
		cout << temp->num << " ";
		temp=temp->prox; 
	}
	cout << endl;	
}

int main()
{
	int n,valor;
	node *pilha;
	pilha = (node *)malloc(sizeof(node));
	if (!pilha) 
	{
		cout << "Sem memória" << endl;
		return 0;
	}
	iniciar(pilha);
	cin >> n;
	for(int i=0;i<n;i++) scanf("%d",&valor), push(pilha,valor);
	show(pilha);
	pop(pilha);
	show(pilha);
}