#include <iostream>
#include <vector>
#include <algorithm>

double getAverage(const std::vector<double>& operands) {
    double sum = 0;
    for (const double& operand : operands) {
        sum += operand;
    }
    return sum / operands.size(); 
}

double getMedian(const std::vector<double>& operands) {
    std::vector<double> sortedOperands(operands);
    std::sort(sortedOperands.begin(), sortedOperands.end());
    
    if (operands.size() % 2 == 0) {
        return (sortedOperands[operands.size() / 2 - 1] + sortedOperands[operands.size() / 2]) / 2;
    } else {
        return sortedOperands[operands.size() / 2];
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "Использование калькулятора: СНАЧАЛА 8 - 10 ОПЕРРАНДОВ, потом -o или --operation, затем название операции: \n";
        std::cout << "1) median\n";
        std::cout << "2) average\n";
        std::cout << "Пример: ./hello 8 8 8 8 8 8 8 8 8 9 -o median\n";
        return 0;
    }
    
    std::vector<double> operands;
    std::string operation;
    
    for (int i = 1; i < argc - 2; i++) {
        double operand;
        try {
            operand = std::stod(argv[i]);
        } catch (const std::exception& e) {
            std::cout << "Error: Invalid operand format\n";
            return 1;
        }
        operands.push_back(operand);
    }
    
    operation = argv[argc - 2];
    
    if (operation == "-o" || operation == "--operation") {
        operation = argv[argc - 1];
    } else {
        std::cout << "Error: Invalid operation parameter\n";
        std::cout << "Использование калькулятора: СНАЧАЛА 8 - 10 ОПЕРРАНДОВ, потом -o или --operation, затем название операции: \n";
        std::cout << "1) median\n";
        std::cout << "2) average\n";
        std::cout << "Пример: ./hello 8 8 8 8 8 8 8 8 8 9 -o median\n";
        return 1;
    }
    
    if (operands.size() < 8 || operands.size() > 10) {
        std::cout << "Error: Invalid number of operands\n";
        std::cout << "Использование калькулятора: СНАЧАЛА 8 - 10 ОПЕРРАНДОВ, потом -o или --operation, затем название операции: \n";
        std::cout << "1) median\n";
        std::cout << "2) average\n";
        std::cout << "Пример: ./hello 8 8 8 8 8 8 8 8 8 9 -o median\n";
        return 1;
    }
    
    
    if (operation == "average") {
        std::cout << "Среднее значение: " << getAverage(operands) << std::endl;
    } else if (operation == "median") {
        std::cout << "Медиана: " << getMedian(operands) << std::endl;
      }
      
      else {
        std::cout << "Error: Invalid operation\n";
        std::cout << "Использование калькулятора: СНАЧАЛА 8 - 10 ОПЕРРАНДОВ, потом -o или --operation, затем название операции: \n";
        std::cout << "1) median\n";
        std::cout << "2) average\n";
        std::cout << "Пример: ./hello 8 8 8 8 8 8 8 8 8 9 -o median\n";
        return 1;
    }
    
    return 0;
}
