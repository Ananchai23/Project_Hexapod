//
// File: mod.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 28-Mar-2018 17:31:11
//

// Include Files
#include "rt_nonfinite.h"
#include "MvAvgFilter.h"
#include "mod.h"

// Function Definitions

//
// Arguments    : double x
// Return Type  : double
//
double b_mod(double x)
{
  double r;
  if (!rtIsInf(x)) {
    if (x == 0.0) {
      r = 0.0;
    } else {
      r = std::fmod(x, 2.0);
      if (r == 0.0) {
        r = 0.0;
      } else {
        if (x < 0.0) {
          r += 2.0;
        }
      }
    }
  } else {
    r = rtNaN;
  }

  return r;
}

//
// File trailer for mod.cpp
//
// [EOF]
//
