#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "print_statements.h"

void gotoxy(short col, short row)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position= {col,row};
    SetConsoleCursorPosition(h,position);
}

void PrintArray(int rows,int coloumns,char a[rows+10][coloumns+10],int c1[rows+10][coloumns+10],struct player p[])
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    int i,j;
    gotoxy(75,10);
    int t=11;
    for(i=0; i<=rows; i++)

    {
        if(i%2!=0)
        {
            for(j=0; j<=coloumns; j++)
            {
                if(c1[i][j]==1)
                {
                    SetConsoleTextAttribute(hConsole, p[1].colour);
                    printf("%c",a[i][j]);
                    SetConsoleTextAttribute(hConsole, saved_attributes);

                }

                else if(c1[i][j]==0)
                {
                    SetConsoleTextAttribute(hConsole, p[0].colour);
                    printf("%c",a[i][j]);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }
                else
                {
                    printf("%c",a[i][j]);

                }
                if(j==coloumns)
                {
                    gotoxy(75,t++);
                }
            }
        }
        else
        {
            for(j=0; j<=coloumns; j++)
            {
                if(c1[i][j]==1)
                {
                    SetConsoleTextAttribute(hConsole, p[1].colour);
                    printf("%c",a[i][j]);
                    SetConsoleTextAttribute(hConsole, saved_attributes);

                }
                else if(c1[i][j]==3)
                {
                    SetConsoleTextAttribute(hConsole, (p[0].colour*16)+15);
                    printf("%c",a[i][j]);
                    SetConsoleTextAttribute(hConsole, saved_attributes);



                }
                else if(c1[i][j]==4)
                {

                    SetConsoleTextAttribute(hConsole, (p[1].colour*16)+15);
                    printf("%c",a[i][j]);
                    SetConsoleTextAttribute(hConsole, saved_attributes);


                }
                else if(c1[i][j]==0)
                {
                    SetConsoleTextAttribute(hConsole, p[0].colour);
                    printf("%c",a[i][j]);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }
                else
                {
                    printf("%c",a[i][j]);

                }
                if(j==coloumns)
                {
                    gotoxy(75,t++);
                }
            }
        }
    }

}
void PrintInformation(int flag,struct player p[],int RemainingLines,int minutes,int seconds,int t)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    gotoxy(150,1);
    printf("1 --> LEFT");
    gotoxy(150,3);
    printf("3 --> RIGHT");
    gotoxy(150,5);
    printf("5 --> UP");
    gotoxy(150,7);
    printf("2 --> DOWN");
    gotoxy(1,1);
    printf("ENTER 'U' TO UNDO");
    gotoxy(1,3);
    printf("ENTER 'R' TO REDO");
    gotoxy(1,5);
    printf("ENTER 'S' TO SAVE GAME");
    gotoxy(1,7);
    printf("ENTER 'E' TO EXIT GAME");
    t=t+3;
    if(flag==0)
    {
        gotoxy(75,t);
        SetConsoleTextAttribute(hConsole, p[0].colour);
        printf("%s's turn\n",p[0].name);
        SetConsoleTextAttribute(hConsole, saved_attributes);
    }
    else if(flag==1)
    {
        gotoxy(75,t);
        SetConsoleTextAttribute(hConsole, p[1].colour);
        printf("%s's turn\n",p[1].name);
        SetConsoleTextAttribute(hConsole, saved_attributes);
    }
    t=t+3;
    int k=t;
    SetConsoleTextAttribute(hConsole, p[0].colour);
    gotoxy(30,t);
    t=t+3;
    printf("%s's Score =%d\n",p[0].name,p[0].score);
    gotoxy(30,t);
    printf("Number Of Moves For %s = %d\n",p[0].name,p[0].number_of_moves);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, p[1].colour);
    gotoxy(120,k++);
    printf("%s's Score =%d\n",p[1].name,p[1].score);
    k=k+2;
    gotoxy(120,k++);
    printf("Number Of Moves For %s = %d\n",p[1].name,p[1].number_of_moves);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    t=t+3;
    gotoxy(75,t);
    printf("Remaining Lines= %d\n",RemainingLines);
    t=t+3;
    gotoxy(75,t);
    printf("Time= %d:%d\n",minutes,seconds);


}
