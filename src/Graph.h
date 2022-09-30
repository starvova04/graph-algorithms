#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "Printer.h"

#define GRAPH_FILENAME "graph.txt"
using namespace std;

void printGraph() {
	cout << endl << "Graph: " << endl;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A.size(); j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
}

void inputGraph() {
	int SIZE;
	cout << endl << "Please enter the number of vertex: ";
	cin >> SIZE;

	A.resize(SIZE);
	for (int i = 0; i < A.size(); i++) {
		A[i].resize(A.size());
		fill(A[i].begin(), A[i].end(), 0);
	}

	int start, dest, weight;
	char isContinue;
	do {
		cout << "Enter path and weight [example: 1 2 3]: ";
		cin >> start >> dest >> weight;
		if (start != dest && start <= A.size() && dest <= A.size() && weight >= 0 &&
			start > 0 && dest > 0) {
			A[start - 1][dest - 1] = weight;
			A[dest - 1][start - 1] = weight;
		}
		else {
			PrintErrorText("Invalid input! Try again\n");
			continue;
		}
		cout << "Continue? y/n: ";
		do {
			cin >> isContinue;
		} while (!cin.fail() && isContinue != 'y' && isContinue != 'n');
	} while (isContinue != 'n');
	printGraph();
}

void LoadGraphFromFile() {
	fstream file(GRAPH_FILENAME, ios_base::in);

	int size;
	if (file >> size) {
		A.resize(size);
		for (int i = 0; i < A.size(); i++) {
			A[i].resize(A.size());
			fill(A[i].begin(), A[i].end(), 0);
		}
	}
	else {
		PrintErrorText("Invalid file input!\n");
		inputGraph();
		return;
	}

	int start, dest, weight;
	while (file >> start >> dest >> weight) {
		if (start != dest && start <= A.size() && dest <= A.size() && weight >= 0 &&
			start > 0 && dest > 0) {
			A[start - 1][dest - 1] = weight;
			A[dest - 1][start - 1] = weight;
		}
		else {
			PrintErrorText("Invalid file input!\n");
			inputGraph();
			return;
		}
	}
	printGraph();
}

void DijkstraAlgo() {
	char loadFromFile;
	cout << "Load from file? y/n: ";
	do {
		cin >> loadFromFile;
	} while (!cin.fail() && loadFromFile != 'y' && loadFromFile != 'n');

	loadFromFile == 'y' ? LoadGraphFromFile() : inputGraph();

	vector<int> d(A.size());
	vector<int> v(A.size());
	vector<int> ver(A.size());

	int temp, minindex, min;
	int begin_index = 0;

	for (int i = 0; i < A.size(); i++) {
		d[i] = 10000;
		v[i] = 1;
	}
	d[begin_index] = 0;

	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < A.size(); i++) {
			if ((v[i] == 1) && (d[i] < min)) {
				min = d[i];
				minindex = i;
			}
		}

		if (minindex != 10000) {
			for (int i = 0; i < A.size(); i++) {
				if (A[minindex][i] > 0) {
					temp = min + A[minindex][i];
					if (temp < d[i]) {
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);
	cout << "\nShortest distances to vertex:\n";
	for (int i = 0; i < A.size(); i++)
		cout << "\t" << d[i];
}

void FloydAlgo() {
	char loadFromFile;
	cout << "Load from file? y/n: ";
	do {
		cin >> loadFromFile;
	} while (!cin.fail() && loadFromFile != 'y' && loadFromFile != 'n');

	loadFromFile == 'y' ? LoadGraphFromFile() : inputGraph();

	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < A.size(); j++)
			for (int k = 0; k < A.size(); k++)
				for (int i = 0; i < A.size(); i++)
					for (int j = 0; j < A.size(); j++)
						if (A[i][j] > A[i][k] + A[k][j]) {
							A[i][j] = A[i][k] + A[k][j];
						}

	cout << endl << "Output the shortest path: " << endl;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			cout << A[i][j] << " \t";
		}
		cout << endl;
	}
}
