/*				    PROJECT:-

				 ONLINE RESUME

                 */


#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
char mn[12][30]={"January","February",
		 "March","April",
		 "May","June",
		 "July","August",
		 "September","October",
		 "November","December"};
void menu();
struct DT{
int d,m,y;};

class person{
			int ID;
        		char name[40];
		char qualif[40];
		int exper;
		DT dob;
		char dob_c[30];
		char field[40];
		char add[60];
	 public:
		void getd();
		void putd();
		void layout();
		int ret_ID()
		{ return ID;}
                char *ret_name()
                {return name;}
		    };

void person::getd()
{
 cout<<"Enter your ID to be displayed: ";
 cin>>ID;
 cout<<"\nEnter your Name to be displayed: ";
 gets(name);
 cout<<"\nEnter your Date Of Birth: (dd/mm/yy): ";
 cin>>dob.d>>dob.m>>dob.y;
 sprintf(dob_c,"%s , %d %d",mn[dob.m-1],dob.d,dob.y);
 cout<<"\nEnter your address: ";
 gets(add);
 cout<<"\nField you're interested in: ";
 gets(field);
 cout<<"\nDuration of experience you have in "<<field<<": ";
 cin>>exper;
 cout<<"\nEnter your Qualifications: ";
 gets(qualif);

}

void person::putd()
{
 cout<<"\n\nID: "<<ID;
 cout<<"\nName: "<<name;
 cout<<"\nDate of Birth: "<<dob_c;
 cout<<"\nAddress: "<<add;
 cout<<"\nInterested field: "<<field;
 cout<<"\nExperience: "<<exper;
 cout<<"\nQualification: "<<qualif;
}

void add_r()// To add a new record
{
 fstream f;
 f.open("z:web.dat",ios::out|ios::app|ios::binary);
 person s;
 if(!f){cout<<"error in opening file ";getch();return;}
 char resp='y';
 do   {
    s.getd();
    f.write((char*)&s,sizeof(s));
    cout<<"\nWant to exit (y/n)";
    cin>>resp;
    }while(resp!='y');
 f.close();
 clrscr();
menu();
  }

void del_r()// To delete the existing record
{
   fstream f("z:web.dat",ios::binary|ios::in);
   fstream f1("z:temp.dat",ios::binary|ios::out);
   person s;
   int r;
   cout<<"Enter r"; cin>>r;
   while(f.read((char*)&s,sizeof(s)))
    {
     if(s.ret_ID()!=r)
      f1.write((char*)&s,sizeof(s));
    }
     f.close();
     f1.close();
     remove("z:web.dat");
     rename("z:temp.dat","z:web.dat");
}

void view_all()// To display all records
{
  ifstream f("z:web.dat",ios::binary);
  person s;
  int flag=0;
   if(!f){cout<<"No record found ";getch();return;}
  while(f.read((char*)&s,sizeof(person)))
   {
      s.putd();getch();
   }
    f.close();
   if(flag==0)
   cout<<"\nUnsuccessful";
}
void search_ID()// To search records through ID
{
  ifstream f("z:web.dat",ios::binary);
  person s;
  int r, flag=0;
  cout<<"Enter ID: ";
  cin>>r;
   if(!f){cout<<"error in opening file ";getch();return;}
  while(f.read((char*)&s,sizeof(person)))
   {
    if(s.ret_ID()==r)
     {
      flag=1;
      s.putd();getch();
     break;
     }
   }
    f.close();
   if(flag==0)
   cout<<"\nUnsuccessful";
}

void search_nm()
{
  ifstream f("z:web.dat",ios::binary);
  person s;
  int flag=0;
  char u[40];
  cout<<"Enter Name: ";
 gets(u);
  while(f.read((char*)&s,sizeof(s)))
   {
    if(strcmpi(s.ret_name(),u)==0)
     {
      flag=1;
      s.putd();getch();
      break;
     }
   }
    f.close();
   if(flag==0)
   cout<<"\nUnsuccessful";
}

void disp_r()
{
 ifstream f("z:web.dat",ios::binary);
 person s;
 while(f.read((char*)&s,sizeof(s)))
  {
  s.putd();
  }
 f.close();
}

void search_r()
{
 ifstream f1("z:web.dat",ios::binary);
 person s;
 int r, flag=0;
 cout<<"\nEnter your ID: ";
 cin>>r;
 while(f1.read((char*)&s,sizeof(s)))
  {
   if(s.ret_ID()==r)
    {
     flag=1;
      s.putd();
	 break;
    }
  }
  f1.close();

  if(flag==0)
  cout<<"Unsuccessful";
}

