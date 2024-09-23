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
//        std::cout << "�� ����� ������." << std::endl;
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
//        std::cout << "������� ������� ��� ������ ���������: " << costPerMinute << " grn/m." << std::endl;
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

    std::cout << "����:\n";
    std::cout << "1. ����������, ������ ����� ���� ����� �������� ��� �������� ������.\n";
    std::cout << "2. ����������, ������ ���� ����� ���������� ��� �������� ������.\n";
    std::cout << "3. ����������, ������ ������ ��������� ���.\n";
    std::cout << "������ ���� (1-3): ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        double desiredIncome;
        int lateCount;
        std::cout << "������ ������� �����: ";
        std::cin >> desiredIncome;
        std::cout << "������ ������� ��������: ";
        std::cin >> lateCount;

        double totalFine = (lateCount / 3) * finePerLate;
        int requiredLines = (desiredIncome + totalFine) / (paymentPer100Lines / 100);

        std::cout << "��������� �������� " << requiredLines << " ����� ����." << std::endl;
        break;
    }
    case 2: {
        int writtenLines;
        double desiredIncome;
        std::cout << "������ ������� ��������� �����: ";
        std::cin >> writtenLines;
        std::cout << "������ ������� ����� ��������: ";
        std::cin >> desiredIncome;

        double earnedMoney = (writtenLines / 100) * paymentPer100Lines;
        int maxLate = ((earnedMoney - desiredIncome) / finePerLate) * 3;

        std::cout << "����������� ������� ��������: " << maxLate << std::endl;
        break;
    }
    case 3: {
        int writtenLines, lateCount;
        std::cout << "������ ������� ��������� �����: ";
        std::cin >> writtenLines;
        std::cout << "������ ������� ��������: ";
        std::cin >> lateCount;

        double earnedMoney = (writtenLines / 100) * paymentPer100Lines;
        double totalFine = (lateCount / 3) * finePerLate;
        double finalIncome = earnedMoney - totalFine;

        if (finalIncome > 0)
            std::cout << "��� ���������: " << finalIncome << " $" << std::endl;
        else
            std::cout << "��� �� ��������� ����� ������." << std::endl;
        break;
    }
    default:
        std::cout << "������������ ����!" << std::endl;
    }

    return 0;
}
