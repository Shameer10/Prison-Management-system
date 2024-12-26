#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;


struct Prisoner
{
	int ID;
	string Name;
	string Crime;
	int Sentence_Duration;
	int Security_Level;
	string Cell_Assigned;
};
const int Max_Prisoner = 50;
Prisoner P_record[Max_Prisoner];
int NoPrisoner = 0;

struct Visitor
{
	string Name;
	int P_ID;
	string Relation;
	string Visit_Date;
};
const int Max_Visitor = 50;
Visitor V_record[Max_Visitor];
int NoVisitor = 0;

struct struct_login
{
	string Username;
	string Password;
};

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void About() {
	int input;
	string APP;
	string READ;

	fstream about;
	system("cls");

	cout << "Press 1 to add something to the file\n";
	cout << "Press 2 to read and display the file\n";
	cin >> input;
	cin.ignore();

	if (input == 1) {
		about.open("About.txt", ios::out | ios::app);
		if (about.is_open()) {
			cout << "Enter a sentence to add to the file:\n";
			getline(cin, APP);
			about << APP << endl;
			about.close();
			cout << "Content added successfully!\n";
		}
		else {
			cout << "Unable to open the file for writing.\n";
		}
	}
	else if (input == 2) {
		about.open("About.txt", ios::in);
		if (about.is_open()) {
			cout << "File contents:\n";
			while (getline(about, READ)) {
				cout << READ << endl;
			}
			about.close();
		}
		else {
			cout << "Unable to open the file for reading.\n";
		}
	}
	else {
		cout << "Invalid input.\n";
	}
}

//Title
void PrintHeading() {
	cout << "\t\t\t\t************************************************************" << endl;
	cout << "\t\t\t\t*                                                          *" << endl;
	cout << "\t\t\t\t*                PPPPPP     M     M    SSSSS               *" << endl;
	cout << "\t\t\t\t*                P     P    MM   MM   S     S              *" << endl;
	cout << "\t\t\t\t*                PPPPPP     M M M M   S                    *" << endl;
	cout << "\t\t\t\t*                P          M  M  M    SSSSS               *" << endl;
	cout << "\t\t\t\t*                P          M     M         S              *" << endl;
	cout << "\t\t\t\t*                P          M     M   S     S              *" << endl;
	cout << "\t\t\t\t*                P          M     M    SSSSS               *" << endl;
	cout << "\t\t\t\t*                                                          *" << endl;
	cout << "\t\t\t\t************************************************************" << endl << endl;
	cout << "\t\t\t\t                  Prison Management System                  " ;
}

//Writing data from P_record to Prisoner file
void PFileAPP()
{
	fstream Pfile("Prisoner.txt", ios::out);
	int count = 0;
	if (Pfile.is_open())
	{
		while (count < NoPrisoner - 1)
		{
			Pfile << P_record[count].ID << endl;
			Pfile << P_record[count].Name << endl;
			Pfile << P_record[count].Crime << endl;
			Pfile << P_record[count].Sentence_Duration << endl;
			Pfile << P_record[count].Security_Level << endl;
			Pfile << P_record[count].Cell_Assigned << endl;
			count++;
		}
	}
	else
	{
		cout << "Cannot open file";
	}
	Pfile.close();
}

//Reading data from P_record to Prisoner file
void PFileREAD()
{
	fstream Pfile("Prisoner.txt",ios::in);
	
	if (Pfile.is_open())
	{
		while (NoPrisoner < Max_Prisoner && Pfile.good())
		{
			
			Pfile >> P_record[NoPrisoner].ID;
			Pfile >> P_record[NoPrisoner].Name;
			Pfile >> P_record[NoPrisoner].Crime;
			Pfile >> P_record[NoPrisoner].Sentence_Duration;
			Pfile >> P_record[NoPrisoner].Security_Level;
			Pfile.ignore();
			getline(Pfile, P_record[NoPrisoner].Cell_Assigned);
			NoPrisoner++;
		}
		Pfile.close();
	}
	else
	{
		cout << "Cannot open file";
	}
	
}

//Searching ID from P_record and outputting the whole record
void SearchPrisoner()
{
	system("cls");
	int IDSearch;
	cout << "Enter ID of the prisoner : ";
	cin >> IDSearch;
	bool found = false;
	do
	{
		for (int i = 0; i < NoPrisoner; i++)
		{
			if (IDSearch == P_record[i].ID)
			{
				cout << "Name\t\tCrime\t\tDuration\tSec. Level\tCell assigned\n";
				cout << P_record[i].Name << "\t\t" << P_record[i].Crime << "\t\t" << P_record[i].Sentence_Duration << "\t\t";
				cout << P_record[i].Security_Level << "\t\t" << P_record[i].Cell_Assigned << "\t\t" << endl;
				found = true;
			}
		}
		if (found)
		{
			break;
		}
		cout << "Invalid ID!!\n";
		cout << "Enter ID of the prisoner : ";
		cin >> IDSearch;
	} while (true);
}

