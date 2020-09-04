#include<iostream>
#include <windows.h>	//for use to windows system
#include "MMSystem.h"
#include <ctime>	// for add time function
#include <string>
#include <fstream>
#include<conio.h>
using namespace std;
void wel()
      {
      	system("COLOR F0");
      	cout<<"  \t<<==========--Welcome to Manu--==========>>"<<endl<<"  \tCreated by Raghav S. Patel : 201506100110025"<<endl<<"\t\t   Jaymin Patel : 201506100110033."<<endl;
        PlaySound(TEXT("welcome.wav"), NULL, SND_SYNC);
      }

class times	//for time and date
{
	public:
		void clock()	//for get time
   	  {
			time_t currentTime;
			struct tm *localTime;

 			time( &currentTime );
			localTime = localtime( &currentTime ); 

			  int Day    = localTime->tm_mday;
  			  int Month  = localTime->tm_mon + 1;
			  int Year   = localTime->tm_year + 1900;
			  int hour   = localTime->tm_hour;
			  int Min    = localTime->tm_min;
			  int Sec    = localTime->tm_sec;

			  cout << "\n\t\tCurrent time in India is: " << hour << ":" << Min << ":" << Sec <<endl;	//print time
			  cout << "\n\t\tCurrent Date in India is: " << Day << "/" << Month << "/" << Year <<endl;	//print date
			  if(hour>6 && hour<=12)
 				 {
				  	cout<<"\n\t\t\tGood Morning\n"<<endl;	//print good morning 
				  	PlaySound(TEXT("morning.wav"), NULL, SND_SYNC);	//for play good morning sound
 				 }
		     if(hour>12 && hour<=17)
			     {
				  	cout<<"\n\t\t\tGood Afternoon\n"<<endl;
				  	PlaySound(TEXT("afternoon.wav"), NULL, SND_SYNC);
			     }
		     if(hour>17 && hour<=20)
			    {
				  	cout<<"\n\t\t\tGood Evening\n"<<endl;
				  	PlaySound(TEXT("evening.wav"), NULL, SND_SYNC);
			    }
		    if((hour>20 && hour<=24) || (hour>1 && hour<=6) )
			    {
				  	cout<<"\n\t\t\tGood Night\n"<<endl;
				  	PlaySound(TEXT("night.wav"), NULL, SND_SYNC);
 			    }
	  }
};
class musica	//for music file
{
	public:
		void aa1()
      {
      	cout<<"Now playing ==> UTU Anthom"<<endl;
        PlaySound(TEXT("utu.wav"), NULL, SND_SYNC);
      }
      void aa2()
      {
      	cout<<"Now playing ==> Indian National Anthem"<<endl;
        PlaySound(TEXT("indian.wav"), NULL, SND_SYNC);
      }
      void aa3()
      {
		cout<<"Now playing ==> United States of America"<<endl;
        PlaySound(TEXT("usa.wav"), NULL, SND_SYNC);
      }
};
int music()	//for music select
{
	musica m1;
	char track;
	int chack;
	cout<<"\t Please Select any one Anthom"<<endl;
	cout<<"\t\t1==>UTU Anthom"<<endl;
	cout<<"\t\t2==>Indian National Anthem"<<endl;
	cout<<"\t\t3==>United States of America"<<endl;
	do
	{
	cout<<"\t Enter selected==>";
	track=getch();
	switch(track)
	{
		chack=1;
		case '1':
			m1.aa1();
			break;
		case '2':
			m1.aa2();
			break;
		case '3':
			m1.aa3();
			break;
		default :
		cout<<"\t\t\t Please Choose Valid Option"<<endl;
      	chack=0;
      	break;
	} 
	}while (chack=0);
}
int shut()	//for shutdown pc
{
	char ch;
	cout<<"Do you want to Shutdown your pc now"<<endl<<"Enter selected==>";
	cin>>ch;
	if(ch == 'y')
	system("shutdown -f");
	return 0;
}
int cal()
{	int chack;
    char o;
    float num1,num2;
    do
    {
    chack=1;
	cout << "\nEnter operator either + or - or * or /: ";
    o=getch();
    cout << "\nEnter two operands: ";
    cin >> num1 >> num2;
    switch(o) {
        case '+':
            cout << num1+num2<<endl;
            break;
        case '-':
            cout << num1-num2<<endl;
            break;
        case '*':
            cout << num1*num2<<endl;
            break;
        case '/':
            cout << num1/num2<<endl;
            break;
        default:
            cout << "operator is not correct";
            chack=0;
            break;
    }
	}while (chack=0);
    return 0;
}
class user //for user login
 {

public:
	string username,username1;
	string password,password1;

	void userRegister()
	{
		cout << "Please register.\nEnter a new username:\n"<<endl;
		cin >> username;

		cout << "\nPlease enter a new password:\n"<<endl;
		cin >> password;

		ofstream usersFile ("userData.txt"); // txt file

		if (	!usersFile.is_open())
		{
			usersFile.open("userData.txt");
		}

			usersFile << username << " " << password << endl;

			usersFile.close();
			loginuser();
	}
	
	void loginuser()
	{
		cout<<"Please Enter Your usename"<<endl;
		cin>>username1;
		cout<<"Please insert your password"<<endl;
		cin>>password1;
		if(password1.length() < 6)
			{
				cout << "Password length must be atleast 6 characters long.";
			}
		else
		{
			ifstream usersFile ("userData.txt");

			if (	!usersFile.is_open())
			{
				usersFile.open("userData.txt");
			}

			usersFile >> username;
			usersFile >> password;
			if(username != username1 || password != password1)
			{
				cout<<"Your username is wrong"<<endl;
				userRegister();
			}
			usersFile.close();
		}
	}
};
int main()	//main function
{
	user user1;
	int chack;
	char getdata;

	times t1;
	wel();
	t1.clock();
	user1.loginuser();
	cout<<"  \t<<For Anthoms Enter =1>>"<<endl;
	cout<<"  \t<<For File Explorer Enter =2>>"<<endl;
	cout<<"  \t<<For Notepad Enter =3>>"<<endl;
	cout<<"  \t<<For Your ip address Enter =4>>"<<endl;
	cout<<"  \t<<For Your Restart Your pc Enter =5>>"<<endl;
	cout<<"  \t<<For Open Google in your default browser Enter =6>>"<<endl;
	cout<<"  \t<<For calculater softwere Enter =7>>"<<endl;
	cout<<"  \t<<For Exit from this programm =8>>"<<endl;
	do
	{
	cout<<"\n\t Enter selected==>";
	getdata=getch();
	switch(getdata)
	{
		chack=1;
		case '1':
			music();
			break;
		case '2':
			system("explorer.exe");
			break;
		case '3':
			system("notepad.exe");
			break;
		case '4':
			system("C:\\Windows\\System32\\ipconfig");
			break;
		case '5':
			shut();
		case '6':
			system("start www.google.com");
			break;
		case '7':
			cal();
			break;
			case '8':
			return 0;
			break;		
		default :
		cout<<"\t\t\t Please Choose Valid Option"<<endl;
      	chack=0;
      		break;
	} 
	}while (chack=1);
	return 0;
}
//end of the program
