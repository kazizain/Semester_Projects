#include<iostream>
#include<stdlib.h>
#include<string>
#include <fstream>
#include<stack>
#include<queue>
#include<conio.h>
#include<windows.h>
#include"Display.h"
using namespace std;


//-------------------------------------------------->node class
class Node
{
	
	public:
		string userid;
		string name;
		string city;
		string hospital;
		string year;
		string cnic;
		string age;
		string report;
		string doctor;
		string result;
		int height;
		Node *left;
		Node *right;
	
	
	Node(string a,string b,string c,string d,string e, string f, string g, string h, string i, string j)
	{
		userid = a;
		name = b;
		city =c;
		hospital= d;
		year=e;
		cnic=f;
		age=g;
		report=h;
		doctor=i;
		result = j;
		left = right = 0;
		
	}
	
};

class Covid
{	
	Node *root;
		public:
			Covid()
			{
				root = 0;
			}
			
			//Inserting in AVL like BST
   			//Returns the height of the tree
			int heightFinder(Node *n)
			{
				if(n == 0)
					return 0;
	
				return n->height;
			}
			
			//Returns max of two heights given 
			int max(int a, int b)
			{    
				return (a > b)? a : b;
			}
			
			
			//Checks whether left-sub tree is heavier or right one 
			int checkBalance(Node *r)
			{
				if(r == 0)
				{
					return 0;
				}
				else
				{
					return ( heightFinder(r->left) - heightFinder(r->right) );
				}
			}
			
			
			//---------------------------------------->Insertion starts from here
	    	void insert(string a,string b,string c,string d,string e, string f, string g, string h, string i, string j)
			{
	    		//	cout << "d";
	        	root = insert(a,b,c,d,e,f,g,h,i,j, root);
	    	}
	    	
	    	
	    	//------------------------------------------------------> calling insert function by prev insert. (add data in tree shape)
	    	Node *insert(string a,string b,string c,string d,string e,string f, string g, string h, string i, string j, Node *r)
			{
	   	
				if( r == 0)
				{
					r = new Node(a,b,c,d,e,f,g,h,i,j);
					r->height = 1;
				}
			
				else if(c < r->userid)
				{
					r->left = insert(a,b,c,d,e,f,g,h,i,j,r->left);
				}
				
				else if(c > r->userid)
				{
					r->right = insert(a,b,c,d,e,f,g,h,i,j,r->right);
				}
				
				else
				{
					return r;  
				}
	    
				
				//---------------------------------------------> making tree avl to avoid the worst case of bst
				
				
				
				r->height = 1 + max(heightFinder(r->left),heightFinder(r->right));   //updating height of ancestor
		
				int balancing_Factor = checkBalance(r);  //checking balancing factor
	    
	    		// Right rotation to be performed as nodes alligned to the left
	    		if (balancing_Factor > 1 && c < r->left->userid)
				{
					return RightRotation(r);
				}
			
	     		// Left rotation to be performed as nodes alligned to the right
	    		if (balancing_Factor < -1 && c > r->right->userid)
				{
	        		return LeftRotation(r);
				}
	 
	    		// LR ROTATION
	    		if (balancing_Factor > 1 && c > r->left->userid)
				{
					r->left = LeftRotation(r->left);
	        		return RightRotation(r);
				}
	 
	    		//  RL ROTATION
	    		if (balancing_Factor < -1 && c < r->right->userid)
				{
		    		r->right = RightRotation(r->right);
	        		return LeftRotation(r);	
				}
	
	    		return r;
			}
	   
	   
	   
	   		//--------------------------------------------------------> right rotation
			Node *RightRotation(Node *y)
			{
				Node *x = y->left;      
				Node *z = x->right;        
		                        
				x->right = y;
				y->left = z; 
		
	    		y->height = max(heightFinder(y->left) , heightFinder(y->right)) + 1;
	    		x->height = max(heightFinder(x->left) , heightFinder(x->right)) + 1;
	
	    		return x;
			}
	 
