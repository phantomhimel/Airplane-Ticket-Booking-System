#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void category();
void manager();
void signinmanager();
void stuff();
void flightInfo();
void userlogin();
void user();
void bookticket();
void helpcentre();
void flightsave();
void flightread();
void adviewflight();
void loge();
void adviewstuff();
void adreset();
void stuffsave();
void stuffread();
void admin();
void readfile();
void savefile();
void registration();
void ticketsave();
void ticketread();
void ticketshow();
void animation();
void back();

int Z = 0, W = 0, V = 0, f=0;
                                                                      /*________________ All Strucutres ________________*/
 struct flightinfo
{
    char status[50], name[50], to[50],date[50],time[50];
    int bseat,eseat,num;
} data[100];

 struct stuff
{
    char name[50];
    double tk,sum;
    int day;
} spay[100];

 struct ticket
{
    char name1[50],passnum[20],sex[10];
    int age,seat,num,type;
    char tim[30];
} tckt[100];

struct abcd
{
    char name[30];
    char mail[30];
    char nam1[20];
    char  num[20];
}access[100];


void category()
{
    char n;
    system("cls");
    printf("\n\t\t\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c MAIN MENU %c%c%c%c%c%c%c%c%c",178,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,178);
    printf("\n\n\n\t\t\t\t\t\t\t\tPress\n\t\t\t\t\t\t\t\t\t-> 1. Admin\n\t\t\t\t\t\t\t\t\t-> 2. Manager\n\t\t\t\t\t\t\t\t\t-> 3. Passenger\n\t\t\t\t\t\t\t\t\t-> 4. Exit");
    printf("\n\nEnter Choice: ");
    n=getche();
    if (n=='1'){
        animation();
        system("cls");
        signinmanager();
        admin();
    }
    else if (n=='2'){
        animation();
        system("cls");
        signinmanager();
        manager();
    }
    else if (n=='3'){
        animation();
        system("cls");
        user();
    }
    else if (n=='4'){
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t~~~~~~~~~~~~ THANX FOR YOUR VISIT ~~~~~~~~~~~~\n\n\n\n\n\n\n\n\n\n");
        exit(0);
    }
    else{
        system("cls");
        category();
    }
}
void signinmanager()
{
    printf("\n\t \t\t\t\t\t\t~~~~~~~~~~~~~~ SIGN UP OR SIGN IN ~~~~~~~~~~~~~~~\n\n");
    printf("\n\t\t\t\t\t\t\t-> 1. Sign In\n\t\t\t\t\t\t\t-> 2. Sign Up\n\n Enter Choice: ");
    int ch;
    ch=getche();
    if (ch=='1')
    {
        system("cls");
        loge();
    }
    else if (ch=='2')
    {
        system("cls");
        registration();
        system("cls");
        signinmanager();
    }
    else
    {
        system("cls");
        signinmanager();
    }
}

void registration()
{
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~ SIGN UP ~~~~~~~~~~~~~~~\n\n");
    printf("Enter Full Name      : ");
    fflush(stdin);
    scanf("%[^\n]s", access[f].name);
    printf("\nEnter Mail           : ");
    scanf("%s", access[f].mail);
    printf("\nChose an Username    : ");
    scanf("%s", access[f].nam1);
    printf("\nEnter Password       : ");
    scanf("%s", access[f].num);
    savefile();
    f++;
    savefile();
    printf("\n\n\t\t\t\t\t\t\t");
    system("pause");
}

void loge()
{
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~ SIGN IN ~~~~~~~~~~~~~~~\n\n");
    int i, found=0,s=0;
    char name[20],pass[20],p;
    printf("\nEnter Username   : ");
    scanf("%s", name);
    printf("\nEnter Password   : ");
    while(p!=13)
    {
        p=getch();
        if(p!=13)
        {
            putch('*');
            pass[s]=p;
            s++;
        }
    }
    pass[s]='\0';
    readfile();
    for(i=0; i<f; i++)
    {
    if (strcmp(access[i].nam1,name)==0)
    {
        if (strcmp(access[i].num,pass)==0)
        {
            found=1;
            animation();
            system("cls");
        }

    }
    }
    if (found==0)
    {
        printf("\n\n\t\t\t\t\t\t\t\xb2\xb2\xb2\xb2\xb2\xb2 ACCESS DENIED. TRY AGAIN OR SIGN UP \xb2\xb2\xb2\xb2\xb2\xb2");
        getch();
        system("cls");
        signinmanager();
    }
}


