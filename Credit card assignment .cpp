#include <iostream>
#include <vector>
using namespace std;

bool isValid(long long number);//Get the result from Step 2
int sumOfDoubleEvenPlace(long long number);//Return this number if it is a single digit, otherwise, return the sum of the two digits
int getDigit(int number);//Return sum of odd place digits in number
int sumOfOddPlace(long long number);//Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d);//Return the number of digits in d
int getSize(long long d);//Return the first k number of digits from number. If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k);//return the first k number of digits from number. If the number of digits in number is less than k, return number.

int main()
{
    long long number;
    cout << "Enter a credit card number as a long integer: ";
    cin >> number;

    if (isValid(number))
        cout << number << " is valid" << endl;
    else
        cout << number << " is invalid" << endl;

    return 0;
}
bool isValid(long long number)
{
    return (getSize(number) >= 13 && getSize(number) <= 16) &&
           (prefixMatched(number, 4) || prefixMatched(number, 5) ||
            prefixMatched(number, 37) || prefixMatched(number, 6)) &&
           ((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0);
}

int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    bool isEvenPlace = false;

    while (number > 0)
    {
        int digit = number % 10;
        if (isEvenPlace)
        {
            sum += getDigit(digit * 2);
        }
        isEvenPlace = !isEvenPlace;
        number /= 10;
    }

    return sum;
}

int getDigit(int number)
{
    if (number < 10)
        return number;
    else
        return number / 10 + number % 10;
}

int sumOfOddPlace(long long number)
{
    int sum = 0;
    bool isEvenPlace = false;

    while (number > 0)
    {
        int digit = number % 10;
        if (!isEvenPlace)
        {
            sum += digit;
        }
        isEvenPlace = !isEvenPlace;
        number /= 10;
    }

    return sum;
}

bool prefixMatched(long long number, int d)
{
    return getPrefix(number, getSize(d)) == d;
}

int getSize(long long d)
{
    int size = 0;
    while (d > 0)
    {
        size++;
        d /= 10;
    }
    return size;
}

long long getPrefix(long long number, int k)
{
    int size = getSize(number);
    if (size < k)
        return number;
    else
    {
        for (int i = 0; i < size - k; i++)
            number /= 10;
        return number;
    }
}
