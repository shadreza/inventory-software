#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>  // header to show time and date
#include <windows.h>
#include <MMsystem.h>
#define namesize 30
#define passwordsize 50


char static consumername[namesize];
char static managementpasswordin[passwordsize];
char static managementnamein[namesize];
int static workagain;
int static logout;
int static login_input;
int static managementaccessvalue;
int static managementidin;
int static totalproducts = 0 ;
int static prdidc = 0 ;
float static price=0.0;
float static profit=0.0;
float static sold=0.0;
float static vat=0.0;
float static disc=0.0;
long long int static consumercontact;
long long int static consumerfanfollower;


void digit (int num)
{

    int size,div,rem,new_size,i,m=0,x,j,k;

    size=(log(num)/log(10))+1;

    int num_array[size];

    div=num;

    for(i=size-1;i>=0;i--)
    {
        if(div>9)
        {
            rem=div%10;
            num_array[i]=rem;
            div=div/10;
        }

        else
        {
            num_array[i]=div;
        }
    }

    new_size=(size*4);

    char new_array[6][new_size];



    for(i=0;i<6;i++)
        {
            k=0;
            for(j=0;j<new_size;j++)
            {

                if(j>0 && j%4==0)
                {
                    k++;
                }

                if((num_array[k]==0)&&((i==0&&((j%4)==1))||(i==0&&((j%4)==2))||(i==5&&((j%4)==1))||(i==5&&((j%4)==2))||(i==1&&((j%4)==0))||(i==2&&((j%4)==0))||(i==3&&((j%4)==0))||(i==4&&((j%4)==0))||(i==1&&((j%4)==3))||(i==2&&((j%4)==3))||(i==3&&((j%4)==3))||(i==4&&((j%4)==3))))
                {

					printf(" %c",254);

				}

                else if((num_array[k]==1)&&((i==1&&((j%4)==1))||(i==0&&((j%4)==2))||(i==1&&((j%4)==2))||(i==2&&((j%4)==2))||(i==3&&((j%4)==2))||(i==4&&((j%4)==2))||(i==5&&((j%4)==1))||(i==5&&((j%4)==0))||(i==5&&((j%4)==2))||(i==5&&((j%4)==3))))
                {

			       printf(" %c",254);

				}


            	else if((num_array[k]==2)&&((i==0&&((j%4)==1))||(i==0&&((j%4)==2))||(i==1&&((j%4)==0))||(i==1&&((j%4)==3))||(i==2&&((j%4)==3))||(i==3&&((j%4)==2))||(i==4&&((j%4)==1))||(i==5&&((j%4)==0))||(i==5&&((j%4)==1))||(i==5&&((j%4)==2))||(i==5&&((j%4)==3))))
                 {

					printf(" %c",254);

				}


            	else if((num_array[k]==3)&&((i==0&&((j%4)==1))||(i==0&&((j%4)==2))||(i==1&&((j%4)==0))||(i==1&&((j%4)==3))||(i==2&&((j%4)==2))||(i==3&&((j%4)==3))||(i==4&&((j%4)==0))||(i==4&&((j%4)==3))||(i==5&&((j%4)==1))||(i==5&&((j%4)==2))))
                {

					printf(" %c",254);

				}


            	else if((num_array[k]==4)&&((i==0&&((j%4)==2))||(i==0&&((j%4)==3))||(i==1&&((j%4)==1))||(i==1&&((j%4)==3))||(i==2&&((j%4)==0))||(i==2&&((j%4)==1))||(i==2&&((j%4)==2))||(i==2&&((j%4)==3))||(i==3&&((j%4)==3))||(i==4&&((j%4)==3))||(i==5&&((j%4)==3))))
                 {

					printf(" %c",254);

				}


            	else if((num_array[k]==5)&&((i==0&&((j%4)==0))||(i==0&&((j%4)==1))||(i==0&&((j%4)==2))||(i==0&&((j%4)==3))||(i==1&&((j%4)==0))||(i==2&&((j%4)==0))||(i==2&&((j%4)==1))||(i==2&&((j%4)==2))||(i==3&&((j%4)==3))||(i==4&&((j%4)==3))||(i==5&&((j%4)==0))||(i==5&&((j%4)==1))||(i==5&&((j%4)==2))))
                {

					printf(" %c",254);

				}

                else if((num_array[k]==6)&&((i==0&&((j%4)==1))||(i==0&&((j%4)==2))||(i==0&&((j%4)==3))||(i==1&&((j%4)==0))||(i==2&&((j%4)==0))||(i==2&&((j%4)==1))||(i==2&&((j%4)==2))||(i==3&&((j%4)==0))||(i==3&&((j%4)==3))||(i==4&&((j%4)==0))||(i==4&&((j%4)==3))||(i==5&&((j%4)==1))||(i==5&&((j%4)==2))))
                 {

					printf(" %c",254);

				}
                else if((num_array[k]==7)&&((i==0&&((j%4)==0))||(i==0&&((j%4)==1))||(i==0&&((j%4)==2))||(i==0&&((j%4)==3))||(i==2&&((j%4)==2))||(i==3&&((j%4)==1))||(i==5&&((j%4)==0))))
                 {

					printf(" %c",254);

				}


            	else if((num_array[k]==8)&&((i==0&&(((j%4)%4))==0)||(i==(0%4)&&((j%4)==1))||(i==0&&((j%4)==3))||(i==1&&((j%4)==0))||(i==1&&((j%4)==3))||(i==2&&((j%4)==0))||(i==2&&((j%4)==1))||(i==2&&((j%4)==3))||(i==3&&((j%4)==0))||(i==5&&((j%4)==2))||(i==2&&((j%4)==2))||(i==0&&((j%4)==2))||(i==3&&((j%4)==3))||(i==4&&((j%4)==0))||(i==4&&((j%4)==3))||(i==5&&((j%4)==0))||(i==5&&((j%4)==1))||(i==5&&((j%4)==3))))
                {
                    printf(" %c",254);
                }

                else if((num_array[k]==9)&&((i==0&&((j%4)==0))||(i==0&&((j%4)==1))||(i==0&&((j%4)==3))||(i==1&&((j%4)==0))||(i==1&&((j%4)==3))||(i==2&&((j%4)==0))||(i==2&&((j%4)==1))||(i==2&&((j%4)==3))||(i==3&&((j%4)==3))||(i==4&&((j%4)==0))||(i==4&&((j%4)==3))||(i==5&&((j%4)==0))||(i==5&&((j%4)==1))||(i==5&&((j%4)==3))||(i==5&&((j%4)==2))||(i==0&&((j%4)==2))||(i==2&&((j%4)==2))))
                {
                    printf(" %c",254);
                }


                else
                {
                    printf("  ");
                }

            }
            if(i==5 && j==new_size)
            {
                printf("  %%");
            }
            printf("\n");

        }

    printf("\n\n");

}

