#include "header.h"

int main() {
	string param1, param2;
	Table gradeTable;
	Table studentTable;



	for(;;) {
		cout<<"tables> ";
		cin>>param1;

		//transforms user input to lowercase to accept more garbage
		transform(param1.begin(), param1.end(), param1.begin(), ::tolower);

		if(param1 == "students")
		{
			cin>>param2;
			
			//transforms user input to lowercase to accept more garbage
			transform(param1.begin(), param1.end(), param1.begin(), ::tolower);

			if(param2 == "add")
			{
				
				if(studentTable.addItem(STUDENT))
					cout<<"item added successfully"<<endl;
				else
					cout<<"an error occured"<<endl;

			} else if (param2 =="delete")
			{

				gradeTable.deleteItem(GRADE, studentTable.deleteItem(STUDENT, USER_DEFINED_ID));

			} else if (param2 == "display")
			{
				studentTable.displayTable();
				cout<<endl;
			} else 
			{
				cout<<"invalid operation, param2"<<endl;
			}

		} else if (param1 == "grades") 
		{
			cin>>param2;
			
			//transforms user input to lowercase to accept more garbage
			transform(param1.begin(), param1.end(), param1.begin(), ::tolower);
			
			if(param2 == "add")
			{

				if(gradeTable.addItem(GRADE))
					cout<<"item added successfully"<<endl;
				else
					cout<<"an error occured"<<endl;

			} else if (param2 =="delete")
			{

				gradeTable.deleteItem(GRADE, USER_DEFINED_ID);

			} else if (param2 == "display")
			{
				gradeTable.displayTable();
				cout<<endl;
			} else 
			{
				cout<<"invalid operation, param2"<<endl;
			}
		
		} else if (param1 == "quit")
		{
			exit(0);
		}
		else
		{
			cout<<"invalid input, parameter 1"<<endl;
			//flush the buffer to get rid of extra arguments 
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(), '\n');
		}
	}

	return 0;
}