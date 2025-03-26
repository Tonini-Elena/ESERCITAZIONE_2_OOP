#include <iostream>
#include "complex_number.hpp"

int main(void) {
    using complex = complex_number<double>;
    
    
    complex c1(1, 8);   
    complex c2(2, -5);  
    
	
    std::cout << "the conjugate of " << c1 << " is " << c1.conjugate() << std::endl; 
    std::cout << "the real part of " << c2 << " is " << c2.real_part() << std::endl;
    std::cout << "the imaginary part of " << c2 << " is " << c2.imaginary_part() << std::endl;
	
    complex c3 = c1 + c2;  
    std::cout << "(" << c1 << ") + (" << c2 << ") = " << c3 << std::endl; 


    complex c5 = complex(3, 4) + 7;
    std::cout << "(3 + 4i) + 7 = " << c5 << std::endl;

   
    complex c6 = 3.0 + c5;
    std::cout << "3.0 + " << "(" << c5 << ")" << " = " << c6 << std::endl;

    
    complex c8 = complex(4, 3) * 2.0;
    std::cout << "(4 + 3i) * 2.0 = " << c8 << std::endl;
	
	complex c9 = 2.0 * complex(4,3);
    std::cout << "2.0 * (4+3i) = " << c9 << std::endl;

    
    complex c4 = c3 * c6;
    std::cout << "(" << c3 << ") * (" << c6 << ") = " << c4 << std::endl;

    return 0;
}
