#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


class Account {
private:
    string accountName;
    double balance;
    double expense;
    double income;
    double remainder;

public:
    static double totalMoney;


    Account(string name, double initialBalance) {
        accountName = name;
        balance = initialBalance;
        expense = 0;
        income = 0;
        remainder = initialBalance;
        totalMoney += initialBalance;
    }


    void addExpense(double amount) {
        expense += amount;
        remainder -= amount;
        totalMoney -= amount;
        cout << "Raskhod: " << amount << " rub." << endl;
    }


    void addIncome(double amount) {
        income += amount;
        remainder += amount;
        totalMoney += amount;
        cout << "Dohod: " << amount << " rub." << endl;
    }


    void showInfo() {
        cout << "\n--- Informaciya o schete '" << accountName << "' ---" << endl;
        cout << "Saldo: " << balance << " rub." << endl;
        cout << "Raskhod: " << expense << " rub." << endl;
        cout << "Dohod: " << income << " rub." << endl;
        cout << "Ostatok: " << remainder << " rub." << endl;
    }
};


double Account::totalMoney = 0;


string getBankGreeting() {
    return "Vas privetstvuet Nash Bank!";
}


class Bank {
protected:
    double bankPercent;

public:
    Bank(double percent) {
        bankPercent = percent;
    }


    virtual void getPercent(double sum) {
        double result = sum * bankPercent / 100;
        cout << "Vash procent po banku sostavlyaet: " << result << " rub." << endl;
    }
};


class MicroBank : public Bank {
private:
    double microPercent;

public:

    MicroBank(double micro, double bank) : Bank(bank) {
        microPercent = micro;
    }


    void getPercent(double sum) override {
        double totalPercent = microPercent + bankPercent;
        double result = sum * totalPercent / 100;
        cout << "Vash procent po mikrobanku sostavlyaet: " << result << " rub." << endl;
        cout << "(bankPercent: " << bankPercent << "%, microPercent: " << microPercent << "%)" << endl;
    }
};

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "=== PRAKTICHESKOE ZADANIE PO VIRTUALNYM FUNKCIYAM ===" << endl;


    cout << "\n--- Zadanie 1 i 2 ---" << endl;
    cout << getBankGreeting() << endl;


    string name1, name2;
    double balance1, balance2;

    cout << "\nSozdanie schetov:" << endl;
    cout << "Vvedite nazvanie pervogo scheta: ";
    cin >> name1;
    cout << "Vvedite nachalnoe saldo dlya scheta '" << name1 << "': ";
    cin >> balance1;

    cout << "Vvedite nazvanie vtorogo scheta: ";
    cin >> name2;
    cout << "Vvedite nachalnoe saldo dlya scheta '" << name2 << "': ";
    cin >> balance2;


    Account account1(name1, balance1);
    Account account2(name2, balance2);


    cout << "\nOperacii po schetam:" << endl;

    double income1, expense1, income2, expense2;

    cout << "Vvedite dohod dlya scheta '" << name1 << "': ";
    cin >> income1;
    account1.addIncome(income1);

    cout << "Vvedite raskhod dlya scheta '" << name1 << "': ";
    cin >> expense1;
    account1.addExpense(expense1);

    cout << "Vvedite dohod dlya scheta '" << name2 << "': ";
    cin >> income2;
    account2.addIncome(income2);

    cout << "Vvedite raskhod dlya scheta '" << name2 << "': ";
    cin >> expense2;
    account2.addExpense(expense2);


    account1.showInfo();
    account2.showInfo();

    cout << "\nVsego deneg v kasse: " << Account::totalMoney << " rub." << endl;


    cout << "\n--- Zadanie 3 ---" << endl;


    double bankPercent, microPercent, sum;

    cout << "Vvedite procent dlya obychnogo banka (%): ";
    cin >> bankPercent;

    cout << "Vvedite dopolnitelny procent dlya mikrobanka (%): ";
    cin >> microPercent;

    cout << "Vvedite summu dlya rascheta procentov: ";
    cin >> sum;


    Bank regularBank(bankPercent);
    MicroBank microBank(microPercent, bankPercent);

    cout << "\nObychny bank (" << bankPercent << "%):" << endl;
    regularBank.getPercent(sum);

    cout << "\nMikrobank (" << bankPercent << "% + " << microPercent << "%):" << endl;
    microBank.getPercent(sum);


    cout << "\n--- Demonstraciya polimorfizma ---" << endl;
    Bank* bankPtr;

    cout << "Ukazatel na obychny bank:" << endl;
    bankPtr = &regularBank;
    bankPtr->getPercent(sum);

    cout << "\nUkazatel na mikrobank:" << endl;
    bankPtr = &microBank;
    bankPtr->getPercent(sum);

    return 0;
}