	    	//----------------------------------------------------> left rotation
			Node *LeftRotation(Node *x)
			{
				
				Node *y = x->right; 
				Node *z = y->left;  
	 	                
				y->left = x;
				x->right = z;
		
	    		x->height = max(heightFinder(x->left) , heightFinder(x->right)) + 1;
	    		y->height = max(heightFinder(y->left) , heightFinder(y->right)) + 1;
	
	    		return y;
			} 
			
			
			//------------------------------------------------> Returns the min left node
			Node *min(Node *r)
			{
				if(r == 0)
				{
					return 0;
				}
				else if(r->left == 0)
				{
					return r;
				}
				else
				{
					return min(r->left);
				}	
			}
			
			
			//--------------------------------->Deletion like BST then update height for balancing the tree
	    	void deleteByUSERID(string val)
			{
				root = removebyID(val,root);	
			}
	   
			Node *removebyID(string val,Node *r)
			{
				Node *temp;
				if(r == 0)
				{
					return 0;
				}
				else if(val < r->userid)
				{
					r->left = removebyID(val,r->left);
				}
				else if(val > r->userid)
				{
					r->right = removebyID(val,r->right);
				}
				else if(r->left && r->right)
				{
					temp = min(r->right);
					r->userid = temp->userid;
					r->right = removebyID(r->userid, r->right);
				}
				else
				{
					cout<<"\n\n\t\t\tPatient Cases has been deleted "<<endl;
					temp = r;
					r->height = 1 + max(heightFinder(r->left),heightFinder(r->right));
					if(r->right == 0)
					{
						r = r->right;
					}
					else if(r->left == 0)
					{
						r = r->left;
					}
			
					delete temp;
				}
		
	
	    		int balancing_Factor = checkBalance(r);
				// Right rotation to be performed as nodes alligned to the left
	    		if (balancing_Factor > 1 && checkBalance(r->left) >= 0)
				{
	        		return RightRotation(r);
				}
			
				// Left rotation to be performed as nodes alligned to the right
	    		if (balancing_Factor < -1 && checkBalance(r->right) <= 0 )
				{
	        		return LeftRotation(r);
				}
	 
	    		// LR ROTATION
	    		if (balancing_Factor > 1 && checkBalance(r->left) < 0)
				{
	        		r->left = LeftRotation(r->left);
	        		return RightRotation(r);
				}
	 
	    		//  RL ROTATION
	    		if (balancing_Factor < -1 && checkBalance(r->right) > 0)
				{
					r->right = RightRotation(r->right);
	        		return LeftRotation(r);
				}
	
	    		return r;
			}
			
			
			//---------------------------------------------------------------------------------> deleytion end.	
			pass(string val) 
			{
				int i=0;
	    		char ch,st[21],ch1[21]={"janab"};
	    		cout<<"\n\n\n\n\n\n\t\t\t Enter Password : ";
	    		
	    		while(1)
	    		{
	    			ch=getch();
	    			if(ch==13)
	    			{
	        			st[i]='\0';
	        			break;
	    			}
	    			else if(ch==8&&i>0)
	    			{
	        			i--;
	        			cout<<"\b \b";
	    			}
	    			else
	    			{
	    				cout<<"*";
	    				st[i]=ch;
	    				i++;
	    			}
	    		}
	    		ifstream inf("password.txt");
	    		inf>>ch1;
	    		inf.close();
	    		for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
	    		if(st[i]=='\0'&&ch1[i]=='\0')
	    		{
	        		system("cls");
	        		deleteByUSERID(val);
	    		}
	    		else
	    		{
	        		cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
	        		getch();
	        		system("cls");
	        		pass(val);
	    		}
	    	}
    	
