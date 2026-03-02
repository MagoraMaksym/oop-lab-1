#include "cost.h"
#include <iostream>
#include <cmath>

void Cost::add(Cost other) {
    this->hrn += other.hrn;
    this->kop += other.kop;
    if (this->kop >= 100.0f) {
        this->hrn += static_cast<int>(this->kop / 100);
        this->kop = fmod(this->kop, 100.0f);
    }
}

void Cost::multiply(int quantity) {
    float total_kop = (this->hrn * 100.0f + this->kop) * quantity;
    this->hrn = static_cast<int>(total_kop / 100);
    this->kop = fmod(total_kop, 100.0f);
}

void Cost::round_to_10() {
    int k = static_cast<int>(this->kop);
    int last_digit = k % 10;

    if (last_digit < 5) {
        this->kop = static_cast<float>((k / 10) * 10);
    } else {
        this->kop = static_cast<float>((k / 10) * 10 + 10);
    }
 
    if (this->kop >= 100.0f) {
        this->hrn += 1;
        this->kop = 0.0f;
    }
}

void Cost::print() const {
    std::cout << this->hrn << " грн " << this->kop << " коп" << std::endl;
}