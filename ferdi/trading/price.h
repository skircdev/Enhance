#pragma once

#include <ferdi/tec/epsilon_equal_value.h>

namespace ferdi {
namespace trd {

/**************************************************************************//**
   * Essentially a double with comparision operators that allow for 
   * numerical precision issues */
typedef ferdi::tec::EpsilonEqualValue<double> Price;

}  // namespace  trd
}  // namespace  ferdi



