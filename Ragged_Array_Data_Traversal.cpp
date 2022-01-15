//Simple but pretty long.
#include <iostream>
//declare functions
bool promptContinue();
//prompts user to continue, returns TRUE if they choose yes and FALSE otherwise
void outputLabList(int** labList, std::ostream& outStream = std::cout, const unsigned int firstRow = 5, const unsigned int secondRow = 6, const unsigned int thirdRow = 4, const unsigned int fourthRow = 3);
//outputs the ragged array labList with default args - but can be used for any ragged array of 4 rows
void outputRow(int* row, const int rowSize, std::ostream& outStream = std::cout);
//outputs a formatted row (1D array) of # values < rowSize to outStream
bool validateInput(const unsigned int row, const unsigned int column, const unsigned int firstRow = 5, const unsigned int secondRow = 6, const unsigned int thirdRow = 4, const unsigned int fourthRow = 3);
//validates an input of row and column for a ragged array of 4 rows. returns true if within bounds, false otherwise
bool searchLabList(unsigned int userId, unsigned int& lab, unsigned int& station, int** labList, const unsigned int firstRow = 5, const unsigned int secondRow = 6, const unsigned int thirdRow = 4, const unsigned int fourthRow = 3);
//searches all of lab list for userId; if found, returns true and sets lab and station to the index where it was found, +1; if not, returns false.

//main
int main()
{
	using namespace std;
	//define constants
	const unsigned int LABS_TOTAL = 4, LAB1_SIZE = 5, LAB2_SIZE = 6, LAB3_SIZE = 4, LAB4_SIZE = 3;
	//create ragged array
	int** labList = new int* [LABS_TOTAL];
	labList[0] = new int[LAB1_SIZE] {0, 0, 0, 0, 0}; labList[1] = new int[LAB2_SIZE] {0, 0, 0, 0, 0, 0};
	labList[2] = new int[LAB3_SIZE] {0, 0, 0, 0}; labList[3] = new int[LAB4_SIZE] {0, 0, 0};
	//initialize variables
	unsigned int lab, station, userId, menu = 0;
	//begin program
	cout << "Welcome to the computer lab logger test program, admin.\n\n";
	do
	{
		outputLabList(labList);
		cout << "\nChoose an option, admin.\n1. Test log on\n2. Test log off\n3. Search ID\n";
		cin >> menu;
		if (menu == 1)
		{
			cout << "Enter a lab, station, and user ID, each separated by a space.\n";
			cin >> lab >> station >> userId;
			if (validateInput(lab - 1, station - 1))
			{
				labList[lab - 1][station - 1] = userId;
				cout << "Successfully logged on user #" << userId << " on lab " << lab << " station " << station << endl;
			}
			else
				cout << "Invalid input. No action taken.\n";
		}
		else if (menu == 2)
		{
			cout << "Enter a lab and station, separated by a space.\n";
			cin >> lab >> station;
			if (validateInput(lab - 1, station - 1))
			{
				if (labList[lab - 1][station - 1] != 0)
				{
					cout << "Successfully logged off user #" << labList[lab - 1][station - 1] << " on lab " << lab << " station " << station << endl;
					labList[lab - 1][station - 1] = 0;
				}
				else
					cout << "No user logged on at specified system. No action taken.\n";
			}
			else
				cout << "Invalid input. No action taken.\n";
		}
		else if (menu == 3)
		{
			cout << "Enter ID to search for.\n";
			cin >> userId;
			if (searchLabList(userId, lab, station, labList))
				cout << "User ID #" << userId << " found at lab " << lab << " station " << station << endl;
			else
				cout << "User not found.\n";
		}
		else
			cout << "Invalid input.\n";
		cout << endl;
	} while (promptContinue());
	cout << "Hasta la vista, admin.\n";
	return 0;
}
//define functions
//uses <iostream>
bool promptContinue()
{
	char next;
	std::cout << "Would you like to continue? y/n: ";
	std::cin >> next;
	if (next == 'y' || next == 'Y')
		return true;
	else
		return false;
}
//uses <iostream>
void outputLabList(int** labList, std::ostream& outStream, const unsigned int firstRow, const unsigned int secondRow, const unsigned int thirdRow, const unsigned int fourthRow)
{
	outStream << "Lab no.\tComputer Stations\n"
		<< "Lab 1:\t";
	outputRow(labList[0], firstRow);
	outStream << "Lab 2:\t";
	outputRow(labList[1], secondRow);
	outStream << "Lab 3:\t";
	outputRow(labList[2], thirdRow);
	outStream << "Lab 4:\t";
	outputRow(labList[3], fourthRow);
	return;
}
//uses <iostream>
void outputRow(int* row, const int rowSize, std::ostream& outStream)
{
	for (int i = 0; i < rowSize; i++)
	{
		outStream << i + 1 << ": ";
		if (row[i] <= 0)
			outStream << "empty ";
		else //if user logged on
			outStream << row[i] << " ";
	}
	outStream << std::endl;
	return;
}

bool validateInput(const unsigned int row, const unsigned int column, const unsigned int firstRow, const unsigned int secondRow, const unsigned int thirdRow, const unsigned int fourthRow)
{
	switch (row)
	{
	case 0:
		if (column < firstRow)
			return true;
		else
			return false;
		break;
	case 1:
		if (column < secondRow)
			return true;
		else
			return false;
		break;
	case 2:
		if (column < thirdRow)
			return true;
		else
			return false;
		break;
	case 3:
		if (column < fourthRow)
			return true;
		else
			return false;
		break;
	default:
		return false;
		break;
	}
	return false;
}

bool searchLabList(unsigned int userId, unsigned int& lab, unsigned int& station, int** labList, const unsigned int firstRow, const unsigned int secondRow, const unsigned int thirdRow, const unsigned int fourthRow)
{
	for (int i = 0; i < firstRow; i++)
		if (labList[0][i] == userId)
		{
			lab = 1; station = i + 1;
			return true;
		}
	for (int i = 0; i < secondRow; i++)
		if (labList[1][i] == userId)
		{
			lab = 2; station = i + 1;
			return true;
		}
	for (int i = 0; i < thirdRow; i++)
		if (labList[2][i] == userId)
		{
			lab = 3; station = i + 1;
			return true;
		}
	for (int i = 0; i < fourthRow; i++)
		if (labList[3][i] == userId)
		{
			lab = 4; station = i + 1;
			return true;
		}
	return false;
}
