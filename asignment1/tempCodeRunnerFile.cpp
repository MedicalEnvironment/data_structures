#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

bool isDateFormatValid(const std::string& date) {
     std::regex pattern("^\\d{4}-\\{2}-\\d{2}$");
     return std::regex_match(date, pattern);
}

struct Bill {
    std::string name;
    std::string date;
    double amount;
};

std::vector<Bill> readBills(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Bill> bills;

    while(!file.eof()) {
        Bill bill;
        file >> bill.name;
        if (bill.name.empty()) break;  // End of file
        file >> bill.date >> bill.amount;
        bills.push_back(bill);
    }

    return bills;
}

void addBill(const std::string& filename, const Bill& bill) {
    std::ofstream file(filename, std::ios::app);  // Open file in append mode
    file << bill.name << ' ' << bill.date << ' ' << bill.amount << '\n';
}

int main() {
    std::cout << "add or list?";
    std::string command;
    std::cin >> command;

    if (command == "list") {
        std::vector<Bill> bills = readBills("bills.txt");
        for (const Bill& bill : bills) {
            std::cout << bill.name << ' ' << bill.date << ' ' << bill.amount << '\n';
        }
    } else if (command == "add") {
        std::cout << "Input a date format: YYYY.MM.DD";
        Bill bill;
        std::cin >> bill.name >> bill.date >> bill.amount;
        
        if(!isDateFormatValid(bill.date)) {
        std::cout << "Invalid date format";
        return 1;
        }
        
        addBill("bills.txt", bill);
    }

    return 0;
}
