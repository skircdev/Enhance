#include <gtest/gtest.h>
#include <ferdi/trading/currency.h>
#include <ferdi/trading/currency_string.h>

using namespace std;

namespace ferdi {
namespace trd {
namespace ut {
    
TEST(Trading, Currency) {
    vector<string> currencies = { "EUR", "USD", "SGD" };
    for (const auto& ccy: currencies) {
        ASSERT_EQ(ccy, ToString(CurrencyFromString(ccy)));
    }
}    
   
}
}
}