	    	passs() 
			{
				int i=0;
	    		char ch,st[21],ch1[21]={"janab"};
	    		cout<<"\n\n\n\n\n\n\t\t\t Enter Password : ";
	    		while(1)
	    		{
	    			ch=getch();
	    			if(ch==13)
	    			{
	        			st[i]='\0';
	        			break;
	    			}
	    			else if(ch==8&&i>0)
	    			{
	        			i--;
	        			cout<<"\b \b";
	    			}
	    			else
	    			{
	    				cout<<"*";
	    				st[i]=ch;
	    				i++;
	    			}
	    		}
	    		ifstream inf("password.txt");
	    		inf>>ch1;
	    		inf.close();
	    		for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
	    		if(st[i]=='\0'&&ch1[i]=='\0')
	    		{
	        		system("cls");
	        		string a,b,c,d,e,f,g,h,i,j;
	        		
	        		cout<<"\t\t\tEnter the user id: ";
	        		getline(cin,a);
	        		cout<<"\n\t\t\t\tEnter the patient name: ";
	        		getline(cin,b);
	        		cout<<"\n\t\t\tEnter the city: ";
	        		getline(cin,c);
	        		cout<<"\n\t\t\tEnter the hospital: ";
	        		getline(cin,d);
	        		cout<<"\n\t\t\tEnter the year: ";
	        		getline(cin,e);
	        		cout<<"\n\t\t\tEnter the cnic: ";
	        		getline(cin,f);
	        		cout<<"\n\t\t\t\tEnter the Age: ";
	        		getline(cin,g);
	        		cout<<"\n\t\t\tEnter the Report: ";
	        		getline(cin,h);
	        		cout<<"\n\t\t\tEnter the Doctor: ";
	        		getline(cin,i);
	        		cout<<"\n\t\t\tEnter the Result: ";
	        		getline(cin,j);
	        		
	        		//  write here  // zain 
					//	ofstream ip("covid_dataset.csv");
					//	ofstream ic("data1.csv");
					//	ofstream iz("overview.csv");
					//	iz>>j;
					root = insert(a,b,c,d,e,f,g,h,i,j, root);
					
	    		}
	    		else
	    		{
	        		cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
	        		getch();
	        		system("cls");
	        		passs();
	    		}
	    	}
	    	
	    	
	    	//Search in BST 
			void searchById(string val)
			{
				Node *temp = find(val,root);
	   	 		
				if(temp==NULL) 
				{
					cout<<"\t\t\tPatient Cases is not there! "<<endl;
					getchar();
					system ("CLS");
					return;
				}
				if(temp->userid == val){
				
					cout<<"\t\t\tID : "<<temp->userid<<endl;
					cout<<"\t\t\tPatient NAME : "<<temp->name<<endl;
					cout<<"\t\t\tCity : "<<temp->city<<endl;
					cout<<"\t\t\tHospital : "<<temp->hospital<<endl;
					cout<< "\t\t\tDate : " <<  temp->year<<endl;
					cout<< "\t\t\tCnic : " << temp->cnic <<endl;
					cout<< "\t\t\tAge : " << temp->age<<endl;
					cout<<"\t\t\tReport : "<<temp->report<<endl;
					cout<<"\t\t\tDoctor : "<<temp->doctor<<endl;
					cout<<"\n\t\t\t\t:Result : \t\t"<<temp->result<<endl<<endl;
				    getchar();
					system ("CLS");
				}
				else{
					cout<<"\t\t\tPatient Cases is not there! "<<endl;
					getchar();
					system ("CLS");
				}	
			}
	   
