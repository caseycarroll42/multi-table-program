#include <iostream> //cout cin yadda yadda 
#include <limits> //for int check
#include <algorithm> //for transforming text to lowercase
#include <string> //strings
#include <cctype>
#include <stdlib.h> /*exit*/
#include <vector>

using namespace std;

const int STUDENT = 0;
const int GRADE = 1;
const int USER_DEFINED_ID = -1;

//CLASSES

//tuple is the base class for student and grade tuples
class tuple
{
	int id; //student id
public:
	tuple() {id = -1;}
	tuple(int inputID): id(inputID) {}

	int getID() {return id;}

	virtual string getFirstN() {return "";}
	virtual string getLastN() {return "";}
	virtual string getClassN() {return "";}
	virtual char getGrade() {return 0;}

	virtual void displayInfo() {}
};

class StudentTuple: public tuple
{
	string first_name;
	string last_name;
public:
	StudentTuple(int inputID, string inputFirst, string inputLast) : tuple(inputID)
	{
		first_name = inputFirst;
		last_name = inputLast;
	}

	//getters
	string getFirstN() {return first_name;}
	string getLastN() {return last_name;}

	//setters
	void setFirstN(string inFirst) {first_name = inFirst;}
	void setLastN(string inLast) {last_name = inLast;}

	void displayInfo()
	{
		cout << "( " << getID() << " , " << getFirstN() << " , " << getLastN() << " ) ";
	}

};

class GradeTuple: public tuple
{
	string className;
	char grade;
public:
	GradeTuple(int inputID, string inputClassN, char inputGrade) : tuple(inputID)
	{
		className = inputClassN;
		grade = inputGrade;
	}

	//getters
	string getClassN() {return className;}
	char getGrade() {return grade;}

	void displayInfo()
	{
		cout << "( " << getID() << " , " << className << " , " << grade << " ) ";
	}
};

class Table
{
	/*must be a vector of base class pointers for polymorphism*/
	vector<tuple *> table;
public:
	Table() {}
	bool addItem(int tupleType);
	int deleteItem(int tupleType, int ID);
	void displayTable();
};