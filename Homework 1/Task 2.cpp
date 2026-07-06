#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

int countGreater(const vector<int>& arr, int target) 
{
    int left = 0;
    int right = static_cast<int>(arr.size()); 

    while (left < right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) 
        {
            left = mid + 1;
        }
        else 
        {
            right = mid;
        }
    }

    return static_cast<int>(arr.size()) - left;
}

int main(int argc, char** argv)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    vector<int> arr = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };

    int target;
    cout << "Введите точку отсчёта: ";
    cin >> target;

    int result = countGreater(arr, target);
    cout << "Количество элементов в массиве больших, чем " << target << ": " << result << endl;

    return 0;
}