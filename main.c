#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100
#include "print_statements.h"
#include "game.h"
char file_name1[30];
int rowsl,coloumnsl;




//declarations
void TwoPlayers(int rows,int coloumns,int Max);
void TwoPlayersload(char * namel,int rows,int coloumns);
void OnePlayer(int rows,int coloumns,int Max);
void OnePlayerload(char * namel,int rows,int coloumns);
void OnePlayerExpert(int rows,int coloumns,int Max);
void OnePlayerExpertload(char * namel,int rows,int coloumns);
void gotoxy(short col, short row);
void write_file(char* name,struct player p[],int coloumns,int rows,char a[rows+10][coloumns+10],int  b[rows][coloumns],int c1[rows+10][coloumns+10],int Max,int flag,int MaxNumberOfMoves,int RemainingLines,int minutes,int seconds,int temp);
int MainMenu();
int main();






void write_file(char* name,struct player p[],int coloumns,int rows,char a[rows+10][coloumns+10],int  b[rows][coloumns],int c1[rows+10][coloumns+10],int Max,int flag,int MaxNumberOfMoves,int RemainingLines,int minutes,int seconds,int temp)
{
 int i,j;
 FILE* f = fopen(name, "w");
 if (f != NULL)
 {           fprintf(f,"%d\n",temp);
             fprintf(f,"%d\n",minutes);
             fprintf(f,"%d\n",seconds);
             fprintf(f,"%d\n",rows);
             fprintf(f,"%d\n",coloumns);
             fprintf(f,"%d\n",MaxNumberOfMoves);
             fprintf(f,"%d\n",RemainingLines);
             fprintf(f,"%d\n",flag);
             fprintf(f,"%d\n",Max);




            for (i = 0; i <=rows; i++){
            for(j=0;j <=coloumns;j++){

             fprintf(f, "%d\n", c1[i][j]);

             }

             }



            for (i = 0; i <=rows-2; i++){
                for(j=0;j <=coloumns-3;j++){

             fprintf(f, "%d\n",b[i][j]);

             }

             }
             for (i = 0; i <=rows; i++){
            for(j=0;j <=coloumns;j++){

             fprintf(f, "%d\n", a[i][j]);}}
             fprintf(f, "%s,%d,%d,%d\n", p[0].name,p[0].colour,p[0].score,p[0].number_of_moves);
             fprintf(f, "%s,%d,%d,%d\n", p[1].name,p[1].colour,p[1].score,p[1].number_of_moves);
             fclose(f);}
 else
 {
 printf("could create the \"%s\" file!", name);
 }
}

