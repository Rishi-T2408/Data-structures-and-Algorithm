#include <iostream>
#include <string.h>
using namespace std;
struct Stack
{
	int top;
	int size;
	int* S; //This will create an array which will work same as stack
}st;

void push(Stack* st, int x)
{
	if ((st->top) == (st->size - 1))
		cout << "Stack overflow" << endl;
	else {
		st->top++;
		st->S[st->top] = x;  //So the value is pushed in stack 
	}
}

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else
		return 1;
}

int pop(Stack* st)
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

int stackTop(Stack st)
{
	if (st.top != -1)
		return st.S[st.top];
	else {
		return -1;
	}
}

int Eval(char* postfix)
{
	int p1, p2, res;
	int i = 0;
	Stack st;
	st.top = -1;
	st.size = strlen(postfix);
	st.S = new int[st.size];
	while (postfix[i] != '\0')
	{
		if (isOperand(postfix[i]))
		{
			push(&st, (postfix[i++] - '0'));
		}
		else {
			p1 = pop(&st);  //Real int convert krke shii se int stack mai bhrra thaa tohh vohh hi aayega
			p2 = pop(&st);
		
			
			switch (postfix[i])
			{
			case '+':
				res = p2 + p1; 
				push(&st, res); 
				break;
			case '-': 
				res = p2 - p1;
				push(&st, res);
				break;
			case '*':
				res = p2 * p1; 
				push(&st, res); 
				break;
			case '/': 
				res = p2 / p1;
				push(&st, res);
				break;
			};
			i++;

		}
	}
	return stackTop(st);
}
int main()
{
	char postfix[100];
	cout << "Enter the postfix expression :" << endl;
	cin >> postfix;
	int eval = Eval(postfix);
	cout << "The postfix expression evaluated value is " << endl;
	cout << eval << endl;
	return 0;
}