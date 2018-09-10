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

#include "trading_enums.h"
#include "price.h"

namespace ferdi {
namespace trd {

////////////////////////////////////////////////////////////////////////////////    
template <ExecSide side> constexpr ExecSide OtherSide();
template <ExecSide side> int ToInt();
template <ExecSide side> double Diff(double lhs, double rhs);   // Seen from the BUY side
template <ExecSide side> Price Add(Price lhs, Price rhs);       // Seen from the BUY side

////////////////////////////////////////////////////////////////////////////////    
template <> inline constexpr ExecSide OtherSide<ExecSide::BUY>()  { return ExecSide::SELL; }
template <> inline constexpr ExecSide OtherSide<ExecSide::SELL>() { return ExecSide::BUY; }
template <> inline constexpr int ToInt<ExecSide::BUY>()  { return 1; }
template <> inline constexpr int ToInt<ExecSide::SELL>() { return -1; }

template <> inline double Diff<ExecSide::BUY>(double lhs, double rhs) {  // Seen from the BUY side
    return lhs - rhs;
}

template <> inline double Diff<ExecSide::SELL>(double lhs, double rhs) {
    return rhs - lhs;
}


template <> inline ferdi::trd::Price Add<ferdi::trd::ExecSide::BUY>(ferdi::trd::Price lhs, ferdi::trd::Price rhs) {   // Seen from the BUY side
    return lhs + rhs;
}

template <> inline ferdi::trd::Price Add<ferdi::trd::ExecSide::SELL>(ferdi::trd::Price lhs, ferdi::trd::Price rhs) {
    return lhs - rhs;
}

}  // namespace trd
}  // namespace ferdi 
