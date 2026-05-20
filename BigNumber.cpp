#include "BigNumber.h"

BigNumber::BigNumber(){

}

BigNumber::BigNumber(const std::string& number, bool negative){
    negative_ = negative;
    for(int i = number.size() - 1; i >= 0; i--){
        digits_.push_back(number[i] - '0');
    }
}

std::string BigNumber::toString(){
    std::string result = negative_ ? "-" : "";
    for(int n = digits_.size() - 1; n >= 0; n--){
        result += ('0' + digits_[n]);
    }
    return result;
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

BigNumber BigNumber::operator+(const BigNumber& other) const {
    if (negative_ == other.negative_) {
        BigNumber result = addAbsolute(*this, other);
        result.negative_ = negative_;
        return result;
    }
    return *this;
}