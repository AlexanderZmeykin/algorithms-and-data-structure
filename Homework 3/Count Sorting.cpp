#include <iostream>
#include <vector>

void count_sort(int* arr, int size) 
{
    const int MIN_VAL = 10;
    const int MAX_VAL = 24;
    const int RANGE = MAX_VAL - MIN_VAL + 1;  

    int count[RANGE] = { 0 };

    for (int i = 0; i < size; ++i) 
    {
        int val = arr[i];
        count[val - MIN_VAL]++;
    }

    int idx = 0;
    for (int i = 0; i < RANGE; ++i) 
    {
        while (count[i] > 0) 
        {
            arr[idx++] = i + MIN_VAL;
            count[i]--;
        }
    }
}

void print_array(int* arr, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        std::cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() 
{
    int arr1_data[] = 
    {
        19, 14, 22, 22, 17, 22, 13, 21, 20, 24,
        18, 10, 17, 16, 17, 20, 22, 11, 20, 16,
        14, 13, 10, 22, 18, 14, 16, 24, 19, 17
    };

    int size1 = sizeof(arr1_data) / sizeof(arr1_data[0]);
    std::vector<int> vec1(arr1_data, arr1_data + size1);

    std::cout << "Массив 1 до сортировки:" << std::endl;
    print_array(vec1.data(), size1);
    count_sort(vec1.data(), size1);
    std::cout << "Массив 1 после сортировки:" << std::endl;
    print_array(vec1.data(), size1);
    std::cout << std::endl;

    int arr2_data[] = 
    {
        16, 17, 14, 20, 22, 20, 17, 22, 16, 19,
        23, 24, 20, 22, 21, 18, 14, 16, 17, 21,
        10, 11, 19, 23, 11, 11, 17, 17, 11, 21,
        17, 11, 17, 16, 12, 11, 16, 22, 23, 16
    };

    int size2 = sizeof(arr2_data) / sizeof(arr2_data[0]);
    std::vector<int> vec2(arr2_data, arr2_data + size2);

    std::cout << "Массив 2 до сортировки:" << std::endl;
    print_array(vec2.data(), size2);
    count_sort(vec2.data(), size2);
    std::cout << "Массив 2 после сортировки:" << std::endl;
    print_array(vec2.data(), size2);
    std::cout << std::endl;

    int arr3_data[] = 
    {
        21, 15, 19, 18, 23, 12, 18, 18, 19, 23,
        12, 20, 15, 22, 21, 18, 19, 20, 12, 16,
        20, 14, 17, 13, 10, 23, 19, 14, 10, 22,
        19, 12, 24, 23, 22, 15, 13, 22, 18, 18,
        11, 23, 24, 17, 10
    };

    int size3 = sizeof(arr3_data) / sizeof(arr3_data[0]);
    std::vector<int> vec3(arr3_data, arr3_data + size3);

    std::cout << "Массив 3 до сортировки:" << std::endl;
    print_array(vec3.data(), size3);
    count_sort(vec3.data(), size3);
    std::cout << "Массив 3 после сортировки:" << std::endl;
    print_array(vec3.data(), size3);

    return 0;
}