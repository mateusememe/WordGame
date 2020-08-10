/*
	Desenvolvido por Mateus Mendonça Monteiro RA: 10.191.159-9
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio2.h>

//Constantes de Cores para facilitar a definicao das mesmas
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GREY 8
#define LBLUE 9
#define LGREEN 10
#define LAQUA 11
#define LRED 12
#define LILAC 13
#define LYELLOW 14
#define LWHITE 15


//Structs
struct TpPlayer{
	char login[25], Nome[30];
	int Pontos;
	char DataEntrada[10], DataUltAcesso[10];	
};

struct TpBancoPalavras{
	char Palavra[25];
	int quant;
};

struct TpJogo{
	char login[25], Palavra[25];
};
struct TpDicionario{
	char Portugues[25], Ingles[25], Significado[100];
	int Pontos;
};

//Funções de Interface
void put_on_xy(int x, int y, char charstring[])
{
    gotoxy(x,y);
    puts(charstring);
    x += strlen(charstring);
    gotoxy(x,y);
}

void put_on_xy(char letra, int x, int y)
{
    gotoxy(x,y);
    printf("%c",letra);
}

void clear(){
	system("cls");
}

char getLowChar(){
	fflush(stdin);
	return getche();
}

char getUpChar(){
	fflush(stdin);
    return toupper(getche());
}

void getStr(char str[]){
	fflush(stdin);
	gets(str);
}

void limpaMoldPlayer()
{
	for(int l = 9; l < 16; l++)
		for(int c = 25; c < 61; c++)
			put_on_xy(' ',c,l);
}

void MolduraMenorPlayers()
{
	int i,j;
	//bordasMenuSup
	for(j=24; j<61; j++)
		put_on_xy(205,j,8);	
	
	//bordasMenuInf
	for(i=24;i<61;i++)
		put_on_xy(205,i,16);
	
	//lateral
	for(i=8;i<16;i++)	
	{
		put_on_xy(186,23,i);
		put_on_xy(186,60,i); 
	}
	put_on_xy(201,23,8);
	put_on_xy(187,60,8);
	put_on_xy(200,23,16);
	put_on_xy(188,60,16);
}

void MolduraMenorDic()
{
	int i,j;
	//bordasMenuSup
	for(j=22; j<77; j++)
		put_on_xy(205,j,5);	
	
	//bordasMenuInf
	for(i=22;i<76;i++)
		put_on_xy(205,i,22);
	
	//lateral
	for(i=5;i<22;i++)	
	{
		put_on_xy(186,22,i);
		put_on_xy(186,76,i); 
	}
	put_on_xy(201,22,5);
	put_on_xy(187,76,5);
	put_on_xy(200,22,22);
	put_on_xy(188,76,22);
}

void drawScreen(int cor)
{
	int i, CI = 1,LI = 1,CF = 80,LF = 25; 
	textcolor(cor);
	put_on_xy(201,CI,LI);
	put_on_xy(188,CF,LF);
	put_on_xy(187,CF,LI); 
	put_on_xy(200,CI,LF); 
	
	for(i=CI+1;i<CF;i++)
	{
		put_on_xy(205,i,LI); 
		Sleep(1);
		put_on_xy(205,i,LF);
	}
	
	for(i=LI+1;i<LF;i++)
	{
		put_on_xy(186,CI,i); 
		Sleep(1);
		put_on_xy(186,CF,i);
		
	}
}

void Moldura(int cor)
{

	int i, CI = 1,LI = 1,CF = 80,LF = 25; 
	textcolor(cor);
	put_on_xy(201,CI,LI);
	put_on_xy(188,CF,LF);
	put_on_xy(187,CF,LI); 
	put_on_xy(200,CI,LF); 
	
	for(i=CI+1;i<CF;i++)
	{
		put_on_xy(205,i,LI); 
		Sleep(1);
		put_on_xy(205,i,LF);
	}
	
	for(i=LI+1;i<LF;i++)
	{
		put_on_xy(186,CI,i); 
		Sleep(1);
		put_on_xy(186,CF,i);
		
	}
}

void Moldura(int cor, int CI,int CF, int LI, int LF)
{
    system("cls");
	int i;
	textcolor(cor);
	put_on_xy(201,CI,LI);
	put_on_xy(188,CF,LF);
	put_on_xy(187,CF,LI); 
	put_on_xy(200,CI,LF); 
	
	for(i=CI+1;i<CF;i++)
	{
		put_on_xy(205,i,LI); 
		Sleep(1);
		put_on_xy(205,i,LF);
	}
	
	for(i=LI+1;i<LF;i++)
	{
		put_on_xy(186,CI,i); 
		Sleep(1);
		put_on_xy(186,CF,i);
		
	}
}

void MoldLow(char str[],int cor,int CI,int CF, int LI, int LF){
    clear();
    Moldura(cor,CI,CF,LI,LF);
    int x = (((CF-CI) - strlen(str))/2) + CI;
            
    put_on_xy(x,LI,str);
}

void clsInside(int cor, char str[]){
    system("cls");
    drawScreen(cor);    
    int x = (80 - strlen(str))/2;
    put_on_xy(x,1,str);
    textcolor(LWHITE);
}

void infoExitScreen(){
    textcolor(LRED);
    put_on_xy(33,24,"Aperte [Esc] para voltar ao menu");
    textcolor(LWHITE);
    gotoxy(79,24);
}

void putOnMidX(int y,char str[]){
    int x = (80 - strlen(str)) / 2;
    put_on_xy(x,y,str);
}

void ExibeTitleRelat(char str[]){
    clear();
    textcolor(WHITE);
    for(int i=1;i<80;i++)
	{
		put_on_xy(205,i,1); 
		Sleep(1);
	}
    putOnMidX(1,str);
}

//Prototipos
void execute();
int BuscaPalavra(FILE *PtrDic, char Elem[]);
int BBIngles(FILE *PtrDic, char Elem[]); 
void OrdenaDicionarioIngles(char NomeArq[]); 

//Dicionario
void getData(char str[10]){
   time_t mytime;
   mytime = time(NULL);

   char aux[2];
   struct tm tm = *localtime(&mytime);

   //Dia
   itoa(tm.tm_mday,aux,10);
   strcpy(str,aux);
   strcat(str,"/");

   //Mes
   itoa((tm.tm_mon + 1),aux,10);
   strcat(str,aux);
   strcat(str,"/");

   //Ano
   itoa((tm.tm_year + 1900),aux,10);
   strcat(str,aux);
}

int BBIngles(FILE *PtrDic, char Elem[]){
	TpDicionario Reg;
	fseek(PtrDic,0,2);
	int I = 0, M, F = ftell(PtrDic) / sizeof(TpDicionario) - 1;
	M = F/2;
	
	fseek(PtrDic,M*sizeof(TpDicionario),0);
	fread(&Reg,sizeof(TpDicionario),1,PtrDic);
	
	while(I < F && stricmp(Reg.Ingles,Elem) != 0){
		
		if(stricmp(Elem,Reg.Ingles) > 0)
			I = M + 1;
		else
			F = M - 1;
		
		M = (I+F)/2;
		fseek(PtrDic,M*sizeof(TpDicionario),0);
		fread(&Reg,sizeof(TpDicionario),1,PtrDic);
	}
	if(stricmp(Reg.Ingles,Elem) == 0){
		return M * sizeof(TpDicionario);
	}
	else
		return -1;
}
	
void OrdenaDicionarioIngles(char NomeArq[]){//Bubble Sort

	int i, j, QtdeReg;
	TpDicionario RegI, RegJ;
	FILE *PtrDic = fopen(NomeArq,"rb+");

	fseek(PtrDic,0,2);

	QtdeReg = ftell(PtrDic) / sizeof(TpDicionario);

	for (i = 0; i < QtdeReg-1; i++)
		for(j = i+1; j<QtdeReg; j++)
		{	
			fseek(PtrDic,i*sizeof(TpDicionario),0);
			fread(&RegI,sizeof(TpDicionario),1,PtrDic);

			fseek(PtrDic,j*sizeof(TpDicionario),0);
			fread(&RegJ,sizeof(TpDicionario),1,PtrDic);

			if(stricmp(RegI.Ingles,RegJ.Ingles) > 0)
			{
				fseek(PtrDic,i*sizeof(TpDicionario),0);
				fwrite(&RegJ,sizeof(TpDicionario),1,PtrDic);
				fseek(PtrDic,j*sizeof(TpDicionario),0);
				fwrite(&RegI,sizeof(TpDicionario),1,PtrDic);
			}
		}
	fclose(PtrDic);
}

void OrdenaDicionarioPT(char NomeArq[]){//Bubble Sort

	int i, j, QtdeReg;
	TpDicionario RegI, RegJ;
	FILE *PtrDic = fopen(NomeArq,"rb+");
	MoldLow(">> Ordenar Dicionario Portugues <<",WHITE,10,74,5,12);
	put_on_xy(12,7,"Para Ordenar o Dicionario em Portugues aperte qualquer Tecla");
	getch();
	fseek(PtrDic,0,2);
	MoldLow(">> Ordenar Dicionario Portugues <<",WHITE,10,74,5,12);
	put_on_xy(30,8,"Ordenando Dicionario...");
	Sleep(750);
	QtdeReg = ftell(PtrDic) / sizeof(TpDicionario);

	for (i = 0; i < QtdeReg-1; i++)
		for(j = i+1; j<QtdeReg; j++)
		{	
			fseek(PtrDic,i*sizeof(TpDicionario),0);
			fread(&RegI,sizeof(TpDicionario),1,PtrDic);

			fseek(PtrDic,j*sizeof(TpDicionario),0);
			fread(&RegJ,sizeof(TpDicionario),1,PtrDic);

			if(stricmp(RegI.Portugues,RegJ.Portugues) > 0)
			{
				fseek(PtrDic,i*sizeof(TpDicionario),0);
				fwrite(&RegJ,sizeof(TpDicionario),1,PtrDic);
				fseek(PtrDic,j*sizeof(TpDicionario),0);
				fwrite(&RegI,sizeof(TpDicionario),1,PtrDic);
			}
		}
	MoldLow(">> Ordenar Dicionario Portugues <<",WHITE,10,74,5,12);
	put_on_xy(30,11,"// Dicionario Ordenado! //");~
	getch();
	fclose(PtrDic);
}

int BuscaPalavra(FILE *PtrDic, char Palavra[25]){//Busca Exaustiva
	TpDicionario R;
	rewind(PtrDic);
	fread(&R,sizeof(TpDicionario),1,PtrDic);
	while(!feof(PtrDic) && stricmp(Palavra,R.Portugues)!=0)
			fread(&R,sizeof(TpDicionario),1,PtrDic);
	
	if(!feof(PtrDic))
      return ftell(PtrDic) - sizeof(TpDicionario);
    else
      return -1;
}

void CadDicionario(char NomeArq[])
{
	TpDicionario RegDic;
	FILE *PtrDic = fopen(NomeArq,"ab+");
	
	MoldLow(">> Cadastro Palavras <<",WHITE,10,70,5,20);
	put_on_xy(20,8,"Palavra em Portugues: ");
	getStr(RegDic.Portugues);
	while (strcmp(RegDic.Portugues,"\0")!=0)
	{
		if (BuscaPalavra(PtrDic,RegDic.Portugues)==-1)  //NÃ£o encontramos a Palavra
		{
			put_on_xy(20,9,"Palavra em Ingles: ");
			getStr(RegDic.Ingles);
			put_on_xy(20,10,"Significado da Palavra: ");
			gotoxy(21,11);
			getStr(RegDic.Significado);
			RegDic.Pontos = (rand()%3+1) * 10;
			gotoxy(20,12); printf("Pontuacao da Palavra: %d",RegDic.Pontos);
			fwrite(&RegDic,sizeof(TpDicionario),1,PtrDic);
			gotoxy(15,14);printf("Palavra \"%s\" registrada!",RegDic.Portugues);
			getch();
		}
		else{
			MoldLow(">> Cadastro Palavras <<",WHITE,10,70,5,20);
			put_on_xy(25,12,"Palavra em Portugues ja CADASTRADA!");
			getch();
		}
		MoldLow(">> Cadastro Palavras <<",WHITE,10,70,5,20);
		put_on_xy(20,8,"Palavra em Portugues: ");
		getStr(RegDic.Portugues);
	}
	fclose(PtrDic);
}

void RelDicionario(char NomeArq[])
{
	TpDicionario RegDic;
	FILE *PtrDic = fopen(NomeArq,"rb");
	ExibeTitleRelat(">> CONTEUDO DICIONARIO <<");
	int x = 4;
	textcolor(GREEN);
	put_on_xy(2,3,"Portugues        ");
	put_on_xy(20,3,"Ingles        ");
	put_on_xy(35,3,"Pontos  ");
	put_on_xy(44,3,"Significado");
	textcolor(LWHITE);
	fread(&RegDic,sizeof(TpDicionario),1,PtrDic);
	if (feof(PtrDic)){
		put_on_xy(25,12,"Nao ha Palavras Cadastradas!");
		getch();
	} 
    else{
		while (!feof(PtrDic)){
			put_on_xy(2,x,RegDic.Portugues);
			put_on_xy(20,x,RegDic.Ingles);
			gotoxy(35,x); printf("%d",RegDic.Pontos);
			put_on_xy(44,x,RegDic.Significado);
			fread(&RegDic,sizeof(TpDicionario),1,PtrDic);
			x++;
		}    
    }
	for(int i=1;i<80;i++){
		put_on_xy(205,i,x+1); 
		Sleep(1);
	}

	putOnMidX(x+1,"# # #  Fim do Dicionario  # # #");
	getch();
	fclose(PtrDic);
}

void ConsDicionario(char NomeArq[])
{
	TpDicionario RegDic;
	int pos;
	FILE *PtrDic = fopen(NomeArq,"rb");
	MoldLow(">> Consulta Palavras Portugues <<",WHITE,10,70,5,20);
	put_on_xy(12,7,"Palavra em Portugues: ");
	getStr(RegDic.Portugues);
	while (strcmp(RegDic.Portugues,"\0")!=0)
	{
		pos = BuscaPalavra(PtrDic,RegDic.Portugues);
		if (pos==-1){
			MoldLow(">> Consulta Palavras Portugues <<",WHITE,10,70,5,20);
			put_on_xy(12,7,"Palavra NAO encontrada!"); getch();
		}
		else {
			MoldLow(">> DADOS ENCONTRADOS <<",WHITE,10,70,5,20);
			fseek(PtrDic,pos,0);     //Posicionar o PtrDic			   
			fread(&RegDic,sizeof(TpDicionario),1,PtrDic);   //Ler conteudo ... carregar qtde bytes em RegDic
			gotoxy(12,8); printf("Portugues: %s",RegDic.Portugues);
			gotoxy(12,9); printf("Ingles: %s",RegDic.Ingles);
			gotoxy(12,10);printf("Pontos: %d",RegDic.Pontos);
			gotoxy(12,11);printf("Significado:");
			gotoxy(12,12);printf("%s",RegDic.Significado);
			getch();
		}
		MoldLow(">> Consulta Palavras Portugues  <<",WHITE,10,70,5,20);
		put_on_xy(12,7,"Palavra em Portugues: ");
		getStr(RegDic.Portugues);
	}
	fclose(PtrDic);
}

void AltDicionario(char NomeArq[])
{
	TpDicionario RegDic;
	int pos;
	FILE *PtrDic = fopen(NomeArq,"rb+");
	MoldLow(">> Altera Palavras Dicionario <<",WHITE,10,70,5,20);
	put_on_xy(12,7,"Palavra em Portugues: ");
	
	getStr(RegDic.Portugues);
	while (strcmp(RegDic.Portugues,"\0")!=0)
	{
		pos = BuscaPalavra(PtrDic,RegDic.Portugues);

		if (pos==-1){//NÃ£o encontramos a Palavra
			MoldLow(">> Altera Palavras Dicionario <<",WHITE,10,70,5,20);
			put_on_xy(12,7,"Palavra NAO encontrada!"); getch();
		}    
		else{
            MoldLow(">> DADOS ENCONTRADOS <<",WHITE,10,70,5,20);
            fseek(PtrDic,pos,0);     //Posicionar o PtrDic			   
            fread(&RegDic,sizeof(TpDicionario),1,PtrDic);   //Ler conteÃºdo ... carregar qtde bytes em RegDic
            gotoxy(12,8); printf("Portugues: %s",RegDic.Portugues);
			gotoxy(12,9); printf("Ingles: %s",RegDic.Ingles);
			gotoxy(12,10);printf("Pontos: %d",RegDic.Pontos);
			gotoxy(12,11);printf("Significado:");
			gotoxy(12,12);printf("%s",RegDic.Significado);
            put_on_xy(12,14,"Deseja Alterar (S/N)? ");
            if (getUpChar() == 'S')
            {
				MoldLow(">> ALTERACAO <<",WHITE,10,70,5,20);
                put_on_xy(12,8,"NOVA Palavra em Ingles: ");
                getStr(RegDic.Ingles);
                put_on_xy(12,9,"NOVA Pontuacao: ");
                scanf("%d",&RegDic.Pontos);
                put_on_xy(12,10,"NOVO Significado: ");
                gotoxy(12,11);
                getStr(RegDic.Significado);
                fseek(PtrDic,pos,0);
                fwrite(&RegDic,sizeof(TpDicionario),1,PtrDic);
                put_on_xy(18,13,"// Palavra ALTERADA corretamente! //");
				getch();
            }
			else{
				MoldLow(">> Altera Palavras Dicionario <<",WHITE,10,70,5,20);
				put_on_xy(30,11,"Alteracao Cancelada!");	
				Sleep(750);	
			}	
		}
		MoldLow(">> Altera Palavras Dicionario <<",WHITE,10,70,5,20);
		put_on_xy(12,7,"Palavra em Portugues: ");
		getStr(RegDic.Portugues);
	}
	fclose(PtrDic);
}
 
void ExclusaoFisicaDicionario(char NomeArq[])
{
	//Exclusao Logica Fazer dps (Definir somente o status como 1) 
	//porem quando utilizar a palavra ja, tmb definir como 0  
	TpDicionario RegDic;
	int pos;
	char AuxPalavra[25];
	FILE *PtrDic = fopen(NomeArq,"rb");
	MoldLow(">> Excluir Fisicamente Registro no Dicionario <<",WHITE,10,70,5,20);
	put_on_xy(12,7,"Palavra em Portugues: ");	
	getStr(AuxPalavra);

	if(strcmp(AuxPalavra,"\0")!=0)
	{
		pos = BuscaPalavra(PtrDic,AuxPalavra);
		if (pos==-1)          //Nao encontramos a Palavra
		{
			MoldLow(">> Excluir Fisicamente Registro no Dicionario <<",WHITE,10,70,5,20);
			put_on_xy(12,7,"Palavra NAO encontrada!");	
			getch();
			fclose(PtrDic);
		}
		else{
			MoldLow(">> DADOS ENCONTRADOS <<",WHITE,10,70,5,20);
			fseek(PtrDic,pos,0);     //Posicionar o PtrDic			   
			fread(&RegDic,sizeof(TpDicionario),1,PtrDic);   //Ler conteudo ... carregar qtde bytes em RegDic
			gotoxy(12,8); printf("Portugues: %s",RegDic.Portugues);
			gotoxy(12,9); printf("Ingles: %s",RegDic.Ingles);
			gotoxy(12,10);printf("Pontos: %d",RegDic.Pontos);
			gotoxy(12,11);printf("Significado:");
			gotoxy(12,12);printf("%s",RegDic.Significado);
			put_on_xy(12,14,"Confirma Exclusao (S/N)? ");

			if (getUpChar()=='S'){
				FILE *PtrTemp  = fopen("Temp.dat","wb");
				rewind(PtrDic); 		//fseek(PtrTemp,0,0);
				fread(&RegDic,sizeof(TpDicionario),1,PtrDic);
				while (!feof(PtrDic)){
					//Grava todo o arq anterior, menos a palavra a ser excluida
					if(strcmp(AuxPalavra,RegDic.Portugues) != 0)
						fwrite(&RegDic,sizeof(TpDicionario),1,PtrTemp);
					fread(&RegDic,sizeof(TpDicionario),1,PtrDic);
				}
				fclose(PtrDic);
				fclose(PtrTemp);
				remove(NomeArq);
				rename("Temp.dat",NomeArq);
				MoldLow(">> Excluir Fisicamente Registro no Dicionario <<",WHITE,10,70,5,20);
				put_on_xy(18,11,"// Registro Deletado corretamente! //");
				getch();
			}
			else{
				MoldLow(">> Excluir Fisicamente Registro no Dicionario <<",WHITE,10,70,5,20);
				put_on_xy(30,11,"Exclusao Cancelada!");	
				fclose(PtrDic);
				getch();
			}	
		}
		Sleep(200);
	}
	else
		fclose(PtrDic);
	
}

void ConsultPalavraIngles(char NomeArq[]){
	TpDicionario RegDic;
	int pos;
	FILE *PtrDic = fopen(NomeArq,"rb");
	
	MoldLow(">> Consulta Palavras Ingles <<",WHITE,10,70,5,20);
	put_on_xy(12,7,"Palavra em Ingles: ");
	getStr(RegDic.Ingles);
	while (strcmp(RegDic.Ingles,"\0")!=0)
	{
		pos = BBIngles(PtrDic,RegDic.Ingles); //BinarySearch
		if (pos==-1){         //Nao encontramos a Palavra
		    MoldLow(">> Consulta Palavras Ingles <<",WHITE,10,70,5,20);
			put_on_xy(12,7,"Palavra NAO encontrada!"); getch();
		} 
		else {
			MoldLow(">> DADOS ENCONTRADOS <<",WHITE,10,70,5,20);
			fseek(PtrDic,pos,0);     //Posicionar o PtrDic			   
			fread(&RegDic,sizeof(TpDicionario),1,PtrDic);   //Ler conteÃºdo ... carregar qtde bytes em RegDic
			gotoxy(12,8); printf("Portugues: %s",RegDic.Portugues);
			gotoxy(12,9); printf("Ingles: %s",RegDic.Ingles);
			gotoxy(12,10);printf("Pontos: %d",RegDic.Pontos);
			put_on_xy(12,11,"Significado:");
			gotoxy(12,12);printf("%s",RegDic.Significado);
			getch();
		}
		MoldLow(">> Consulta Palavras Ingles <<",WHITE,10,70,5,20);
		put_on_xy(12,7,"Palavra em Ingles: ");
		getStr(RegDic.Ingles);
	}
	fclose(PtrDic);
}

//Jogador
int BBLogin(FILE *PtrPlay, char Login[]){ //Busca Binaria
	TpPlayer Reg;
	fseek(PtrPlay,0,2);
	int I = 0, M, F = ftell(PtrPlay) / sizeof(TpPlayer) - 1;
	M = F/2;
	
	fseek(PtrPlay,M*sizeof(TpPlayer),0);
	fread(&Reg,sizeof(TpPlayer),1,PtrPlay);
	
	while(I < F && stricmp(Reg.login,Login) != 0){
		
		if(stricmp(Login,Reg.login) > 0)
			I = M + 1;
		else
			F = M - 1;
		
		M = (I+F)/2;
		fseek(PtrPlay,M*sizeof(TpPlayer),0);
		fread(&Reg,sizeof(TpPlayer),1,PtrPlay);
	}
	if(stricmp(Reg.login,Login) == 0){
		return M * sizeof(TpPlayer);
	}
	else
		return -1;
}

int IndexLogin(FILE *ptrPlay,char login[]){ //Busca Sequencial Indexada
    TpPlayer R;
    rewind(ptrPlay);

    fread(&R,sizeof(TpPlayer),1,ptrPlay);
    while(!feof(ptrPlay) && stricmp(login,R.login) > 0)
        fread(&R,sizeof(TpPlayer),1,ptrPlay);

    //Retorna a posicao na onde achou a palavra
    if(!feof(ptrPlay) && stricmp(login,R.login) == 0)
        return ftell(ptrPlay) - sizeof(TpPlayer);
    else
        return -1;
}

int ExhaustiveLogin(FILE *PtrPlay, char Login[25]){//Busca Exaustiva
	TpPlayer R;
	rewind(PtrPlay);
	fread(&R,sizeof(TpPlayer),1,PtrPlay);
	while(!feof(PtrPlay) && stricmp(Login,R.login)!=0)
			fread(&R,sizeof(TpPlayer),1,PtrPlay);
	
	if(!feof(PtrPlay))
      return ftell(PtrPlay) - sizeof(TpPlayer);
    else
      return -1;
}

void OrdenaJogadoresLogin(char NomeArq[]){
	int i, j, QtdeReg;
	TpPlayer RegI, RegJ;
	FILE *PtrDic = fopen(NomeArq,"rb+");
	
	fseek(PtrDic,0,2);

	QtdeReg = ftell(PtrDic) / sizeof(TpPlayer);

	for (i = 0; i < QtdeReg-1; i++)
		for(j = i+1; j<QtdeReg; j++)
		{	
			fseek(PtrDic,i*sizeof(TpPlayer),0);
			fread(&RegI,sizeof(TpPlayer),1,PtrDic);
			

			fseek(PtrDic,j*sizeof(TpPlayer),0);
			fread(&RegJ,sizeof(TpPlayer),1,PtrDic);

			if(stricmp(RegI.login,RegJ.login) > 0)
			{
				fseek(PtrDic,i*sizeof(TpPlayer),0);
				fwrite(&RegJ,sizeof(TpPlayer),1,PtrDic);
				fseek(PtrDic,j*sizeof(TpPlayer),0);
				fwrite(&RegI,sizeof(TpPlayer),1,PtrDic);
			}
		}
	fclose(PtrDic);
}

void OrdenaJogadoresPontos(char NomeArq[]){ //Bubble Sort //Fazer um selection sort...

	int i, j, QtdeReg;
	TpPlayer RegI, RegJ;
	FILE *PtrDic = fopen(NomeArq,"rb+");
	
	fseek(PtrDic,0,2);

	QtdeReg = ftell(PtrDic) / sizeof(TpPlayer);

	for (i = 0; i < QtdeReg-1; i++)
		for(j = i+1; j<QtdeReg; j++)
		{	
			fseek(PtrDic,i*sizeof(TpPlayer),0);
			fread(&RegI,sizeof(TpPlayer),1,PtrDic);

			fseek(PtrDic,j*sizeof(TpPlayer),0);
			fread(&RegJ,sizeof(TpPlayer),1,PtrDic);

			if(RegI.Pontos < RegJ.Pontos)
			{
				fseek(PtrDic,i*sizeof(TpPlayer),0);
				fwrite(&RegJ,sizeof(TpPlayer),1,PtrDic);
				fseek(PtrDic,j*sizeof(TpPlayer),0);
				fwrite(&RegI,sizeof(TpPlayer),1,PtrDic);
			}
		}
	fclose(PtrDic);
}

void OrdenaJogadoresNome(char NomeArq[]){ //Bubble Sort //Fazer um selection sort...

	int i, j, QtdeReg;
	TpPlayer RegI, RegJ;
	FILE *PtrDic = fopen(NomeArq,"rb+");
	ExibeTitleRelat(">> ORDENAR JOGADORES PELO NOME <<");
	put_on_xy(40,10,"Ordenando Jogadores...");
	Sleep(750);
	fseek(PtrDic,0,2);

	QtdeReg = ftell(PtrDic) / sizeof(TpPlayer);

	for (i = 0; i < QtdeReg-1; i++)
		for(j = i+1; j<QtdeReg; j++)
		{	
			fseek(PtrDic,i*sizeof(TpPlayer),0);
			fread(&RegI,sizeof(TpPlayer),1,PtrDic);

			fseek(PtrDic,j*sizeof(TpPlayer),0);
			fread(&RegJ,sizeof(TpPlayer),1,PtrDic);

			if(stricmp(RegI.Nome,RegJ.Nome) > 0)
			{
				fseek(PtrDic,i*sizeof(TpPlayer),0);
				fwrite(&RegJ,sizeof(TpPlayer),1,PtrDic);
				fseek(PtrDic,j*sizeof(TpPlayer),0);
				fwrite(&RegI,sizeof(TpPlayer),1,PtrDic);
			}
		}
	ExibeTitleRelat(">> RELATORIO GERAL: PALAVRAS E JOGADORES <<");
	put_on_xy(40,12,"Jogadores Ordenados :) ");
	getch();
	fclose(PtrDic);
}

void insDireta(FILE *PtrPlay){ //Insertion Sort

	TpPlayer RegA, RegB;
	
	fseek(PtrPlay,0,2);

	int QtdeReg = ftell(PtrPlay) / sizeof(TpPlayer);
	
	fseek(PtrPlay,(QtdeReg-2)*sizeof(TpPlayer),0);
	fread(&RegB,sizeof(TpPlayer),1,PtrPlay);	
	fread(&RegA,sizeof(TpPlayer),1,PtrPlay);
	

	while (QtdeReg > 1 && stricmp(RegA.login,RegB.login) < 0){
		fseek(PtrPlay,(QtdeReg-2)*sizeof(TpPlayer),0);

		fwrite(&RegA,sizeof(TpPlayer),1,PtrPlay);
		fwrite(&RegB,sizeof(TpPlayer),1,PtrPlay);

		QtdeReg--;
		if(QtdeReg > 1){
			fseek(PtrPlay,(QtdeReg-2)*sizeof(TpPlayer),0);
			fread(&RegB,sizeof(TpPlayer),1,PtrPlay);	
			fread(&RegA,sizeof(TpPlayer),1,PtrPlay);
		}
	}
}

void CadJogador(char NomeArq[]){
	TpPlayer Player;
	FILE *PtrPlay = fopen(NomeArq,"rb+");

	
	MoldLow(">> Cadastrar Jogador <<",WHITE,20,70,5,18);
	put_on_xy(24,8,"Digite o seu Login: ");
	getStr(Player.login);
	while (strcmp(Player.login,"\0") != 0){
		if(BBLogin(PtrPlay,Player.login) == -1){
			put_on_xy(24,9,"Digite o seu Nome: ");
			getStr(Player.Nome);
			Player.Pontos = 0;
			getData(Player.DataEntrada);
			getData(Player.DataUltAcesso);
			gotoxy(24,10); printf("Data de Entrada: %s",Player.DataEntrada);
			fseek(PtrPlay,0,2);
			fwrite(&Player,sizeof(TpPlayer),1,PtrPlay);
			insDireta(PtrPlay);	
			gotoxy(24,12); printf("// Jogador %s Cadastrado //",Player.login);
			getch();
		}
		else{
			MoldLow(">> Cadastrar Jogador <<",WHITE,20,70,5,18);
			put_on_xy(34,15,"Login ja cadastrado!");
			getch();
		}
		MoldLow(">> Cadastrar Jogador <<",WHITE,20,70,5,18);
		put_on_xy(24,8,"Digite o seu Login: ");
		getStr(Player.login);
	}
	
	fclose(PtrPlay);
}

void RelJogador(char NomeArq[])
{
	TpPlayer RegPlay;
	FILE *PtrPlay = fopen(NomeArq,"rb");
	ExibeTitleRelat(">> JOGADORES CADASTRADOS <<");
	int x = 4;
	textcolor(LYELLOW);
	put_on_xy(2,3,"Login      ");
	put_on_xy(20,3,"Nome          ");
	put_on_xy(36,3,"Pontos ");
	put_on_xy(44,3,"Data de Entrada");
	put_on_xy(61,3,"Data Ultimo Acesso");
	textcolor(LWHITE);
	fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
	if (feof(PtrPlay)){  
		ExibeTitleRelat(">> JOGADORES CADASTRADOS <<");
		put_on_xy(25,12,"Nao ha Palavras Cadastradas!");
		getch();
	}
    else
    {
		while (!feof(PtrPlay))
		{
			put_on_xy(2,x,RegPlay.login);
			put_on_xy(20,x,RegPlay.Nome);
			gotoxy(38,x); printf("%d",RegPlay.Pontos);
			put_on_xy(44,x,RegPlay.DataEntrada);
			put_on_xy(61,x,RegPlay.DataUltAcesso);
			x++;
			
			fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
		}    
    }
    for(int i=1;i<80;i++){
		put_on_xy(205,i,x+1); 
		Sleep(1);
	}

	putOnMidX(x+1,"// Fim dos Jogadores Cadastrados //");
	getch();
	fclose(PtrPlay);
}

void ConsultJogador(char NomeArq[]){
	TpPlayer RegPlay;
	int pos;
	FILE *PtrPlay = fopen(NomeArq,"rb");
	MoldLow(">> Consulta Jogadores <<",WHITE,10,60,5,20);
	put_on_xy(12,7,"Login do Jogador: ");
	getStr(RegPlay.login);
	while (strcmp(RegPlay.login,"\0") != 0){
		pos = IndexLogin(PtrPlay,RegPlay.login);
		if(pos == -1){
			MoldLow(">> Consulta Jogadores <<",WHITE,10,60,5,20);
			put_on_xy(12,11,"Login NAO encontrado :("); getch();
		}
		else{
			MoldLow(">> DADOS ENCONTRADOS <<",WHITE,10,60,5,20);
			fseek(PtrPlay,pos,0); 
			fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
			gotoxy(12,8); printf("Login: %s",RegPlay.login);
			gotoxy(12,9); printf("Nome: %s",RegPlay.Nome);
			gotoxy(12,10);printf("Pontos: %d",RegPlay.Pontos);
			gotoxy(12,11);printf("Data de Entrada: %s",RegPlay.DataEntrada);
			gotoxy(12,12);printf("Data de Ultimo Acesso: %s",RegPlay.DataUltAcesso);
			getch();
		}
		MoldLow(">> Consulta Jogadores <<",WHITE,10,60,5,20);
		put_on_xy(12,7,"Login do Jogador: ");
		getStr(RegPlay.login);
	}
	fclose(PtrPlay);
}

void AlteraJogador(char NomeArq[]){
	TpPlayer RegPlay;
	int pos;
	FILE *PtrPlay = fopen(NomeArq,"rb+");
	MoldLow(">> Alterar Jogadores <<",WHITE,10,60,5,20);
	put_on_xy(12,7,"Login do Jogador: ");
	getStr(RegPlay.login);

	while (strcmp(RegPlay.login,"\0") != 0){
		pos = ExhaustiveLogin(PtrPlay,RegPlay.login);
		if(pos == -1){
			MoldLow(">> Alterar Jogadores <<",WHITE,10,60,5,20);
			put_on_xy(12,11,"Login NAO encontrado :("); getch();
		}
		else{
			MoldLow(">> DADOS ENCONTRADOS <<",WHITE,10,60,5,20);
			fseek(PtrPlay,pos,0);
			fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
			gotoxy(12,8); printf("Login: %s",RegPlay.login);
			gotoxy(12,9); printf("Nome: %s",RegPlay.Nome);
			gotoxy(12,10);printf("Pontos: %d",RegPlay.Pontos);
			gotoxy(12,11);printf("Data de Entrada: %s",RegPlay.DataEntrada);
			gotoxy(12,12);printf("Data de Ultimo Acesso: %s",RegPlay.DataUltAcesso);
			put_on_xy(12,14,"Deseja Alterar (S/N)? ");
			if(getUpChar() == 'S'){
				MoldLow(">> ALTERACAO <<",WHITE,10,60,5,20);
				put_on_xy(12,8,"NOVO Nome : ");
                getStr(RegPlay.Nome);
				put_on_xy(12,9,"NOVA Quantidade de Pontos: ");
                scanf("%d",&RegPlay.Pontos);
				fseek(PtrPlay,pos,0);
				fwrite(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
				put_on_xy(18,12,"// Jogador ALTERADO corretamente! //");
				getch();
			}
			else{
				MoldLow(">> Alterar Jogadores <<",WHITE,10,60,5,20);
				put_on_xy(30,11,"Alteracao Cancelada!");	
				Sleep(750);	
			}
		}
		MoldLow(">> Alterar Jogadores <<",WHITE,10,60,5,20);
		put_on_xy(12,7,"Login do Jogador: ");
		getStr(RegPlay.login);
	}
	fclose(PtrPlay);
}

void ExclusaoFisicaJogadores(char NomeArq[]){
	TpPlayer RegPlay;
	int pos;
	char auxLogin[25];
	FILE *PtrPlay = fopen(NomeArq, "rb");
	MoldLow(">> Excluir Fisicamente Registro de Jogador <<",WHITE,10,70,5,20);
	put_on_xy(12,7,"Digite o Login: ");	
	getStr(auxLogin);
	if(strcmp(auxLogin,"\0")!=0){
		pos = BBLogin(PtrPlay,auxLogin);
		if(pos == -1){
			MoldLow(">> Excluir Fisicamente Registro de Jogador <<",WHITE,10,70,5,20);
			put_on_xy(12,7,"Nenhum jogador encontrado com esse login!");	
			getch();
			fclose(PtrPlay);
		}
		else{
			MoldLow(">> DADOS ENCONTRADOS <<",WHITE,10,70,5,20);
			fseek(PtrPlay,pos,0);
			fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
			gotoxy(12,8); printf("Login: %s",RegPlay.login);
			gotoxy(12,9); printf("Nome: %s",RegPlay.Nome);
			gotoxy(12,10);printf("Pontos: %d",RegPlay.Pontos);
			gotoxy(12,11);printf("Data de Entrada: %s",RegPlay.DataEntrada);
			gotoxy(12,12);printf("Data de Ultimo Acesso: %s",RegPlay.DataUltAcesso);
			put_on_xy(12,14,"Deseja Realmente Excluir (S/N)? ");
			if (getUpChar() == 'S'){
				FILE *PtrTemp = fopen("Temp.dat","wb");
				rewind(PtrPlay);
				fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
				while (!feof(PtrPlay))
				{
					if(stricmp(auxLogin,RegPlay.login) != 0)
						fwrite(&RegPlay,sizeof(TpPlayer),1,PtrTemp);
					fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
				}
				fclose(PtrPlay);
				fclose(PtrTemp);
				remove(NomeArq);
				rename("Temp.dat",NomeArq);
				MoldLow(">> EXCLUSAO <<",WHITE,10,70,5,20);
				put_on_xy(15,11,"// Registro de Jogador Deletado corretamente! //");
				getch();
			}
			else{
				MoldLow(">> Excluir Fisicamente Registro de Jogador <<",WHITE,10,70,5,20);
				put_on_xy(30,11,"Exclusao Cancelada!");	
				fclose(PtrPlay);
				getch();
			}
		}
		Sleep(200);
	}
	else
		fclose(PtrPlay);
}

//Jogo

int ValidaJogo(FILE *arq, TpJogo elem){
    TpJogo reg;
	rewind(arq);
	fread(&reg,sizeof(TpJogo),1,arq);
    while(!feof(arq) && !(stricmp(reg.login,elem.login) == 0 && stricmp(reg.Palavra,elem.Palavra) == 0))
        fread(&reg,sizeof(TpJogo),1,arq);

    if(!feof(arq))
        return ftell(arq) / sizeof(TpJogo);
    return -1;
}

int sortPalavra(char NomeArq[]){
	TpDicionario Dic;
	FILE *PtrDic = fopen(NomeArq,"rb");
	fseek(PtrDic,0,2);
	
	int qtdReg = ftell(PtrDic) / sizeof(TpDicionario);
	int pos = (rand()%qtdReg) * sizeof(TpDicionario);

	fclose(PtrDic);

	return pos;
}

void JogoPortugues(char ArqDic[], char ArqJogo[], char ArqPlayers[]){
	//Moldura do Game e Limpa tela
	MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);

	//Declaração de Variaveis
	TpPlayer Player;
	TpDicionario Dic;
	TpJogo Game;
	int posPlay, posDic, chances = 5, mid;
	FILE *ptrPlay = fopen(ArqPlayers,"rb+");
	FILE *ptrGame = fopen(ArqJogo,"ab+");
	char auxLogin[25], auxData[10], Suposicao[25];
	
	//Inserido Login
	put_on_xy(28,12,"Digite o seu Login: ");
	getStr(auxLogin);
	while (strcmp(auxLogin,"\0") != 0){
		posPlay = BBLogin(ptrPlay,auxLogin);
		if(posPlay != -1){
			textcolor(GREEN);
			put_on_xy(4,2,"MODO: Portugues");
			textcolor(WHITE);
			//Posicionando no arq para atualizar a data de ult acesso
			fseek(ptrPlay,posPlay,0);
			fread(&Player,sizeof(TpPlayer),1,ptrPlay);
			
			getData(auxData);
			strcpy(Player.DataUltAcesso,auxData);
			fseek(ptrPlay,posPlay,0);
			fwrite(&Player,sizeof(TpPlayer),1,ptrPlay);
			
			putOnMidX(12,"* * * Login carregado :) * * *");
			Sleep(1000);
			putOnMidX(12,"                                                           ");

			//Sorteando a Palavra
			posDic = sortPalavra(ArqDic);
			FILE *ptrDic = fopen(ArqDic,"rb");
			fseek(ptrDic,posDic,0);
			fread(&Dic,sizeof(TpDicionario),1,ptrDic);
			fclose(ptrDic);
			
			//Gravando na Struct jogo para Registrar o Jogo
			strcpy(Game.login,auxLogin);
			strcpy(Game.Palavra,Dic.Portugues);
			
			//Valida se o jogo nao esta repetido
			if(ValidaJogo(ptrGame,Game) == -1){
				//Jogando
				while (chances > 0 && stricmp(Suposicao,Dic.Portugues) != 0){
					MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
					textcolor(GREEN);
					put_on_xy(4,2,"MODO: Portugues");
					textcolor(WHITE);
					put_on_xy(56,2,"Tentativas restantes: "); printf("%d",chances);
					//Gera Riscos
					mid = (78 - strlen(Dic.Portugues)) / 2;
					gotoxy(mid,8);
					for(int i = 0; i < strlen(Dic.Portugues); i++){
						printf("- ");
					}
					
					putOnMidX(6,"Significado da Palavra:");
					textcolor(LYELLOW);
					putOnMidX(7,Dic.Significado);
					textcolor(LWHITE);
					
					put_on_xy(3,23,"Digite a palavra que voce acha que e a partir do significado: ");
					
					getStr(Suposicao);
					//Decrementa das chances
					if (stricmp(Suposicao,Dic.Portugues) != 0){
						chances--;
					}						
				}
				//Se o jogador perder
				if(chances == 0){
					MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
					textcolor(GREY);
					putOnMidX(6,"Infelizmente voce nao acertou a palavra e acabaram suas chances :c");
					gotoxy(((80 - (strlen(Dic.Portugues) + 18)) / 2),7); printf("A Palavra era: %s",Dic.Portugues);
					textcolor(LWHITE);
					getch();
				}
				//Se o jogador Ganhar
				else{
					Player.Pontos = Player.Pontos + Dic.Pontos;
					fseek(ptrPlay,posPlay,0);
					fwrite(&Player,sizeof(TpPlayer),1,ptrPlay);
					fwrite(&Game,sizeof(TpJogo),1,ptrGame);

					MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
					textcolor(GREEN);
					putOnMidX(11,"Parabens voce Acertou a palavra :D");
					gotoxy(29,12); printf("Voce ganhou %d pontos",Dic.Pontos);
					textcolor(LWHITE);
					getch();
				}
			}
			//Caso Existir um jogo o Jogador insere o login novamente
			else{
				MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
				putOnMidX(11,"Jogo ja Realizado...");
				putOnMidX(12,"Digite o Login novamente :c");
				getch();
			}
		}
		//Caso o login nao encotrado
		else{
			MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
			putOnMidX(12,"Login nao encontrado! :c");
			Sleep(750);
		}
		//para sair do jogo basta apertar o enter
		MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
		chances = 5;
		put_on_xy(28,12,"Digite o seu Login: ");
		getStr(auxLogin);
	}
	fclose(ptrGame);
	fclose(ptrPlay);
}

void JogoIngles(char ArqDic[], char ArqJogo[], char ArqPlayers[]){
//Moldura do Game e Limpa tela
	MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);

	//Declaração de Variaveis
	TpPlayer Player;
	TpDicionario Dic;
	TpJogo Game;
	int posPlay, posDic, chances = 5, mid;
	FILE *ptrPlay = fopen(ArqPlayers,"rb+");
	FILE *ptrGame = fopen(ArqJogo,"ab+");
	char auxLogin[25], auxData[10], Suposicao[25];
	//Inserido Login
	put_on_xy(28,12,"Digite o seu Login: ");
	getStr(auxLogin);
	while (strcmp(auxLogin,"\0") != 0){
		posPlay = BBLogin(ptrPlay,auxLogin);
		if(posPlay != -1){
			textcolor(LBLUE);
			put_on_xy(4,2,"MODO: Ingles");
			textcolor(WHITE);
			//Posicionando no arq para atualizar a data de ult acesso
			fseek(ptrPlay,posPlay,0);
			fread(&Player,sizeof(TpPlayer),1,ptrPlay);
			getData(auxData);
			strcpy(Player.DataUltAcesso,auxData);
			fseek(ptrPlay,posPlay,0);
			fwrite(&Player,sizeof(TpPlayer),1,ptrPlay);
			putOnMidX(12,"* * * Login carregado :) * * *");
			Sleep(1000);
			putOnMidX(12,"                              ");

			//Sorteando a Palavra
			posDic = sortPalavra(ArqDic);
			FILE *ptrDic = fopen(ArqDic,"rb");
			fseek(ptrDic,posDic,0);
			fread(&Dic,sizeof(TpDicionario),1,ptrDic);
			fclose(ptrDic);
			//Gravando na Struct jogo para Registrar o Jogo
			strcpy(Game.login,auxLogin);
			strcpy(Game.Palavra,Dic.Ingles);
			//Valida se o jogo nao esta repetido
			if(ValidaJogo(ptrGame,Game) == -1){
				//Jogando
				while (chances > 0 && stricmp(Suposicao,Dic.Ingles) != 0){
					put_on_xy(56,2,"Tentativas restantes: "); printf("%d",chances);
					//Gera Riscos
					mid = (80 - strlen(Dic.Portugues)) / 2;
					gotoxy(mid,8);
					for(int i = 0; i < strlen(Dic.Portugues); i++){
						printf("- ");
					}
					putOnMidX(6,"Significado da Palavra:");
					textcolor(LYELLOW);
					putOnMidX(7,Dic.Significado);
					textcolor(LWHITE);

					put_on_xy(3,23,"Digite a palavra que voce acha que e a partir do significado: ");
					getStr(Suposicao);
					//Decrementa das chances
					if (stricmp(Suposicao,Dic.Ingles) != 0){
						chances--;
					}						
				}
				//Se o jogador perder
				if(chances == 0){
					MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
					textcolor(GREY);
					putOnMidX(6,"Infelizmente voce nao acertou a palavra e acabaram suas chances :c");
					gotoxy(((80 - (strlen(Dic.Ingles) + 18)) / 2),7); printf("A Palavra era: %s",Dic.Ingles);
					textcolor(LWHITE);
					getch();
				}
				//Se o jogador Ganhar
				else{
					Player.Pontos = Player.Pontos + Dic.Pontos;
					fseek(ptrPlay,posPlay,0);
					fwrite(&Player,sizeof(TpPlayer),1,ptrPlay);
					fwrite(&Game,sizeof(TpJogo),1,ptrGame);

					MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
					textcolor(GREEN);
					putOnMidX(11,"Parabens voce Acertou a palavra :D");
					gotoxy(29,12); printf("Voce ganhou %d pontos",Dic.Pontos);
					textcolor(LWHITE);
					getch();
				}
			}
			//Caso Existir um jogo o Jogador insere o login novamente
			else{
				MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
				putOnMidX(11,"Jogo ja Realizado...");
				putOnMidX(12,"Digite o Login novamente :c");
				getch();
			}
		}
		//Caso o login nao encotrado
		else{
			MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
			putOnMidX(12,"Login nao encontrado! :c");
			Sleep(750);
		}
		//para sair do jogo basta apertar o enter
		MoldLow(">> JOGO DAS PALAVRAS <<",YELLOW,1,80,1,25);
		chances = 5;
		put_on_xy(28,12,"Digite o seu Login: ");
		getStr(auxLogin);
	}
	fclose(ptrGame);
	fclose(ptrPlay);
}

void ConsultPalavraPlayer(char NomeArq[]){
	TpJogo Game;
	char login[25];
	int x = 8;
	FILE *ptrGame = fopen(NomeArq,"rb");
	rewind(ptrGame);

	MoldLow(">> Consulta Jogadores <<",WHITE,10,70,5,20);
	put_on_xy(12,6,"Login do Jogador: ");
	getStr(login);
	fread(&Game,sizeof(TpJogo),1,ptrGame);
	MoldLow(">> Consulta Jogadores <<",WHITE,10,70,5,20);
	textcolor(LAQUA);
	gotoxy(15,7); printf("Palavras:");
	textcolor(LWHITE);
	while(!feof(ptrGame)){
		if(stricmp(Game.login,login) == 0){
			gotoxy(20,x); printf("%s",Game.Palavra);
			x++;
		}
		fread(&Game,sizeof(TpJogo),1,ptrGame);
	}
	getch();

	fclose(ptrGame);
}

int BuscaGame(FILE *PtrGame, char Login[25], char Palavra[25]){
	TpJogo G;
	rewind(PtrGame);
	fread(&G,sizeof(TpJogo),1,PtrGame);

	while(!feof(PtrGame) && !(stricmp(Login,G.login) == 0 && stricmp(Palavra,G.Palavra) == 0))
		fread(&G,sizeof(TpJogo),1,PtrGame);
	
	if(!feof(PtrGame))
      return ftell(PtrGame) - sizeof(TpJogo);
    else
      return -1;
}

void AlteraGame(char NomeArq[]){
	TpJogo ReGame;
	int pos;
	FILE *PtrGame = fopen(NomeArq,"rb+");
	MoldLow(">> Alterar Jogo <<",WHITE,10,70,5,20);
	put_on_xy(12,7,"Login do Jogador: ");
	getStr(ReGame.login);
	put_on_xy(12,8,"Digite a Palavra: ");
	getStr(ReGame.Palavra);
	while(strcmp(ReGame.Palavra,"\0") != 0){
		pos = BuscaGame(PtrGame,ReGame.login,ReGame.Palavra);
		if(pos != -1){
			fseek(PtrGame,pos,0); 
			fread(&ReGame,sizeof(TpJogo),1,PtrGame);
			MoldLow(">> DADOS ENCONTRADOS <<",WHITE,10,70,5,20);
			gotoxy(12,8); printf("Login: %s",ReGame.login);
			gotoxy(12,9); printf("Palavra: %s",ReGame.Palavra);
			put_on_xy(12,11,"Deseja Alterar (S/N)? ");

			if(getUpChar() == 'S'){
				MoldLow(">> ALTERACAO <<",WHITE,10,70,5,20);
				put_on_xy(12,8,"NOVO Login: ");
                getStr(ReGame.login);
				put_on_xy(12,9,"NOVA Palavra: ");
                getStr(ReGame.Palavra);
				fseek(PtrGame,pos,0);
				fwrite(&ReGame,sizeof(TpJogo),1,PtrGame);
				put_on_xy(18,12,"// Jogo ALTERADO corretamente! //");
				getch();
			}
			else{
				MoldLow(">> ALTERACAO <<",WHITE,10,70,5,20);
				put_on_xy(30,11,"Alteracao Cancelada!");	
				Sleep(750);	
			}
		}
		else{
			MoldLow(">> Alterar Jogo <<",WHITE,10,70,5,20);
			put_on_xy(12,8,"Jogo nao encontrado :c");
			getch();
		}
		getch();
		MoldLow(">> Alterar Jogo <<",WHITE,10,70,5,20);
		put_on_xy(12,7,"Login do Jogador: ");
		getStr(ReGame.login);
		put_on_xy(12,8,"Digite a Palavra: ");
		getStr(ReGame.Palavra);
	}
	fclose(PtrGame);
}

void ExcluiGame(char NomeArq[]){
	TpJogo ReGame;
	int pos;
	char AuxLogin[25], AuxPalavra[25];
	FILE *PtrGame = fopen(NomeArq, "rb");
	MoldLow(">> Excluir Fisicamente Registro de Jogo <<",WHITE,10,70,5,20);
	put_on_xy(12,7,"Digite o Login: ");	
	getStr(AuxLogin);
	put_on_xy(12,8,"Digite o Palavra: ");	
	getStr(AuxPalavra);
	if(strcmp(AuxLogin,"\0") != 0 || strcmp(AuxPalavra,"\0") != 0){
		pos = BuscaGame(PtrGame,AuxLogin,AuxPalavra);
		if(pos == -1){
			MoldLow(">> Excluir Fisicamente Registro de Jogo <<",WHITE,10,70,5,20);
			put_on_xy(12,7,"Nenhum jogo encontrado com esse login e palavra!");	
			getch();
			fclose(PtrGame);
		}
		else{
			MoldLow(">> DADOS ENCONTRADOS <<",WHITE,10,70,5,20);
			fseek(PtrGame,pos,0);
			fread(&ReGame,sizeof(TpJogo),1,PtrGame);
			gotoxy(12,8); printf("Login: %s",ReGame.login);
			gotoxy(12,9); printf("Palavra: %s",ReGame.Palavra);
			put_on_xy(12,11,"Deseja Realmente Excluir (S/N)? ");
			
			if (getUpChar() == 'S'){
				FILE *PtrTemp = fopen("Temp.dat","wb");
				rewind(PtrGame);
				fread(&ReGame,sizeof(TpJogo),1,PtrGame);
				while (!feof(PtrGame)){
					if(!(stricmp(AuxLogin,ReGame.login) == 0 && stricmp(AuxPalavra,ReGame.Palavra) == 0))
						fwrite(&ReGame,sizeof(TpJogo),1,PtrTemp);
					fread(&ReGame,sizeof(TpJogo),1,PtrGame);	
				}
				fclose(PtrGame);
				fclose(PtrTemp);
				remove(NomeArq);
				rename("Temp.dat",NomeArq);
				MoldLow(">> EXCLUSAO <<",WHITE,10,70,5,20);
				put_on_xy(15,11,"// Registro de Jogador Deletado corretamente! //");
				getch();
				
			}
			else{
				MoldLow(">> Excluir Fisicamente Registro de Jogo <<",WHITE,10,70,5,20);
				put_on_xy(30,11,"Exclusao Cancelada!");	
				fclose(PtrGame);
				getch();
			}
		}
		Sleep(750);
	}
	else
		fclose(PtrGame);
	
}

char MenuPlayers(){
	clear();
	textcolor(LWHITE);
	MoldLow(">> MENU Players <<",WHITE,20,70,7,20);
	
    put_on_xy(25,9,"[A] - Cadastro Jogador");
    put_on_xy(25,10,"[B] - Relatorio Jogador");
    put_on_xy(25,11,"[C] - Consultar Jogador");
    put_on_xy(25,12,"[D] - Alterar Jogador");
    put_on_xy(25,13,"[E] - Excluir Jogador");
    put_on_xy(25,14,"[F] - Ordenar Jogadores pelo Nome");
	textcolor(RED);
    put_on_xy(25,15,"[Esc] - Voltar");
 	textcolor(LWHITE);
	put_on_xy(29,18,"Qual opcao voce deseja ?");
	put_on_xy(30,19,"> ");

	return getUpChar();
}

void selPlayers(char NomeArq[]){
	char opc;
	do{
		opc = MenuPlayers();
		switch(opc)
			{
				case 'A':
					CadJogador(NomeArq);
					break;
				case 'B':
					RelJogador(NomeArq);
					break;
				case 'C':
					ConsultJogador(NomeArq);
					break;
				case 'D':
					AlteraJogador(NomeArq);
					break;
				case 'E':
					ExclusaoFisicaJogadores(NomeArq);
					break;
				case 'X':
					//Ordena Jogadores pelo Nome
					OrdenaJogadoresNome(NomeArq);
					break;
				case 27:
					execute();
					break;
				default:
					break;
			}
	}while(opc != 27);
	
}

char MenuDicionario(){
	clear();
	MolduraMenorDic();
	put_on_xy(32,7,"----------// DICIONARIO //----------");
	put_on_xy(25,9,"[A] Inserir Registro no Dicionario");
	put_on_xy(25,10,"[B] Relatorio de Dicionario");
	put_on_xy(25,11,"[C] Consultar Dicionario pela palavra em Portugues");
	put_on_xy(25,12,"[D] Consulta Palavra em Ingles");
	put_on_xy(25,13,"[E] Alterar dados de Dicionario");
	put_on_xy(25,14,"[F] Excluir Registro de Dicionario");
	put_on_xy(25,15,"[G] Ordenar Dicionario Portugues");
	textcolor(RED);
	put_on_xy(25,16,"[Esc] - Voltar");
 	textcolor(LWHITE);
	put_on_xy(29,19,"Qual opcao voce deseja ?");
	put_on_xy(30,20,"> "); gotoxy(33,20);

	return getUpChar();
}

void selDicionario(char NomeArq[]){
	char opc;
	do{
		opc = MenuDicionario();
		switch(opc)
			{
				case 'A':
					CadDicionario(NomeArq);
					break;
				case 'B':
					RelDicionario(NomeArq);
					break;
				case 'C':
					ConsDicionario(NomeArq);
					break;
				case 'D':
					OrdenaDicionarioIngles(NomeArq);
					ConsultPalavraIngles(NomeArq);
					break;
				case 'E':
					AltDicionario(NomeArq);
					break;
				case 'F':
					ExclusaoFisicaDicionario(NomeArq);
					break;
				case 'G':
					OrdenaDicionarioPT(NomeArq);
					break;
				
				case 27:
					execute();
					break;	
				default:
					break;
			}
	}while(opc != 27);
	
}

char MenuJogoPalavras(){
	
	MoldLow(">> JOGO DAS PALAVRAS <<",WHITE,10,76,5,20);

	put_on_xy(15,8,"[A] Jogar em Portugues");
	put_on_xy(15,9,"[B] Jogar em Ingles");
	put_on_xy(15,10,"[C] Consultar Palavras que sairam para determinado Jogador");
	put_on_xy(15,11,"[D] Alterar Jogos");
	put_on_xy(15,12,"[E] Excluir Jogos");
	textcolor(RED);
	put_on_xy(15,13,"[Esc] - Voltar");
	textcolor(LWHITE);
	put_on_xy(15,15,"Qual opcao voce deseja?");
	put_on_xy(15,16,"> ");
	return getUpChar();
}

void selJogo(char ArqDic[], char ArqJogo[], char ArqPlayers[]){
	char opc;
	do{
		opc = MenuJogoPalavras();
		switch(opc)
		{
			case 'A':
				OrdenaJogadoresLogin(ArqPlayers);
				JogoPortugues(ArqDic,ArqJogo,ArqPlayers);
				break;
			case 'B':
				OrdenaJogadoresLogin(ArqPlayers);
				JogoIngles(ArqDic,ArqJogo,ArqPlayers);
				break;
			case 'C':
				ConsultPalavraPlayer(ArqJogo);
				break;
			case 'D':
				AlteraGame(ArqJogo);
				break;
			case 'E':
				ExcluiGame(ArqJogo);
				break;	
			default:
				break;
		}
	}while(opc != 27);
	
}

//Relatorios
void RankingGeral(char ArqPlayers[]){
	OrdenaJogadoresPontos(ArqPlayers);
	
	TpPlayer RegPlay;
	FILE *PtrPlay = fopen(ArqPlayers,"rb");

	ExibeTitleRelat(">> RANKING JOGADORES <<");
	int x = 4, xRank = 1;
	
	if (feof(PtrPlay)){  
		putOnMidX(4,"Nao ha Jogadores Cadastrados!");
		Sleep(1000);
	}
    else{	
		textcolor(LGREEN);
		put_on_xy(4,3,"Login        ");
		put_on_xy(18,3,"Nome            ");
		put_on_xy(43,3,"Pontos  ");
		put_on_xy(54,3,"Data Ultimo Acesso");
		textcolor(LWHITE);
		fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
		while (!feof(PtrPlay)){	
			gotoxy(1,x); printf("%d.",xRank);
			put_on_xy(4,x,RegPlay.login);
			put_on_xy(18,x,RegPlay.Nome);
			gotoxy(43,x); printf("%d",RegPlay.Pontos);
			put_on_xy(54,x,RegPlay.DataUltAcesso);
			x++;
			xRank++;
			fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
		}    
    }

	for(int i=1;i<80;i++){
		put_on_xy(205,i,x+1); 
		Sleep(1);
	}

	putOnMidX(x+1,"// FIM DO RANKING //");
	getch();
	fclose(PtrPlay);
}

void OrdenaGame(char ArqGame[]){
	int i, j, QtdeReg;
	TpJogo RegI, RegJ;
	FILE *PtrGame = fopen(ArqGame,"rb+");
	
	fseek(PtrGame,0,2);

	QtdeReg = ftell(PtrGame) / sizeof(TpJogo);

	for (i = 0; i < QtdeReg-1; i++)
		for(j = i+1; j<QtdeReg; j++)
		{	
			fseek(PtrGame,i*sizeof(TpJogo),0);
			fread(&RegI,sizeof(TpJogo),1,PtrGame);
			

			fseek(PtrGame,j*sizeof(TpJogo),0);
			fread(&RegJ,sizeof(TpJogo),1,PtrGame);

			if(!(stricmp(RegI.login,RegJ.login) < 0 && stricmp(RegI.Palavra,RegJ.Palavra) < 0))
			{
				fseek(PtrGame,i*sizeof(TpJogo),0);
				fwrite(&RegJ,sizeof(TpJogo),1,PtrGame);
				fseek(PtrGame,j*sizeof(TpJogo),0);
				fwrite(&RegI,sizeof(TpJogo),1,PtrGame);
			}
		}
	fclose(PtrGame);

}

void PlayerStartWithLetter(char ArqPlayers[]){
	TpPlayer RegPlay;
	FILE *PtrPlay = fopen(ArqPlayers,"rb");
	char letra;
	int x = 4;

	ExibeTitleRelat(">> CONSULTA JOGADOR PELA INICIAL <<");
	put_on_xy(10,2,"Digite uma Letra para consultar jogadores que iniciam com ela: ");
	letra = getUpChar();
	do{
		if(letra != 13){
			rewind(PtrPlay);
			textcolor(LBLUE);
			put_on_xy(4,3,"Nome        ");
			put_on_xy(18,3,"Login           ");
			put_on_xy(35,3,"Pontos  ");
			put_on_xy(44,3,"Data Ultimo Acesso");
			textcolor(LWHITE);
			fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
			while(!feof(PtrPlay)){
				if(letra == toupper(RegPlay.login[0])){
					put_on_xy(4,x,RegPlay.login);
					put_on_xy(18,x,RegPlay.Nome);
					gotoxy(35,x); printf("%d",RegPlay.Pontos);
					put_on_xy(44,x,RegPlay.DataUltAcesso);
					x++;
				}
				fread(&RegPlay,sizeof(TpPlayer),1,PtrPlay);
			}
			getch();
		}
		else{
			ExibeTitleRelat(">> CONSULTA JOGADOR PELA INICIAL <<");
			put_on_xy(30,4,"Consulta Cancelada!");
			Sleep(750);
		}
		ExibeTitleRelat(">> CONSULTA JOGADOR PELA INICIAL <<");
		put_on_xy(10,2,"Digite uma Letra para consultar jogadores que iniciam com ela: ");
		letra = getUpChar();
		x = 4;
	}while(letra != 13);
	
	x = 4;
	ExibeTitleRelat(">> CONSULTA JOGADOR PELA INICIAL <<");
	for(int i=1;i<80;i++){
		put_on_xy(205,i,x+1); 
		Sleep(1);
	}
	putOnMidX(x+1,"// FIM DA CONSULTA //");
	getch();
	fclose(PtrPlay);

}

void RankGeralPlayersWords(char ArqGame[]){
	TpJogo RegJogo;
	FILE *PtrGame = fopen(ArqGame,"rb");
	rewind(PtrGame);
	int x = 4;
	ExibeTitleRelat(">> RELATORIO GERAL: PALAVRAS E JOGADORES <<");

	
	if (feof(PtrGame)){  
		printf("\nNao ha Jogadores Cadastrados!\n");
	}
    else
    {
		textcolor(LRED);
		put_on_xy(4,3,"Jogador        ");
		put_on_xy(21,3,"Palavra");
		textcolor(LWHITE);
		fread(&RegJogo,sizeof(TpJogo),1,PtrGame);
		while (!feof(PtrGame))
		{	
			put_on_xy(4,x,RegJogo.login);
			put_on_xy(21,x,RegJogo.Palavra);
			x++;
			fread(&RegJogo,sizeof(TpJogo),1,PtrGame);
		}    
    }
    for(int i=1;i<80;i++){
		put_on_xy(205,i,x+1); 
		Sleep(1);
	}
	putOnMidX(x+1,"// FIM DO RELATORIO //");
	getch();
	fclose(PtrGame);
}

void GeralOrdenado(char ArqGame[]){
	OrdenaGame(ArqGame);
	ExibeTitleRelat(">> RANKING JOGADORES ORDENADO<<");

	TpJogo RegGame;
	FILE *ptrGame = fopen(ArqGame,"rb");

	int x = 4;
	
	if (feof(ptrGame)){  
		putOnMidX(4,"Nao ha Jogadores Cadastrados!");
		Sleep(1000);
	}
    else
	{	
		textcolor(BLUE);
		put_on_xy(18,3,"Login        ");
		put_on_xy(35,3,"Palavra");
		textcolor(LWHITE);
		fread(&RegGame,sizeof(TpJogo),1,ptrGame);
		while (!feof(ptrGame)){	
			put_on_xy(18,x,RegGame.login);
			put_on_xy(35,x,RegGame.Palavra);
			x++;
			fread(&RegGame,sizeof(TpJogo),1,ptrGame);
		}    
    }

	for(int i=1;i<80;i++){
		put_on_xy(205,i,x+1); 
		Sleep(1);
	}

	putOnMidX(x+1,"// FIM DO RANKING //");
	getch();
	fclose(ptrGame);
}

int isPt(char palavra[]){
	TpDicionario Dic;
	FILE *ptrDic = fopen("Archives\\Dicionario.dat","rb");
	rewind(ptrDic);
	fread(&Dic,sizeof(TpDicionario),1,ptrDic);
	while(!feof(ptrDic)){
		if(stricmp(Dic.Portugues,palavra) == 0){
			return 1;
		}
		fread(&Dic,sizeof(TpDicionario),1,ptrDic);
	}
	fclose(ptrDic);
	return -1;
}

void OrdenaBanco(char ArqBanco[]){
	int i, j, QtdeReg;
	TpBancoPalavras RegI, RegJ;
	FILE *ptrBank = fopen(ArqBanco,"rb+");
	
	fseek(ptrBank,0,2);

	QtdeReg = ftell(ptrBank) / sizeof(TpBancoPalavras);

	for (i = 0; i < QtdeReg-1; i++)
		for(j = i+1; j<QtdeReg; j++)
		{	
			fseek(ptrBank,i*sizeof(TpBancoPalavras),0);
			fread(&RegI,sizeof(TpBancoPalavras),1,ptrBank);
			

			fseek(ptrBank,j*sizeof(TpBancoPalavras),0);
			fread(&RegJ,sizeof(TpBancoPalavras),1,ptrBank);

			if(RegI.quant < RegJ.quant)
			{
				fseek(ptrBank,i*sizeof(TpBancoPalavras),0);
				fwrite(&RegJ,sizeof(TpBancoPalavras),1,ptrBank);
				fseek(ptrBank,j*sizeof(TpBancoPalavras),0);
				fwrite(&RegI,sizeof(TpBancoPalavras),1,ptrBank);
			}
		}
	fclose(ptrBank);
}

int SearchWordBank(FILE *ptrB, char Palavra[]){
	TpBancoPalavras B;
	rewind(ptrB);
	fread(&B,sizeof(TpBancoPalavras),1,ptrB);

	while(!feof(ptrB) && stricmp(B.Palavra,Palavra) != 0)
		fread(&B,sizeof(TpBancoPalavras),1,ptrB);
	
	if(!feof(ptrB))
      return ftell(ptrB) - sizeof(TpBancoPalavras);
    else
      return -1;
}

void RankingDasPalavrasPT(char ArqGame[], char ArqBanco[]){
	TpJogo Game;
	TpBancoPalavras Banco;
	int posVerify = 0, i = 0;
	//Sempre cria o arq para atualizar as infos depos dos jogos
	FILE *ptrBank = fopen(ArqBanco,"wb+");
	FILE *ptrGame = fopen(ArqGame,"rb");
	rewind(ptrGame);

	ExibeTitleRelat(">> RANKING PALAVRAS MAIS RESOLVIDAS EM PT-BR <<");
	fread(&Game,sizeof(TpJogo),1,ptrGame);
	while (!feof(ptrGame)){
		posVerify = SearchWordBank(ptrBank,Game.Palavra);
		if(isPt(Game.Palavra)){
			if(posVerify == -1){			
				fseek(ptrBank,0,2);
				fread(&Game,sizeof(TpJogo),1,ptrGame);
				strcpy(Banco.Palavra,Game.Palavra);
				Banco.quant = 1;
				fwrite(&Banco,sizeof(TpBancoPalavras),1,ptrBank);
			}
			else{
				fseek(ptrBank,posVerify,0);
				fread(&Banco,sizeof(TpBancoPalavras),1,ptrBank);
				Banco.quant++;
				fseek(ptrBank,posVerify,0);
				fwrite(&Banco,sizeof(TpBancoPalavras),1,ptrBank);
			}
		}
		fread(&Game,sizeof(TpJogo),1,ptrGame);
	}

	//Exibicao do Rank
	int x = 4;
	textcolor(LILAC);
	put_on_xy(10,3,"Rank");
	put_on_xy(18,3,"Palavra        ");
	put_on_xy(35,3,"Quantidade");
	textcolor(LWHITE);
	fclose(ptrBank);
	//fecha o arquivo para ordenar o mesmo
	OrdenaBanco(ArqBanco);
	ptrBank = fopen(ArqBanco,"rb");
	rewind(ptrBank);
	fread(&Banco,sizeof(TpBancoPalavras),1,ptrBank);
	while (!feof(ptrBank)){
		gotoxy(10,x); printf("%d.",i+1);
		put_on_xy(18,x,Banco.Palavra);
		gotoxy(35,x); printf("%d",Banco.quant);
		x++;
		i++;
		fread(&Banco,sizeof(TpBancoPalavras),1,ptrBank);
	}
	for(int i=1;i<80;i++){
		put_on_xy(205,i,x+1); 
		Sleep(1);
	}
	putOnMidX(x+1,"// FIM DO RANKING //");
	getch();
	fclose(ptrBank);
	fclose(ptrGame);

}

char MenuRelatorios(){
	MoldLow(">> RELATORIOS EXTRAS <<",WHITE,10,79,5,20);
	
	put_on_xy(15,8,"[A] Ranking Geral de Jogadores");
	put_on_xy(15,9,"[B] Jogadores que iniciam com uma determinada letra");
	put_on_xy(15,10,"[C] Ranking de Palavras que mais foram resolvidas em Portugues");
	put_on_xy(15,11,"[D] Geral: Jogadores e palavras que sairam");
	put_on_xy(15,12,"[E] Geral Ordenado: Palavras e os Jogadores que as jogaram");
	textcolor(RED);
	put_on_xy(15,13,"[Esc] - Voltar");
	textcolor(LWHITE);
	put_on_xy(15,15,"Qual opcao voce deseja?");
	put_on_xy(15,16,"> ");
	return getUpChar();
}

void selRelat(){
	char opc;
	do{
		opc = MenuRelatorios();
		switch(opc)
			{
				case 'A':
					RankingGeral("Archives\\Player.dat");
					break;
				case 'B':
					PlayerStartWithLetter("Archives\\Player.dat");
					break;
				case 'C':
					RankingDasPalavrasPT("Archives\\Jogo.dat","Archives\\BancoPT.dat");
					break;
				case 'D':
					RankGeralPlayersWords("Archives\\Jogo.dat");
					break;
				case 'E':
					GeralOrdenado("Archives\\Jogo.dat");
					break;	
				default:
					break;
			}
	}while(opc != 27);
	
}

char Menu(void){

	clear();
	MoldLow(">>> MENU PRINCIPAL <<<",WHITE,22,60,7,18);
 	Moldura(LWHITE);
	
	put_on_xy(28,9,"1: MANIPULAR JOGADORES");

	put_on_xy(28,10,"2: MANIPULAR DICIONARIO");

	put_on_xy(28,11,"3: JOGO DAS PALAVRAS");
	
	put_on_xy(28,12,"4: RELATORIOS ESPECIFICOS");
	textcolor(RED);
	put_on_xy(28,14,"[Esc] Sair do Programa");

	textcolor(LWHITE);

	put_on_xy(28,16,"Digite a opcao desejada -> ");
	
	return getUpChar();
}
 
void VerifArquivos(void)
{
	FILE *PtrArq;
	PtrArq = fopen("Archives\\Dicionario.dat","ab");
	fclose(PtrArq);
	PtrArq = fopen("Archives\\Player.dat","ab");
	fclose(PtrArq);
	PtrArq = fopen("Archives\\Jogo.dat","ab");
	fclose(PtrArq);
	PtrArq = fopen("Archives\\BancoPT.dat","ab");
	fclose(PtrArq);
}

void execute(){
	char op;
	VerifArquivos(); //Verifica a existÃªncia dos Arquivos

	do
	{
		op = Menu();
		switch(op)
		{
			//Jogadores
			case '1':
				selPlayers("Archives\\Player.dat");
				break;
			case '2':
				selDicionario("Archives\\Dicionario.dat");
				break;
			case '3':
				selJogo("Archives\\Dicionario.dat","Archives\\Jogo.dat","Archives\\Player.dat");
				break;
			case '4':
				selRelat();
				break;
			default:
				clear();
				put_on_xy(40,12,"Fechando o Programa...");
				break;
		}
	}while(op!=27);
}

int main(void){
	execute();
	return 0;
}
