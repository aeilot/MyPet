//
//  main.c
//  MyPet
//
//  Created by Louis.Aeilot.D on 2017/6/3.
//  Copyright © 2017年 Louis.Aeilot.D. All rights reserved.
//
//  Put Library.txt in home.
//
#include <stdio.h>
#include <stdlib.h>

FILE *fp = NULL;
struct User_Pet {
    int carrot;
    int life;
    char name[50];
    int happy;
    int age;
    int hungry;
    int money;
};

void Main_UI(struct User_Pet *up);
void setup(struct User_Pet *up);
void Store_UI(struct User_Pet *up);
void InFile(struct User_Pet *up,int *set);
void OutFile(struct User_Pet *up,int *set);
void Feed_UI(struct User_Pet *up);
void about_UI(struct User_Pet *up);

void setup(struct User_Pet *up)
{
    printf("What is you pet's name.\n");
    printf(":");
    scanf("%s",up->name);
    up->age=1;
    up->carrot=100;
    up->happy=100;
    up->hungry=100;
    up->life=100;
    up->money=100;
}
void Store_UI(struct User_Pet *up)
{
    int input;
Store:
    printf("-----------------------------------\n");
    printf("                STORE              \n");
    printf(" You have %d 💰                    \n",up->money);
    printf("1: 100 🥕                      25💰\n");
    printf("2: 500 🥕                      125💰\n");
    printf("3: 1000 🥕                     250💰\n");
    printf("4: 5000 🥕                    1250💰\n");
    printf("5: one day younger            2500💰\n");
    printf("6: Back                              \n");
    printf("-----------------------------------\n");
put:
    printf(":");
    scanf("%d",&input);
    switch (input) {
        case 1:
            if (up->money>=25) {
                printf("You buy it.\n");
                up->money-=25;
                up->carrot+=100;
                goto Store;
            }
            else{
                printf("you cannot buy it.\n");
                goto Store;
            }
            break;
        case 2:
            if (up->money>=125) {
                printf("You buy it.\n");
                up->money-=125;
                up->carrot+=500;
                goto Store;
            }
            else{
                printf("you cannot buy it.\n");
                goto Store;
            }
            break;
        case 3:
            if (up->money>=250) {
                printf("You buy it.\n");
                up->money-=250;
                up->carrot+=1000;
                goto Store;
            }
            else{
                printf("you cannot buy it.\n");
                goto Store;
            }
            break;
        case 4:
            if (up->money>=1250) {
                printf("You buy it.\n");
                up->money-=1250;
                up->carrot+=5000;
                goto Store;
            }
            else{
                printf("you cannot buy it.\n");
                goto Store;
            }
            break;
        case 5:
            if (up->money>=2500&&up->age>1) {
                printf("You buy it.\n");
                up->money-=2500;
                up->age-=100;
                goto Store;
            }
            else{
                printf("you cannot buy it.\n");
                goto Store;
            }
            break;
        case 6:
            Main_UI(up);
            break;
        default:
            printf("Input Error.Please input again.\n");
            goto put;
            break;
    }
}
void InFile(struct User_Pet *up,int *set)
{
    fp=fopen("~/MyPet/Lib/library.txt", "w");
    fprintf(fp, "%d %d %d %s %d %d %d %d",*set,up->carrot,up->life,up->name,up->happy,up->age,up->hungry,up->money);
    fclose(fp);
}
void OutFile(struct User_Pet *up,int *set)
{
    fp=fopen("~/MyPet/Lib/Library.txt", "r");
    fscanf(fp,"%d %d %d %s %d %d %d %d",set,&up->carrot,&up->life,up->name,&up->happy,&up->age,&up->hungry,&up->money);
    up->age+=1;
    up->hungry-=10;
    up->happy-=5;
    if (up->happy<=20||up->hungry<=10) {
        up->life-=10;
    }
    if (up->life==0) {
        set=0;
        printf("Your pet died.\n");
        setup(up);
    }
    fclose(fp);
    Main_UI(up);
}
void Play_UI(struct User_Pet *up)
{
    int input;
Play:
    printf("--------------------------------------------\n");
    printf("     What do you want to play with it?      \n");
    printf("1: Play football.             Age 3 and more\n");
    printf("😀 : 10                                     \n");
    printf("2: Sports.                    Age 5 and more\n");
    printf("😀 : 20                                     \n");
    printf("3: Painting.                        All ages\n");
    printf("😀 : 5                                      \n");
    printf("4: Back                                     \n");
    printf("--------------------------------------------\n");
    printf(":");
    scanf("%d",&input);
    switch (input) {
        case 1:
            if (up->age>=3)
            {
                printf("You are playing football with it.\n");
                up->happy+=10;
                goto Play;
            }
            else
            {
                printf("It is too young,it cannot play it.\n");
                goto Play;
            }
            break;
        case 2:
            if (up->age>=5)
            {
                printf("You are playing sports with it.\n");
                up->happy+=20;
                goto Play;
            }
            else
            {
                printf("It is too young,it cannot play it.\n");
                goto Play;
            }
            break;
        case 3:
            printf("You are painting with it.\n");
            up->happy+=5;
            goto Play;
            break;
        case 4:
            Main_UI(up);
            break;
        default:
            printf("Input Error.\n");
            goto Play;
            break;
    }
}
void Feed_UI(struct User_Pet *up)
{
    int how;
Feed:
    printf("You have %d 🥕.\n",up->carrot);
    printf("How many 🥕 do you want to feed it?\n");
    printf(":");
    scanf("%d",&how);
    if (how<=up->carrot) {
        printf("You feed it.\n");
        up->hungry+=how*2;
        up->carrot-=how;
        Main_UI(up);
    }
    else{
        printf("You cannot feed it.\n");
        goto Feed;
    }
}
void about_UI(struct User_Pet *up)
{
    printf("                          \n");
    printf("My Pet\n");
    printf("Created Mr.Rubber Tech.,lnc.\n");
    printf("Made with Xcode.\n");
    printf("Copyright © 2017 Mr.Rubber Tech.,lnc. All rights reserved.\n");
    printf("Made by Louis Studio.\n");
    printf("v.1.0\n");
    printf("                          \n");
    Main_UI(up);
}
void Main_UI(struct User_Pet *up)
{
    int input = 0;
    if (up->happy>=50) {
        printf("--------------------------\n");
        printf("                          \n");
        printf("       *          *       \n");
        printf("      * *        * *      \n");
        printf("                          \n");
        printf("      *            *      \n");
        printf("       ************       \n");
        printf("                          \n");
        printf("--------------------------\n");
    }
    else
    {
        printf("--------------------------\n");
        printf("                          \n");
        printf("       *          *       \n");
        printf("      * *        * *      \n");
        printf("                          \n");
        printf("       ************       \n");
        printf("      *            *      \n");
        printf("                          \n");
        printf("--------------------------\n");
    }
    printf("Name:%s\n",up->name);
    printf("Age:%d\n",up->age);
    printf("🥕:%d\n",up->carrot);
    printf("💰:%d\n",up->money);
    printf("❤️:%d\n",up->life);
    printf("🍴:%d\n",up->hungry);
    printf("😀:%d\n",up->happy);
    printf("--------------------------\n");
    printf("           Input          \n");
    printf("         1 :Store         \n");
    printf("      2 :Play with it    \n");
    printf("        3 :Feed it        \n");
    printf("         4 :About         \n");
    printf("           5 :End         \n");
    printf("--------------------------\n");
Input:
    printf(":");
    scanf("%d",&input);
    switch (input) {
        case 1:
            Store_UI(up);
            break;
        case 2:
            Play_UI(up);
            break;
        case 3:
            Feed_UI(up);
            break;
        case 4:
            about_UI(up);
            break;
        case 5:
            break;
        default:
            printf("Input Error.Please input again.\n");
            goto Input;
            break;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct User_Pet up;
    int set = 0;
    if (set>=0) {
        OutFile(&up,&set);
    }
    else
    {
        setup(&up);
        set++;
    }
    Main_UI(&up);
    InFile(&up,&set);
    return 0;
}