			void searchByname(string val)
			{		
	   	 
				stack<Node*> Stack;
				Node *temp=root;
				
				while(temp!=NULL || Stack.empty()==false) 
				{
					while(temp!=NULL) 
					{
						Stack.push(temp);
						temp=temp->left;
					}
					
					temp=Stack.top();
					Stack.pop();
					
					if(temp->name == val) 
					{
						break;
					}
					temp=temp->right;
				}
				
	   	 		
	   	 		if(temp==NULL) 
				{
	   	 			cout<<"\n\n\t\t\tPatient Cases is not present!/ "<<endl;
					getchar();
					system ("CLS");
					return;
				}
				if(temp->name == val)
				{
					cout<<"\t\t\tID: "<<temp->userid<<endl;
					cout<<"\t\t\tPatient NAME: "<<temp->name<<endl;
					cout<<"\t\t\tCity: "<<temp->city<<endl;
					cout<<"\t\t\tHospital: "<<temp->hospital<<endl;
					cout<< "\t\t\tDate: " <<  temp->year<<endl;
					cout<< "\t\t\tCnic: " << temp->cnic <<endl;
					cout<< "\t\t\tAge: " << temp->age<<endl;
					cout<<"\t\t\tReport: "<<temp->report<<endl;
					cout<<"\t\t\tDoctor: "<<temp->doctor<<endl;
					cout<<"\n\t\t\t\tResult:\t\t"<<temp->result<<endl<<endl;
					getchar();
					system ("CLS");
				}
				else
				{
					cout<<"\n\n\t\t\tPatient Cases is not present!/ "<<endl;
					getchar();
					system ("CLS");
				}	
			}
			
			Node *find(string val, Node *r)
			{
				if(r == 0){
					return 0;
				}
				else if(val < r->userid){
					return find(val,r->left);
				}
				else if(val > r->userid){
					return find(val,r->right);
				}
				return r;	  
			}
			
			void cityInorder(Node *r,string x)
			{
				if(r == 0)
				{
					return;
				}
				
				
				if(r->city == x){
	    	
				cout<<"\t\t\tID : "<<r->userid<<endl;
				cout<<"\t\t\tPatient NAME : "<<r->name<<endl;
				cout<<"\t\t\tCity : "<<r->city<<endl;
				cout<<"\t\t\tHospital : "<<r->hospital<<endl;
				cout<< "\t\t\tDate : " <<  r->year<<endl;
				cout<< "\t\t\tCnic : " << r->cnic <<endl;
				cout<< "\t\t\tAge : " << r->age<<endl;
				cout<<"\t\t\tReport : "<<r->report<<endl;
				cout<<"\t\t\tDoctor : "<<r->doctor<<endl;
				cout<<"\n\t\t\t\tResult : \t\t"<<r->result<<endl<<endl;
				}   
				cityInorder(r->left,x);
				cityInorder(r->right,x);   
			}
			
			void displayCovidCity()
			{
				cout<<"\n\n\t\t\tCovid Cases Cities:  "<<endl;
				string x;
				cout<<"Enter City : ";
				cin>>x;
				cityInorder(root,x);
				getchar();
				cout<<endl<<endl;
			}
			
			void hospitalInorder(string a,Node *r)
			{
				if(r == 0){
					return;
				}
		
				if(r->hospital == a){
				cout<<"\t\t\tID : "<<r->userid<<endl;
				cout<<"\t\t\tPatient NAME : "<<r->name<<endl;
				cout<<"\t\t\tCity : "<<r->city<<endl;
				cout<<"\t\t\tHospital : "<<r->hospital<<endl;
				cout<< "\t\t\tDate : " <<  r->year<<endl;
				cout<< "\t\t\tCnic : " << r->cnic <<endl;
				cout<< "\t\t\tAge : " << r->age<<endl;
				cout<<"\t\t\tReport : "<<r->report<<endl;
				cout<<"\t\t\tDoctor : "<<r->doctor<<endl;
				cout<<"\n\t\t\t\tResult : \t\t"<<r->result<<endl<<endl;
				
				}   
				hospitalInorder(a,r->left);
				hospitalInorder(a,r->right);   
			} 
	  
	    	void displayHospital(string a)
			{
	    		cout<<"\n\n\t\t\tHospital : "<<endl;
				hospitalInorder(a,root);
				getchar();
				system ("CLS");
				cout<<endl<<endl;
			}
			
			void searchByAge(string val)
			{
				ByAge(val,root);
				getchar();
				system ("CLS");
				cout<<endl<<endl;
			}
	   
