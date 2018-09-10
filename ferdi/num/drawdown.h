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

namespace ferdi {
namespace num {

template<typename ContainerType> auto CurrentDrawdown(const ContainerType& seq);
template<typename ContainerType> auto CurrentDrawdownRatio(const ContainerType& seq);
template<typename ContainerType> auto MaxDrawdown(const ContainerType& seq);
template<typename ContainerType> auto DrawdownRatio(const ContainerType& seq);   // aka Calmar
template<typename ContainerType> size_t MaxRecoveryDays(const ContainerType& seq);

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
template<typename ContainerType>
inline auto MaxDrawdown(const ContainerType& seq) {
    const typename ContainerType::value_type zero(0);
    typename ContainerType::value_type max_drawdown = zero;
    typename ContainerType::value_type accum_profit = zero;
    typename ContainerType::value_type max_accum_profit = zero;
    for (auto it = seq.begin(); it != seq.end(); ++it) {
            accum_profit += *it;
            if (accum_profit > max_accum_profit) max_accum_profit = accum_profit;
            const auto current_drawdown = max_accum_profit - accum_profit;
            if (current_drawdown > max_drawdown) max_drawdown = current_drawdown;
    }
    return max_drawdown;
}

template<typename ContainerType> 
inline auto CurrentDrawdown(const ContainerType& seq) {
    const typename ContainerType::value_type zero(0);
    typename ContainerType::value_type max_drawdown = zero;
    typename ContainerType::value_type current_drawdown = zero;
    typename ContainerType::value_type accum_profit = zero;
    typename ContainerType::value_type max_accum_profit = zero;
    for (auto it = seq.begin(); it != seq.end(); ++it) {
            accum_profit += *it;
            if (accum_profit > max_accum_profit) max_accum_profit = accum_profit;
            current_drawdown = max_accum_profit - accum_profit;
            if (current_drawdown > max_drawdown) max_drawdown = current_drawdown;
    }
    return current_drawdown;
}

template<typename ContainerType> auto CurrentDrawdownRatio(const ContainerType& seq) {
    const typename ContainerType::value_type zero(0);
    typename ContainerType::value_type max_drawdown = zero;
    typename ContainerType::value_type current_drawdown = zero;
    typename ContainerType::value_type accum_profit = zero;
    typename ContainerType::value_type max_accum_profit = zero;
    for (auto it = seq.begin(); it != seq.end(); ++it) {
            accum_profit += *it;
            if (accum_profit > max_accum_profit) max_accum_profit = accum_profit;
            current_drawdown = max_accum_profit - accum_profit;
            if (current_drawdown > max_drawdown) max_drawdown = current_drawdown;
    }
    if (max_drawdown > 0) return current_drawdown / max_drawdown;
    return zero;
}

template<typename ContainerType>
inline auto DrawdownRatio(const ContainerType& seq) {
    const typename ContainerType::value_type zero(0);
    typename ContainerType::value_type max_drawdown = zero;
    typename ContainerType::value_type accum_profit = zero;
    typename ContainerType::value_type max_accum_profit = zero;
    for (auto it = seq.begin(); it != seq.end(); ++it) {
            accum_profit += *it;
            if (accum_profit > max_accum_profit) max_accum_profit = accum_profit;
            const auto current_drawdown = max_accum_profit - accum_profit;
            if (current_drawdown > max_drawdown) max_drawdown = current_drawdown;
    }
    if (max_drawdown == zero) return typename ContainerType::value_type(999);
    return accum_profit / max_drawdown;
}

template<typename ContainerType> 
inline size_t MaxRecoveryDays(const ContainerType& seq) {
    const typename ContainerType::value_type zero(0);
    typename ContainerType::value_type accum_profit = zero;
    typename ContainerType::value_type max_accum_profit = zero;
    size_t max_recovery_days = 0;
    size_t current_recovery_days = 0;
    for (auto it = seq.begin(); it != seq.end(); ++it) {
            accum_profit += *it;
            if (accum_profit > max_accum_profit) {
                    max_accum_profit = accum_profit;
                    current_recovery_days = 0;
            }
            else current_recovery_days++;
            max_recovery_days = std::max(max_recovery_days, current_recovery_days);
    }
    return max_recovery_days;
}

} // namespace
} // namespace