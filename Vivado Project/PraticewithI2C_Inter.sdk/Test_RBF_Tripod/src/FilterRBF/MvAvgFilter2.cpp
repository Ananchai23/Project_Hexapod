//
// File: MvAvgFilter2.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 18-May-2018 16:04:25
//

// Include Files
#include "rt_nonfinite.h"
#include "MvAvgFilter2.h"
#include "sum.h"
#include "RBF2Test2.h"
#include "mod.h"

// Function Definitions

//
// A function to Filter Torque motor using a moving average filter.
//  where Input:
//                Data_TE     -> Matrix 18(Torque) + 3 (Gyro - Yaw,Pitch,Roll)
//                Count       -> Value control
//        Output:
//                x           -> Data (18*1) or (22*1) Test RBF
// Arguments    : const double T1[1200]
//                const double T2[1200]
//                const double T3[1200]
//                const double T4[1200]
//                const double T5[1200]
//                const double T6[1200]
//                const double T7[1200]
//                const double T8[1200]
//                const double T9[1200]
//                const double T10[1200]
//                const double T11[1200]
//                const double T12[1200]
//                const double T13[1200]
//                const double T14[1200]
//                const double T15[1200]
//                const double T16[1200]
//                const double T17[1200]
//                const double T18[1200]
//                double Count
//                double N
// Return Type  : double
//
double MvAvgFilter2(const double T1[1200], const double T2[1200], const double
                    T3[1200], const double T4[1200], const double T5[1200],
                    const double T6[1200], const double T7[1200], const double
                    T8[1200], const double T9[1200], const double T10[1200],
                    const double T11[1200], const double T12[1200], const double
                    T13[1200], const double T14[1200], const double T15[1200],
                    const double T16[1200], const double T17[1200], const double
                    T18[1200], double Count, double N)
{
  double y;
  int i0;
  static double data_TE[21600];
  int i;
  int loop_ub;
  double x[18];
  int b_loop_ub;
  int data_TE_size[2];
  int b_data_TE_size[2];
  double data_TE_data[99];
  int c_data_TE_size[2];
  double b_data_TE_data[1200];

  // 'MvAvgFilter2:9' Buffer_data = 1200;
  // 'MvAvgFilter2:10' data_TE = [T1(1:Buffer_data);T2(1:Buffer_data);T3(1:Buffer_data);T4(1:Buffer_data);T5(1:Buffer_data);T6(1:Buffer_data);T7(1:Buffer_data);T8(1:Buffer_data);T9(1:Buffer_data);... 
  // 'MvAvgFilter2:11'     T10(1:Buffer_data);T11(1:Buffer_data);T12(1:Buffer_data);T13(1:Buffer_data);T14(1:Buffer_data);T15(1:Buffer_data);T16(1:Buffer_data);T17(1:Buffer_data);T18(1:Buffer_data)]; 
  for (i0 = 0; i0 < 1200; i0++) {
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

  // 'MvAvgFilter2:12' num_in = 18;
  //  Select 18(Torque) + 3 (Gyro)
  // 'MvAvgFilter2:13' span = 100;
  //  span for the moving average
  // 'MvAvgFilter2:14' Point_data = Buffer_data;
  //  Buffer data
  // 'MvAvgFilter2:15' x = zeros(num_in,1);
  //  allocation
  // 'MvAvgFilter2:16' y = 0;
  y = 0.0;

  // 'MvAvgFilter2:18' if N ==1
  if (N == 1.0) {
    // 'MvAvgFilter2:19' if Count <= span - 1
    if (Count <= 99.0) {
      // 'MvAvgFilter2:20' odd = mod(Count,2);
      // 'MvAvgFilter2:21' if(odd == 1)
      if (b_mod(Count) == 1.0) {
        // 'MvAvgFilter2:22' for i=1 : num_in
        // 'MvAvgFilter2:25' x = x/Count;
        if (1.0 > Count) {
          loop_ub = 0;
        } else {
          loop_ub = (int)Count;
        }

        for (i = 0; i < 18; i++) {
          // 'MvAvgFilter2:23' x(i,1) = sum(data_TE(i,1:Count),2);
          data_TE_size[0] = 1;
          data_TE_size[1] = loop_ub;
          for (i0 = 0; i0 < loop_ub; i0++) {
            data_TE_data[i0] = data_TE[i + 18 * i0];
          }

          x[i] = sum(data_TE_data, data_TE_size) / Count;
        }

        // 'MvAvgFilter2:26' y = RBF2Test2(x);
        y = RBF2Test2(x);
      }
    } else {
      if ((Count >= 100.0) && (Count <= 1200.0)) {
        // 'MvAvgFilter2:28' elseif Count >= span && Count <= Point_data
        // 'MvAvgFilter2:30' startp = Count - span + 1;
        // 'MvAvgFilter2:31' endp   = Count;
        // 'MvAvgFilter2:33' for i=1:num_in
        // 'MvAvgFilter2:36' x = x/span;
        for (i = 0; i < 18; i++) {
          // 'MvAvgFilter2:34' x(i,1) = sum(data_TE(i,startp:endp),2);
          if ((Count - 100.0) + 1.0 > Count) {
            i0 = 0;
            b_loop_ub = 0;
          } else {
            i0 = (int)((Count - 100.0) + 1.0) - 1;
            b_loop_ub = (int)Count;
          }

          data_TE_size[0] = 1;
          data_TE_size[1] = b_loop_ub - i0;
          loop_ub = b_loop_ub - i0;
          for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
            b_data_TE_data[b_loop_ub] = data_TE[i + 18 * (i0 + b_loop_ub)];
          }

          x[i] = sum(b_data_TE_data, data_TE_size) / 100.0;
        }

        // 'MvAvgFilter2:37' y = RBF2Test2(x);
        y = RBF2Test2(x);
      }
    }
  }

  // 'MvAvgFilter2:41' if N >= 2
  if (N >= 2.0) {
    // 'MvAvgFilter2:42' if Count <= span-1
    if (Count <= 99.0) {
      // 'MvAvgFilter2:44' startp = 2*span + Count;
      // 'MvAvgFilter2:45' endp   = Point_data;
      // 'MvAvgFilter2:47' for i=1:num_in
      // 'MvAvgFilter2:50' x = x/span;
      if (1.0 > Count) {
        loop_ub = 0;
      } else {
        loop_ub = (int)Count;
      }

      b_loop_ub = 1201 - (int)(200.0 + Count);
      for (i = 0; i < 18; i++) {
        // 'MvAvgFilter2:48' x(i,1) = sum(data_TE(i,startp:endp),2) + sum(data_TE(i,1:Count),2); 
        b_data_TE_size[0] = 1;
        b_data_TE_size[1] = 1201 - (int)(200.0 + Count);
        for (i0 = 0; i0 < b_loop_ub; i0++) {
          b_data_TE_data[i0] = data_TE[i + 18 * (((int)(200.0 + Count) + i0) - 1)];
        }

        c_data_TE_size[0] = 1;
        c_data_TE_size[1] = loop_ub;
        for (i0 = 0; i0 < loop_ub; i0++) {
          data_TE_data[i0] = data_TE[i + 18 * i0];
        }

        x[i] = (sum(b_data_TE_data, b_data_TE_size) + sum(data_TE_data,
                 c_data_TE_size)) / 100.0;
      }

      // 'MvAvgFilter2:51' y = RBF2Test2(x);
      y = RBF2Test2(x);
    } else {
      if ((Count >= 100.0) && (Count <= 1200.0)) {
        // 'MvAvgFilter2:53' elseif Count >= span && Count <= Point_data
        // 'MvAvgFilter2:55' startp = Count - span + 1;
        // 'MvAvgFilter2:56' endp   = Count;
        // 'MvAvgFilter2:58' for i=1:num_in
        // 'MvAvgFilter2:61' x = x/span;
        for (i = 0; i < 18; i++) {
          // 'MvAvgFilter2:59' x(i,1) = sum(data_TE(i,startp:endp),2);
          if ((Count - 100.0) + 1.0 > Count) {
            i0 = 0;
            b_loop_ub = 0;
          } else {
            i0 = (int)((Count - 100.0) + 1.0) - 1;
            b_loop_ub = (int)Count;
          }

          b_data_TE_size[0] = 1;
          b_data_TE_size[1] = b_loop_ub - i0;
          loop_ub = b_loop_ub - i0;
          for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
            b_data_TE_data[b_loop_ub] = data_TE[i + 18 * (i0 + b_loop_ub)];
          }

          x[i] = sum(b_data_TE_data, b_data_TE_size) / 100.0;
        }

        // 'MvAvgFilter2:62' y = RBF2Test2(x);
        y = RBF2Test2(x);
      }
    }
  }

  return y;
}

//
// File trailer for MvAvgFilter2.cpp
//
// [EOF]
//
