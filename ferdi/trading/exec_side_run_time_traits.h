#pragma once

#include <algorithm>
#include "trading_enums.h"

namespace ferdi {
namespace trd {

////////////////////////////////////////////////////////////////////////////////    
int ToInt(ExecSide side);
ExecSide OtherSide(ExecSide side);

template <typename T> bool IsGreater(ExecSide side, T lhs, T rhs);  // Seen from the SELL side
template <typename T> bool IsGreaterEqual(ExecSide side, T lhs, T rhs);  // Seen from the SELL side


////////////////////////////////////////////////////////////////////////////////
inline int ToInt(ExecSide side) {
    return (ExecSide::BUY == side) ? 1 : -1;
}

inline ExecSide OtherSide(ExecSide side) {
    if (ExecSide::SELL == side) return ExecSide::BUY;
    return ExecSide::SELL;
}

template <typename T>
inline bool IsGreater(ExecSide side, T lhs, T rhs) {  // Seen from the SELL side
    if (side == ExecSide::SELL) return lhs > rhs;
    return lhs < rhs;
}

template <typename T>
inline bool IsGreaterEqual(ExecSide side, T lhs, T rhs) {  // Seen from the SELL side
    if (side == ExecSide::SELL) return lhs >= rhs;
    return lhs <= rhs;
}

template <typename T>
inline T Add(ExecSide side, T lhs, T rhs) {  // Seen from the BUY side
    if (side == ExecSide::BUY) return lhs + rhs;
    return lhs - rhs;
}

template <typename T>
inline T Diff(ExecSide side, T lhs, T rhs) {  // Seen from the BUY side
    if (side == ExecSide::BUY) return lhs - rhs;
    return rhs - lhs;
}

template <typename T>
inline T Max(ExecSide side, T lhs, T rhs) {  // Seen from the BUY side
    if (side == ExecSide::BUY) return std::max(lhs, rhs);
    return std::min(lhs, rhs);
}

template <typename T>
inline T Min(ExecSide side, T lhs, T rhs) {  // Seen from the BUY side
    if (side == ExecSide::BUY) return std::min(lhs, rhs);
    return std::max(lhs, rhs);
}

template <typename T>    
inline T GetQtyForTargetPosition(ExecSide side, T current_pos, T target_pos) {
    if (side == ExecSide::BUY) {
        return target_pos - current_pos;
    } else if (side == ExecSide::SELL) {
        return current_pos + target_pos;
    }
    return T(0);
}

template <typename T>    
inline T PositionAddQty(ExecSide side, T pos, T qty) {
    if (side == ExecSide::BUY) {
        return pos + qty;
    } 
    return pos - qty;
}

}  // namespace trd
}  // namespace ferdi 
