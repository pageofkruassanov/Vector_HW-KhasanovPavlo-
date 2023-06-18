#include "Vector.h"

int main()
{
	double* dArr = new double[3] {3.2, 4.4, 5.5};
	Vector<double> d(3,dArr);
	cout << d;
	d[0] = 0;
	cout << endl << d;
	d.changeSize(2);
	cout << endl << d;
	d.changeSize(5);
	cout << endl << d;
	Vector<double> d1(2, 5);
	Vector<double> res = d + d1;
	cout << endl << res;
	res = res * 2;
	cout << endl << res;
}