#include "header.h"

bool Table::addItem(int tupleType) {
	int tempID;
	tuple *tupleToAdd;

	if(!(cin>>tempID))
	{
		cout<<endl<<"Error: INVALID NUMBER"<<endl;
		cout<<"please try again"<<endl<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');
		return false;
	}

	if(tupleType == STUDENT)
	{
		string tempFirst, tempLast;

		cin>>tempFirst;
		cin>>tempLast;

		//(tempID, tempFirst, tempLast);

		/*add the student to the table*/
		table.push_back(new StudentTuple(tempID, tempFirst, tempLast));
		return true;
	} else if(tupleType == GRADE)
	{
		string className;
		double tempGrade;

		cin>>className;
		
		if(!(cin>>tempGrade))
		{
			cout<<endl<<"Error: INVALID NUMBER"<<endl;
			cout<<"please try again"<<endl<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(), '\n');
			return false;
		};

		/*add the grade to the table*/
		table.push_back(new GradeTuple(tempID, className, tempGrade));
		return true;
	} else {
		cout<<"something went wrong..."<<endl;
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
	if(ID>-1)
	{
		for(it = table.begin(); it!=table.end(); ++it)
		{
			cout<<"iterate"<<endl;
			if((*it)->getID() == ID)
			{
				table.erase(it);
				it = it-1;//bump iterator back because erase shifted vector
			}
		}
		return 0;
	}

	if(!(cin>>key))
	{
		cout<<endl<<"Error: INVALID NUMBER"<<endl;
		cout<<"please try again"<<endl<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');
		return 0;
	}

	if(tupleType == STUDENT)
	{
		for(it = table.begin(); it!=table.end(); ++it)
		{
			if ((*it)->getID() == key)
			{
				int returnID = (*it)->getID();
				table.erase(it);
				return returnID; //allows to search through grade table!
			}
		}

		cout<<"could not find by id"<<endl;
		return 0;
	} else if (tupleType == GRADE)
	{
		string classKey;
		cin>>classKey;

		for(it = table.begin(); it!=table.end(); ++it)
		{
			if (((*it)->getID() == key)
				&&((*it)->getClassN() == classKey))
			{
				table.erase(it);
				return 1;
			}
		}

		cout<<"could not find by id and class name"<<endl;
		return false;	
	}

}

void Table::displayTable()
{
	vector<tuple *>::iterator it;

	if(table.empty()){
		cout<<"empty table";
		return;
	}

	for(it = table.begin(); it!=table.end(); ++it)
	{
		(*it)->displayInfo();
		if(it != table.end()-1)
			cout<<"- ";
	}
}