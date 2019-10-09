#include <stdio.h>
#include <string.h>
#include <time.h>  // header to show time and date
#define namesize 30
#define passwordsize 50

char static consumername[namesize];
long long int static consumercontact;
long long int static consumerfanfollower;
char static managementpasswordin[passwordsize];
char static managementnamein[namesize];
int static managementidin;

struct Consumer
{
    char name[namesize];
    long long int contact_no;
    long long int fan_id;
};

struct Management
{
    char name[namesize];
    char password[passwordsize];
    long long int id;
};

typedef struct Consumer consumerinfo;

void time_date ()  // showing date and time
{
    printf("\n");
    time_t t;  // not a primitive data type
    time(&t);
    printf("\t\t\t\t\t\t\t\t\t\t\tToday %s",ctime(&t));
    printf("\n");
}

const char * show_time ()
{
    time_t t;
    time(&t);
    return ctime(&t);
}

void firstdisplay()  // printing the fist display
{
    for(int i=1;i<=13;i++)
    {
        if(i==1)
        {
            printf("\t\t\t\t\t");
        }
        printf("%c%c",220,220);
    }
    printf("\n\t\t\t\t\t\%c                        \%c",219,219);
    printf("\n\t\t\t\t\t");
    printf("\%c   Inventory Software   \%c",219,219);
    printf("\n\t\t\t\t\t\%c                        \%c",219,219);
    printf("\n\t\t\t\t\t");
    printf("\%c\t  by\x2026Shad Reza   \%c\n",219,219);
    printf("\t\t\t\t\t\%c                        \%c\n",219,219);
    for(int i=1;i<=13;i++)
    {
        if(i==1)
        {
            printf("\t\t\t\t\t");
        }
        printf("%c%c",223,223);
    }
   printf("\n");
}

int log_in()  // log in option
{
    printf("\n");
    printf("\n\tHello and Welcome to my software\n\tAt first please IDENTIFY yourself\n\tPRESS\n\t(1) if management needs to access\n\t\tor\n\t(2) if a customer is there\n\t\tor\n\t(0) if want to exit\n\n\t\tYour input please :\t");
    int login_input;
    wscanf(L"%d",&login_input);
    if(login_input!=1 && login_input!=2 && login_input!=0)
    {
        printf("\n\tINVALID input");
        log_in();
    }
    return login_input;
}

void underline()  // underline or highlighting a header
{
    for(int i=1;i<=15;i++)
    {
        printf("%c%c",169,170);
    }
    printf("\n");
}

consumerinfo consumerinfogather()  // collecting data from the consumer
{
    char fanfollowerqna;  // is the customer a fan with a fan id
    char namemobileprovide;  // will the consumer provide his name and mobile number
    consumerinfo consumer;
    int i;

    label_wrongfanfollowerqna:
        printf("\n\t\t\t\t\t\t Consumer Side\n\t\t\t\t\t");
        underline();
        printf("\n\tHello and GREETINGS again\n\tAre you one of our fan followers (Y/N)?\t");
        getchar();
        fanfollowerqna=getchar();
        if(fanfollowerqna=='Y'||fanfollowerqna=='y')
        {
            printf("\n\t\tYour FANFOLLOWER ID please:\t");
            scanf("%I64d",&consumer.fan_id);
        }
        else if(fanfollowerqna=='N'||fanfollowerqna=='n')
        {
            printf("\n\tIf you have purchased more than 5000 bdt then you will automatically be in the club with special discounts of 10%\n");
            printf("\n\tWould you like to provide your name and mobile number (Y/N)\t");
            getchar();
            namemobileprovide=getchar();

            label_wrongnamemobileinput:
            if(namemobileprovide=='Y'||namemobileprovide=='y')
            {
                printf("\n\t\tYour Name please:\t");
                getchar();
                gets(consumer.name);
                printf("\n\t\tYour Mobile number please:\t");
                scanf("%I64d",&consumer.contact_no);
                consumer.fan_id=0;
            }
            else if(namemobileprovide=='N'||namemobileprovide=='n')
            {
                consumer.name[0]='u';
                consumer.name[1]='n';
                consumer.name[2]='k';
                consumer.name[3]='n';
                consumer.name[4]='o';
                consumer.name[5]='w';
                consumer.name[6]='n';
                consumer.name[7]='\0';
                consumer.contact_no=-1;
                consumer.fan_id=-1;
            }
            else
            {
                printf("\n\tWrong input");
                goto label_wrongnamemobileinput;
            }
        }
        else
        {
            printf("\n\tWrong input");
            goto label_wrongfanfollowerqna;
        }

        for(i=0;i<strlen(consumer.name);i++)
        {
            consumername[i]=consumer.name[i];
        }
        consumername[i]='\0';
        consumercontact=consumer.contact_no;
        consumerfanfollower=consumer.fan_id;

        return consumer;

}

