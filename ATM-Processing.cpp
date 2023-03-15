#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

// atm class
class atm{
	private:
	// private member variables
		long int Account_No;
		string Name;
		int PIN;
		double Balance;
		string Mobile_No;
		
	public:
		void setData(long int account_no, string name, int pIN, double balance, string mobile_no){
		// assigning arguments to private member variable
			Account_No = account_no;
			Name = name;
			PIN = pIN;
			Balance = balance;
			Mobile_No = mobile_no;
		}
	
	//getAccountNo return user's account No.
	long int getAccountNo(){
		return Account_No;
	}
	
	//getName returns user's name
	string getName(){
		return Name;
	}
	
	//getPIN returns user's PIN
	int getPIN(){
		return PIN;
	}
	
	//getBalance returns user's account balance
	double getBalance(){
		return Balance;
	}
	
	//getMobile returns user's mobile No.
	string getMobile(){
		return Mobile_No;
	}
	
	// setMobile will update the user's mobile No.
	void setMobile(string prev_mobileNo, string new_MobileNo){
		// to check old Mobile No.
		if(prev_mobileNo == Mobile_No){	
			cout<<endl<<"Mobile No. updated successfully";
			_getch();
		}
		else{
			cout<<endl<<"Incorrect Old Mobile No. !!";
			_getch();
		}
	}
	
	// cashWithdraw will be used to withdraw cash from ATM
	void cashWithdraw(int amount){
		// to check whether amount entered is valid or not
		if(amount >0 && amount < Balance){
			Balance = Balance - amount;		//update balance
			cout<<endl<<"Please collect your cash";
			cout<<endl<<"Available Balance: "<<Balance;
			_getch();
		}
		else{
			cout<<endl<<"Invalid input or Insufficient Balance";
			_getch();
		}
	}	
};

int main(){
	int choice, enterPIN;
	long int enterAccountNo;
	system("cls");
	
	// create a User
	atm User_1;
	// set User Details
	User_1.setData(987456321, "Anand", 1212, 10000, "9592953791");
	
	do{
		int amount;
		string oldMobileNo, newMobileNo;
		system("cls");
		cout << endl << "  Welcome to ATM  ";
		
		// Asking for User details
		cout<< endl << "Enter your Account No: ";
		cin >> enterAccountNo;
		cout << endl << "Enter your PIN: ";
		cin >> enterPIN;
		
		// Verifying details
		if((enterAccountNo == User_1.getAccountNo()) && (enterPIN == User_1.getPIN())){
			do{
				system("cls");
				cout << endl << "  Welcome to ATM  ";
				cout << endl << "# Select Option" << endl;
				cout << endl << "1) Balance Enquiry";
				cout << endl << "2) Cash Withdrawl";
				cout << endl << "3) Show User Details";
				cout << endl << "4) Update Mobile No.";
				cout << endl << "5) Cancel" << endl;
				cin >> choice;
				
				switch(choice){
					case 1:
						cout << endl << "Your Bank balance is: "<< User_1.getBalance();
						_getch();
						break;
						
					case 2:
						cout << endl << "Enter the amount: ";
						cin >> amount;
						User_1.cashWithdraw(amount);
						break;
						
					case 3:
						cout << endl << "  User Details are :-";
						// fetching user details
						cout << endl << "* Name       : " << User_1.getName();
						cout << endl << "* Account No.: " << User_1.getAccountNo();
						cout << endl << "* Balance    : " << User_1.getBalance();
						cout << endl << "* Mobile No. : " << User_1.getMobile();
						
						_getch();
						break;
					
					case 4:
						cout << endl << "Enter old Mobile No.: ";
						cin >> oldMobileNo;
						cout << endl << "Enter new Mobile No.: ";
						cin >> newMobileNo;
						
						User_1.setMobile(oldMobileNo, newMobileNo);
						break;
						
					case 5:
						exit(0);
						
					default:
						cout << endl << "Invalid request";
						_getch();
						exit(0);
				}
			}while(true);			
		}
		
		// in case of incorrect Account No. or PIN
		else{
			cout << endl << "Incorrect Account No. or PIN";
		}
	}while(true);
	
	return 0;
}