void savefile()
{
    FILE *fp;
    fp= fopen("test.txt", "w");
    fwrite(&access, sizeof(access), 1, fp);
    fclose(fp);

    FILE *fp1;
    fp1= fopen("test1.txt", "w");
    fwrite(&f, sizeof(f), 1, fp1);
    fclose(fp1);

}

void readfile()
{
    FILE *fp;
    fp= fopen("test.txt", "r");
    fread(&access, sizeof(access), 1, fp);
    fclose(fp);

    FILE *fp1;
    fp1= fopen("test1.txt", "r");
    fread(&f, sizeof(f), 1, fp1);
    fclose(fp1);
}

void manager()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~ MANAGER WORK PANEL~~~~~~~~~~~~~~~~~");
    char ch;
    printf("\n\n\t\t\t\t\t\tPress\n\t\t\t\t\t\t\t-> A. Edit Flight Information\n\t\t\t\t\t\t\t-> B. Search Passenger Passport Number To View Details\n\t\t\t\t\t\t\t-> C. Pay To Stuff\n\t\t\t\t\t\t\t-> Q. Main Menu");
    printf("\n\nEnter Choice: ");
    ch= getche();
    switch (ch)
    {
        case 'A':
        case 'a':
            animation();
            system("cls");
            flightInfo();
            break;

        case 'B':
        case 'b':
            animation();
            system("cls");
            ticketshow();
            break;

        case 'C':
        case 'c':
            animation();
            system("cls");
            stuff();
            break;

        case 'Q':
        case 'q':
            system("cls");
            category();
            break;

        default:
            manager();
    }
}

void flightInfo()
{
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~ EDIT FLIGHT INFORMATION ~~~~~~~~~~~~~~~~~");
       int i,n;
       printf("\n\nHow Many FLight Information You Want To Add? : ");
       scanf("%d",&n);
       for(i=Z; i<Z+n; i++)
       {
        printf("\nFlight Number                         : ");
        scanf("%d", & data[i].num);
        printf("\nFlight Status (International/Domestic): ");
        scanf("%s",  data[i].status);
        printf("\nFlight Name                           : ");
        scanf("%s",  data[i].name);
        printf("\nBusiness Class Seat                   : ");
        scanf("%d", & data[i].bseat);
        printf("\nEconomy Class Seat                    : ");
        scanf("%d", & data[i].eseat);
        printf("\nDestination of Flight                 : ");
        scanf("%s", data[i].to);
        printf("\nDeparture Date (dd/mm/yyyy)           : ");
        scanf("%s",  data[i].date);
        printf("\nDeparture Time (24 hr format)         : ");
        scanf("%s",  data[i].time);
        flightsave();
        printf("\n\n");
       }
       Z = i;
       flightsave();
       animation();
       printf("\n\n\t\t\t\t\t>>>>>>>>>>>>>> Flight Information Updated Successfully <<<<<<<<<<<<<<<\n");
       back();
       manager();
}

void flightsave()
{
     FILE * info;
     info = fopen("flight1.txt","w");
     fwrite(&data, sizeof(data),1,info);
     fclose(info);

     FILE * info2;
     info2 = fopen("flight2.txt", "w");
     fwrite(&Z, sizeof(Z), 1, info2);
     fclose(info2);
}

void flightread()
{
    FILE * info;
    info = fopen("flight1.txt", "r");
    fread(&data, sizeof(data), 1, info);
    fclose(info);

    FILE * info2;
    info2= fopen("flight2.txt", "r");
    fread(&Z, sizeof(Z), 1, info2);
    fclose(info2);
}

