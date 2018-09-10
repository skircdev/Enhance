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

#include <cmath>
#include <numeric>
#include <algorithm>
#include "details/single_loop_sums.h"

namespace ferdi {
namespace num {

template<typename ContainerType> auto Sum(const ContainerType& seq);    
template<typename ContainerType> auto Mean(const ContainerType& seq);
template<typename ContainerType> auto Max(const ContainerType& seq);
template<typename ContainerType> auto Min(const ContainerType& seq);
template<typename ContainerType> auto Std(const ContainerType& seq);
template<typename ContainerType> auto CumSum(const ContainerType& seq);

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
template<typename ContainerType>
inline auto Sum(const ContainerType& seq) {
    return std::accumulate(seq.begin(), seq.end(), typename ContainerType::value_type(0.0));
}

template<typename ContainerType>
inline auto Mean(const ContainerType& seq) {
    typename ContainerType::value_type avg(0);
    if (!seq.empty()) {
        avg = std::accumulate(seq.begin(), seq.end(), typename ContainerType::value_type(0.0)) / seq.size();
    }
    return avg;
}

template<typename ContainerType> 
inline auto Max(const ContainerType& seq) {
    if (!seq.empty()) {
        return *(std::max_element(seq.begin(), seq.end()));
    }
    return std::numeric_limits<typename ContainerType::value_type>::quiet_NaN();
}

template<typename ContainerType> 
inline auto Min(const ContainerType& seq) {
    if (!seq.empty()) {
        return *(std::min_element(seq.begin(), seq.end()));
    }
    return std::numeric_limits<typename ContainerType::value_type>::quiet_NaN();
}

template<typename ContainerType> 
inline auto Std(const ContainerType& seq) {
    const details::SingleLoopSum<ContainerType> sums(seq);
    return (sums.N > 1) ? sqrt(sums.GetVariance()) : std::numeric_limits<typename ContainerType::value_type>::quiet_NaN();
}

template<typename ContainerType> 
inline auto CumSum(const ContainerType& seq) {
    ContainerType cum_sum(seq.size());
    std::partial_sum(seq.begin(), seq.end(), cum_sum.begin());
    return cum_sum;
}

} // namespace num
} // namespace ferdi
