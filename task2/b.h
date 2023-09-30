#pragma once
#include <iostream>

class Rational {
public:
    void Normalize(){
        if (num == 0){
            denom = 1;
            return;
        }
        for (int i = 2; i <= denom; i++){
            while (((num % i) == 0) && ((denom % i) == 0)) {
                num /= i; denom /= i;
            }
        }
        if (num * denom < 0){
            num = -abs(num);
            denom = abs(denom);
        }
        else{
            num = abs(num);
            denom = abs(denom);
        }
    }
    Rational (int num = 0, int denom = 1) : num(num), denom(denom){
        (*this).Normalize();
    };
    Rational (const Rational & rhs){
        this->num = rhs.num;
        this->denom = rhs.denom;
        (*this).Normalize();
    }
    Rational & operator=(const Rational & rhs){
        this->num = rhs.num;
        this->denom = rhs.denom;
        (*this).Normalize();
        return *this;
    }
    Rational & operator+=(const Rational & rhs){
        (*this) = (*this) + rhs;
        return *this;
    }
    Rational & operator-=(const Rational & rhs){
        (*this) = (*this) - rhs;
        return *this;
    }
    Rational & operator*=(const Rational & rhs){
        (*this) = (*this) * rhs;
        return *this;
    }
    Rational & operator/=(const Rational & rhs){
        (*this) = (*this) / rhs;
        return *this;
    }
    Rational operator-() const {
        Rational ans = *this;
        ans.num = -ans.num;
        ans.Normalize();
        return ans;
    }
    Rational operator+() const{
        return *this;
    }
    explicit operator double() const{
        return static_cast<double>(this->num) / static_cast<double>(this->denom);
    }
    double toDouble() const {
        return double(*this);
    }
private:
    friend void print(Rational);
    friend bool operator <(const Rational & lhs, const Rational & rhs);
    friend bool operator <=(const Rational & lhs, const Rational & rhs);
    friend bool operator >(const Rational & lhs, const Rational & rhs);
    friend bool operator >=(const Rational & lhs, const Rational & rhs);
    friend bool operator ==(const Rational & lhs, const Rational & rhs);
    friend bool operator !=(const Rational & lhs, const Rational & rhs);
    friend Rational operator *(const Rational & lhs, const Rational & rhs);
    friend Rational operator /(const Rational & lhs, const Rational & rhs);
    friend Rational operator -(const Rational & lhs, const Rational & rhs);
    friend Rational operator +(const Rational & lhs, const Rational & rhs);
    int num, denom;
};

void print(Rational a){
    std::cout << a.num << " / " << a.denom << '\n';
}

bool operator<(const Rational & lhs, const Rational & rhs) {
    return (lhs.num * rhs.denom < rhs.num * lhs.denom);
}
bool operator>(const Rational & lhs, const Rational & rhs) {
    return (lhs.num * rhs.denom > rhs.num * lhs.denom);
}
bool operator>=(const Rational & lhs, const Rational & rhs) {
    return not(lhs < rhs);
}
bool operator<=(const Rational & lhs, const Rational & rhs) {
    return not(lhs > rhs);
}
bool operator==(const Rational & lhs, const Rational & rhs) {
    bool eq_num = lhs.num == rhs.num;
    bool eq_denom = lhs.denom == rhs.denom;
    return eq_num && eq_denom;
}
bool operator!=(const Rational & lhs, const Rational & rhs) {
    return not(lhs == rhs);
}

Rational operator+(const Rational & lhs, const Rational & rhs) {
    Rational answer;
    answer.denom = lhs.denom * rhs.denom;
    answer.num = lhs.num * rhs.denom + lhs.denom * rhs.num;
    answer.Normalize();
    return answer; 
}

Rational operator -(const Rational & lhs, const Rational & rhs) {
    Rational answer;
    answer.denom = lhs.denom * rhs.denom;
    answer.num = lhs.num * rhs.denom - lhs.denom * rhs.num;
    answer.Normalize();
    return answer; 
}

Rational operator*(const Rational & lhs, const Rational & rhs) {
    Rational answer;
    answer.denom = lhs.denom * rhs.denom;
    answer.num = lhs.num * rhs.num;
    answer.Normalize();
    return answer; 
}

Rational operator/(const Rational & lhs, const Rational & rhs) {
    Rational answer;
    answer.denom = lhs.denom * rhs.num;
    answer.num = lhs.num * rhs.denom;
    answer.Normalize();
    return answer;
}