int managementaccess()
{
    char managementpassword[passwordsize];
    char managementname[namesize];
    int managementid;
    FILE * f;
    f = fopen("password.txt","r");
    fscanf(f,"%s",managementname);
    fscanf(f,"%d",&managementid);
    fscanf(f,"%s",managementpassword);
    fclose(f);
    printf("\n\n\t\t\t%s %d %s",managementname,managementid,managementpassword);
    printf("\n\n\t\tEnter the NAME :\t");
    scanf("%s",managementnamein);
    if(strlen(managementnamein)!=strlen(managementname))
    {
        return 0;
    }
    for(int i=0;i<strlen(managementname);i++)
    {
        if(managementname[i]!=managementnamein[i])
        {
            return 0;
        }
        else
        {
            if(i==strlen(managementname)-1)
            {

            }
        }
    }
    printf("\n\n\t\tEnter the ID :\t");
    scanf("%d",&managementidin);
    if(managementid!=managementidin)
    {
        return 0;
    }
    printf("\n\n\t\tEnter the Password :\t");
    scanf("%s",managementpasswordin);
    if(strlen(managementpasswordin)!=strlen(managementpassword))
    {
        return 0;
    }
    for(int i=0;i<strlen(managementpassword);i++)
    {
        if(managementpassword[i]!=managementpasswordin[i])
        {
            return 0;
        }
        else
        {
            if(i==strlen(managementpassword)-1)
            {

            }
        }

    }
    return 1;
}

void purchase ()
{

}

void feedback ()
{
    FILE * f;
    FILE * p;
    int a=0;
    const char * time = show_time();
    long long int feedth;
    f=fopen("feedbackcounter.txt","r");
    if(f==NULL)
    {
        p=fopen("feedbackcounter.txt","a");
        fprintf(p,"%d\t",a);
        fclose(p);
    }
    fclose(f);
    f=fopen("feedbackcounter.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%I64d",&feedth);
    }
    fclose(f);


    char feedbackin[100000];

    printf("\n\t\tWe really value your feedbacks ,%s:\t",consumername);
    getchar();
    gets(feedbackin);

    f=fopen("feedback.txt","a");
    fprintf(f,"\n%I64d.\tName:%s\n\tContact number:+880%I64d\n\tFanFollower number:%I64d\n\tTime:%s\n\t... ... %s\n\n",feedth+1,consumername,consumercontact,consumerfanfollower,time,feedbackin);
    fclose(f);

    f=fopen("feedbackcounter.txt","a");
    fprintf(f,"\t%I64d",feedth+1);
    fclose(f);

}

void consumeroptions ()
{
    int choice;
    printf("\n\n\t\t%s , you have the following options :\n\t\t\t(1)Make a Purchase\n\t\t\t(2)Give a Feedback\n\t\t\t(3)Exit\n\t\tPlease give a choice :\t",consumername);
    scanf("%d",&choice);
    if(choice==1)
    {
        purchase();
    }
    else if(choice==2)
    {
        feedback();
    }
    else if(choice==3)
    {
        printf("\n\t\tThank You %s and Goodbye\n",consumername);
    }
    else
    {
        printf("\n\t\tINVALID INPUT %s please read carefully\n",consumername);
        consumeroptions();
    }
}

int main()
{
    oncemore:
    int managementaccessvalue;
    consumerinfo consumer;
    time_date();
    firstdisplay();
    int login_input=log_in();
    char workagain;
    if(login_input==0)
    {
        printf("\n\t\t\t\t\t\tTERMINATING the process\n\n");
        return 0;
    }
    else if(login_input==1)
    {
        time_date();
        printf("\n\t\t\t\t\t\tManagement Side\n\t\t\t\t\t");
        underline();
        managementaccessvalue=managementaccess();
        if(managementaccessvalue==1)
        {
            printf("\n\t\tACCESS GRANTED");
        }
        else
        {
            printf("\n\t\tACCESS DENIED");
        }
    }
    else if(login_input==2)
    {
        time_date();
        consumer=consumerinfogather();
        consumeroptions();
    }
    printf("\n\n\t\tAny work left? (Y/N)\t");
    getchar();
    scanf("%c",&workagain);
    if(workagain=='Y' || workagain=='y')
    {
        goto oncemore;
    }
    printf("\n\n");
    return 0;
}
