#include <iostream>
#include <string>

double powerOf(double num1, int num2, double &num1Ptr){
    if (num2 == 0) return 1;
    else if (num2 == 1) return num1;
    else (num2 > 1){
        num1 = num1 * num1Ptr;
        --num2;
        return powerOf(num1, num2, num1Ptr);
    }
}

std::string powerOutput(double &num1, double &num2){
    //int num1Whole = (int)num1;
    int num2Whole = (int)num2;
    
    if 
    
    powerOutput(num1, num2, num1)
}

int main() {
    
    //get inputs
    double num1, num2;
    std::cout << "Please enter the needed number\n"
                << "first number: ";
    std::cin >> num1;
    std::cout << "second number: ";
    std::cin >> num2;
    
    std::cout << num1 <<" to the power of " << num2 << " is " << powerOutput(num1, num2) << "\n";
    return 0;
}
