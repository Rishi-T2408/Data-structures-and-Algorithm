// Polynomial creation and evaluation C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;

class Term {
public:
	int coeff;
	int expo; 
};  //It will keep the record of each terms of our memory
class Poly {
private:
	int num; //Jisse non zero terms ka number pta chll paaye
	Term* t;   //Pointer to the array of tuples containing information
public:
	Poly(int num) {
		this->num = num;
		//Now we can create the array of tuples containing the term information
		t = new Term[num];
		//Now we will fill the terms info
		for (int i = 0; i < num; i++)
		{
			cout << "Enter the coefficient and the power of the " << i + 1 << "th term";
			cin >> t[i].coeff;
			cin >> t[i].expo;   //As t[i] is the structure variable

		}
	}
	int evaluate(int x)
	{
		int sump=0;
		for (int j = 0; j < num; j++)
		{
			sump += t[j].coeff * pow(x, t[j].expo);
		}

		return sump;
	}




};
int main()
{
	int num;
	int x;
	cout << "Enter the number of terms in the polynomial";
	cin >> num;
	Poly p1(num);

	cout << "Enter the value for which you have to evaluate the expression" << endl;
	cin >> x;
	int eva;
	eva=p1.evaluate(x);
	cout << "And the result is..........." << endl;
	cout << eva << endl;
	return 0;
}

