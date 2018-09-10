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

#include "details/single_loop_sums.h"

namespace ferdi {
namespace num {

template<typename ContainerType> auto AnnualizedSharpeRatio(const ContainerType& seq, 
                                                            double annualization_factor = 15.87);

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
template<typename ContainerType>
inline auto AnnualizedSharpeRatio(const ContainerType& seq, double annualization_factor) {
    const details::SingleLoopSum<ContainerType> sums(seq);
    if (sums.N > 1) {
        const auto variance = sums.GetVariance();
        const auto mean = sums.GetAverage();
        return annualization_factor * mean / sqrt(variance);
    }
    return std::numeric_limits<typename ContainerType::value_type>::quiet_NaN();
}

} // namespace num
} // namespace ferdi