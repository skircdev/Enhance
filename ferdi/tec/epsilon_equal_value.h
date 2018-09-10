// Licensed under the MIT License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software distributed 
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
// CONDITIONS OF ANY KIND, either express or implied. See the License for the 
// specific language governing permissions and limitations under the License.

#pragma once

#include <iostream>
#include <limits>
#include <cmath> 
#include <ferdi/iostreams/value_streaming.h>

namespace ferdi {
namespace tec {

/**************************************************************************//**
   * Essentially a double with comparision operators that allow for 
   * numerical precision issues */
template <typename ValueType>    
class EpsilonEqualValue {
    friend std::ostream& operator<<(std::ostream& os, const EpsilonEqualValue value) { os << value.value_; return os; }
    friend std::istream& operator>>(std::istream& is, EpsilonEqualValue& value) { is >> value.value_; return is; }

public:
    EpsilonEqualValue() : value_(InvalidValue()) {}
    explicit EpsilonEqualValue(ValueType price) : value_(price) {}

    void set_value(ValueType price) { value_ = price; }
    ValueType get_value() const { return value_; }
    bool IsValid() const { return !std::isnan(value_); }
    bool IsNotValid() const { return std::isnan(value_); }
    bool IsZero() const { return IsEqual(value_, 0.0); }
    bool IsNotZero() const { return !IsEqual(value_, 0.0); }
    bool IsPositive() const { return value_ >=  GetEqualityThreshold(); }
    bool IsNegative() const { return value_ <= -GetEqualityThreshold(); }

    static constexpr EpsilonEqualValue CreateMin() { return EpsilonEqualValue(std::numeric_limits<ValueType>::min()); }
    static constexpr EpsilonEqualValue CreateInvalid() { return EpsilonEqualValue(InvalidValue()); }
    static bool IsEqual(ValueType lhs, ValueType rhs) { return fabs(lhs - rhs) < GetEqualityThreshold(); }

    EpsilonEqualValue& operator+=(EpsilonEqualValue price) { value_ += price.value_; return *this; }
    EpsilonEqualValue& operator-=(EpsilonEqualValue price) { value_ -= price.value_; return *this; }

    friend bool operator!=(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return !IsEqual(lhs.value_, rhs.value_); }
    friend bool operator==(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return IsEqual(lhs.value_, rhs.value_); }
    friend bool operator>(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return IsEqual(lhs.value_, rhs.value_) ? false : lhs.value_ > rhs.value_; }
    friend bool operator>=(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return IsEqual(lhs.value_, rhs.value_) || lhs.value_ > rhs.value_; }
    friend bool operator<(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return IsEqual(lhs.value_, rhs.value_) ? false : lhs.value_ < rhs.value_; }
    friend bool operator<=(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return IsEqual(lhs.value_, rhs.value_) || lhs.value_ < rhs.value_; }
    friend EpsilonEqualValue operator+(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return EpsilonEqualValue(lhs.value_ + rhs.value_); }
    friend EpsilonEqualValue operator-(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return EpsilonEqualValue(lhs.value_ - rhs.value_); }
    friend EpsilonEqualValue operator*(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return EpsilonEqualValue(lhs.value_ * rhs.value_); }
    friend EpsilonEqualValue operator*(EpsilonEqualValue lhs, ValueType rhs) { return EpsilonEqualValue(lhs.value_ * rhs); }
    friend EpsilonEqualValue operator/(EpsilonEqualValue lhs, EpsilonEqualValue rhs) { return EpsilonEqualValue(lhs.value_ / rhs.value_); }
    friend EpsilonEqualValue operator/(EpsilonEqualValue lhs, ValueType rhs) { return EpsilonEqualValue(lhs.value_ / rhs); }
    friend EpsilonEqualValue abs(EpsilonEqualValue value) { return value.value_ >= 0 ? value : EpsilonEqualValue(-value.value_); }

    void Read(std::ifstream& file) { ferdi::iostreams::ReadValueFromStream(file, &value_); }
    void Write(std::ofstream* file) const { ferdi::iostreams::WriteValueToStream(value_, file); }

private:
    static constexpr ValueType InvalidValue() { return std::numeric_limits<ValueType>::quiet_NaN(); }
    static constexpr ValueType GetEqualityThreshold() { return 1e-8; }
        
private:
    ValueType value_;
};

}  // namespace tec
}  // namespace ferdi



