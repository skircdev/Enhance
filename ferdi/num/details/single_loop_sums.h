#pragma once

namespace ferdi {
namespace num {
namespace details {

/**************************************************************************//**
    * Reusable in other contexts */
template<typename ValueType> 
struct SingleLoopSumBase {
    SingleLoopSumBase(size_t init_N, ValueType init_sx, ValueType init_sxx) 
        : N(init_N), sx(init_sx), sxx(init_sxx) {}
    void Reset() { N = 0; sx = ValueType(0); sxx = ValueType(0); }
    void IncrementSums(ValueType x) { sx += x; sxx += x*x; }
    ValueType GetAverage() const { return (N > 0) ? sx / N : std::numeric_limits<ValueType>::quiet_NaN(); }
    ValueType GetVariance() const { return (N > 1) ? (N*sxx - sx*sx) / (N*(N - 1)) : std::numeric_limits<ValueType>::quiet_NaN(); }
    
    size_t N;
    ValueType sx;
    ValueType sxx;
};    
    
/**************************************************************************//**
    *	*/
template<typename ContainerType> 
struct SingleLoopSum : public SingleLoopSumBase<typename ContainerType::value_type> {
    SingleLoopSum(const ContainerType& seq);
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
template<typename ContainerType>
inline SingleLoopSum<ContainerType>::SingleLoopSum(const ContainerType& seq) 
    : SingleLoopSumBase<typename ContainerType::value_type>(seq.size(), 0, 0) {
    for (auto x : seq) {
        this->IncrementSums(x);
    }
}

} // namespace
} // namespace
} // namespace