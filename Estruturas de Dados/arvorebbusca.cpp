#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int chave;
	Node *esq;
	Node *dir;
}

typedef struct Node node;

node *busca(int chave, node *aux, node **pai, int *f)
{
	if (aux == NULL) //Arvore vazia
	{
		*f = 0;
		return aux;
	}
	else
	{
		if (chave == aux->chave) //encontrei
		{
			*f=1;
			return aux;
		}
		else
		{
			if (chave < aux->chave) //ir para esquerda
			{
				if (aux->esq!=NULL)
				{
					*pai=aux;
					return busca(chave,aux->esq,pai,f);
				}
				else
				{
					*f=2;
					return aux;
				}
			}
			else
			{
				if(aux->dir!=NULL)
				{
					*pai = aux;
					return busca(chave, aux->dir, pai,f)

				}
				else
				{
					*f=3;
					return aux;
				}
			}
		}
	}
}



int main()
{

}