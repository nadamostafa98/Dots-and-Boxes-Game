#ifndef PRINT_STATEMENTS_H_INCLUDED
#define PRINT_STATEMENTS_H_INCLUDED

struct player
{
    char name[255];
    int score;
    int colour;
    int number_of_moves;
} p[2];


struct player1
{
    char name[255];
    int score;

} pl[10];

//protoypes;
void PrintArray(int rows,int coloumns,char a[rows+10][coloumns+10],int c1[rows+10][coloumns+10],struct player p[]);
void gotoxy(short col, short row);
void PrintInformation(int flag,struct player p[],int RemainingLines,int minutes,int seconds,int t);
void write_file(char* name,struct player p[],int coloumns,int rows,char a[rows+10][coloumns+10],int  b[rows][coloumns],int c1[rows+10][coloumns+10],int Max,int flag,int MaxNumberOfMoves,int RemainingLines,int minutes,int seconds,int temp);

#endif // PRINT_STATEMENTS_H_INCLUDED
