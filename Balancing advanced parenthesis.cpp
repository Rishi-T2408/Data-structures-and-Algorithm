#include <iostream>
#include <string.h>
using namespace std;
struct Stack
{
	int top;
	int size;
	char* S; //This will create an array which will work same as stack
}st;
void push(Stack* st, char x)
{
	if ((st->top) == (st->size - 1))
		cout << "Stack overflow" << endl;
	else {
		st->top++;
		st->S[st->top] = x;  //So the value is pushed in stack 
	}
}
char pop(Stack* st)
{
	int x = -1; //So if this function returns -1 it mean value cannot we popped
	if (st->top == -1)
		cout << "Stack underflow" << endl;
	else {
		x = st->S[st->top];
		st->top--;
	}
	return x;
}
int isBalanced(char* exp)
{
	int i = 0;
	Stack st1;
	st1.size = strlen(exp);
	st1.top = -1;
	st1.S = new char[st1.size];
	while (exp[i] != '\0')
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			push(&st1, exp[i]);

		else if (exp[i] == ')' && st1.S[st1.top] == '(')
		{
			int m = pop(&st1);
			if (m == -1)
			{
				return 0;
			}
		}

		else if (exp[i] == ']' && st1.S[st1.top] == '[')
		{
			int m = pop(&st1);
			if (m == -1)
			{
				return 0;
			}
		}

		else if (exp[i] == '}' && st1.S[st1.top] == '{')
		{
			int m = pop(&st1);
			if (m == -1)
			{
				return 0;
			}
		}
		else {

		}
		i++;
	}
	if (st1.top == -1)  //Stack is perfectly empty with no underflow
	{
		return 1;
	}
	else
		return 0;
}


int main()
{
	char exp[100];
	cout << "Enter the expression :" << endl;
	cin >> exp;
	int c = isBalanced(exp);  //An string name is the address of the string like an array
	if (c == 1)
		cout << "Equation is balanced with parenthesis" << endl;
	else {
		cout << "Not balanced" << endl;
	}
	return 0;
}













