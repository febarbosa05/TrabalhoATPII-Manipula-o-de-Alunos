#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "meuconio.h"
#define TF 100

struct TpAluno
{
	char RA[13], Nome[30];
};

struct TpDisc
{
	int CodDisc;
	char Descr[40];	
};

struct TpNota
{
	char RA[13];
	int CodDisc;
	float Nota;
};

struct TpReprovado
{
	char RA[13];
};

struct TpRelatorioG
{
	char RA[13];
};

struct TpMedia
{
	int Cod;
};

void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF,int SupE,int SupD,int InfE,int InfD)
{
	int i;
	textcolor(CorT);
	textbackground(CorF);
	gotoxy(CI,LI);
	printf("%c",SupE);
	gotoxy(CI,LF);
	printf("%c",InfE);
	gotoxy(CF,LI);
	printf("%c",SupD);
	gotoxy(CF,LF);
	printf("%c",InfD);
	for(i=CI+1; i<CF; i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1; i<LF; i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

void FundoMenu(void)
{
	
	clrscr();
	//valores: (CL,LI,CF,LF,CorT,CorF,SupE,SupD,InfE,InfD)
	Moldura(1,1,100,30,0,1,201,187,200,188);
	//Titulo 
	Moldura(1,5,100,30,0,1,204,185,200,188); 
	textcolor(6);
	gotoxy(40,3);
	printf("REGISTRO DE NOTAS");
	//MENU
	Moldura(20,6,80,29,5,0,201,187,200,188);
	
}

void Fundo(void)
{
	clrscr();
	//valores: (CL,LI,CF,LF,CorT,CorF,SupE,SupD,InfE,InfD)
	Moldura(1,1,100,30,0,1,201,187,200,188);
	//Titulo 
	Moldura(1,5,100,30,0,1,204,185,200,188);
}

char Menu(void)
{
	textcolor(15);
	gotoxy(22,7);
	printf("######################### MENU ##########################");
	textcolor(10);
	gotoxy(23,9);
	printf("[A] Cadastrar Alunos");
	gotoxy(23,11);
	printf("[B] Cadastrar Disc.");
	gotoxy(23,13);
	printf("[C] Cadastrar Notas");
	gotoxy(23,15);
	printf("[D] Cadastro autom.");
	gotoxy(23,17);
	printf("[E] Exclusao de Aluno");
	gotoxy(23,19);
	printf("[F] Exclusao de Disc.");
	gotoxy(23,21);
	printf("[G] Exclusao de Nota");
	gotoxy(55,9);
	printf("[H] Alteracao de Aluno");
	gotoxy(55,11);
	printf("[I] Alteracao de Disc.");
	gotoxy(55,13);
	printf("[J] Alteracao de Nota");
	gotoxy(55,15);
	printf("[K] Consulta de Aluno");
	gotoxy(55,17);
	printf("[L] Consulta de Disc.");
	gotoxy(55,19);
	printf("[M] Consulta de Nota");
	gotoxy(55,21);
	printf("[N] Relatorios");
	gotoxy(40,25);
	printf("[ESC] Finalizar");
	textcolor(11);
	gotoxy(38,27);
	printf("Escolha: ");
	textcolor(7);
	return toupper(getche());
}

char Relatorio(void)
{
	textcolor(15);
	gotoxy(22,7);
	printf("###################### RELATORIO ########################");
	textcolor(10);
	gotoxy(37,10);
	printf("[A] Reprovados em 2 ou +");
	gotoxy(37,12);
	printf("[B] Aluno por Letra");
	gotoxy(37,14);
	printf("[C] Disc. por Palavra");
	gotoxy(37,16);
	printf("[D] Disc. Media < 6");
	gotoxy(37,18);
	printf("[E] Relatorio Geral");
	gotoxy(37,20);
	printf("[ESC] Voltar para o Menu");
	textcolor(11);
	gotoxy(38,24);
	printf("Escolha: ");
	textcolor(7);
	return toupper(getche());
}

int BuscaRA(TpAluno Al[TF],int TL, char AuxRA[13])
{
	int i=0;
	while(i<TL && stricmp(AuxRA, Al[i].RA)!=0)
		i++;
	if(i<TL)
		return i;
	else
		return -1;
}

int BuscaDisc(TpDisc Disc[TF], int TL, int AuxCod)
{
	int i=0;
	while(i<TL && AuxCod!=Disc[i].CodDisc)
		i++;
	if(i<TL)
		return i;
	else
		return -1;
}

int BuscaDescr(TpDisc Disc[TF], int TL, char AuxDesc[40])
{
	int i=0;
	while(i<TL && stricmp(AuxDesc, Disc[i].Descr)!= 0)
		i++;
	if(i<TL)
		return i;
	else
		return -1;
}

int BuscaNota(TpNota Notas[TF*2],int TL,int AuxCod, char AuxRA[13])
{
	int i=0;
	while(i<TL && stricmp(AuxRA,Notas[i].RA)!= 0)
		i++;
	if(i<TL && AuxCod==Notas[i].CodDisc)
		return i;
	else
		return -1;
}

int BuscaRE(TpReprovado Re[TF],int TL,char AuxRA[13])
{
	int i=0;
	while(i<TL && stricmp(AuxRA, Re[i].RA)!=0)
		i++;
	if(i<TL)
		return i;
	else
		return -1;
}

int BuscaGE(TpRelatorioG Geral[TF],int TL,char AuxRA[13])
{
	int i=0;
	while(i<TL && stricmp(AuxRA, Geral[i].RA)!=0)
		i++;
	if(i<TL)
		return i;
	else
		return -1;
}

int BuscaME(TpMedia Me[TF],int TL,int AuxCod)
{
	int i=0;
	while(i<TL && AuxCod!=Me[i].Cod)
		i++;
	if(i<TL)
		return i;
	else
		return -1;
}

//busca das notas do aluno que foi exlcuido
int BuscaALN(TpNota Notas[TF*2],int TL, char AuxRA[13])
{
	int i=0;
	while(i<TL && stricmp(AuxRA,Notas[i].RA)!= 0)
		i++;
	if(i<TL)
		return i;
	else
		return -1;	
}

//busca das notas da disciplina que foi exlcuido
int BuscaDiscN(TpNota Notas[TF*2],int TL, int &AuxCod)
{
	int i=0;
	while(i<TL && AuxCod!=Notas[i].CodDisc)
		i++;
	if(i<TL)
		return i;
	else
		return -1;	
}

void LimpaLinha(int LI,int CI,int LF,int CF)
{
	int l,c;
	textcolor(0);
	for(l=LI;l<LF+1;l++)
		for(c=CI; c<CF+1;c++)
		{
			gotoxy(c,l);
			printf("0");
		}
	textcolor(7);
}

void CadastroRA(TpAluno Al[TF], int &TL)
{
	char AuxRA[13];
	int l=7,c=15,bus;
	Fundo();
	textcolor(4);
	gotoxy(38,3);
	printf("### CADASTRO DE ALUNOS ###");
	if(TL<TF)
	{
		gotoxy(c,l);
		textcolor(10);
		printf("R.A: ");
		fflush(stdin);
		textcolor(14);
		gets(AuxRA);
		while(TL<TF && strcmp(AuxRA,"\0")!=0)
		{
			bus=BuscaRA(Al,TL,AuxRA);
			if(bus==-1)
			{
				strcpy(Al[TL].RA ,AuxRA);
				l++;
				gotoxy(c,l);
				textcolor(10);
				printf("Nome: ");
				textcolor(14);
				fflush(stdin);
				gets(Al[TL].Nome);
				TL++;
				if(c==15)
				{				
					c=50;
					l--;
				}
				else
				{
					c=15;
					l+=2;
				}	
				if(l>27)
				{
					LimpaLinha(7,15,29,98);
					l=7;
				}
				if(TL<TF)
				{
					gotoxy(c,l); textcolor(10);
					printf("R.A: ");
					fflush(stdin);
					textcolor(14);
					gets(AuxRA);
				}
			}
			else
			{
				gotoxy(18+c,l); textcolor(4);
				printf("Ja Existente!!");
				Sleep(1000);
				LimpaLinha(l,c,l,c+32);
				gotoxy(c,l); textcolor(10);
				printf("R.A: ");
				fflush(stdin);
				textcolor(14);
				gets(AuxRA);
			}
		}
	}
	else
	{
		//valores: (CL,LI,CF,LF,CorT,CorF,SupE,SupD,InfE,InfD)
		Moldura(25,10,67,20,0,4,201,187,200,188);
		gotoxy(30,15);
		textcolor(10);
		printf("## CADASTRO DE ALUNOS CHEIO!! ##");
		Sleep(1000);
	}
}

void CadastroDisc(TpDisc Disc[TF],int &TL)
{
	char AuxDesc[40];
	int AuxCod,c=30, l=8, bus;
	
	Fundo();
	textcolor(6);
	gotoxy(31,3);
	printf("### CADASTRO DE DISCIPLINAS ###");
	if(TL<TF)
	{
		gotoxy(33,6);
		textcolor(3);
		printf("DIGITE 0 NO CODIGO PARA SAIR");
		gotoxy(c,l);
		textcolor(12);
		printf("Codigo: ");
		textcolor(14);
		scanf("%d",&AuxCod);
		while(TL<TF && AuxCod!=0 )
		{
			gotoxy(2*c,l);
			textcolor(12);
			printf("Disciplina: ");
			textcolor(14);
			fflush(stdin);
			gets(AuxDesc);
			bus=BuscaDisc(Disc, TL, AuxCod);
			if(bus==-1)
				bus=BuscaDescr(Disc, TL,AuxDesc);
			if(bus==-1)
			{
				Disc[TL].CodDisc=AuxCod;
				strcpy(Disc[TL].Descr,AuxDesc);
				TL++; l+=2;
			}
			else
			{
				gotoxy(c,l+1);
				printf("Disciplina ja cadastrada!!");
				Sleep(1000);
				LimpaLinha(l,30,l+1,99);
			}
			if(TL<TF && strcmp(AuxDesc,"\0")!=0)
			{
				if(l>=28) //quando chega no limite da moldura
				{
					LimpaLinha(8,10,29,98);
					l=8; c=30;
				}
				gotoxy(c,l); textcolor(12);
				printf("Codigo: ");
				textcolor(14);
				scanf("%d",&AuxCod);
			}
		}
	}
	else
	{
		//valores: (CL,LI,CF,LF,CorT,CorF,SupE,SupD,InfE,InfD)
		Moldura(25,10,72,20,0,4,201,187,200,188);
		gotoxy(30,15);
		textcolor(3);
		printf("## CADASTRO DE DISCIPLINAS CHEIO!! ##");
		Sleep(1000);
	}
}

void CadastroNotas(TpNota Notas[TF*2], TpAluno Al[TF], TpDisc Disc[TF] ,int &TL, int TL_Al, int TL_D)
{
	char AuxRA[13];
	int AuxCod,bus,l=7;
	float AuxNota;
	
	Fundo();
	textcolor(13);
	gotoxy(34,3);
	printf("### CADASTRO DE NOTAS ###");
	if(TL<TF*2)
	{
		gotoxy(10,l);
		textcolor(11);
		printf("R.A: ");
		fflush(stdin);
		textcolor(8);
		gets(AuxRA);
		while(TL<TF*2 && strcmp(AuxRA,"\0")!=0 && AuxCod!=0)
		{
			bus=BuscaRA(Al,TL_Al,AuxRA); //Busca para saber se o RA esta cadastrada
			if(bus!=-1)
			{
				gotoxy(35,l);
				textcolor(11);
				printf("Codigo da Disciplina: ");
				textcolor(8);
				scanf("%d",&AuxCod);
				bus=BuscaDisc(Disc,TL_D,AuxCod); //Busca para saber se a disciplina esta cadastrada
				if(bus!=-1) //esta cadastrada
				{
					gotoxy(70,l);
					textcolor(11);
					printf("Nota: ");
					textcolor(8);
					scanf("%f",&AuxNota);
					while(AuxNota<0 || AuxNota>10)
					{
						gotoxy(70,l+1);
						textcolor(4);
						printf("Nota invalida!!");
						Sleep(1000);
						LimpaLinha(l,70,l+1,98);
						gotoxy(70,l);
						textcolor(11);
						printf("Nota: ");
						textcolor(8);
						scanf("%f",&AuxNota);
					}
					TL++; l+=2;
					strcpy(Notas[TL].RA,AuxRA);
					Notas[TL].CodDisc=AuxCod;
					Notas[TL].Nota=AuxNota;
					if(TL<TF*2)
					{
						if(l>=28) //quando chega no limite da moldura
						{
							LimpaLinha(7,10,29,98);
							l=7;
						}
						gotoxy(10,l);
						textcolor(11);
						printf("R.A: ");
						fflush(stdin);
						textcolor(8);
						gets(AuxRA);
					}
				}
				else //Disciplina não cadastrada
				{
					gotoxy(35,l+1);
					textcolor(4);
					printf("Diciplina nao cadastrado!!");
					Sleep(1000);
					LimpaLinha(l,35,l+1,69);
				}
			}
			else
			{
				gotoxy(10,l+1);
				textcolor(4);
				printf("R.A nao cadastrado!!");
				Sleep(1000);
				LimpaLinha(l,10,l+1,30);
				gotoxy(10,l);
				textcolor(11);
				printf("R.A: ");
				fflush(stdin);
				textcolor(8);
				gets(AuxRA);
			}		
		}
	}
	else
	{
		//valores: (CL,LI,CF,LF,CorT,CorF,SupE,SupD,InfE,InfD)
		Moldura(25,10,66,20,0,4,201,187,200,188);
		gotoxy(30,15);
		textcolor(3);
		printf("## CADASTRO DE NOTAS CHEIO!! ##");
		Sleep(1000);
	}
}

void CadastroAutom(TpAluno Al[TF],TpDisc Disc[TF],TpNota Notas[TF],int &TL_Al,int &TL_D,int &TL_N)
{
	int i,l;
	//Cadastro de Alunos
	strcpy(Al[TL_Al].RA,"26.24.1178-1");
	strcpy(Al[TL_Al++].Nome,"Roberto");
	strcpy(Al[TL_Al].RA,"26.24.1178-2");
	strcpy(Al[TL_Al++].Nome,"Joao");
	strcpy(Al[TL_Al].RA,"26.24.1178-3");
	strcpy(Al[TL_Al++].Nome,"Matheus");
	strcpy(Al[TL_Al].RA,"26.24.1178-4");
	strcpy(Al[TL_Al++].Nome,"Felipe");
	strcpy(Al[TL_Al].RA,"26.24.1178-5");
	strcpy(Al[TL_Al++].Nome,"Jose");
	//Cadastro de Disciplina
	Disc[TL_D].CodDisc=100;
	strcpy(Disc[TL_D++].Descr,"ATP I");
	Disc[TL_D].CodDisc=200;
	strcpy(Disc[TL_D++].Descr,"ATP II");
	Disc[TL_D].CodDisc=300;
	strcpy(Disc[TL_D++].Descr,"LOGICA");
	Disc[TL_D].CodDisc=400;
	strcpy(Disc[TL_D++].Descr,"AMB PROG");
	Disc[TL_D].CodDisc=500;
	strcpy(Disc[TL_D++].Descr,"GESTAO FIN");
	//Cadastro de Notas
	strcpy(Notas[TL_N].RA,"26.24.1178-4");
	Notas[TL_N].CodDisc=200;
	Notas[TL_N++].Nota=2.0;
	strcpy(Notas[TL_N].RA,"26.24.1178-5");
	Notas[TL_N].CodDisc=400;
	Notas[TL_N++].Nota=4.7;
	strcpy(Notas[TL_N].RA,"26.24.1178-4");
	Notas[TL_N].CodDisc=300;
	Notas[TL_N++].Nota=5.8;
	strcpy(Notas[TL_N].RA,"26.24.1178-2");
	Notas[TL_N].CodDisc=200;
	Notas[TL_N++].Nota=3.5;
	strcpy(Notas[TL_N].RA,"26.24.1178-1");
	Notas[TL_N].CodDisc=100;
	Notas[TL_N++].Nota=5.0;
	Fundo();
	textcolor(10);
	gotoxy(34,3);
	printf("### CADASTRO AUTOMATICO ###");
	Moldura(25,10,67,21,4,0,201,187,200,188);
	gotoxy(30,15);
	textcolor(15);
	printf("   CADASTRO FEITO COM SUCESSO!!   ");
	Sleep(1000);
}

void ExclusaoAL(TpAluno Al[TF],TpNota Notas[TF*2],int &TL,int &TL_N)
{
	char AuxRA[13],resp,AuxRA2[13];
	int pos,i,pos_n;
	Fundo();
	textcolor(13);
	gotoxy(34,3);
	printf("### EXCLUSAO DE ALUNO ###");
	gotoxy(25,8);
	textcolor(6);
	printf("Digite o R.A do Aluno que deseja excluir!!");
	gotoxy(30,11);
	textcolor(14);
	printf("R.A: ");
	fflush(stdin);
	textcolor(3);
	gets(AuxRA);
	strcpy(AuxRA2,AuxRA);
	while(strcmp(AuxRA,"\0")!=0)
	{
		pos=BuscaRA(Al,TL,AuxRA);
		if(pos>=0)
		{
			gotoxy(34,13);
			textcolor(10);
			printf("R.A ENCONTRADO!!");
			gotoxy(30,15);
			textcolor(14);
			printf("R.A: ");
			textcolor(13);
			printf("%s",Al[pos].RA);
			gotoxy(50,15);
			textcolor(14);
			printf("Nome: ");
			textcolor(13);
			printf("%s",Al[pos].Nome);
			gotoxy(34,17);
			textcolor(2);
			printf("Deseja mesmo excluir?(S/N) ");
			fflush(stdin);
			scanf("%s",&resp);
			if(resp=='s' || resp=='S')
			{
				for(i=pos;i<TL;i++)
				{
					strcpy(Al[i].RA,Al[i+1].RA);
					strcpy(Al[i].Nome,Al[i+1].Nome);
				}
				TL--;
				pos_n=BuscaALN(Notas,TL_N,AuxRA2);
				while(pos_n>=0)
				{
					for(i=pos_n;i<TL_N;i++)
					{
						strcpy(Notas[i].RA,Notas[i+1].RA);
						Notas[i].CodDisc=Notas[i+1].CodDisc;
						Notas[i].Nota=Notas[i+1].Nota;
					}
					TL_N--;
					pos_n=BuscaALN(Notas,TL_N,AuxRA2);
				}
				gotoxy(34,20);
				textcolor(5);
				printf("ALUNO EXCLUIDO COM SUCESSO!!");
			}
			else
			{
				gotoxy(34,20);
				textcolor(5);
				printf("ALUNO NAO FOI EXCLUIDO!!");
			}
		}
		else
		{
			Moldura(30,13,58,17,11,15,201,187,200,188);
			gotoxy(35,15);
			textcolor(4);
			printf("R.A NAO ENCONTRADO!!");
		}
		Sleep(1000);
		LimpaLinha(10,20,28,98);
		gotoxy(30,11);
		textcolor(14);
		printf("R.A: ");
		fflush(stdin);
		textcolor(3);
		gets(AuxRA);
		strcpy(AuxRA2,AuxRA);
	}
}

void ExclusaoDisc(TpDisc Disc[TF],TpNota Notas[TF*2],int &TL,int &TL_N)
{
	char AuxNome[40],resp;
	int pos,i,pos_n,AuxCod;
	Fundo();
	textcolor(13);
	gotoxy(34,3);
	printf("### EXCLUSAO DE DISCIPLINA ###");
	gotoxy(25,8);
	textcolor(6);
	printf("Digite o nome da disciplina que deseja excluir!!");
	gotoxy(30,11);
	textcolor(14);
	printf("Nome: ");
	fflush(stdin);
	textcolor(3);
	gets(AuxNome);
	while(strcmp(AuxNome,"\0")!=0)
	{
		pos=BuscaDescr(Disc,TL,AuxNome);
		if(pos>=0)
		{
			gotoxy(34,13);
			textcolor(10);
			printf("DISCIPLINA ENCONTRADA!!");
			gotoxy(30,15);
			textcolor(14);
			printf("Codigo: ");
			textcolor(13);
			printf("%d",Disc[pos].CodDisc);
			AuxCod=Disc[pos].CodDisc;
			gotoxy(50,15);
			textcolor(14);
			printf("Nome: ");
			textcolor(13);
			printf("%s",Disc[pos].Descr);
			gotoxy(34,17);
			textcolor(2);
			printf("Deseja mesmo excluir?(S/N) ");
			fflush(stdin);
			scanf("%s",&resp);
			if(resp=='s' || resp=='S')
			{
				for(i=pos;i<TL;i++)
				{
					Disc[i].CodDisc=Disc[i+1].CodDisc;
					strcpy(Disc[i].Descr,Disc[i+1].Descr);
				}
				TL--;
				pos_n=BuscaDiscN(Notas,TL_N,AuxCod);
				while(pos_n>=0)
				{
					for(i=pos_n;i<TL_N;i++)
					{
						strcpy(Notas[i].RA,Notas[i+1].RA);
						Notas[i].CodDisc=Notas[i+1].CodDisc;
						Notas[i].Nota=Notas[i+1].Nota;
					}
					TL_N--;
					pos_n=BuscaDiscN(Notas,TL_N,AuxCod);
				}
				gotoxy(32,20);
				textcolor(5);
				printf("DISCIPLINA EXCLUIDA COM SUCESSO!!");
			}
			else
			{
				gotoxy(32,20);
				textcolor(5);
				printf("DISCIPLINA NAO FOI EXCLUIDA!!");
			}
		}
		else
		{
			Moldura(30,13,60,17,11,15,201,187,200,188);
			gotoxy(32,15);
			textcolor(4);
			printf("DISCIPLINA NAO ENCONTRADA!!");
		}
		Sleep(1000);
		LimpaLinha(10,20,28,98);
		gotoxy(30,11);
		textcolor(14);
		printf("Nome: ");
		fflush(stdin);
		textcolor(3);
		gets(AuxNome);
	}
}

void ExclusaoNotas(TpNota Notas[TF*2],int &TL)
{
	char AuxRA[13],resp;
	int pos,i,AuxCod;
	Fundo();
	textcolor(13);
	gotoxy(34,3);
	printf("### EXCLUSAO DE NOTAS ###");
	gotoxy(25,8);
	textcolor(6);
	printf("Digite o R.A do Aluno que deseja excluir!!");
	gotoxy(30,11);
	textcolor(14);
	printf("R.A: ");
	fflush(stdin);
	textcolor(3);
	gets(AuxRA);
	while(strcmp(AuxRA,"\0")!=0)
	{
		LimpaLinha(8,25,8,68);
		gotoxy(25,8);
		textcolor(8);
		printf("Digite o codigo da Disciplina que deseja excluir a nota!!");
		gotoxy(53,11);
		textcolor(14);
		printf("Codigo: ");
		textcolor(3);
		scanf("%d",&AuxCod);
		pos=BuscaNota(Notas,TL,AuxCod,AuxRA);
		if(pos>=0)
		{
			gotoxy(40,13);
			textcolor(10);
			printf("NOTA ENCONTRADA!!");
			gotoxy(30,15);
			textcolor(14);
			printf("Aluno: ");
			textcolor(13);
			printf("%s",Notas[pos].RA);
			gotoxy(52,15);
			textcolor(14);
			printf("Disciplina: ");
			textcolor(13);
			printf("%d",Notas[pos].CodDisc);
			gotoxy(74,15);
			textcolor(14);
			printf("Nota: ");
			textcolor(13);
			printf("%d",Notas[pos].Nota);
			gotoxy(34,17);
			textcolor(2);
			printf("Deseja mesmo excluir?(S/N) ");
			fflush(stdin);
			scanf("%s",&resp);
			if(resp=='s' || resp=='S')
			{
				for(i=pos;i<TL;i++)
				{
					strcpy(Notas[i].RA,Notas[i+1].RA);
					Notas[i].CodDisc=Notas[i+1].CodDisc;
					Notas[i].Nota=Notas[i+1].Nota;
				}
				TL--;
				gotoxy(35,20);
				textcolor(5);
				printf("NOTA EXCLUIDA COM SUCESSO!!");
			}
			else
			{
				gotoxy(35,20);
				textcolor(5);
				printf("NOTA NAO FOI EXCLUIDA!!");
			}
		}
		else
		{
			Moldura(30,13,59,17,11,15,201,187,200,188);
			gotoxy(35,15);
			textcolor(4);
			printf("NOTA NAO ENCONTRADO!!");
		}
		Sleep(1000);
		LimpaLinha(8,20,28,98);
		gotoxy(25,8);
		textcolor(6);
		printf("Digite o R.A do Aluno que deseja excluir!!");
		gotoxy(30,11);
		textcolor(14);
		printf("R.A: ");
		fflush(stdin);
		textcolor(3);
		gets(AuxRA);
	}
}

void AlterarAL(TpAluno Al[TF],TpNota Notas[TF*2],int TL_Al,int TL_N)
{
	char AuxRA[13],AlterarRA[13],AuxNome[30],resp;
	int pos,bus;
	Fundo();
	textcolor(9);
	gotoxy(36,3);
	printf("### ALTERACAO DE ALUNOS ###");
	gotoxy(25,8);
	textcolor(4);
	printf("Digite o R.A do Aluno que deseja Alterar!!");
	gotoxy(28,11);
	textcolor(14);
	printf("R.A: ");
	fflush(stdin);
	textcolor(3);
	gets(AuxRA);
	while(strcmp(AuxRA,"\0")!=0)
	{
		pos=BuscaRA(Al,TL_Al,AuxRA);
		if(pos>=0)
		{
			gotoxy(34,13);
			textcolor(10);
			printf("R.A ENCONTRADO!!");
			gotoxy(30,15);
			textcolor(14);
			printf("R.A: ");
			textcolor(13);
			printf("%s",Al[pos].RA);
			gotoxy(50,15);
			textcolor(14);
			printf("Nome: ");
			textcolor(13);
			printf("%s",Al[pos].Nome);
			gotoxy(34,17);
			textcolor(2);
			printf("Deseja mesmo alterar?(S/N) ");
			fflush(stdin);
			scanf("%s",&resp);
			if(resp=='s' || resp=='S')
			{
				gotoxy(28,19);
				textcolor(14);
				printf("R.A: ");
				fflush(stdin);
				textcolor(3);
				gets(AlterarRA);
				bus=BuscaRA(Al,TL_Al,AlterarRA);
				if(bus==-1 || stricmp(AlterarRA,Al[pos].RA)==0)
				{
					strcpy(Al[pos].RA,AlterarRA);
					gotoxy(48,19);
					textcolor(14);
					printf("Nome: ");
					textcolor(3);
					fflush(stdin);
					gets(AuxNome);
					while(strcmp(AuxNome,"\0")==0)
					{
						gotoxy(48,19);
						textcolor(14);
						printf("Nome: ");
						textcolor(3);
						fflush(stdin);
						gets(AuxNome);
					}
					strcpy(Al[pos].Nome,AuxNome);
					bus=BuscaALN(Notas,TL_N,AuxRA);
					while(bus>=0)
					{
						strcpy(Notas[bus].RA,AlterarRA);
						bus=BuscaALN(Notas,TL_N,AuxRA);
					}
					gotoxy(34,22);
					textcolor(5);
					printf("ALUNO ALTERADO COM SUCESSO!!");
					
				}
				else
				{
					gotoxy(34,22); 
					textcolor(4);
					printf("Ja Existente!!");
				}
			}
			else
			{
				gotoxy(34,20);
				textcolor(5);
				printf("ALUNO NAO FOI ALTERADO!!");
			}
		}
		else
		{
			Moldura(30,13,58,17,11,15,201,187,200,188);
			gotoxy(35,15);
			textcolor(4);
			printf("R.A NAO ENCONTRADO!!");
		}
		Sleep(1000);
		LimpaLinha(10,20,28,98);
		gotoxy(28,11);
		textcolor(14);
		printf("R.A: ");
		fflush(stdin);
		textcolor(3);
		gets(AuxRA);
	}
	
}

void AlterarDisc(TpDisc Disc[TF],TpNota Notas[TF*2],int TL_D,int TL_N)
{
	char resp, AuxDesc[40];
	int pos,bus, AuxCod, AlterarCod;
	Fundo();
	textcolor(9);
	gotoxy(36,3);
	printf("### ALTERACAO DE DISCIPLINA ###");
	gotoxy(25,8);
	textcolor(4);
	printf("Digite o codigo da disciplina que deseja Alterar!!");
	gotoxy(44,9);
	textcolor(4);
	printf("(0 - para Sair)");
	gotoxy(28,11);
	textcolor(14);
	printf("Codigo: ");
	textcolor(3);
	scanf("%d",&AuxCod);
	while(AuxCod>0)
	{
		pos=BuscaDisc(Disc,TL_D,AuxCod);
		if(pos>=0)
		{
			gotoxy(34,13);
			textcolor(10);
			printf("DISCIPLINA ENCONTRADA!!");
			gotoxy(30,15);
			textcolor(14);
			printf("Codigo: ");
			textcolor(13);
			printf("%d",Disc[pos].CodDisc);
			gotoxy(45,15);
			textcolor(14);
			printf("Nome: ");
			textcolor(13);
			printf("%s",Disc[pos].Descr);
			gotoxy(34,17);
			textcolor(2);
			printf("Deseja mesmo alterar?(S/N) ");
			fflush(stdin);
			scanf("%s",&resp);
			if(resp=='s' || resp=='S')
			{
				gotoxy(30,19);
				textcolor(14);
				printf("Codigo: ");
				textcolor(3);
				scanf("%d",&AlterarCod);
				bus=BuscaDisc(Disc,TL_D,AlterarCod);
				if(bus==-1 || AlterarCod==AuxCod)
				{
					Disc[pos].CodDisc=AlterarCod;
					gotoxy(45,19);
					textcolor(14);
					printf("Nome: ");
					textcolor(3);
					fflush(stdin);
					gets(AuxDesc);
					while(strcmp(AuxDesc,"\0")==0)
					{
						gotoxy(45,19);
						textcolor(14);
						printf("Nome: ");
						textcolor(3);
						fflush(stdin);
						gets(AuxDesc);
					}
					bus=BuscaDescr(Disc,TL_D,AuxDesc);
					if(bus==-1 || stricmp(AuxDesc,Disc[pos].Descr)==0)
					{
						strcpy(Disc[pos].Descr,AuxDesc);
						pos=BuscaDiscN(Notas,TL_N,AuxCod);
						while(pos>=0)
						{
							Notas[pos].CodDisc=AlterarCod;
							pos=BuscaDiscN(Notas,TL_N,AuxCod);
						}
						gotoxy(34,22);
						textcolor(5);
						printf("DISCIPLINA ALTERADO COM SUCESSO!!");
					}
					else
					{
						gotoxy(34,22); 
						textcolor(4);
						printf("Ja Existente!!");
					}
				}
				else
				{
					gotoxy(34,22); 
					textcolor(4);
					printf("Ja Existente!!");
				}
			}
			else
			{
				gotoxy(34,20);
				textcolor(5);
				printf("DISCIPLINA NAO FOI ALTERADO!!");
			}
		}
		else
		{
			Moldura(30,13,65,17,11,15,201,187,200,188);
			gotoxy(35,15);
			textcolor(4);
			printf("DISCIPLINA NAO ENCONTRADO!!");
		}
		Sleep(1000);
		LimpaLinha(10,20,28,98);
		gotoxy(28,11);
		textcolor(14);
		printf("Codigo: ");
		textcolor(3);
		scanf("%d",&AuxCod);
	}
}

void AlterarNota(TpNota Notas[TF*2],TpAluno Al[TF], TpDisc Disc[TF],int TL,int TL_Al,int TL_D)
{
	char AuxRA[13],AlterarRA[13],resp;
	int pos,bus,AuxCod,AlterarCod;
	float AuxNota;
	Fundo();
	textcolor(9);
	gotoxy(36,3);
	printf("### ALTERACAO DE NOTA ###");
	gotoxy(25,8);
	textcolor(4);
	printf("Digite os dados que deseja Alterar!!");
	gotoxy(28,11);
	textcolor(14);
	printf("R.A: ");
	fflush(stdin);
	textcolor(3);
	gets(AuxRA);
	while(strcmp(AuxRA,"\0")!=0)
	{
		gotoxy(48,11);
		textcolor(14);
		printf("Codigo da Disciplina: ");
		textcolor(3);
		scanf("%d",&AuxCod);
		pos=BuscaNota(Notas,TL,AuxCod,AuxRA);
		if(pos>=0)
		{
			gotoxy(34,13);
			textcolor(10);
			printf("DADOS ENCONTRADO!!");
			gotoxy(30,15);
			textcolor(14);
			printf("R.A: ");
			textcolor(13);
			printf("%s",Notas[pos].RA);
			gotoxy(50,15);
			textcolor(14);
			printf("Disciplina: ");
			textcolor(13);
			printf("%d",Notas[pos].CodDisc);
			gotoxy(69,15);
			textcolor(14);
			printf("Nota: ");
			textcolor(13);
			printf("%.2f",Notas[pos].Nota);
			gotoxy(34,17);
			textcolor(2);
			printf("Deseja mesmo alterar?(S/N) ");
			fflush(stdin);
			scanf("%s",&resp);
			if(resp=='s' || resp=='S')
			{
				gotoxy(28,19);
				textcolor(14);
				printf("R.A: ");
				fflush(stdin);
				textcolor(3);
				gets(AlterarRA);
				bus=BuscaRA(Al,TL_Al,AlterarRA);
				if(bus>=0)
				{
					strcpy(Notas[pos].RA,AlterarRA);
					gotoxy(48,19);
					textcolor(14);
					printf("Codigo da Disc.: ");
					textcolor(3);
					scanf("%d",&AuxCod);
					bus=BuscaDisc(Disc,TL_D,AuxCod);
					if(bus>=0)
					{
						Notas[pos].CodDisc=AuxCod;
						gotoxy(70,19);
						textcolor(14);
						printf("Notas: ");
						textcolor(3);
						scanf("%f",&AuxNota);
						while(AuxNota<0 || AuxNota>10)
						{
							gotoxy(73,20);
							textcolor(4);
							printf("Nota invalida!!");
							Sleep(1000);
							LimpaLinha(19,70,20,98);
							gotoxy(70,19);
							textcolor(14);
							printf("Notas: ");
							textcolor(3);
							scanf("%f",&AuxNota);
						}
						Notas[pos].Nota=AuxNota;
						gotoxy(34,22);
						textcolor(5);
						printf("NOTA ALTERADA COM SUCESSO!!");
					}
					else
					{
						gotoxy(34,22); 
						textcolor(4);
						printf("Disciplins nao existente!!");
					}
				}
				else
				{
					gotoxy(34,22); 
					textcolor(4);
					printf("R.A nao existente!!");
				}
			}
			else
			{
				gotoxy(34,20);
				textcolor(5);
				printf("DADOS NAO FOI ALTERADO!!");
			}
		}
		else
		{
			Moldura(30,13,58,17,11,15,201,187,200,188);
			gotoxy(35,15);
			textcolor(4);
			printf("NOTA NAO ENCONTRADA!!");
		}
			Sleep(1000);
			LimpaLinha(10,20,28,98);
			gotoxy(28,11);
			textcolor(14);
			printf("R.A: ");
			fflush(stdin);
			textcolor(3);
			gets(AuxRA);
		}
		
}

void ConsultaAL(TpAluno Al[TF],int &TL)
{
	int i,c=15,l=7;
	Fundo();
	textcolor(4);
	gotoxy(36,3);
	printf("### CONSULTA DE ALUNOS ###");
	if(TL>0)
	{
		for(i=0;i<TL;i++)
		{
			gotoxy(c,l);
			textcolor(13);
			printf("R.A: ");
			textcolor(9);
			printf("%s",Al[i].RA);
			gotoxy(c+20,l);
			textcolor(13);
			printf("Nome: ");
			textcolor(9);
			printf("%s",Al[i].Nome);
			if(c==15)				
				c=60;
			else
			{
				c=15;
				l+=3;
			}	
			if(l>27)
			{
				getch();
				LimpaLinha(7,15,29,98);
				l=7;
			}
			
		}
	}
	else
	{
		Moldura(30,13,68,17,6,9,201,187,200,188);
		textcolor(10);
		gotoxy(33,15);
		printf("NAO HA NENHUM ALUNO CADASTRADO!!");
	}
	getch();
}

void ConsultaDisc(TpDisc Disc[TF],int &TL)
{
	int i,c=15,l=7;
	Fundo();
	textcolor(4);
	gotoxy(36,3);
	printf("### CONSULTA DE DISCIPLINA ###");
	if(TL>0)
	{
		for(i=0;i<TL;i++)
		{
			gotoxy(c,l);
			textcolor(13);
			printf("Codigo: ");
			textcolor(9);
			printf("%d",Disc[i].CodDisc);
			gotoxy(c+16,l);
			textcolor(13);
			printf("Nome: ");
			textcolor(9);
			printf("%s",Disc[i].Descr);
			if(c==15)				
				c=60;
			else
			{
				c=15;
				l+=3;
			}	
			if(l>27)
			{
				getch();
				LimpaLinha(7,15,29,98);
				l=7;
			}
			
		}
	}
	else
	{
		Moldura(30,13,74,17,6,9,201,187,200,188);
		textcolor(10);
		gotoxy(33,15);
		printf("NAO HA NENHUMA DISCIPLINA CADASTRADO!!");
	}
	getch();
}

void ConsultaNota(TpNota Notas[TF*2],int &TL)
{
	int i,c=3,l=7;
	Fundo();
	textcolor(4);
	gotoxy(36,3);
	printf("### CONSULTA DE NOTAS ###");
	if(TL>0)
	{
		for(i=0;i<TL;i++)
		{
			gotoxy(c,l);
			textcolor(13);
			printf("R.A: ");
			textcolor(9);
			printf("%s",Notas[i].RA);
			gotoxy(c+19,l);
			textcolor(13);
			printf("Disciplina: ");
			textcolor(9);
			printf("%d",Notas[i].CodDisc);
			gotoxy(c+36,l);
			textcolor(13);
			printf("Nota: ");
			textcolor(9);
			printf("%.2f",Notas[i].Nota);
			if(c==3)				
				c=53;
			else
			{
				c=3;
				l+=3;
			}	
			if(l>27)
			{
				getch();
				LimpaLinha(7,5,29,98);
				l=7;
			}
			
		}
	}
	else
	{
		Moldura(30,13,68,17,6,9,201,187,200,188);
		textcolor(10);
		gotoxy(33,15);
		printf("NAO HA NENHUMA NOTA CADASTRADO!!");
	}
	getch();
}

void OrdenarAl(TpAluno Al[TF],int TL)
{
	int i,t;
	char AuxNome[30],AuxRA[13];
	for(i=0;i<TL-1;i++)
		for(t=i+1;t<TL;t++)
			if(stricmp(Al[i].Nome,Al[t].Nome)>0)
			{
				strcpy(AuxNome,Al[i].Nome);
				strcpy(AuxRA,Al[i].RA);
				strcpy(Al[i].Nome,Al[t].Nome);
				strcpy(Al[i].RA,Al[t].RA);
				strcpy(Al[t].Nome,AuxNome);
				strcpy(Al[t].RA,AuxRA);
			}
}

void OrdenarDisc(TpDisc Disc[TF],int TL)
{
	int i,t,AuxCod,l;
	char AuxDescr[40];
	for(i=0;i<TL-1;i++)
		for(t=i+1;t<TL;t++)
			if(stricmp(Disc[i].Descr,Disc[t].Descr)>0)
			{
				strcpy(AuxDescr,Disc[i].Descr);
				AuxCod=Disc[i].CodDisc;
				strcpy(Disc[i].Descr,Disc[t].Descr);
				Disc[i].CodDisc=Disc[t].CodDisc;
				strcpy(Disc[t].Descr,AuxDescr);
				Disc[t].CodDisc=AuxCod;
			}
}

void OrdenarNota(TpNota Notas[TF*2],int TL)
{
	int i,t,AuxCod,l;
	float AuxNota;
	char AuxRA[13];
	for(i=0;i<TL-1;i++)
		for(t=i+1;t<TL;t++)
			if(stricmp(Notas[i].RA,Notas[t].RA)>0)
			{
				strcpy(AuxRA,Notas[i].RA);
				AuxCod=Notas[i].CodDisc;
				AuxNota=Notas[i].Nota;
				strcpy(Notas[i].RA,Notas[t].RA);
				Notas[i].CodDisc=Notas[t].CodDisc;
				Notas[i].Nota=Notas[t].Nota;
				strcpy(Notas[t].RA,AuxRA);
				Notas[t].CodDisc=AuxCod;
				Notas[t].Nota=AuxNota;
			}
}

void Reprovado(TpNota Notas[TF*2],TpAluno Al[TF],int TL, int TL_Al)
{
	TpReprovado Re[TF];
	int i,t,l=11,Cont_R,pos,TL_R=0;
	char AuxRA[13],AuxRAr[13];
	Fundo();
	textcolor(8);
	gotoxy(38,3);
	printf("### RELATORIO ###");
	gotoxy(30,8);
	textcolor(13);
	printf("ALUNOS REPROVADO EM 2 OU + DISCIPLINA");
	for(i=0;i<TL-1;i++)
	{
        Cont_R=0;
        if(Notas[i].Nota<6)
            Cont_R++;
        for (t=0; t<TL;t++)
			if(stricmp(Notas[i].RA,Notas[t].RA)==0)
	            if (Notas[t].Nota<6)
	                Cont_R++;
        if (Cont_R>=2)
		{
			strcpy(AuxRA,Notas[i].RA);
			strcpy(AuxRAr,AuxRA);
			if(BuscaRE(Re,TL_R,AuxRAr)==-1)
			{
				pos=BuscaRA(Al,TL_Al,AuxRA);
				gotoxy(32,l);
				textcolor(4);
		        printf("RA: %s Nome: %s \tquant.: %d", Notas[i].RA, Al[pos].Nome,Cont_R);
		        strcpy(Re[TL_R].RA,AuxRAr);
		        TL_R++;
		        l+=2;
			}
        }
    }
    getch();
}

void PalavraDisc(TpDisc Disc[TF], int TL, char Palavra[30])
{
	int i,l=12;
	Fundo();
	textcolor(8);
	gotoxy(38,3);
	printf("### RELATORIO ###");
	gotoxy(30,8);
	textcolor(12);
	printf("Disciplinas que contem o termo '%s':",Palavra);
		for(i=0;i<TL;i++)
			if(strstr(Disc[i].Descr, Palavra)!=0)
			{
				gotoxy(28,l);
				textcolor(13);
				printf("Codigo: ");
				textcolor(3);
				printf("%d",Disc[i].CodDisc);
				gotoxy(45,l);
				textcolor(13);
				printf("Disciplina: ");
				textcolor(3);
				printf("%s",Disc[i].Descr);
				l+=2;
			}
		if(l==12)
		{
			Moldura(25,12,75,18,13,0,201,187,200,188);
			gotoxy(30,15);
			textcolor(10);
			printf("## NAO EXISTE DISC. COM ESSA PALAVRA!! ##");
		}
	getch();
}

void DigitePa(TpDisc Disc[TF],int TL)
{
	char Palavra[30];
	Fundo();
	textcolor(8);
	gotoxy(38,3);
	printf("### RELATORIO ###");
	gotoxy(35,8);
	textcolor(10);
	printf("Procura de Disciplinas");
	gotoxy(26,12);
	textcolor(13);
	printf("Digite uma palavra: ");
	textcolor(4);
	fflush(stdin);
	gets(Palavra);
	if(strcmp(Palavra,"\0")!=0)
		PalavraDisc(Disc,TL,Palavra);
}

void LetraAl(TpAluno Al[TF],int TL,char Letra)
{
	int i,l=12;
	Fundo();
	textcolor(8);
	gotoxy(38,3);
	printf("### RELATORIO ###");
	gotoxy(30,8);
	textcolor(12);
	printf("Alunos que comecam com essa letra '%c':",Letra);
	for(i=0;i<TL;i++)
		if(toupper(Al[i].Nome[0])==toupper(Letra))
		{
			gotoxy(28,l);
			textcolor(13);
			printf("R.A: ");
			textcolor(3);
			printf("%s",Al[i].RA);
			gotoxy(49,l);
			textcolor(13);
			printf("Nome: ");
			textcolor(3);
			printf("%s",Al[i].Nome);
			l+=2;
		}
	if(l==12)
	{
		Moldura(25,12,75,18,13,0,201,187,200,188);
		gotoxy(30,15);
		textcolor(10);
		printf("## NAO EXISTE DISC. COM ESSA PALAVRA!! ##");
	}
	getch();
}

void DigiteLe(TpAluno Al[TF],int TL)
{
	char Letra;
	Fundo();
	textcolor(8);
	gotoxy(38,3);
	printf("### RELATORIO ###");
	gotoxy(35,8);
	textcolor(10);
	printf("Procura de Aluno");
	gotoxy(26,12);
	textcolor(13);
	printf("Digite uma letra: ");
	textcolor(4);
	fflush(stdin);
	scanf("%c",&Letra);
	LetraAl(Al,TL,Letra);
}

void DiscMedia(TpNota Notas[TF*2],TpDisc Disc[TF],int TL_N,int TL_D)
{
	TpMedia Me[TF];
	int i,t,Cont_N,l=11,pos,AuxCod,TL_M=0;
	float media,soma;
	Fundo();
	textcolor(8);
	gotoxy(38,3);
	printf("### RELATORIO ###");
	gotoxy(30,8);
	textcolor(13);
	printf("DISCIPLINA COM MEDIA ABAIXO DE 6");
	for(i=0;i<TL_N;i++)
	{
        soma=0;
        Cont_N=0;
        for(t=0;t<TL_N;t++)
        
				if(Notas[t].CodDisc==Notas[i].CodDisc)
	            {
	            	AuxCod=Notas[t].CodDisc;
					if(BuscaME(Me,TL_M,AuxCod)==-1)
					{
						soma=soma+Notas[t].Nota;
			            Cont_N++;
			            Me[TL_M].Cod=AuxCod;
			            TL_M++;
			        }
		        }
        media=(float) soma /Cont_N;
        if (media < 6.0)
		{
			AuxCod=Notas[i].CodDisc;
			pos=BuscaDisc(Disc,TL_D,AuxCod);
			gotoxy(28,l);
			textcolor(12);
            printf("Disciplina: ");
            textcolor(8);
			printf("%s",Disc[pos].Descr);
			gotoxy(56,l);
			textcolor(12);
			printf("Media: ");
			textcolor(8);
			printf("%.2f",media);
			l+=2;
        }
    }
	getch();	
}

void RelaGeral(TpAluno Al[TF], TpDisc Disc[TF],TpNota Notas[TF*2],int TL_Al,int TL_D,int TL_N)
{
	TpRelatorioG Geral[TF];
	int i,t,pos,l=8,AuxCod,TL_G=0;
	char AuxRAg[13],AuxRA[13];
	Fundo();
	textcolor(8);
	gotoxy(38,3);
	printf("### RELATORIO GERAL ###");
	for(i=0;i<TL_N;i++)
	{
		strcpy(AuxRAg,Notas[i].RA);
		if(BuscaGE(Geral,TL_G,AuxRAg)==-1)
		{
			
			strcpy(AuxRA,Notas[i].RA);
			strcpy(Geral[TL_G].RA,Notas[i].RA);
			TL_G++;
			pos=BuscaRA(Al,TL_Al,AuxRA);
			gotoxy(12,l);
			textcolor(5);
			printf("R.A: ");
			textcolor(14);
			printf("%s",Notas[i].RA);
			gotoxy(32,l++);
			textcolor(5);
			printf("Nome: ");
			textcolor(14);
			printf("%s",Al[pos].Nome);
			for(t=0;t<TL_N;t++)
			{
				if(strcmp(Notas[i].RA,Notas[t].RA)==0)
				{
					AuxCod=Notas[t].CodDisc;
					pos=BuscaDisc(Disc,TL_D,AuxCod);
					gotoxy(12,l);
					textcolor(5);
					printf("Disciplina: ");
					textcolor(14);
					printf("%d - %s",Notas[t].CodDisc,Disc[pos].Descr);
					textcolor(5);
					printf("\t\tNota: ");
					textcolor(14);
					printf("%.2f",Notas[t].Nota);
					textcolor(5);
					printf("\tSituacao: ");
					textcolor(14);
					if(Notas[t].Nota>=6)
						printf("Aprovado");
					else
						printf("Reprovado");
					l++;
				}
			}
			l+=2;
			if(l>=28)
			{
				getch();
				LimpaLinha(8,10,29,98);
				l=8;
			}
		}
	}
	getch();	
}
		
void ExecutarRelatorio(TpAluno Aluno[TF], TpDisc Disciplina[TF],TpNota Notas[TF*2],int &TL_Al,int &TL_D,int &TL_N)
{
	char OpcaoR;
	int tl_Al=TL_Al,tl_D=TL_D,tl_N=TL_N;
	system("cls");
	FundoMenu();
	OpcaoR=Relatorio();
	while(OpcaoR!=27)
	{
		switch(OpcaoR)
		{
			case 'A':
				//Reprovados em 2 ou +
				Reprovado(Notas,Aluno,tl_N,tl_Al);
				break;
			case 'B':
				//Aluno por letra
				DigiteLe(Aluno,tl_Al);
				break;
			case 'C':
				//Disciplina por palavra
				DigitePa(Disciplina,tl_D);	
				break;
			case 'D':
				//Disc. media < 6
				DiscMedia(Notas,Disciplina,tl_N,tl_D);
				break;
			case 'E':
				//Relatorio Geral
				RelaGeral(Aluno,Disciplina,Notas,tl_Al,tl_D,tl_N);
				break;
		}
		system("cls");
		FundoMenu();
		OpcaoR=Relatorio();
	}
}

void Executar()
{
	char Opcao;
	TpAluno Aluno[TF];
	TpDisc Disciplina[TF];
	TpNota Notas[TF*2];
	int TL_Al=0, TL_D=0, TL_N=0;
	Opcao=Menu();
	while(Opcao!=27)
	{
		switch(Opcao)
		{
			case 'A':
				CadastroRA(Aluno,TL_Al);
				break;
			case 'B':
				CadastroDisc(Disciplina,TL_D);
				break;
			case 'C':
				CadastroNotas(Notas,Aluno,Disciplina,TL_N,TL_Al,TL_D);
				break;
			case 'D':
				CadastroAutom(Aluno,Disciplina,Notas,TL_Al,TL_D,TL_N);
				break;
			case 'E':
				ExclusaoAL(Aluno,Notas,TL_Al,TL_N);
				break;
			case 'F':
				ExclusaoDisc(Disciplina,Notas,TL_D,TL_N);
				break;
			case 'G':
				ExclusaoNotas(Notas,TL_N);
				break;
			case 'H':
				AlterarAL(Aluno,Notas,TL_Al,TL_N);
				break;
			case 'I':
				AlterarDisc(Disciplina,Notas,TL_D,TL_N);
				break;
			case 'J':
				AlterarNota(Notas,Aluno,Disciplina,TL_D,TL_Al,TL_D);
				break;
			case 'K':
				ConsultaAL(Aluno,TL_Al);
				break;
			case 'L':
				ConsultaDisc(Disciplina,TL_D);
				break;
			case 'M':
				ConsultaNota(Notas,TL_N);
				break;
			case 'N':
				ExecutarRelatorio(Aluno,Disciplina,Notas,TL_Al,TL_D,TL_N);
				break;
		}
		OrdenarAl(Aluno,TL_Al);
		OrdenarDisc(Disciplina,TL_D);
		OrdenarNota(Notas,TL_N);
		system("cls");
		FundoMenu();
		Opcao=Menu();
	}
}

int main(void)
{
	FundoMenu();
	Executar();
	return 0;
}
