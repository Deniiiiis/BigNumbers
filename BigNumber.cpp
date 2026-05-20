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