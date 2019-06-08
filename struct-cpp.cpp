
/*Name: Muhamad Noor Hazim Bin Mohamed Esa
Date created : 08/6/2019
Project description: This program shows you how to use structure in c++
Project Features:
- Register User (multiple user)
- Login
- logout
- Forgot Password
- Reset Password
- change type text to password
*/
#include <iomanip>
#include <iostream>
#include <string>
#include<conio.h> //lib for getch() -> change text to *****

using namespace std;

//prorotype function declare
int display();
int login(string username, string password);
int controller();
int forgotpass();
int program(int i);

//global declare struct
struct user {
	string name,username,password,security;
} u[5];

//main function
int main(){
	int sys = true;
	
	while(sys){
		cout << endl;
		cout << "++++++++++++++++++++++++++++" << endl;
		cout << "List Users (Max 5 users):" << endl;
		for(int a = 0; a <5 ; a++){
			if(u[a].name != ""){
				cout << a+1 << " - " << u[a].name << endl;
			}
		}
		sys = controller();	
	}
}

//controller function
int controller(){
	int mode ;
	string tmp_username, tmp_password;
	mode = display();
	
	if(mode == 1){
		cout << endl;
		cout << "Login :: Please Enter your Username & Password" << endl;
		cout << "Username : ";
		cin >> tmp_username ;
		cout << "Password : ";
		for(int i=0;i<6;i++)
	    {
	       	tmp_password+=getch();
	        printf("*");
	    }
		login(tmp_username, tmp_password);
		
	} else if(mode == 2){
		for (int a = 0; a < 5; a++){
			if(u[a].name == ""){
				cout << endl;
				cout << "Register :: Please enter your details" << endl;
				cout << "Name : ";
				cin >> u[a].name;
				cout << "Username : ";
				cin >> u[a].username ;
				cout << "Passoword (6 digit): ";
				for(int i=0;i<6;i++)
			    {
			        u[a].password+=getch();
			        printf("*");
			    }
				cout << endl << "Security (For Forgot Password) : ";
				cin >> u[a].security;
				break;
			}
		}
		return true;
		
	} else if(mode == 3){
		forgotpass();
	} else if(mode == 0){
		return false;
	} else {
		cout << endl << endl;
		cout << "Invalid enter. try again. " << endl << endl ;
		return true;
	}
}

//forgot password function
int forgotpass(){
	//f = forgot
	string f_secure, f_newpass, f_username ;
	
	cout << "Forgot Password :: Enter your Username & security code " << endl << endl;
	cout << "Username : " ;
	cin >> f_username;
	cout << "Security Code : ";
	cin >> f_secure ;
	for(int a = 0; a < 5; a++){
		if(f_username == u[a].username && f_secure == u[a].security){
			cout << "Enter your new password : " ;
			for(int i=0;i<6;i++)
			    {
			        f_newpass+=getch();
			        printf("*");
			    }
			u[a].password = f_newpass ;
			cout << endl ;
			cout << "Successful, your password has been reset. Try Login again " << endl << endl;
			return true;
		} 
	}
	cout << endl ;
	cout << "Unsuccessful, Your username or security code are invalid " << endl << endl;
	return true;
	
}

//display function
int display(){
	int a ;
	cout << endl;
	cout << "++++++++++++++++++++++++++++" << endl ;
	cout << "Please Select:"<< endl ;
	cout << "1. Login"<< endl ;
	cout << "2. Register"<< endl ;
	cout << "3. Forgot Password"<< endl ;
	cout << "0. Exit" << endl;
	cout << endl ;
	
	cout << "No : ";
	cin >> a;
	
	return a;
}

//login function
int login(string a, string b){
	for(int i = 0; i < 5; i++){
		if(a == u[i].username && b == u[i].password){
			program(i);
			return true;
		}
	}
	cout << endl << "invalid username or password" << endl << endl;
	return true;	
}

//program function
int program(int i){
	int a ;
	cout << endl << endl;
	cout << "Successfull login:" << endl;
	cout << "+----------------------+" << endl ;
	cout << "Hello, " << u[i].name << endl;
	cout << "Welcome to your program"<< endl ;
	cout << endl ;
	cout << "Your Details :" << endl ;
	cout << "Name : " << u[i].name << endl ;
	cout << "Username : " << u[i].username << endl ;
	cout << "Security Code : " << u[i].security << endl << endl;
	cout << "1. Logout"<< endl ;
	cout << "+----------------------+" << endl ;
	cout << endl ;
	
	
	cout << "No : ";
	cin >> a;
	if(a == 1){
		return true;
	} else {
		program(i);
	}
}
