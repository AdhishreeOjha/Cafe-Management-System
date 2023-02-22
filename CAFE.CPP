//All header files
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip.h>

void main();
void memeberfun();

//ALL Global variables
int count_member=0;
int count_staff=0;
int count_customer=0;

//Class member to store member details
class member
{
	private:
		char mname[20];
		int memid;
		char madd[30];
		unsigned long mph;
		char memail[30];

	public:
		void mgetdata();
		void mdisplay();
		void mmodify();
		int mgetid()
		{
			return memid;
		}
};

//Function to get member details
void member :: mgetdata()
{
	++count_member;
	cout<<"\n Enter member's name: ";
	gets(mname);
	cout<<"Enter member's member id: ";
	cin>>memid;
	cout<<"\n Enter member's address: ";
	gets(madd);
	cout<<"Enter member's phone no: ";
	cin>>mph;
	cout<<"\n Enter member's email id: ";
	gets(memail);
}
void write_member(member m)
{
	fstream fout("member.dat",ios::out|ios::in|ios::binary);
	if(!fout)
	cout<<"Error in opening file....";
	fout.seekp(((count_member-1)*sizeof(member),ios::beg));
	fout.write((char*)&m,sizeof(m));
	cout<<"\n Member is added to the cafe...congratulations";
	getch();
	fout.close();
}

//Function to display member details
void member::mdisplay()
{
	cout<<"\n Member's Name: "<<mname;
	cout<<"\n Member's Id: "<<memid;
	cout<<"\n Member's Address: "<<madd;
	cout<<"\n Member's Phone number: "<<mph;
	cout<<"\n Member's Email id: "<<memail;
}

void read_member()
{
	member m;
	fstream fin("member.dat",ios::in|ios::out|ios::binary);
	if(!fin)
	cout<<"Error in opening the file...";
	cout<<"\n All members in the cafe are \n\n";
	while(fin.read((char*)&m,sizeof(member)))
	m.mdisplay();
	getch();
	fin.close();
}

//Function to modify member details
void member::mmodify()
{
	char nm[20],add[20],mem[20];
	int id,ph;
	cout<<"\n Enter name :('.' to retain old data) ";
	gets(nm);
	cout<<"\n Enter id : ('-1' to retain old data) ";
	cin>>id;
	cout<<"\n Enter address : ('.' to retain old data) ";
	gets(add);
	cout<<"\n Enter phone no : ('-1' to retain old data) ";
	cin>>ph;
	cout<<"\n Enter email id : ('.' to retain old data)";
	gets(mem);

	if(strcmp(nm,".")!=0)
		strcpy(mname,nm);
	if(id!=-1)
		memid=id;
	if(strcmp(madd,".")!=0)
		strcpy(madd,add);
	if(mph!=-1)
		mph=ph;
	if(strcmp(mem,".")!=0)
		strcpy(memail,mem);
}

void modify_member()
{
	member m1;
	int no;
	int flag=0;
	fstream fin("member.dat",ios::in|ios::out|ios::binary);
	if(!fin)
	cout<<"Error in opening the file...";
	char ans;
	long pos;
	cout<<"Enter id which you want to modify: ";
	cin>>no;
	while(fin.read((char*)&m1,sizeof(member)))
	{
		pos=fin.tellg();
		if(no==m1.mgetid())
		{
			cout<<"\n Record found";
			m1.mdisplay();
			flag=1;
			cout<<"\n Modify this record?";
			cin>>ans;

			if(ans=='Y' || ans=='y')
			{
				cout<<"\n\n Enter new details\n";
				m1.mmodify();
				fin.seekp((pos-sizeof(member)),ios::beg);
				fin.write((char*)&m1,sizeof(member));
				cout<<"\n Record is modified";
			}
		getch();
		break;
		}
	}
	if(flag==0)
	{
		cout<<"\n Member does not exist ";
	}
	fin.close();
}