void stuff()    /* _________________________________________ a function used for paying to stuff by manager _________________________*/
{
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~ PAY TO STUFF ~~~~~~~~~~~~~~~~~~~");
    int l,d;
    double sum=0;
    printf("\n\nHow Many Stuff Do You Want To Pay? : ");
    scanf("%d", & d);
    for(l=W; l<W+d; l++)
    {
        printf("\n\nStuff Name                     : ");
        scanf("%s", spay[l].name);
        printf("\nPer Day Taka                   : BDT ");
        scanf("%lf", & spay[l].tk);
        printf("\nWorking Days                   : ");
        scanf("%d", & spay[l].day);
        spay[l].sum = (spay[l].day*spay[l].tk);
        printf("\nTotal Amount For %d Days Is    : BDT %.1lf", spay[l].day,spay[l].sum);
        stuffsave();
        printf("\n\n");
    }
    W = l;
    stuffsave();
    printf("\n\t\t\t\t\t\t\t>>>>>>>>>>>>> STUFF SALARY PAID <<<<<<<<<<<<<<\n");
     back();
     manager();
}

void stuffsave()
{
     FILE * stuffpay1;
     stuffpay1 = fopen("stuff1.txt","w");
     fwrite(&spay, sizeof(spay), 1, stuffpay1);
     fclose(stuffpay1);

     FILE  * stuffpay2;
     stuffpay2 = fopen("stuff2.txt","w");
     fwrite(&W, sizeof(W), 1, stuffpay2);
     fclose(stuffpay2);
}

void stuffread()
{
     FILE * stuffpay1;
     stuffpay1 = fopen("stuff1.txt","r");
     fread(&spay, sizeof(spay), 1, stuffpay1);
     fclose(stuffpay1);

     FILE  * stuffpay2;
     stuffpay2 = fopen("stuff2.txt","r");
     fread(&W, sizeof(W), 1, stuffpay2);
     fclose(stuffpay2);
}

void admin()
{
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~ ADMIN PANEL ~~~~~~~~~~~~~~~~~~~~");
    char ch1;
    printf("\n\n\t\t\t\t\t\tPress");
    printf("\n\t\t\t\t\t\t\t-> A. View Flight Information\n\t\t\t\t\t\t\t-> B. View Paid Stuff\n\t\t\t\t\t\t\t-> C. Reset Data\n\t\t\t\t\t\t\t-> Q. Main Menu\n\nEnter choice: ");
    ch1=getche();
    if (ch1=='A' || ch1=='a')
    {
        animation();
        system("cls");
        adviewflight();
         back();
         admin();
    }
    else if (ch1=='B' || ch1=='b')
    {
        animation();
        system("cls");
        adviewstuff();
    }
    else if(ch1=='C' || ch1=='c')
    {
        animation();
        system("cls");
        adreset();
    }
    else if (ch1=='Q' || ch1=='q')
    {
        system("cls");
        category();
    }
    else
    {
        system("cls");
        admin();
    }
}