void person::layout()
{
    char bgcolor[40];
    char fcolor[40];
    char fname[40];
    int fsize;
cout<<"Enter page Specfications \n\n";
cout<<"Enter Background Color: ";
cin>>bgcolor;
cout<<"\nEnter Font Color: ";
cin>>fcolor;
cout<<"\nEnter Font Name: ";
cin>>fname;
cout<<"\nEnter Font Size: ";
cin>>fsize;
ofstream fout("z:\\ashu.htm");
fout<<"<html> <head><title>"<<name<<"'s Page</title></head>\n";
fout<<"<body bgcolor= \""<<bgcolor<<"\" text=\""<<fcolor<<"\">";
fout<<"<font face =\""<<fname<<"\"size =\""<<fsize<<"\" >";
fout<<"<center>"<<name<<" </center>";
fout<<"<center>"<<add<<"</center>";
fout<<"PERSONAL DETAILS"<<"<hr>";
fout<<"Id : "<<ID;
fout<<"<br>D.o.b : "<<dob_c;
fout<<"<br><br>INTEREST"<<"<hr>"<<field;
fout<<"<br><br>EXPERIENCE"<<"<hr>"<<exper;
fout<<"<br><br>QUALIFICATION"<<"<hr>"<<qualif;
fout<<"</body></html>";
fout.close();
}
void create_p()
{       clrscr();
 ifstream f1("z:web.dat",ios::binary);
 person s;
 int r, flag=0;
 cout<<"\nEnter ID of whose resume is to be made: ";
 cin>>r;
 while(f1.read((char*)&s,sizeof(s)))
  {
   if(s.ret_ID()==r)
       {
     flag=1;
      s.layout();
	 break;
    }
  }
  f1.close();

  if(flag==0)
  cout<<"Unsuccessful";
}

void out()
{
	textmode(BW80);
	int i;
	clrscr();
       //	gotoxy(15,10);
	for (i=0; i<9; i++)
	{
	 textattr(i + ((i+1) << 4));
	 cout<<"\n";

	 cprintf("THIS IS THE END BYE!BYE!\r\n");
	}
	getch();
	clrscr();
	textmode(C40);
	for(i=0;i<71;i++)
	{
	textcolor(BLUE);
	delay(10);
	cprintf("A");
	textcolor(RED);
	delay(10);
	cprintf("S");
	textcolor(GREEN);
	delay(10);
	cprintf("H");
	textcolor(YELLOW);
	delay(10);
	cprintf("U");
	textcolor(MAGENTA);
	delay(10);
	cprintf("S");
	textcolor(CYAN);
	textcolor(LIGHTRED);
	delay(10);
	cprintf("I");
	textcolor(LIGHTBLUE);
	delay(10);
	cprintf("N");
	textcolor(LIGHTGRAY);
	delay(10);
	cprintf("G");
	textcolor(LIGHTMAGENTA);
	delay(10);
	cprintf("H");
	textcolor(LIGHTCYAN);
	delay(10);
	cprintf("A");
	textcolor(LIGHTGREEN);
	delay(10);
	cprintf("L");
	cout<<"  ";
	}

	gotoxy(10,12);
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("D");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("O");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("N");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("T");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf(" ");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("M");
	textcolor(WHITE+BLINK);
	textcolor(WHITE+BLINK);
	cprintf("A");
	delay(40);
	cprintf("K");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("E");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf(" ");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("I");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("L");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("L");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("E");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("G");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("A");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("L");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf(" ");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("C");
	textcolor(WHITE+BLINK);
	cprintf("O");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("P");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("I");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("E");
	textcolor(WHITE+BLINK);
	delay(40);
	cprintf("S");
	getch();
	exit(0);
}

void FM()
{
  int k;
  do{
  gotoxy(15,5);

  cout<<"лллллллллллллллллллллллллллллллллллллллллллллл";

  gotoxy(15,6);
  cout<<"лл            File Maintenance              лл";

  gotoxy(15,7);
  cout<<"лл                                          лл";

  gotoxy(15,8);
  cout<<"лл   1. Add Record                          лл";

  gotoxy(15,9);
  cout<<"лл   2. Modify Record                       лл";

  gotoxy(15,10);
  cout<<"лл   3. Delete Record                       лл";

  gotoxy(15,11);
  cout<<"лл   4. Back                                лл";

  gotoxy(15,12);
  cout<<"лл   0. Exit                                лл";

  gotoxy(15,13);
  cout<<"лл                                          лл";

  gotoxy(15,14);
  cout<<"лллллллллллллллллллллллллллллллллллллллллллллл";

  gotoxy(15,17);
   cout<<"Enter your choice: ";
  cin>>k;

  clrscr();

     switch(k)
      {
       case 1:    add_r(); cout<<"back";getch();
		    break;

       case 2:    del_r();
		    break;

       case 3:     menu();
                    break;
       case 0:     exit(0);

      }
      }while(k!=0);

}

