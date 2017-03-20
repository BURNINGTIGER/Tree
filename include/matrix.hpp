#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Matrix
{
private:
	int **matr;
	int st, cl;

public:
	Matrix();
	Matrix(int, int);
	Matrix(Matrix &matrс);
	~Matrix();
	int rows();
	int columns();
	Matrix operator+ (const Matrix &mat_2) const;
	Matrix operator* (const Matrix &mat_2) const;
	Matrix& operator =(Matrix &);
	bool operator==(const Matrix&)const;
	friend istream& operator >> (istream& ist, const Matrix& cmatr);
	friend ostream& operator << (ostream&, const Matrix&);
};
