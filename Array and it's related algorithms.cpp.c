// Array and it's operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//    Single menu driver program writting all the operations

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
// Now making an user defined data type array which can be used to make our arrays(physical data structure) in stack or in heap 
struct Array
{
    int *A;   //As an array pointer works like an name of array
    int lenght;
    int size; // order of structure elements are important for initialization
};  //Iss data type ke ekhh variable se ekhh array bnegi


void display(struct Array arr)  
{
    printf("Elements filled in an array are\n");
    for (int i = 0; i < arr.lenght; i++)// lenght matlab number of elements filled 
    {
       
        cout << arr.A[i] <<"  ";  
    }
}
void Append(struct Array *p,int x)   //So call by value will not change the array present in the main function so call by address
{
    // First you see is there space available in the end size>lenght
    if (p->size > p->lenght)
    {
        p->A[p->lenght] = x;
        p->lenght++;
    }
}

void insert(Array*ptr, int index, int x)
{
    // First check index is valid or not
    if (index >= 0 && index <= ptr->size)
    {
        for (int m = ptr->lenght; m > index; m--)  // Shifting done first
        {
            ptr->A[m] = ptr->A[m - 1];
        }
        ptr->A[index] = x;  //After shifting inserting done
        ptr->lenght++;
      
    }
}

int Delete(struct Array* p, int index)  //returning the deleted element value
{
    if (index >= 0 && index <= p->lenght)
    {
        int m = p->A[index];
        for (int j = index; j < ((p->lenght) - 1); j++)  // j shold be increamented
        {
            p->A[j] = p->A[j + 1];
        }
        // As one element is shifted and elements next to that are shifted to the start of array so lenght is decresed by one
        p->lenght--;
        return m;
    }
    return 0;
}
void swap(int *x,int *y)
{
    int m = *x;
    *x = *y;
    *y = m;
}

int LinearSearchTransposition(Array *arr, int key) //As we want to only search and improvement
{
    for (int i = 0; i < arr->lenght; i++)
    {
        if (arr->A[i] == key) // Then element found
        {
            swap(&arr->A[i],&arr->A[i-1]);
            return i-1;
        }
           
    }
    return -1;
}

int LinearSearchMOH(Array* arr, int key) //As we want to only search and improvement MOVE TO HEAD
{
    for (int i = 0; i < arr->lenght; i++)
    {
        if (arr->A[i] == key) // Then element found
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }

    }
    return -1;
}


int LinearSearch(Array arr, int key) //As we want to only search and not improve
{
    for (int i = 0; i < arr.lenght; i++)
    {
        if (arr.A[i] == key) // Then element found
            return i;
    }
    return -1;
}


