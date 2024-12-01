#pragma once
#include <string>
#include <iostream>
#include <sstream>

class Complex
{

public: 
    Complex();
    Complex(double re, double im);
    Complex(std::string& data);
    Complex(const Complex& p);
    ~Complex();

    Complex operator = (const Complex& complex);

    //Base math operators
    Complex operator + (const Complex& complex);
    Complex operator - (const Complex& complex);
    Complex operator * (const Complex& complex);
    Complex operator / (const Complex& complex);
    Complex operator ^ (const int& deg);

    //Aquate math operators
    void operator -= (const Complex& complex);
    void operator += (const Complex& complex);
    void operator *= (const Complex& complex);
    void operator /= (const Complex& complex);
    void operator ^= (const int& deg);

    //Compare operators
    bool operator == (const Complex& complex);
    bool operator != (const Complex& complex);
    bool operator >= (const Complex& complex);
    bool operator <= (const Complex& complex);
    bool operator > (const Complex& complex);
    bool operator < (const Complex& complex);

    friend std::ostream& operator << (std::ostream& output, const Complex& p);
    friend std::istream& operator >> (std::istream& input, const Complex& p);

    std::string ToString() const;
    static Complex sum(Complex a, Complex b);
    static Complex dif(Complex a, Complex b);
    static Complex mul(Complex a, Complex b);
    static Complex sub(Complex a, Complex b);
    static Complex exp(Complex a, int deg);
private:
    double m_re;
    double m_im;
};

