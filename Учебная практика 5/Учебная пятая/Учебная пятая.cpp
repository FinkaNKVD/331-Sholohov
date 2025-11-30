#include <iostream>
#include <string>
using namespace std;


class Car {
public:
    string name;
    int speed;

    Car(string n, int s) {
        name = n;
        speed = s;
    }

    bool operator==(const Car& other) {
        return name == other.name && speed == other.speed;
    }

    bool operator<(const Car& other) {
        return speed < other.speed;
    }

    bool operator>(const Car& other) {
        return speed > other.speed;
    }
};


class Account {
public:
    string name;
    double balance;
    double expense;
    double income;

    Account(string n, double b, double e, double i) {
        name = n;
        balance = b;
        expense = e;
        income = i;
    }

    void operator++() {
        income += 1;
        balance += 1;
    }

    void operator--() {
        expense += 1;
        balance -= 1;
    }

    void operator+(double value) {
        if (value > 0) {
            income += value;
            balance += value;
        }
        else if (value < 0) {
            expense += (-value);
            balance += value;
        }
    }
};

int main() {

    cout << "=== Testing Car class ===" << endl;

    string carName1, carName2;
    int carSpeed1, carSpeed2;

    cout << "Enter first car name: ";
    cin >> carName1;
    cout << "Enter first car speed: ";
    cin >> carSpeed1;

    cout << "Enter second car name: ";
    cin >> carName2;
    cout << "Enter second car speed: ";
    cin >> carSpeed2;

    Car car1(carName1, carSpeed1);
    Car car2(carName2, carSpeed2);

    cout << "\nCar comparison results:" << endl;
    cout << "car1 == car2: " << (car1 == car2) << endl;
    cout << "car1 < car2: " << (car1 < car2) << endl;
    cout << "car1 > car2: " << (car1 > car2) << endl;


    cout << "\n=== Testing Account class ===" << endl;

    string accName;
    double startBalance, startExpense, startIncome;

    cout << "Enter account name: ";
    cin >> accName;
    cout << "Enter starting balance: ";
    cin >> startBalance;
    cout << "Enter starting expense: ";
    cin >> startExpense;
    cout << "Enter starting income: ";
    cin >> startIncome;

    Account acc(accName, startBalance, startExpense, startIncome);

    cout << "\nInitial account state:" << endl;
    cout << "Name: " << acc.name << endl;
    cout << "Balance: " << acc.balance << endl;
    cout << "Expense: " << acc.expense << endl;
    cout << "Income: " << acc.income << endl;


    ++acc;
    cout << "\nAfter ++ (increment):" << endl;
    cout << "Balance: " << acc.balance << endl;
    cout << "Expense: " << acc.expense << endl;
    cout << "Income: " << acc.income << endl;

    --acc;
    cout << "\nAfter -- (decrement):" << endl;
    cout << "Balance: " << acc.balance << endl;
    cout << "Expense: " << acc.expense << endl;
    cout << "Income: " << acc.income << endl;

    double addValue;
    cout << "\nEnter value to add (positive for income, negative for expense): ";
    cin >> addValue;

    acc + addValue;
    cout << "\nAfter adding " << addValue << ":" << endl;
    cout << "Balance: " << acc.balance << endl;
    cout << "Expense: " << acc.expense << endl;
    cout << "Income: " << acc.income << endl;

    return 0;
}