void bar_print(char * a,int n)
{
    int i;
    for(i=0;i<=100;i++)
    {
        if(i==0)
        {
            printf("%s\t",a);
        }
        else
        {
            if(i<=n)
            {
                printf("%c",254);
            }
            else
            {
                printf(" ");
            }
            if(i==100)
            {
                printf("%c %d%% left",219,n);
            }


        }
    }
    printf("\n");
}

struct Products
{
    float prdpricebought;
    float prdpricesell;
    int prdid;
    int prdqty;
    char prdname[100];
};
typedef struct Products prd;

struct Consumer
{
    char name[namesize];
    long long int contact_no;
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
    scanf("%d",&login_input);
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
    int i;
    int namemobileprovide;  // will the consumer provide his name and mobile number
    consumerinfo consumer;

    label_wrongfanfollowerqna:
        printf("\n\t\t\t\t\t\t Consumer Side\n\t\t\t\t\t");
        underline();
            printf("\n\tWould you like to provide your name and mobile number? \n\t\t\tPress\t\t((1)Yes/(2)No)?\t");
            scanf("%d",&namemobileprovide);
            label_wrongnamemobileinput:
            if(namemobileprovide==1)
            {
                printf("\n\t\tYour Name please:\t");
                scanf("%s",consumer.name);
                printf("\n\t\tYour Mobile number please:\t");
                scanf("%I64d",&consumer.contact_no);
            }
            else if(namemobileprovide==2)
            {
                consumer.name[0]='u';
                consumer.name[1]='n';
                consumer.name[2]='k';
                consumer.name[3]='n';
                consumer.name[4]='o';
                consumer.name[5]='w';
                consumer.name[6]='n';
                consumer.name[7]='\0';
                consumer.contact_no=0;

            }
            else
            {
                printf("\n\tWrong input");
                goto label_wrongnamemobileinput;
            }


        FILE * f;
        f=fopen("customer.txt","w");
            fprintf(f,"%s\n%d\n",consumer.name,consumer.contact_no);
        fclose(f);


        for(i=0;i<strlen(consumer.name);i++)
        {
            consumername[i]=consumer.name[i];
        }
        consumername[i]='\0';
        consumercontact=consumer.contact_no;



        return consumer;

}

void show_prd_to_sell()
{
    FILE * f;
    char name[100];
    int id;
    int i;
    int ic;
    int qty;
    float bp;
    float sp;
    printf("\n\n\t\t\tProducts For Sale\n\t\t");
    underline();
    f=fopen("prdtosellcount.txt","r");
        fscanf(f,"%d",&ic);
    fclose(f);
    printf("\n\tProduct Id\tProduct Name\tAvailable Quantity\tProduct Price\t\n");
    f=fopen("prdtosell.txt","r");
        if(f==NULL)
        {
            printf("No products available");
        }
        else
        {
        i=0;
        while(!feof(f))
        {
            fscanf(f,"%d",&id);
            fscanf(f,"%s",name);
            fscanf(f,"%d",&qty);
            fscanf(f,"%f",&bp);
            fscanf(f,"%f",&sp);
            i++;
            if(i<=ic)
            {
                printf("\t%d\t\t  %s\t\t  %d\t\t\t%f\n",id,name,qty,sp);
            }
            else
            {

            }

        }
    fclose(f);
}
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
    //printf("\n\n\t\t\t%s %d %s",managementname,managementid,managementpassword);
    printf("\n\n\t\tEnter the NAME :\t");
    getchar();
    gets(managementnamein);
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
    getchar();
    gets(managementpasswordin);
    if(strlen(managementpasswordin)!=strlen(managementpassword))
    {
        return 0;
    }
    for(int i=0;i<strlen(managementpassword);i++)
    {
        if(managementpassword[i]!=managementpasswordin[i])
        {
            printf("\n\t\tACCESS DENIED");
            return 0;
        }
    }
    printf("\n\t\tACCESS GRANTED\n\n");

    f = fopen("who_accessed.txt","a");
        fprintf(f,"%s(username) %d(userid) gained access in %s\n",managementnamein,managementidin,show_time());
    fclose(f);

    f = fopen("who_accessed_last.txt","w");
        fprintf(f, "%s",managementnamein);
        fprintf(f,"\n%d",managementidin);
    fclose(f);

    return 1;
}

