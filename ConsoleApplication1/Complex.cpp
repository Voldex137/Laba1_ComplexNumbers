#include "Complex.h"
#include <charconv>

Complex::Complex()
{
	m_re = 0;
	m_im = 0;
}

Complex::Complex(double re, double im)
{
	m_re = re;
	m_im = im;
}

Complex::Complex(std::string& data)
{
	std::stringstream ss;
	ss << data;
	ss >> m_re >> m_im;
}

Complex::Complex(const Complex& p)
{
	m_re = p.m_re;
	m_im = p.m_im;
}

Complex::~Complex()
{
}

Complex Complex::operator=(const Complex& complex)
{
	m_re = complex.m_re;
	m_im = complex.m_im;
	return *this;
}

Complex Complex::operator+(const Complex& complex)
{
	return Complex::sum(*this, complex);
}

Complex Complex::operator-(const Complex& complex)
{
	return Complex::dif(*this, complex);
}

Complex Complex::operator*(const Complex& complex)
{
	return Complex::mul(*this, complex);
}

Complex Complex::operator/(const Complex& complex)
{
    return Complex::sub(*this, complex);
}

Complex Complex::operator^(const int& deg)
{
	return Complex::exp(*this, deg);
}

void Complex::operator+=(const Complex& complex)
{
	*this = Complex::sum(*this, complex);
}

void Complex::operator-=(const Complex& complex)
{
	*this = Complex::dif(*this, complex);
}

void Complex::operator*=(const Complex& complex)
{
	*this = Complex::mul(*this, complex);
}

void Complex::operator/=(const Complex& complex)
{
	//	  Complex res = mul(Complex(m_re, m_im), Complex(complex.m_re, -complex.m_im));
	//   double div = complex.m_re * complex.m_re - complex.m_im * complex.m_im;
	//   res.m_re /= div;
	//   res.m_im /= div;
	*this = Complex::sub(*this, complex);
}

void Complex::operator^=(const int& deg)
{
	*this = Complex::exp(*this, deg);
}

bool Complex::operator==(const Complex& complex)
{
	return (m_re == complex.m_re && m_im == complex.m_im);
}

bool Complex::operator>=(const Complex& complex)
{
	if (*this == complex)
	{
		return true;
	}
	if (m_re > complex.m_re || m_re == complex.m_re && m_im > complex.m_im)
	{
		return true;
	}
	return false;
}

bool Complex::operator<=(const Complex& complex)
{
	if (*this == complex)
	{
		return true;
	}
	if (m_re < complex.m_re || m_re == complex.m_re && m_im < complex.m_im)
	{
		return true;
	}
	return false;
}

bool Complex::operator>(const Complex& complex)
{
	if (m_re > complex.m_re || m_re == complex.m_re && m_im > complex.m_im)
	{
		return true;
	}
	return false;
}

bool Complex::operator<(const Complex& complex)
{
	if (m_re < complex.m_re || m_re == complex.m_re && m_im < complex.m_im)
	{
		return true;
	}
	return false;
}

bool Complex::operator!=(const Complex& complex)
{
	return (m_re != complex.m_re || m_im != complex.m_im);
}

std::string Complex::ToString() const
{
	if (m_im == 0 && m_re == 0)
	{
		return std::string("0");
	}

	std::stringstream data;
	if (m_re != 0)
	{
		data << m_re;
	}
	data << (m_im > 0 ? "+" : "");
	if (m_im != 0)
	{
		if (m_im == 1)
		{
			data << "i";
		}
		else if (m_im == -1)
		{
			data << "-i";
		}
		else
		{
			data << m_im << "i";
		}
	}

	return data.str();
}

Complex Complex::sum(Complex a, Complex b)
{
	return Complex(a.m_re + b.m_re, a.m_im + b.m_im);
}

Complex Complex::dif(Complex a, Complex b)
{
	return Complex(a.m_re - b.m_re, a.m_im - b.m_im);
}

Complex Complex::mul(Complex a, Complex b)
{
	return Complex(a.m_re * b.m_re - a.m_im * b.m_im, a.m_re * b.m_im + a.m_im * b.m_re);
}

Complex Complex::sub(Complex a, Complex b)
{
	if (b == Complex())
	{
		throw 0;
		return Complex();
	}
	Complex res = mul(Complex(a.m_re, a.m_im), Complex(b.m_re, -b.m_im));
	double div = b.m_re * b.m_re - b.m_im * b.m_im;
	res.m_re /= div;
	res.m_im /= div;
	return res;
}

Complex Complex::exp(Complex a, int deg)
{
	Complex res = a;
	for (int i = 0; i < deg-1; i++)
	{
		res = mul(res, a);
	}
	return res;
}

std::ostream& operator<<(std::ostream& output, const Complex& p)
{
	output << p.ToString();
	return output;
}

std::istream& operator>>(std::istream& output, Complex& p)
{
	std::string dataString;
	output >> dataString;
	p = Complex(dataString);
	return output;
}
