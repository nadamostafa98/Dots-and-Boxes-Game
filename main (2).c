#include <stdio.h>
#include <stdlib.h>

void TwoPlayersload(char * namel,int rows,int coloumns)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    fflush(stdin);
    int i,j;

    int MaxNumberOfMoves;
    int c1[rows+10][coloumns+10];
    char a[rows+10][coloumns+10];
    int b[rows][coloumns];
    int flag,Max,RemainingLines,temp,minutes,seconds;

    for(i=0; i<=rows; i++)
    {
        for(j=0; j<=coloumns; j++)
        {

            c1[i][j]=2;
            fflush(stdin);
            a[i][j]=' ';
        }
    }
    for(i=0; i<=rows-2; i++)
    {
        for(j=0; j<=coloumns-3; j++)
        {
            b[i][j]=0;

        }
    }

    FILE* f5 = fopen(namel, "r");
    if (f5 != NULL)
    {
        while (!feof(f5))
        {
            fscanf(f5,"%d\n",&temp);
            fscanf(f5,"%d\n",&minutes);
            fscanf(f5,"%d\n",&seconds);
            fscanf(f5,"%d\n",&rows);
            fscanf(f5,"%d\n",&coloumns);
            fscanf(f5,"%d\n",&MaxNumberOfMoves);
            fscanf(f5,"%d\n",&RemainingLines);
            fscanf(f5,"%d\n",&flag);
            fscanf(f5,"%d\n",&Max);




            for (i = 0; i <=rows; i++)
            {
                for(j=0; j <=coloumns; j++)
                {

                    fscanf(f5, "%d\n", &c1[i][j]);

                }

            }



            for (i = 0; i <=rows-2; i++)
            {
                for(j=0; j <=coloumns-3; j++)
                {

                    fscanf(f5, "%d\n",& b[i][j]);

                }

            }
            for (i = 0; i <=rows; i++)
            {
                for(j=0; j <=coloumns; j++)
                {

                    fscanf(f5, "%d\n", &a[i][j]);
                }
            }
            fscanf(f5, "%[^,],%d,%d,%d\n", p[0].name,&p[0].colour,&p[0].score,&p[0].number_of_moves);
            fscanf(f5, "%[^,],%d,%d,%d\n", p[1].name,&p[1].colour,&p[1].score,&p[1].number_of_moves);
        }
        fclose(f5);
    }
    else
    {
        printf("could create the %s file!",namel);
    }


    int o=MaxNumberOfMoves;
    int c,move;
    char r[200];

    int flagscore=2;
    int flag1,flag2=1,flag3=0;//flag 3 bta3 elleaderboard
    char A=p[0].name[0];
    char B=p[1].name[0];


    struct PreviousMove  //will be used for undo and redo
    {
        char array1[rows+10][coloumns+10];
        int array2[rows][coloumns];
        int array3[rows+10][coloumns+10];
        int ScoreOne;
        int ScoreTwo;
        int FlagScore;
        int N1;
        int N2;
        int Flag;
        int Flag2;
        int maxNumberOfMoves;
        int remainingLines;
    };

    struct PreviousMove P [Max-MaxNumberOfMoves];
    P[MaxNumberOfMoves].ScoreOne=p[0].score;
    P[MaxNumberOfMoves].ScoreTwo=p[1].score;
    P[MaxNumberOfMoves].FlagScore=flagscore;
    P[MaxNumberOfMoves].N1=p[0].number_of_moves;
    P[MaxNumberOfMoves].N2=p[1].number_of_moves;
    P[MaxNumberOfMoves].Flag=flag;
    P[MaxNumberOfMoves].Flag2=flag2;
    P[MaxNumberOfMoves].maxNumberOfMoves=MaxNumberOfMoves;
    P[MaxNumberOfMoves].remainingLines=RemainingLines;
    for(i=0; i<=rows; i++)
    {
        for(j=0; j<=coloumns; j++)
        {
            P[MaxNumberOfMoves].array1[i][j]=a[i][j];
            P[MaxNumberOfMoves].array3[i][j]=c1[i][j];
        }
    }
    for(i=0; i<=rows; i++)
    {
        for(j=0; j<=coloumns; j++)
        {
            P[MaxNumberOfMoves].array2[i][j]=b[i][j];
        }
    }

    int temp2=0;
    int z=MaxNumberOfMoves+1;


    int t=20;
    PrintArray(rows,coloumns,a,c1,p);
    PrintInformation(flag,p,RemainingLines,minutes,seconds,t);

    while(MaxNumberOfMoves<Max)
    {
        clock_t StartTime,EndTime,TotalTime;
        StartTime=clock();
jump1:
        fflush(stdin);
        gets(r);
        if(r[1]!='\0')
        {
            system("cls");
            gotoxy(72,8);
            printf("INVALID MOVE!");
            PrintArray(rows,coloumns,a,c1,p);
            PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
            goto jump1;
        }
        if(r[0]=='s')
        {
            char file_name[30];
            printf("Please enter the name of the game you want to save: ");
            fflush(stdin);
            fgets(file_name, sizeof(file_name), stdin);
            if (file_name[strlen(file_name) - 1] == '\n')
                file_name[strlen(file_name) - 1] = '\0';
            write_file(file_name,p,coloumns,rows,a,b,c1,Max,flag,MaxNumberOfMoves,RemainingLines,minutes,seconds,temp);
            printf("game saved ");
            MaxNumberOfMoves--;
            system("cls");
            PrintArray(rows,coloumns,a,c1,p);

        }
        else if(r[0]=='u')
        {
            system("cls");
            if(z-2<o)
            {
                gotoxy(75,8);
                printf("INVALID!\n");
            }
            else
            {
                p[0].score=P[z-2].ScoreOne;
                p[1].score=P[z-2].ScoreTwo;
                flagscore=P[z-2].FlagScore;
                p[0].number_of_moves=P[z-2].N1;
                p[1].number_of_moves=P[z-2].N2;
                flag=P[z-2].Flag;
                flag2=P[z-2].Flag2;
                MaxNumberOfMoves=P[z-2].maxNumberOfMoves;
                RemainingLines=P[z-2].remainingLines;
                for(i=0; i<=rows; i++)
                {
                    for(j=0; j<=coloumns; j++)
                    {
                        a[i][j]=P[z-2].array1[i][j];
                        c1[i][j]=P[z-2].array3[i][j];
                    }
                }
                for(i=0; i<=rows; i++)
                {
                    for(j=0; j<=coloumns; j++)
                    {
                        b[i][j]=P[z-2].array2[i][j];
                    }
                }
                z--;
            }
            PrintArray(rows,coloumns,a,c1,p);
        }
        else if(r[0]=='r')
        {
            system("cls");
            if(z>=temp2)
            {
                gotoxy(70,8);
                printf("INVALID!\n");
            }
            else
            {
                p[0].score=P[z].ScoreOne;
                p[1].score=P[z].ScoreTwo;
                flagscore=P[z].FlagScore;
                p[0].number_of_moves=P[z].N1;
                p[1].number_of_moves=P[z].N2;
                flag=P[z].Flag;
                flag2=P[z].Flag2;
                MaxNumberOfMoves=P[z].maxNumberOfMoves;
                RemainingLines=P[z].remainingLines;
                for(i=0; i<=rows; i++)
                {
                    for(j=0; j<=coloumns; j++)
                    {
                        a[i][j]=P[z].array1[i][j];
                        c1[i][j]=P[z].array3[i][j];
                    }
                }

                for(i=0; i<=rows; i++)
                {
                    for(j=0; j<=coloumns; j++)
                    {
                        b[i][j]=P[z].array2[i][j];
                    }
                }
                z++;
            }
            PrintArray(rows,coloumns,a,c1,p);
        }
        else if(r[0]=='e')
        {
            system("cls");
            MainMenu();
        }

        else
        {
            if(isalpha(r[0]))
            {
                system("cls");
                gotoxy(72,8);
                printf("INVALID MOVE!");
                PrintArray(rows,coloumns,a,c1,p);
                PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                goto jump1;
            }
            scanf("%d %d",&c,&move);
            system("cls");
            r[0]=r[0]-48;
            /*To prevent choosing a non-existing point*/
            if(((((2*r[0])-1)%2==0)&& ((c+(2*(c-1)))%3!=(7%3))) || r[0]<1 || r[0]>(coloumns-rows+1) || c<1 || c>(coloumns-rows+1) )
            {
                gotoxy(72,8);
                printf("INVALID MOVE!");
                PrintArray(rows,coloumns,a,c1,p);
                PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                goto jump1;
            }
            if(flag==0)
            {
                switch(move)
                {

                case 5:
                    if ((a[(2*r[0])-2][c+(2*(c-1))]=='|' )|| r[0]==1)
                    {
                        gotoxy(72,8);
                        printf("INVALID MOVE!");
                        PrintArray(rows,coloumns,a,c1,p);
                        PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                        goto jump1;
                    }
                    else
                    {
                        a[(2*r[0])-2][c+(2*(c-1))]='|';
                        c1[(2*r[0])-2][c+(2*(c-1))]=0;
                    }
                    break; /*To prevent playing an already played move or to play at the edges*/
                case 1:
                    if ((a[(2*r[0])-1][c+(2*(c-1))-1]=='-') || c==1)
                    {
                        gotoxy(72,8);
                        printf("INVALID MOVE!");
                        PrintArray(rows,coloumns,a,c1,p);
                        PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                        goto jump1;
                    }
                    else
                    {
                        a[(2*r[0])-1][c+(2*(c-1))-1]='-';
                        a[(2*r[0])-1][c+(2*(c-1))-2]='-';
                        c1[(2*r[0])-1][c+(2*(c-1))-1]=0;
                        c1[(2*r[0])-1][c+(2*(c-1))-2]=0;
                    }
                    break;
                case 2:
                    if ((a[(2*r[0])][c+(2*(c-1))]=='|') || r[0]==(coloumns-rows+1))
                    {
                        gotoxy(72,8);
                        printf("INVALID MOVE!");
                        PrintArray(rows,coloumns,a,c1,p);
                        PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                        goto jump1;
                    }
                    else
                    {
                        a[(2*r[0])][c+(2*(c-1))]='|';
                        c1[(2*r[0])][c+(2*(c-1))]=0;
                    }
                    break;
                case 3:
                    if( (a[(2*r[0])-1][c+(2*(c-1))+1]=='-') || c==(coloumns-rows+1) )
                    {
                        gotoxy(70,8);
                        printf("INVALID MOVE!");
                        PrintArray(rows,coloumns,a,c1,p);
                        PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                        goto jump1;
                    }
                    else
                    {
                        a[(2*r[0])-1][c+(2*(c-1))+1]='-';
                        a[(2*r[0])-1][c+(2*(c-1))+2]='-';
                        c1[(2*r[0])-1][c+(2*(c-1))+1]=0;
                        c1[(2*r[0])-1][c+(2*(c-1))+2]=0;
                    }
                    break;
                default:
                    gotoxy(70,8);
                    printf("INVALID MOVE!");
                    PrintArray(rows,coloumns,a,c1,p);
                    PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                    goto jump1;
                    break;
                }
            }
            else
            {

                switch(move)
                {

                case 5:
                    if ((a[(2*r[0])-2][c+(2*(c-1))]=='|' )|| r[0]==1)
                    {
                        gotoxy(72,8);
                        printf("INVALID MOVE!");
                        PrintArray(rows,coloumns,a,c1,p);
                        PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                        goto jump1;
                    }
                    else
                    {
                        a[(2*r[0])-2][c+(2*(c-1))]='|';
                        c1[(2*r[0])-2][c+(2*(c-1))]=1;
                    }
                    break; /*To prevent playing an already played move or to play at the edges*/
                case 1:
                    if ((a[(2*r[0])-1][c+(2*(c-1))-1]=='-') || c==1)
                    {
                        gotoxy(72,8);
                        printf("INVALID MOVE!");
                        PrintArray(rows,coloumns,a,c1,p);
                        PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                        goto jump1;
                    }
                    else
                    {
                        a[(2*r[0])-1][c+(2*(c-1))-1]='-';
                        a[(2*r[0])-1][c+(2*(c-1))-2]='-';
                        c1[(2*r[0])-1][c+(2*(c-1))-1]=1;
                        c1[(2*r[0])-1][c+(2*(c-1))-2]=1;
                    }
                    break;
                case 2:
                    if ((a[(2*r[0])][c+(2*(c-1))]=='|') || r[0]==(coloumns-rows+1))
                    {
                        gotoxy(72,8);
                        printf("INVALID MOVE!");
                        PrintArray(rows,coloumns,a,c1,p);
                        PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                        goto jump1;
                    }
                    else
                    {
                        a[(2*r[0])][c+(2*(c-1))]='|';
                        c1[(2*r[0])][c+(2*(c-1))]=1;
                    }
                    break;
                case 3:
                    if( (a[(2*r[0])-1][c+(2*(c-1))+1]=='-') || c==(coloumns-rows+1) )
                    {
                        gotoxy(72,8);
                        printf("INVALID MOVE!");
                        PrintArray(rows,coloumns,a,c1,p);
                        PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                        goto jump1;
                    }
                    else
                    {
                        a[(2*r[0])-1][c+(2*(c-1))+1]='-';
                        a[(2*r[0])-1][c+(2*(c-1))+2]='-';
                        c1[(2*r[0])-1][c+(2*(c-1))+1]=1;
                        c1[(2*r[0])-1][c+(2*(c-1))+2]=1;
                    }
                    break;
                default:
                    gotoxy(72,8);
                    printf("INVALID MOVE!");
                    PrintArray(rows,coloumns,a,c1,p);
                    PrintInformation(flag,p,RemainingLines,minutes,seconds,t);
                    goto jump1;
                    break;
                }
            }

            for(i=1; i<=(rows-2); i=i+2)
            {
                for(j=1; j<=(coloumns-3); j=j+3)
                {
                    if((a[i+1][j]!=' ') && (a[i][j+1]!=' ') && (a[i+1][j+3]!=' ') && (a[i+2][j+1]!=' '))
                    {
                        if(b[i][j]!=1)
                        {
                            b[i][j]=1;
                            if(flag==0)
                            {
                                a[i+1][j+1]=A;
                                a[i+1][j+2]=A;
                                c1[i+1][j+1]=3;//3 for 1st player back ground
                                c1[i+1][j+2]=3;//4 for 2nd player back ground
                                c1[i+1][j]=0;
                                c1[i][j+2]=0;
                                c1[i][j+1]=0;
                                c1[i+1][j+3]=0;
                                c1[i+2][j+1]=0;
                                c1[i+2][j+2]=0;

                                p[0].score++;
                                flag=0;
                                flagscore=0;
                            }
                            else if(flag==1)
                            {
                                a[i+1][j+1]=B;
                                a[i+1][j+2]=B;
                                c1[i+1][j+1]=4;
                                c1[i+1][j+2]=4;
                                c1[i+1][j]=1;
                                c1[i][j+2]=1;
                                c1[i][j+1]=1;
                                c1[i+1][j+3]=1;
                                c1[i+2][j+1]=1;
                                c1[i+2][j+2]=1;
                                p[1].score++;
                                flag=1;
                                flagscore=1;
                            }
                        }
                    }
                }
            }
            PrintArray(rows,coloumns,a,c1,p);
            if(flagscore==0)
            {
                flag=0;
                flagscore=2;
                p[0].number_of_moves++;
                p[1].number_of_moves--;
            }
            else if(flagscore==1)
            {
                flag=1;
                flagscore=2;
                p[1].number_of_moves++;
                p[0].number_of_moves--;
            }
            else
            {
                flag1=flag;
                flag=flag2;
                flag2=flag1;

            }
            if(flag==0)
            {
                p[1].number_of_moves++;
            }
            else if(flag==1)
            {
                p[0].number_of_moves++;
            }
            RemainingLines--;
            MaxNumberOfMoves++;

            P[z].ScoreOne=p[0].score;
            P[z].ScoreTwo=p[1].score;
            P[z].FlagScore=flagscore;
            P[z].N1=p[0].number_of_moves;
            P[z].N2=p[1].number_of_moves;
            P[z].Flag=flag;
            P[z].Flag2=flag2;
            P[z].maxNumberOfMoves=MaxNumberOfMoves;
            P[z].remainingLines=RemainingLines;
            for(i=0; i<=rows; i++)
            {
                for(j=0; j<=coloumns; j++)
                {
                    P[z].array1[i][j]=a[i][j];
                    P[z].array3[i][j]=c1[i][j];
                }
            }
            for(i=0; i<=rows; i++)
            {
                for(j=0; j<=coloumns; j++)
                {
                    P[z].array2[i][j]=b[i][j];
                }
            }
            z++;
            temp2=z;
        }
        //in case of undo and redo the code starts again here
        EndTime=clock();
        TotalTime=((EndTime-StartTime)/CLOCKS_PER_SEC);
        temp+=TotalTime;
        minutes=temp/60;
        seconds=temp%60;
        if (RemainingLines!=0) {PrintInformation(flag,p,RemainingLines,minutes,seconds,t);}
    }




      FILE* f;
    f = fopen("variables.txt", "r");
    if (f != NULL)
    {

        while (!feof(f))
        {
            fscanf(f,"%d",&count);


        }
        fclose(f);
    }
    if(count==0) {}


    else
    {
        i=0;
        FILE* f4;//f4 34an a2ry elleaderboard
        f4 = fopen("scores_begineer.bin", "rb");
        if ((f4 = fopen("scores_begineer.bin","rb")) == NULL)
        {
            printf("Error! opening file");
            exit(1);
        }
        fread(pl, sizeof(struct player1) * count, 1, f4);


        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(2,2);
        printf("<----");
        gotoxy(4,1);
        printf("B");
        gotoxy(2,4);
        printf("<----");
        gotoxy(4,3);
        printf("E");
        SetConsoleTextAttribute(hConsole, saved_attributes);





        fclose(f4);
    }


    char tempo1[50];
    if(p[0].score>p[1].score)
    {
        SetConsoleTextAttribute(hConsole, p[0].colour);
        gotoxy(72,20);
        printf("%s WINS!",p[0].name);
        strcpy(tempo1,p[0].name);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        for(i=0; i<=count; i++)
        {
            if(strcmp(strlwr(pl[i].name),strlwr(p[0].name))== 0)
            {
                flag3=0;
                if(p[0].score>pl[i].score)
                {
                    pl[i].score=p[0].score;
                }
                else {}
                break;
            }
            else
            {
                flag3=1;
            }

        }
        if(flag3==1)
        {
            strcpy(pl[count].name,p[0].name);
            pl[count].score=p[0].score;
            count++;
        }
    }
    else if(p[0].score<p[1].score)
    {
        SetConsoleTextAttribute(hConsole, p[1].colour);
        gotoxy(72,20);
        printf("%s WINS!",p[1].name);
        strcpy(tempo1,p[1].name);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        for(i=0; i<=count; i++)
        {
            if(strcmp(strlwr(pl[i].name),strlwr(p[1].name)) == 0)
            {
                flag3=0;
                if(p[1].score>pl[i].score)
                {
                    pl[i].score=p[1].score;
                }
                else {}
                break;
            }
            else
            {
                flag3=1;
            }

        }
        if(flag3==1)
        {
            strcpy(pl[count].name,p[1].name);
            pl[count].score=p[1].score;
            count++;
        }
    }
    else
    {
        gotoxy(72,20);
        printf("DRAW!");
    }
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
                    for(i=0;i<count;i++){
                            if(strcmp(pl[i].name,tempo1)==0){
                                    gotoxy(70,23);
                        printf("Player's Name\t\t\tPlayer's Score\n");
                        gotoxy(70,25);
                        printf("%d)%s",i+1, pl[i].name);
                        gotoxy(105,25);
                        printf("%d\n", pl[i].score);}}

    FILE* f3 = fopen("scores_begineer.bin", "wb");
    if ((f3 = fopen("scores_begineer.bin", "wb")) == NULL)
    {
        printf("Error opening file\n");
    }

    fwrite(pl, sizeof(struct player1) * count, 1,f3);

    fclose(f3);

    FILE* f1 = fopen("variables.txt", "w");
    if (f1 != NULL)
    {
        fprintf(f1,"%d",count);
        fclose(f1);
    }



    else
    {
        printf("could create the \"variables.txt\" file!");
    }
   char StartAgain[100];
    do
    {
        gotoxy(70,40);
        fflush(stdin);
        gets(StartAgain);

    }
    while(StartAgain[1]!='\0' || StartAgain[0]!='b'&& StartAgain[0]!='e');
    if(StartAgain[0]=='b'){system("cls");MainMenu();}
    else{do{ system("cls");
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
            gets(StartAgain);
            system("cls");}
            while(StartAgain[1]!='\0' || StartAgain[0]!='b'&& StartAgain[0]!='e');
            if(StartAgain[0]=='b'){system("cls");MainMenu();}
            else{exit(0);}

            }


}
