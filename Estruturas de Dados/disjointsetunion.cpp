#include <bits/stdc++.h>
using namespace std;
/*

Disjoint set union (DSU)

*/
const int N = 10E6;
int pai[N]; //for(int i=0;i<N;i++) par[i] = i;
int size[N]; // for (int i=0;i<N;i++) size[i] = 1;

int find(int a)
{
	if(pai[a]==a) return a;
	return pai[a] = find(pai[a]); //poderia ser return find(pai[a]) apenas, porém colocar pai[a] = find(...) faz a compressão de caminho!
}

void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a==b) return;
	if(b>a) swap(a,b);
	pai[b] = a;
	size[a] += size[b];
}