//Adding a prisoner to P_record
void AddPrisoner()
{
	system("cls");
	char choice;
	int max = P_record[0].ID;
	do {
		for (int i = 0; i < NoPrisoner; i++)
		{
			if (max < P_record[i].ID)
			{
				max = P_record[i].ID;
			}
		}
		P_record[NoPrisoner - 1].ID = max + 1;
		cout << "Enter prisoner name : ";
		cin >> P_record[NoPrisoner - 1].Name;
		cout << "Enter prisoner Crime : ";
		cin >> P_record[NoPrisoner - 1].Crime;
		cout << "Enter prisoner Sentence Duration : ";
		cin >> P_record[NoPrisoner - 1].Sentence_Duration;
		cout << "Enter prisoner Security Level : ";
		cin >> P_record[NoPrisoner - 1].Security_Level;
		if (P_record[NoPrisoner - 1].Security_Level == 3) {
			P_record[NoPrisoner - 1].Cell_Assigned = "Solitary Confinement";
		}
		else if (P_record[NoPrisoner - 1].Security_Level == 2) {
			P_record[NoPrisoner - 1].Cell_Assigned = "Restricted Custody";
		}
		else if (P_record[NoPrisoner - 1].Security_Level == 1) {
			P_record[NoPrisoner - 1].Cell_Assigned = "Open Custody";
		}

		cout << "\nDo u want to add another prisoner?( y / n ) : ";
		cin >> choice;
		NoPrisoner++;
	} while (choice == 'y');

}

//Deleting Prisoner record from P_record
void DeletePrisoner()
{
	system("cls");
	int IDSearch;
	char choice;
	do
	{
		cout << "Enter ID of the prisoner : ";
		cin >> IDSearch;

		for (int i = 0; i < NoPrisoner - 1; i++)
		{
			if (IDSearch == P_record[i].ID)
			{
				for (int j = i; j < NoPrisoner; j++)
				{
					P_record[j].ID = P_record[j + 1].ID;
					P_record[j].Name = P_record[j + 1].Name;
					P_record[j].Crime = P_record[j + 1].Crime;
					P_record[j].Sentence_Duration = P_record[j + 1].Sentence_Duration;
					P_record[j].Security_Level = P_record[j + 1].Security_Level;
					P_record[j].Cell_Assigned = P_record[j + 1].Cell_Assigned;
				}
				NoPrisoner--;
				break;
			}
		}
		cout << "\nDo u want to delete another prisoner?( y / n) : ";
		cin >> choice;

	} while (choice == 'y');
}

//Searching ID and then updating the Name, crime, sentence duration, or security level
void UpdatePrisoner()
{
	system("cls");
	int IDSearch;
	cout << "Enter ID of the prisoner : ";
	cin >> IDSearch;
	int num;
	for (int i = 0; i < NoPrisoner - 1; i++)
	{
		if (IDSearch == P_record[i].ID)
		{
			cout << "Enter 1 to change Name\n";
			cout << "Enter 2 to change Crime\n";
			cout << "Enter 3 to change Sentence Duration\n";
			cout << "Enter 4 to change Security level\n";
			cin >> num;
			
			switch (num)
			{
			case 1: {
					cout << "Enter the new name : ";
					cin >> P_record[i].Name;
					break;
					}
			case 2: {
				cout << "Enter the new Crime (Assault\tMurder\tCyber\tRobbery\tFraud): ";
				cin >> P_record[i].Crime;
				break;
			}
			case 3: {
				cout << "Enter the new Sentence duration : ";
				cin >> P_record[i].Sentence_Duration;
				break;
			}
			case 4: {
				cout << "Enter the new Security level : ";
				cin >> P_record[i].Security_Level;
				if (P_record[i].Security_Level == 3) {
					P_record[i].Cell_Assigned = "Solitary Confinement";
				}
				else if (P_record[i].Security_Level == 2) {
					P_record[i].Cell_Assigned = "Restricted Custody";
				}
				else if (P_record[i].Security_Level == 1) {
					P_record[i].Cell_Assigned = "Open Custody";
				}
				break;
			}
			}

		}
	}
}

//Writing data from V_record to Visitors file
void VFileAPP()
{
	fstream Vfile("Visitors.txt", ios::out);

	int count = 0;
	if (Vfile.is_open())
	{
		while (count < NoVisitor - 1)
		{
			Vfile << V_record[count].Name << endl;
			Vfile << V_record[count].P_ID << endl;
			Vfile << V_record[count].Relation << endl;
			Vfile << V_record[count].Visit_Date << endl;
			count++;
		}

	}
	else
	{
		cout << "Cannot open file";
	}
	Vfile.close();
}