void adviewflight()
{
        int i,m,no,found=0,found1=0,count=0,count1=0;
        printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~ VIEW FLIGHT INFORMATION ~~~~~~~~~~~\n\n");
        printf("\t=====================================================================================================================================");
        printf("\n\tSerial Id\tStatus\t\t\tName\t\tB.Seat\t\tE.Seat\t\tDestination\t\tDate\t\tTime\n");
        printf("\t=====================================================================================================================================\n\n");
        for (i=0; i<Z; i++)
        {
            found=1;
             printf("\t%d\t\t%s\t\t%s\t%d\t\t%d\t\t%s\t\t\t%s\t%s\n",data[i].num,data[i].status,data[i].name,data[i].bseat,data[i].eseat,data[i].to,data[i].date,data[i].time);
        }
        if (found==0)
        {
            printf("\n\n\t\t\t\t\t\t\t>>>>>>>>>>>>>> DATA NOT FOUND <<<<<<<<<<<<<<<");
            back();
            admin();
        }
        char ch;
        printf("\n\n\nDo You Want To See Passenger List? ( press 'y' For Yes and 'n' For No): ");
        ch=getche();
        if (ch=='y'||ch=='Y')
        {
            printf("\n\nEnter Flight Number To View Passenger List: ");
            scanf("%d",&no);
            ticketread();
            system("cls");
            printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~ PASSENGER LIST FOR FLIGHT NUMBER %d ~~~~~~~~~~~~~~~~\n\n\n",no);
            printf("\n\t\t=======================================================================================================================\n");
            printf("\t\tName\t\t|\tAge\t\t|\tGender\t\t|\tPassport Number\t\t|\tTicket Type\n");
            printf("\t\t=======================================================================================================================\n");
            for(m=0; m<V; m++)
            {
                if (no==tckt[m].num)
                {
                    found1=1;
                    if (tckt[m].type==1)
                        {
                            printf("\n\t\t%s\t\t\t%d\t\t\t%s\t\t\t%s\t\t\t\tBusiness Class", tckt[m].name1,tckt[m].age,tckt[m].sex,tckt[m].passnum);
                            count++;
                        }
                    else if(tckt[m].type==2)
                        {
                            printf("\n\t\t%s\t\t\t%d\t\t\t%s\t\t\t%s\t\t\t\tEconomy Class", tckt[m].name1,tckt[m].age,tckt[m].sex,tckt[m].passnum);
                            count1++;
                        }
                }
            }
            printf("\n\n\n\nBusiness Class Seat Booked : %d", count);
            printf("\n\nEconomy Class Seat Booked  : %d\n\n\n",count1);
            if (found1==0)
            {
                printf("\n\n\t\t\t\t\t\t\t>>>>>>>>>>>>>>> NO TICKET BOOKED YET <<<<<<<<<<<<<<", no);
            }
        if (found==0)
        {
            printf("\n\t\t\t\t\t\t\t>>>>>>>>>>>>>> DATA NOT FOUND <<<<<<<<<<<<<");
        }
        }
        else
        {
            system("@cls");
            admin();
        }
}

void adviewstuff()
{
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~ VIEW PAID STUFF ~~~~~~~~~~~~~~~~~~~~~~");
    int l,found=0,j,found1=0;
    char n;
    struct stuff temp;
    printf("\n\n\n\t\t\t\t\t\t\tPress\n\t\t\t\t\t\t\t\t-> 1. View Stuff As Ascending Paid Order\n\t\t\t\t\t\t\t\t-> 2. View Stuff As Descending Paid Order\n\nEnter: ");
    n=getche();
    if (n== '1')
    {
        for (l=0; l<W-1; l++)
        {
            for(j=0; j<W-1-l; j++)
            {
                if (spay[j].sum>spay[j+1].sum)
                {
                    temp=spay[j];
                    spay[j]=spay[j+1];
                    spay[j+1]=temp;
                }
            }
        }
        stuffsave();
          printf("\n\n\n\t\t\t==============================================================================\n");
         printf("\t\t\tName\t\tBDT Per Day\t\tWorking Days\t\tTotal Amount\n");
    printf("\t\t\t==============================================================================\n\n");
    for(l=0; l<W; l++)
        {
            found=1;
            printf("\t\t\t%s\t\t%.2lf\t\t\t%d\t\t\t%.2lf BDT\n",spay[l].name,spay[l].tk,spay[l].day,spay[l].sum);
        }

            if(found==0)
            {
                printf("\n\n\t\t\t\t\t\t\t>>>>>>>>>>>>> DATA NOT FOUND <<<<<<<<<<<<<<<");
            }
              back();
            admin();
    }
     if (n== '2' )
    {
        for (l=0; l<W-1; l++)
        {
            for(j=0; j<W-1-l; j++)
            {
                if (spay[j].sum<spay[j+1].sum)
                {
                    temp=spay[j];
                    spay[j]=spay[j+1];
                    spay[j+1]=temp;
                }
            }
        }
        stuffsave();
          printf("\n\n\n\t\t\t=============================================================================\n");
         printf("\t\t\tName\t\tBDT Per Day\t\tWorking Days\t\tTotal Amount\n");
    printf("\t\t\t=============================================================================\n\n");
    for(l=0; l<W; l++)
        {
            found1=1;
            printf("\t\t\t%s\t\t%.2lf\t\t\t%d\t\t\t%.2lf BDT\n",spay[l].name,spay[l].tk,spay[l].day,spay[l].sum);
        }
        if (found1==0)
       {
           printf("\n\n\t\t\t\t\t\t\t>>>>>>>>>>>>>> DATA NOT FOUND <<<<<<<<<<<<<<<");
           back();
           admin();
       }
         back();
         admin();
    }
    else
    {
        system("cls");
        adviewstuff();
    }
}