int MainMenu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    char choice1[100],choice2[100], choice3[100],choice4[100] ,choice[100],choice5[100],choice6[100],choice7[100],choice8[100];

    int i,j;

    FILE* f;
            f = fopen("variables.txt", "r");
            if (f != NULL)
            {

            while (!feof(f))
            {
            fscanf(f,"%d",&count);


            }
            fclose(f); }

    jump1:
    do
    {  SetConsoleTextAttribute(hConsole, 12);
        gotoxy(67,10);
      printf("------------------------------");
      gotoxy(67,11);
        printf("  <<< D O T S & B O X E S >>>");
        gotoxy(67,12);
      printf("------------------------------");
        SetConsoleTextAttribute(hConsole, saved_attributes);

         gotoxy(70,15);
        printf("1) START A NEW GAME\n");
        gotoxy(70,18);
        printf("2) LOAD A SAVED GAME\n");
        gotoxy(70,21);
        printf("3) TOP 10 PLAYERS\n");
        gotoxy(70,24);
        printf("4) HOW TO PLAY\n");
        gotoxy(70,27);
        printf("5) EXIT\n");
        fflush(stdin);
        gets(choice);
        system("cls");}

    while(choice[1]!='\0' || isalpha(choice[0])|| choice[0]<49 || choice[0]>53);

        switch(choice[0])
        {
        case(49): jump0:
            do{
        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(40,10);
        printf(" CHOOSE A LEVEL >>>");
        SetConsoleTextAttribute(hConsole, saved_attributes);
            gotoxy(70,15);
            printf("1) BEGINNER'S LEVEL\n");
            gotoxy(70,18);
            printf("2) INTERMEDIATE LEVEL\n");
            gotoxy(70,21);
            printf("3) EXPERT'S LEVEL\n");
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(2,2);
            printf("<----");
            gotoxy(4,1);
            printf("B");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            gotoxy(70,23);
            gets(choice1);
            system("cls");}
            while(choice1[1]!='\0' || (isalpha(choice1[0]) &&choice1[0]!='b') || (choice1[0]<49 && choice1[0] !='b')|| (choice1[0]>51 && choice1[0]!='b'));
            if (choice1[0]=='b'){goto jump1;}
            else{
    int rows=0,coloumns=0,Max=0; //Number of rows and coloumns int the matrix and maximum number of moves/
    jump3:
    do{
        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(40,10);
        printf(" CHOOSE A MODE >>>");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        gotoxy(70,15);
        printf("1) ONE PLAYER\n");
        gotoxy(70,18);
        printf("2) TWO PLAYERS\n");
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(2,2);
            printf("<----");
            gotoxy(4,1);
            printf("B");
            SetConsoleTextAttribute(hConsole, saved_attributes);
         gotoxy(70,19);
         gets(choice2);
        system("cls");}
        while(choice2[1]!='\0' || (isalpha(choice2[0]) &&choice2[0]!='b') || (choice2[0]<49 && choice2[0] !='b')|| (choice2[0]>50 && choice2[0]!='b'));
        if(choice2[0]=='b'){goto jump0;}
        if(choice2[0]==49){
            if(choice1[0]==49)//beginners level
            {
                rows=5;
                coloumns=7;
                Max=12;
        OnePlayer(rows,coloumns,Max);
            }
            if(choice1[0]==50)//intermediate level/
                {
                do{
        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(40,10);
        printf(" CHOOSE A SIZE >>>");
        SetConsoleTextAttribute(hConsole, saved_attributes);
                gotoxy(70,15);
                printf("1) 3x3\n");
                gotoxy(70,18);
                printf("2) 4x4\n");
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(2,2);
            printf("<----");
            gotoxy(4,1);
            printf("B");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            gotoxy(70,21);
                gets(choice3);
                system("cls");
                if(choice3[0]=='b'){goto jump3;}
                switch (choice3[0]){
                case 49:
                    rows=7;
                    coloumns=10;
                    Max=24;
                    OnePlayerExpert(rows,coloumns,Max);
                    break;
                case 50:
                    rows=9;
                    coloumns=13;
                    Max=40;
                    OnePlayer(rows,coloumns,Max);
                    break;
                default:break;
                }}
                while(choice3[1]!='\0' || (isalpha(choice3[0]) &&choice3[0]!='b') || (choice3[0]<49 && choice3[0] !='b')|| (choice3[0]>50 && choice3[0]!='b'));}
            if(choice1[0]==51)//Expert's Level/
                {
                rows=11;
                coloumns=16;
                Max=60;
                OnePlayerExpert(rows,coloumns,Max);
            }
            system("cls");
                  }



        else if(choice2[0]==50)//one player/
            {
            if(choice1[0]==49)//beginners level
            {
                rows=5;
                coloumns=7;
                Max=12;
            }
            if(choice1[0]==50)//intermediate level/
                {
                do{
        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(40,10);
        printf(" CHOOSE A SIZE >>>");
                gotoxy(70,15);
                printf("1) 3x3\n");
                gotoxy(70,18);
                printf("2) 4x4\n");
            gotoxy(2,2);
            printf("<----");
            gotoxy(4,1);
            printf("B");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            gotoxy(70,21);
                gets(choice3);
                system("cls");
                if(choice3[0]=='b'){goto jump3;}
                switch (choice3[0]){
                case 49:
                    rows=7;
                    coloumns=10;
                    Max=24;
                    break;
                case 50:
                    rows=9;
                    coloumns=13;
                    Max=40;
                    break;
                default:break;
                }}
                while(choice3[1]!='\0' || (isalpha(choice3[0]) &&choice3[0]!='b') || (choice3[0]<49 && choice3[0] !='b')|| (choice3[0]>50 && choice3[0]!='b'));}
            if(choice1[0]==51)//Expert's Level/
                {
                rows=11;
                coloumns=16;
                Max=80;
            }
            system("cls");
        TwoPlayers(rows,coloumns,Max);}}
            break;
        case(50):
            jump12:

                do{
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(2,2);
            printf("<----");
            gotoxy(4,1);
            printf("B");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            gotoxy(70,15);
            printf("CHOOSE THE DIFFICULTY YOU WANT TO LOAD \n");
            gotoxy(70,18);
            printf("1) BEGINEER\n");
            gotoxy(70,21);
            printf("2) INTERMEDIATE(3X3)\n");
            gotoxy(70,24);
                printf("3) INTERMEDIATE(4X4)\n");
                gotoxy(70,27);
                printf("4) EXPERT\n");
                fflush(stdin);
                gets(choice6);
                system("cls");}
                while(choice6[1]!='\0' || (isalpha(choice6[0]) &&choice6[0]!='b') || (choice6[0]<49 && choice6[0] !='b')|| (choice6[0]>52 && choice6[0]!='b'));
                if (choice6[0]=='b'){goto jump1;}
                else{   do{
                        SetConsoleTextAttribute(hConsole, 12);
                    gotoxy(2,2);
                    printf("<----");
                    gotoxy(4,1);
                    printf("B");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    gotoxy(70,15);
                    printf("CHOOSE THE MODE YOU WANT TO LOAD \n");
                    gotoxy(70,18);
                    printf("1) HUMAN VERSES COMPUTER\n");
                    gotoxy(70,21);
                    printf("2) HUMAN VERSES HUMAN\n");
                    fflush(stdin);
                gets(choice7);
                system("cls");}
                while(choice7[1]!='\0' || (isalpha(choice7[0]) &&choice7[0]!='b') || (choice7[0]<49 && choice7[0] !='b')|| (choice7[0]>50 && choice7[0]!='b'));
                if (choice7[0]=='b'){goto jump12;}
                    else{


                gotoxy(40,10);
                printf("Please enter the name of the game you want to load: ");
                fflush(stdin);
                fgets(file_name1, sizeof(file_name1), stdin);
                if (file_name1[strlen(file_name1) - 1] == '\n')
                {file_name1[strlen(file_name1) - 1] = '\0';}
                 switch(choice6[0]){
                 case 49:rowsl=5;coloumnsl=7;break;
                 case 50:rowsl=7;coloumnsl=10;break;
                 case 51:rowsl=9;coloumnsl=13;break;
                 case 52:rowsl=11;coloumnsl=16;break;
                 default:break;


                 }
                 if(choice7[0]==50){system("cls");TwoPlayersload(file_name1,rowsl,coloumnsl);}
                 else if(choice7[0]==49&&(choice6[0]==49||choice6[0]==51)){system("cls");OnePlayerload(file_name1,rowsl,coloumnsl);}
                 else if(choice7[0]==49&&(choice6[0]==50||choice6[0]==52)){system("cls");OnePlayerExpertload(file_name1,rowsl,coloumnsl);}
                 break;
            }}

        case(51):

            do{

            i=0;
            FILE* f4;//f4 34an a2ry elleaderboard
            f4 = fopen("scores_begineer.bin", "rb");
            if ((f4 = fopen("scores_begineer.bin","rb")) == NULL){

            system("cls");
            gotoxy(60,20);
            printf("NO LEADERBOARD YET!,U MUST PLAY THE GAME IN ORDER TO SEE LEADERBOARD");
            Sleep(500);
            system("cls");
            main();
            exit(1);}
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(2,2);
            printf("<----");
            gotoxy(4,1);
            printf("B");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            gotoxy(70,15);
            printf("TOP PLAYERS:\n");
            gotoxy(70,16);
            printf("Player's Name\t\t\tPlayer's Score\n");
            fread(pl, sizeof(struct player1) * count/* Just read one person */, 1, f4);
            int maxscore=0;
            char tempo[50];
            for(i=0;i<count;i++){
                for(j=0;j<count;j++){
                    if(pl[j].score<pl[i].score){
                        maxscore=pl[j].score;
                        pl[j].score=pl[i].score;
                        pl[i].score=maxscore;
                        strcpy(tempo,pl[j].name);
                        strcpy(pl[j].name,pl[i].name);
                        strcpy(pl[i].name,tempo);

                    }}}
                    if(count<10){
            for(i=0;i<count;i++){
            gotoxy(70,18+i);
            printf("%d)%s",i+1, pl[i].name);
            gotoxy(105,18+i);
            printf("%d\n", pl[i].score);}}
            else{
                for(i=0;i<10;i++){
            gotoxy(70,18+i);
            printf("%d)%s",i+1, pl[i].name);
            gotoxy(105,18+i);
            printf("%d\n", pl[i].score);}
            }
            fclose(f4);
            fflush(stdin);
            gets(choice5);
            system("cls");}
            while(choice5[1]!='\0' || (isalpha(choice5[0]) &&choice5[0]!='b')||(choice5[0]>47 && choice5[0] !='b')|| (choice5[0]<58 && choice5[0]!='b' ));
            if (choice5[0]=='b'){goto jump1;}

            break;
        case(52):
            do{
            gotoxy(70,15);
            printf("1. CHOOSE A ROW NUMBER.");
            gotoxy(70,18);
            printf("2. CHOOSE A COLUMN NUMBER.");
            gotoxy(70,21);
            printf("3. CHOOSE A MOVE:");
            gotoxy(75,24);
            printf("2 --> Downwards");
            gotoxy(75,26);
            printf("5 --> Upwards");
            gotoxy(75,28);
            printf("3 --> Right");
            gotoxy(75,30);
            printf("1 --> Left");
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(2,2);
            printf("<----");
            gotoxy(4,1);
            printf("B");
            gotoxy(40,10);
            printf(" HOW TO PLAY >>>");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            gotoxy(70,40);
            gets(choice8);
            system("cls");}
            while(choice8[1]!='\0' || (isalpha(choice8[0]) &&(choice8[0]!='e'&&choice8[0]!='b'))||(choice8[0]>47 && (choice8[0]!='b'))|| (choice8[0]<58 && (choice8[0]!='b')));
            goto jump1;
        case(53):do{
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(2,2);
            printf("<----");
            gotoxy(4,1);
            printf("B");
            gotoxy(130,40);
            printf("CREDITS");
            gotoxy(130,41);
            printf("AHMED MOLAHEZ");
            gotoxy(130,42);
            printf("NADA RASHAD");

            SetConsoleTextAttribute(hConsole, saved_attributes);
            gotoxy(67,16);
            printf("ARE YOU SURE U WANT TO EXIT(E) >=(\n");
            fflush(stdin);
            gets(choice4);
            system("cls");}
            while(choice4[1]!='\0' || (isalpha(choice4[0]) &&(choice4[0]!='e'&&choice4[0]!='b'))||(choice4[0]>47 && (choice4[0]!='e'&&choice4[0]!='b'))|| (choice4[0]<58 && (choice4[0]!='e'&&choice4[0]!='b')));
            if (choice4[0]=='e'){exit(0);}
            else{goto jump1;}

            break;
        default: break;}

        return 0;

}
int main()
{
    MainMenu();
    return 0;
}
