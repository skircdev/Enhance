#pragma once

#include "price.h"
#include "trading_enums.h"

namespace ferdi {
namespace trd {

/**************************************************************************//**
	*/
class TickSize : public Price {
public:
    using Price::Price;
    long GetNbrIntTicks(const Price price) const;
    Price GetCeilPrice(const ferdi::trd::ExecSide side, const Price price) const;
};

////////////////////////////////////////////////////////////////////////////////
inline long TickSize::GetNbrIntTicks(const Price price) const {
    if (this->IsNotZero()) {
            const double fraction = price.get_value() / this->get_value();
            return std::lrint(fraction);
    }
    return std::numeric_limits<long>::max();
}

inline Price TickSize::GetCeilPrice(const ferdi::trd::ExecSide side, const Price price) const {
    if (this->IsNotZero()) {
            const double fraction = price.get_value() / this->get_value();
            if (side == ferdi::trd::ExecSide::BUY) return Price(this->get_value() * std::ceil(fraction));
            else return Price(this->get_value() * std::floor(fraction));
    }
    return Price();   // Invalid
}

}  // namespace  trd
}  // namespace  ferdi