			void ByAge(string a,Node *r)
			{
				if(r == 0)
				{
					return;
				}
				if(r->age == a)
				{
	    			cout<<"\t\t\tID : "<<r->userid<<endl;
					cout<<"\t\t\tPatient NAME : "<<r->name<<endl;
					cout<<"\t\t\tCity : "<<r->city<<endl;
					cout<<"\t\t\tHospital : "<<r->hospital<<endl;
					cout<< "\t\t\tDate : " <<  r->year<<endl;
					cout<< "\t\t\tCnic : " << r->cnic <<endl;
					cout<< "\t\t\tAge : " << r->age<<endl;
					cout<<"\t\t\tReport : "<<r->report<<endl;
					cout<<"\t\t\tDoctor : "<<r->doctor<<endl;
					cout<<"\n\t\t\t\tResult : \t\t"<<r->result<<endl<<endl;
				}   
				ByAge(a,r->left);
				ByAge(a,r->right);   
			} 
			
			void searchbyDate(string d) 
			{
				cout << "\n\n\t\t\tCovid Test date " << d << " are: \n\n";
				inorderByDate(d,root);
				getchar();
				system ("CLS");
				cout << endl<< endl;  
			}
			
			void inorderByDate(string a,Node *r)
			{
				if(r == 0){
					return;
				}
		
				if(r->year == a)
				{
	    			cout<<"\t\t\tID : "<<r->userid<<endl;
					cout<<"\t\t\tPatient NAME : "<<r->name<<endl;
					cout<<"\t\t\tCity : "<<r->city<<endl;
					cout<<"\t\t\tHospital : "<<r->hospital<<endl;
					cout<< "\t\t\tDate : " <<  r->year<<endl;
					cout<< "\t\t\tCnic : " << r->cnic <<endl;
					cout<< "\t\t\tAge : " << r->age<<endl;
					cout<<"\t\t\tReport : "<<r->report<<endl;
					cout<<"\t\t\tDoctor : "<<r->doctor<<endl;
					cout<<"\n\t\t\tResult : \t\t"<<r->result<<endl<<endl;
				}   
				inorderByDate(a,r->left);
				inorderByDate(a,r->right);   
			}
			
			void searchByResult(string val)
			{
				stack<Node*> Stack;
				Node *temp=root;
				
				while(temp!=NULL || Stack.empty()==false) 
				{
					while(temp!=NULL) 
					{
						Stack.push(temp);
						temp=temp->left;
					}
					
					temp=Stack.top();
					Stack.pop();
					
					if(temp->result ==val) {
						break;
					}
					temp=temp->right;
				}
				
				if(temp==NULL) 
				{
					cout << "\n\n\t\t\tPatient Cases Donot Exist!\n";
					getchar();
				    system ("CLS");
					return;
				}
				if(temp->result == val){
						cout<<"\t\t\tID : "<<temp->userid<<endl;
						cout<<"\t\t\tPatient NAME : "<<temp->name<<endl;
						cout<<"\t\t\tCity : "<<temp->city<<endl;
						cout<<"\t\t\tHospital : "<<temp->hospital<<endl;
						cout<< "\t\t\tDate : " <<temp->year<<endl;
						cout<< "\t\t\tCnic : " << temp->cnic <<endl;
						cout<< "\t\t\tAge : " << temp->age<<endl;
						cout<<"\t\t\tReport : "<<temp->report<<endl;
						cout<<"\t\t\tDoctor : "<<temp->doctor<<endl;
						cout<<"\n\t\t\t\tResult : \t\t"<<temp->result<<endl<<endl;
				
					getchar();
					system ("CLS");
				}
				else{
					cout<<"\n\n\t\t\t\t\tNode is not there "<<endl;
					
					getchar();
					system ("CLS");
				}	
			}
			
