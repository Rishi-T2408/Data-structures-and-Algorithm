

#include <iostream>
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
int main()
{
	Stack st;  //But yehh stack variable tohh local hai nhh tohh yehh bss iss function ke liye defined hooga
	Create(&st);  //So iam sending address of this strcture
	push(&st, 3);
	push(&st, 5);
	push(&st, 8);
	push(&st, 9);
	int val = stackTop(st);
	cout << val;
	Display(st);
}

