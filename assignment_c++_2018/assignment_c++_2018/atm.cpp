
/*Assignment C++ 2018
2.ระบบ ATM*/

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;

void regis(int r);
void log();
void display();
void deposit(string bankuser,int r);
void Withdraw(string bankuser,int r);
void Transfer(string bankuser,int r);

ifstream InFile;
ofstream OutFile;

string data[50][5];
string bank;
int mon[50];
int keep[50][5];

int main()
{
	int  done=1;
	int r=0;
	int choice;
	
	do{
	system("cls");
	cout << setw(10) << "+" << setw(49) << setfill('=') << "+" << endl;
	cout << setfill(' ');
	cout << setw(39) <<"|	           	ATM		          |"<< endl;
	cout << setw(10) << "+" << setw(49) << setfill('=') << "+" << endl;
	cout << setfill(' ');
	cout << setw(59) << "|  1 -> Register                                 |" << endl;
	cout << setw(59) << "|  2 -> ATM                                      |" << endl;
	cout << setw(59) << "|  3 -> Report                                   |" << endl;
	cout << setw(59) << "|  4 -> Exit                                     |" << endl;
	cout << setw(10) << "+" << setw(49) << setfill('=') << "+" << endl;
	cout << setfill(' ');
	do{
		cout << "Selest menu (1 - 4) : ";
		cin>>choice;
		if(choice < 1 || choice > 4)
		{
		 cout << "Error! please enter again . . .\n";
		}
	}while(choice < 1 || choice > 4);
		if(choice==1)
		{
			r=r+1;
			regis(r);
		}
		else if(choice==2)
		{
			log();

		}
		else if(choice==3)
		{
			display();

		}
		else if(choice==4)
		{
			done=0;

		}
	}while(done);
	return 0;
}
void regis(int r)
{
	system("cls");
	string id;
	srand((unsigned int)time(0));
	int n;
	string File;
	int choice;
	string a="K-bank",b="SCB",c="TMB";

	cout << setfill('-') << setw(35) <<"-"<<endl;
	cout << setfill(' ');
	cout <<"	Choose your bank" << endl;
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
	cout << "1." << a << endl;
	cout << "2." << b << endl;
	cout << "3." << c << endl;
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
	
	do{
		cout << "Selest menu (1 - 3) : ";
		cin>>choice;
		
		if(choice < 1 || choice > 3)
		{
		 cout << "Error! please enter again . . .\n";
		}

	}while(choice < 1 || choice > 3);


	cout<<endl;
	if(choice==1){bank=a;}
	else if(choice==2){bank=b;}
	else if(choice==3){bank=c;}
	data[r][0]=bank;
	system("cls");
	cout << setfill('-') << setw(40) << "-" << endl;
	cout << setfill(' ');
	cout <<"Enter name and surname : ";
	cin>>data[r][1]>>data[r][2];

	for(int i=0;i<6;i++){
	n=rand()%10;
	if(n==0)
	{
		id="0";
	}
	else if(n==1)
	{
		id="1";
	}
	else if(n==2)
	{
		id="2";
	}
	else if(n==3)
	{
		id="3";
	}
	else if(n==4)
	{
		id="4";
	}
		else if(n==5)
	{
		id="5";
	}
		else if(n==6)
	{
		id="6";
	}
		else if(n==7)
	{
		id="7";
	}
		else if(n==8)
	{
		id="8";
	}
		else if(n==9)
	{
		id="9";
	}
		data[r][3]=data[r][3]+id;
	}
	system("cls");
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
	cout << "Your id is : " << data[r][3] << endl;
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
	cout << "Enter number of money : ";
	cin >> mon[r];
	ofstream OutFile;
	File = bank + ".txt";
	
	OutFile.open (File,ios_base::out|ios_base::app);
	for(int c=0;c<4;c++){
	OutFile<<data[r][c]<<" ";
	}
	OutFile<<mon[r]<<endl;	
	OutFile.close();
	system("cls");
}
void log()
{
	bool done=true;
	bool done1=true;
	system("cls");
	string id,bankuser;
	int choice,choose;
	string a="K-bank",b="SCB",c="TMB";
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
	cout << "	Choose your bank" <<endl;
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
	cout << "1." << a << endl;
	cout << "2." << b << endl;
	cout << "3." << c << endl;
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');

	do{
		cout << "Selest menu (1 - 3) : ";
		cin>>choice;
		if(choice < 1 || choice > 3)
		{
		 cout << "Error! please enter again . . .\n";
		}
	}while(choice < 1 || choice > 3);

	cout<<endl;
	if(choice==1){bankuser=a;}
	else if(choice==2){bankuser=b;}
	else if(choice==3){bankuser=c;}
	
	do{
	system("cls");
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
	cout << "Enter id card (0 for exit) : " ;
	cin >> id;
	
	ifstream inFile;
	inFile.open(bankuser + ".txt");
	
	for(int r=0;r<20;r++){
	inFile >> mon[r];
		for(int c=0;c<4;c++){
		inFile >> data[r][c];
		}
		if(id==data[r][3] && bankuser==data[r][0])
		{
		system("cls");
		
			do{
			system("cls");
			cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
			cout << "1.Deposit  " << endl;
			cout << "2.Withdraw  " << endl;
			cout << "3.Transfer  " << endl;
			cout << "4.Balance  " << endl;
			cout << "5.Exit  " << endl;
			cout<<setfill('-')<<setw(35)<<"-"<<endl;
	cout<<setfill(' ');
			
			do{
				cout << "Selest menu (1 - 5) : ";
				cin>>choose;
				if(choose < 1 || choose > 5)
		{
		 cout << "Error! please enter again . . .\n";
		}
			}while(choose < 1 || choose > 5);

			if(choose==1)
			{
			system("cls");
			cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
			cout << "Balance : " << mon[r] << endl;
			cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
			deposit(bankuser,r);
			
			}
			else if(choose==2)
			{
			system("cls");
			cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
			cout << "Balance : " << mon[r] << endl;
			cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
			Withdraw(bankuser,r);
			}
			else if(choose==3)
			{
			system("cls");
			cout<<setfill('-')<<setw(35)<<"-"<<endl;
	cout<<setfill(' ');
			cout<<"Balance : "<<mon[r]<<endl;
			cout<<setfill('-')<<setw(35)<<"-"<<endl;
	cout<<setfill(' ');
			Transfer(bankuser,r);
			}
			else if(choose==4){
				system("cls");
				cout<<setfill('-')<<setw(35)<<"-"<<endl;
		cout<<setfill(' ');
				cout<<"Balance : "<<mon[r]<<endl;
				system("PAUSE");
			}
			else if(choose==5){
				
				done1=false;
			}
			}while(done1);
			done=false;
		}
		if(id=="0")
		{
			
			done=false;
		}
	}
	inFile.close();
	}while(done);
	system("cls");
	
}
void deposit(string bankuser,int r)
{
	int moneydeposit;
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
	cout<<"Enter money for deposit : ";
	cin>>moneydeposit;
	if(moneydeposit>0){

	ifstream inFile;
	inFile.open(bankuser + ".txt");
	inFile>>mon[r];

	mon[r]=moneydeposit+mon[r];
	
	keep[r][0]=keep[r][0]+moneydeposit;
	cout<<"\n\n---DONE!---\n\n";
	cout<<"Total money is : "<<mon[r]<<endl;
	
	OutFile.open (bankuser+".txt",ios_base::out|ios_base::app);
	OutFile<<mon[r]<<" ";
	OutFile.close();
	system("PAUSE");
	system("cls");
	}
	else{
		cout << "Money for deposit error! . . .\n";
		system("PAUSE");
	}
}

