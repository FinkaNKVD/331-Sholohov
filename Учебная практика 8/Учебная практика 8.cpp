#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void sortWords() {
    cout << "=== ZADANIE 1: SORTIROVKA SLOV IZ FAILA ===" << endl;

    vector<string> words;
    string word;


    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Oshibka: ne udalos otkryt file input.txt" << endl;
        return;
    }

    cout << "Chitaem slova iz faila input.txt..." << endl;
    while (inputFile >> word) {
        words.push_back(word);
        cout << "Prochitano slovo: " << word << endl;
    }
    inputFile.close();


    sort(words.begin(), words.end());


    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cout << "Oshibka: ne udalos sozdat file output.txt" << endl;
        return;
    }

    cout << "\nZapisivaem otsortirovannye slova v output.txt..." << endl;
    for (const string& w : words) {
        outputFile << w << endl;
        cout << "Zapisano slovo: " << w << endl;
    }
    outputFile.close();

    cout << "Sortirovka zavershena! Rezultat v failе output.txt" << endl;
}


void workWithNumbers() {
    cout << "\n=== ZADANIE 2: RABOTA S CHISLAMI ===" << endl;

    double number;


    cout << "Vvedite chislo dlya zapisi v fail primer1.txt: ";
    cin >> number;

    ofstream file1("primer1.txt");
    if (file1.is_open()) {
        file1 << number;
        file1.close();
        cout << "Chislo " << number << " uspeshno zapisano v primer1.txt" << endl;
    }
    else {
        cout << "Oshibka sozdaniya faila primer1.txt" << endl;
        return;
    }


    ifstream readFile1("primer1.txt");
    if (readFile1.is_open()) {
        double readNumber;


        if (readFile1 >> readNumber) {

            double result = readNumber * 0.5;

            ofstream file2("primer2.txt");
            if (file2.is_open()) {
                file2 << "50% ot chisla " << readNumber << " = " << result;
                file2.close();
                cout << "Rezultat vychisleniya zapisan v primer2.txt: " << result << endl;
            }
        }
        else {

            cout << "V faile stroka. Neobhodimo chislo" << endl;
        }
        readFile1.close();
    }
    else {
        cout << "Oshibka chteniya faila primer1.txt" << endl;
    }
}

int main() {

    system("chcp 65001 > nul");

    cout << "RABOTA S POTOKAMI I FAILAMI" << endl;
    cout << "============================" << endl;


    sortWords();
    workWithNumbers();

    cout << "\nProgramma zavershena." << endl;
    cout << "Proverte soderzhimoe failov:" << endl;
    cout << "- input.txt (ishodnye slova)" << endl;
    cout << "- output.txt (otsortirovannye slova)" << endl;
    cout << "- primer1.txt (vvedennoe chislo)" << endl;
    cout << "- primer2.txt (50% ot chisla)" << endl;

    return 0;
}