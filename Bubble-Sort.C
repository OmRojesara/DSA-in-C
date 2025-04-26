#include<stdio.h>
#include<conio.h>

void ReadArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

void PrintArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Arr[%d]: %d\n", i, arr[i]);
    }
}

void Bubble_Sort(int arr[], int n)
{
    int i, j, temp, flag;
    for(i = 0; i < n - 1; i++)
    {
        flag = 1;
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                flag = 1;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}

void Selection_Sort(int arr[], int n)
{
    int i, j, min_index, temp;

    for(i = 0; i < n - 1; i++)
    {
        min_index = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if(i != min_index)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void Insertion_Sort(int arr[], int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        j = i - 1;
        temp = arr[i];
        while(j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}


int a[100];

void Quick_Sort(int L, int R)
{
    int Pivot, i = L, left, Right, M;
    Pivot = a[i];
    left = L;
    Right = R;

    while(a[R] > Pivot && L < R)
    {
        R--;
    }
    if(L != R)
    {
        a[L] = a[R];
        L++;
    }

    while(a[L] < Pivot && L < R)
    {
        L++;
    }
    if(L != R)
    {
        a[R] = a[i];
        R--;
    }

    a[L] = Pivot;
    M = L;
    R = Right;
    L = left;

    if(L < M)
    {
        Quick_Sort(L, M - 1);
    }
    if(M < R)
    {
        Quick_Sort(M + 1, R);
    }
}

int main()
{
    int n, choice;
    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    ReadArray(a, n);

    printf("\nChoose Sorting Method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            Bubble_Sort(a, n);
            break;
        case 2:
            Selection_Sort(a, n);
            break;
        case 3:
            Insertion_Sort(a, n);
            break;
        case 4:
            Quick_Sort(0, n - 1);
            break;
        default:
            printf("Invalid choice! Exiting...");
            getch();
            return 0;
    }

    printf("\nSorted Array:\n");
    PrintArray(a, n);

    getch();
    return 0;
}
