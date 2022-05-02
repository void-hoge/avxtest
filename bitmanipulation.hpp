#ifndef BITMANIPULATION_HPP
#define BITMANIPULATION_HPP

#include <immintrin.h>
#include <ostream>

class bits {
private:
	alignas(32) __m256i _data;
public:
	bits& operator=(const uint16_t);
	bits& operator&=(const bits&);
	bits& operator&=(const uint16_t);
	bits& operator|=(const bits&);
	bits& operator|=(const uint16_t);
	bits& operator^=(const bits&);
	bits& operator^=(const uint16_t);
	bits(){}
	bits(const __m256i& dt) {
		this->_data = dt;
	}
	bits(const uint16_t n) {
		*this = n;
	}
	const __m256i& data() const{
		return this->_data;
	}
};

std::ostream& operator<<(std::ostream& ost, const bits& n);

bits operator&(const bits& a, const bits& b);

bits operator&(const bits& a, const bits& b);

bits operator&(const bits& a, const uint16_t b);

bits operator|(const bits& a, const bits& b);

bits operator|(const bits& a, const uint16_t b);

bits operator^(const bits& a, const bits& b);

bits operator^(const bits& a, const uint16_t b);

bits operator<<(const bits& a, const int n);

bits operator>>(const bits& a, const int n);

bits operator~(const bits& a);

#endif
