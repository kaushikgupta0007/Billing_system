#include<bits/stdc++.h>
#include<string.h>
#include<fstream>
using namespace std;
class shopping
{
	 private:
	 	int pcode;
	 	float price;
	 	float dis;
	 	string pname;
	 	
	 	
	 	public:
	 		void menu();
	 		void administrator();
	 		void buyer();
	 		void add();
	 		void edit();
	 		void rem();
	 		void list();
	 		void receipt();
	 	
};
void shopping::menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t\t________________________________________\n";
	cout<<"\t\t\t\t\t                                        \n";
	cout<<"\t\t\t\t\t              Main Menu                 \n";
	cout<<"\t\t\t\t\t                                        \n";
	cout<<"\t\t\t\t\t________________________________________\n";
	cout<<"\t\t\t\t\t                                        \n";
	cout<<"\t\t\t\t\t                                        \n";
	cout<<"\t\t\t\t\t || 1) Administrator   ||\n";
	cout<<"\t\t\t\t\t ||                    ||\n";
	cout<<"\t\t\t\t\t || 2) Buyer           ||\n";
	cout<<"\t\t\t\t\t ||                    ||\n";
	cout<<"\t\t\t\t\t || 3) Exit            ||\n";
	cout<<"\t\t\t\t\t ||                    ||\n";
	cout<<"\t\t\t\t\t                         \n";
	cout<<"\t\t\t\t\t                         \n";
	cout<<"\t\t\t\t\t ||  please select     ||\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
		cout<<"\t\t\t Please Login \n";
		cout<<"\t\t\t_________ Email__________ \n";
		cin>>email;
		cout<<"\t\t\t _________Password________\n";
		cin>>password;
		if(email=="kaushikgupta123@gmail.com" && password=="kaushik@123")
		{
			administrator();
		}
		else
		{
			cout<<"Invalid email/password";
		}
		break;
		case 2:
			{
				buyer();
			}
		case 3:
			{
				exit(0);
			}
		default:
			cout<<"\nplease enter a valid Input\n";
	}
	
	goto m ;
	
}
void shopping::administrator()
{
	
	k:
	int choice;
	cout<<"\n\n\n\t\t\t ____Administrator menu______";
	cout<<"\n\t\t\t\t||____1) Add The Product_____||";
	cout<<"\n\t\t\t\t||                           ||";
	cout<<"\n\t\t\t\t||____2) Modify The Product__||";
	cout<<"\n\t\t\t\t||                           ||";
	cout<<"\n\t\t\t\t||____3) Delete The Product__||";
	cout<<"\n\t\t\t\t||                           ||";
	cout<<"\n\t\t\t\t||____4) Back To Main Menu___||";
	cout<<"\n\t\t\t\t||                           ||";
	
	cout<<"\n\n\t_____ please enter your choice____ ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			{
				cout<<"\nPlease enter a valid Input\n";
			}
	}
	
	goto k;
	
	
}
void shopping::buyer()
{
	
	j:
	int choice;
	cout<<"\t\t\t_________Buyer__________\n";
	cout<<"_______________________________\n";
	cout<<"                      \n";
	cout<<"\t\t\t 1) Buy product \n";
	cout<<"                      \n";
	cout<<"\t\t\t 2) Go back     \n";
	cout<<"________________________\n";
	cout<<"                      \n";
	cout<<"\t\t\t Enter Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;	
		default:
			cout<<"\nPlease enter a valid Input\n";
	}
	goto j; 
	
}
 void shopping :: add()
 {
 	k:
 	fstream data;
 	int c;
 	int token=0;
 	float p;
 	float d;
 	string n;
 	
 	cout<<"\n\n\n\t\t <<<<<<<<Add New Product>>>>>>>   ";
 	cout<<"\n\n\n\t\t Product code of the product ";
 	cin>>pcode;
 	cout<<"\n\n\t Name of the product ";
 	cin>>pname;
 	cout<<"\n\n\t price of the product ";
 	cin>>price;
 	cout<<"\n\n\t Discount on the product ";
 	cin>>dis;
 	
 	data.open("database.txt",ios::in);
 	
 	if(!data)
	 { 
 		data.open("database.txt",ios::app|ios::out);
 		data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
 		data.close();
 		
	 }
	 else 
	 {
	 	data>>c>>n>>p>>d;
	 	
	 	while(!data.eof())
	 	{
	 		if(c==pcode)
	 		{
	 			token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	 
	 if(token==1)
	 {
	 	goto k;
	 }
	 else
	 {
	 	data.open("database.txt",ios::app|ios::out);
 		data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
 		data.close();
 		
	 }
	}
	 cout<<"\n\n\t\t Record Inserted !";
 }
 
void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t Modify The Record ";
	cout<<"\n\n\t\t\t enter the product code";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n File doesn't exist ! ";
	}
	else
	{
		
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\n\t\t Product New Code :";
				cin>>c;
				cout<<"\n\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\n\t\t price of the product :";
				cin>>p;
				cout<<"\n\n\t\t discount on the product :";
				cin>>d;
				data1<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"\n";
				cout<<"\n\n\t\t Record Edited ";
				token++;
			}
			else 
			{
				data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		
	data.close();
	data1.close();
	remove("database.txt");
	rename("database1.txt","database.txt");
	if(token==0)
	{
		cout<<"\n\n Record not found ! ";
	}
}
}
void shopping::rem()
{
	fstream data,data1;
	int pkey; 
	int token=0;
	cout<<"\n\n\t\t Delete Product ";
	cout<<"\n\t\t enter product code :";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n File doesn't exist ";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted successfully";
				token++;
			}
			else
			{
				data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record Not Found";
		}
		
	}
}
void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|___________________________________________\n";
	cout<<"pro_No\t\tName\t\tprice\n";
	cout<<"\n\n|___________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		 cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		 data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping::receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float ammount=0;
	float dis=0;
	float total=0;
	cout<<"\n\n\t\t\t___RECEPT____";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty Database ";
	}
	else
	{
		data.close();
		list();
		cout<<"\n_____________________________________________\n";
		cout<<"\n|                                           |\n";
		cout<<"\n|         Please place the order            |\n";
		cout<<"\n|                                           |\n";
		cout<<"\n|___________________________________________|\n";
		
		do
		{
			l:
			cout<<"\n\n Enter Product Code : ";
			cin>>arrc[c];
			cout<<"\n\n Enter the product quantity : ";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate Product Code , Please try again !";
					goto l;
				}
			}
			c++;
			cout<<"\n\n Do you want to but another product ? if yes then press y otherwise no :  ";
			cin>>choice;
		}while(choice=='y');
		
		cout<<"\n\n\t\t\t___________________RECEPT__________________\n";
		cout<<"\n product_No\t product_name \t product quantity \t Price \t Ammout \t Ammount with discount\n";
		for(int i=0;i<c;i++)
		{
			data.open("datatbase.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					ammount=price*arrq[i];
					dis=ammount-(ammount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<ammount<<"\t\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
			data.close();
		}
		
		cout<<"\n\n_____________________________________________________________";
		
		cout<<"\n Total Amount :: "<<total;
		
		
	}
	
	
}

int main()
{
	shopping s;
	s.menu(); 
}
