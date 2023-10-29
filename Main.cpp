#include<iostream>
using namespace std;
class Fraction {
private:
    int numerator;   
    int denominator; 

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}
    void input() {
        cout << "Enter the number: ";
        cin >> numerator;
        do {
            cout << "Enter the denominator (not zero): ";
            cin >> denominator;
        } while (denominator == 0);
    }
    void display() {
        cout << numerator << "/" << denominator;
    }
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    void simplify() {
        int commonFactor = gcd(numerator, denominator);
        numerator /= commonFactor;
        denominator /= commonFactor;
    }
    Fraction operator+(const Fraction& other) {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        Fraction result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }
    Fraction operator-(const Fraction& other) {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        Fraction result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }
    Fraction operator*(const Fraction& other) {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        Fraction result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }
    Fraction operator/(const Fraction& other) {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        Fraction result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }
};
int main() {
    Fraction fraction1, fraction2, result;
    cout << "Fraction 1:\n";
    fraction1.input();
    cout << "Fraction 2:\n";
    fraction2.input();
    cout << "Fraction 1: ";
    fraction1.display();
    cout << "\nFraction 2: ";
    fraction2.display();
    result = fraction1 + fraction2;
    cout << "\nSumm: ";
    result.display();
    result = fraction1 - fraction2;
    cout << "\nDifference: ";
    result.display();
    result = fraction1 * fraction2;
    cout << "\nProduct: ";
    result.display();
    result = fraction1 / fraction2;
    cout << "\nFraction: ";
    result.display();
    return 0;
}