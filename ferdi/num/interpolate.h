#pragma once

#include <vector>

namespace ferdi {
namespace num {

/*****************************************************************************//**
  * Returns interpolated value at x from parallel arrays ( xData, yData )
  * Assumes that xData has at least two elements, is sorted and is strictly monotonic increasing
  * boolean argument extrapolate determines behaviour beyond ends of array (if needed)  */
double Interpolate(const std::vector<double>& x, const std::vector<double>& y, double value, bool extrapolate);

// TODO TODO Make more robust against nan

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
inline double Interpolate(const std::vector<double>& x, const std::vector<double>& y, double value, bool extrapolate) {    
   const size_t size = x.size();
   if (size < 2) {
       return std::numeric_limits<double>::quiet_NaN();
   }

   int i = 0;                                                              // find left end of interval for interpolation
   if ( value >= x[size - 2] ) {                                           // special case: beyond right end 
      i = size - 2;
   }
   else {
      while ( value > x[i+1] ) i++;
   }
   double xL = x[i], yL = y[i], xR = x[i+1], yR = y[i+1];                  // points on either side (unless beyond ends)
   if ( !extrapolate ) {                                                   // if beyond ends of array and not extrapolating
      if ( value < xL ) yR = yL;
      if ( value > xR ) yL = yR;
   }

   const double dydx = ( yR - yL ) / ( xR - xL );                          // gradient
   return yL + dydx * ( value - xL );                                      // linear interpolation
}


} // namespace num
} // namespace ferdi 