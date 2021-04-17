
#include <iostream>
#include <math.h>
using namespace std;
struct Node {
    int coeff;
    int pow;
    Node* next;
}*first = NULL;
void Create(int term)
{
    Node* last = NULL;
    int Pow, Coeff;
    for (int i = 0; i < term; i++)
    {
        if (i == 0)
        {
            Node* t = new Node;
            cout << "Enter the power of " << i + 1 << "th term" << endl;
            cout << "Enter the coefficient of " << i + 1 << "th term" << endl;
            cin >> Pow;
            cin >> Coeff;
            t->coeff = Coeff;
            t->pow = Pow;
            first = t;
            last = t;
            t->next = NULL;
        }
        else {
            Node* t = new Node;
            cout << "Enter the power of " << i + 1 << "th term" << endl;
            cout << "Enter the coefficient of " << i + 1 << "th term" << endl;
            cin >> Pow;
            cin >> Coeff;
            t->coeff = Coeff;
            t->pow = Pow;
            last->next = t;
            last = t;
            t->next = NULL;
        }
    }
}
void Eval(int x)
{
    double sum = 0;
    Node* p = first;
    while (p != NULL)
    {
        sum = sum + (p->coeff) * pow(x, p->pow);
        p = p->next;
    }
    cout << "Value evaluated is " << sum << endl;

}
int main()
{
    int term;
    int x;
    cout << "Enter the number of terms in an polynomial" << endl;
    cin >> term;
    Create(term);
    cout << "Enter the value of x" << endl;
    cin >> x;
    Eval(x);
}

