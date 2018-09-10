#include <gtest/gtest.h>
#include <ferdi/num/interpolate.h>
#include <math.h>
using namespace std;

namespace ferdi {
namespace num {
namespace ut {

////////////////////////////////////////////////////////////////////////////////    
TEST(Num, Interpolate) {
    const vector<double> values_x({2, 4, 6 });
    const vector<double> values_y({2, 4, 6 });
    const double value = 3.0;
    ASSERT_TRUE(isnan(ferdi::num::Interpolate({1}, {2}, value, false)));
    ASSERT_EQ(ferdi::num::Interpolate(values_x, values_y, value, false), value);
    ASSERT_EQ(ferdi::num::Interpolate(values_x, values_y, values_y.front(), false), values_y.front());
}    
   
}
}
}
