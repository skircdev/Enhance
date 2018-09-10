#pragma once

//#include <string>
#include "trading_enums.h"

namespace ferdi {
namespace trd {

////////////////////////////////////////////////////////////////////////////////
PositionSide OtherSide(PositionSide side);    
template <typename T> PositionSide GetSideFromPosition(T pos);


////////////////////////////////////////////////////////////////////////////////
template <typename T>     
inline PositionSide GetSideFromPosition(T pos) {
    const T zero(0);
    if (pos > zero) return PositionSide::LONG;
    if (pos < zero) return PositionSide::SHORT;
    return PositionSide::FLAT;    
}

inline PositionSide OtherSide(PositionSide side) {
    if (PositionSide::LONG == side) return PositionSide::SHORT;
    return PositionSide::LONG;
}

} // namespace trd
} // namespace ferdi 