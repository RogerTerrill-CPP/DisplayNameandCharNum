#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Declare prototypes
void getFirstLast(string& str1, int& length);
void writeRecordToFile(string str1, int length, ofstream& output);
void new_line();

int main()
{
	//Declare variables
	string recordName, enterRecord;
	int stringLength = 0;

	//Declare outstream variable
	ofstream outputFile;

	//Open output file and append to existing file
	outputFile.open("NameOutputFile.txt", ios::app);

	//Display welcome message to program
	cout << "Hello to my program 8-3. \n";

	do
	{
		//Get first and last name
		getFirstLast(recordName, stringLength);

		//Write first and last name with character number to output file
		writeRecordToFile(recordName, stringLength, outputFile);

		//Display if we want another record
		cout << "Would you like to add another record? " << endl;

		//User inputs yes or no
		cin >> enterRecord;

		//Ignore characters after first characters
		new_line();
	} while ((enterRecord != "no") && (enterRecord != "No"));

	//Close filestr
	outputFile.close();

	//Display thank you notice.
	cout << "Thank you, Good Bye!";
	return 0;
}

/*******************************************************
Name            :   getFirstLast(string& str1, int& length)
Arguments       :   firstName, lastName
Returns         :   None
Precondition    :   None
Postcondition   :   Return by reference str1 and length of first and last name
*******************************************************/
void getFirstLast(string& str1, int& length)
{
	string firstName, lastName;

	cout << "Please enter your first name: ";
	cin >> firstName;

	cout << "Please enter your last name: ";
	cin >> lastName;

	str1 = firstName + " " + lastName;
	length = str1.length() - 1;

	cout << "Your Record Name is: " << firstName << " " << lastName << " and the total number of \n"
		<< "characters in your first and last names is: " << length << "." << endl;

}

/*******************************************************
Name            :   writeRecordToFile(string str1, int length, ofstream& output)
Arguments       :
Returns         :   None
Precondition    :   str1, length, and output must be declared and initialized
Postcondition   :   Output Record name and character number to output file.
*******************************************************/
void writeRecordToFile(string str1, int length, ofstream& output)
{
	output << left << setw(15) << str1 << "\t\t" << length << endl;

}

/*******************************************************
Name            :   new_line()
Arguments       :   next_char
Returns         :   None
Precondition    :   None
Postcondition   :   Discards all the input remaining on the current input line.
*******************************************************/
void new_line()
{
	char next_char;
	do
	{
		cin.get(next_char);
	} while (next_char != '\n');
}
