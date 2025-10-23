#include <iostream>
#include <cmath>



double calculat(double x) {
    return -sin(x - 5);
}

int main() {
    double num1;
    char contine;

    std::cout << "" << std::endl;

    do {

        std::cout << "Enter number: ";   
        std::cin >> num1;

        double result = calculat(num1);
        std::cout << "Otvet:" << result << std::endl;

        std::cout << "ready?  1 - yes, 2 - no" << std::endl;
        std::cin >> contine; 

    } while (contine == '1');

    std::cout << "goodbye" << std::endl;

    return 0;

}
