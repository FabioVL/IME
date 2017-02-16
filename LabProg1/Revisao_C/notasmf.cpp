#include <bits/stdc++.h>
using namespace std;

int main()
{
	FILE *fp;
	char sexo;
	float notam=0,notaf=0, contm=0, contf=0, nota;

	fp = fopen("ex4.txt","r");
	if (fp == NULL) printf("Não é possivel abrir o arquivo");
	else
	{
		while(fscanf(fp,"%c %f",&sexo,&nota)!=EOF)
		{
			if (sexo == 'M' or sexo == 'm')
			{
				notam+=nota;
				contm++;
			}
			if (sexo == 'F' or sexo == 'f')
			{
				notaf+=nota;
				contf++;
			}
		}
		if ((notam/contm) > (notaf/contf)) cout << "M " << notam/contm << endl;
		else if ((notam/contm) < (notaf/contf)) cout << "F " << notaf/contf << endl;
		else cout << "As medias sao iguais a: " << notam/contm << endl;
		fclose(fp);
	}	
}