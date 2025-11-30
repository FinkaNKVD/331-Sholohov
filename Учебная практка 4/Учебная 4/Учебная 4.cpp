#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "=== Задание 1 ===" << endl;
    string str = "Приветсвую тебя добрый человек";
    char searchChar;

    cout << "Исходная строка: " << str << endl;
    cout << "Введите символ для поиска: ";
    cin >> searchChar;

    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == searchChar) {
            count++;
        }
    }

    if (count > 0) {
        cout << "Данный символ встречается в строке " << count << " раз" << endl;
    }
    else {
        cout << "Строка не содержит символ" << endl;
    }

    cout << endl;

    cout << "=== Задание 2 ===" << endl;
    string str2 = "Что ты хочешь со мной сделать???";
    char char1, char2;

    cout << "Исходная строка: " << str2 << endl;
    cout << "Введите символ для поиска: ";
    cin >> char1;
    cout << "Введите символ для замены: ";
    cin >> char2;

    bool found = false;
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] == char1) {
            str2[i] = char2;
            found = true;
        }
    }

    if (found) {
        cout << "Символ заменен" << endl;
        cout << "Новая строка: " << str2 << endl;
    }
    else {
        cout << "Символ не найден" << endl;
    }

    cout << endl;

    cout << "=== Задание 3 ===" << endl;
    int arr[10] = { 5, 2, 8, 1, 9, 3, 7, 4, 6, 0 };
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int searchNumber;
    cout << "Введите число для поиска: ";
    cin >> searchNumber;

    bool numberFound = false;
    int position = -1;

    for (int i = 0; i < 10; i++) {
        if (arr[i] == searchNumber) {
            numberFound = true;
            position = i;
            break;
        }
    }

    if (numberFound) {
        cout << "Число найдено на позиции: " << position << endl;
    }
    else {
        cout << "Число не найдено" << endl;
    }

    return 0;
}