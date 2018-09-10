#include <gtest/gtest.h>
#include <ferdi/num/drawdown.h>

using namespace std;

namespace ferdi {
namespace num {
namespace ut {
    
TEST(Num, Drawdown) {
    const vector<double> empty;
    const vector<double> one_day_win = { 1.0 };
    const vector<double> one_day_loss = { -1.0 };    
    const vector<double> const_positive = { 1, 1, 1, 1, 1 };
    const vector<double> short_dip = { 1, 1, -1, 1, 1 };
    const vector<double> long_dip = { 1, -1, -2, -1, 1, 1, 1 };
    ASSERT_EQ(ferdi::num::MaxDrawdown(empty), 0);
    ASSERT_EQ(ferdi::num::MaxDrawdown(one_day_win), 0);
    ASSERT_EQ(ferdi::num::MaxDrawdown(const_positive), 0);
    ASSERT_EQ(ferdi::num::MaxDrawdown(one_day_loss), -1.0 * one_day_loss.front());
    ASSERT_EQ(ferdi::num::MaxDrawdown(short_dip), 1.0);
    ASSERT_EQ(ferdi::num::MaxDrawdown(long_dip), 4.0);
    
    ASSERT_EQ(ferdi::num::CurrentDrawdown(empty), 0);
    ASSERT_EQ(ferdi::num::CurrentDrawdown(one_day_win), 0);
    ASSERT_EQ(ferdi::num::CurrentDrawdown(const_positive), 0);
    ASSERT_EQ(ferdi::num::CurrentDrawdown(short_dip), 0);
    ASSERT_EQ(ferdi::num::CurrentDrawdown(long_dip), 1);
}    
  
} // namespace 
} // namespace 
} // namespace
