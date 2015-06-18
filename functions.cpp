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

bool Table::deleteItem(int tupleType)
{
	int key;
	vector<tuple *>::iterator it;
	
	if(!(cin>>key))
	{
		cout<<endl<<"Error: INVALID NUMBER"<<endl;
		cout<<"please try again"<<endl<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');
		return false;
	}
	if(tupleType == STUDENT)
	{
		for(it = table.begin(); it!=table.end(); ++it)
		{
			if ((*it)->getID() == key)
			{
				table.erase(it);
				return true;
			}
		}

		cout<<"could not find by id"<<endl;
		return false;
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
				return true;
			}
		}

		cout<<"could not find by id and class name"<<endl;
		return false;	
	}

}

void Table::displayTable()
{
	vector<tuple *>::iterator it;

	for(it = table.begin(); it!=table.end(); ++it)
	{
		(*it)->displayInfo();
		if(it != table.end()-1)
			cout<<"- "<<endl;
	}
}