#include "BigNumber.h"

BigNumber::BigNumber(){

}

BigNumber::BigNumber(const std::string& number, bool negative){
    negative_ = negative;
    for(int i = number.size() - 1; i >= 0; i--){
        digits_.push_back(number[i] - '0');
    }
}

std::string BigNumber::toString() const{
    std::string result = negative_ ? "-" : "";
    for(int n = digits_.size() - 1; n >= 0; n--){
        result += ('0' + digits_[n]);
    }
    return result;
}

int BigNumber::compareValues(const BigNumber& a, const BigNumber& b) {
    if (a.digits_.size() != b.digits_.size())
        return a.digits_.size() > b.digits_.size() ? 1 : -1;
    for (int i = (int)a.digits_.size() - 1; i >= 0; i--) {
        if (a.digits_[i] != b.digits_[i])
            return a.digits_[i] > b.digits_[i] ? 1 : -1;
    }
    return 0;
}

BigNumber BigNumber::addAbsolute(const BigNumber& a, const BigNumber& b){
    BigNumber result;
    result.digits_.clear();
    int carry = 0;
    int maxLen = std::max(a.digits_.size(), b.digits_.size());
    for(int i = 0; i < maxLen || carry; i++){
        int sum = carry;
        if (i < (int)a.digits_.size()) sum += a.digits_[i];
        if (i < (int)b.digits_.size()) sum += b.digits_[i];
        result.digits_.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}

BigNumber BigNumber::subtractValues(const BigNumber& a, const BigNumber& b){
    BigNumber result;
    result.digits_.clear();
    int borrow = 0;
    for(int i = 0; i < (int)a.digits_.size(); i++){
        int diff = a.digits_[i] - borrow;
        if(i < (int)b.digits_.size()) diff -= b.digits_[i];
        if(diff < 0){diff += 10; borrow = 1;}
        else borrow = 0;
        result.digits_.push_back(diff);
    }
    while(result.digits_.size() > 1 && result.digits_.back() == 0)
        result.digits_.pop_back();
    return result;
}

BigNumber BigNumber::operator+(const BigNumber& other)const{
    if(negative_ == other.negative_){
        BigNumber result = addAbsolute(*this, other);
        result.negative_ = negative_;
        return result;
    }else{
        if(compareValues(*this, other) >= 0){
            BigNumber result = subtractValues(*this, other);
            result.negative_ = negative_;
            return result;
        }else{
            BigNumber result = subtractValues(other, *this);
            result.negative_ = other.negative_;
            return result;
        }
    }
}

std::string BigNumber::firstTen()const{
    std::string all = toString();
    std::string sign = negative_ ? "-" : "";
    std::string numPart = negative_ ? all.substr(1) : all;
    if((int)numPart.size() <= 10)
    return all;
    return sign + numPart.substr(0, 10);
}