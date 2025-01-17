#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<time.h>
#include<iomanip>
#include<fstream>
using namespace std;

char f[10]="f";
char s[10]="s";
int addr,ad,flag,f1,d,m,i,amt;
float tamt;

class login
{
public:
    char id[100];
    char pass[100];
    char password[100];
    void getid()
    {
        cout<<"Enter your id:";
        cin>>id;
        cout<<"Enter the password: ";
        cin>>password;
        strcpy(pass,password);
        
        fstream f;
        f.open("identities.txt",ios::in|ios::out|ios::app);
        f<<id<<" "<<password<<"\n";
        f.close();
    }
    void displayid()
    {
        cout<<"Id:"<<id<<"\n"<<"Password:"<<pass<<endl;
    }
};

class detail
{
public:
    int tno;
    char tname[100];
    char bp[100];
    char dest[100];
    int c1,c1fare;
    int c2,c2fare;
    int d,m,y;
    void getdetail()
    {
        cout<<"Enter the details as follows\n";
        cout<<"Train no:";
        cin>>tno;
        cout<<"Train name:";
        cin>>tname;
        cout<<"Boarding point:";
        cin>>bp;
        cout<<"Destination pt:";
        cin>>dest;
        cout<<"No of seats in first class & fare per ticket(separated by space):";
        cin>>c1>>c1fare;
        cout<<"No of seats in second class & fare per ticket(separated by space):";
        cin>>c2>>c2fare;
        cout<<"Date of travel(Separated by space):";
        cin>>d>>m>>y;
        
        fstream f;
        f.open("trains.txt",ios::in|ios::out|ios::app);
        f<<tno<<" "<<tname<<" "<<bp<<" "<<dest<<" "<<c1<<"-"<<c1fare<<" "<<c2<<"-"<<c2fare<<" "<<d<<"-"<<m<<"-"<<y<<"\n";
        f.close();
    }
    void displaydetail()
    {
        cout<<tno<<"\t"<<tname<<"\t"<<bp<<"\t"<<dest<<"\t";
        cout<<c1<<"\t"<<c1fare<<"\t"<<c2<<"\t"<<c2fare<<"\t";
        cout<<d<<"-"<<m<<"-"<<y<<"\t"<<endl;
    }
};

class reser
{
public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    char clas[10];
    int nosr;
    int i;
    int d,m,y;
	float amc;
    void getresdet()
    {
        cout<<"Enter the details as follows\n";
        cout<<"Train no:";
        cin>>tno;
        cout<<"Train name:";
        cin>>tname;
        cout<<"Boarding point:";
        cin>>bp;
        cout<<"Destination pt:";
        cin>>dest;
        cout<<"No of seats required:";
        cin>>nosr;
        for(i=0; i<nosr ; i++)
        {
            cout<<"Passenger name:";
            cin>>pname[i];
            cout<<"Passenger age:";
            cin>>age[i];
        }
        cout<<"Enter the class f-first class s-second class:";
        cin>>clas;
        cout<<"Date of travel:";
        cin>>d>>m>>y;
        
        fstream f;
        f.open("passengers.txt",ios::in|ios::out|ios::app);
        f<<pnr<<tno<<" "<<tname<<" "<<bp<<" "<<dest<<" "<<nosr<<" ";
		for(i=0;i<nosr;i++)
			f<<pname[i]<<" "<<age[i]<" ";
		f<<d<<"-"<<m<<"-"<<y<<"\n";
        f.close();

    }
    void displayresdet()
    {
        cout<<"...............................................\n";
        cout<<"...............................................\n";
        cout<<"Pnr no:"<<pnr;
        cout<<"\nTrain no:"<<tno;
        cout<<"\nTrain name:";
        puts(tname);
        cout<<"\nBoarding point:";
        puts(bp);
        cout<<"\nDestination pt:";
        puts(dest);
        cout<<"\nNo of seats reserved:"<<nosr;
        for(i=0; i<nosr; i++)
        {
            cout<<"\nPassenger name:";
            puts(pname[i]);
            cout<<"\nPassenger age:"<<age[i];
        }

        cout<<"\nYour class:";
        puts(clas);
        cout<<"\nDate of reservation:"<<d<<"-"<<m<<"-"<<y;
        cout<<"\nYou must pay:"<<amc<<endl;
        cout<<"***********************************************\n";
        cout<<".........END OF RESERVATION.................\n";
        cout<<"***********************************************\n";
    }
};

