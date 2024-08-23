#include <iostream>
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

// Function to find the greatest common divisor (GCD)
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

string fractionAddition(string expression)
{
    int numerator = 0, denominator = 1;
    istringstream ss(expression);
    int num, denom;
    char slash, sign;

    // Parsing the input expression
    while (ss >> num >> slash >> denom)
    {
        numerator = numerator * denom + num * denominator;
        denominator *= denom;
        int g = gcd(abs(numerator), denominator);
        numerator /= g;
        denominator /= g;
    }

    return to_string(numerator) + "/" + to_string(denominator);
}

int main()
{
    // Test cases
    string expression1 = "-1/2+1/2";
    string expression2 = "-1/2+1/2+1/3";
    string expression3 = "1/3-1/2";

    cout << fractionAddition(expression1) << endl; // Output: "0/1"
    cout << fractionAddition(expression2) << endl; // Output: "1/3"
    cout << fractionAddition(expression3) << endl; // Output: "-1/6"

    return 0;
}
