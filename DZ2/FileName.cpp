#include <iostream>
#include <cctype>
//
//int main() {
//    char symbol;
//    std::cout << "Write symbol ";
//    std::cin >> symbol;
//
//    if (std::isalpha(symbol))
//        std::cout << "this is letter." << std::endl;
//    else if (std::isdigit(symbol))
//        std::cout << "this is number." << std::endl;
//    else if (std::ispunct(symbol))
//        std::cout << "This is a punctuation mark." << std::endl;
//    else
//        std::cout << "Це інший символ." << std::endl;
//
//    return 0;
//}





//int main2() {
//    double costPerMinute;
//    int fromOperator, toOperator;
//
//    std::cout << "Enter the cost of the call (per minute): ";
//    std::cin >> costPerMinute;
//
//    std::cout << "Choose from which operator you are calling (1 - Operator A, 2 - Operator B, 3 - Operator C): ";
//    std::cin >> fromOperator;
//
//    std::cout << "Choose which operator you are calling (1 - Operator A, 2 - Operator B, 3 - Operator C): ";
//    std::cin >> toOperator;
//
//    if (fromOperator == toOperator) {
//        std::cout << "Вартість розмови для одного оператора: " << costPerMinute << " grn/m." << std::endl;
//    }
//    else {
//        double extraCharge = 0.5;
//        std::cout << "Call cost for different operators: " << costPerMinute + extraCharge << " grn/m." << std::endl;
//    }
//
//    return 0;











#include <iostream>

const double paymentPer100Lines = 50.0;
const double finePerLate = 20.0;

int main() {
    int choice;

    std::cout << "Меню:\n";
    std::cout << "1. Порахувати, скільки рядків коду треба написати для бажаного доходу.\n";
    std::cout << "2. Порахувати, скільки разів можна запізнитися для бажаного доходу.\n";
    std::cout << "3. Порахувати, скільки грошей заплатять Васі.\n";
    std::cout << "Зробіть вибір (1-3): ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        double desiredIncome;
        int lateCount;
        std::cout << "Введіть бажаний дохід: ";
        std::cin >> desiredIncome;
        std::cout << "Введіть кількість запізнень: ";
        std::cin >> lateCount;

        double totalFine = (lateCount / 3) * finePerLate;
        int requiredLines = (desiredIncome + totalFine) / (paymentPer100Lines / 100);

        std::cout << "Необхідно написати " << requiredLines << " рядків коду." << std::endl;
        break;
    }
    case 2: {
        int writtenLines;
        double desiredIncome;
        std::cout << "Введіть кількість написаних рядків: ";
        std::cin >> writtenLines;
        std::cout << "Введіть бажаний обсяг зарплати: ";
        std::cin >> desiredIncome;

        double earnedMoney = (writtenLines / 100) * paymentPer100Lines;
        int maxLate = ((earnedMoney - desiredIncome) / finePerLate) * 3;

        std::cout << "Максимальна кількість запізнень: " << maxLate << std::endl;
        break;
    }
    case 3: {
        int writtenLines, lateCount;
        std::cout << "Введіть кількість написаних рядків: ";
        std::cin >> writtenLines;
        std::cout << "Введіть кількість запізнень: ";
        std::cin >> lateCount;

        double earnedMoney = (writtenLines / 100) * paymentPer100Lines;
        double totalFine = (lateCount / 3) * finePerLate;
        double finalIncome = earnedMoney - totalFine;

        if (finalIncome > 0)
            std::cout << "Васі заплатять: " << finalIncome << " $" << std::endl;
        else
            std::cout << "Васі не заплатять через штрафи." << std::endl;
        break;
    }
    default:
        std::cout << "Неправильний вибір!" << std::endl;
    }

    return 0;
}