			void inorder(Node *r)
			{
				if(r == 0){
					return;
				}
		   
				inorder(r->left);
			
	    		cout<<"\t\t\tID : "<<r->userid<<endl;
				cout<<"\t\t\tPatient NAME : "<<r->name<<endl;
				cout<<"\t\t\tCity : "<<r->city<<endl;
				cout<<"\t\t\tHospital : "<<r->hospital<<endl;
				cout<< "\t\t\tDate : " <<  r->year<<endl;
				cout<< "\t\t\tCnic : " << r->cnic <<endl;
				cout<< "\t\t\tAge : " << r->age<<endl;
				cout<<"\t\t\tReport : "<<r->report<<endl;
				cout<<"\t\t\tDoctor : "<<r->doctor<<endl;
				cout<<"\n\t\t\t\tResult : \t\t"<<r->result<<endl<<endl;
				
				inorder(r->right);   
			}
			// ----------------------------------------------------------------------------------------------------------
			
			
				void hospitalPositiveCasesInorder(string a,Node *r)
			{
				if(r == 0){
					return;
				}
		
				if(r->hospital == a && r->report == "positive"){
				cout<<"\t\t\tID : "<<r->userid<<endl;
				cout<<"\t\t\tPatient NAME : "<<r->name<<endl;
				cout<<"\t\t\tCity : "<<r->city<<endl;
				cout<<"\t\t\tHospital : "<<r->hospital<<endl;
				cout<< "\t\t\tDate : " <<  r->year<<endl;
				cout<< "\t\t\tCnic : " << r->cnic <<endl;
				cout<< "\t\t\tAge : " << r->age<<endl;
				cout<<"\t\t\tReport : "<<r->report<<endl;
				cout<<"\t\t\tDoctor : "<<r->doctor<<endl;
				cout<<"\n\t\t\t\tResult : \t\t"<<r->result<<endl<<endl;
				
				}   
				hospitalPositiveCasesInorder(a,r->left);
				hospitalPositiveCasesInorder(a,r->right);   
			} 
	  
	    	void displayPositiveCasesHospital(string a)
			{
	    		cout<<"\n\n\t\t\tHospital : "<<endl;
				hospitalPositiveCasesInorder(a,root);
				getchar();
				system ("CLS");
				cout<<endl<<endl;
			}
			
			// ----------------------------------------------------------------------------------------------------------
			void display()
			{
	    		cout<<"\n\t\t\tDisplay All Data: "<<endl;
				inorder(root);
				getchar();
				cout<<endl<<endl;
			}
			void searchReport(string val) 
			{
				reportInorder(val,root);
				getchar();
			}
		
			void reportInorder(string val,Node *r){
				if(r == 0){
					return;
				}
				
				reportInorder(val,r->left);
				
				if(r->hospital==val) 
				{
					if(r->report == "postive")
					{
	    				cout<<"\t\t\tID : "<<r->userid<<endl;
						cout<<"\t\t\tPatient NAME : "<<r->name<<endl;
						cout<<"\t\t\tCity : "<<r->city<<endl;
						cout<<"\t\t\tHospital : "<<r->hospital<<endl;
						cout<< "\t\t\tDate : " <<  r->year<<endl;
						cout<< "\t\t\tCnic : " << r->cnic <<endl;
						cout<< "\t\t\tAge : " << r->age<<endl;
						cout<<"\t\t\tReport : "<<r->report<<endl;
						cout<<"\t\t\tDoctor : "<<r->doctor<<endl;
						cout<<"\n\t\t\t\t:Result : \t\t"<<r->result<<endl<<endl;
					}
				}  
				 
				reportInorder(val,r->right);  
			}
	
};