//Function to search a member(by name)
void search_member()
{
	member m1;
	int flag=0,no;
	fstream fin("member.dat",ios::in|ios::out|ios::binary);
	if(!fin)
	cout<<"Error opening the file...";
	cout<<"Enter member id which you want to search: ";
	cin>>no;
	while(fin.read((char*)&m1,sizeof(member)))
	{
		if(no==m1.mgetid())
		{
			cout<<"\n Record is found";
			m1.mdisplay();
			flag=1;
			break;
		}
	}
	if(flag==0)
	cout<<"member doesn't exist";
	getch();
	fin.close();
}

//Function to delete a member's record
void del_member()
{
	member m1;
	int no;
	int flag=0;
	fstream fin("member.dat",ios::in|ios::out|ios::binary);
	if(!fin)
	cout<<"Error in opening file...";
	cout<<"\n Enter member id to be deleted: ";
	cin>>no;

	fstream fout("temp.dat",ios::in|ios::out|ios::binary);
	while(fin.read((char*)&m1,sizeof(member)))
	{
		if(no!=m1.mgetid())
			fout.write((char*)&m1,sizeof(member));
		else
		{
			cout<<"\n Record found";
			m1.mdisplay();
			flag=1;
		}
	}
	fin.close();
	fout.close();
	if(flag==0)
	{
		cout<<"\n Member doesn't exist";
		getch();
	}
	else
	{
		cout<<"Record successfully deleted";
		getch();
	}
	remove("member.dat");
	rename("temp.dat","member.dat");
}

//Class staff to store all staff details
class staff
{
	private:
		char sname[20];
		int sid;
		char sduty[20];
		char sdesig[20];
		long scont;
       public:
		void sget();
		void sdisplay();
		void smodify();
		int sgetid()
		{
			return sid;
		}
};

//Function to get staff details
void staff :: sget()
{
	++count_staff;
	cout<<"Enter Staff's name";
	gets(sname);
	cout<<"Enter staff's id";
	cin>>sid;
	cout<<"Enter staff's duty";
	gets(sduty);
	cout<<"Enter staff's designation";
	gets(sdesig);
	cout<<"Enter staff's contact number";
	cin>>scont;
}
void write_staff(staff s)
{
	fstream fout("staff.dat",ios::in|ios::out|ios::binary);
	if(!fout)
	cout<<"Error in opening file";
	fout.seekp(((count_staff-1)*sizeof(staff)),ios::beg);
	fout.write((char*)&s,sizeof(s));
	cout<<"\n Staff is added to cafe";
	getch();
	fout.close();
}

//Function to display staff details
void staff::sdisplay()
{
	cout<<"Staff's name: "<<sname;
	cout<<"Staff's id: "<<sid;
	cout<<"Staff's duty: "<<sduty;
	cout<<"Staff's designation: "<<sdesig;
	cout<<"Staff's contact no: "<<scont;
}

void read_staff(void)
{
	staff s;
	fstream fout("staff.dat",ios::in|ios::out|ios::binary);
	if(!fout)
		cout<<"Error in reading file...";
	cout<<"\n All staff present in cafe are:\n\n";
	while(fout.read((char*)&s,sizeof(staff)))
		s.sdisplay();
	getch();
	fout.close();
}