void Withdraw(string bankuser,int r)
{
	int moneywithdraw;
	cout << setfill('-') << setw(35) << "-" << endl;
	cout << setfill(' ');
	cout<<"Enter money for Withdraw : ";
	cin>>moneywithdraw;
	if(moneywithdraw>0){
	ifstream inFile;
	inFile.open(bankuser + ".txt");
	inFile>>mon[r];
	if(moneywithdraw<=mon[r]){
	mon[r]=mon[r]-moneywithdraw;
	
	keep[r][1]=keep[r][1]+moneywithdraw;
	cout<<"\n\n---DONE!---\n\n";
	cout<<"Total money is : "<<mon[r]<<endl;
	OutFile.open (bankuser+".txt",ios_base::out|ios_base::app);
	OutFile<<mon[r]<<" ";
	OutFile.close();
	}
	if(moneywithdraw<0){
		cout << "Number of money error! . . .\n";
		system("PAUSE");
	}
	}
	ifstream inFile;
	inFile.open(bankuser + ".txt");
	inFile>>mon[r];
	 if(moneywithdraw>mon[r]){
		cout<<"Not enough money! . . ."<<endl;
		system("PAUSE");
	}
	system("cls");
}

void Transfer(string  bankuser,int r)
{
	int done=true;
	string id,bankuserb;
	
	int rb=r;
	int rn;
	
	bankuserb=bankuser;
	int moneytransfer;
	int choice;
	string a="K-bank",b="SCB",c="TMB";
	cout<<"Choose your bank"<<endl;
	cout<<"1."<<a<<endl;
	cout<<"2."<<b<<endl;
	cout<<"3."<<c<<endl;
	cout<<setfill('-')<<setw(35)<<"-"<<endl;
	cout<<setfill(' ');

	do{
		cout << "Selest menu (1 - 3) : ";
		cin>>choice;
		if(choice < 1 || choice > 3)
		{
		 cout << "Error! please enter again . . .\n";
		}
	}while(choice < 1 || choice > 3);
	cout<<endl;

	if(choice==1){bankuser=a;}
	else if(choice==2){bankuser=b;}
	else if(choice==3){bankuser=c;}
	do{
	system("cls");
	cout << setfill('-') << setw(50) << "-" << endl;
	cout << setfill(' ');
	cout << "Enter transfer to id card (0 for exit) : " ;
	cin>>id;
	ifstream inFile;
	
	for(int r=0;r<20;r++){
	inFile >> mon[r];
		for(int c=0;c<4;c++){
		inFile >> data[r][c];
		}
		if(id==data[r][3]&&bankuser==data[r][0])
		{
	rn=r;
	r=rb;
	system("cls");
	cout << setfill('-') << setw(40) << "-" << endl;
	cout << setfill(' ');
	cout<<"Enter money for Transfer : ";
	cin>>moneytransfer;
	ifstream inFile;
	inFile.open(bankuser + ".txt");
	inFile>>mon[r];
	if(moneytransfer<=mon[r]&&moneytransfer>0){
	mon[r]=mon[r]-moneytransfer;
	keep[r][2]=keep[r][2]+moneytransfer;
	cout<<"\n\n---DONE!---\n\n";
	cout<<"Total money : "<<mon[r]<<endl;
	OutFile.open (bankuserb+".txt",ios_base::out|ios_base::app);
	OutFile<<mon[r]<<" ";
	OutFile.close();
	system("PAUSE");

	inFile.open(bankuser + ".txt");
	inFile>>mon[r];
	r=rn;
	inFile.open(bankuser + ".txt");
	inFile>>mon[r];
	mon[r]=moneytransfer+mon[r];
	OutFile.open (bankuser+".txt",ios_base::out|ios_base::app);
	OutFile<<mon[r]<<" ";
	OutFile.close();
	}
	else if(moneytransfer>mon[r]){
		cout<<"Not enough money! . . ."<<endl<<endl;
		system("PAUSE");
	}
	/*inFile.open(bankuser + ".txt");
	inFile>>mon[r];
	r=rn;
	inFile.open(bankuser + ".txt");
	inFile>>mon[r];
	mon[r]=moneytransfer+mon[r];
	OutFile.open (bankuser+".txt",ios_base::out|ios_base::app);
	OutFile<<mon[r]<<" ";
	OutFile.close();*/
	done=false;
		}
	 if(id=="0")
		{
			done=false;
		}
	}
		}while(done);
	cout<<endl;
 system("cls");
}

