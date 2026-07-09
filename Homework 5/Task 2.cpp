#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string getNodeInfo(const vector<int>& arr, int i) 
{
    ostringstream oss;
    if (i == 0) 
    {
        oss << "0 root " << arr[i];
    }
    else 
    {
        int level = (int)floor(log2(i + 1));
        int parentIdx = (i - 1) / 2;
        string relation = (i % 2 == 1) ? "left" : "right";
        oss << level << " " << relation << "(" << arr[parentIdx] << ") " << arr[i];
    }
    return oss.str();
}

void printArray(const vector<int>& arr) 
{
    cout << "Исходный массив:";
    for (int x : arr) cout << " " << x;
    cout << endl;
}

void printHeap(const vector<int>& arr) 
{
    cout << "Пирамида:" << endl;
    for (size_t i = 0; i < arr.size(); ++i) 
    {
        cout << getNodeInfo(arr, i) << endl;
    }
}

void printCurrent(const vector<int>& arr, int idx) 
{
    cout << "Вы находитесь здесь: " << getNodeInfo(arr, idx) << endl;
}

int main() 
{
    cout << "Введите массив пирамиды: " << endl;
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int x;
    
    while (ss >> x) 
    {
        arr.push_back(x);
    }

    if (arr.empty()) 
    {
        cerr << "Массив не введён или пуст." << endl;
        return 1;
    }

    printArray(arr);
    printHeap(arr);

    int current = 0;  

    while (true) 
    {
        printCurrent(arr, current);
        cout << "Введите команду: ";
        string cmd;
        cin >> cmd;

        if (cmd == "exit") 
        {
            break;
        }
        else if (cmd == "up") 
        {
            if (current == 0) 
            {
                cout << "Ошибка! Отсутствует родитель" << endl;
            }
            else 
            {
                current = (current - 1) / 2;
                cout << "Ок" << endl;
            }
        }
        else if (cmd == "left") 
        {
            int left = 2 * current + 1;
            if (left >= (int)arr.size()) 
            {
                cout << "Ошибка! Отсутствует левый потомок" << endl;
            }
            else 
            {
                current = left;
                cout << "Ок" << endl;
            }
        }
        else if (cmd == "right") 
        {
            int right = 2 * current + 2;
            if (right >= (int)arr.size()) 
            {
                cout << "Ошибка! Отсутствует правый потомок" << endl;
            }
            else 
            {
                current = right;
                cout << "Ок" << endl;
            }
        }
        else 
        {
            cout << "Ошибка! Неизвестная команда" << endl;
        }
    }

    return 0;
}