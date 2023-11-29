#include <stdio.h>
#include <assert.h>

class Date 
{
    // public fields
    int day;
    int month;
    int year;

    public:
    // constructor
    Date(int d, int m, int y)   
    {
        day = d;
        month = m;
        year = y;
    }

    // public methods
    bool isLeapYear()
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main(void)
{
    Date birthday(23, 6, 1912); // Alan Turing date of birth

    assert(birthday.day == 23);
    assert(birthday.month == 6);
    assert(birthday.year == 1912);

    assert(birthday.isLeapYear() == true);

    return 0;
}