//Function to modify staff details
void staff :: smodify()
{
	char nm[20],duty[20],desig[20];
	int ph,id;
	cout<<"\n Enter name :('.' to retain old data)";
	gets(nm);
	cout<<"\n Enter id :('-1' to retain old data)";
	cin>>id;
	cout<<"\n Enter duty of staff :('.' to retain old data)";
	gets(duty);
	cout<<"\n Enter designation of staff :('.' to retain old data)";
	gets(desig);
	cout<<"\n Enter contact no :('-1' to retain old data)";
	cin>>ph;

	if(strcmp(nm,".")!=0)
		strcpy(sname,nm);
	if(id!=-1)
		sid=id;
	if(strcmp(duty,".")!=0)
		strcpy(sduty,duty);
	if(strcmp(desig,".")!=0)
		strcpy(sdesig,desig);
	if(ph!=-1)
		scont=ph;
}
void modify_staff()
{
	staff s1;
	int no;
	int flag=0;
	fstream fin("staff.dat",ios::in|ios::out|ios::binary);
	if(!fin)
		cout<<"Error in opening file....";
	char ans;
	long pos;
	cout<<"Enter id which you want to modify: ";
	cin>>no;
	while(fin.read((char*)&s1,sizeof(staff)))
	{
		pos=fin.tellg();
		if(no==s1.sgetid())
		{
			cout<<"\n Record found";
			s1.sdisplay();
			flag=1;
			cout<<"\n\n Modify this record?";
			cin>>ans;

			if(ans=='Y' || ans=='y')
			{
				cout<<"\n\n Enter new details: \n";
				s1.smodify();
				fin.seekp((pos-sizeof(staff)),ios::beg);
				fin.write((char*)&s1,sizeof(staff));
				cout<<"\n Record is modified";
			}
			getch();
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\n Staff doesn't exist";
		getch();
	}
	fin.close();
}

//Function to search a staff's record
void search_staff()
{
	staff s1;
	int flag=0,no;
	fstream fin("staff.dat",ios::in|ios::out|ios::binary);
	if(!fin)
		cout<<"Error in opening file.....";
	cout<<"Enter staff id which you want to search: ";
	cin>>no;
	while(fin.read((char*)&s1,sizeof(staff)))
	{
		if(no==s1.sgetid())
		{
			cout<<"Record is found";
			s1.sdisplay();
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\nStaff does not exist";
	getch();
	fin.close();
}

//Function to delete a staff's record
void del_staff()
{
	staff s1;
	int no;
	int flag=0;
	fstream fin("staff.dat",ios::in|ios::out|ios::binary);
	if(!fin)
		cout<<"Error in opening file.....";
	cout<<"Enter staff id to be deleted: ";
	cin>>no;

	fstream fout("temp.dat",ios::in|ios::out|ios::binary);
	while(fin.read((char*)&s1,sizeof(staff)))
	{
		if(no!=s1.sgetid())
			fout.write((char*)&s1,sizeof(staff));
		else
		{
			cout<<"\n Record found";
			s1.sdisplay();
			flag=1;
		}
	}
	fin.close();
	fout.close();
	if(flag==0)
	{
		cout<<"\nStaff doesnot exist";
		getch();
	}
	else
	{
		cout<<"\n Record deleted successfully";
		getch();
	}
	remove("staff.dat");
	rename("temp1.dat","staff.dat");
}

//Class customer to store customer details
class customer
{
	private:
		char cname[20];
		char order[5][30];
		int tableno;
		int count;

	public:
		void cget();
		void cdisplay();
		void cmodify();
		void menu();
		void bill();
		int gettable()
		{
			return tableno;
		}
};


//FUNCTION TO DISPLAY MENU
void customer:: menu()
{
		cout<<"**************************************************************************";
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n			         MENU			                       ";
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n**************************************************************************";
		cout<<"\n**                                \t\t\t\t\t**";
		cout<<"\n**\t \t SANDWICHES           \t   RATES \t\t\t**";
		cout<<"\n**                                \t\t\t\t\t**";
		cout<<"\n**\t Aloo sandwich           \t    40\t\t\t\t**";
		cout<<"\n**\t Cheese sandwich         \t    70\t\t\t\t**";
		cout<<"\n**\t Vege sandwich           \t    80\t\t\t\t**";
		cout<<"\n**\t Mozerella sandwich      \t    90\t\t\t\t**";
		cout<<"\n**\t Onion capsicum sandwich \t    100\t\t\t\t**";
		cout<<"\n**\t Three layer sandwich    \t    110\t\t\t\t**";
		cout<<"\n**\t Special sandwich        \t    150\t\t\t\t**";
		cout<<"\n**                                \t\t\t\t\t**";
		cout<<"\n**\t \t PIZZAS               \t   RATES\t\t\t**";
		cout<<"\n**\t \t                 \tsmall\t medium\t large\t\t** ";
		cout<<"\n**\t Margherita pizza   \t\t 110\t 170\t 210  \t\t** ";
		cout<<"\n**\t Onion capsicum pizza\t\t 130\t 190\t 250  \t\t** ";
		cout<<"\n**\t Double cheese pizza \t\t 90\t 120\t 160  \t\t** ";
		cout<<"\n**\t Graden pizza        \t\t 100 \t 130\t 160  \t\t** ";
		cout<<"\n**\t Special pizza       \t\t 150 \t 195\t 230  \t\t** ";
		cout<<"\n**                                \t\t\t\t\t**";
		cout<<"\n**\t     ENTER ANY KEY TO CONTINUE     \t\t\t\t**";

		getch();
		cout<<"\n**                                \t\t\t\t\t**";
		cout<<"\n**\t \t DESI TADKA            \t  RATES\t\t\t\t**";
		cout<<"\n**                                \t\t\t\t\t**";
		cout<<"\n**\t Samosa                   \t   50  \t\t\t\t**";
		cout<<"\n**\t Dahi papdi chat          \t   70  \t\t\t\t**";
		cout<<"\n**\t Kachore                  \t   30  \t\t\t\t**";
		cout<<"\n**\t Sev puri                 \t   75  \t\t\t\t**";
		cout<<"\n**                                \t\t\t\t\t**";
		cout<<"\n**\t \t BEVERAGES             \t  RATES\t\t\t\t**";
		cout<<"\n**                                \t\t\t\t\t**";
		cout<<"\n**\t Lemonde                  \t   80  \t\t\t\t**";
		cout<<"\n**\t Coke float               \t   85  \t\t\t\t**";
		cout<<"\n**\t cafe Coffee              \t   90  \t\t\t\t**";
		cout<<"\n**\t Blue berry               \t   100 \t\t\t\t**";
		cout<<"\n**\t Black current            \t   110 \t\t\t\t**";
		cout<<"\n**\t Vanut coffee             \t   130 \t\t\t\t**";

}

//FUNCTION TO GET CUSTOMER DETAILS
void customer::cget()
{
	++count_customer;
	char ch;
	cout<<"\n ENTER TABLE NO :";
	cin>>tableno;
	cout<<"\n ENTER CUSTOMER'S NAME :";
	gets(cname);
	int i=0;
	do
	{
		cout<<"\n ENTER CUSTOMER'S ORDER :";
		gets(order[i]);
		i++;
		cout<<"\n \t DO YOU WANT TO ORDER MORE :";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	count=i-1;

}
void write_customer(customer c)
{
	fstream f("customer.dat",ios::out|ios::in|ios::binary);
	if(!f)
		cout<<"Error in opening file...";

	f.seekp(((count_customer-1)*sizeof(customer)),ios::beg);
	f.write((char*)&c,sizeof(c));
	cout<<"\n Customer details is added to the cafe....";
	getch();
	f.close();
}

//FUNCTION TO DISPLAY CUSTOMER DETAILS
void customer :: cdisplay()
{
	cout<<"\n CUSTOMER'S NAME :"<<cname;
	for(int i=0;i<count;i++)
	cout<<"\n CUSTOMER'S ORDER :"<<order[i];
	cout<<"\n CUSTOMER'S TABLE NO :"<<tableno;
}
void read_customer(void)
{
	 customer c;
	fstream f("customer.dat",ios::in|ios::out|ios::binary);
	if(!f)
		cout<<"Error in opening the file....";
	cout<<"\nAll customer in the cafe are\n\n";
	while(f.read((char*)&c,sizeof(customer)))
		c.cdisplay();
	getch();
	f.close();
}

//FUNCTION TO MODIFY CUSTOMER DETAILS
void customer :: cmodify()
{
	int ctableno;
	char nm[20], corder[5][30];
	cout<<"\n Enter customer's name:('.' to retain old data) ";
	gets(nm);
	cout<<"\n Enter the table number:('-1' to retain old data) ";
	cin>>ctableno;
	cout<<"\n Enter the order changed:('.' to retain old data) ";
	for(int i=0;i<count;i++)
	gets(corder[i]);

	if(strcmp(nm,".")!=0)
		strcpy(cname,nm);
	if(ctableno!=-1)
		tableno=ctableno;
	for(i=0;i<count;i++)
	{
		if(strcmp(corder[i],".")!=0)
		strcpy(order[i],corder[i]);
	}
}
void modify_customer()
{
	customer c1;
	int no;
	int flag=0;
	fstream f("customer.dat",ios::in|ios::out|ios::binary);
	if(!f)
		cout<<"Error in opening the file....";
	char ans;
	long pos;
	cout<<"\n Enter table no which u want to modify : ";
	cin>>no;
	while(f.read((char*)&c1,sizeof(customer)))
	{
		pos=f.tellg();
		if(no==c1.gettable())
		{
			cout<<"\nRecord found";
			c1.cdisplay();
			flag=1;
			cout<<"\n\nModify this record ?";
			cin>>ans;

			if(ans=='Y'||ans=='y')
			{
				cout<<"\n\nEnter new details\n";
				c1.cmodify();
				f.seekp((pos-sizeof(customer)),ios::beg);
				f.write((char*)&c1,sizeof(customer));
				cout<<"\nRecord is modified";
			}
		getch();
		break;
		}
	}
	if(flag==0)
	{
		cout<<"\n Customer does not exist ";
		getch();
	}
	f.close();
}

//FUNCTION TO PRINT THE BILL
void customer :: bill()
{
	cout<<"\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
	cout<<"\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
	cout<<"\n\t\t  ~~            AMIGOS              ~~";
	cout<<"\n\t\t   ~~     LAKE CITY ROAD,UPAIPUR     ~~";
	cout<<"\n\t\t    ~~                                ~~";
	cout<<"\n\t\t     ~~             BILL               ~~";
	cout<<"\n\t\t      ~~ *****************************  ~~";
	cout<<"\n\t\t       ~~ ";
}

void astaff()
{
	staff s;
	int ch,choice1;
	start:
	clrscr();
	do
	{
	cout<<"\n STAFF MENU:";
	cout<<"\n 1.Enter staff details";
	cout<<"\n 2.View staff details";
	cout<<"\n 3.Modify a staff's details";
	cout<<"\n 4.Search a staff";
	cout<<"\n 5.Delete a staff's record";
	cout<<"\n 6.Exit";
	cout<<"\n Enter your choice: ";
	cin>>ch;
	switch(ch)
	{
	case 1:	clrscr();
		s.sget();
		write_staff(s);
		break;

	case 2:	clrscr();
		read_staff();
		break;

	case 3: clrscr();
		modify_staff();
		break;

	case 4:	clrscr();
		search_staff();
		break;

	case 5: clrscr();
		del_staff();
		break;

	case 6: clrscr();
		goto start;
}
		cout<<"\n do you want to go back to the staff menu :";
		cin>>ch;
		}while(ch=='y'||ch=='Y');

}

void memberfun()
{
	int choice1,ch;
	start:
	clrscr();
	do
	{
		clrscr();
		cout<<"\n MEMBER MENU ";
		cout<<"\n 1.Enter the details of a new member";
		cout<<"\n 2.View member details";
		cout<<"\n 3.Modify a member's detils";
		cout<<"\n 4.Search a member(by name)";
		cout<<"\n 5.Delete a member's details";
		cout<<"\n 6.Exit";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1: clrscr();
			member m;
			m.mgetdata();
			write_member(m);
			break;

		case 2: clrscr();
			read_member();
			break;

		case 3: clrscr();
			modify_member();
			break;

		case 4: clrscr();
			search_member();
			break;

		case 5: clrscr();
			del_member();
			break;

		case 6: clrscr();
			goto start;
		}
		cout<<"\n do you want to go back to the member menu :";
		cin>>choice1;
		}while(choice1=='y'||choice1=='Y');

}

void admin()
{
	int choice;
	do
	{
	clrscr();
	cout<<"WElcome to Admin Page"<<endl;
	cout<<"\n 1.Staff details :";
	cout<<"\n 2.Member details :";
	cout<<"\n 3.EXIT....";
	cout<<"\n Enter your choice:";
	cin>>choice;
	switch(choice)
	{
		case 1: astaff();
			break;
		case 2: memeberfun();
			break;
		case 3: exit(0);
			break;
		default: cout<<"Wrong choice: ";
		}
	}while(choice!=2);
}

void customerad()
{
	clrscr();
	int ch,choice1;
	customer c;
	start:
	do
	{  clrscr();
		cout<<"\n CUSTOMER MENU";
		cout<<"\n 1. View menu";
		cout<<"\n 2. Enter customer details";
		cout<<"\n 3. Display customer details";
		cout<<"\n 4. Print bill";
		cout<<"\n 5. Modify customer details";
		cout<<"\n 6. Exit";
		cout<<"\n Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:	clrscr();
			c.menu();
			break;

			case 2:	clrscr();
				cout<<"Enter customer details\n";
				c.cget();
				write_customer(c);
				break;

						case 3:
							clrscr();
							read_customer();

						case 4:
							clrscr();
							c.bill();
							break;

						case 5:
							clrscr();
							modify_customer();
							break;

						case 6: clrscr();
							goto start;
					}

					cout<<"\n Do you want to go back to customer menu (y/n) : ";
					cin>>choice1;
				}while(choice1=='y'||choice1=='Y');

}

//Login for Admin
void login(int z)
{
	clrscr();
	int i,j;
	char passw[20],ch;
	for(j=0;j<3;j++)
	{
		cout<<"Enter password...\n";
		i=0;
		while((ch=getch())!=13)
		{
			passw[i]=ch;
			i++;
			cout<<"*";
		}
		passw[i]='\0';
		if(strcmp(passw,"adis")==0)
		{
			admin();
			break;
		}
		else
		{       z++;
			cout<<"Incorrect Password...."<<endl;
			cout<<"Please Try Again...\n";
		}
	}
	getch();
}

//Login for User
void loginuser(int az)
{
	clrscr();
	int i,j;
	char passw[20],ch;
	for(j=0;j<3;j++)
	{
	     ab:cout<<"Enter password...\n";
		i=0;
		while((ch=getch())!=13)
		{
			passw[i]=ch;
			i++;
			cout<<"*";
		}
		passw[i]='\0';
		if(strcmp(passw,"user")==0)
		{
			customerad();
			break;
		}
		else
		{       az++;
			cout<<"Incorrect Password...."<<endl;
			cout<<"Please Try Again...\n";
			goto ab;
		}
	}
	getch();
}


//MAIN FUNCTION
void main()
{
	textcolor(RED);
	clrscr();
	int choice,ch,aj,z,az;
	char choice1;
	char answer;
	do
	{
		clrscr();
		customer c;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n********************************************************************************";
		cout<<"\n********************************************************************************";
		cout<<"\n \t\t\tWELCOME TO AMIGOS";
		cout<<"\n \t\t\tA PLACE FOR A PERFECT HANGOUT!!!!!";
		cout<<"\n \t\t\tLAKE CITY ROAD, UDAIPUR";
		cout<<"\n********************************************************************************";
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n1.Admin"<<endl;
		cout<<"2.Customer"<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>aj;
		switch(aj)
		{

			case 1: login(z);
				break;
			case 2: loginuser(az);
				break;
			case 3: exit(0);
				break;
			default: cout<<"Wrong choice try again!";
			}
		}while(aj!=3);
		getch();
}
