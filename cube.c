/*
	�ۼ��� : ������
	���α׷� �̸� : ť��
	�ۼ� ���α׷� : notepad++
	����� �����Ϸ� : mingw gcc
	�ۼ� ���� ��¥ : 16.04.14
*/

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>

int gotoxy()//������ Ŀ���̵�
{
    COORD pos = {0,0};
	
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API �Լ��Դϴ�. �̰� ���ʿ� �����
}

void cursor(char show) //ȭ���� Ŀ���� ���̰ų� �����
{
         HANDLE hConsole; // �ܼ� �ڵ�
         CONSOLE_CURSOR_INFO ConsoleCursor; // �ܼ�Ŀ�� ���� ����ü

         hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ��� ���ϰ�

         ConsoleCursor.bVisible = show; // SHOW ���� , HIDE �Ⱥ���
         ConsoleCursor.dwSize = 1; // Ŀ�� ������
         SetConsoleCursorInfo(hConsole , &ConsoleCursor); // ����
}

int cubefun(int cube [][42],int view,int speed)//ť�� ��� �Լ�
{
	int i,j,k,x,y,b,c,temp1,temp2,temp3,temp4;
	char g[2][2] = {"��"};
	
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_SCREEN_BUFFER_INFO csbi;
	//GetConsoleScreenBufferInfo(hC,&csbi);
	//COLORREF a;
		
	SetConsoleTextAttribute(hC,15|0);	
	
	printf("\n");
	SetConsoleTextAttribute(hC,0);
	if(view==0)
	{
	for(i=3 ; i<12 ; i++ )
		{
			printf("		  ");
			for(j=12 ; j<21 ; j++)
			{
				SetConsoleTextAttribute(hC,cube[i][j]);
				printf("%s",g);
			}
			if(i==3)
			{
				SetConsoleTextAttribute(hC,15|0);
				printf("   ---������---   (z�� �����ø� ���� ų �� �ֽ��ϴ�.)");
			}
				
			printf("\n");
		}
		
		for(i=12 ; i<21 ; i++ )
		{
			for(j=3 ; j<39 ; j++)
			{
				SetConsoleTextAttribute(hC,cube[i][j]);
				printf("%s",g);
			}
			printf("\n");
		}
		
		for(i=21 ; i<30 ; i++ )
		{
			printf("		  ");
			for(j=12 ; j<21 ; j++)
			{
				SetConsoleTextAttribute(hC,cube[i][j]);
				printf("%s",g);
			}
			printf("\n");
		}
	}
		SetConsoleTextAttribute(hC,15|0);
		printf("\n   						���� ��ȯ : ����Ű  \n");
		
		SetConsoleTextAttribute(hC,15|0);
		printf("  	      q a     w s     e d ");
		SetConsoleTextAttribute(hC,0);
		printf("	\n           ");
		
		SetConsoleTextAttribute(hC,15|0);
		printf(" �֢�    �֢�    �֢�  \n\n");
		SetConsoleTextAttribute(hC,0);
	
		for(i=12 , k=10 , x=11 , y=21 , b=0 , c=1 ; i<21 || c<10 ; i++ , k-=2 , c++ )
		{
			if(i==14 || i==17 || i==20)
			{
				x++;
				k+=2;
				continue;
			}
			
			temp1=k;
			
			for(; temp1>0 ; temp1--)
				printf(" ");		
			
			for(j=12 ; j<21 ; j++ )
			{
				if(x==37)
					break;
				
				SetConsoleTextAttribute(hC,cube[i][j]);
				printf("%s",g);
			}
			
			x++;
			temp2=x;
			temp3=y;
			for(b=0 ; b<c ; b++ ,x-- ,y++)
			{	
				if(b==2 || b==5 || b==8)
				{
					y--;
					continue;
				}
				
				SetConsoleTextAttribute(hC,cube[x][y]);
				printf("%s",g);
			}
			x=temp2;
			y=temp3;
			
			if(i==12)
			{
				printf(" ");
				SetConsoleTextAttribute(hC,15|0);	
				printf("�� u 		���� �ӵ� : %d (�ְ�ӵ� = 0)   ",speed);
				SetConsoleTextAttribute(hC,0);
			}
			if(i==13)
			{
				printf(" ");
				SetConsoleTextAttribute(hC,15|0);	
				printf("�� y");
				SetConsoleTextAttribute(hC,0);
			}
			
			if(i==16)
			{
				printf(" ");
				SetConsoleTextAttribute(hC,15|0);	
				printf("�� j 		EnterŰ�� �����ø� ť�긦 �����ϴ�.");
				SetConsoleTextAttribute(hC,0);
			}
			if(i==18)
			{
				printf(" ");
				SetConsoleTextAttribute(hC,15|0);	
				printf("�� h ");
				SetConsoleTextAttribute(hC,0);
			}
			if(i==19)
			{
				SetConsoleTextAttribute(hC,15|0);
				printf("			SpaceBar�� �����ø� ť�긦 �ڵ����� ����ϴ�.");
			}
			
			printf("\n");
		}
		
		for(i=21 , x=20 , b=0 , c=10 , y=22 ; i<30 || c>0 ; i++ , c--)
		{
			if(i==26 || i==28)
				c--;
			
			for(j=12 ; j<21 ; j++)
			{
				SetConsoleTextAttribute(hC,cube[i][j]);
				printf("%s",g);
			}

			temp2=x;
			temp3=y;
			for(b=0 ; b<c && b<9; b++ ,x-- ,y++ )
				{	
					if(b==2 || b==5 || b==8)
					{
						y--;
						continue;
					}
					
					SetConsoleTextAttribute(hC,cube[x][y]);
					printf("%s",g);
				}
			x=temp2;
			y=temp3;
			y++;
			
			if(i==21)
			{
				printf(" ");
				SetConsoleTextAttribute(hC,15|0);	
				printf("�� m ");
				SetConsoleTextAttribute(hC,0);
			}
			if(i==22)
			{
				printf(" ");
				SetConsoleTextAttribute(hC,15|0);	
				printf("�� n 		<  > Ű�� ť����ߴ� �ӵ��� ������ �� �ֽ��ϴ�.");
				SetConsoleTextAttribute(hC,0);
			}
			if(i==24)
			{
				SetConsoleTextAttribute(hC,15|0);
				printf("			CŰ�� �����ø� ť�긦 ���󺹱��մϴ�.");
			}
			if(i==25)
			{
				printf("  ");
				SetConsoleTextAttribute(hC,15|0);	
				printf("��� ");
				SetConsoleTextAttribute(hC,0);
			}
			if(i==26)
			{
				printf("    ");
				SetConsoleTextAttribute(hC,15|0);	
				printf(" r t 		XŰ�� �����ø� �ð��� �����մϴ�. �ٽ� �����ø� �����մϴ�.");
				SetConsoleTextAttribute(hC,0);
			}
			
			if(i==27)
			{
				printf("  ");
				SetConsoleTextAttribute(hC,15|0);	
				printf("���");
				SetConsoleTextAttribute(hC,0);
			}
			if(i==28)
			{
				printf("    ");
				SetConsoleTextAttribute(hC,15|0);	
				printf(" f g  	     		ESCŰ�� �����ø� �����մϴ�.");
				SetConsoleTextAttribute(hC,0);
			}
			
			printf("\n");
		}
			
				printf("  		  ");
				SetConsoleTextAttribute(hC,15|0);	
				printf(" ��� ");
				SetConsoleTextAttribute(hC,0);
			printf("\n");
				printf("  		  ");
				SetConsoleTextAttribute(hC,15|0);	
				printf("  v b   	                        			made by 16422034 ������\n");
				SetConsoleTextAttribute(hC,0);
}

