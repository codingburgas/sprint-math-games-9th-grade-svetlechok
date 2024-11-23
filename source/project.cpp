#include <iostream>
#include <string>

using namespace std;

int main()
{
	int choice;
	cout << "0. Quit" << endl << "1. Start a game" << endl << "2. How to play" << endl;
	cin >> choice;

	switch (choice)
	{
	case 0:
		cout << "Goodbye" << endl;
		return 0;

	case 1:
		cout << "Paste code here..." << endl;
		break;

	case 2:
		cout << "How to play" << endl;
		break;

	default:
		cout << "Incorrect answer. Choose again..." << endl;
		break;
	}

	do
	{
		cout << "0. Quit" << endl << "1. Play again" << endl << "2. How to play" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Goodbye" << endl;
			return 0;

		case 1:
			cout << "Paste code here..." << endl;
			break;

		case 2:
			cout << "How to play" << endl;
			break;

		default:
			cout << "Incorrect answer. Choose again..." << endl;
			break;

		}
	} while (choice != 0);
}