void adreset()
{
    char g,h;
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~ RESET DATA ~~~~~~~~~~~~~~~~~~~");
    printf("\n\nIf You Reset Your Data You'll No Longer Able to Use Them. Do You Want to Contiue? ('y' for Yes and 'n' for No)\n\nEnter:: ");
    h=getche();
    if (h=='y' || h=='Y')
    {
        system("cls");
    printf("\n\n\t\t\t\t\t\tPress\n\t\t\t\t\t\t\t-> 1. Reset All Flight and Passenger Information\n\t\t\t\t\t\t\t-> 2. Reset All Stuff Pay Informaiton\n\nEnter: ");
    g=getche();
    if (g== '1')
    {
        remove("flight1.txt");
        remove("flight2.txt");
        remove("ticket1.txt");
        remove("ticket2.txt");
        printf("\n\t\t\t\t\t>>>>>>>>>>>>>>>>>>> FLIGHT AND PASSENGER INFORMATION SUCCESSFULLY DELETED <<<<<<<<<<<<<<<<<<<");
        printf("\n\n\nPress Any Key to Quit the Program");
        getch();
        exit(0);
    }
    else if (g== '2')
    {
        remove("stuff1.txt");
        remove("stuff2.txt");
        printf("\n\t\t\t\t\t>>>>>>>>>>>>>>>>>>> STUFF INFORMATION SUCCESSFULLY DELETED <<<<<<<<<<<<<<<<<<<");
        printf("\n\n\nPress Any Key to Quit the Program");
        getch();
        exit(0);
    }
    }
    else
    {
        system("cls");
        admin();
    }
}
void user()
{
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~ USER PANEL ~~~~~~~~~~~~~~~~~~~~~");
    char n;
    printf("\n\n\n\t\t\t\t\t\tPress\n\t\t\t\t\t\t\t-> A. View Flight Schedule\n\t\t\t\t\t\t\t-> B. Ask Us\n\t\t\t\t\t\t\t-> Q. Main Menu");
    printf("\n\nEnter Choice: ");
    n=getche();
    if (n=='A' || n== 'a')
    {
        animation();
        system("cls");
        bookticket();
        back();
        user();
    }
    else if (n== 'B' || n== 'b')
    {
        animation();
        system("cls");
        helpcentre();
        back();
        user();
    }
    else if (n=='Q' || n=='q')
    {
        system("cls");
        category();
    }
    else
    {
        system("cls");
        user();
    }
}

