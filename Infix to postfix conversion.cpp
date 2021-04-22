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

int stackTop(Stack st)
{
	if (st.top != -1)
		return st.S[st.top];
	else {
		return -1;
	}
}

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else
		return 1;
}
int pre(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	else {
		return 0;
	}
}
int isEmpty(Stack p)
{
	if (p.top == -1)
		return 1;
	else
		return 0;
}
char* toPostfix(char* infix)
{
	int i = 0;
	int j = 0;
	Stack st;
	st.top = -1;
	st.size = strlen(infix);
	st.S = new char[st.size];   //Created an stack containing characters in the heap 
	char* postfix = new char[strlen(infix)+1];  //+1 is to store NULL character
	while (infix[i] != '\0')  //null char contains forward slash
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else {
			if (pre(infix[i]) > pre(stackTop(st)))
			{
				push(&st, infix[i++]); //If precedence is higher then one in the stack iam push it in stack 
			}
			else {
				postfix[j++] = pop(&st);  //Here we will not increament i 
			}
		}
	}
	while (!isEmpty(st))
	{
		postfix[j++] = pop(&st);
	}
	postfix[j] = '\0'; 
	return postfix;

}

int main()
{
	char infix[100];
	cout << "Enter the infix expression :" << endl;
	cin >> infix;
	char *postfix=toPostfix(infix);
	cout << "The postfix expression is " << endl;
	cout << postfix << endl;
	return 0;
}