void display()
{
	bool done=true;
	system("cls");
	string id,bankuser;
	int choice,choose;
	string a="K-bank",b="SCB",c="TMB";
	cout<<setfill('-')<<setw(35)<<"-"<<endl;
	cout<<setfill(' ');
	cout<<"	Choose your bank"<<endl;
	cout<<setfill('-')<<setw(35)<<"-"<<endl;
	cout<<setfill(' ');
	cout<<"1."<<a<<endl;
	cout<<"2."<<b<<endl;
	cout<<"3."<<c<<endl;
	cout<<setfill('-')<<setw(35)<<"-"<<endl;
	cout<<setfill(' ');

	do{
		cout << "Selest menu (1 - 3) : ";
		cin>>choice;
		if(choice < 1 || choice > 3)
		{
		 cout << "Error! please enter again . . .\n";
		}
	}while(choice < 1 || choice > 3);
	cout<<endl;

	if(choice==1){bankuser=a;}
	else if(choice==2){bankuser=b;}
	else if(choice==3){bankuser=c;}
	//do{
	system("cls");
	cout<<setfill('=')<<setw(70)<<"="<<endl;
	cout<<setfill(' ');

	ifstream inFile;
	inFile.open(bankuser + ".txt");


	cout<<"			Show All Incude money " << bankuser <<endl;
			cout<<setfill('-')<<setw(70)<<"-"<<endl;
			cout<<setfill(' ');
			cout<<"    Id:	       Deposit:       Withdraw:       Transfer:      Balance:"<<endl;
			cout<<setfill('=')<<setw(70)<<"="<<endl;
			cout<<setfill(' ');

			OutFile.open (bankuser+".txt",ios_base::out|ios_base::app);
			OutFile<<endl;

			OutFile<<"			Show All Incude money " << bankuser <<endl;
			OutFile<<setfill('-')<<setw(70)<<"-"<<endl;
			OutFile<<setfill(' ');
			OutFile<<"    Id:	       Deposit:       Withdraw:       Transfer:      Balance:"<<endl;
			OutFile<<setfill('=')<<setw(70)<<"="<<endl;
			OutFile<<setfill(' ');

	for(int r=0;r<20;r++){
	inFile >> mon[r];
		for(int c=0;c<4;c++){
		inFile >> data[r][c];
		}
		if(" "!=data[r][3] && bankuser==data[r][0])
		{
			
			/*cout<<"		Incude money " << bankuser <<endl;
			cout<<setfill('=')<<setw(56)<<"="<<endl;
			cout<<setfill(' ');
			cout<<"	Id:		Deposit:	Withdraw:	Transfer:	Balance:"<<endl;
			cout<<setfill('=')<<setw(56)<<"="<<endl;
			cout<<setfill(' ');*/

			cout << " " <<setw(5) << data[r][3] <<"          ";

			for (int c=0;c<3;c++){
			cout<<" "<<setw(5)<<keep[r][c]<<"          ";
			}
			cout<<" "<<mon[r];
			cout<<endl;
			cout<<setfill('-')<<setw(70)<<"-"<<endl;
			cout<<setfill(' ');
			/*OutFile.open (bankuser+".txt",ios_base::out|ios_base::app);
			OutFile<<endl;/*

			/*OutFile<<"		Incude money"<<endl;
			OutFile<<setfill('=')<<setw(56)<<"="<<endl;
			OutFile<<setfill(' ');
			OutFile<<" deposit:	Withdraw:	Transfer:	Balance:"<<endl;
			OutFile<<setfill('=')<<setw(56)<<"="<<endl;
			OutFile<<setfill(' ');*/

			OutFile << " " <<setw(5) << data[r][3] <<"          ";

			for (int c=0;c<3;c++){
			OutFile<<" "<<setw(5)<<keep[r][c]<<"          ";
			}
			OutFile<<"   "<<mon[r];
			OutFile<<endl;
			OutFile<<setfill('-')<<setw(70)<<"-"<<endl;
			OutFile<<setfill(' ');
			OutFile.close();
			//system("PAUSE");
			//done=false;
		}
	else if(id=="0"){
		done=false;
	}
	}system("PAUSE");
	//}while(done);
}