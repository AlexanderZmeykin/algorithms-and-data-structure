#include <iostream>

using namespace std;

void print_pyramid(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        {
        int level = 0;
        while ((1 << (level + 1)) - 1 <= i)
        {
            ++level;
        }

        cout << level << " ";

        if (i == 0)
        {
            cout << "root ";
        }
        else
        {
            int parent = (i - 1) / 2;
            if (i % 2 == 1)
            {
                cout << "left(" << arr[parent] << ") ";
            }
            else
            {
                cout << "right(" << arr[parent] << ") ";
            }
        }

        cout << arr[i] << endl;
    }
}

void print_array(const int arr[], int size)
{
    cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i];
        if (i != size - 1) cout << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {1, 3, 6, 5, 9, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    print_array(arr1, size1);
    cout << "Пирамида:" << endl;
    print_pyramid(arr1, size1);
    cout << endl;

    int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    print_array(arr2, size2);
    cout << "Пирамида:" << endl;
    print_pyramid(arr2, size2);
    cout << endl;

    int arr3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    print_array(arr3, size3);
    cout << "Пирамида:" << endl;
    print_pyramid(arr3, size3);

    return 0;
}
