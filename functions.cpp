#include "header.h"

bool Table::addItem(int tupleType) {
	int tempID;
	tuple *tupleToAdd;
	vector<tuple *>::iterator insertIT;

	if (!(cin >> tempID))
	{
		cout << endl << "Error: INVALID NUMBER" << endl;
		cout << "please try again" << endl << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');
		return false;
	}

	if (tupleType == STUDENT)
	{
		string tempFirst, tempLast;

		cin >> tempFirst;
		cin >> tempLast;

		/*add the student to the table*/
		//if the table is empty, add a new student without sorting
		if (table.empty())
			table.push_back(new StudentTuple(tempID, tempFirst, tempLast));
		else
		{
			for (insertIT = table.begin(); insertIT != table.end(); ++insertIT)
			{
				//if the new value is less than a value in the table, insert it before the next largest value
				if (tempID <= (*insertIT)->getID())
				{
					insertIT = table.insert(insertIT, new StudentTuple(tempID, tempFirst, tempLast));
					break;
				}
			}
			if (tempID > table.back()->getID())
			{
				table.push_back(new StudentTuple(tempID, tempFirst, tempLast));
			}
		}

		return true;

	} else if (tupleType == GRADE)
	{
		string className;
		double tempGrade;

		cin >> className;

		if (!(cin >> tempGrade))
		{
			cout << endl << "Error: INVALID NUMBER" << endl;
			cout << "please try again" << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(), '\n');
			return false;
		};

		//add a new item to the grade table
		//if the table is empty, simply add it without sorting.
		if (table.empty())
			table.push_back(new GradeTuple(tempID, className, tempGrade));
		else
		{
			for (insertIT = table.begin(); insertIT != table.end(); ++insertIT)
			{
				//if the new value is less than a value in the table, insert it before the next largest value
				if (tempID < (*insertIT)->getID())
				{

					break;
				} else if (tempID == (*insertIT)->getID()) {

					//ids are equal, must alphabetize
					if (className < (*insertIT)->getClassN())
					{
						insertIT = table.insert(insertIT, new GradeTuple(tempID, className, tempGrade));
					}
				}
			}
			if (tempID > table.back()->getID())
			{
				table.push_back(new GradeTuple(tempID, className, tempGrade));
			}
		}

		return true;

	} else {
		cout << "something went wrong..." << endl;
		return false;
	}
}

int Table::deleteItem(int tupleType, int ID)
{
	int key;
	vector<tuple *>::iterator it;

	//no user input required
	//goes through list and deletes grades associated with
	// a student that is being deleted
	if (ID > -1)
	{
		for (it = table.begin(); it != table.end(); ++it)
		{
			cout << "iterate" << endl;
			if ((*it)->getID() == ID)
			{
				table.erase(it);
				it = it - 1; //bump iterator back because erase shifted vector
			}
		}
		return 0;
	}

	if (!(cin >> key))
	{
		cout << endl << "Error: INVALID NUMBER" << endl;
		cout << "please try again" << endl << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');
		return 0;
	}

	if (tupleType == STUDENT)
	{
		for (it = table.begin(); it != table.end(); ++it)
		{
			if ((*it)->getID() == key)
			{
				int returnID = (*it)->getID();
				table.erase(it);
				return returnID; //allows to search through grade table!
			}
		}

		cout << "could not find by id" << endl;
		return 0;
	} else if (tupleType == GRADE)
	{
		string classKey;
		cin >> classKey;

		for (it = table.begin(); it != table.end(); ++it)
		{
			if (((*it)->getID() == key)
			        && ((*it)->getClassN() == classKey))
			{
				table.erase(it);
				return 1;
			}
		}

		cout << "could not find by id and class name" << endl;
		return false;
	}

}

void Table::displayTable()
{
	vector<tuple *>::iterator it;

	if (table.empty()) {
		cout << "empty table";
		return;
	}

	for (it = table.begin(); it != table.end(); ++it)
	{
		(*it)->displayInfo();
		if (it != table.end() - 1)
			cout << "- ";
	}
}