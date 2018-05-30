//
// File: sum.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 28-Mar-2018 17:31:11
//

// Include Files
#include "rt_nonfinite.h"
#include "MvAvgFilter.h"
#include "sum.h"

// Function Definitions

//
// Arguments    : const double x_data[]
//                const int x_size[2]
// Return Type  : double
//
double sum(const double x_data[], const int x_size[2])
{
  double y;
  int k;
  if (x_size[1] == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= x_size[1]; k++) {
      y += x_data[k - 1];
    }
  }

  return y;
}

//
// File trailer for sum.cpp
//
// [EOF]
//
