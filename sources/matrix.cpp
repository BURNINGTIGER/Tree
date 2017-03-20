#include "matrix.hpp"

using namespace std;

Matrix::Matrix(): st(0), cl(0), matr{nullptr}
{
}

Matrix::Matrix(int m, int n) : st(m), cl(n)
{
	matr = new int *[m];
	for (int i = 0; i < m; i++)
		matr[i] = new int[n]();
}

Matrix::Matrix(Matrix &matrc)
{
	matr = new int*[matrc.st];
	for (int i = 0; i < matrc.st; i++)
		matr[i] = new int[matrc.cl];
	st = matrc.st;
	cl = matrc.cl;
	for (int i = 0; i < matrc.st; i++)
	for (int j = 0; j < matrc.cl; j++)
		matr[i][j] = matrc.matr[i][j];
}

Matrix::~Matrix()
{
	for (int i = 0; i < st; i++)
		delete[] matr[i];
	delete[] matr;
}

Matrix Matrix::operator+ (const Matrix &mat_2) const
{
	if (st != mat_2.st || cl != mat_2.cl)
	{
		cout << "Add error\n";
		system("pause");
		exit(1);
	}
	Matrix result(st, cl);
	for (int i = 0; i < st; i++)
	{
		for (int j = 0; j < cl; j++)
			result.matr[i][j] = matr[i][j] + mat_2.matr[i][j];
	}
	return result;
}
Matrix Matrix::operator*(const Matrix &mat_2) const
{
	if (st != mat_2.cl)
	{
		cout << "Mult error\n";
		system("pause");
		exit(1);
	}
	Matrix result(st, mat_2.cl);
	for (int i = 0; i < st; i++)
	for (int j = 0; j < mat_2.cl; j++)
	{
		result.matr[i][j] = 0;
		for (int k = 0; k < cl; k++)
			result.matr[i][j] += matr[i][k] * mat_2.matr[k][j];
	}
	return result;
}


Matrix& Matrix::operator =(Matrix &matrc)
{
	for (int i = 0; i < st; i++)
	for (int j = 0; j < cl; j++)
		matr[i][j] = matrc.matr[i][j];
	return *this;
}


bool Matrix::operator==(const Matrix& com)const
{
	bool res = true;
	if (st != com.st || cl != com.cl)
	{
		cout << "Comp error" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		for (int i = 0; i < st; i++)
		for (int j = 0; j < cl; j++)
		if (matr[i][j] != com.matr[i][j])
			res = false;
	}
	return res;
}

istream& operator >> (istream& in, const Matrix& mat)
{
	for (int i = 0; i < mat.st; i++)
	for (int j = 0; j < mat.cl; j++)
		in >> mat.matr[i][j];
	return in;
}

ostream& operator << (ostream& out, const Matrix& mat)
{
	for (int i = 0; i < mat.st; i++)
	{
		for (int j = 0; j < mat.cl; j++)
			out << " " << mat.matr[i][j];
		out << endl;
	}
	return out;
}

int Matrix::str()
{
	return st;
}

int Matrix::col()
{
	return cl;
}
