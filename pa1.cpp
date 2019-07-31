#include "pa1.h"
#include <iostream>

MSquare::MSquare(int size) {
	//constructor of MSquare class, initializes and declares two 2d arrays
	array = new int*[size];
	n = size;

	for (int i = 0; i < size; i++) {
		array[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			array[i][j] = 0;
		}
	}

	secondarray = new int*[size];

	for (int i = 0; i < size; i++) {
		secondarray[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			secondarray[i][j] = 0;
		}
	}
}

void MSquare::sizeThree() {
	//adds 3 or 5 to the preexisting arrays for size 3
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] += 5;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			secondarray[i][j] += 3;
		}
	}
}

void MSquare::print(int **array, int number) {
	//prints the formatted 2d array
	std::cout << "Magic square #" << number << " is:\n" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", array[i][j]);
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void MSquare::rowcolSwap() {
	//take two columns and swap them
	int col1 = 1;
	int col2 = n - 2;
	int temp = 0;

	for (int i = 0; i < n; i++) {
		temp = array[i][col2];
		array[i][col2] = array[i][col1];
		array[i][col1] = temp;
	}

	print(array, 9);

	Checker(array);

	//take two rows and swap them
	int row1 = 1;
	int row2 = n - 2;

	for (int j = 0; j < n; j++) {
		temp = array[row1][j];
		array[row1][j] = array[row2][j];
		array[row2][j] = temp;
	}

	print(array, 10);

	Checker(array);

}

void MSquare::rotate() {
	//rotates the arrays by swapping column and row positions and calculating row with size - 1 - current column

	/*
	*    concept adapted from: https://stackoverflow.com/questions/42519/how-do-you-rotate-a-two-dimensional-array
	*/

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			secondarray[i][j] = array[n - j - 1][i];
		}
	}
	//prints the rotated array
	print(secondarray, 2);
	//checks the sums of the rotated array (repeat for the rest)
	Checker(secondarray);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			array[i][j] = secondarray[n - j - 1][i];
		}
	}

	print(array, 3);

	Checker(array);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) {
			secondarray[i][j] = array[n - j - 1][i];
		}
	}

	print(secondarray, 4);

	Checker(secondarray);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			array[i][j] = secondarray[n - j - 1][i];
		}
	}
}

void MSquare::reflect() {
	//reflects the arrays
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			secondarray[i][j] = array[n - i - 1][j];
		}
	}
	//reflected up from original
	print(secondarray, 5);

	Checker(secondarray);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = secondarray[n - j - 1][i];
		}
	}
	//reflected toward bottom left corner from original
	print(array, 6);

	Checker(array);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			secondarray[i][j] = array[n - j - 1][i];
		}
	}
	//reflected left from original
	print(secondarray, 7);

	Checker(secondarray);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			array[i][j] = secondarray[n - j - 1][i];
		}
	}
	//reflected toward top left corner from original
	print(array, 8);

	Checker(array);
}

void MSquare::rowChecker(int** array, int i) {
	//adds up sum of a row
	int rowSum = 0;
	for (int j = 0; j < n; j++) {
		rowSum += array[i][j];
	}
	std::cout << rowSum << " ";
}

void MSquare::colChecker(int** array, int j) {
	//adds up sum of a column
	int colSum = 0;
	for (int i = 0; i < n; i++) {
		colSum += array[i][j];
	}
	std::cout << colSum << " ";
}

void MSquare::diaChecker(int **array) {
	//adds up sums of the two diagonals
	int diaSum = 0;
	int diaSum2 = 0;
	for (int i = 0; i < n; i++) {
		diaSum += array[i][i];
	}
	std::cout << diaSum << " ";
	for (int j = 0; j < n; j++) {
		diaSum2 += array[j][n - 1 - j];
	}
	std::cout << diaSum2 << " ";
}

void MSquare::Checker(int **array) {
	//checks the sums of the rows, columns, and diagonals
	std::cout << "Checking the sums of every row: ";
	for (int i = 0; i < n; i++) {
		rowChecker(array, i);
	}
	std::cout << "\n";

	std::cout << "Checking the sums of every column: ";
	for (int j = 0; j < n; j++) {
		colChecker(array, j);
	}
	std::cout << "\n";

	std::cout << "Checking the sums of every diagonal: ";
	diaChecker(array);
	std::cout << "\n\n";
}

void MSquare::magicMaker() {
	//implements the magic square algorithm by translating conditions found in below article to fill the array with magic square values

	/*
	*    Title: Magic Square
	*    Author: Aashish Barnwal
	*    Availability: https://www.geeksforgeeks.org/magic-square/
	*/

	int size = n;
	//first number is stored at (n/2, n-1) for (m, p)
	int m = size / 2;
	int p = size - 1;

	//loop through all values for square
	for (int num = 1; num <= size * size;) {
		//if row is -1 and column is size, new position is (0, size - 2) for (m, p)
		if ((m == -1) && (p == size)) {
			p = size - 2;
			m = 0;
		}
		else {
			//if the column position becomes the size, wraps around to 0
			if (p == size) {
				p = 0;
			}
			//if the row position becomes -1, wraps around to size - 1
			if (m < 0) {
				m = size - 1;
			}
		}
		//if the square already has a value, the column position goes left 2 and down 1
		if (array[m][p] != 0) {
			p -= 2;
			m += 1;
			continue;
		}
		else {
			array[m][p] = num++;
		}
		//next number is stored at (m - 1, p + 1)
		p += 1;
		m -= 1;
	}
}

MSquare::~MSquare() {
	//destructor for MSquare that deletes the memory allocated for the two 2d arrays
	for (int i = 0; i < n; ++i) {
		delete[] array[i];
	}
	delete[] array;

	for (int i = 0; i < n; ++i) {
		delete[] secondarray[i];
	}
	delete[] secondarray;
}

int main() {
	//initializes size of square to 0
	int size(0);

	//takes input for size of array, throws exception if not given an odd number 3-15
	try {
		std::cout << "Enter the size of a magic square: " << std::endl;
		std::cin >> size;
		if (size != 3 && size != 5 && size != 7 && size != 9 && size != 11 && size != 13 && size != 15) {
			throw 1;
		}
	}
	catch (...) {
		std::cout << "Invalid number. Please choose a size that is an odd number between 3 and 15.";
		return 0;
	}

	//creates MSquare object
	MSquare square(size);
	square.magicMaker();

	//first magic square
	square.print(square.array, 1);
	square.Checker(square.array);

	//manipulations for rest of magic squares
	square.rotate();
	square.reflect();

	//for size 3 arrays, prints 2 more arrays with adding 3 or 5, otherwise swaps columns and rows for last magic squares
	if (size > 3) {
		square.rowcolSwap();
	}
	else {
		square.sizeThree();
		square.print(square.array, 9);
		square.Checker(square.array);
		square.print(square.secondarray, 10);
		square.Checker(square.secondarray);
	}
	return 0;
}