void bookticket()
{
        int i,m,found=0;
        char ch;
        time_t t;
        time(&t);
        printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~ VIEW FLIGHT INFORMATION ~~~~~~~~~~~\n\n");
        printf("\t=====================================================================================================================================");
        printf("\n\tSerial Id\tStatus\t\t\tName\t\tB.Seat\t\tE.Seat\t\tDestination\t\tDate\t\tTime\n");
        printf("\t=====================================================================================================================================\n\n");
        for (i=0; i<Z; i++)
        {
            found=1;
             printf("\t%d\t\t%s\t\t%s\t%d\t\t%d\t\t%s\t\t\t%s\t%s\n",data[i].num,data[i].status,data[i].name,data[i].bseat,data[i].eseat,data[i].to,data[i].date,data[i].time);
        }
        if (found==0)
        {
            printf("\n\n\t\t\t\t\t\t\t>>>>>>>>>>>>>> DATA NOT FOUND <<<<<<<<<<<<<<<");
            back();
            user();
        }
        printf("\n\nDo You Want To Book Ticket? (Press 'y' For Yes 'n' For No): ");
        ch=getche();
        if (ch=='y'||ch=='Y')
        {
        printf("\n\n\n\n\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~ BUY TICKET ~~~~~~~~~~~~~~~~~~~~~");
        int m,p,k, found1=0;
        printf("\n\nHow Many Ticket You Want To Buy?       : ");
        scanf("%d", &p);
        for(m=V; m<V+p; m++)
        {
        printf("\nFlight Number                          : ");
        scanf("%d", & tckt[m].num);
        for(k=0; k<Z; k++)
        {
            if (tckt[m].num==data[k].num)
            {
                  found1=1;
                  if (data[k].bseat==0 && data[k].eseat==0)
                {
                    printf("\n\t\t\t\t\t>>>>>>>>>> Sorry!! Seats Are Not Available For %d FLight <<<<<<<<<<<",data[k].num);
                    printf("\n\nPress Any Key To Re-open The Option. . .");
                    getch();
                    system("cls");
                    bookticket();
                }
                 else {
                 printf("\nName (Give First Name)                 : ");
                scanf("%s", tckt[m].name1);
                printf("\nAge                                    : ");
                scanf("%d", & tckt[m].age);
                printf("\nGender                                 : ");
                scanf("%s", tckt[m].sex);
                printf("\nPasport Number                         : ");
                scanf("%s", & tckt[m].passnum);
                printf("\nChoose Seat Type                       : 1. Business Class (5000 BDT)\t2. Economy Class (3500 BDT)\n");
                printf("\nPress 1 Or 2 To Choose Seat            : ");
                scanf("%d", & tckt[m].type);
                if (tckt[m].type==1)
                {
                    if(data[k].bseat==0)
                    {
                        printf("\n\n\t\t>>>>>>>>>> Business Class Seat Are Not Available <<<<<<<<<<<");
                        printf("\n\n\nPress Any Key To Re-open The Option. . .");
                        getch();
                        system("cls");
                        bookticket();
                    }
                    else{
                    data[k].bseat--;
                    }
                }
                else if (tckt[m].type==2)
                {
                    if (data[k].eseat==0)
                    {
                        printf("\n\n\t\t>>>>>>>>>> Economy Class Seat Are Not Available <<<<<<<<<<<");
                        printf("\n\n\nPress Any Key To Re-open The Option. . .");
                        getch();
                        system("cls");
                        bookticket();
                    }
                    else {
                    data[k].eseat--;
                    }
                }
                printf("\nBooking Date And Time                  : %s", ctime(&t));
                strcpy(tckt[m].tim,ctime(&t));
                }

                flightsave();
        ticketsave();
            }
        }
        if(found1==0)
        {
            printf("\n\n\t\t>>>>>>>>>>>> Flight Id Doesnot Match <<<<<<<<<<<<");
            back();
            system("cls");
            user();
        }

        printf("\n\n");
        }
        V = m;
        ticketsave();
        printf("\n\t\t\t\t>>>>>>>>>>>>>> TICKET BOOKING SUCCESSFULLY DONE. PLAESE GET YOUR TICKET FROM COUNTER BEFORE FLIGHT <<<<<<<<<<<<<<\n");
        back();
        user();
        }
        else
        {
            system("cls");
            user();
        }
}

void ticketsave()
{
        FILE * flight_ticket;
        flight_ticket = fopen("ticket1.txt", "w");
        fwrite(&tckt, sizeof(tckt), 1, flight_ticket);
        fclose(flight_ticket);

        FILE * flight_ticket2;
        flight_ticket2 = fopen("ticket2.txt", "w");
        fwrite(&V, sizeof (V), 1, flight_ticket2);
        fclose(flight_ticket2);
}

void ticketread()
{
        FILE * flight_ticket;
        flight_ticket = fopen("ticket1.txt", "r");
        fread(&tckt, sizeof (tckt), 1, flight_ticket);
        fclose(flight_ticket);

        FILE * flight_ticket2;
        flight_ticket2 = fopen("ticket2.txt", "r");
        fread(&V, sizeof (V), 1, flight_ticket2);
        fclose(flight_ticket2);
}

