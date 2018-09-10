#include <gtest/gtest.h>
#include <ferdi/trading/trading_enums_string.h>
#include <ferdi/trading/price.h>
#include <ferdi/trading/exec_side_compile_time_traits.h>
#include <ferdi/trading/exec_side_run_time_traits.h>

//using namespace ferdi::trd;

namespace ferdi {
namespace trd {
namespace ut {


////////////////////////////////////////////////////////////////////////////////    
TEST(Trading, ExecSideTraits) {
    const ExecSide buy  = ExecSide::BUY;
    const ExecSide sell = ExecSide::SELL;
    
    // ----- String
    ASSERT_EQ(buy,  ExecSideFromString(ToString(buy)));
    ASSERT_EQ(buy,  ExecSideFromString(ToProperCaseString(buy)));
    ASSERT_EQ(buy,  ExecSideFromString("BUY"));
    ASSERT_EQ(buy,  ExecSideFromString("Buy"));
    ASSERT_EQ(sell, ExecSideFromString(ToString(sell)));
    ASSERT_EQ(sell, ExecSideFromString(ToProperCaseString(sell)));
    ASSERT_EQ(buy,  ExecSideFromString(std::string("BUY").c_str()));
    
    // ----- OtherSide
    ASSERT_EQ(buy,  OtherSide(sell));
    ASSERT_EQ(buy,  OtherSide<sell>());
    ASSERT_EQ(sell, OtherSide(buy));
    ASSERT_EQ(sell, OtherSide<buy>());
    ASSERT_NE(buy, OtherSide(buy));
    
    // ----- IsGreater
    ASSERT_TRUE(IsGreater(sell, 2, 1));
    ASSERT_FALSE(IsGreater(buy, 2, 1));
    
    // ----- PositionAddQty
    ASSERT_EQ(7.0,   PositionAddQty(buy, 5.0, 2.0));
    ASSERT_EQ(2.0,   PositionAddQty(buy, -5.0, 7.0));
    ASSERT_EQ(3.0,   PositionAddQty(sell, 5.0, 2.0));
    ASSERT_EQ(-6.0,  PositionAddQty(sell, -5.0, 1.0));
    
    // ----- Run Time vs Compile Time 
    std::vector<std::pair<double, double>> test_cases = { std::make_pair(2, 7), std::make_pair(2, -7) };
    for (const auto& tc: test_cases) {
        ASSERT_EQ(Diff<buy>(tc.first, tc.second), Diff(buy, tc.first, tc.second));
        ASSERT_EQ(Diff<sell>(tc.first, tc.second), Diff(sell, tc.first, tc.second));
        ASSERT_EQ(Add<buy>(Price(tc.first), ferdi::trd::Price(tc.second)), ferdi::trd::Price(Add(buy, tc.first, tc.second)));
    }
}    
   
}
}
}