void search()
{
  int n;
  do{
  clrscr();
  gotoxy(15,5);

  cout<<"лллллллллллллллллллллллллллллллллллллллллллллл";

  gotoxy(15,6);
  cout<<"лл                  Search                  лл";

  gotoxy(15,7);
  cout<<"лл                                          лл";

  gotoxy(15,8);
  cout<<"лл   1. Search BY ID                        лл";

  gotoxy(15,9);
  cout<<"лл   2. Search By Name                      лл";

  gotoxy(15,10);
  cout<<"лл   3. Back to Main Menu                   лл";

  gotoxy(15,11);
  cout<<"лл   0. Exit to system                      лл";

  gotoxy(15,12);
  cout<<"лл                                          лл";

  gotoxy(15,13);
  cout<<"лллллллллллллллллллллллллллллллллллллллллллллл";

  gotoxy(15,15);
   cout<<"Enter your choice: ";
  cin>>n;

  clrscr();

     switch(n)
      {
       case 1:search_ID();
		    break;

       case 2:search_nm();           ;
		    break;

       case 3:     menu();
                    break;
       case 0:     exit(0);

      }
      }while(n!=0);

}

void menu()
{
  int p;
do{
  clrscr();
  gotoxy(15,5);

  cout<<"лллллллллллллллллллллллллллллллллллллллллллллл";

  gotoxy(15,6);
  cout<<"лл  Create your Online Resume if data exist,лл";

  gotoxy(15,7);
  cout<<"лл          else Enter data first           лл";

  gotoxy(15,8);
  cout<<"лл                                          лл";

  gotoxy(15,9);
  cout<<"лл   1. File Maintenance                    лл";

  gotoxy(15,10);
  cout<<"лл   2. Search Records                      лл";

  gotoxy(15,11);
  cout<<"лл   3. Create Online Resume                лл";

  gotoxy(15,12);
  cout<<"лл   4. View all Records                    лл";

    gotoxy(15,13);
  cout<<"лл   0. Exit                                лл";

  gotoxy(15,14);
  cout<<"лл                                          лл";

  gotoxy(15,15);
  cout<<"лллллллллллллллллллллллллллллллллллллллллллллл";

  gotoxy(15,17);
  cout<<"Enter your choice: ";
  cin>>p;

  clrscr();

     switch(p)
      {
       case 1:       FM();
		    break;

       case 2:   search();
		    break;

       case 3: create_p();
		    break;

       case 4: view_all();
		    break;

       case 0:      out();
       default:   gotoxy(15,21); cout<<"Invalid Choice"; getch();

      }
     }while(p!=0);

}

void main()
{
 textbackground(YELLOW);
  textbackground(BLACK);
  textmode(BW80);
  clrscr();
  _setcursortype(_NOCURSOR);
  char str[]="PROJECT ****BY**** ASHU SINGHAL";
  gotoxy((80-strlen(str))/2,10);
  int x;
  delay(100);
  for(int i=0; i<strlen(str); i++)
  {
    x=wherex();
    textcolor(DARKGRAY);
    cprintf("%c",str[i]);
    delay(50);
    gotoxy(x,10);
    textcolor(LIGHTGRAY);
    cprintf("%c",str[i]);
    delay(50);
    gotoxy(x,10);
    textcolor(WHITE);
    cprintf("%c",str[i]);
    delay(50);
  }
  gotoxy((80-strlen(str))/2,11);
  for(i=0; i<strlen(str); i++)
    cout<<"Э";
  gotoxy(25,15);
  textcolor(BLACK);
  for(i=0; i<30; i++)
    cprintf("л");
  gotoxy(35,18);
  textcolor(15+128);
  cprintf("Loading...");
  gotoxy(25,15);
  textcolor(WHITE);
  for(i=0; i<30; i++)
  {
     delay(5*(30-i));
     cprintf("л");
  }
 // textcolor(15+128); gotoxy(1,13);clreol();

  textcolor(WHITE);
  gotoxy((80-strlen(str))/2,18);
  strcpy(str,"[ Press any key to continue ]");
  cprintf("%s",str);
  getch();
  _setcursortype(_SOLIDCURSOR);
  textcolor(15);
clrscr();
menu();
getch();
}