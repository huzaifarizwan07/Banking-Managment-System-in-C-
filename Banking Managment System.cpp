#include <iostream>
#include <string>
using namespace std;

void createAccount(string, string, string);
void checkDetails(string, string);
void depositAmount(string, string);
void withdrawAmount(string, string);
void Admin();

double balance[100];
string cnicData[100], nameData[100], pinData[100];
int count1, flag=1;
bool isTrue = false;

int main(){
	string name, cnic, cardno, username, pin, password;
	int option;
	double amount;
	
	do{
		int r=0;
		k:
		cout<<"**** WELCOME TO XFI BANK ****"<<endl;
		cout<<endl;
		cout<<"1. Create Account"<<endl;
		cout<<"2. Check Details"<<endl;
		cout<<"3. Withdraw Amount"<<endl;
		cout<<"4. Deposit Amount"<<endl;
		cout<<"5. ADMIN ACCESS"<<endl;
		cout<<endl;
		cout<<"CHOOSE AN OPTION: ";
		cin>>option;
		
		cin.ignore();
		
		switch(option){
			case 1:
				system("CLS");
				cout<<"Enter your name: ";
				getline(cin, name);
				
				x:
				cout<<"Please Enter your correct CNIC No: ";
				cin>>cnic;
				
				if(cnic.length()!=13){
					cout<<"CNIC must be of 13 characters"<<endl;
					goto x;
				}
				
				cout<<"Enter pin: ";
				cin>>pin;
				cout<<endl;
				cout<<"YOUR ACCOUNT CREATED SUCCESSFULLY"<<endl;
				cout<<endl;
				system("PAUSE");
				system("CLS");
				cout<<"PLAESE REMEMBER THESE DETAILS"<<endl;
				cout<<endl;
				cout<<"NAME    : "<<name<<endl;
				cout<<"CARD NO : "<<cnic<<endl;
				cout<<"PIN     : "<<pin<<endl;
				cout<<endl;
				system("PAUSE");
				
				createAccount(name, cnic, pin);
				
				system("CLS");
				
				break;
			case 2:
				y:
				system("CLS");
				cout<<"Enter Your Card no: ";
				cin>>cardno;
				cout<<"Enter pin: ";
				cin>>pin;
				
				checkDetails(cardno, pin);
				cout<<endl;
				
				
				if(isTrue==false){
					r++;
					if(r==4){
						cout<<"PLEASE TRY LATER...."<<endl;
						cout<<endl;
						system("PAUSE");
						system("CLS");
						goto k;
					}
					cout<<"Account not fount! Please Try Again"<<endl;
					cout<<endl;
					system("PAUSE");
					goto y;
				}
				system("PAUSE");
				system("CLS");
				
				break;
			case 3:
				z:
				system("CLS");
				cout<<"Enter Your Card no: ";
				cin>>cardno;
				cout<<"Enter pin: ";
				cin>>pin;
				
				withdrawAmount(cardno, pin);
				
				if(isTrue==false){
					r++;
					if(r==4){
						cout<<"PLEASE TRY LATER...."<<endl;
						cout<<endl;
						system("PAUSE");
						system("CLS");
						goto k;
					}
					cout<<"Account not fount! Please Try Again"<<endl;
					cout<<endl;
					system("PAUSE");
					goto z;
				}
				system("CLS");
				
				break;
			case 4:
				r:
				system("CLS");
				cout<<"Enter Your Card no: ";
				cin>>cardno;
				cout<<"Enter pin: ";
				cin>>pin;
				
				depositAmount(cardno, pin);
				
				if(isTrue==false){
					r++;
					if(r==4){
						cout<<"PLEASE TRY LATER...."<<endl;
						cout<<endl;
						system("PAUSE");
						system("CLS");
						goto k;
					}
					cout<<"Account not fount! Please Try Again"<<endl;
					cout<<endl;
					system("PAUSE");
					goto r;
				}
				system("CLS");
				break;
			case 5:
				n:
				system("CLS");
				cout<<"Enter username: ";
				cin>>username;
				cout<<"Enter password: ";
				cin>>password;
				
				if((username=="admin")&&(password=="2848")){
					Admin();
				}
				else{
					cout<<endl;
					cout<<"INVALID USERNAME OR PASSWORD"<<endl;
					cout<<endl;
					system("PAUSE");
					goto n;
				}
				break;
			default:
				cout<<"WRONG INPUT!"<<endl;
				cout<<endl;
				system("PAUSE");
				system("CLS");					
		}
		
	}while(flag!=0);

	return 0;
}

void createAccount(string n,string c, string p){
	
	cnicData[count1] = c;
	nameData[count1] = n;
	pinData[count1] = p;
	
	count1++;
	
}

void checkDetails(string c, string p){
	
	for(int i=0; i<count1; i++){
		if(c==cnicData[i]){
			if(p==pinData[i]){
				cout<<endl;
				cout<<"OWNER   : "<<nameData[i]<<endl;
				cout<<"BALANCE : Rs."<<balance[i]<<endl;
				isTrue = true;
				break;
			}
			else{
				isTrue = false;
			}
		}
		else{
			isTrue = false;
		}
	}
	
}

void depositAmount(string c, string p){
	double amount;
	for(int i=0; i<count1; i++){
		if(c==cnicData[i]){
			if(p==pinData[i]){
				a:
				cout<<endl;
				cout<<"Enter amount you want to deposit: ";
				cin>>amount;
				balance[i]+=amount;
				cout<<endl;
				cout<<"Rs "<<amount<<" DEPOSITED IN YOUR ACCOUNT"<<endl;
				cout<<endl;
				isTrue = true;
				system("PAUSE");
				break;
			}
			else{
				isTrue = false;
			}
		}
		else{
			isTrue = false;
		}
	}
}

void withdrawAmount(string c, string p){
	double amount;
	for(int i=0; i<count1; i++){
		if(c==cnicData[i]){
			if(p==pinData[i]){
				a:
				cout<<endl;	
				cout<<"Enter amount you want to withdraw: ";
				cin>>amount;
				if(amount<=balance[i]){
					balance[i]-=amount;
					cout<<endl;
					cout<<"Rs "<<amount<<" WITHDRAWL FROM YOUR ACCOUNT"<<endl;
					isTrue = true;
					cout<<endl;
					system("PAUSE");
					break;
				}
				else{
					cout<<"Your account does not have sufficient balance"<<endl;
					cout<<"THANK YOU"<<endl;
					system("PAUSE");
					isTrue = true;
				}
			}
			else{
				isTrue = false;
			}
		}
		else{
			isTrue = false;
		}
	}
}

void Admin(){
	
	int option;
	w:
	system("CLS");
	cout<<"1. CLOSE THE SYSTEM"<<endl;
	cout<<"2. CHECK DETAILS"<<endl;
	cout<<endl;
	cout<<"CHOOSE AN OPTION: ";
	cin>>option;	
	if(option==1){
		flag=0;
		cout<<endl;
		system("PAUSE");
	}	
	else if(option==2){
		system("CLS");
		cout<<"NAME\t\t\t\t|  CARD NO \t\t\t\t| BALANCE"<<endl;
		cout<<"----------------------------------------------------------------------------------"<<endl;
		for(int i=0; i<count1; i++){
			cout<<nameData[i]<<"\t\t\t"<<cnicData[i]<<"\t\t\t\t "<<balance[i]<<endl;
		}
		cout<<endl;
		system("PAUSE");
		system("CLS");
	}
	else{
		cout<<"INAVLID INPUT! PLEASE TRY AGAIN!"<<endl;
		cout<<endl;
		system("PAUSE");
		goto w;
	}
}
