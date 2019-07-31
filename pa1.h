#ifndef PA1_MSQUARE_H
#define PA1_MSQUARE_H

//class definitions for MSquare
class MSquare {
public:
	MSquare(int size);
	~MSquare();
	void print(int **array, int number);
	void rotate();
	void reflect();
	void rowcolSwap();
	void Checker(int **array);
	void magicMaker();
	void sizeThree();
	int **array;
	int **secondarray;
private:
	int n;
	void rowChecker(int **array, int i);
	void colChecker(int **array, int j);
	void diaChecker(int **array);
};

#endif //PA1_MSQUARE_H
#pragma once
