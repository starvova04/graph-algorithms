#include "Globals.h"
#include "Graph.h"
#include "Printer.h"

using namespace std;

int main() {
	PrintHeader("\t\t\t\t\t|Realization Graph algorithm|");

	while (true) {
		int choice;
			cout << "\n\nChoose algorithm you would like to use:\n"
			<< "1.If you want to choice DijkstraAlgo.\n"
			<< "2.If you want to choice FloydAlgo.\n"
			<< "3.Clear console.\n"
			<< "4.Exit.\n"
			<< "Number: ";

		cin >> choice;
		switch (choice) {
		case 1: {
			DijkstraAlgo();
			break;
		}
		case 2: {
			FloydAlgo();
			break;
		}
		case 3: {
			system("cls");
				cout << "\t\t\t\t\t"
				<< "|Realization Graph algorithm| " << endl
				<< endl;
			break;
		}
		case 4: {
			exit(0);
		}
		default: {
			PrintErrorText("Wrong operation id, try again!");
		}
		}
	}
	return 0;
}