//Reading data from P_record to Prisoner file
void VFileREAD()
{
	fstream Vfile("Visitors.txt", ios::in);

	if (Vfile.is_open())
	{
		while (NoVisitor < Max_Visitor && Vfile.good())
		{

			Vfile >> V_record[NoVisitor].Name;
			Vfile >> V_record[NoVisitor].P_ID;
			Vfile >> V_record[NoVisitor].Relation;
			Vfile >> V_record[NoVisitor].Visit_Date;
			NoVisitor++;
		}
		Vfile.close();
	}
	else
	{
		cout << "Cannot open file";
	}
}

//Adding a Visitor to V_record
void AddVisitor()
{
	system("cls");
	char choice;
	int ID;
	bool found = false;
	do {
		cout << "Enter Prisoner ID : ";
		cin >> ID;
		while (true)
		{
			for (int i = 0; i < NoPrisoner - 1; i++)
			{
				if (ID == P_record[i].ID)
				{
					found = true;
					break;
				}
			}
			if (found == true)
			{
				V_record[NoVisitor -1].P_ID = ID;
				break;
			}
			
			cout << "Invalid ID enter correct ID or -1 to leave : ";
			cin >> ID;
			if (ID == -1)
			{
				break;
			}
		}
		if (ID == -1)
		{
			break;
		}
		cout << "Enter Visitor name : ";
		cin >> V_record[NoVisitor - 1].Name;
		cout << "Enter relationship with prisoner : ";
		cin >> V_record[NoVisitor - 1].Relation;
		cout << "Enter date dd/mm/yyyy : ";
		cin >> V_record[NoVisitor - 1].Visit_Date;
		cout << "\nDo you want to add another Visitor?( y / n ) : ";
		cin >> choice;
		NoVisitor++;
	} while (choice == 'y');
}

//Generate Reports
void Report()
{
	system("cls");
	int num;

	cout << "What type of prisoner report you want to generate\n";
	cout << "Press 1 for type of crime\n";
	cout << "Press 2 for Sentence Duration\n";
	cout << "Press 3 for type of security level\n";
	cin >> num;

	int choiceint;
	string choicestring;
	bool greater;
	switch (num)
	{
	case 1: cout << "Enter the type of crime(Assault\tMurder\tCyber\tRobbery\tFraud) : ";
		cin >> choicestring;
		cout << "*****************************************************************************************************\n";
		cout << "ID\t\tName\t\tCrime\t\tDuration\tSec. Level\tCell assigned\n";
		for (int i = 0; i < NoPrisoner -1 ; i++)
		{
			if(choicestring == P_record[i].Crime)
			cout << P_record[i].ID << "\t\t" << P_record[i].Name << "\t\t" << P_record[i].Crime << "\t\t" << P_record[i].Sentence_Duration << "\t\t" << P_record[i].Security_Level << "\t\t" << P_record[i].Cell_Assigned << endl;
		}
		cout << "*****************************************************************************************************\n";
		break;
	case 2:cout << "Enter Sentence duration condition\n";
		int year;
		cout << "Greater or Less : \n";
		cin >> choicestring;
		if (choicestring == "Greater")
		{
			greater = true;
			cout << "Enter year to be greater of : ";
			cin >> year;
			cout << "*****************************************************************************************************\n";
			cout << "ID\t\tName\t\tCrime\t\tDuration\tSec. Level\tCell assigned\n";
			for (int i = 0; i < NoPrisoner -1; i++)
			{
				if (P_record[i].Sentence_Duration > year)
				{
					cout << P_record[i].ID << "\t\t" << P_record[i].Name << "\t\t" << P_record[i].Crime << "\t\t" << P_record[i].Sentence_Duration << "\t\t" << P_record[i].Security_Level << "\t\t" << P_record[i].Cell_Assigned << endl;
				}
			}
			cout << "*****************************************************************************************************\n";
		}
		else if (choicestring == "Less")
		{
			greater = false;
			cout << "Enter year to be Less of : ";
			cin >> year;
			cout << "*****************************************************************************************************\n";
			cout << "ID\t\tName\t\tCrime\t\tDuration\tSec. Level\tCell assigned\n";
			for (int i = 0; i < NoPrisoner -1; i++)
			{
				if (P_record[i].Sentence_Duration < year)
				{
					cout << P_record[i].ID << "\t\t" << P_record[i].Name << "\t\t" << P_record[i].Crime << "\t\t" << P_record[i].Sentence_Duration << "\t\t" << P_record[i].Security_Level << "\t\t" << P_record[i].Cell_Assigned << endl;
				}
			}
			cout << "*****************************************************************************************************\n";
		}
		else
		{
			cout << "Invalid data";
		}
		break;
	case 3:cout << "Enter Security level : ";
		cin >> choiceint;
		cout << "*****************************************************************************************************\n";
		cout << "ID\t\tName\t\tCrime\t\tDuration\tSec. Level\tCell assigned\n";
		for (int i = 0; i < NoPrisoner -1; i++)
		{
			if (P_record[i].Security_Level == choiceint )
			{
				cout << P_record[i].ID << "\t\t" << P_record[i].Name << "\t\t" << P_record[i].Crime << "\t\t" << P_record[i].Sentence_Duration << "\t\t" << P_record[i].Security_Level << "\t\t" << P_record[i].Cell_Assigned << endl;
			}
		}
		cout << "*****************************************************************************************************\n";
		break;
	default:cout << "Invalid input";
	}
}

