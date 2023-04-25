// Conversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;


bool is_valid(string s, int sys,int sys2) 
{
    if (sys > 10 || sys2 > 10) return false;
    for (auto c : s) {
        if (!isdigit(c) || c - 48 > sys) return false;
    }
    return true;
}

int to_decimal(string num_orig, int sys_orig)
{
    int curr{ 0 };
    if (num_orig.length() == 1) return num_orig[0] - 48;
    else
    {
        curr = (num_orig[0] - 48) * pow(sys_orig, (num_orig.length() - 1));
        string s = num_orig.erase(0, 1);
        return curr + to_decimal(s, sys_orig);
    }
}

string to_new(int num, int sys)
{
    string s{ "" };
    for (int i = num; i > 0; i /= sys)
    {
        s += char(i%sys + 48);
    }
    reverse(s.begin(), s.end());
    return s;
}



string convert(string num_orig, int sys_orig, int sys_der)
{
    int number_dec = to_decimal(num_orig, sys_orig);
    string result = to_new(number_dec, sys_der) ;
    return result;
}



int main()
{
    string num_orig;
    int sys_orig;
    int sys_der;
    string num_der;
    cout << "Hello! Let's try to convert some numbers. Give me : a number to work with, an original number system, and number system, that you wish to convert it to." << endl;
    cin >> num_orig >> sys_orig >> sys_der;
    while (!is_valid(num_orig, sys_orig, sys_der))
    {
        cout << "Something doesn't smell right. Please, check your input. \n";
        cin >> num_orig >> sys_orig >> sys_der;
    }
    num_der = convert(num_orig, sys_orig, sys_der);
    cout << "And the answer is: " << num_der <<"."<< endl;
}

