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

#include <cstring>
#include "trading_enums.h"

namespace ferdi {
namespace trd {

////////////////////////////////////////////////////////////////////////////////  
constexpr const char* NotImplemented() { return "NotImplemented";  }
const char* ToString(ExecSide side);
const char* ToProperCaseString(ExecSide side);
const char* ToProperCaseString(LiquidityType liquidity);
const char* ToProperCaseString(OrderType order_type);
ExecSide ExecSideFromString(const char* side);

////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////  
    
inline const char* ToString(ExecSide side) {
    switch (side) {
        case ExecSide::BUY:     return "BUY";
        case ExecSide::SELL:    return "SELL";
        case ExecSide::UNKNOWN: return "UNKNOWN";
    }
    return NotImplemented();   
}

inline const char* ToProperCaseString(ExecSide side) {
    switch (side) {
        case ExecSide::BUY:     return "Buy";
        case ExecSide::SELL:    return "Sell";
        case ExecSide::UNKNOWN: return "Unknown";
    }
    return NotImplemented();
}

inline const char* ToProperCaseString(LiquidityType liquidity) {
    switch (liquidity) {
        case LiquidityType::MARKER:  return "Maker";
        case LiquidityType::TAKER:   return "Taker";
        case LiquidityType::UNKNOWN: return "Unknown";
    }
    return NotImplemented();
}

inline const char* ToProperCaseString(OrderType order_type) {
    switch (order_type) {
        case OrderType::Limit:   return "Limit";
        case OrderType::Market:  return "Market";
        case OrderType::UNKNOWN: return "Unknown";
    }
    return NotImplemented();
}

inline ExecSide ExecSideFromString(const char* side) {
    if (strcmp("BUY",  side) == 0) return ExecSide::BUY;
    if (strcmp("SELL", side) == 0) return ExecSide::SELL;
    if (strcmp("Buy",  side) == 0) return ExecSide::BUY;
    if (strcmp("Sell", side) == 0) return ExecSide::SELL;    
    return ExecSide::UNKNOWN;
} 

}  // namespace trd
}  // namespace ferdi 
