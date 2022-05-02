#include "bitmanipulation.hpp"

#include <immintrin.h>
#include <bitset>
#include <iostream>
#include <ostream>

bits& bits::operator=(const uint16_t n) {
	this->_data = _mm256_set_epi16(n,n,n,n,
								   n,n,n,n,
								   n,n,n,n,
								   n,n,n,n);
	return *this;
}

bits& bits::operator&=(const bits& a) {
	*this = *this & a;
	return *this;
}

bits& bits::operator&=(const uint16_t a) {
	*this = *this & a;
	return *this;
}
bits& bits::operator|=(const bits& a) {
	*this = *this | a;
	return *this;
}

bits& bits::operator|=(const uint16_t a) {
	*this = *this | a;
	return *this;
}

bits& bits::operator^=(const bits& a) {
	*this = *this ^ a;
	return *this;
}

bits& bits::operator^=(const uint16_t a) {
	*this = *this ^ a;
	return *this;
}


std::ostream& operator<<(std::ostream& ost, const bits& n) {
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 0) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 1) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 2) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 3) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 4) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 5) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 6) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 7) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 8) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 9) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 10) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 11) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 12) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 13) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 14) << ' ';
	ost << (std::bitset<16>)_mm256_extract_epi16(n.data(), 15) << ' ';
	return ost;
}

bits operator&(const bits& a, const bits& b) {
	return bits(_mm256_and_si256(a.data(), b.data()));
}

bits operator&(const bits& a, const uint16_t b) {
	bits tmp = b;
	return bits(_mm256_and_si256(a.data(), tmp.data()));
}

bits operator|(const bits& a, const bits& b) {
	return bits(_mm256_or_si256(a.data(), b.data()));
}

bits operator|(const bits& a, const uint16_t b) {
	bits tmp = b;
	return bits(_mm256_or_si256(a.data(), tmp.data()));
}

bits operator^(const bits& a, const bits& b) {
	return bits(_mm256_xor_si256(a.data(), b.data()));
}

bits operator^(const bits& a, const uint16_t b) {
	bits tmp = b;
	return bits(_mm256_xor_si256(a.data(), tmp.data()));
}

bits operator<<(const bits& a, const int n) {
	return bits(_mm256_slli_epi16(a.data(), n));
}

bits operator>>(const bits& a, const int n) {
	return bits(_mm256_srli_epi16(a.data(), n));
}

bits operator~(const bits& a) {
	return a ^ 0;
}
