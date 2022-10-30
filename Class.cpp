/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Programmer: OSAMA MALIK                      Reg No~ 4319-FBAS-BSSE/F21                        Project: Student Data Base  /////
Teacher Name: Sir NADEEM                     **************************                        Date: 10-18-2022            /////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#define MAX 70
using namespace std;

struct myDate
{
	unsigned int dd, mm, yy;
};

void Abc()      //Headings
{
	cout << ""
	     << "RegNo\t\t"
	     << "Name\t\t"
		 << "Father Name\t"
		 << "CGpa\t"
		 << "DOA\t\t"
		 << "DOB\n";
}

class Student
{
	string RegNum, name, Fname;
	unsigned int Cgpa, Num;
	myDate doa, dob;
public:
	Student(int c = 0, int n = 0) : Cgpa(c), Num(n) {}   //constructor
	void create();   //Create database
	bool search(string rn);      //Helping Function to check Reg Num are matched or not
	void update(); //To update student data except reg N but if we want to update whole so no need of this function and call create in case update 
	void display();
};

void Student::create(){   //Create database      
	cin.ignore(50, '\n');
	cout << "Enter the Registration number(in XXXX-bsse/fXX format): ";
	getline(cin, RegNum);
	cout << "Enter the Name: ";
	getline(cin, name);
	cout << "Enter the Father Name: ";
	getline(cin, Fname);
	do{
	cout << "Enter the CGpa(0-4): ";
	cin >> Cgpa;
	} 
	while (!((Cgpa>0) && (Cgpa<=4)));
	cout << "Date of Admission\n";
	do{
		cout<< "Day(1-31): ";
	cin >> doa.dd;
	} 
	while (!((doa.dd>0) && (doa.dd<32)));
	do{
	cout << "Month(1-12): ";
	cin >> doa.mm;
	}
	while (!((doa.mm>0) && (doa.mm<13)));
	do{
	cout << "Year(1990-2022): ";
	cin >> doa.yy;
	}
	while (!((doa.yy>=1990) && (doa.yy<=2022)));
	cout << "Date of Birth\n";
	do{
		cout<< "Day(1-31): ";
	cin >> dob.dd;
	} 
	while (!((dob.dd>0) && (dob.dd<32)));
	do{
	cout << "Month(1-12): ";
	cin >> dob.mm;
	}
	while (!((dob.mm>0) && (dob.mm<13)));
	do{
	cout << "Year(1990-2022): ";
	cin >> dob.yy;
	}
	while (!((dob.yy>=1990) && (dob.yy<=2022)));
	cout << "\t\t saved...\n\n";
}
bool Student::search(string rn)               //Search the data	  
{   
	if (RegNum == rn)
		return true;
	else
		return false;
}

void Student::update()             //To update any student data
{   
		cin.ignore(50,'\n');
	    cout << "Name: ";
		getline(cin, name);
		cout << "Father's name: ";
		getline(cin, Fname);
		do{
		cout << "Enter the CGpa(0-4): ";
		cin >> Cgpa;
		}
		while (!((Cgpa>0) && (Cgpa<=4)));
		cout << "\t\tUpdated...!\n\n";
}

void Student::display() 
{
	cout << RegNum << "\t"      
		<< name << "\t"
		<< Fname << "\t"
		<< Cgpa << "\t"
		<< doa.dd << "/"
		<< doa.mm << "/"
		<< doa.yy << "\t"
		<< dob.dd << "/"
		<< dob.mm << "/"
		<< dob.yy << "\n";
}

//User Define Functions for Search and Delete && not a member function of the above class

int sch(Student SE[], string rn, int &Num)      //Search Function && rn position
{
	int i;
		int flag=-1;
		for (i=0; i<Num; i++)
		{
			flag=SE[i].search(rn);
		    if(flag==true)
			return i;
		}
		  return -1;
}
void mydelete(Student SE[], int pos, int& Num)
{
		for (int j = pos; j < Num-1 ; j++)
		SE[j] = SE[j + 1];
	    Num--;
}

int main() {
	int Num, i = 0;
	string rno;
	int pos;
	Student SE[MAX];
	char ch = 0;
	do {
		cout << "\t\t\t\t\t\t************************\n"
			 << "\t\t\t\t\t\t*      Main Menu       *\n"
			 << "\t\t\t\t\t\t************************\n"
			 << "\t\t\t\t\t\t|1. Create Database    |\n"
			 << "\t\t\t\t\t\t|2. Append data        |\n"
			 << "\t\t\t\t\t\t|3. Update the Data    |\n"
			 << "\t\t\t\t\t\t|4. Search the Data    |\n"
			 << "\t\t\t\t\t\t|5. Delete the Data    |\n"
			 << "\t\t\t\t\t\t|6. Display the Data   |\n"
			 << "\t\t\t\t\t\t|7. Exit               |\n"
             << "\t\t\t\t\t\t|______________________|\n";		 
		cout << "Select an option: ";
		cin >> ch;
		switch (ch)
		{
		case '1':      //Read Data
			do{
			cout << "How many students you want to Enter(1-70): ";
			cin >> Num;
			}
			while (!((Num > 0) && (Num < 71)));
				for (i = 0; i < Num; i++)
					SE[i].create();
			break;
		case '2':                   //Append
			SE[Num].create();
			Num++;
			break;
		case '3':                   //Update
			cout<<"Enter the Registration number: ";
			cin >> rno; 
			pos = sch(SE, rno, Num);
			if(pos==-1)
				cout<<"\t\tNot Found..!"<<endl;
			else
			{ 
					Abc();
					SE[pos].display();
					SE[pos].update();
			}
			system("pause");
			break;
		case '4':                   //Search 
			cout<<"Enter the Registration number: ";
			cin >> rno; 
			pos = sch(SE, rno, Num);
			if(pos==-1)
				cout<<"\t\tNot Found...!"<<endl;
			else
			{
					Abc();
					SE[pos].display();
			}
			system("pause");
			break;
		case '5':                   //Delete any Data
			cout<<"Enter the Registration number: ";
			cin >> rno;
			pos = sch(SE, rno, Num);
			if(pos==-1)
				cout<<"\t\tNot Found...!"<<endl;
			else
			{
				mydelete(SE, pos, Num);
				cout<< "\t\tDeleted...!"<<endl;
			}
			system("pause");
			break;
		case '6':                        //Display the data   //per screen 25 se zyada data nhi hona chahiye so use system pause after 25 
			cout << "\n"                                      //and then continue
				<< "Sr.  ";
				Abc();        //Headings

			for (int i = 0; i < Num; i++) 
			{
				cout << i + 1 << "    ";
				SE[i].display();
			}
			system("pause");
			break;
		case '7':
			exit(0);
			
		default:
			cout << "\t\tInvalid Option...!\n";
		}system("cls");
	} while (true);
	return 0;
}