int isidoktosell(int x)
{
    FILE * f;
    char name[100];
    int id;
    int qty;
    float bp;
    float sp;
    f=fopen("prdtosell.txt","r");
    while(!feof(f))
    {

        fscanf(f,"%d",&id);
        fscanf(f,"%s",name);
        fscanf(f,"%d",&qty);
        fscanf(f,"%f",&bp);
        fscanf(f,"%f",&sp);

    if(x==id)
    {
        fclose(f);
        return 1;
    }
    }
    fclose(f);
    return 0;
}
void purchase()
{
    FILE * f;
    FILE * p;
    char cname[100];
    int cnum;
    f=fopen("customer.txt","r");
        fscanf(f,"%s",cname);
        fscanf(f,"%d",&cnum);
    fclose(f);
    int c=how_many_prd_to_sell();
    prd a [c];
    show_prd_to_sell();
    int i=0;
    int idin;
    int qtyin;
    f=fopen("prdtosell.txt","r");
    for(i=0;i<c;i++)
    {
            fscanf(f,"%d",&a[i].prdid);
            fscanf(f,"%s",a[i].prdname);
            fscanf(f,"%d",&a[i].prdqty);
            fscanf(f,"%f",&a[i].prdpricebought);
            fscanf(f,"%f",&a[i].prdpricesell);
    }
    fclose(f);
    printf("The Id that you want to buy?\t");
    scanf("%d",&idin);

    int idc=isidoktosell(idin);
    if(idc==1)
    {
        for(i=0;i<c;i++)
        {
            if(a[i].prdid==idin)
            {
                break;
            }
        }
        printf("There are %d amounts available for %s\nHow many to buy?\n\tPress 0 if not to buy.\t",a[i].prdqty,a[i].prdname);
        scanf("%d",&qtyin);
        if(qtyin==0)
        {

        }
        else if(qtyin<0 || qtyin>a[i].prdqty)
        {
            printf("Wrong input\n");
        }
        else
        {
            p=fopen("profit.txt","r");
                if(p==NULL)
                {
                    profit=0;
                }
                else
                {
                    fscanf(p,"%f",&profit);
                }
            fclose(p);
            p=fopen("sold.txt","r");
                if(p==NULL)
                {
                    sold=0;
                }
                else
                {
                    fscanf(p,"%f",&sold);
                }
            fclose(p);
            a[i].prdqty=a[i].prdqty-qtyin;
            price=price+(qtyin*a[i].prdpricesell);
            if(profit==0)
            {
                p=fopen("profit.txt","w");
                    fprintf(p,"0");
                fclose(p);
            }
            profit=profit+((a[i].prdpricesell-a[i].prdpricebought)*qtyin*1.0);

            if(sold==0)
            {
                p=fopen("sold.txt","w");
                    fprintf(p,"0");
                fclose(p);
            }
            sold=sold+(a[i].prdpricebought*qtyin*1.0);

            f=fopen("sell_record.txt","a");
                fprintf(f,"%d\n%s\n%d\n%f\n",idin,a[i].prdname,qtyin,a[i].prdpricesell);
            fclose(f);
            f=fopen("prdtosell.txt","w");
            for(i=0;i<c;i++)
            {
            fprintf(f,"%d\n",a[i].prdid);
            fprintf(f,"%s\n",a[i].prdname);
            fprintf(f,"%d\n",a[i].prdqty);
            fprintf(f,"%f\n",a[i].prdpricebought);
            fprintf(f,"%f\n",a[i].prdpricesell);
            }
            fclose(f);
        }
    }
    int buyagain;
    printf("Want to buy more?\n\tPress : (1) Yes\t(2)No\n\t\t\tYour choice:\t");
    scanf("%d",&buyagain);
    if(buyagain==1)
    {
        purchase();
    }
    else
    {
        int idid;
        int qtyc;
        char nam[100];
        float ps;
        int cc=0;
        f=fopen("sell_record.txt","r");
            while(!feof(f))
            {
                cc++;
                fscanf(f,"%d",&idid);
                fscanf(f,"%s",nam);
                fscanf(f,"%d",&qtyin);
                fscanf(f,"%f",&ps);
            }
        fclose(f);

        printf("\n\t\t%s''s Memo\n\t",cname);
        underline();
        f=fopen("sell_record.txt","r");
        i=1;
            while(i<cc)
            {
                i++;
                fscanf(f,"%d",&idid);
                fscanf(f,"%s",nam);
                fscanf(f,"%d",&qtyc);
                fscanf(f,"%f",&ps);
                printf("\n%d %s %d %f %f",idid,nam,qtyc,ps,(qtyc*ps*1.0));
                p=fopen("sale.txt","a");
                    fprintf(p,"\n%d %s %d %f %f",idid,nam,qtyc,ps,(qtyc*ps*1.0));
                fclose(p);
            }
        fclose(f);
        price=price*(1+((vat-disc)/100))*1.0;
        printf("\nTotal Bill: %f\nVAT: %f%%\nDISC: %f%%\nTime: %s\nContact: +%d\nThank you. Good Day!",price,vat,disc,show_time(),cnum);

        p=fopen("sale.txt","a");
            fprintf(p,"\nTotal Bill: %f\nVAT: %f%%\nDISC: %f%%\nTime: %s\nContact: +%d\nThank you. Good Day!",price,vat,disc,show_time(),cnum);
        fclose(p);

        f=fopen("sell_record.txt","w");
            fprintf(f,"0");
        fclose(f);

        profit=100.0*(profit/sold);

        p=fopen("profit.txt","w");
            fprintf(p,"%f",profit);
        fclose(p);
    }

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
    fprintf(f,"\n%I64d.\tName: ",feedth+1);
    fprintf(f, "%s",consumername);
    fprintf(f, "\n\tContact number:+880%I64d\n\tFanFollower number:%I64d\n\tTime:%s\n\t... ... %s\n\n",consumercontact,consumerfanfollower,time,feedbackin);
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
        price=0.0;
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

void managementopt ()
{
    printf("\n\n\t\tWell %s these are the options :\n\t\t(1)Enter Products\n\t\t(2)Change Products\n\t\t(3)Edit VAT\n\t\t(4)Edit Discount\n\t\t(5)Highest Sale\n\t\t(6)Lowest Sale\n\t\t(7)Zero Quantity\n\t\t(8)Total Sale\n\t\t(9)Daily Sale\n\n\t%s what is your choice?\t",managementnamein,managementnamein);
}

void managementtitleprint()
{
    printf("\n\t\t\t\t\t\tManagement Side\n\t\t\t\t\t");
    underline();
}

int how_many_prd_ever_enterd()
{
    FILE * g;
    FILE * f;
    prd pdts;
    int i;
            g=fopen("prdeverenterd.txt","r");
            i=0;
            if(g==NULL)
            {
                f=fopen("prdeverenterdcount.txt","w");
                    fprintf(f,"1");
                fclose(f);
                return i;
            }
            else
            {
            while(!feof(g))
            {
                i=i+1;
                fscanf(g,"%d",&pdts.prdid);
                fscanf(g,"%s",pdts.prdname);
                fscanf(g,"%d",&pdts.prdqty);
                fscanf(g,"%f",&pdts.prdpricebought);
                fscanf(g,"%f",&pdts.prdpricesell);
            }
            fclose(g);
                f=fopen("prdeverenterdcount.txt","w");
                    fprintf(f,"%d",i-1);
                fclose(f);
                return i-1;
            }

}

int prdentry()
{

    int prdtoenter;
    int i;
    int id;
    int managementidin;
    char managementnamein [100];
    int idcount;
    int qtycount;
    float pb;
    float ps;
    char n[100];

    FILE * f;
    FILE * p;

    wrongprdentryinput:
        printf("How many products to enter?\t");
        scanf("%d",&prdtoenter);

        if(prdtoenter==0)
        {
            return 0;
        }
        else if(prdtoenter<0)
        {
            printf("\n\tWrong input please input a positive number.");
            goto wrongprdentryinput;
        }

            id=how_many_prd_ever_enterd();
            prd prdin[prdtoenter];

            for(i=0;i<prdtoenter;i++)
            {
                prdin[i].prdid=id+i+1;
                printf("\n\t\tEnter the name of the product:\t");
                getchar();
                gets(prdin[i].prdname);
                printf("\n\tEnter the quantity to enter:\t");
                scanf("%d",&prdin[i].prdqty);
                printf("\n\tEnter the buying price:\t");
                scanf("%f",&prdin[i].prdpricebought);
                printf("\n\tEnter the selling price:\t");
                scanf("%f",&prdin[i].prdpricesell);
                f=fopen("prdeverenterd.txt","a");
                    fprintf(f,"%d\n",prdin[i].prdid);
                    fprintf(f, "%s",prdin[i].prdname);
                    fprintf(f,"\n%d\n",prdin[i].prdqty);
                    fprintf(f,"%f\n",prdin[i].prdpricebought);
                    fprintf(f,"%f\n",prdin[i].prdpricesell);
                fclose(f);

                p=fopen("prdtosell.txt","a");
                    fprintf(p,"%d\n",prdin[i].prdid);
                    fprintf(p,"%s\n",prdin[i].prdname);
                    fprintf(p,"%d\n",prdin[i].prdqty);
                    fprintf(p,"%f\n",prdin[i].prdpricebought);
                    fprintf(p,"%f\n",prdin[i].prdpricesell);
                fclose(p);
            }

            f=fopen("prdeverenterd.txt","r");
            i=0;
            while(!feof(f))
            {
                fscanf(f,"%d",&idcount);
                fscanf(f,"%s",n);
                fscanf(f,"%d",&qtycount);
                fscanf(f,"%f",&pb);
                fscanf(f,"%f",&ps);
                i++;
            }
            fclose(f);

            f=fopen("prdeverenterdcount.txt","w");
                fprintf(f,"%d",i-1);
            fclose(f);


            f=fopen("prdtosell.txt","r");
            i=0;
            while(!feof(f))
            {
                fscanf(f,"%d",&idcount);
                fscanf(f,"%s",n);
                fscanf(f,"%d",&qtycount);
                fscanf(f,"%f",&pb);
                fscanf(f,"%f",&ps);
                i++;
            }
            fclose(f);

            f=fopen("prdtosellcount.txt","w");
                fprintf(f,"%d",i-1);
            fclose(f);

            f = fopen("who_accessed_last.txt","r");
                fscanf(f,"%s",managementnamein);
                fscanf(f,"%d",&managementidin);
            fclose(f);


            f=fopen("prdentryrecord.txt","a");
                fprintf(f,"%d products were entered in",prdtoenter);
                fprintf(f, "%s",show_time());

                fprintf(f, "by user_name:" );
                fprintf(f, "%s",managementnamein);

                fprintf(f, "login_id:%d\n",managementidin);
            fclose(f);


    return 1;
}

int how_many_prd_to_sell()
{
    FILE * g;
    FILE * f;
    prd pdts;
    int i;
            g=fopen("prdtosell.txt","r");
            i=0;
            if(g==NULL)
            {
                f=fopen("prdtosellcount.txt","w");
                    fprintf(f,"1");
                fclose(f);
                return i;
            }
            else
            {
            while(!feof(g))
            {
                i=i+1;
                fscanf(g,"%d",&pdts.prdid);
                fscanf(g,"%s",pdts.prdname);
                fscanf(g,"%d",&pdts.prdqty);
                fscanf(g,"%f",&pdts.prdpricebought);
                fscanf(g,"%f",&pdts.prdpricesell);
            }
            fclose(g);
                f=fopen("prdtosellcount.txt","w");
                    fprintf(f,"%d",i-1);
                fclose(f);
                return i-1;
            }
}

int isidok(int x)
{
    int id;
    int qty;
    float buyprice;
    float sellprice;
    char name [100];
    FILE * f;
    f=fopen("prdtosell.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d",&id);
        fscanf(f,"%s",name);
        fscanf(f,"%d",&qty);
        fscanf(f,"%f",&buyprice);
        fscanf(f,"%f",&sellprice);
        if(x==id)
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int isidokever(int x)
{
    int id;
    int qty;
    float buyprice;
    float sellprice;
    char name [100];
    FILE * f;
    f=fopen("prdeverenterd.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d",&id);
        fscanf(f,"%s",name);
        fscanf(f,"%d",&qty);
        fscanf(f,"%f",&buyprice);
        fscanf(f,"%f",&sellprice);
        if(x==id)
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int addoredit()
{
    FILE * f;
    FILE * p;
    FILE * q;
    char  user[100];
    char cname[100];
    int userid;
    int input;
    int id;
    int idtochange;
    int idinput;
    int i;
    int j;
    int nh=how_many_prd_ever_enterd();;
    int k=0;
    int l;
    int m=0;
    int s;
    int t=0;
    int inopt;
    int idok=0;
    int idcount=how_many_prd_to_sell();
    int idcounteveer=how_many_prd_ever_enterd();
    int cqty;
    float cbp;
    float csp;
    prd pdts [idcount];
    prd pdtss [idcounteveer];
    f=fopen("who_accessed_last.txt","r");
        fscanf(f,"%s",user);
        fscanf(f,"%d",&userid);
    fclose(f);
    i=0;
    q=fopen("prdeverenterd.txt","r");
        while(!feof(q))
        {
            fscanf(q,"%d",&pdtss[i].prdid);
            fscanf(q,"%s",pdtss[i].prdname);
            fscanf(q,"%d",&pdtss[i].prdqty);
            fscanf(q,"%f",&pdtss[i].prdpricebought);
            fscanf(q,"%f",&pdtss[i].prdpricesell);
            i++;
        }
    fclose(q);
    while(1)
    {
        printf("In the shop we have %d products available would you like to change any of them or add to them?\n\t\tPress:\t(1) Modify\n\t\t\t\t(2) Add quantity\n\t\t\t(3) Exit\n\t\t\t\tYour choice please:\t",how_many_prd_to_sell());
        scanf("%d",&input);
        if(input==3)
        {
            break;
        }
        else if(input==1)
        {
            l=0;
            m=0;
            wrongid:
            printf("Input the product id:\t");
            scanf("%d",&idinput);
            if(idinput<1 || idinput>idcount)
            {
                goto wrongid;
            }
            idok=isidok(idinput);
            if(idok==0 || idok != 1)
            {
                goto wrongid;
            }

            if(isidokever(idinput))
            {
                k=1;
            }

            f=fopen("prdtosell.txt","r");
                i=0;
                t=0;
                while(!feof(f))
                {
                    fscanf(f,"%d",&pdts[i].prdid);
                    fscanf(f,"%s",pdts[i].prdname);
                    fscanf(f,"%d",&pdts[i].prdqty);
                    fscanf(f,"%f",&pdts[i].prdpricebought);
                    fscanf(f,"%f",&pdts[i].prdpricesell);
                    if(pdts[i].prdid==idinput)
                    {
                        wrongkey:
                        printf("\nFor modification of product id %d , %s the options are given bellow:\n\t\t(1)Change Name,\n\t\t(2)Change Price Bought,\n\t\t(3)Change Price to Sell\n\t\t\tYour choice",idinput,pdts[i].prdname);
                        scanf("%d",&inopt);
                        if(inopt<1 && inopt>3)
                        {
                            printf("Wrong input.");
                            goto wrongkey;
                        }
                        if(inopt==1 && l==0)
                        {
                            getchar();
                            printf("The name that you want to give:\t");
                            gets(cname);
                            j=0;
                            p=fopen("changed_name_list.txt","a");
                                fprintf(p, "user: " );
                                fprintf(p, "%s ",user);
                                fprintf(p, "\tuserid:%d\tchanged the name ",userid);
                                fprintf(p, "%s ",pdts[i].prdname);
                                fprintf(p, "to ");
                                fprintf(p, "%s ",cname);
                                fprintf(p, "in ");
                                fprintf(p, "%s",show_time());
                                fprintf(p, "\n");
                            fclose(p);
                            while(cname[j]!='\0')
                            {
                                pdts[i].prdname[j]=cname[j];
                                j++;
                            }
                            pdts[i].prdname[j]='\0';
                            l++;
                            if(k==1 && m==0)
                            {
                                s=0;
                                while(t<nh)
                                    {
                                        if(pdtss[t].prdid==idinput)
                                        {
                                            while(cname[s]!='\0')
                                            {
                                                pdtss[t].prdname[s]=cname[s];
                                                s++;
                                            }
                                            pdtss[t].prdname[s]='\0';
                                        }
                                        t++;
                                    }
                                m=1;
                            }

                        }
                        else if(inopt==2 && l==0)
                        {
                            wrong:
                            printf("The buying price that you want to change:\t");
                            scanf("%f",&cbp);
                            if(cbp<0)
                            {
                                printf("Value must be non negative");
                                goto wrong;
                            }
                            p=fopen("changed_buying_price_list.txt","a");
                                fprintf(p, "user: " );

                                fprintf(p, "%s",user);
                                fprintf(p, "\tuserid:%d\tchanged the buying price of prd_id %d , ",userid,pdts[i].prdid);
                                fprintf(p, "%s ",pdts[i].prdname);
                                fprintf(p, "from %f to %f in ",pdts[i].prdpricebought,cbp);
                                fprintf(p, "%s",show_time());
                                fprintf(p, "\n");
                            fclose(p);
                            pdts[i].prdpricebought=cbp;
                            l++;
                            t=0;
                            if(k==1 && m==0)
                            {
                                while(t<nh)
                                {
                                    if(pdtss[t].prdid==idinput)
                                    {
                                        pdtss[t].prdpricebought=cbp;
                                    }
                                    t++;
                                }
                                m=1;
                            }
                        }
                        else if(inopt==3 && l==0)
                        {
                            wrongn:
                            printf("The Selling price that you want to change:\t");
                            scanf("%f",&csp);
                            if(csp<0)
                            {
                                printf("Value must be non negative");
                                goto wrongn;
                            }
                            p=fopen("changed_buying_price_list.txt","a");
                                fprintf(p, "user: " );

                                fprintf(p, "%s",user);
                                fprintf(p, "\tuserid:%d\tchanged the buying price of prd_id %d , ",userid,pdts[i].prdid);

                                fprintf(p, "%s ",pdts[i].prdname);
                                fprintf(p, "from %f to %f in ",pdts[i].prdpricesell,csp);

                                fprintf(p, "%s",show_time());
                                fprintf(p, "\n");
                            fclose(p);
                            pdts[i].prdpricesell=csp;
                            l++;
                            t=0;
                            if(k==1 && m==0)
                            {
                                while(t<nh)
                                {
                                    if(pdtss[t].prdid==idinput)
                                    {
                                        pdtss[t].prdpricesell=csp;
                                    }
                                    t++;
                                }
                                m=1;
                            }
                        }
                    }
                    i++;


                }

            fclose(f);
            f=fopen("prdtosell.txt","w");
                for(i=0;i<idcount;i++)
                {
                    fprintf(f, "%d\n",pdts[i].prdid );
                    fprintf(f, "%s\n",pdts[i].prdname);
                    fprintf(f, "%d\n", pdts[i].prdqty);
                    fprintf(f, "%f\n",pdts[i].prdpricebought );
                    fprintf(f, "%f\n",pdts[i].prdpricesell);
                }
            fclose(f);
            f=fopen("prdeverenterd.txt","w");
                for(i=0;i<nh;i++)
                {
                    fprintf(f, "%d\n",pdtss[i].prdid );
                    fprintf(f, "%s\n",pdtss[i].prdname);
                    fprintf(f, "%d\n",pdtss[i].prdqty);
                    fprintf(f, "%f\n",pdtss[i].prdpricebought );
                    fprintf(f, "%f\n",pdtss[i].prdpricesell);
                }
            fclose(f);

        }
        else if(input==2)
        {
            l=0;
            m=0;
            if(isidokever(idinput))
            {
                k=1;
            }
            wrongids:
            printf("Input the product id:\t");
            scanf("%d",&idinput);
            if(idinput<1||idinput>idcount)
            {
                goto wrongids;
            }
            idok=isidok(idinput);
            if(idok==0 || idok != 1)
            {
                goto wrongid;
            }
            f=fopen("prdtosell.txt","r");
                i=0;
                while(!feof(f))
                {
                    fscanf(f,"%d",&pdts[i].prdid);
                    fscanf(f,"%s",pdts[i].prdname);
                    fscanf(f,"%d",&pdts[i].prdqty);
                    fscanf(f,"%f",&pdts[i].prdpricebought);
                    fscanf(f,"%f",&pdts[i].prdpricesell);
                    if(pdts[i].prdid==idinput && l==0)
                    {
                        wrongin:
                        printf("\nHow many quantities to add to product id %d , %s \t:",idinput,pdts[i].prdname);
                        scanf("%d",&cqty);
                        if(cqty<0)
                        {
                            printf("wrong input.");
                            goto wrongin;
                        }
                        p=fopen("changed_qty_list.txt","a");
                                fprintf(p, "user: " );
                                fprintf(p, "%s",user);
                                fprintf(p, "\tuserid:%d\tadded quantity of prd_id , ",userid,pdts[i].prdid);
                                fprintf(p, "%s ",pdts[i].prdname);
                                fprintf(p, "%d to %d in ",pdts[i].prdqty,pdts[i].prdqty+cqty);
                                fprintf(p, "%s",show_time());
                                fprintf(p, "\n");
                        fclose(p);
                        pdts[i].prdqty=pdts[i].prdqty+cqty;
                        l++;

                            t=0;
                            if(k==1 && m==0)
                            {
                                while(t<nh)
                                {
                                    if(pdtss[t].prdid==idinput)
                                    {
                                        pdtss[t].prdqty=pdtss[t].prdqty+cqty;
                                    }
                                    t++;
                                }
                                m=1;
                            }
                    }
                    i++;


                }
            fclose(f);

            f=fopen("prdtosell.txt","w");
                for(i=0;i<idcount;i++)
                {
                    fprintf(f, "%d\n",pdts[i].prdid );
                    fprintf(f, "%s\n",pdts[i].prdname);
                    fprintf(f, "%d\n", pdts[i].prdqty);
                    fprintf(f, "%f\n",pdts[i].prdpricebought );
                    fprintf(f, "%f\n",pdts[i].prdpricesell);
                }
            fclose(f);

            f=fopen("prdeverenterd.txt","w");
                for(i=0;i<nh;i++)
                {
                    fprintf(f, "%d\n",pdtss[i].prdid );
                    fprintf(f, "%s\n",pdtss[i].prdname);
                    fprintf(f, "%d\n",pdtss[i].prdqty);
                    fprintf(f, "%f\n",pdtss[i].prdpricebought );
                    fprintf(f, "%f\n",pdtss[i].prdpricesell);
                }
            fclose(f);
        }
        else
        {
            printf("Wrong input. Please check again.");
        }
    }
    return 1;
}

int isidokok(int x)
{
    FILE * f;
    char name[100];
    int id;
    int qty;
    float bp;
    float sp;
    f=fopen("prdtosell.txt","r");
    while(!feof(f))
    {

        fscanf(f,"%d",&id);
        fscanf(f,"%s",name);
        fscanf(f,"%d",&qty);
        fscanf(f,"%f",&bp);
        fscanf(f,"%f",&sp);

    if(x==id)
    {
        fclose(f);
        return 1;
    }
    }
    fclose(f);
    return 0;
}

void del_prd()
{

    FILE * f;
    FILE * p;
    char name[100];
    int idin;
    int i;
    int c=how_many_prd_to_sell();
    prd a[c];
    printf("Give the prd id to delete\t");
    scanf("%d",&idin);
    if(isidokok(idin))
    {
        f=fopen("prdtosell.txt","r");
        for(i=0;i<c;i++)
        {
            fscanf(f,"%d",&a[i].prdid);
            fscanf(f,"%s",a[i].prdname);
            fscanf(f,"%d",&a[i].prdqty);
            fscanf(f,"%f",&a[i].prdpricebought);
            fscanf(f,"%f",&a[i].prdpricesell);
        }
        fclose(f);

        f=fopen("prdtosell.txt","w");
        for(i=0;i<c;i++)
        {
            if(a[i].prdid==idin)
            {
                continue;
            }
            else
            {
                fprintf(f,"%d\n%s\n%d\n%f\n%f\n",a[i].prdid,a[i].prdname,a[i].prdqty,a[i].prdpricebought,a[i].prdpricesell);
            }
        }
        fclose(f);
    }
    else
    {
        printf("Wrong Product id.");
        del_prd();
    }
    f=fopen("prdtosellcount.txt","r");
        fscanf(f,"%d",&i);
    fclose(f);
    f=fopen("prdtosellcount.txt","w");
        fprintf(f,"%d",i-1);
    fclose(f);

}

void change_vat_disc()
{
    vatwr:
    printf("What will be your VAT at present it is %f\t",vat);
    scanf("%f",&vat);
    if(vat<0)
    {
        printf("VAT can not be negative. Please put correct value.\n");
        goto vatwr;
    }
    discwr:
    printf("What will be your DISCOUNT at present it is %f\t",disc);
    scanf("%f",&disc);
    if(disc<0 || disc >100)
    {
        printf("DISCOUNT must be between zero(0%) to hundred(100%). Please put correct value.\n");
        goto discwr;
    }
}

void show_zero_qty()
{
    FILE * f;
    char name[100];
    int id;
    int qty;
    int i;
    int c=how_many_prd_to_sell();
    float bp;
    float sp;
    i=0;
    f=fopen("prdtosell.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d",&id);
        fscanf(f,"%s",name);
        fscanf(f,"%d",&qty);
        fscanf(f,"%f",&bp);
        fscanf(f,"%f",&sp);
        if((qty==0 || qty<1)&&(i<c))
        {
            ++i;
            printf("The product having zero quantity is prd id\n");
            digit(id);

        }
    }
    if(i==0)
    {
        printf("No such Products that are ZERO in QUANTITY\n");
    }
    fclose(f);
}

void bar()
{
    FILE * f;
    FILE * p;
    int c=how_many_prd_to_sell();
    prd a[c];
    int cp=how_many_prd_ever_enterd();
    prd b[cp];
    int q;
    int i;
    int j;
    f=fopen("prdtosell.txt","r");
        for(i=0;i<c;i++)
        {
            fscanf(f,"%d",&a[i].prdid);
            fscanf(f,"%s",a[i].prdname);
            fscanf(f,"%d",&a[i].prdqty);
            p=fopen("prdeverenterd.txt","r");
                for(j=0;j<cp;j++)
                {
                    fscanf(p,"%d",&b[j].prdid);
                    fscanf(p,"%s",b[j].prdname);
                    fscanf(p,"%d",&b[j].prdqty);
                    fscanf(p,"%f",&b[j].prdpricebought);
                    fscanf(p,"%f",&b[j].prdpricesell);
                    if(a[i].prdid==b[j].prdid)
                    {
                        bar_print(&b[j].prdname[0],((100*a[i].prdqty)/b[j].prdqty));
                        printf("\n");
                        break;
                    }
                }
            fclose(p);
            fscanf(f,"%f",&a[i].prdpricebought);
            fscanf(f,"%f",&a[i].prdpricesell);
        }
    fclose(f);
}

void is_less_than_10()
{
    FILE * f;
    int i;
    int c=how_many_prd_to_sell();
    prd a[c];
    f=fopen("prdtosell.txt","r");
        for(i=0;i<c;i++)
        {
            fscanf(f,"%d",&a[i].prdid);
            fscanf(f,"%s",a[i].prdname);
            fscanf(f,"%d",&a[i].prdqty);
            fscanf(f,"%f",&a[i].prdpricebought);
            fscanf(f,"%f",&a[i].prdpricesell);
        }
    fclose(f);
    for(i=0;i<c;i++)
    {
        if(a[i].prdqty<10)
        {
            printf("\nProduct Id %d , %s is running low less than 10 at present %d quantities.",a[i].prdid,a[i].prdname,a[i].prdqty);
        }
    }
}

int managementchoice ()
{
    printf("\n\n\t\tThe options that you can handle are:");
    printf("\n\n\t\t\t1. Enter New Products.");
    printf("\n\n\t\t\t2. Add or Edit Products.");
    printf("\n\n\t\t\t3. Delete Products.");
    printf("\n\n\t\t\t4. Show All Available Products.");
    printf("\n\n\t\t\t5. Show The Zero Quantity Product.");
    printf("\n\n\t\t\t6. Edit VAT & DISCOUNT.");
    printf("\n\n\t\t\t7. Show profit.");
    printf("\n\n\t\t\t8. Bar Print.");
    printf("\n\n\t\t\t9. Exit.");
    printf("\n\n\t\tPress the number associated with the option: \t");
    is_less_than_10();
    int managementoptionin;
    scanf("%d",&managementoptionin);
    if(managementoptionin==1)
    {
        int reciever=prdentry();
    }
    else if(managementoptionin==2)
    {
        int reciever=addoredit();
    }
    else if(managementoptionin==3)
    {
        del_prd();
    }
    else if(managementoptionin==4)
    {
        show_prd_to_sell();
    }
    else if(managementoptionin==5)
    {
        show_zero_qty();
    }
    else if(managementoptionin==6)
    {
        change_vat_disc();
    }
    else if(managementoptionin==7)
    {
        FILE * f;
        f=fopen("profit.txt","r");
        fscanf(f,"%f",&profit);
        fclose(f);
        digit(profit);
    }
    else if(managementoptionin==8)
    {
        bar();
    }
    else if(managementoptionin==9)
    {
        return 0;
    }
    else
    {

    }

    return 1;

}

int wanttologout ()
{
        printf("\n\n\t\t\n\tWant to Log Out?\tPress\t(1)Yes\n\t\t\t\tor\n\t\t\t\t(2)No\t");
        scanf("%d",&logout);
        if(logout==1)
        {
            printf("\n\n\t\tAn User has just LOGGED OUT");
            return 1;
        }
        else
        {
            return 0;
        }
}

int main()
{

        printf("This song was taken from ENRICHO , a youtube content maker\n");
        //PlaySound(TEXT("D:\\programming\\c\\cse106_project\\INVENTORY_soft_by_shadreza\\my.wav"),NULL,SND_ASYNC);

    consumerinfo consumer;
oncemore:
    time_date();
    firstdisplay();
    login_input=log_in();
    if(login_input==0)
    {
        printf("\n\n\t\t\tTERMINATING the process\n\n");
        return 0;
    }
    else if(login_input==1)
    {
        time_date();
        managementtitleprint();

        managementaccessvalue=managementaccess();
    againmanagement:
        if(managementaccessvalue==1)
        {
            managementchoice();
            if(wanttologout())
            {

            }
            else
            {
                goto againmanagement;
            }
        }


    }
    else if(login_input==2)
    {
        time_date();
        consumer=consumerinfogather();
        consumeroptions();
    }
    printf("\n\n\t\tAny work left?\n\t\t\tPress\t(1)Yes\n\t\t\t\tor\n\t\t\t\t(2)No\t");
    scanf("%d",&workagain);
    if(workagain==1)
    {
        goto oncemore;
    }
    printf("\n\n");
    return 0;
}