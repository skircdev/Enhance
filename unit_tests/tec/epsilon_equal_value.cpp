#include <gtest/gtest.h>
#include <ferdi/tec/epsilon_equal_value.h>

namespace ferdi {
namespace tec {
namespace ut {
    
TEST(Tec, Price) {
    typedef EpsilonEqualValue<double> Price;
    const Price p_zero(0.0);
    const Price p_1(1.0);
    const Price p_2(2.0);
    const Price p_nan = Price::CreateInvalid();
    ASSERT_GT(p_2, p_1);
    ASSERT_LT(p_1, p_2);
    ASSERT_EQ(p_1, p_1);
    ASSERT_EQ(p_2, p_2);
    ASSERT_TRUE(p_1.IsNotZero());
    ASSERT_TRUE(p_1.IsPositive());
    ASSERT_FALSE(p_1.IsZero());
    ASSERT_TRUE(p_zero.IsZero());
    ASSERT_TRUE(p_1.IsValid());
    ASSERT_FALSE(p_nan.IsValid());
    ASSERT_TRUE(p_nan.IsNotValid());
}    
   
}
}
}
