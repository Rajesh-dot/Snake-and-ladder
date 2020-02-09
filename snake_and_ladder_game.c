#include <stdio.h>
#include<stdlib.h>
int d,position,x,y,new_position,count;
char p1[10],p2[10];
void dice(void);
void p(void);
void progess(void);
void relavent_message(void);
void snake_and_ladder_game(void);
void six(void);
int main()
{
    char q;
    do
    {
    count=0;
    printf("...WELCOME TO THE GAME...\n");
    printf("\n...SNAKES...\n");
    printf("snake-17to7 snake-54to34 snake-62to18\n");
    printf("snake-64to60 snake-87to24 snake-93to73\n");
    printf("snake-95to75 snake-99to78\n");
    printf("...LADDERS...\n");
    printf("ladder-4to15 ladder-9to31 ladder-20to38\n");
    printf("ladder-28to84 ladder-40to59 ladder-63to81\n");
    printf("ladder-71to91\n");
    printf("\nPLAYER-1:");
    scanf("%s",&p1);
    printf("\nPLAYER-2:");
    scanf("%s",&p2);
    x=0;y=0;position=0;new_position=0;
    snake_and_ladder_game();

    printf("\nDo You Want To Play Again(y/n):");
    scanf("%c",&q);
    }
    while(q!='n');

    return 0;
}
void dice()
{
    d=rand()%6+1;
    printf("\nYou rolled %d",d);
}
void progess()
{
    if((count%2)==1)
    {
        x+=d;
        position=x;
    }
    if((count%2)==0)
    {
        y+=d;
        position=y;
    }
    count++;

}
void p()
{
    switch(position)
    {
        case 4:new_position=15;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 9:new_position=31;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 17:new_position=7;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 20:new_position=38;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 28:new_position=84;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 40:new_position=59;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 54:new_position=34;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 62:new_position=18;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 63:new_position=81;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 64:new_position=60;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 71:new_position=91;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 87:new_position=24;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 93:new_position=73;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 95:new_position=75;((count%2)==0)?(x=new_position):(y=new_position);break;
        case 99:new_position=78;((count%2)==0)?(x=new_position):(y=new_position);break;
        default:new_position=position;
    }
}
void relavent_message()
{
    if(new_position>position)
    {
        printf("\nLucky! %s landed on LADDER moved from %d to %d",((count%2)==1)?(p1):(p2),position,new_position);
    }
    else if(new_position<position)
    {
        printf("\noops! %s landed on SNAKE moved from %d to %d",((count%2)==1)?(p1):(p2),position,new_position);
    }
    else
    {
        printf("\n%s you are in %d",((count%2)==1)?(p1):(p2),new_position);
    }
}
void six()
{
    if(d==6)
    {
        printf("\nBonus! %s got another chance",((count%2)==1)?(p1):(p2));
        count--;
    }
}
void snake_and_ladder_game()
{
    char game;
    while(x<100 && y<100)
    {
        scanf("%c",&game);
        dice();
        progess();
        p();
        if(((count%2)==0)?(x<100):(y<100))
        {
            relavent_message();
            six();
        }
        else if(((count%2)==0)?(x==100):(y==100))
            continue;
        else
        {
            printf("\n%s invalid more than 100",((count%2)==1)?(p1):(p2));
            ((count%2)==0)?(x=x-d):(y=y-d);
        }
    }
    if((count%2)==0)
    {
        printf("\nCONGRATULATIONS! %s is the winner",p2);
    }
    else
    {
        printf("\nCONGRATULATIONS! %s is the winner",p1);
    }
}