class canc
{
public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    int i;
    char clas[10];
    int nosc;
    int d,m,y;
    float amr;
    void getcancdet()
    {
        cout<<"Enter the details as follows\n";
        cout<<"Pnr no:";
        cin>>pnr;
        cout<<"Date of cancellation:";
        cin>>d>>m>>y;
        cout<<"...........END OF GETTING DETAILS...........\n";
    }
    void displaycancdet()
    {
        cout<<"...........................................\n";
        cout<<"...........................................\n";
        cout<<"Pnr no:"<<pnr;
        cout<<"\nTrain no:"<<tno;
        cout<<"\nTrain name:";
        puts(tname);
        cout<<"\nBoarding point:";
        puts(bp);

        cout<<"\nDestination pt:";
        puts(dest);
        cout<<"\nYour class:";
        puts(clas);
        cout<<"No of seats to be cancelled:"<<nosc;
        for(i=0; i<nosc; i++)
        {
            cout<<"\nPassenger name:";
            puts(pname[i]);
            cout<<"   Passenger age:"<<age[i];
        }
        cout<<"\nDate of cancellation:"<<d<<"-"<<m<<"-"<<y;
        cout<<"\nYou can collect:"<<amr<<"rs"<<endl;
        cout<<"*****************************************\n";
        cout<<".........END OF CANCELLATION.............\n";
        cout<<"*****************************************\n";
    }
};

void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancel();
void enquiry();
int main()
{
    int ch;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    do
    {
        cout<<"^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
        cout<<"1.Admin mode\n2.User mode\n3.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            database();
            break;
        case 2:
            user();
            break;
        case 3:
            exit(0);
        }
    }
    while(ch<=3);
    getch();
}

void database()
{
    char password[100];
    char pass[]="miniproject";
    printf("Enter the admininistrator password:");
    scanf("%s", &password);
    detail a;
    fstream f;
    int ch;
    char c;
    if(strcmp(pass,password)!=0)
    {
        cout<<"Enter the password correctly \n";
        cout<<"You are not permitted to logon this mode\n";
        return;
    }
    if(strcmp(pass,password)==0)
    {
        char c;
        do
        {
            cout<<"...........ADMINISTRATOR MENU...........\n";
            cout<<"1.Create detail data base\n2.Add details\n";
            cout<<"3.Display details\n4.User management\n";
            cout<<"5.Display passenger details\n6.Return to main menu\n";
            cout<<"Enter your choice:";
            cin>>ch;


            cout<<endl;
            switch(ch)
            {
            case 1:
                f.open("t.txt",ios::out|ios::binary);
                do
                {
                    a.getdetail();
                    f.write((char *) &a,sizeof(a));
                    cout<<"Do you want to add one more record?\n";
                    cout<<"y-for Yes\nn-for No\n";
                    cin>>c;
                }
                while(c=='y');
                f.close();
                break;
            case 2:
                f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
                a.getdetail();
                f.write((char *) &a,sizeof(a));
                f.close();
                break;
            case 3:
                f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
                f.seekg(0);
                while(f.read((char *) &a,sizeof(a)))
                {
                    a.displaydetail();
                }
                f.close();
                break;
            case 4:
                manage();
                break;
            case 5:
                displaypassdetail();
                break;
            }
        }while(ch<=5);

        f.close();
    }

}

void displaypassdetail()
{
    fstream f;
    reser b;
    f.open("p.txt",ios::in|ios::out|ios::binary);
    f.seekg(0);
    while(f.read((char *) & b,sizeof(b)))
    {
        b.displayresdet();
    }
    f.close();
    getch();
}

