#include "AttendanceTracker.h"

Menu::Menu()
{
	fstr.open("classList.csv");	

	int option = 0;
	
	do
	{
		option = 0;

		while (option > 7 || option < 1)
		{
			cout << "Select an option: " << endl;
			cout << "1.	Import Course List" << endl;
			cout << "2.	Load Master List" << endl;
			cout << "3.	Store Master List" << endl;
			cout << "4.	Mark Absences" << endl;
			cout << "5.	Generate Report" << endl;
			cout << "6.	Edit Absences" << endl;
			cout << "7.	Exit" << endl;
			cin >> option;
			system("cls");
		}

		switch (option)
		{
		case 1: // import course
			import();
			break;
		case 2: // load master list
			mstr.open("Master.txt");
			loadList();
			mstr.close();
			cout << "Record loaded from master list!!!" << endl;
			break;
		case 3: // store master list
			mstr.open("Master.txt");
			storeList();
			mstr.close();
			cout << "Master list successfully stored!!!" << endl;		
			break;
		case 4: // mark absences
			markAbsences();
			system("pause");
			system("cls");
			cout << "Attendance is recored...." << endl;
			break;
		case 5: // generate reports
			generateReport();
			system("pause");
			system("cls");
			break;
		case 6: // BONUS edit absences
			editAbsences();
			system("pause");
			system("cls");
			cout << "Absences are up to date!!!" << endl;
			break;
		case 7: // exit
			cout << "Goodbye.....exiting...";
			break;
		}
	} while (option != 7);
}
Menu::~Menu()
{
	fstr.close();
	mstr.close();
}


void Menu::import()
{
	if (mList.getFrontPtr() != nullptr)
	{
		mList.destroyList(); // delete old list to make way for new one 
	}
	string firstLine, name, email, program, level;
	string record, ID, units;
	char comma, quotes;

	getline(fstr, firstLine, '\n'); // read in and discard first line....just headers

	while (!fstr.eof())
	{
		int Units = 0;
		getline(fstr, record, ',');
		if (record != "") // checks for empty line
		{
			int rec = std::stoi(record);
			getline(fstr, ID, ',');
			int id = std::stoi(ID);
			fstr >> quotes;
			getline(fstr, name, '"');
			fstr >> comma;
			getline(fstr, email, ',');
			getline(fstr, units, ',');
			if (units != "AU")
			{
				Units = std::stoi(units);
			}
			getline(fstr, program, ',');
			getline(fstr, level, '\n');

			mList.insertAtFront(rec, id, name, email, Units, program, level);
		}
	}
	cout << "Records imported successfully!!!" << endl;

}

void Menu::loadList()
{
	if (mList.getFrontPtr() != nullptr)
	{
		mList.destroyList(); // delete old list to make way for new one 
	}

	string firstLine, name, email, program, level;
	string record, ID, units, absences;
	char comma, quotes;

	getline(mstr, firstLine, '\n'); // read in and discard first line....just headers

	while (!mstr.eof())
	{
		int Units = 0;
		getline(mstr, record, ',');
		if (record != "") // checks for empty line
		{
			int rec = std::stoi(record);
			getline(mstr, ID, ',');
			int id = std::stoi(ID);
			mstr >> quotes;
			getline(mstr, name, '"');
			mstr >> comma;
			getline(mstr, email, ',');
			getline(mstr, units, ',');
			if (units != "AU")
			{
				Units = std::stoi(units);
			}
			getline(mstr, program, ',');
			getline(mstr, level, ',');
			getline(mstr, absences, '\n');
			int absence = std::stoi(absences);
			mList.insertAtFront(rec, id, name, email, Units, program, level, absence);
		}
	}
}

void Menu::storeList()
{
	mstr << "Record,ID,Name,Email,Units,Program,Level,Absences"<< endl;
	mstr << mList; //using overloaded operator in list.h
}

void Menu::markAbsences()
{
	Node * pCur = mList.getFrontPtr();
	char yn = 0;

	while (pCur != nullptr)
	{
		cout << "Is this student absent: " << pCur->getName() << "(Y/N) ";
		cin >> yn;
		if (yn == 'y' || yn == 'Y')
		{
			pCur->setAbsences(1);
			//retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
			time_t t = time(0);   // get time now
			struct tm * now = localtime(&t);
			cout << (now->tm_year + 1900) << '-'
				<< (now->tm_mon + 1) << '-'
				<< now->tm_mday
				<< endl;
			string Date = std::to_string((now->tm_year + 1900)) + "-" + std::to_string((now->tm_mon + 1)) + "-" + std::to_string(now->tm_mday);
			pCur->getStack().push(Date);
		}
		pCur = pCur->getPtr();
	}
}

void Menu::generateReport()
{
	int option = 0;

	while (option > 2 || option < 1)
	{
		cout << "Select an option: " << endl;
		cout << "1. Generate Report for Everyone" << endl;
		cout << "2. Search by Number of Absences" << endl;
		cin >> option;
		system("cls");
	}

	Node * pCur = mList.getFrontPtr();

	if (option == 1)
	{				
		while (pCur != nullptr)
		{
			string Date = "";
			pCur->getStack().peek(Date);

			if (pCur->getAbsences() != 0)
			{
				cout << pCur->getName() << " was most recently absent " << Date << endl;
			}
			else
			{
				cout << pCur->getName() << " has no absences " << endl;
			}
			pCur = pCur->getPtr();
		}
	}
	else //option == 2
	{
		int absences;

		cout << "Enter Number of Absences: ";
		cin >> absences;

		while (pCur != nullptr)
		{
			if (pCur->getAbsences() >= absences)
			{
				cout << pCur->getName() << " with " << pCur->getAbsences()<< " absences."<<endl;
			}

			pCur = pCur->getPtr();
		}

	}
}

void Menu::editAbsences()
{
	int ID, size = 0;
	string Date, Absence, Dates[100];
	Node * pCur = mList.getFrontPtr(), *pMem;
	bool found = false;

	cout << "Enter the Student's ID Number: ";
	cin >> ID;

	while (found != true && pCur != nullptr)
	{
		if (ID == pCur->getID())
		{
			found = true;
			cout << pCur->getName() << endl;
			pMem = pCur; // saves the node
		}
		pCur = pCur->getPtr();
	}

	cout << "Enter Date of Absence to Delete (yyyy-m-d): ";
	cin >> Date;

	pMem->getStack().pop(Absence);

	int stacksize = pMem->getStack().getSize();

	while (Absence != Date || stacksize > 0)
	{
		Dates[size] = Absence; // store date in seperate array
		size++;
		stacksize--;
		pCur->getStack().pop(Absence);	
	}	
	if (Absence == Date)
	{
		pMem->setAbsences(-1);
	}
	while (size >= 0)
	{
		Absence = Dates[size];
		pMem->getStack().push(Absence);
		size--;
	}
}