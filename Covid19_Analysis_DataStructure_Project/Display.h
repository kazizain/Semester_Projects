#include<iostream>
#include<windows.h>
#include <conio.h>
#include<fstream>
#include <sstream>
using namespace std;

string bankName="COVID-19 ANALYSIS";

void title()
{
			system("cls");
	        char Arr[100];
			strcpy(Arr,bankName.c_str());
			cout<<"\n\t\t----------------------------------------------";
			cout<<"\n\t\t\t";
			for(int i=1;i<=17;i++)
			{
				if( i < 9)
				{
					Sleep(100);
					cout<<">";
				}
				else if( i > 9 )
				{
					Sleep(100);
					cout<<"<";
				}
				else if( i == 9 )
				{
					cout<<"   ";
					for(int j=0;j<bankName.length();j++)
					{
						Sleep(100);
						cout<<Arr[j];
					}
					cout<<"   ";
					
				}
				else
				{
					cout<<endl;
				}
			}	
			cout<<"\n\t\t----------------------------------------------\n\n";
}
void loading()
{
	cout<<"\n\t\t";
    system("pause");
    cout<<"\n\t\tLoading in process ";
    for(int i=0;i<3;i++)
    {
    	Sleep(500);
    	cout<<(char)16<<" "; // for loading line ....!
    
	}
	Sleep(1000);
	system("cls");
}	void display()
{	
			cout<<"\n\n\t\t----------------------------------------------";
			cout<<"\n\n\t\t		"<<(char)04<<(char)04<<(char)04<<(char)04<<"WELCOME TO "<<(char)04<<(char)04<<(char)04<<(char)04<<"\n";
			title();
			cout<<"\n\n\t\t\tCOVID-19 DATASET";
			cout<<"\n\n\t\t\tPOWERED BY TEAM AVANGERS  \n\n";
			cout<<"\n\n\t\t--------------------------------------------";
			loading();
}