int main()
{
	system("color F1");
	display();
	Covid data;
	int c=0, opt=0;
	
	ifstream ip("covid_dataset.csv");
	ifstream ic("data1.csv");
	ifstream iz("overview.csv");
	
	if(!ip.is_open() || !ic.is_open() || !iz.is_open()) {
		cout << "\n\n\t\t\terror file open!" << endl;
	}

	string userid, name, city, hospital, year, cnic, age, report, result, doctor;
	
	while(ip.good() && ic.good() && iz.good()) 
	{
		c++;
		getline(ip,userid,',');
		getline(ip,name,',');
		getline(ip,cnic,',');
		getline(ip,age,',');
		getline(ip,report,'\n');
		// data1
		getline(ic,year,',');
		getline(ic,city,',');
		getline(ic,hospital,',');
		getline(ic,doctor,'\n');
		// overview
		getline(iz,result,'\n');
		
		data.insert(userid, name, city, hospital, year, cnic, age, report,  doctor, result);
		if(	c==1999 ) 
		{
			break;
	    }
	}	

	ip.close();
	ic.close();
	iz.close();
	
	while(1) 
	{
		cout<<"\n\t\t----------------------------------------------\n\n";
		cout << endl << "\t\t\t\t~MENU~" << endl << endl;
		cout<<"\n\t\t----------------------------------------------\n\n";

		cout << "\t\t\t1. Search by Patient ID.\n" << endl;
		cout << "\t\t\t2. Search by Patient Name.\n" << endl;
		cout << "\t\t\t3. Search by Covid Date.\n" << endl;
		cout << "\t\t\t4. Search by Age.\n" << endl;
		cout << "\t\t\t5. Search Top Cities Covid Cases.\n" << endl;
		cout << "\t\t\t6. Search by Hospital.\n" << endl;
		cout << "\t\t\t7. Search each Hospital Positive Cases.\n" << endl;
		cout << "\t\t\t8. Display all Covid Cases.\n" << endl;
		cout << "\t\t\t9. Add Covid Case by Patient ID.\n" << endl;
		cout << "\t\t\t11.Delete each Covid Case by Patient ID.\n" << endl;
		cout << "\t\t\t11.Close Application.\n" << endl;
		cout << "\t\t\tEnter any option number: ";
		cin >> opt;
		cout << "\n\t\t\t\t\t";

		system ("CLS");
		
		switch(opt) {
			case 1:
				cout << "\n\n\n\n\t\t\t\t\tEnter the Patient ID: ";
				getchar();
				getline(cin,userid);
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				data.searchById(userid);
				break;
				
			case 2:
				cout << "\n\n\n\n\t\t\t\t\tEnter the Patient Name: ";
				getchar();
				getline(cin,name);
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				data.searchByname(name);
				break;
				
			case 3:
				cout << "\n\n\n\n\t\t\t\t\tEnter Covid Test Date: ";
				getchar();
				getline(cin,year);
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				data.searchbyDate(year);
				break;	
						
			
			case 4:
				cout << "\n\n\n\n\t\t\t\t\tEnter Age: ";
				getchar();
				getline(cin,age);
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				data.searchByAge(age);
				break;
						
			case 5:
				data.displayCovidCity();
				getchar();
			    cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				break;
			
			case 6:
				cout << "\n\n\n\n\t\t\t\t\tEnter Hospital For All Cases: ";
				getchar();
				getline(cin,hospital);
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				data.displayHospital(hospital);
				break;
				
			case 7:
				cout << "\n\n\n\n\t\t\t\t\tEnter Hospital For Postive Cases: ";
				getchar();
				getline(cin,hospital);
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				data.displayPositiveCasesHospital(hospital);
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				break;
				
			case 8:
				cout << "\n\n\n\n\t\t\t\t\tList of all Cases: " << endl;
				data.display();
				getchar();
			    cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				break;
			
			
			case 9:
				cout << "\n\n\n\n\t\t\t\t\tEnter the data for Covid Case addition: ";
				getchar();
				system ("CLS");
				data.passs();
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				break;	
				
					
			case 10:
				cout << "\n\n\n\n\t\t\t\t\tEnter the Patient ID for deletion: ";
				getchar();
				getline(cin,userid);
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				data.pass(userid);
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
				break;	
					
				
			case 11:
				cout << "\n\n\n\n\t\t\t\t\tClosing Application...";
				cout <<"\n\n\n\n\t\t\t\t\tThank You.";
				exit(0);
				break;		
			
			default:
				cout << "\n\n\n\n\t\t\t\t\tEnter valid Option!."<<endl;
				getchar();
				getchar();
				cout << "\n\t\t\t\t\t";
				system("pause");
				system ("CLS");
			    						
		}
	}
    
	return 0;
}
