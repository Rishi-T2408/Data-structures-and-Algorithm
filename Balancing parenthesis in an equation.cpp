

#include <iostream>
#include <string.h>
using namespace std;
struct Stack
{
	int top;
	int size;
	int* S; //This will create an array which will work same as stack
}st;
void Create(Stack *st)
{
	cout << "Please enter the size of the stack" << endl;
	int sz;
	cin >> sz;
	st->size=sz;
	st->top = -1; //Intially stack is empty
	st->S = new int[st->size];
}
void Display(Stack st)
{
	while (st.top != -1)
	{
		cout << st.S[st.top] << " ";
		st.top--;
	}
}
void push(Stack* st,int x)
{
	if ((st->top) == (st->size - 1))
		cout << "Stack overflow" << endl;
	else {
		st->top++;
		st->S[st->top] = x;  //So the value is pushed in stack 
	}
}
int pop(Stack *st)
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
int peek(Stack st, int pos)
{
	int x = -1;
	if ((st.top - pos + 1) < 0)
		cout << "Invalid index" << endl;
	else {
		x = st.S[st.top - pos + 1];
	}
	return x;
}
int isEmpty(Stack p)
{
	if (p.top == -1)
		return 1;
	else
		return 0;
}
int isFull(Stack st)
{
	if (st.top == (st.size - 1))
		return 1;
	else
		return 0;
}
int stackTop(Stack st)
{
	if (st.top != -1)
		return st.S[st.top];
	else {
		return -1;
	}
}

int isBalanced(char* exp)
{
	int i = 0;
	Stack st1;
	st1.size = strlen(exp);
	st1.top = -1;
	st1.S = new int[st1.size];
	while (exp[i] != '\0')
	{
		if (exp[i] == '(')
			push(&st1,1);   //So i have encoded ( as 1
		else if (exp[i] == ')')
		{
			int m=pop(&st1);
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
	int c=isBalanced(exp);  //An string name is the address of the string like an array
	if (c == 1)
		cout << "Equation is balanced with parenthesis" << endl;
	else {
		cout << "Not balanced" << endl;
	}
	return 0;
}

