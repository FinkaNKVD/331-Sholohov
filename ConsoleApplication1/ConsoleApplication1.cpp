

#include <iostream>
#include <cmath>

int main(){
double num1, num2, max_num, chislo ;

     std::cout << "Enter the first number: ";   //вводим первое число
     std::cin >> num1;

     std::cout << "Enter the second number: ";  //вводим второе число 
     std::cin >> num2;

     if (num1 > num2) {
         max_num = num1;
     }
     else {
         max_num = num2;
     }

     chislo = -sin(max_num - 5);

     std::cout << "High number:" << max_num << std::endl; 
     std::cout << "Otvet:" << chislo ;

     return 0;

}

