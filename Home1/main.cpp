#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
bool isLeapYear(int year);

template <typename GigaArbyz>
void countElements(GigaArbyz arr[], int size, int& positiveCount, int& negativeCount, int& zeroCount);

int daysBetweenDates(unsigned int day1, unsigned int month1, unsigned int year1, unsigned int day2, unsigned int month2, unsigned int year2);

template <typename arrCount>
arrCount arrMidCount(arrCount arr[], int arrSize);


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int day1, month1, year1;
    int day2, month2, year2;

    int positiveCount, negativeCount, zeroCount;

	const int size = 6;
	float array[size]{ -4.2, 2.5, 6.5, 0, -1, 52 };
    std::cout << arrMidCount(array, size) << '\n';

    countElements(array, size, positiveCount, negativeCount, zeroCount);

    std::cout << "Положительные элементы: " << positiveCount << std::endl;
    std::cout << "Отрицательные элементы: " << negativeCount << std::endl;
    std::cout << "Нулевые элементы: " << zeroCount << '\n\n';

    std::cout << "Введите первую дату (формат: 4 12 2008) \n\n";
    std::cout << "Введите день: ";
    std::cin >> day1;
    std::cout << "Введите месяц: ";
    std::cin >> month1;
    std::cout << "Введите год: ";
    std::cin >> year1;

    std::cout << '\n';


    std::cout << "Введите вторую дату (формат: 4 12 2008) ";
    std::cout << "Введите день: ";
    std::cin >> day2;
    std::cout << "Введите месяц: ";
    std::cin >> month2;
    std::cout << "Введите год: ";
    std::cin >> year2;


    int difference = daysBetweenDates(day1, month1, year1, day2, month2, year2);

    std::cout << "Разность в днях между датами: " << difference << " дней" << '\n';


    return 0;
}

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }

}
template <typename GigaArbyz>
void countElements(GigaArbyz arr[], int size, int& positiveCount, int& negativeCount, int& zeroCount) {

    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            positiveCount++;
        }
        else if (arr[i] < 0) {
            negativeCount++;
        }
        else {
            zeroCount++;
        }
    }
}

int daysBetweenDates(unsigned int day1, unsigned int month1, unsigned int year1, unsigned int day2, unsigned int month2, unsigned int year2) {

    if (day1 > 31 || day2 > 31)
    {
        std::cerr << "Value input error";
        return 0;
    }
    else if (month1 > 12 || month2 > 12)
    {
        std::cerr << "Value input error\n\n";
        return 0;
    }
    std::tm date1 = {};
    date1.tm_year = year1 - 1900;
    date1.tm_mon = month1 - 1;
    date1.tm_mday = day1;

    std::tm date2 = {};
    date2.tm_year = year2 - 1900;
    date2.tm_mon = month2 - 1;
    date2.tm_mday = day2;

    std::time_t time1 = std::mktime(&date1);
    std::time_t time2 = std::mktime(&date2);
    time_t TimeDifferense = std::difftime(time2, time1) / (60 * 60 * 24);
    if (TimeDifferense < 0) {
        TimeDifferense = TimeDifferense * -1;
    }
    return TimeDifferense;
}

template <typename arrCount>
arrCount arrMidCount(arrCount arr[], int arrSize) {
    arrCount sum = 0;
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
    }
    sum = sum / arrSize;
    return sum;
}