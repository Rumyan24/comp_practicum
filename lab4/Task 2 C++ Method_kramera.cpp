#include <iostream>
using namespace std;

int determinant(int matrix[3][3]);
int determinantX1(int coefMatrix[3][3], int constTermsMatrix[3]);
int determinantX2(int coefMatrix[3][3], int constTermsMatrix[3]);
int determinantX3(int coefMatrix[3][3], int constTermsMatrix[3]);

int main()
{
	int i, j;

	int coefficientsMatrix3x3[3][3] = {
        {5, 2, -2},
        {3, -3, -1},
        {2, 3, -1}
    };
	int constantTermsMatrix3x1[3] = {0, 1, -1};

	int det = determinant(coefficientsMatrix3x3);
	int detX1 = determinantX1(coefficientsMatrix3x3, constantTermsMatrix3x1);
	int detX2 = determinantX2(coefficientsMatrix3x3, constantTermsMatrix3x1);
	int detX3 = determinantX3(coefficientsMatrix3x3, constantTermsMatrix3x1);

	if (det != 0)
	{
		cout << "X[0] = " << (float)detX1/(float)det << endl;
		cout << "X[1] = " << (float)detX2/(float)det << endl;
		cout << "X[2] = " << (float)detX3/(float)det << endl;
	}
	else
		cout << "The system has no solution" << endl << endl;

	return 0;
}

int determinant(int matrix[3][3])
{
	int a11 = matrix[0][0];
	int a12 = matrix[0][1];
	int a13 = matrix[0][2];
	int a21 = matrix[1][0];
	int a22 = matrix[1][1];
	int a23 = matrix[1][2];
	int a31 = matrix[2][0];
	int a32 = matrix[2][1];
	int a33 = matrix[2][2];

	return (a11 * a22 * a33) + (a12 * a23 * a31) + (a13 * a21 * a32) -
		(a13 * a22 * a31) - (a11 * a23 * a32) - (a12 * a21 * a33);
}

int determinantX1(int coefMatrix[3][3], int constTermsMatrix[3])
{
	int a12 = coefMatrix[0][1];
	int a13 = coefMatrix[0][2];
	int a22 = coefMatrix[1][1];
	int a23 = coefMatrix[1][2];
	int a32 = coefMatrix[2][1];
	int a33 = coefMatrix[2][2];
	int c1 = constTermsMatrix[0];
	int c2 = constTermsMatrix[1];
	int c3 = constTermsMatrix[2];

	return (c1 * a22 * a33) + (a12 * a23 * c3) + (a13 * c2 * a32) -
		(a13 * a22 * c3) - (c1 * a23 * a32) - (a12 * c2 * a33);
}

int determinantX2(int coefMatrix[3][3], int constTermsMatrix[3])
{
	int a11 = coefMatrix[0][0];
	int a13 = coefMatrix[0][2];
	int a21 = coefMatrix[1][0];
	int a23 = coefMatrix[1][2];
	int a31 = coefMatrix[2][0];
	int a33 = coefMatrix[2][2];
	int c1 = constTermsMatrix[0];
	int c2 = constTermsMatrix[1];
	int c3 = constTermsMatrix[2];

	return (a11 * c2 * a33) + (c1 * a23 * a31) + (a13 * a21 * c3) -
		(a13 * c2 * a31) - (a11 * a23 * c3) - (c1 * a21 * a33);
}

int determinantX3(int coefMatrix[3][3], int constTermsMatrix[3])
{
	int a11 = coefMatrix[0][0];
	int a12 = coefMatrix[0][1];
	int a21 = coefMatrix[1][0];
	int a22 = coefMatrix[1][1];
	int a31 = coefMatrix[2][0];
	int a32 = coefMatrix[2][1];
	int c1 = constTermsMatrix[0];
	int c2 = constTermsMatrix[1];
	int c3 = constTermsMatrix[2];

	return (a11 * a22 * c3) + (a12 * c2 * a31) + (c1 * a21 * a32) -
		(c1 * a22 * a31) - (a11 * c2 * a32) - (a12 * a21 * c3);
}
