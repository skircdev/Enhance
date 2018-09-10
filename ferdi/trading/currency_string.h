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

#include <string>
#include "currency.h"

namespace ferdi {
namespace trd {

std::string ToString(Currency ccy);
Currency    CurrencyFromString(const std::string& ccy);    

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
inline std::string ToString(Currency ccy) {
    switch (ccy) {
        // Fiat Currencies
        case Currency::USD:     return "USD";
        case Currency::EUR:     return "EUR";
        case Currency::JPY:     return "JPY";
        case Currency::CHF:     return "CHF";
        case Currency::GBP:     return "GBP";
        case Currency::CAD:     return "CAD";
        case Currency::AUD:     return "AUD";
        case Currency::NZD:     return "NZD";
        case Currency::SGD:     return "SGD";
        case Currency::HKD:     return "HKD";
        case Currency::THB:     return "THB";
        
        // Crypto Currencies
        case Currency::XBT:     return "XBT";
        case Currency::ETH:     return "ETH";
        case Currency::LTC:     return "LTC";
        
        // Other
        case Currency::UNKNOWN: return "Unknown";
    }
    return "NotImplemented";
}

inline Currency CurrencyFromString(const std::string& ccy) {
    if (ccy == "USD") return Currency::USD;
    if (ccy == "EUR") return Currency::EUR;
    if (ccy == "JPY") return Currency::JPY;
    if (ccy == "CHF") return Currency::CHF;
    if (ccy == "GBP") return Currency::GBP;
    if (ccy == "CAD") return Currency::CAD;
    if (ccy == "AUD") return Currency::AUD;
    if (ccy == "NZD") return Currency::NZD;
    if (ccy == "SGD") return Currency::SGD;
    if (ccy == "HKD") return Currency::HKD;
    if (ccy == "THB") return Currency::THB;
    
    // Crypto Currencies
    if (ccy == "XBT") return Currency::XBT;
    if (ccy == "ETH") return Currency::ETH;
    if (ccy == "LTC") return Currency::LTC;
    return Currency::UNKNOWN;
}


} // namespace trd
} // namespace ferdi