void manage()
{
    int ch;
    fstream f;
    char c;
    login a;
    cout<<".........WELCOME TO THE USER MANAGEMENT MENU........\n";
    do
    {
        cout<<"1.Create id data base\n2.Add details\n";
        cout<<"3.Display details\n4.Return to the main menu\n";
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            f.open("id.txt",ios::out|ios::binary);
            do
            {
                a.getid();
                f.write((char *) & a,sizeof(a));
                cout<<"Do you want to add one more record\n";
                cout<<"y-Yes\nn-No\n";
                cin>>c;
            }
            while(c=='y');
            f.close();
            break;
        case 2:
            f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
            a.getid();
            f.write((char *) & a,sizeof(a));
            f.close();
            break;
        case 3:
            f.open("id.txt",ios::in|ios::out|ios::binary);
            f.seekg(0);
            while(f.read((char *) & a,sizeof(a)))
            {
                a.displayid();
            }
            f.close();
            break;
        }
    }
    while(ch<=3);
    getch();
}

void user()
{
    login a;
    int ch;
    cout<<"*****************************************************\n";
    cout<<"***********WELCOME TO THE USER MENU**\n";
    cout<<"****************************************************\n";
    char password[100];

    fstream f;
    f.open("id.txt",ios::in|ios::out|ios::binary);
    char id[100];
    printf("Enter your id:");
    scanf("%s", &id);
    printf("Enter your password:");
    scanf("%s", &password);
    while(f.read((char *) & a,sizeof(a)))
    {
        if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
        {
            do
            {
                cout<<"1.Reserve\n2.Cancel\n3.Enquiry\n4.Return to the main menu\n";
                cout<<"Enter your choice:";
                cin>>ch;
                cout<<endl;
                switch(ch)
                {
                case 1:
                    res();
                    break;
                case 2:
                    cancel();
                    break;
                case 3:
                    enquiry();
                    break;
                }
            }
            while(ch<=3);
            return;
        }
        else
        {
            d=1;
        }
    }
    if(d==1)
    {
        cout<<"Enter your user id and password correctly\n";
    }

    getch();
    
}

void res()
{
    detail a;
    reser b;
    fstream f1,f2;
    time_t t;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);
    int ch, flag;
    b.getresdet();
    while(f1.read((char *) &a,sizeof(a)))
    {
        if(a.tno==b.tno)
        {
            if(strcmp(b.clas,f)==0)
            {
                if(a.c1>=b.nosr)

                {
                    amt=a.c1fare;
                    addr=f1.tellg();
                    ad=sizeof(a.c1);
                    f1.seekp(addr-(7*ad));
                    a.c1=a.c1-b.nosr;                 //Deducting from total number of seats
                    f1.write((char *) & a.c1,sizeof(a.c1));
                    b.amc=b.nosr*amt;                 // Calculating the price of the seats (Transaction management)
                    
                    srand((unsigned) time(&t));
                    b.pnr=rand();						//Generation of PNR for the tickets
                    f2.write((char *) & b,sizeof(b));
                    b.displayresdet();
                    cout<<"------------------------------------------------------\n";
                    cout<<"--------------Your ticket is reserved-----------\n";
                    cout<<"-----------------End of reservation menu-------\n";
                }
                else
                {
                    cout<<"**********Sorry requested seats not available********\n";

                }
            }
            else if(strcmp(b.clas,s)==0)
            {
                if(a.c2>=b.nosr)
                {
                    amt=a.c2fare;
                    addr=f1.tellg();
                    ad=sizeof(a.c2);
                    f1.seekp(addr-(5*ad));
                    a.c2=a.c2-b.nosr;							//Deduction
                    f1.write((char *) & a.c2,sizeof(a.c2));
                    b.amc=b.nosr*amt;							//Transaction
            
            		srand((unsigned) time(&t));
                    b.pnr=rand();								//PNR generation
                    f2.write((char *) & b,sizeof(b));
                    b.displayresdet();
                    cout<<"---------------------------------------\n";
                    cout<<"--------Your ticket is reserved--------\n";
                    cout<<"------------End of reservation---------\n";
                }
                else
                {
                    cout<<"********Sorry requested no of seats not available*******\n";
                }
            }
            getch();

            return;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        cout<<"............Wrong train no......................\n";
        cout<<"......Enter the train no from the data base.....\n";
    }
    f1.close();
    f2.close();
    getch();

}

