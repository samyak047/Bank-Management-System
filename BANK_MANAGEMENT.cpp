#include<bits/stdc++.h>
using namespace std;
void clrscr();
int wait();

class account
{
	int acno;
	char name[50];
	float deposit;
	char type;
public:
	void password();
	void create_account();	//function to get data from user
	void show_account();	//function to show data on screen
	void modify();   //function to get new data from user
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report();	//function to show data in tabular format
	void check_acno();   //function to check the availity of acc. no present or not
	void check_type();   //function to check the type of account
	void check_deposit();  //functionn to check proper deposit
	void check_name();      //function to check proper name
	int retacno();	//function to return account number
	int retdeposit();	//function to return balance amount
	char rettype();	//function to return type of account
};         //class ends here
void account::password()
{ clrscr();
  cout<<"Enter The Password ";
  string pw;
  cin>>pw;
  if(pw=="abc")
  { return; }
  else
  {
  long i;
  cout<<"\n\n\n Wrong Password ......exiting";
  for(i=0;i<99999999;i++){}
  exit(0);
    }
}
void account::create_account()
{
	cout<<"\nEnter The Account Number :";
	cin>>acno;
	check_acno();
	cout<<"\n\nEnter The Name of The Account Holder : ";
	gets(name);
	check_name();
	cout<<"\n\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	check_type();
	cout<<"\n\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	check_deposit();
	cout<<"\n\n\a\a\aAccount Created...";
}

void account::show_account()
{
	cout<<"\nAccount Number : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\nThe Account Number:"<<acno;
	cout<<"\nEnter The Name of The Account Holder : ";
	gets(name);
	check_name();
	cout<<"\nEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	check_type();
	cout<<"\nEnter The Amount : ";
	cin>>deposit;
	check_deposit();
}


void account::check_acno()
{
	account ac;
	int flag=0;
	if(isupper(acno)||islower(acno))
	{
	cout<<"\n Account no. must be a numerical value";
	cout<<"\n Enter acc. no.:";
	cin>>acno;
	}
	ifstream inFile;
	inFile.open("account.dat",ios::binary|ios::app);
	inFile.read((char*)& ac,sizeof(ac));
	while(!inFile.eof()&&flag==0)
	{
	  if(ac.retacno()==acno)
	      flag ++;
	  inFile.read((char*)& ac,sizeof(ac));
	}
	inFile.close();
	if(flag!=0)
	  {
		cout<<"\n\n SORRY!!!....THIS ACC. NO. IS ALREADY PRESENT";
		cout<<"\n\n PLEASE TRY ANOTHER ONE :";
		cin>>acno;
		check_acno();
	  }
}


void account::check_type()
{
	while (type!='C'&&type!='S')

	  {
		cout<<"\n\n SORRY!!!....THIS IS NOT ANY ACCOUNT TYPE";
		cout<<"\n\n PLEASE SELECT EITHER 'C' OR 'S'(C:Current and S:Savings)" ;
		cin>>type;
		type=toupper(type);
	   }

}
void account::check_deposit()
{
	while (type=='C'&&deposit<1000)

	  {
		cout<<"\n\n SORRY!!!....You can not deposit less than 1000 Rs. for a current account";
		cout<<"\n\n PLEASE enter your amount to deposit" ;
		cin>>deposit;
	   }
	while (type=='S'&&deposit<500)

	  {
		cout<<"\n\n SORRY!!!....You can not deposit less than 500 Rs. for a saving account";
		cout<<"\n\n PLEASE enter your amount to deposit" ;
		cin>>deposit;
	   }
}

void account::check_name()
{       int flag=0;

	for(int i=0;i<strlen(name);i++)
	 {
	      if(name[i]==' ')
	      flag ++;
	 }
	if(flag==0)
	{
	cout<<"\n\n PLEASE enter name properly (first name and last name both)";
	gets(name);
	check_name();
	}
}




void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report()
{
	cout<<acno<<setw(7)<<" "<<name<<setw(20-strlen(name))<<" "<<type<<setw(6)<<deposit<<endl;
}

int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}


//***************************************************************
//    	function declaration
//****************************************************************
void password();
void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{       account a;
	char ch;
	int num;
	clrscr();
	intro();
	a.password();
	do
	{
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n1. NEW ACCOUNT";
		cout<<"\n\n2. DEPOSIT AMOUNT";
		cout<<"\n\n3. WITHDRAW AMOUNT";
		cout<<"\n\n4. BALANCE ENQUIRY";
		cout<<"\n\n5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n6. CLOSE AN ACCOUNT";
		cout<<"\n\n7. MODIFY AN ACCOUNT";
		cout<<"\n\n8. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8): ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The Account Number : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The Account Number : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\tEnter The Account Number : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The Account Number : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The Account Number : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\t***\t~Thank you for using our Bank Management System~\t***\t";
			break;
		 default :cout<<"\a";
		}
		wait();
	}while(ch!='8');
	return 0;
}


//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(account));
	outFile.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	account ac;
	int flag=0;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n)
{
	int found=0;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c No.         NAME            Type      Balance\n";
	cout<<"====================================================\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	int found=0;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSIT AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited:";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdrawn:";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficient Balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)* sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
	       }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************


void intro()
{       char p[50];
	cout<<"\n\t\t\t\tBANK MANAGEMENT SYSTEM\t\n";
	cout<<"\n\t\t\t\tCREATED BY :\tSAMYAK JAIN";
	wait();
}

void clrscr()
{
    cout<<'\n';
}

int wait()
{
    for(int i=0;i<1000000000;i++) ;
}


//***************************************************************
//    			END OF PROJECT
//***************************************************************
