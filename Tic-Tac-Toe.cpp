#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
char pat[20][167],position;
int chancePlayerOne=0,chancePlayerTwo=0,chanceNums=1,player=1,game,a[9]={0}, point[9]={0};
	
void printPattern();
void mark(char,int);
int  rootchecker(char,int);
void right(char);
void cross(char);

void initSpace()
{
	//Assigning each value of array to space...i.e Creating blank space//
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<167;j++)
			pat[i][j]=' ';
	}
}
void right(char position)
{
	if(position=='a')
	{		
		int x=1;
		pat[5][67]=' ';
		pat[5][63+x] = pat[6][65+x] = pat[5][67+x] = pat[4][69+x]='*';	
	}
	else if(position=='b')
	{
		int x=13;
		pat[5][79]=' ';
		pat[5][63+x] = pat[6][65+x] = pat[5][67+x] = pat[4][69+x]='*';	
	}
	else if(position=='c')
	{
		int x=25;
		pat[5][90]=' ';
		pat[5][63+x] = pat[6][65+x] = pat[5][67+x] = pat[4][69+x]='*';	
	}
	else if(position=='d')
	{
		int x=1,y=5;
		pat[5+y][67]=' ';
		pat[5+y][63+x] = pat[6+y][65+x] = pat[5+y][67+x] = pat[4+y][69+x]='*';	
	}
	else if(position=='e')
	{
		int x=13,y=5;
		pat[10][79]=' ';
		pat[5+y][63+x] = pat[6+y][65+x] = pat[5+y][67+x] = pat[4+y][69+x]='*';	
	}
	else if(position=='f')
	{
		int x=25,y=5;
		pat[10][90]=' ';
		pat[5+y][63+x] = pat[6+y][65+x] = pat[5+y][67+x] = pat[4+y][69+x]='*';	
	}
	else if(position=='g')
	{
		int x=1,y=10;
		pat[5+y][67]=' ';
		pat[5+y][63+x] = pat[6+y][65+x] = pat[5+y][67+x] = pat[4+y][69+x]='*';	
	}
	else if(position=='h')
	{
		int x=13,y=10;
		pat[15][79]=' ';
		pat[5+y][63+x] = pat[6+y][65+x] = pat[5+y][67+x] = pat[4+y][69+x]='*';	
	}
	else if(position=='i')
	{
		int x=25,y=10;
		pat[15][90]=' ';
		pat[5+y][63+x] = pat[6+y][65+x] = pat[5+y][67+x] = pat[4+y][69+x]='*';	
	}
}
void cross(char position)
{
	if(position=='a')
	{
		pat[5][67]=' ';pat[4][68] = pat[4][66] = pat[5][67] = pat[6][68] = pat[6][66]='*';		
	}
	else if(position=='b')
	{
		pat[5][79]=' ';
		pat[4][80]='*';	pat[4][78]='*';	pat[5][79]='*';
		pat[6][80]='*';	pat[6][78]='*';		
	}
	else if(position=='c')
	{
		pat[5][90]=' ';
		int x=12;
		pat[4][80+x]='*';	pat[4][78+x]='*';	pat[5][79+x]='*';
		pat[6][80+x]='*';	pat[6][78+x]='*';
	}
	else if(position=='d')
	{
		int y=5;
		pat[5+y][67]=' ';
		pat[4+y][68]='*';	pat[4+y][66]='*';	pat[5+y][67]='*';
		pat[6+y][68]='*';	pat[6+y][66]='*';		
	}
	else if(position=='e')
	{
		int x=5;
		pat[5+x][79]=' ';
		pat[4+x][80]='*';	pat[4+x][78]='*';	pat[5+x][79]='*';
		pat[6+x][80]='*';	pat[6+x][78]='*';		
	}
	else if(position=='f')
	{
		int x=12,y=5;
		pat[5+y][90]=' ';
		pat[4+y][80+x]='*';	pat[4+y][78+x]='*';	pat[5+y][79+x]='*';
		pat[6+y][80+x]='*';	pat[6+y][78+x]='*';
	}
	else if(position=='g')
	{
		int y=10;
		pat[5+y][67]=' ';
		pat[4+y][68]='*';	pat[4+y][66]='*';	pat[5+y][67]='*';
		pat[6+y][68]='*';	pat[6+y][66]='*';		
	}
	else if(position=='h')
	{
		int x=10;
		pat[5+x][79]=' ';
		pat[4+x][80]='*';	pat[4+x][78]='*';	pat[5+x][79]='*';
		pat[6+x][80]='*';	pat[6+x][78]='*';		
	}
	else if(position=='i')
	{
		int x=12,y=10;
		pat[5+y][90]=' ';
		pat[4+y][80+x]='*';	pat[4+y][78+x]='*';	pat[5+y][79+x]='*';
		pat[6+y][80+x]='*';	pat[6+y][78+x]='*';
	}
}
void equal1()
{	
	for(int i=1;i<168;i++)
		printf("=");
	puts("");
}
void head()
{
	for(int i=1;i<156;i++)
	{
		if(i==74)
			printf(" Tic-Tac-Toe ");
		else
			printf("=");
	}
	printf("\n\n%60s%55s\n\n","Player 1 - RIGHT","Player 2 - CROSS");
	equal1();
}
void pattern()
{
	int i,j;
	//p and q//
	for(i=3;i<18;i++)
	{
		for(j=75;j<=75;j++)
		{
			pat[i][j]=179;
			pat[i][j+9]=179;
		}
	}
	for(i=8;i<=8;i++)
	{
		for(j=60;j<=97;j++)
		{
			pat[i][j]=196;
			pat[i+4][j]=196;
		}
	}
}
void printPattern()
{
	int i,j;
	for(i=0;i<20;i++)
	{
		for(j=0;j<167;j++)
			cout<<pat[i][j];
		puts("");
	}
}
int rootchecker(char position, int player)
{
	if(position=='a' && point[0]==0)
	{
		if(player==1)
			point[0]=1;
		else
			point[0]=2;
	}
	else if(position=='b' && point[1]==0)
	{
		if(player==1)
			point[1]=1;
		else
			point[1]=2;
	}
	else if(position=='c' && point[2]==0)
	{
		if(player==1)
			point[2]=1;
		else
			point[2]=2;
	}
	else if(position=='d' && point[3]==0)
	{
		if(player==1)
			point[3]=1;
		else
			point[3]=2;
	}
	else if(position=='e' && point[4]==0)
	{
		if(player==1)
			point[4]=1;
		else
			point[4]=2;
	}
	else if(position=='f' && point[5]==0)
	{
		if(player==1)
			point[5]=1;
		else
			point[5]=2;
	}
	else if(position=='g' && point[6]==0)
	{
		if(player==1)
			point[6]=1;
		else
			point[6]=2;
	}
	else if(position=='h' && point[7]==0)
	{
		if(player==1)
			point[7]=1;
		else
			point[7]=2;
	}
	else if(position=='i' && point[8]==0)
	{
		if(player==1)
			point[8]=1;
		else
			point[8]=2;
	}
	//for right combinations//
	if(point[0]==1 && point[1]==1 && point[2]==1 || point[3]==1 && point[4]==1 && point[5]==1 || point[6]==1 && point[7]==1 && point[8]==1)
		return 1;
	else if((point[0]==1 && point[3]==1 && point[6]==1) || (point[1]==1 && point[4]==1 && point[7]==1) || (point[2]==1 && point[5]==1 && point[8]==1))
		return 1;
	else if(point[0]==1 && point[4]==1 && point[8]==1 || point[2]==1 && point[4]==1 && point[6]==1)
		return 1;
	
	//f|| cross combinations//
	if(point[0]==2 && point[1]==2 && point[2]==2 || point[3]==2 && point[4]==2 && point[5]==2 || point[6]==2 && point[7]==2 && point[8]==2)
		return 2;
	else if(point[0]==2 && point[3]==2 && point[6]==2 || point[1]==2 && point[4]==2 && point[7]==2 || point[2]==2 && point[5]==2 && point[8]==2)
		return 2;
	else if(point[0]==2 && point[4]==2 && point[8]==2 || point[2]==2 && point[4]==2 && point[6]==2)
		return 2;
		
	return 0;
}
void kernel()
{
	pat[5][67]='a'; pat[10][67]='d'; pat[15][67]='g';
	pat[5][79]='b'; pat[10][79]='e'; pat[15][79]='h';
	pat[5][90]='c'; pat[10][90]='f'; pat[15][90]='i';
	int res;
	for(game=1;game<=9;game++)
	{
	//init();
	if(player==1)
	{
	head();
	pattern();
	printPattern();
	equal1();
	printf("%85s -> %d\n","Chance Number",chanceNums);
	printf("%60s %d %55s %d\n\n","Player-1 Chances ->",chancePlayerOne,"Player - 2 Chances ->",chancePlayerTwo);
	equal1();
	printf("\n%88s\n","Player-1 RIGHT");
	fflush(stdin);	
	printf("%50c%c%s",' ',221," Enter the position: ");
	scanf("%c",&position);
	mark(position,player);
	res=rootchecker(position,player);
	if(res == 1 || res == 2)
		break;
	chancePlayerOne++;
	chanceNums++;
	player=2; //assigning new value to player so that next chance is of player 2//
	}
	else
	{
	head();
	pattern();
	printPattern();
	equal1();
	printf("%85s -> %d\n","Chance Number",chanceNums);
	printf("%60s %d %55s %d\n\n","Player-1 Chances ->",chancePlayerOne,"Player - 2 Chances ->",chancePlayerTwo);
	equal1();
	printf("\n%88s\n","Player-2 CROSS");
	
	fflush(stdin);
	printf("%50c%c%s",' ',221," Enter the position: ");
	scanf("%c",&position);
	mark(position,player);
	res=rootchecker(position,player);
	if(res == 1 || res == 2)
		break;
	chancePlayerTwo++;
	chanceNums++;
	player=1;
	}
	if(game!=9)
		system("cls");
}
if(res == 1 || res == 2)
	{
		system("cls");
		head();
		printPattern();
		equal1();
		printf("\n%88s %d %s\n\n","Congratulations Player",res,"WINS");
		equal1();
		getch();
		exit(0);
	}
}
void mark(char position, int player)
{
	if(position=='a' && a[0]==0)
	{
		if(player==1)
			right('a');
		else
			cross('a');
		a[0]=1;
	}
	else if(position=='b' && a[1]==0)
	{
		if(player==1)
			right('b');
		else
			cross('b');
		a[1]=1;
	}
	else if(position=='c' && a[2]==0)
	{
		if(player==1)
			right('c');
		else
			cross('c');
		a[2]=1;
	}
	else if(position=='d' && a[3]==0)
	{
		if(player==1)
			right('d');
		else
			cross('d');
		a[3]=1;
	}
	else if(position=='e' && a[4]==0)
	{
		if(player==1)
			right('e');
		else
			cross('e');
		a[4]=1;
	}
	else if(position=='f' && a[5]==0)
	{
		if(player==1)
			right('f');
		else
			cross('f');
		a[5]=1;
	}
	else if(position=='g' && a[6]==0)
	{
		if(player==1)
			right('g');
		else
			cross('g');
		a[6]=1;
	}
	else if(position=='h' && a[7]==0)
	{
		if(player==1)
			right('h');
		else
			cross('h');
		a[7]=1;
	}
	else if(position=='i' && a[8]==0)
	{
		if(player==1)
			right('i');
		else
			cross('i');
		a[8]=1;
	}
	else
	{
		printf("%90s","Invalid input!\n");
		getch();
		exit(0);
	}
}
int main()
{
	getch(); 	
	kernel();
	getch();
}
