#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define ANSI_COLOR_PINK "\x1b[35;1m"
#define ANSI_COLOR_RED "\x1b[31;1m"
#define ANSI_COLOR_GREEN "\x1b[32;1m"
#define ANSI_COLOR_YELLOW "\x1b[33;1m"
#define ANSI_COLOR_BLUE "\x1b[34;1m"
#define ANSI_COLOR_CYAN "\x1b[36;1m"
#define COLOR_BOLD  "\e[1m"
#define COLOR_OFF   "\e[m"
void white()
{
    printf("\033[0;37m");
}
int clue(int rn)
{
    char ch;
    white();
    scanf(" %c",&ch);
    int a=rn,dig=0;
    if(ch=='Y'||ch=='N')
    {
        for(int a=rn;a!=0;a/=10)
        {
            dig++;
        }
        if(ch=='Y')
        {
            printf(ANSI_COLOR_PINK COLOR_BOLD"Number of digits is %d\n"COLOR_OFF,dig);
        }
        else if(ch=='N')
            return 0;
    }
    else
    {
        printf(ANSI_COLOR_RED"Invalid Letter.\n");
        printf(ANSI_COLOR_CYAN"Enter again:\n");
        clue(rn);
    }
    return 0;
}
int clue5(int * g,int * r)
{
    white();
    int a=*r;
    a=a%10;
    char ch;
    scanf(" %c",&ch);
    if(ch=='Y')
    {
        printf(ANSI_COLOR_PINK"The last digit of the random Number is %d\n",a);
    }
    else if(ch=='N')
    {
        return 0;
    }
    else
    {
        printf(ANSI_COLOR_RED"Wrong Input..."ANSI_COLOR_CYAN "Enter Again\n");
        clue5(g,r);

    }
    return 0;
}
int main()
{
    char play;
    do
    {
        time_t t1=time(NULL);//STORE THE TIME WHEN PROGRAM STARTS
        srand(time(NULL));// TO STORE A RANDOM NUMBER
        int n,tries;
        printf(ANSI_COLOR_CYAN"Enter the MAX Range you want to guess from\n");
        white();
            scanf("%d",&n);
        for(;n>10000;)
        {
            printf(ANSI_COLOR_RED"The number u entered is more than the maximum range you should enter\nEnter Again\n");
            white();
            scanf("%d",&n);
        }
        if(n<=10000&& n>=1000)
            printf(ANSI_COLOR_CYAN"You selected HARD LEVEL\n");
        else if(n<1000&&n>=100)
            printf(ANSI_COLOR_CYAN"You selected MEDIUM LEVEL\n");
        else
            printf(ANSI_COLOR_CYAN"You selected EASY LEVEL\n");
        int rn=(rand()%n)+1;
        int guess;
        printf(ANSI_COLOR_CYAN"Do you want a clue? 'Y' or 'N' \n");
        clue(rn);
        printf(ANSI_COLOR_CYAN"Enter your Guess:\n");
        white();
        scanf("%d",&guess);
        for(tries=1;rn!=guess && tries!=10;tries++)
        {
            if(guess>rn)
            {
                printf(ANSI_COLOR_RED"your guess is "ANSI_COLOR_YELLOW"greater "ANSI_COLOR_RED"than the random Number\n");
            }
            else if(guess<rn)
            {
                printf(ANSI_COLOR_RED"your guess is "ANSI_COLOR_YELLOW"less "ANSI_COLOR_RED"than the random Number\n");
            }
            if(tries==5&&rn>9)
            {
                printf(ANSI_COLOR_CYAN"You already took half of your chances...\n");
                printf(ANSI_COLOR_CYAN"Do you want more clue??? 'Y' or 'N' \n");
                clue5(&guess,&rn);
                
            }
            printf(ANSI_COLOR_CYAN"Enter your guess again\n");
            white();
            scanf("%d", &guess);
        }
        if(tries==10)
        {
                printf(ANSI_COLOR_RED"LOST THIS GAME...\nYou FAILED to guess the Number...\nYou have already took 10 tries...\n");
                printf("The correct answer is "ANSI_COLOR_CYAN "%d",rn);
                printf(ANSI_COLOR_YELLOW COLOR_BOLD"\nBETTER LUCK NEXT TIME\n"COLOR_OFF);
        }
        else if(guess==rn)
        {
            time_t t2=time(NULL);
            time_t diff=difftime(t2,t1);
            time_t hour=diff/3600;
            diff%=3600;
            time_t min=diff/60;
            diff%=60;
            printf(ANSI_COLOR_GREEN"YAY... Your guess" ANSI_COLOR_CYAN" %d"ANSI_COLOR_GREEN" is correct\n", guess);
            printf(ANSI_COLOR_GREEN"You got the correct answer after"ANSI_COLOR_CYAN" %d"ANSI_COLOR_GREEN" tries\n",tries);
            if (tries==1)
                printf(ANSI_COLOR_CYAN"Your score is 100... HURRAY ;)\n");
            else if(tries==2)
                printf(ANSI_COLOR_CYAN"Your score is 90... Excellant\n");
            else if(tries==3)
                printf(ANSI_COLOR_CYAN"Your score is 80... \n");
            else if(tries==4)
                printf(ANSI_COLOR_CYAN"Your score is 70... \n");
            else if(tries==5)
                printf(ANSI_COLOR_CYAN"Your score is 60... \n");
            else if(tries==6)
                printf(ANSI_COLOR_CYAN"Your score is 50... \n");
            else if(tries==7)
                printf(ANSI_COLOR_CYAN"Your score is 40... \n");
            else if(tries==8)
                printf(ANSI_COLOR_CYAN"Your score is 30... \n");
            else if(tries==9)
                printf(ANSI_COLOR_CYAN"Your score is 20... \n");
            else if(tries==9)
                printf(ANSI_COLOR_CYAN"Your score is 10... \n");
            printf(ANSI_COLOR_PINK"You took %02ld hours %02d minutes and %02d seconds to guess the correct answer\n",hour,min,diff);
        }
        printf(ANSI_COLOR_YELLOW COLOR_BOLD "Do you want to play again? 'Y' or 'N' \n"COLOR_OFF);
        scanf(" %c",&play);
    } while (play=='Y'||play=='y');
    return 0;
}