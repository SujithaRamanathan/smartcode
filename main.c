#include <stdio.h>
#include <conio.h>
#include <string.h >

char date[20];
char uname[20];
char cname[20];
char mno[15];
long int cost;
int n,i;

void main()
{

    char ch;
    char lm[20];
    //textcolor(10);
   // textbackground(4);

    do
    {
       // clrscr();
        printf("\t*****WELCOME TO SUJI CARS*****\n");
        printf("Press<1>:FOR CREATING A NEW ENTRY\n");
        printf("Press<2>:FOR DISPLAYING ENTRIES AT A GIVEN SPECIFIC DATE\n");
        printf("Press<0>:TO EXIT\n");

        printf("\n\n Enter choice:: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            write();
            break;
        case 2:
            printf("\n\n Enter date:");
            scanf("%s",&lm);
           display(lm);
            break;
        case 0:
            exit(0);

        default:
            printf("\nInvalid Selection");
        }
        getch();
        }
        while(ch!=0);
}


void write()
{

    FILE *fp;
    char dat[20];
    char unam[20];
    char cnam[20];
    char mn[15];
    long int cos;


    printf("\n Enter date--->");
    scanf("%s",&dat);
    printf("\n Enter the name of the customer---> ");
    scanf("%s",&unam);
    printf("\n Enter the name of the car---> ");
    scanf("%s",&cnam);
    printf("\n Enter the mobile number---> ");
    scanf("%s",&mn);
    printf("\n Enter the cost of the car---> ");
    scanf("%ld",&cos);

    fp=fopen("Record.txt","a");
    fprintf(fp,"\n%s %s %s %s %ld\n",dat,unam,cnam,mn,cos);
    printf("\n             Record written sucessfully!!!");
    fclose(fp);


}
void display(char da[])
{
    FILE *fp;
    int res;

    fp=fopen("Record.txt","r");

    while(fscanf(fp,"%s %s %s %s %ld\n",date,uname,cname,mno,&cost)!=EOF){
        res=strcmp(date,da);
        if(res==0)
        {

            printf("\n\n Customer name=%s",uname);
            printf("\n Car name=%s",cname);
            printf("\n Mobile number=%s",mno);
            printf("\n Cost of the car=%ld",cost);

        }


}
fclose(fp);
}




















