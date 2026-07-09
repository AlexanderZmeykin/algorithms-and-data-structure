#include <iostream>
using namespace std;

void print_dynamic_array(int* arr, int actual_size, int logical_size)
{
    for (int i = 0; i < actual_size; ++i)
    {
        if (i < logical_size)
            cout << arr[i];
        else
            cout << '_';
        if (i != actual_size - 1)
            cout << ' ';
    }
    cout << endl;
}

void append_to_dynamic_array(int** arr, int& actual_size, int& logical_size, int value)
{
    if (logical_size < actual_size)
    {
        // Есть свободное место
        (*arr)[logical_size] = value;
        ++logical_size;
    }
    else
    {
        int new_actual = actual_size * 2;
        int* new_arr = new int[new_actual];
        for (int i = 0; i < logical_size; ++i)
            new_arr[i] = (*arr)[i];
        new_arr[logical_size] = value;
        delete[] * arr;
        *arr = new_arr;
        actual_size = new_actual;
        ++logical_size;
    }
}

int main()
{
    int actual_size, logical_size;

    do {
        cout << "Введите фактичеcкий размер массива: ";
        cin >> actual_size;
        cout << "Введите логический размер массива: ";
        cin >> logical_size;
        if (logical_size > actual_size)
        {
            cout << "Ошибка! Логический размер массива не может превышать фактический!" << endl;
        }
    } while (logical_size > actual_size);

    int* arr = new int[actual_size];
    for (int i = 0; i < logical_size; ++i)
    {
        cout << "Введите arr[" << i << "]: ";
        cin >> arr[i];
    }

    print_dynamic_array(arr, actual_size, logical_size);

    while (true)
    {
        cout << "Введите элемент для добавления: ";
        int value;
        cin >> value;
        if (value == 0)
            break;
        append_to_dynamic_array(&arr, actual_size, logical_size, value);
        print_dynamic_array(arr, actual_size, logical_size);
    }

    cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, actual_size, logical_size);

    delete[] arr;
    return 0;
}
