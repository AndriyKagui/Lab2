#include <iostream>
#include <math.h>
using namespace std;

void Sort(double a[], int p) {
	double T;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p - 1; j++) {
			if (a[j] > a[j + 1]) {
				T = a[j + 1];
				a[j + 1] = a[j];
				a[j] = T;
			}
		}
	}
}
int flag = 0;
void Union(double a[], double b[], double c[], int pa, int pb, int pc) {
	for (int i = 0; i < pc; i++) {
		if (i < pa) {
			c[i] = a[i];
		}
		else {
			c[i] = b[i - pa];
		}
	}
	
	for (int i = 0; i < pc; i++)
	{
		for (int j = i + 1; j < pc; j++)
		{
			if (c[i] == c[j])
			{
				flag++;
				for (int shift = j; shift < pc - 1; shift++)
				{
					c[shift] = c[shift + 1];
				}
			}
		}
	}
}

void Intersect(double a[], double b[], int pa, int pb) {
	int pc = 0;
	double* c = new double[pc];
	for (int j = 0; j < pa; j++) {
		for (int i = 0; i < pb; i++) {
			if (a[i] == b[j]) {
				c[pc] = a[i];
				pc++;
			}
		}
	}
	for (int i = 0; i < pc; i++) {
		cout << c[i] << " ";
	}
}

int main()
{
	int m1 = 0, m2 = 0, p1, p2, pp, po;
	int const size = 100;
	double N1, N2;
	cout << "Enter size for arr1" << endl;
	cin >> p1;
	cout << "Enter size for arr2" << endl;
	cin >> p2;
	po = p1 + p2;
	double *mnoz1 = new double[p1];
	double *mnoz2 = new double[p2];
	double per[size];
	double* obj = new double[po];

	do {
		cout << "Enter elements for arr1" << endl;
		cin >> N1;
			mnoz1[m1] = N1;
			m1++;
	} while (m1 < p1);
	do {
		cout << "Enter elements for arr2" << endl;
		cin >> N2;
			mnoz2[m2] = N2;
			m2++;
	} while (m2 < p2);

	Sort(mnoz1, p1);
	Sort(mnoz2, p2);
	Union(mnoz1, mnoz2, obj, p1, p2, po);
	Sort(obj, po);

	cout << endl;
	cout << "Array 1: ";
	for (int i = 0; i < p1; i++) {
		cout << mnoz1[i] << " ";
	}
	cout << endl; 
	cout << "Array 2: ";

	for (int i = 0; i < p2; i++) {
		cout << mnoz2[i] << " ";
	}
	cout << endl; 
	cout << "Union of arrays:";

	for (int i = 0; i < po - sqrt(flag); i++) {
		cout << obj[i] << " ";
	}
	cout << endl;
	cout << "Intersection of arrays is: "; Intersect(mnoz1, mnoz2, p1, p2);
	cout << endl;
}
