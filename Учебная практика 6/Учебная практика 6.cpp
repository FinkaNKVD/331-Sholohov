#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


void swapEvenOdd(int* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}


void decrementWithoutPointer(int x) {
    x--;
    cout << "Decrement without pointer: " << x << endl;
}

void decrementWithPointer(int* x) {
    (*x)--;
    cout << "Decrement with pointer: " << *x << endl;
}


class iPhone {
public:
    double diagonal;
    double processorFrequency;

    string showiPhone() {
        return "Phone type: iPhone with diagonal " + to_string(diagonal) +
            " and frequency " + to_string(processorFrequency) + " GHz";
    }
};

class Xiaomi {
public:
    double diagonal;
    double processorFrequency;

    string showXiaomi() {
        return "Phone type: Xiaomi with diagonal " + to_string(diagonal) +
            " and frequency " + to_string(processorFrequency) + " GHz";
    }
};

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    cout << "=== Task 1 ===" << endl;
    int size = 6;
    int* arr = new int[size];


    for (int i = 0; i < size; i++) {
        cout << "Enter " << (i + 1) << "-th element: ";
        cin >> arr[i];
    }


    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    swapEvenOdd(arr, size);
    cout << "Modified array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    delete[] arr;


    cout << "=== Task 2 ===" << endl;
    int number = 10;
    cout << "Original value: " << number << endl;
    decrementWithoutPointer(number);
    cout << "Value after call without pointer: " << number << endl;

    decrementWithPointer(&number);
    cout << "Value after call with pointer: " << number << endl << endl;


    cout << "=== Task 3 ===" << endl;


    iPhone iphone;
    iphone.diagonal = 6.1;
    iphone.processorFrequency = 3.2;

    Xiaomi xiaomi;
    xiaomi.diagonal = 6.5;
    xiaomi.processorFrequency = 2.8;

    string(iPhone:: * showIphonePtr)() = &iPhone::showiPhone;
    string(Xiaomi:: * showXiaomiPtr)() = &Xiaomi::showXiaomi;


    cout << (iphone.*showIphonePtr)() << endl;
    cout << (xiaomi.*showXiaomiPtr)() << endl;

    return 0;
}