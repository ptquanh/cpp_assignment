#include <iostream>
#include <string>
#include <sstream>
using namespace std;
typedef unsigned int uint;

class dateStructure {
private:
    uint month;
    uint day;
    uint year;

public:
    dateStructure() : month(0), day(0), year(0) {}

    // Get date from user in mm/dd/yy format
    void getdate() {
        string date;
        cout << "Enter date in mm/dd/yy format: ";
        getline(cin, date);
        month = stoi(date.substr(0, 2));
        day = stoi(date.substr(3, 2));
        year = stoi(date.substr(6, 2));
        // Check if the date is valid
        if (!checkDate()) {
            cout << "INVALID! Please enter again: " << endl;
            getdate();
        }
    }

    // Display date in dd/mm/yy format
    void showdate() const {
        cout << "Display date in dd/mm/yy format: ";
        cout << (day < 10 ? "0" : "") << day << "/"
        << (month < 10 ? "0" : "") << month << "/"
        << (year < 10 ? "0" : "") << year << endl;
    }

    // Check if the date is valid
    bool checkDate() const {
        // Check for valid day, month, year
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
        if (month == 2 && day > 29) return false;
        if (year > 99) return false;
        return true;
    }
};

int main() {
    dateStructure *today= new dateStructure;
    today->getdate();
    today->showdate();
    return 0;
}
