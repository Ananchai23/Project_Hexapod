//
// File: MvAvgFilter.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 28-Mar-2018 17:31:11
//

// Include Files
#include "rt_nonfinite.h"
#include "MvAvgFilter.h"
#include "sum.h"
#include "RBF2Test.h"
#include "mod.h"

// Function Definitions

//
// A function to Filter Torque motor using a moving average filter.
//  where Input:
//                Data_TE     -> Matrix 18(Torque) + 3 (Gyro - Yaw,Pitch,Roll)
//                Count       -> Value control
//        Output:
//                x           -> Data (18*1) or (22*1) Test RBF
// Arguments    : const double T1[1440]
//                const double T2[1440]
//                const double T3[1440]
//                const double T4[1440]
//                const double T5[1440]
//                const double T6[1440]
//                const double T7[1440]
//                const double T8[1440]
//                const double T9[1440]
//                const double T10[1440]
//                const double T11[1440]
//                const double T12[1440]
//                const double T13[1440]
//                const double T14[1440]
//                const double T15[1440]
//                const double T16[1440]
//                const double T17[1440]
//                const double T18[1440]
//                double Count
//                double N
// Return Type  : double
//
double MvAvgFilter(const double T1[1440], const double T2[1440], const double
                   T3[1440], const double T4[1440], const double T5[1440], const
                   double T6[1440], const double T7[1440], const double T8[1440],
                   const double T9[1440], const double T10[1440], const double
                   T11[1440], const double T12[1440], const double T13[1440],
                   const double T14[1440], const double T15[1440], const double
                   T16[1440], const double T17[1440], const double T18[1440],
                   double Count, double N)
{
  double y;
  int i0;
  static double data_TE[25920];
  int i;
  int loop_ub;
  double x[18];
  int b_loop_ub;
  int data_TE_size[2];
  int b_data_TE_size[2];
  double data_TE_data[238];
  int c_data_TE_size[2];
  double b_data_TE_data[1440];
  for (i0 = 0; i0 < 1440; i0++) {
    data_TE[18 * i0] = T1[i0];
    data_TE[1 + 18 * i0] = T2[i0];
    data_TE[2 + 18 * i0] = T3[i0];
    data_TE[3 + 18 * i0] = T4[i0];
    data_TE[4 + 18 * i0] = T5[i0];
    data_TE[5 + 18 * i0] = T6[i0];
    data_TE[6 + 18 * i0] = T7[i0];
    data_TE[7 + 18 * i0] = T8[i0];
    data_TE[8 + 18 * i0] = T9[i0];
    data_TE[9 + 18 * i0] = T10[i0];
    data_TE[10 + 18 * i0] = T11[i0];
    data_TE[11 + 18 * i0] = T12[i0];
    data_TE[12 + 18 * i0] = T13[i0];
    data_TE[13 + 18 * i0] = T14[i0];
    data_TE[14 + 18 * i0] = T15[i0];
    data_TE[15 + 18 * i0] = T16[i0];
    data_TE[16 + 18 * i0] = T17[i0];
    data_TE[17 + 18 * i0] = T18[i0];
  }

  //  Select 18(Torque) + 3 (Gyro)
  //  span for the moving average
  //  Buffer data
  //  allocation
  y = 0.0;
  if (N == 1.0) {
    if (Count <= 238.0) {
      if (b_mod(Count) == 1.0) {
        if (1.0 > Count) {
          loop_ub = 0;
        } else {
          loop_ub = (int)Count;
        }

        for (i = 0; i < 18; i++) {
          data_TE_size[0] = 1;
          data_TE_size[1] = loop_ub;
          for (i0 = 0; i0 < loop_ub; i0++) {
            data_TE_data[i0] = data_TE[i + 18 * i0];
          }

          x[i] = sum(data_TE_data, data_TE_size) / Count;
        }

        y = RBF2Test(x);
      }
    } else {
      if ((Count >= 239.0) && (Count <= 1440.0)) {
        for (i = 0; i < 18; i++) {
          if ((Count - 239.0) + 1.0 > Count) {
            i0 = 0;
            b_loop_ub = 0;
          } else {
            i0 = (int)((Count - 239.0) + 1.0) - 1;
            b_loop_ub = (int)Count;
          }

          data_TE_size[0] = 1;
          data_TE_size[1] = b_loop_ub - i0;
          loop_ub = b_loop_ub - i0;
          for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
            b_data_TE_data[b_loop_ub] = data_TE[i + 18 * (i0 + b_loop_ub)];
          }

          x[i] = sum(b_data_TE_data, data_TE_size) / 239.0;
        }

        y = RBF2Test(x);
      }
    }
  }

  if (N >= 2.0) {
    if (Count <= 238.0) {
      if (1.0 > Count) {
        loop_ub = 0;
      } else {
        loop_ub = (int)Count;
      }

      b_loop_ub = 1441 - (int)(478.0 + Count);
      for (i = 0; i < 18; i++) {
        b_data_TE_size[0] = 1;
        b_data_TE_size[1] = 1441 - (int)(478.0 + Count);
        for (i0 = 0; i0 < b_loop_ub; i0++) {
          b_data_TE_data[i0] = data_TE[i + 18 * (((int)(478.0 + Count) + i0) - 1)];
        }

        c_data_TE_size[0] = 1;
        c_data_TE_size[1] = loop_ub;
        for (i0 = 0; i0 < loop_ub; i0++) {
          data_TE_data[i0] = data_TE[i + 18 * i0];
        }

        x[i] = (sum(b_data_TE_data, b_data_TE_size) + sum(data_TE_data,
                 c_data_TE_size)) / 239.0;
      }

      y = RBF2Test(x);
    } else {
      if ((Count >= 239.0) && (Count <= 1440.0)) {
        for (i = 0; i < 18; i++) {
          if ((Count - 239.0) + 1.0 > Count) {
            i0 = 0;
            b_loop_ub = 0;
          } else {
            i0 = (int)((Count - 239.0) + 1.0) - 1;
            b_loop_ub = (int)Count;
          }

          b_data_TE_size[0] = 1;
          b_data_TE_size[1] = b_loop_ub - i0;
          loop_ub = b_loop_ub - i0;
          for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
            b_data_TE_data[b_loop_ub] = data_TE[i + 18 * (i0 + b_loop_ub)];
          }

          x[i] = sum(b_data_TE_data, b_data_TE_size) / 239.0;
        }

        y = RBF2Test(x);
      }
    }
  }

  return y;
}

//
// File trailer for MvAvgFilter.cpp
//
// [EOF]
//