void helpcentre()
{
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~ HELP CENTER ~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\nPlease Contact Us for Any Kind of Query\n\n");
    printf("Mail    : z_himel@outlook.com\nMobile  : +8801955377998\n\n");
    back();
    user();
}
void ticketshow()
{
    char tmp_num[10],p;
    printf("\n\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~ VIEW BOOKING TICKET ~~~~~~~~~~~~~~~~~~");
    int m,found=0,b,in;
    printf("\n\nEnter Passenger Passport Number To See The Details: ");
	scanf("%s", tmp_num);
    for(m=0; m<V; m++)
    {
    if (strcmp(tmp_num,tckt[m].passnum)==0)
        {
            found=1;
        printf("\n\nFlight Number               : %d",tckt[m].num);
        printf("\nPassenger First Name        : %s",  tckt[m].name1);
        printf("\nAge                         : %d",  tckt[m].age);
        printf("\nGender                      : %s", tckt[m].sex);
        printf("\nPassport Number             : %s", tckt[m].passnum);
        if (tckt[m].type==1)
        {
            printf("\nSeat Type                   : Business Class");
        }
        else
        {
            printf("\nSeat Type                   : Economy Class");
        }
        printf("\nTicket Booking Date         : %s", tckt[m].tim);
        }
    }
     if (found==0)
    {
        printf("\n\n\t\t\t\t\t\t\t>>>>>>>>>>>>>>> PASSPORT NUMBER DOES NOT EXISTS <<<<<<<<<<<<<<<");
        back();
        manager();
    }
        printf("\n\nPress '1' to Confirm Ticket or '2' to Cancel Ticket::: ");
        p=getche();
        if (p== '1')
        {
            printf("\n\n\t\t\t\t%c%c%c%c%c TICEKT HAS BEEN CONFIRMED %c%c%c%c%c",254,254,254,254,254,254,254,254,254,254);
            back();
            manager();
        }
        else if (p== '2')
        {
            for(m=0;m<V;m++)
            {
                if (strcmp(tmp_num,tckt[m].passnum)==0)
                {
                        for(b=0; b<Z; b++)
                            {
                                if (tckt[m].num==data[b].num)
                                    {
                                        if (tckt[m].type==1)
                                            {
                                                data[b].bseat++;
                                            }
                                        else if(tckt[m].type==2)
                                            {
                                                data[b].eseat++;
                                            }
                                    }
                            }
                    in=m;
                    break;
                }
            }
    ticketsave();
    flightsave();
    for(m=in;m<V;m++){
    	tckt[m]=tckt[m+1];
	}
	V--;
	ticketsave();
    printf("\n\n\t\t\t%c%c%c%c%c TICKET SUCCESSFULLY CANCELD %c%c%c%c%c", 254,254,254,254,254,254,254,254,254,254);
    back();
    manager();
    }
}

void animation()        /*__________________________ loading bar _________________________*/
{
    int i,j;
    printf("\n\n");
    for (i = 0; i < 10000; i++)
    {
        for(j=0;j<2500; j++)
        {

        }
        printf("\r\t\t\t\t\t\t\t\tLoading.......... %d%%", i/100+1);
    }
       printf("\n");
}

void intro()   /* ______________________________ introduction of author _________________________*/
{
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\tPROJECT NAME\n\n\t\t\t\t\t\"A I R P L A N E   M A N A G E M E N T   A N D   T I C K E T   B O O K I N G   S Y S T E M\"");
    printf("\n\n\n\n\n\n\n______________\n COMPLETED BY\n______________\t\t\tZUBAYER ALAM\n\n\t\t\t\tDEPARTMENT OF SWE\n\n\t\t\t\tDAFFODIL INTERNATIONAL UNIVERSITY\n\n\n");
    system("pause");
    system("cls");
}

void back()      /* _____________________________ a function used for going back to previous menu _____________________________*/
{
    char bck;
        printf("\n\nPress 'B' To Go Back: ");
        bck=getche();
        if (bck=='B' || bck=='b')
        {
          system("cls");
        }
        else
        {
            system("cls");
        }
}

int main()  /* ________________________________ main function of the project _________________________________*/
{
    flightread();
    stuffread();
    ticketread();
    readfile();
    system("color 3F");
    intro();
    category();
}














