#include <iostream>
using namespace std;
typedef unsigned int uint;

class dateStructure {
    public:
    uint month;
    uint date;
    uint year;
    void getDate(uint &month, uint &date, uint &year);
    void showDate(uint date, uint month, uint year);
    bool checkDate(uint date, uint month, uint year);
};

bool dateStructure::checkDate(uint date, uint month, uint year) {
    if((1<=date && date<=31) && (1<=month && month<=12) && (year <=99)) return true;
    else return false;
}


//getDate function
void dateStructure::getDate(uint &month, uint &date, uint &year) {
    cout << "Date Format: mm/dd/yy \n";
    cin >> month >> date >> year;
    if(checkDate(date,month,year)==false) {
        cout << "INVALID \n";
        getDate(month,date,year);
    }
}

void dateStructure::showDate(uint date, uint month, uint year) {
    cout << "Date Format: dd/mm/yy \n";
    printf("%02d %02d %02d", date, month,year);
}

int main() {
    dateStructure dateObj;
    dateObj.getDate(dateObj.month,dateObj.date,dateObj.year);
    dateObj.showDate(dateObj.date,dateObj.month,dateObj.year);
}