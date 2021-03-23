#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<cstring>
#include<windows.h>
using namespace std;

//START OF CLASS



class hotel
{

int room_no;
char name[30];
char address[50];
char phone[10];

public:

void main_menu();
void add();
void display();
void rooms();
void edit();
int check(int);
void modify();
void delete_rec();
void bill();
     };



//FOR DISPLAYING MAIN MENU



void hotel::main_menu()
{

int choice;
while(choice!=5)
{

  system("cls");
cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t SIMPLE HOTEL MANAGEMENT ";
cout<<"\n\t\t\t\t      * MAIN MENU *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Customer Records";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Bill of Customer";
cout<<"\n\t\t\t6.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;

switch(choice)
{

case 1:	add();
break;

case 2: display();
break;

case 3: rooms();
break;

case 4:	edit();
break;

case 5: bill();
break;
case 6: exit(0);
default:
{

cout<<"\n\n\t\t\tWrong choice.....!!!";
Sleep(1000);
main_menu();

}

}

}

}




//FUNCTION FOR BOOKING OF ROOM


void hotel::add()
{

  system("cls");
int r,flag;
char choice[10];
ofstream fout("Record.dat",ios::app);

cout<<"\n Enter Customer Detalis";
cout<<"\n ----------------------";
cout<<"\n\n Room no: ";
cout<<"\n Total no. of Rooms - 100";
cout<<"\n Ordinary Rooms from 1 - 50";
cout<<"\n Deluxe Rooms from 51 - 85";
cout<<"\n Villa from 86 - 100";
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;

flag=check(r);

if(flag)
cout<<"\n Sorry..!!!Room is already booked";

else
{

room_no=r;
cout<<" Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone No: ";
cin>>phone;

fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is booked...!!!";

}

cout<<"\n Want to book another room(Y/N):";
cin>>choice;
if(strcmp(choice,"Y")==0)
  add();
else
  fout.close();

}




//DISPLAY A PURTICULAR CUSTOMER`S RECORD





void hotel::display()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
int r,flag=0;
char choice[10];
cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

  system("cls");
cout<<"\n Cusromer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;

}

}

if(flag==0)
  cout<<"\n Sorry Room no. not found or vacant....!!";

cout<<"\n\n Want to display data for other room(Y/N): ";
cin>>choice;
if(strcmp(choice,"Y")==0)
  display();
else
  fin.close();
}



//DISPLAY ALL ROOMS OCCUPIED


void hotel::rooms()
{

  system("cls");
int r;
ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";

fin.read((char*)this,sizeof(hotel));

while(!fin.eof())
{

cout<<"\n\n "<<room_no<<"\t\t"<<name<<"\t\t"<<address<<"\t\t"<<phone;
fin.read((char*)this,sizeof(hotel));

}

cout<<"\n\n Press 1 to go back";
cout<<"\n Press 0 to exit";
cin>>r;
if(r==1)
  main_menu();
else
  exit(0);
fin.close();

}


//FUNCTION FOR EDITING RECORDS AND FOR BILL


void hotel::edit()
{

  system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n 3.Go Back";
cout<<"\n Enter your choice: ";

cin>>choice;


switch(choice)
{

case 1:	modify();
break;

case 2:	delete_rec();
break;

case 3: main_menu();
break;

default: cout<<"\n Wrong Choice.....!!";

}
Sleep(1000);
edit();
}


int hotel::check(int r)
{

int flag=0;

ifstream fin("Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}


//FUNCTION TO MODIFY CUSTOMERS RECORD


void hotel::modify()
{
system("cls");
int r;
cout<<"\n Enter room no: " ;
cin>>r;
long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(hotel));

if(room_no==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}



//FUNCTION FOR DELETING RECORD


void hotel::delete_rec()
{
return;
}





//FUNCTION FOR CUSTOMER`S BILL

void hotel::bill()
{
  system("cls");
  int r;
  cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t SIMPLE HOTEL MANAGEMENT ";
cout<<"\n\t\t\t\t      * MAIN MENU *";
cout<<"\n\t\t\t\t*************************";
  cout<<"\n\n\n\t\t\t\tEnter the room no. :";
  cin>>r;

hotel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);

if(!f1)
 cout<<"cannot open";

 else
 {

  f1.read((char*)&h1,sizeof (hotel));
  while(f1)

  {

  f1.read((char*)&h1,sizeof(hotel));

  }

  if (h1.room_no == r)
  {

  if(h1.room_no>=1&&h1.room_no<=50)
  cout<<"\n\t\t\t\tyour bill = 5000";

  else if (h1.room_no>=51&&h1.room_no<=85)
  cout<<"\n\t\t\t\tyour bill = 7000" ;

  else
  cout<<"\n\t\t\t\tyour bill = 10000";

  }

  else
  { cout<<"\n\t\t\t\troom no. not found";
    Sleep(1000);
    bill();
  }
  int flag;
  cout<<"\n\n Press 1 to go back";
  cout<<"\n Press 0 to exit";
  cin>>flag;
  if(flag==1)
    main_menu();
  else
    exit(0);
  f1.close();

 }
}


//START OF MAIN PROGARM


int main()
{

hotel h;


h.main_menu();
return 0;
}