int turn(int t, int cube[][42],int view,int speed)//ť�� ȸ�� �Լ�
{
	int i,j,k,x,y,b,c,temp;
    char ch;
	
	int tempcube2[33][42] = {
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
	};
	
	int tempcube[9][9];
	
    
		
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC,&csbi);
	COLORREF a;
	
	SetConsoleTextAttribute(hC,0);
	
	gotoxy();
	
	cubefun(cube,view,speed);
    
	
		if(t=='e')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=18 ; j<21 ; j++ )
				{
					for( i=2 ; i<29 ; i++ )
					{
						cube[i][j] = cube[i+1][j] ;
					}
				}
			
				for( i=0 , x=9 ; i<3 ; i++ , x++ )
				{
					for(j=18 , y=30 ; j<21 ; j++ , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
				
			
				for( j=30 ; j<33 ; j++ )
				{
					for( i=24 ; i>5 ; i-- )
					{
						cube[i][j] = cube[i-1][j] ;
					}
				}
				
				for( i=21 , x=29 ; i<24 ; i++ , x++ )
				{
					for( j=30 , y=18 ; j<33 ; j++ , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
			}

			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=21 , y=0 ; j<30 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=29 , x=0 ; j>=21 || x<9 ; j-- , x++)
			{
				for(i=12 , y=0 ; i<21 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}	
		
		if(t=='d')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=18 ; j<21 ; j++ )
				{
					for( i=30 ; i>=2 ; i-- )
					{
						cube[i][j] = cube[i-1][j] ;
					}
				}
				
				for( i=30 , x=21 ; i<33 ; i++ , x++ )
				{
					for(j=18 , y=30 ; j<21 ; j++ , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
			
				for( j=30 ; j<33 ; j++ )
				{
					for( i=6 ; i<23 ; i++ )
					{
						cube[i][j] = cube[i+1][j] ;
					}
				}
				
				
				for( i=11, x=3, j=30 , y=18 ; j<33 ; j++ , y++ )
				{
					cube[x][y] = cube[i][j];
				}
			}
			
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=21 , y=0 ; j<30 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=21 , x=0 ; j<30 || x<9 ; j++ , x++)
			{
				for(i=20 , y=0 ; i>11 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='a')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=12 ; j<15 ; j++ )
				{
					for( i=30 ; i>2 ; i-- )
					{
						cube[i][j] = cube[i-1][j] ;
					}
				}
				
				for( i=30 , x=21 ; i<33 ; i++ , x++ )
				{
					for(j=12 , y=36 ; j<15 ; j++ , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
			
				for( j=36 ; j<39 ; j++ )
				{
					for( i=11 ; i<21 ; i++ )
					{
						cube[i][j] = cube[i+1][j] ;
					}
				}
				
				
				for( i=11, x=3, j=36 , y=12 ; j<39 ; j++ , y++ )
				{
					cube[x][y] = cube[i][j];
				}
			}
			
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=3 , y=0 ; j<12 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=11 , x=0 ; j>=3 || x<9 ; j-- , x++)
			{
				for(i=12 , y=0 ; i<21 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
				
			cubefun(cube,view,speed);
		}
	
		if(t=='q')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=12 ; j<15 ; j++ )
				{
					for( i=2 ; i<27 ; i++ )
					{
						cube[i][j] = cube[i+1][j] ;
					}
				}
			
				for( i=0 , x=9 ; i<3 ; i++ , x++ )
				{
					for(j=12 , y=36 ; j<15 ; j++ , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
				
			
				for( j=36 ; j<39 ; j++ )
				{
					for( i=24 ; i>5 ; i-- )
					{
						cube[i][j] = cube[i-1][j] ;
					}
				}
				
				for( i=21 , x=30 ; i<24 ; i++ , x++ )
				{
					for( j=36 , y=12 ; j<39 ; j++ , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
				
				for( j=12 ; j<15 ; j++ )
				{
					for( i=26 ; i<34 ; i++ )
					{
						cube[i][j] = cube[i+1][j] ;
					}
				}
			}
			
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=3 , y=0 ; j<12 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=3 , x=0 ; j<12 || x<9 ; j++ , x++)
			{
				for(i=20 , y=0 ; i>11 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='w')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=15 ; j<18 ; j++ )
				{
					for( i=2 ; i<29 ; i++ )
					{
						cube[i][j] = cube[i+1][j] ;
					}
				}
			
				for( i=0 , x=9 ; i<3 ; i++ , x++ )
				{
					for(j=15 , y=33 ; j<18 ; j++ , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
				
			
				for( j=33 ; j<36 ; j++ )
				{
					for( i=24 ; i>5 ; i-- )
					{
						cube[i][j] = cube[i-1][j] ;
					}
				}
				
				for( i=21 , x=29 ; i<24 ; i++ , x++ )
				{
					for( j=33 , y=15 ; j<36 ; j++ , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
			}

			cubefun(cube,view,speed);
		}
		
		if(t=='s')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=15 ; j<18 ; j++ )
				{
					for( i=30 ; i>=2 ; i-- )
					{
						cube[i][j] = cube[i-1][j] ;
					}
				}
				
				for( i=30 , x=21 ; i<33 ; i++ , x++ )
				{
					for(j=15 , y=33 ; j<18 ; j++ , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
			
				for( j=33 ; j<36 ; j++ )
				{
					for( i=6 ; i<25 ; i++ )
					{
						cube[i][j] = cube[i+1][j] ;
					}
				}
				
				
				for( i=11, x=3, j=33 , y=15 ; j<36 ; j++ , y++ )
				{
					cube[x][y] = cube[i][j];
				}	
			}

			cubefun(cube,view,speed);
		}
		
		if(t=='b')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=39 ; j>2 ; j-- )
				{
					for( i=18 ; i<21 ; i++ )
					{
						cube[i][j] = cube[i][j-1] ;
					}
				}
			
				for( i=18 , x=18 , y=3 , j=39 ; i<21 && x<21 ; i++ , x++ )
				{
						cube[x][y] = cube[i][j];
				}
				
			}
			
			for(i=21 , x=0 ; i<30 || x<9; i++ , x++)
			{
				for(j=12 , y=0 ; j<21 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=20 , x=0 ; j>=12 || x<9 ; j-- , x++)
			{
				for(i=21 , y=0 ; i<30 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='v')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=2 ; j<40 ; j++ )
				{
					for( i=18 ; i<21 ; i++ )
					{
						cube[i][j] = cube[i][j+1] ;
					}
				}
			
				for( i=18 , x=18 , y=38 , j=2 ; i<21 && x<21 ; i++ , x++ )
				{
						cube[x][y] = cube[i][j];
				}
				
			}
			
			for(i=21 , x=0 ; i<30 || x<9; i++ , x++)
			{
				for(j=12 , y=0 ; j<21 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=12 , x=0 ; j<21 || x<9 ; j++ , x++)
			{
				for(i=29 , y=0 ; i>20 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='g')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=39 ; j>2 ; j-- )
				{
					for( i=15 ; i<18 ; i++ )
					{
						cube[i][j] = cube[i][j-1] ;
					}
				}
			
				for( i=15 , x=15 , y=3 , j=39 ; i<18 && x<18 ; i++ , x++ )
				{
						cube[x][y] = cube[i][j];
				}
				
			}
			cubefun(cube,view,speed);
		}
		
		if(t=='f')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=2 ; j<39 ; j++ )
				{
					for( i=15 ; i<18 ; i++ )
					{
						cube[i][j] = cube[i][j+1] ;
					}
				}
			
				for( i=15 , x=15 , y=38 , j=2 ; i<18 && x<18 ; i++ , x++ )
				{
						cube[x][y] = cube[i][j];
				}
				
			}
			cubefun(cube,view,speed);
		}
		
		if(t=='t')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=39 ; j>2 ; j-- )
				{
					for( i=12 ; i<15 ; i++ )
					{
						cube[i][j] = cube[i][j-1] ;
					}
				}
			
				for( i=12 , x=12 , y=3 , j=39 ; i<15 && x<15 ; i++ , x++ )
				{
						cube[x][y] = cube[i][j];
				}
				
			}
			
			for(i=3 , x=0 ; i<12 || x<9; i++ , x++)
			{
				for(j=12 , y=0 ; j<21 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=12 , x=0 ; j<21 || x<9 ; j++ , x++)
			{
				for(i=11 , y=0 ; i>=3 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='r')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=2 ; j<39 ; j++ )
				{
					for( i=12 ; i<15 ; i++ )
					{
						cube[i][j] = cube[i][j+1] ;
					}
				}
			
				for( i=12 , x=12 , y=38 , j=2 ; i<15 && x<15 ; i++ , x++ )
				{
						cube[x][y] = cube[i][j];
				}
				
			}
			
			for(i=11 , x=0 ; i>=3 || x<9; i-- , x++)
			{
				for(j=12 , y=0 ; j<21 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=12 , x=0 ; j<21 || x<9 ; j++ , x++)
			{
				for(i=3 , y=0 ; i<12 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='u')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for(i=21 ; i<24 ; i++)
				{
					for(j=11 ; j<20 ; j++)
						cube[i][j] = cube[i][j+1];
				}
				
				for(j=9 ; j<12 ; j++)
				{
					for(i=11 ; i<20 ; i++)
						cube[i][j] = cube[i+1][j];
				}
				
				for(i=9 ; i<12 ; i++)
				{
					for(j=21 ; j>=12 ; j--)
						cube[i][j] = cube[i][j-1];
				}
					
				for(j=21 ; j<24 ; j++)
				{
					for(i=21 ; i>=12 ; i--)
						cube[i][j] = cube[i-1][j];
				}
				
				for(i=20 , j=9 ; j<12 ; j++)
					for(x=21 , y=11 ; x<24 ; x++)
						cube[i][j] = cube[x][y];
					
				for(i=9 , j=12 ; i<12 ; i++)
					for(x=11 , y=9 ; y<12 ; y++)
						cube[i][j] = cube[x][y];
					
				for(i=12 , j=21 ; j<24 ; j++)
					for(x=9 , y=21 ; x<12 ; x++)
						cube[i][j] = cube[x][y];
					
				for(i=21 , j=20 ; i<24 ; i++)
					for(x=21 , y=21 ; y<24 ; y++)
						cube[i][j] = cube[x][y];
			}
			
			for(i=20 , x=0 ; i>=12 || x<9; i-- , x++)
			{
				for(j=12 , y=0 ; j<21 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=12 , x=0 ; j<21 || x<9 ; j++ , x++)
			{
				for(i=12 , y=0 ; i<21 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='y')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for(i=21 ; i<24 ; i++)
				{
					for(j=21 ; j>=13 ; j--)
						cube[i][j] = cube[i][j-1];
				}
				
				for(j=21 ; j<24 ; j++)
				{
					for(i=11 ; i<20 ; i++)
						cube[i][j] = cube[i+1][j];
				}
				
				for(i=9 ; i<12 ; i++)
				{
					for(j=11 ; j<20 ; j++)
						cube[i][j] = cube[i][j+1];
				}
					
				for(j=9 ; j<12 ; j++)
				{
					for(i=21 ; i>=13 ; i--)
						cube[i][j] = cube[i-1][j];
				}
				
				for(i=20 , j=21 ; j<24 ; j++)
					for(x=21 , y=21 ; x<24 ; x++)
						cube[i][j] = cube[x][y];
					
				for(i=9 , j=20 ; i<12 ; i++)
					for(x=11 , y=21 ; y<24 ; y++)
						cube[i][j] = cube[x][y];
					
				for(i=12 , j=9 ; j<12 ; j++)
					for(x=9 , y=11 ; x<12 ; x++)
						cube[i][j] = cube[x][y];
				
				for(i=21 , j=12 ; i<24 ; i++)
					for(x=21 , y=9 ; y<12 ; y++)
						cube[i][j] = cube[x][y];
			}
		
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=12 , y=0 ; j<21 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=12 , x=0 ; j<21 || x<9 ; j++ , x++)
			{
				for(i=20 , y=0 ; i>11 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='j')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for(i=24 ; i<27 ; i++)
				{
					for(j=11 ; j<20 ; j++)
						cube[i][j] = cube[i][j+1];
				}
				
				for(j=6 ; j<9 ; j++)
				{
					for(i=11 ; i<20 ; i++)
						cube[i][j] = cube[i+1][j];
				}
				
				for(i=6 ; i<9 ; i++)
				{
					for(j=21 ; j>=12 ; j--)
						cube[i][j] = cube[i][j-1];
				}
					
				for(j=24 ; j<27 ; j++)
				{
					for(i=21 ; i>=12 ; i--)
						cube[i][j] = cube[i-1][j];
				}
			
				
				for(i=20 , j=6 ; j<9 ; j++)
					for(x=24 , y=11 ; x<27 ; x++)
						cube[i][j] = cube[x][y];
					
				for(i=6 , j=12 ; i<9 ; i++)
					for(x=11 , y=6 ; y<9 ; y++)
						cube[i][j] = cube[x][y];
					
				for(i=12 , j=24 ; j<27 ; j++)
					for(x=6 , y=21 ; x<9 ; x++)
						cube[i][j] = cube[x][y];
					
				for(i=24 , j=20 ; i<27 ; i++)
					for(x=21 , y=24 ; y<27 ; y++)
						cube[i][j] = cube[x][y];
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='h')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for(i=24 ; i<27 ; i++)
				{
					for(j=21 ; j>=13 ; j--)
						cube[i][j] = cube[i][j-1];
				}
				
				for(j=24 ; j<27 ; j++)
				{
					for(i=11 ; i<20 ; i++)
						cube[i][j] = cube[i+1][j];
				}
				
				for(i=6 ; i<9 ; i++)
				{
					for(j=11 ; j<20 ; j++)
						cube[i][j] = cube[i][j+1];
				}
					
				for(j=6 ; j<9 ; j++)
				{
					for(i=21 ; i>=13 ; i--)
						cube[i][j] = cube[i-1][j];
				}
				
				for(i=20 , j=24 ; j<27 ; j++)
					for(x=24 , y=21 ; x<27 ; x++)
						cube[i][j] = cube[x][y];
					
				for(i=6 , j=20 ; i<9 ; i++)
					for(x=11 , y=24 ; y<27 ; y++)
						cube[i][j] = cube[x][y];
					
				for(i=12 , j=6 ; j<9 ; j++)
					for(x=6 , y=11 ; x<9 ; x++)
						cube[i][j] = cube[x][y];
				
				for(i=24 , j=12 ; i<27 ; i++)
					for(x=21 , y=6 ; y<9 ; y++)
						cube[i][j] = cube[x][y];
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='m')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for(i=27 ; i<30 ; i++)
				{
					for(j=11 ; j<20 ; j++)
						cube[i][j] = cube[i][j+1];
				}
				
				for(j=3 ; j<6 ; j++)
				{
					for(i=11 ; i<20 ; i++)
						cube[i][j] = cube[i+1][j];
				}
				
				for(i=3 ; i<6 ; i++)
				{
					for(j=21 ; j>=12 ; j--)
						cube[i][j] = cube[i][j-1];
				}
					
				for(j=27 ; j<30 ; j++)
				{
					for(i=21 ; i>=12 ; i--)
						cube[i][j] = cube[i-1][j];
				}
				
				for(i=20 , j=3 ; j<6 ; j++)
					for(x=27 , y=11 ; x<30 ; x++)
						cube[i][j] = cube[x][y];
					
				for(i=3 , j=12 ; i<6 ; i++)
					for(x=11 , y=3 ; y<6 ; y++)
						cube[i][j] = cube[x][y];
					
				for(i=12 , j=27 ; j<30 ; j++)
					for(x=3 , y=21 ; x<6 ; x++)
						cube[i][j] = cube[x][y];
					
				for(i=27 , j=20 ; i<30 ; i++)
					for(x=21 , y=27 ; y<30 ; y++)
						cube[i][j] = cube[x][y];
			}
			
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=30 , y=0 ; j<39 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=30 , x=0 ; j<39 || x<9 ; j++ , x++)
			{
				for(i=20 , y=0 ; i>11 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t=='n')
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for(i=27 ; i<30 ; i++)
				{
					for(j=21 ; j>=13 ; j--)
						cube[i][j] = cube[i][j-1];
				}
				
				for(j=27 ; j<30 ; j++)
				{
					for(i=11 ; i<20 ; i++)
						cube[i][j] = cube[i+1][j];
				}
				
				for(i=3 ; i<6 ; i++)
				{
					for(j=11 ; j<20 ; j++)
						cube[i][j] = cube[i][j+1];
				}
					
				for(j=3 ; j<6 ; j++)
				{
					for(i=21 ; i>=13 ; i--)
						cube[i][j] = cube[i-1][j];
				}
				
				for(i=20 , j=27 ; j<30 ; j++)
					for(x=27 , y=21 ; x<30 ; x++)
						cube[i][j] = cube[x][y];
					
				for(i=3 , j=20 ; i<6 ; i++)
					for(x=11 , y=27 ; y<30 ; y++)
						cube[i][j] = cube[x][y];
					
				for(i=12 , j=3 ; j<6 ; j++)
					for(x=3 , y=11 ; x<6 ; x++)
						cube[i][j] = cube[x][y];
				
				for(i=27 , j=12 ; i<30 ; i++)
					for(x=21 , y=3 ; y<6 ; y++)
						cube[i][j] = cube[x][y];
			}
			
			for(i=20 , x=0 ; i>=12 || x<9; i-- , x++)
			{
				for(j=30 , y=0 ; j<39 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=30 , x=0 ; j<39 || x<9 ; j++ , x++)
			{
				for(i=12 , y=0 ; i<21 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t==75) // ��
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for(i=21 ; i<30 ; i++)
				{
					for(j=11 ; j<20 ; j++)
						cube[i][j] = cube[i][j+1];
				}
				
				for(j=3 ; j<12 ; j++)
				{
					for(i=11 ; i<20 ; i++)
						cube[i][j] = cube[i+1][j];
				}
				
				for(i=3 ; i<12 ; i++)
				{
					for(j=21 ; j>=12 ; j--)
						cube[i][j] = cube[i][j-1];
				}
					
				for(j=21 ; j<30 ; j++)
				{
					for(i=21 ; i>=12 ; i--)
						cube[i][j] = cube[i-1][j];
				}
				
				for(i=20 , j=11 , x=21 , y=11; j>=3 || x<30 ;x++, j--)
					cube[i][j] = cube[x][y];
					
				for(i=3 , j=12 ,x=11 , y=3 ; i<12 || y<12 ;y++, i++)
					cube[i][j] = cube[x][y];
					
				for(i=12 , j=29 , x=3 , y=21 ; j>=21 || x<12 ;x++, j--)
					cube[i][j] = cube[x][y];
					
				for(i=21 , j=20 , x=21 , y=21 ; i<30 || y<30 ;y++, i++)
					cube[i][j] = cube[x][y];
			}
			
			for(i=20 , x=0 ; i>=12 || x<9; i-- , x++)
			{
				for(j=12 , y=0 ; j<21 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=12 , x=0 ; j<21 || x<9 ; j++ , x++)
			{
				for(i=12 , y=0 ; i<21 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=30 , y=0 ; j<39 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=30 , x=0 ; j<39 || x<9 ; j++ , x++)
			{
				for(i=20 , y=0 ; i>11 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t==72) // ��
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=12 ; j<21 ; j++ )
				{
					for( i=2 ; i<29 ; i++ )
					{
						cube[i][j] = cube[i+1][j] ;
					}
				}
			
				for( i=0 , x=9 ; i<3 ; i++ , x++ )
				{
					for(j=12 , y=38 ; j<21 ; j++ , y-- )
					{
						cube[x][y] = cube[i][j];
					}
				}
				
			
				for( j=30 ; j<39 ; j++ )
				{
					for( i=24 ; i>5 ; i-- )
					{
						cube[i][j] = cube[i-1][j] ;
					}
				}
				
				for( i=21 , x=29 ; i<24 ; i++ , x++ )
				{
					for( j=38 , y=12 ; j>=30 ; j-- , y++ )
					{
						cube[x][y] = cube[i][j];
					}
				}
			}

			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=21 , y=0 ; j<30 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=29 , x=0 ; j>=21 || x<9 ; j-- , x++)
			{
				for(i=12 , y=0 ; i<21 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=3 , y=0 ; j<12 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=3 , x=0 ; j<12 || x<9 ; j++ , x++)
			{
				for(i=20 , y=0 ; i>11 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t==77) // ��
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for(i=21 ; i<30 ; i++)
				{
					for(j=21 ; j>=13 ; j--)
						cube[i][j] = cube[i][j-1];
				}
				
				for(j=21 ; j<30 ; j++)
				{
					for(i=11 ; i<20 ; i++)
						cube[i][j] = cube[i+1][j];
				}
				
				for(i=3 ; i<12 ; i++)
				{
					for(j=11 ; j<20 ; j++)
						cube[i][j] = cube[i][j+1];
				}
					
				for(j=3 ; j<12 ; j++)
				{
					for(i=21 ; i>=13 ; i--)
						cube[i][j] = cube[i-1][j];
				}
				
				for(i=20 , j=21 , x=21 , y=21 ; j<30 || x<30 ;x++, j++)
					cube[i][j] = cube[x][y];
					
				for(i=11 , j=20 , x=11 , y=21 ; i>=3 || y<30 ;y++, i--)
					cube[i][j] = cube[x][y];
					
				for(i=12 , j=3 , x=3 , y=11 ; j<12 || x<12 ;x++, j++)
					cube[i][j] = cube[x][y];
				
				for(i=29 , j=12 , x=21 , y=3 ; i>=21 || y<12 ;y++, i--)
					cube[i][j] = cube[x][y];
			}
		
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=12 , y=0 ; j<21 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=12 , x=0 ; j<21 || x<9 ; j++ , x++)
			{
				for(i=20 , y=0 ; i>11 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			for(i=20 , x=0 ; i>=12 || x<9; i-- , x++)
			{
				for(j=30 , y=0 ; j<39 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=30 , x=0 ; j<39 || x<9 ; j++ , x++)
			{
				for(i=12 , y=0 ; i<21 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(t==80) // ��
		{
			gotoxy();
			
			for( c=0 ; c<9 ; c++ )
			{
				for( j=12 ; j<21 ; j++ )
				{
					for( i=30 ; i>=2 ; i-- )
					{
						cube[i][j] = cube[i-1][j] ;
					}
				}
				
				for( i=30 , x=21 ; i<33 ; i++ , x++ )
				{
					for(j=12 , y=38 ; j<21 ; j++ , y-- )
					{
						cube[x][y] = cube[i][j];
					}
				}
			
				for( j=30 ; j<39 ; j++ )
				{
					for( i=6 ; i<23 ; i++ )
					{
						cube[i][j] = cube[i+1][j] ;
					}
				}
				
				
				for( i=11, x=3, j=38 , y=12 ; j>=30 ; j-- , y++ )
				{
					cube[x][y] = cube[i][j];
				}
			}
			
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=21 , y=0 ; j<30 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=21 , x=0 ; j<30 || x<9 ; j++ , x++)
			{
				for(i=20 , y=0 ; i>11 || y<9 ; i-- , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			for(i=12 , x=0 ; i<21 || x<9; i++ , x++)
			{
				for(j=3 , y=0 ; j<12 || y<9 ; j++ , y++)
				{
					tempcube[x][y] = cube[i][j];
				}
			}
			
			for(j=11 , x=0 ; j>=3 || x<9 ; j-- , x++)
			{
				for(i=12 , y=0 ; i<21 || y<9 ; i++ , y++)
				{
					cube[i][j] = tempcube[x][y];
				}
			}
			
			cubefun(cube,view,speed);
		}
		
		if(i=='c')
		{
			gotoxy();
			
			for(i=0 ; i<33 ; i++)
				for(j=0 ; j<42 ; j++)
					cube[i][j] = tempcube2[i][j];
				
			cubefun(cube,view,speed);
		}

		if(i==32)//�����̽���
		{
			
			while(1)//1�� ����
			{
                
                if(kbhit())
                {
                    ch = getch();
                }
                
                if(ch=='p')
                {
                    break;
                }
                    
                    
				while(1)//�Ͼ�� ���ڰ�
				{
                    if(kbhit())
                    {
                        ch = getch();
                    }
                    
                    if(ch=='p')
                    {
                        break;
                    }
                    
    
					//�Ͼ�� �Ʒ���
					if(cube[6][15]==15)
					{
					gotoxy();
					
					turn(72,cube,view,speed);
					Sleep(speed);
				}
					
					if(cube[15][6]==15)
					{
					gotoxy();
					
					turn(75,cube,view,speed);
					Sleep(speed);
						
					turn(72,cube,view,speed);
					Sleep(speed);
				}
					
					if(cube[15][15]==15)
					{
					gotoxy();
					
					turn(72,cube,view,speed);
					Sleep(speed);
						
					turn(72,cube,view,speed);
					Sleep(speed);
				}
					
					if(cube[15][24]==15)
					{
					gotoxy();
					
					turn(75,cube,view,speed);
					Sleep(speed);
					
					turn(80,cube,view,speed);
					Sleep(speed);
				}
					
					if(cube[15][33]==15)
					{
					;
				}
					
					if(cube[24][15]==15)
					{
					gotoxy();
					
					turn(80,cube,view,speed);
					Sleep(speed);
				}		
					//�ϾȻ� �Ʒ��� ��
				
					//�ʷϻ��� ������
					if(cube[15][6]==2)
					{
					gotoxy();
					
					turn(77,cube,view,speed);
					Sleep(speed);
				}
					
					if(cube[6][15]==2)
					{
					gotoxy();
					
					turn(77,cube,view,speed);
					Sleep(speed);
					
					turn(77,cube,view,speed);
					Sleep(speed);
				}
					
					if(cube[15][24]==2)
					{
						gotoxy();
						
						turn(75,cube,view,speed);
						Sleep(speed);
					}
					//�ʷϻ��� ������ ��
				
					//�Ͼ�� ���ڰ� ���߱�
					
					//�Ķ���
					if(cube[3][15]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('r',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[6][12]==15 && cube[12][33]!=15)//���������� �����   
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[6][12]==15 && cube[15][30]!=15)//���������� �����  
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[6][12]==15 && cube[15][36]!=15)//���������� �����  
					{
						gotoxy();
						
						turn('q',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[6][12]==15 && cube[18][33]!=15)//���������� ����Ʒ�  
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[6][18]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[6][18]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('e',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[6][18]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[6][18]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[9][15]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[9][15]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('r',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[9][15]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('r',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[9][15]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('r',cube,view,speed);
						Sleep(speed);
					}
					
					//������
					if(cube[12][6]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('r',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][6]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('r',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][6]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('r',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][6]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('r',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][3]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][9]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('r',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][9]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][9]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][9]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][6]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][6]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][6]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][6]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					//�����
					if(cube[12][15]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][15]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][15]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][15]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][12]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][12]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][12]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][12]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][18]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][18]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][18]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][18]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][15]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][15]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][15]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][15]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
					}
					
					//��Ȳ��
					if(cube[12][24]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('t',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][24]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][24]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][24]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][21]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][21]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][21]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][21]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][27]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][24]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][24]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][24]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[18][24]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('b',cube,view,speed);
						Sleep(speed);
					}
					
					//�ʷϻ�
					if(cube[21][15]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[21][15]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[21][15]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[21][15]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[24][12]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[24][12]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[24][12]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('a',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[24][12]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[24][18]==15 && cube[12][33]!=15)
					{
						gotoxy();
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[24][18]==15 && cube[15][30]!=15)
					{
						gotoxy();
						
						turn('d',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[24][18]==15 && cube[15][36]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[24][18]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[27][15]==15 && cube[18][33]!=15)
					{
						gotoxy();
						
						turn('v',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[12][33]==15 && cube[15][30]==15 && cube[15][36]==15 && cube[18][33]==15)
						break;
				}
						//�Ͼ�� ���ڰ� ��
						
				while(1)//���� ����
				{
                    if(kbhit())
                    {
                        ch = getch();
                    }
                    
                    if(ch=='p')
                    {
                        break;
                    }
                
					while(1)//�ʷϻ� �������
					{
                        if(kbhit())
                        {
                            ch = getch();
                        }
                        
                        if(ch=='p')
                        {
                            break;
                        }
                        
						if(cube[27][15]!=2)
						{
							gotoxy();
						
							turn('n',cube,view,speed);
							Sleep(speed);
						}
						
						if(cube[27][15]==2)
							break;
					}
					
					if(cube[15][27]!=6 && cube[3][15]!=9 && cube[15][3]!=12)//�پȸ�����
					{
						gotoxy();
					
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('r',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][27]==6 && cube[3][15]!=9 && cube[15][3]!=12)//��,�ָ�����
					{
						gotoxy();
					
						turn('t',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('r',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('t',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][27]!=6 && cube[3][15]!=9 && cube[15][3]==12)//��,��������
					{
						gotoxy();
					
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('m',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('n',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][27]!=6 && cube[3][15]==9 && cube[15][3]!=12)//��,�ĸ�����
					{
						gotoxy();
					
						turn('g',cube,view,speed);
						Sleep(speed);
						
						turn('g',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('g',cube,view,speed);
						Sleep(speed);
						
						turn('g',cube,view,speed);
						Sleep(speed);
					}
					
					if(cube[15][27]==6 && cube[3][15]==9 && cube[15][3]==12)//�ٸ�����
						break;
				}
						//���� ��
				
				while(1)//�ڳ� ����
				{
                    if(kbhit())
                    {
                        ch = getch();
                    }
                    
                    if(ch=='p')
                    {
                        break;
                    }
                
					while(1)//�Ͼ�� �ٸ���
					{
						if(kbhit())
                        {
                            ch = getch();
                        }
                        
                        if(ch=='p')
                        {
                            break;
                        }
                
						if(cube[12][30]!=15 || cube[12][36]!=15 || cube[18][30]!=15 || cube[18][36]!=15)//3�����ִ� 1��������
						{
						for(i=0 ; i<4 ; i++)
						{					
							if(cube[18][21]==15 && cube[18][18]==6)
							{
								gotoxy();
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==2 && cube[18][18]==15)
							{
								gotoxy();
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==6 && cube[18][18]==2)
							{
								gotoxy();
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==15 && cube[18][18]==9)
							{
								gotoxy();
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==6 && cube[18][18]==15)
							{
								gotoxy();
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==9 && cube[18][18]==6)
							{
								gotoxy();
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==15 && cube[18][18]==12)
							{
								gotoxy();
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==9 && cube[18][18]==15)
							{
								gotoxy();
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==12 && cube[18][18]==9)
							{
								gotoxy();
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==15 && cube[18][18]==2)
							{
								gotoxy();
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==12 && cube[18][18]==15)
							{
								gotoxy();
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][21]==2 && cube[18][18]==12)
							{
								gotoxy();
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
							}
							
							
							gotoxy();
							
							turn('y',cube,view,speed);
							Sleep(speed);
						}
						}			
						//3�����ִ� 1�������� ��
					
						if(cube[12][30]!=15 || cube[12][36]!=15 || cube[18][30]!=15 || cube[18][36]!=15)//1�����ִ� �ڱ��ڽ� 1��������
						{
							for(i=0 ; i<4 ; i++)
							{
								if(i==0)
								{
									x=2;
									y=6;
								}
								
								if(i==1)
								{
									x=6;
									y=9;
								}
								
								if(i==2)
								{
									x=9;
									y=12;
								}
								
								if(i==3)
								{
									x=12;
									y=2;
								}
								
								if(cube[27][18]==15 && cube[18][27]==x)
								{
									gotoxy();
									
									turn('e',cube,view,speed);
									Sleep(speed);
									
									turn('y',cube,view,speed);
									Sleep(speed);
									
									turn('d',cube,view,speed);
									Sleep(speed);
									
									turn('u',cube,view,speed);
									Sleep(speed);
									
									turn('e',cube,view,speed);
									Sleep(speed);
									
									turn('y',cube,view,speed);
									Sleep(speed);
									
									turn('d',cube,view,speed);
									Sleep(speed);
									
									turn('u',cube,view,speed);
									Sleep(speed);
								}
								
								if(cube[27][18]==y && cube[18][27]==15)
								{
									gotoxy();
									
									turn('e',cube,view,speed);
									Sleep(speed);
									
									turn('u',cube,view,speed);
									Sleep(speed);
									
									turn('d',cube,view,speed);
									Sleep(speed);
									
									turn('y',cube,view,speed);
									Sleep(speed);
									
									turn('e',cube,view,speed);
									Sleep(speed);
									
									turn('u',cube,view,speed);
									Sleep(speed);
									
									turn('d',cube,view,speed);
									Sleep(speed);
									
									turn('y',cube,view,speed);
									Sleep(speed);
								}
									
								gotoxy();
								
								turn(75,cube,view,speed);
								Sleep(speed);
							}
						}
						//1�����ִ� �ڱ��ڽ� 1�������� ��
						
						for(i=0 ; i<4 ; i++)//���δٸ���� Ʈ����Ʈ�� ����
						{		
							if(i==0)
							{
								x=2;
							}
							
							if(i==1)
							{
								x=6;
							}
							
							if(i==2)
							{
								x=9;
							}
							
							if(i==3)
							{
								x=12;
							}
							
							
							if(cube[27][18]!=x)
							{
								gotoxy();
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
							}
							
							gotoxy();
							
							turn(75,cube,view,speed);
							Sleep(speed);
						}
					
						if(cube[12][33]!=15 || cube[15][30]!=15 || cube[15][36]!=15 || cube[18][33]!=15)
							break;
						
						if(cube[12][30]==15 && cube[12][36]==15 && cube[18][30]==15 && cube[18][36]==15)
							break;	
					}
					
						for(i=0 ; i<4 ; i++)//���δٸ���� Ʈ����Ʈ�� ����
							{		
								if(i==0)
								{
									x=2;
								}
								
								if(i==1)
								{
									x=6;
								}
								
								if(i==2)
								{
									x=9;
								}
								
								if(i==3)
								{
									x=12;
								}
								
								
								if(cube[27][18]!=x)
								{
									gotoxy();
									
									turn('e',cube,view,speed);
									Sleep(speed);
									
									turn('u',cube,view,speed);
									Sleep(speed);
									
									turn('d',cube,view,speed);
									Sleep(speed);
									
									turn('y',cube,view,speed);
									Sleep(speed);
								}
								
								gotoxy();
								
								turn(75,cube,view,speed);
								Sleep(speed);
							}
						
					
					if(cube[12][30]==15 && cube[12][36]==15 && cube[18][30]==15 && cube[18][36]==15  && cube[27][12]==cube[27][18]&& cube[12][27]==cube[18][27]&& cube[12][3]==cube[18][3]&& cube[3][12]==cube[3][18])
						break;
					
					if(cube[12][33]!=15 || cube[15][30]!=15 || cube[15][36]!=15 || cube[18][33]!=15)
						break;
				}
					//�ڳ� ��
						
				if(cube[12][33]==15 && cube[15][30]==15 && cube[15][36]==15 && cube[18][33]==15  && cube[12][30]==15 && cube[12][36]==15 && cube[18][30]==15 && cube[18][36]==15  && cube[27][12]==cube[27][18]&& cube[12][27]==cube[18][27]&& cube[12][3]==cube[18][3]&& cube[3][12]==cube[3][18])
						break;	

				if(cube[12][33]!=15 || cube[15][30]!=15 || cube[15][36]!=15 || cube[18][33]!=15)
					break;
					
			}
				//1�� ��
			
			
			while(1)//2�� ����
			{
                if(kbhit())
                {
                    ch = getch();
                }
                
                if(ch=='p')
                {
                    break;
                }
                
						for(i=0 ; i<4 ; i++)//3�����ִ� 2�����߱�
						{
							if(cube[18][15]==2 && cube[21][15]==6)
							{
								gotoxy();
										
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][15]==6 && cube[21][15]==2)
							{
								gotoxy();
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][15]==6 && cube[21][15]==9)
							{
								gotoxy();
										
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][15]==9 && cube[21][15]==6)
							{
								gotoxy();
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][15]==9 && cube[21][15]==12)
							{
								gotoxy();
										
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][15]==12 && cube[21][15]==9)
							{
								gotoxy();
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][15]==12 && cube[21][15]==2)
							{
								gotoxy();
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[18][15]==2 && cube[21][15]==12)
							{
								gotoxy();
								
								turn('h',cube,view,speed);
								
								turn('n',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('j',cube,view,speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
							}
							
							gotoxy();
								
							turn('y',cube,view,speed);
							Sleep(speed);
						}
							//3�����ִ� 2�����߱� ��
						
						if(cube[24][12]!=2 || cube[24][18]!=2 || cube[12][24]!=6 || cube[18][24]!=6 || cube[6][12]!=9 || cube[6][18]!=9 || cube[12][6]!=12 || cube[18][6]!=12)//2���� �ڱⲨ���� �ٸ���������
						{
						for(i=0 ; i<4 ; i++)
						{
							if(i==0)
							{
								x=2;
								y=6;
							}
							
							if(i==1)
							{
								x=6;
								y=9;
							}
							
							if(i==2)
							{
								x=9;
								y=12;
							}
							
							if(i==3)
							{
								x=12;
								y=2;
							}
							
							if(cube[24][18]!=x || cube[18][24]!=y)
							{
								gotoxy();
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn(75,cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn(77,cube,view,speed);
								Sleep(speed);
							}
							
							gotoxy();
							
							turn(75,cube,view,speed);
							Sleep(speed);
						}
						}
						
						
						if(cube[24][12]==2 && cube[24][18]==2 && cube[12][24]==6 && cube[18][24]==6 && cube[6][12]==9 && cube[6][18]==9 && cube[12][6]==12 && cube[18][6]==12)
							break;
			}
				//2�� ��
			
		
			while(1)//3�� ����
			{
                if(kbhit())
                {
                    ch = getch();
                }
                
                if(ch=='p')
                {
                    break;
                }
                
				while(1)//����� ���ڰ� ����
				{
                    if(kbhit())
                    {
                        ch = getch();
                    }
                    
                    if(ch=='p')
                    {
                        break;
                    }
                    
					if(cube[12][15]!=14 && cube[15][12]!=14 && cube[15][18]!=14 && cube[18][15]!=14)//���϶�
					{
						gotoxy();
											
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('g',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('f',cube,view,speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					else if(cube[12][15]!=14 && cube[15][12]!=14)//�����϶�
					{
						gotoxy();
											
						turn('b',cube,view,speed);
						
						turn('g',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('f',cube,view,speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					else if(cube[12][15]!=14 && cube[15][18]!=14)//�����϶�
					{
						gotoxy();
							
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						
						turn('g',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('f',cube,view,speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					else if(cube[15][18]!=14 && cube[18][15]!=14)//�����϶�
					{
						gotoxy();
							
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						
						turn('g',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('f',cube,view,speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					else if(cube[15][12]!=14 && cube[18][15]!=14)//�����϶�
					{
						gotoxy();
							
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						
						turn('g',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('f',cube,view,speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					else if(cube[12][15]!=14 && cube[18][15]!=14)//1���϶�
					{
						gotoxy();
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					else if(cube[15][12]!=14 && cube[15][18]!=14)//1���϶�
					{
						gotoxy();
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
					
					else
						break;
				}
					//����� ���ڰ�  ��
				
				while(1)//����� ��ü ����
				{
                    if(kbhit())
                    {
                        ch = getch();
                    }
                    
                    if(ch=='p')
                    {
                        break;
                    }
                
					if(cube[12][9]==14 && cube[21][12]==14 && cube[21][18]==14)//���ڵι�
					{
						gotoxy();
											
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
					}
				
					if(cube[9][12]==14 && cube[9][18]==14 && cube[21][12]==14 && cube[21][18]==14)//����Ʈ����Ʈ
					{
						gotoxy();
											
						turn('b',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('v',cube,view,speed);
						Sleep(speed);
					}
				
					if(cube[9][12]==14 && cube[12][21]==14 && cube[18][12]==14 && cube[21][18]==14)//�����
					{
						gotoxy();
											
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
					}
				
					if(cube[12][9]==14 && cube[9][18]==14 && cube[21][12]==14 && cube[18][18]==14)//�����
					{
						gotoxy();
											
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
					}
				
					if(cube[12][12]==14 && cube[9][18]==14 && cube[18][12]==14 && cube[21][18]==14)//��ũ��������
					{
						gotoxy();
											
						turn(72,cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn(80,cube,view,speed);
						Sleep(speed);
					}
				
					if(cube[12][9]==14 && cube[12][18]==14 && cube[18][9]==14 && cube[18][18]==14)//��ũ�������
					{
						gotoxy();
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
					}
				
					if(cube[12][12]==14 && cube[9][18]==14 && cube[18][9]==14 && cube[18][18]==14)//8��
					{
						gotoxy();
						
						turn(72,cube,view,speed);
						Sleep(speed);
						
						turn('d',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('q',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn('e',cube,view,speed);
						Sleep(speed);
						
						turn('y',cube,view,speed);
						Sleep(speed);
						
						turn('a',cube,view,speed);
						Sleep(speed);
						
						turn('u',cube,view,speed);
						Sleep(speed);
						
						turn(80,cube,view,speed);
						Sleep(speed);
					}
				
				
					if(cube[12][12]==14 && cube[12][18]==14 && cube[18][12]==14 && cube[18][18]==14)//�ٸ���
						break;
					
					gotoxy();
							
					turn('y',cube,view,speed);
					Sleep(speed);
				}
					//����� ��ü ��
				
				while(1)//������
				{
                    if(kbhit())
                    {
                        ch = getch();
                    }
                    
                    if(ch=='p')
                    {
                        break;
                    }
                
					if(cube[9][12]==9 && cube[9][15]==9 && cube[9][18]==9 && cube[21][12]==2 && cube[21][15]==2 && cube[21][18]==2 && cube[12][9]==12 && cube[15][9]==12 && cube[18][9]==12)
						break;
					
					for(i=0 ; i<4 ; i++)
					{
						if(cube[9][12]==9 && cube[9][15]==9 && cube[9][18]==9 && cube[21][12]==2 && cube[21][15]==2 && cube[21][18]==2 && cube[12][9]==12 && cube[15][9]==12 && cube[18][9]==12)
							break;
						
						for(j=0 ; j<4 ; j++)
						{
							if(j==0)
							{
								x=2;
								y=6;
								b=9;
								c=12;
							}
							if(j==1)
							{
								x=12;
								y=2;
								b=6;
								c=9;
							}
							if(j==2)
							{
								x=9;
								y=12;
								b=2;
								c=6;
							}
							if(j==3)
							{
								x=6;
								y=9;
								b=12;
								c=2;
							}
							
							
							if(cube[9][12]==9 && cube[9][15]==9 && cube[9][18]==9 && cube[21][12]==2 && cube[21][15]==2 && cube[21][18]==2 && cube[12][9]==12 && cube[15][9]==12 && cube[18][9]==12)
								break;
							
							if(cube[9][12]==x && cube[9][15]==b && cube[9][18]==x && cube[21][12]==b && cube[21][15]==x && cube[21][18]==b && cube[15][9]==c)//�ι��ι�
							{
								gotoxy();
													
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								break;
							}
						
							if(cube[9][15]==b && cube[15][9]==c && cube[21][15]==x && cube[15][21]==y)//�ʺ� ������
							{
								gotoxy();
													
								turn(80,cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('m',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn(72,cube,view,speed);
								Sleep(speed);
							}
						
							if(cube[15][9]==b && cube[21][12]==x && cube[21][15]==x && cube[21][18]==x)//���� Ʈ����Ʈ ����
							{
								gotoxy();
													
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								break;
							}
						
							if(cube[15][9]==y && cube[21][12]==x && cube[21][15]==x && cube[21][18]==x)//������ Ʈ����Ʈ ����
							{
								gotoxy();
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								break;
							}
						
							if(cube[9][12]==b && cube[9][18]==x && cube[12][21]==c && cube[18][21]==y && cube[21][12]==b && cube[21][18]==x && cube[12][9]==c && cube[18][9]==y)//����1
							{
								gotoxy();
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn(72,cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn(80,cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[9][12]==x && cube[9][18]==b && cube[12][21]==y && cube[18][21]==c && cube[21][12]==x && cube[21][18]==b && cube[12][9]==y && cube[18][9]==c)//����2
							{
								gotoxy();
								
								turn(72,cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn(80,cube,view,speed);
								Sleep(speed);
							}
							
							if(cube[12][9]==cube[18][9] && cube[12][21]!=cube[18][21])//�⺻
							{
								gotoxy();
													
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('q',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('a',cube,view,speed);
								Sleep(speed);
							}
						
							if(cube[9][12]==cube[15][9] && cube[9][15]==cube[12][9] && cube[9][18]==cube[15][9] && cube[9][15]==cube[18][9])//���1
							{
								gotoxy();
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								break;
							}
								
							if(cube[9][12]==cube[15][21] && cube[9][15]==cube[12][21] && cube[9][18]==cube[15][21] && cube[9][15]==cube[18][21])//���2
							{
								gotoxy();
								
								turn(77,cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('d',cube,view,speed);
								Sleep(speed);
								
								turn('y',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('e',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
								
								turn('u',cube,view,speed);
								Sleep(speed);
									
								turn(75,cube,view,speed);
								Sleep(speed);
								
								
								break;
							}
							
							if(cube[9][12]==9 && cube[9][15]==9 && cube[9][18]==9 && cube[21][12]==2 && cube[21][15]==2 && cube[21][18]==2 && cube[12][9]==12 && cube[15][9]==12 && cube[18][9]==12)
								break;
							
							gotoxy();
								
							turn('y',cube,view,speed);
							Sleep(speed);
						}
						
						if(cube[9][12]==9 && cube[9][15]==9 && cube[9][18]==9 && cube[21][12]==2 && cube[21][15]==2 && cube[21][18]==2 && cube[12][9]==12 && cube[15][9]==12 && cube[18][9]==12)
							break;
							
						gotoxy();
								
						turn(75,cube,view,speed);
						Sleep(speed);
					}
				}
				
				if(cube[9][12]==9 && cube[9][15]==9 && cube[9][18]==9 && cube[21][12]==2 && cube[21][15]==2 && cube[21][18]==2 && cube[12][9]==12 && cube[15][9]==12 && cube[18][9]==12)
					break;
				
					gotoxy();
								
					turn('y',cube,view,speed);
					Sleep(speed);
					
					gotoxy();
								
					turn(75,cube,view,speed);
					Sleep(speed);
				}
				//3�� ��
				
			if(cube[9][12] == cube[12][6])
			{
				gotoxy();
							
				turn('j',cube,view,speed);
				
				turn('m',cube,view,speed);
				Sleep(speed);
			}
			if(cube[9][12] == cube[12][24])
			{
				gotoxy();
							
				turn('h',cube,view,speed);
				
				turn('n',cube,view,speed);
				Sleep(speed);
			}
			if(cube[9][12] == cube[24][12])
			{
				gotoxy();
							
				turn('j',cube,view,speed);
				
				turn('m',cube,view,speed);
				Sleep(speed);
				
				turn('j',cube,view,speed);
				
				turn('m',cube,view,speed);
				Sleep(speed);
			}
		
			gotoxy();
			cubefun(cube,view,speed);
		}
        
        if(ch=='p')
        {
            ch=0;
            return 0;
        }
		
		gotoxy();
		cubefun(cube,view,speed);
}

int main(void)
{
	int complete,where,i,j,k,x,y,b,c,temp;
	int random=1;
	int view=0;
	int speed=100;
	time_t st,ed;
	int record=0;
    char ch;
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursor(0);
	
	int cube[33][42] = {
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{15,15,15  ,12,12,12,12,12,12,12,12,12,  14,14,14,14,14,14,14,14,14,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		{ 2, 2, 2  , 2, 2, 2, 2, 2, 2, 2, 2, 2,   2, 2, 2, 2, 2, 2, 2, 2, 2,   6, 6, 6, 6, 6, 6, 6, 6, 6,  15,15,15,15,15,15,15,15,15 ,  0, 0, 0},
		
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
		{ 0, 0, 0  ,12,12,12,12,12,12,12,12,12,   9, 9, 9, 9, 9, 9, 9, 9, 9,   9, 9, 9, 9, 9, 9, 9, 9, 9,  14,14,14,14,14,14,14,14,14 ,  0, 0, 0},
	};
	
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC,&csbi);
	COLORREF a;
	
	SetConsoleTextAttribute(hout,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	SetConsoleTextAttribute(hC,0);
	
	system("cls");
	
	system("mode con: cols=110 lines=52"); 
	
	printf("");
	
	gotoxy();
	SetConsoleTextAttribute(hC,15|0);
printf("\n\n	                              SP                          Ui                                   \n");
printf("                                     .Br                         .B:                                   \n");
printf("                                     BB                          BB                                    \n");
printf("                                    ,B2        .,               .B,                                    \n");
printf("   7B:2BB8 5BBB     vBBBBBq    ,BBBBBB       0BBBBB             BB PBBq    MB     Y                    \n");
printf("   BBBB BBBB.BB   .BBq. BB.   NBB. 2BB     :BB,  BB             BBBk:LBB  iBS    BB                    \n");
printf("  :BBu  BBi  B8  ,BB    BB   BB:    Bq    .Br  LBBi            LBB    BB  BB    MBi                    \n");
printf("  BBi  YB,  :B:  BB    :BY  LBi    PBY  rBBBNBBN,              BB    .BP  Br   BBB                     \n");
printf("  B8   BB   NB  .BU   LBB:  BB    LBBJ    BB     .i           .B    7BZ  UB  iBBB,                     \n");
printf(" 1B,  UB:   BB   BBr7BBLBi  2BE:jBB7BB    NBr.:NBBL           YBY7GBBr   PBGBB75B                      \n");
printf(" 71   r2    r;   .ZBM7  B,   vBBBL  1B     7BBBN:              FBMS,      iu:  BB                      \n");
printf("                                                                              .Bv                      \n");
printf("                                                                              UB.                      \n");
printf("                                                                              BB                       \n");
printf("                                                                               .                       \n");
                                                                                                       printf("\n");
printf("               .    ,,                          .          SBBZ.                                       \n");
printf("             .BB    BB   MB      ,BBBBBSr      7Bv       :BB,iNB7                                      \n");
printf("             8B  irOBr   BB       ...::BBi     MB        7B.   Bk                                      \n");
printf("             BBGBBOBB,  :BBYSqr       7Br      BB         UBBMB8                                       \n");
printf("             BY    XB   SBJuSP:      BBB       Bq         rB. BF                                       \n");
printf("             BU  .,BB   XB         .BB JBJ    .B;         BB ,B                                        \n");
printf("             BBBBBGUr   MB        .BB   vBX   ;B.       .BBBMBBBBBB                                    \n");
printf("                    :XSjBB:       BB     7B:  UB         Y.       .                                    \n");
printf("                    7SULr5BB      .           ZB             :Ek.                                      \n");
printf("                          Bj                  BB           :BBrBBB                                     \n");
printf("                         vB                   BB           BB   1B                                     \n");
printf("                         BB                   rU           MBPSBBi                                     \n");
printf("                         BB                                  7L:                                       \n");
                                                                                                       
	sleep(2);
	SetConsoleTextAttribute(hC,0);
	system("cls");
	
	printf("");
	
	gotoxy();
	
	
	/*										//����� 15
		SetConsoleTextAttribute(hC,0);		//��������
		SetConsoleTextAttribute(hC,15|0);	//����
		
		SetConsoleTextAttribute(hC,12);		//��������
		SetConsoleTextAttribute(hC,13);		//��ȫ����
		SetConsoleTextAttribute(hC,9);		//�Ķ�����
		SetConsoleTextAttribute(hC,11);		//�ϴñ���
		SetConsoleTextAttribute(hC,2);		//�ʷϱ���
		SetConsoleTextAttribute(hC,10);		//���α���
		SetConsoleTextAttribute(hC,14);		//�������
		SetConsoleTextAttribute(hC,6);		//��Ȳ�̾�� �ణ�������
	*/
		
	
	turn('c',cube,view,speed);
	
	srand(GetTickCount());
	
	while(1)
	{
		i = getch();
		
		turn(i,cube,view,speed);
		
		if(i=='x')
		{
			if(record==0)
			{
				record=1;
				st=clock();
				//time(&st);
				printf("                 ");
			}
			
			else if(record==1)
			{
				ed=clock();
				//time(&ed);
				//printf("\n���:%.1lf\n",((double)ed-st/(CLOCKS_PER_SEC))/1000);
				SetConsoleTextAttribute(hC,15|0);
				printf("��� : %.2f��",difftime(ed,st)/CLK_TCK);
				SetConsoleTextAttribute(hC,0);
				record=0;
				st=0;ed=0;
			}
		}
		
		if(i==',')
		{
			speed-=100;
			
			if(speed<0)
			{
				speed=0;
			}
			
			gotoxy();
			cubefun(cube,view,speed);
		}
		
		if(i=='.')
		{
			speed+=100;
			gotoxy();
			cubefun(cube,view,speed);
		}
		
		if(i==13)//����
		{
			
			for(k=0 ; k<30 ; k++)
			{
				random=rand()%18;
                
                
				
				if(random==0)
					turn('q',cube,view,speed);
				
				if(random==1)
					turn('w',cube,view,speed);
				
				if(random==2)
					turn('e',cube,view,speed);
				
				if(random==3)
					turn('a',cube,view,speed);
				
				if(random==4)
					turn('s',cube,view,speed);
				
				if(random==5)
					turn('d',cube,view,speed);
				
				if(random==6)
					turn('r',cube,view,speed);
				
				if(random==7)
					turn('t',cube,view,speed);
				
				if(random==8)
					turn('f',cube,view,speed);
				
				if(random==9)
					turn('g',cube,view,speed);
				
				if(random==10)
					turn('v',cube,view,speed);
				
				if(random==11)
					turn('b',cube,view,speed);
				
				if(random==12)
					turn('y',cube,view,speed);
				
				if(random==13)
					turn('u',cube,view,speed);
				
				if(random==14)
					turn('h',cube,view,speed);
				
				if(random==15)
					turn('j',cube,view,speed);
				
				if(random==16)
					turn('n',cube,view,speed);
				
				if(random==17)
					turn('m',cube,view,speed);
			}
		}
								
		if(i=='z')
		{
			system("cls");
			
			system("mode con: cols=110 lines=24"); 
			
			gotoxy();
			
			if(view==0)
				view=1;
			
			else
			{
				system("mode con: cols=110 lines=52"); 
				view=0;
			}
			
			system("cls");
			
			turn(x,cube,view,speed);
		}
		
		if(i==27)//esc����
			break;
	}
		
	SetConsoleTextAttribute(hC,15|0);
	printf("\nESCŰ�� �����ż� �����մϴ�.\n");
	
	SetConsoleTextAttribute(hC,0);
	
	system("cls");
	
	for(i=0; i<60 ; i++)
		printf("										\n");
		
	gotoxy();
			
	SetConsoleTextAttribute(hC,240);
	cursor(1);
	system("mode con: cols=150 lines=80"); 
	
	system("cls");
		
	return 0;
}