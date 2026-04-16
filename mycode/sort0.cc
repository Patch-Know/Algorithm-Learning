#include <iostream>

using namespace std;

void sort_select(int a[], int n);
void sort_bubble(int a[], int n);
void sort_insert(int a[], int n);
void show(int a[], int n);
void setnum(int a[], int n, int k);
void swap0(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    const int n1 = 1980;
    const int k1 = 226;
    int a0[n1];

    setnum(a0, n1, k1);
    cout << "Initial array: \n";
    show(a0, n1);
    cout << "\nSort(select): \n";
    sort_select(a0, n1);
    show(a0, n1);

    setnum(a0, n1, k1);
    cout << "\nInitial array: \n";
    show(a0, n1);
    cout << "\nSort(bubble): \n";
    sort_bubble(a0, n1);
    show(a0, n1);

    setnum(a0, n1, k1);
    cout << "\nInitial array: \n";
    show(a0, n1);
    cout << "\nSort(insert): \n";
    sort_insert(a0, n1);
    show(a0, n1);

    return 0;
}

void sort_select(int a[], int n)
{
    int min, pmin;
    for (int i = 0; i < n - 1; i++)
    {
        pmin = i;
        min = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                pmin = j;
                min = a[j];
            }
        }
        swap0(&a[i], &a[pmin]);
    }
}

void sort_bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap0(&a[j], &a[j + 1]);
        }
    }
}

void sort_insert(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (a[j] < a[j - 1])
        {
            swap0(&a[j], &a[j - 1]);
            j--;
        }
    }
}

void show(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
        if ((i + 1) % 20 == 0)
            cout << endl;
    }
}

void setnum(int a[], int n, int k)
{
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % k + 1;
    }
}