//Display all visitors
void DisplayVisitor()
{
	system("cls");
	cout << "**********************************************************\n";
	cout << "Name\t\tP_ID\t\tRelation\tVisit date\n";
	for (int i = 0; i < NoVisitor - 1; i++)
	{
		cout << V_record[i].Name << "\t\t" << V_record[i].P_ID << "\t\t" << V_record[i].Relation << "\t\t" << V_record[i].Visit_Date << endl;
	}
	cout << "**********************************************************\n";
}

//Display all prisoners
void DisplayPrisoner()
{
	system("cls");
	cout << "*****************************************************************************************************\n";
	cout << "ID\t\tName\t\tCrime\t\tDuration\tSec. Level\tCell assigned\n";
	for (int i = 0; i < NoPrisoner - 1; i++)
	{
		cout << P_record[i].ID << "\t\t" << P_record[i].Name << "\t\t" << P_record[i].Crime << "\t\t" << P_record[i].Sentence_Duration << "\t\t" << P_record[i].Security_Level << "\t\t" << P_record[i].Cell_Assigned << endl;
	}
	cout << "*****************************************************************************************************\n";
}

//Logged in as admin
void Admin()
{
	PFileREAD();
	char choice;
	int num;
	do {
		system("cls");

		cout << "Press 1 to Search for prisoner\n";
		cout << "Press 2 to add prisoner\n";
		cout << "Press 3 to delete prisoner\n";
		cout << "Press 4 to update prisoner\n";
		cout << "Press 5 to veiw all prisoners\n";
		cout << "Press 6 to generate report\n";
		cout << "Press 7 to know about us\n";
		cin >> num;

		switch (num)
		{
		case 1: SearchPrisoner();
			break;
		case 2: AddPrisoner();
			break;
		case 3: DeletePrisoner();
			break;
		case 4: UpdatePrisoner();
			break;
		case 5: DisplayPrisoner();
			break;
		case 6: Report();
			break;
		case 7: About();
			break;
		default: cout << "Invalid input";
		}
		cout << "Do you want to perform another action( y / n ) : ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
	if (choice != 'y' || choice != 'Y')
	{
		PFileAPP();
	}
}

//Logged in as staff
void Staff()
{
	VFileREAD();
	PFileREAD();
	char choice;
	int num;
	do
	{
		system("cls");
		cout << "Press 1 to view visitors\n";
		cout << "Press 2 to add visitor\n";
		cin >> num;
		switch (num)
		{
		case 1: DisplayVisitor();
			break;
		case 2: AddVisitor();
			break;
		default: cout << "Invalid input";
		}
		cout << "Do you want to perform another action( y / n ) : ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');

	if (choice != 'y' || choice != 'Y')
	{
		VFileAPP();
	}

}

//Login Details
void login() 
{
	struct_login login_details[2];
	login_details[0].Username = "admin";
	login_details[0].Password = "admin123";
	login_details[1].Username = "staff";
	login_details[1].Password = "staff123";

	PrintHeading();
	cout << "\n\n\n\n";
	struct_login input;
	cout << "Enter Username: ";
	cin >> input.Username;
	cout << "Enter Password: ";
	cin >> input.Password;
	while (true)
	{
		if (input.Username == login_details[0].Username && input.Password == login_details[0].Password)
		{
			Admin();
			break;
		}
		if (input.Username == login_details[1].Username && input.Password == login_details[1].Password)
		{
			Staff();
			break;
		}
		cout << "Invalid credentials!!\nTry again\n";
		cout << "Enter Username: ";
		cin >> input.Username;
		cout << "Enter Password: ";
		cin >> input.Password;
	}
}

int main()
{
	login();
	return 0;
}