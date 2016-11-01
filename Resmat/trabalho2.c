#include <stdio.h>
#include <string.h>

/*
	Integrantes:
	Fabio Viana Lopes Andrade da Silva
	Onias Castelo Branco Silveira
	Marina Mendonça Alves
	Rafael Araújo França
	Vitor Amor Wolfgram


	Esse programa foi feito utilizando o SO Ubuntu 16.04 LTS
	Esse código permite a escolha de resolver a questão: por entrada de dados do teclado ou por entrada de dados por um arquivo.
*/



int main()
{
	FILE *fp, *aux, *fpmatP, *fpmatEF;
	char ch; 
	float diamEF,diamP,compEF,compP,passo,EEF,EP,b;
	float deslEF, deslP;
	float forca,tensao;
	int cont=0,opcaoq,opcaoparafuso,opcaoEF;
	char materialParafuso[50],materialEF[50];

	void pegadadosParafuso(int linhaS, int linhaE, int linhaD, int linhaP)
	{
		int linha=0;
		fpmatP = fopen("MaterialParafuso.txt","r");
		if (fpmatP == NULL) printf("Não é possível abrir o arquivo.");
		else
		{
			while((ch=fgetc(fpmatP))!=EOF)
			{
				// Esse if conta o número de linhas; será importante para sabermos em qual linha pegar determinado dado.
				if(ch=='\n') linha++;

			
				// Essa série de if vai verificar a linha que o dado se encontra para então armazenar seus valores.
			


				if (linha == linhaS)
				{
					fscanf(fpmatP,"%s",materialParafuso);
				}
				// Esse if é responsável por pegar o Módulo de Young.
				if(linha==linhaE)
				{
					fscanf(fpmatP,"%f",&EP);
				}
				// Esse if é responsável por pegar o diâmetro do parafuso.
				if(linha==linhaD)
				{
					fscanf(fpmatP,"%f",&diamP);
				}
				// Esse if é responsável por pegar o passo.
				if(linha==linhaP)
				{
					fscanf(fpmatP,"%f",&passo);
				}
			}
		}
		fclose(fpmatP);
	}

	void pegadadosEF(int linhaS,int linhaE, int linhaD)
	{
		int linha =0;
		fpmatEF = fopen("MaterialEF.txt","r");
		if (fpmatEF == NULL) printf("Não é possível abrir o arquivo.");
		else
		{
			while((ch=fgetc(fpmatEF))!=EOF)
			{
				// Esse if conta o número de linhas; será importante para sabermos em qual linha pegar determinado dado.
				if(ch=='\n') linha++;

			
				// Essa série de if vai verificar a linha que o dado se encontra para então armazenar seus valores.
			

				if(linha == linhaS)
				{
					fscanf(fpmatEF,"%s",materialEF);
				}
				// Esse if é responsável por pegar o Módulo de Young.
				if(linha==linhaE)
				{
					fscanf(fpmatEF,"%f",&EEF);
				}
				// Esse if é responsável por pegar o diâmetro da barra EF.
				if(linha==linhaD)
				{
					fscanf(fpmatEF,"%f",&diamEF);
				}
			}
		}
		fclose(fpmatEF);
	}



	printf("Escolha uma opção:\n1 - Resolver a questão recebendo dados do teclado.\n2 - Recebendo dados de um arquivo.\nOutro - Sair\n");
	scanf("%d",&opcaoq);

	switch(opcaoq)
	{
		case 1:
		{

			printf("Escolha um parafuso: ");
			scanf("%d",&opcaoparafuso);
			switch(opcaoparafuso)
			{
				case 1:
				{
					pegadadosParafuso(4,6,8,10);
					break;
				}
				case 2:
				{
					pegadadosParafuso(14,16,18,20);
					break;
				}
				case 3:
				{
					pegadadosParafuso(24,26,28,30);
					break;
				}
			}
			
			printf("Escolha a barra EF: ");
			scanf("%d",&opcaoEF);
			switch(opcaoEF)
			{
				case 1:
				{
					pegadadosEF(3,5,7);
					break;
				}
				case 2:
				{
					pegadadosEF(10,12,14);
					break;
				}
				case 3:
				{
					pegadadosEF(17,19,21);
					break;
				}
			}
			printf("Informe o comprimento da barra EF e o da barra CD:\n");
			scanf("%f%f",&compEF,&compP);
			// Recebidos os dados, vamos realizar os cálculos necessários para chegar à resposta
			deslEF = 4*compEF/(3.1415926*diamEF*diamEF*EEF);
			deslP = 4*compP/(3.1415926*diamP*diamP*EP); 
			passo /= 4;
			forca = 2*passo/(deslP + 2*deslEF); 
			tensao = 4000*forca/(3.1415926*diamEF*diamEF);
			printf("\nMaterial do parafuso: %s\nModulo de Young do parafuso: %.1f\nDiâmetro do parafuso: %.1f\nPasso do parafuso: %.1f\nComprimento do parafuso: %.1f\n\nMaterial da barra EF: %s\nMódulo de Young da barra: %.1f\nDiâmetro da barra EF: %.1f\nComprimento da barra EF: %.1f\n\nForça na barra EF: %.1f kN\nA tensão na barra EF é: %.1f MPa\n\n",materialParafuso,EP,diamP,passo*4,compP,materialEF,EEF,diamEF,compEF,forca,tensao);


			break;
		}
		
		case 2:
		{
			fp = fopen("DadosDaQuestaoResmat.txt","r");
			if (fp==NULL) printf("Não é possível abrir o arquivo. Verifique se o arquivo se encontra na mesma pasta que o executável.\n");
			else
			{
				while((ch=fgetc(fp))!=EOF)
				{
					// Esse if conta o número de linhas; será importante para sabermos em qual linha pegar determinado dado.
					if(ch=='\n') cont++;
	
				
					// Essa série de if vai verificar a linha que o dado se encontra para então armazenar seus valores.
				
	
					// Esse if é responsável por pegar os dados da 2ª linha: os diâmetros.
					if(cont==1)
					{
						fscanf(fp,"%d",&opcaoparafuso);
						switch(opcaoparafuso)
						{
							case 1:
							{
								pegadadosParafuso(4,6,8,10);
								break;
							}
							case 2:
							{
								pegadadosParafuso(14,16,18,20);
								break;
							}
							case 3:
							{
								pegadadosParafuso(24,26,28,30);
								break;
							}
						}
					}
					// Esse if é responsável por pegar os comprimentos das barras na linha 4.
					if(cont==3)
					{
						fscanf(fp,"%d",&opcaoEF);
						switch(opcaoEF)
						{
							case 1:
							{
								pegadadosEF(3,5,7);
								break;
							}
							case 2:
							{
								pegadadosEF(10,12,14);
								break;
							}
							case 3:
							{
								pegadadosEF(17,19,21);
								break;
							}
						}
					}
					// Esse if é responsável por pegar o dado da linha 6: o passo.
					if(cont==5)
					{
						fscanf(fp,"%f%f",&compEF,&compP);
					}
				}	
	
				// Feitas as leituras, basta fazer os cálculos necessários para chegar à resposta.
			
				deslEF = 4*compEF/(3.1415926*diamEF*diamEF*EEF);
				deslP = 4*compP/(3.1415926*diamP*diamP*EP);
				passo /= 4;
				forca = 2*passo/(deslP + 2*deslEF);
				tensao = 4000*forca/(3.1415926*diamEF*diamEF);
				fclose(fp);
			}

			//Para terminar, precisamos escrever no arquivo a resposta. Esse código adiciona as respostas sem apagar os resultados anteriores.
			fp = fopen("Resposta.txt","w");
			fprintf(fp, "Material do parafuso: %s\nModulo de Young do parafuso: %.1f\nDiâmetro do parafuso: %.1f\nPasso do parafuso: %.1f\nComprimento do parafuso: %.1f\n\nMaterial da barra EF: %s\nMódulo de Young da barra: %.1f\nDiâmetro da barra EF: %.1f\nComprimento da barra EF: %.1f\n\nForça na barra EF: %.1f kN\nA tensão na barra EF é: %.1f MPa\n\n",materialParafuso,EP,diamP,passo*4,compP,materialEF,EEF,diamEF,compEF,forca,tensao);
			fclose(fp);
		}
	}
}