void enquiry()
{

    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);
    detail a;
    while(f.read((char *) & a,sizeof(a)))
    {
        a.displaydetail();
    }
    getch();
}

void cancel()
{
    detail a;
    reser b;
    canc c;
    fstream f1,f2,f3;
    int flag;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary);
    cout<<"**********CANCELLATION MENU*********\n";
    c.getcancdet();
    while(f2.read((char *) &b,sizeof(b)))
    {
        if(b.pnr==c.pnr)
        {
            c.tno=b.tno;
            strcpy(c.tname,b.tname);
            strcpy(c.bp,b.bp);
            strcpy(c.dest,b.dest);
            c.nosc=b.nosr;
            for(int j=0; j<c.nosc; j++)
            {
                strcpy(c.pname[j],b.pname[j]);
                c.age[j]=b.age[j];
            }
            strcpy(c.clas,b.clas);
            if(strcmp(c.clas,f)==0)
            {
                while(f1.read((char *) &a,sizeof(a)))
                {
                    if(a.tno==c.tno)
                    {
                        a.c1=a.c1+c.nosc;
                        d=a.d;
                        m=a.m;
                        addr=f1.tellg();
                        ad=sizeof(a.c1);
                        f1.seekp(addr-(7*ad));
                        f1.write((char *) & a.c1,sizeof(a.c1));
                        tamt=b.amc;
                        if((c.d==d)&&(c.m==m))
                        {
                            cout<<"You are cancelling at the date of departure\n";
                            c.amr=tamt-((tamt*60)/100);
                        }
                        else if(c.m==m)
                        {
                            cout<<"You are cancelling at the month of departure\n";
                            c.amr=tamt-((tamt*50)/100);
                        }
                        else if(m>c.m)
                        {
                            cout<<"You are cancelling before the month of departure\n";
                            c.amr=tamt-((tamt*20)/100);
                        }
                        else
                        {
                            cout<<"Cancelling after the departure\n";
                            cout<<"Your request cannot be completed\n";
                        }
                        c.displaycancdet();
                        goto h;
                        
                    }
                }
            }
            else if(strcmp(c.clas,s)==0)
            {
                while(f1.read((char *) & a,sizeof(a)))
                {

                    if(a.tno==c.tno)
                    {
                        a.c2=a.c2+c.nosc;
                        d=a.d;
                        m=a.m;
                        addr=f1.tellg();
                        ad=sizeof(a.c2);
                        f1.seekp(addr-(5*ad));
                        f1.write((char *) & a.c2,sizeof(a.c2));
                        tamt=b.amc;
                        if((c.d==d)&&(c.m==m))
                        {
                            cout<<"You are cancelling at the date of departure\n";
                            c.amr=tamt-((tamt*60)/100);
                        }
                        else if(c.m==m)
                        {
                            cout<<"You are cancelling at the month of departure\n";
                            c.amr=tamt-((tamt*50)/100);
                        }
                        else if(m>c.m)
                        {
                            cout<<"You are cancelling before the month of departure\n";
                            c.amr=tamt-((tamt*20)/100);
                        }
                        else
                        {
                            cout<<"Cancelling after the departure\n";
                            cout<<"Your request cannot be completed\n";
                        }
                        c.displaycancdet();
                        goto h;
                    }
                }
            }
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        cout<<"Enter the correct pnr no\n";
    }
    h:
    f1.close();
    f2.close();
    f3.close();
    getch();
}



