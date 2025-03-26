#pragma once
#include <iostream>

template<typename T> requires std::floating_point <T>
class complex_number{
    
    T p_real, p_im;
    
public:
    
    complex_number()
        : p_real(0), p_im(0) 
    {}
    
    
    explicit complex_number(T n)
        : p_real(n), p_im(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }	
	
	
	complex_number(T r, T i)
        : p_real(r), p_im(i)
    {}
	
	T real_part(void) const {
        return p_real;
    }
    
	
    T imaginary_part(void) const {
        return p_im;
    }
	
	
	complex_number& operator+=(const complex_number& other) {
        T a = p_real;
        T b = p_im;
        T c = other.p_real;
        T d = other.p_im;
        p_real = a+c;
        p_im = b+d;
        return *this;
	}
	
	
	complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
	complex_number& operator+=(const T& other) {
	    p_real += other;
        return *this;
	}
	
	complex_number operator+(const T& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	

	complex_number conjugate() const {
       return complex_number(p_real, -p_im);
    }
	
	bool operator<(const complex_number& other) const {
      if (p_real < other.p_real) {
        return true;
      } else if (p_real > other.p_real) {
        return false;
      }
    
    return p_im < other.p_im;
	}

    complex_number& operator*=(const complex_number& other) {
        T a = p_real;
        T b = p_im;
        T c = other.p_real;
        T d = other.p_im;
        p_real = a*c - b*d;
        p_im = a*d + b*c;
        return *this;
	}
	
	
	complex_number operator*(const complex_number& other) const {
        complex_number pr = *this;
        pr *= other;
        return pr;
    }
	
	complex_number& operator*=(const T& other) {
	    p_real *= other;
		p_im *= other;
        return *this;
	}
	
	complex_number operator*(const T& other) const {
        complex_number pr = *this;
        pr *= other;
        return pr;
    }

};

template<typename T>
complex_number<T>
operator+(const T& t, const complex_number<T>& c)
{
    return c + t;
}

template<typename T>
complex_number<T>
operator*(const T& t, const complex_number<T>& c)
{
    return c * t;
}

template<typename T>
std::ostream&operator<<(std::ostream& os, const complex_number<T>& c) {
    if (c.imaginary_part() < 0)
	   os << c.real_part() << c.imaginary_part() << "i";
    else
      os << c.real_part() <<  "+" << c.imaginary_part() << "i";

    return os;
}