int BinSearchI(Array arr, int key)  // l ar h nagrr se deena bewakffi hoogi kyoki vohh algorithm ke internal variable hai
{
    int l, h;
    l = 0;
    h = arr.lenght - 1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;  // Division gives the floor value of the result
        if (arr.A[mid] == key)
        {
            return mid;
        }
        else if (arr.A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return - 1;
}


int BinSearchR(Array arr, int l,int h,int key)  // l ar h nagrr se deena bewakffi hoogi kyoki vohh algorithm ke internal variable hai
{
   
    int mid;
    if(l <= h)
    {
        mid = (l + h) / 2;  // Division gives the floor value of the result
        if (arr.A[mid] == key)
        {
            return mid;
        }
        else if (arr.A[mid] > key)
            return BinSearchR(arr,l,mid-1,key);  // Isme recursive function ke hrr components mai same array de di gaii hai via call by value
        else
            return BinSearchR(arr,mid+1,h, key);    
    }
    return -1;
}

int Get(Array arr,int index)
{
    if (index >= 0 && index < arr.lenght)
        return arr.A[index];
}

void set(Array *arr1, int index, int x)  // We have to change main array from this so call by ##address## 
{
    if (index >= 0 && index < arr1->lenght)
        arr1->A[index] = x;    
}

int Max(Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.lenght; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}


int Min(Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.lenght; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(Array arr)
{
    int Total = 0;
    for (int i = 0; i < arr.lenght; i++)
        Total = Total + arr.A[i];
    return Total;
}

float Avg(Array arr)
{
    int Total = 0;
    for (int i = 0; i < arr.lenght; i++)
        Total = Total + arr.A[i];
    return (float)Total/arr.lenght;
}

void Reversal1(Array *p)   //Reversal of array by using the arbitarry array also
{
    // I will not use the stack array as we need to delclare size here in code only so for giving it an size or lenght which will be known at run time we will use heap array
    int* b;
    b = (int*)malloc(p->size * sizeof(int));  // Maked an array in heap  
    int l = p->lenght;
    for (int i = l - 1, j = 0; i>=0; i--, j++)   //i end se start jayega A ke aur j usse condition se Start se end to B 
    {
        b[j] = p->A[i];
    }

    for (int i = 0; i < l; i++)   // Tu last index ko idg=hrr assess nhi krrha thaa
    {
        p->A[i] = b[i];   // B se content same order mai A mai store krrdiye tohh A ka reversal hoogya
    }
}


void Reversal2(Array* p)  // In this we will not have the duplicate array and on taht array only we will swap the elements in order to reverse it
{
    int i, j;
    for (i = 0, j = (p->lenght - 1); i < j; i++, j--)    //i=j and i>j nhi hoona chaiye (i<j jobhh tkhh hai tbhh tkhh reversal hooga
    {
        swap(&p->A[i], &p->A[j]);
    }
}

void insertSort(Array* ptr,int x)  // Inserting an key in the sorted position 
{
    if (ptr->lenght == ptr->size)
        return;
    int i = ptr->lenght - 1;
    while (i>=0 && ptr->A[i] > x)   //Jbhh tkhh badha mile right shift krvao index position value ko to its next position
    {
        ptr->A[i + 1] = ptr->A[i];
        i--;     //So as we are at end of array so we should decrement
    }
    ptr->A[i + 1] = x;
    ptr->lenght++;
}

int isSorted(Array arr1)  //It will return True if array is sorted false if not sorted 
{
    for (int i = 0; i < arr1.lenght - 1; i++)
    {
        if (arr1.A[i] > arr1.A[i + 1])  //Hooo yehh nhi hoona thaa yehh tohh unsorted hai 
            return false; 
    }
    return true;
}

void Rearrange(Array* p)
{
    int i = 0;
    int j = p->lenght - 1;
    while (i < j)
    {
        while (p->A[i] < 0)    //So it will trap positive number
            i++;
        while (p->A[j] >= 0)    //So it will trap negative number
            j--;  //j variable is iterating form last index towards starting
        if(i<j)
        swap(&p->A[i], &p->A[j]);

    }
}

Array* Merge(Array arr1, Array arr2)
{
    Array *ptr = (Array *)malloc(sizeof(struct Array));     //Created an struct on heap using ptr
    
    int i = 0,j=0,k=0;  //It will trap the positive number on left side
    while (i < arr1.lenght && j < arr2.lenght)   //That comparison and copying will be done till one array all elements finshed
    {
        if (arr1.A[i] < arr2.A[j])    
            ptr->A[k++] = arr1.A[i++];
        else
            ptr->A[k++] = arr2.A[j++];
    }
    for (; i < arr1.lenght; i++)
        ptr->A[k++] = arr1.A[i];
    for (; j < arr2.lenght; j++)     //Because this is array to which is stored in struct created by arr2
        ptr->A[k++] = arr2.A[j];
    ptr->lenght = arr1.lenght + arr2.lenght;
    return ptr;
}

//Union of sorted arrays we will use the tech of merge function
Array* UnionSorted(Array arr1, Array arr2)   //Isme union krke unioned set will also come sorted
{
    Array* ptr = (Array*)malloc(sizeof(struct Array));     //Created an struct on heap using ptr
    int i = 0, j = 0, k = 0;  //It will trap the positive number on left side
    while (i < arr1.lenght && j < arr2.lenght)   //That comparison and copying will be done till one array all elements finshed
    {
        if (arr1.A[i] == arr2.A[j])
        {
            ptr->A[k++] = arr2.A[j++];
            i++;
        }
        else if (arr1.A[i] < arr2.A[j])
            ptr->A[k++] = arr1.A[i++];
        else
            ptr->A[k++] = arr2.A[j++];
    }
    for (; i < arr1.lenght; i++)
        ptr->A[k++] = arr1.A[i];
    for (; j < arr2.lenght; j++)     //Because this is array to which is stored in struct created by arr2
        ptr->A[k++] = arr2.A[j];    //Iss statement se k ekhh aur baar increament krgea fhirr conditon false hooajyegi 
    ptr->lenght = k;   //k fhirr lenght of the array hoo jaayega
    return ptr;
}

//Intersection of the sorted sets
Array* IntersectionSorting(Array arr1,Array arr2)  
{
    Array* ptr = (Array*)malloc(sizeof(struct Array));     //Created an struct on heap using ptr
    int i = 0, j = 0, k = 0;  //It will trap the positive number on left side
    while (i < arr1.lenght && j < arr2.lenght)   //That comparison and copying will be done till one array all elements finshed
    {
        if (arr1.A[i] == arr2.A[j])
        {
            ptr->A[k++] = arr2.A[j++];
            i++;
        }
        else if (arr1.A[i] < arr2.A[j])
            i++;
        else
            j++;
    }
    ptr->lenght = k;   //k fhirr lenght of the array hoo jaayega
    return ptr;
}

Array* DifferenceSorted(Array arr1, Array arr2)   
{
    Array* ptr = (Array*)malloc(sizeof(struct Array));     //Created an struct on heap using ptr
    int i = 0, j = 0, k = 0;  //It will trap the positive number on left side
    while (i < arr1.lenght && j < arr2.lenght)   //That comparison and copying will be done till one array all elements finshed
    {
        if (arr1.A[i] == arr2.A[j])
        {
            j++;
            i++;
        }        
        else if (arr1.A[i] < arr2.A[j])
            ptr->A[k++] = arr1.A[i++];
        else
            j++;
    }
    for (; i < arr1.lenght; i++)
        ptr->A[k++] = arr1.A[i]; 
    ptr->lenght = k;   //k fhirr lenght of the array hoo jaayega
    return ptr;
}

//Unsorted arrays ka union,intersection and difference nhh hai course mai
int main()
{
    struct Array arr; // In menu driven program the user wil choose the array and give the values whatever he want
    int y;
    arr.lenght = 0;
    cout << "Give the size of the array" << endl;
    cin >> arr.size;
    arr.A = (int*)malloc(arr.size * sizeof(int));    //User se size legi aur heap mai array bnna degi
    //An menu driven program works like heve will have option and we will select it to perform operations
    cout << "Menu" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Search" << endl;
    cout << "4. Sum" << endl;
    cout << "5. Dispaly" << endl;
    cout << "6. Exit" << endl;
    int ch;// As ch will contain the choise
    //Now according to user choice we will perform operations
    do {
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
           
        case 1:
            int index;
            int x;
            cout << "Enter the index and the key to be inserted" << endl;
            cin >> index >> x;
            insert(&arr, index, x);
            break;
        case 2:
            int x1;
            cout << "Enter the index value to be deleted" << endl;
            cin >> index;  //Firse index sca matlab index ki value assign hooni
            x1 = Delete(&arr, index);
            cout << "Deleted value is " << x1;
            break;
        case 3:
            cout << "Enter the key to be search" << endl;
            cin >> y;
            index = LinearSearch(arr, y);
            cout << "Searched element is present at index" << endl;
            break;
        case 4:
            int sum;
            sum = Sum(arr);
            cout << "Sum of all the elements of array" << sum<< endl;
            break;
        case 5:
            display(arr);
            break;
        }
    } while (ch < 6);
    return 0;
}



//Left or right shift se welcome ko jaate huee dhekhaunga