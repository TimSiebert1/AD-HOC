/*        Generated by TAPENADE     (INRIA, Ecuador team)
    Tapenade 3.16 (develop) - 25 Oct 2024 09:00
*/
/*        Generated by TAPENADE     (INRIA, Ecuador team)
    Tapenade 3.16 (develop) - 25 Oct 2024 09:00

        Generated by TAPENADE     (INRIA, Ecuador team)
    Tapenade 3.16 (develop) - 25 Oct 2024 09:00

        Generated by TAPENADE     (INRIA, Ecuador team)
    Tapenade 3.16 (develop) - 25 Oct 2024 09:00
*/
#include <math.h>
#include <stdio.h>

/*
  Differentiation of cdf_n_d_d_d in forward (tangent) mode:
   variations   of useful results: *cdf_ndd *cdf_n_dd *cdf_nd
                *cdf_n_d *cdf_nd0 *cdf_n_d_d *cdf_n cdf_n_d_d_d
   with respect to varying inputs: *cdf_ndd xd0d *cdf_n_dd xddd
                xdd xd x *cdf_nd *cdf_n_d *cdf_nd0 *cdf_n_d_d
                *cdf_n xdd0 xd0 xd1
   Plus diff mem management of: cdf_ndd:in cdf_n_dd:in cdf_nd:in
                cdf_n_d:in cdf_nd0:in cdf_n_d_d:in cdf_n:in


  Differentiation of cdf_n_d_d in forward (tangent) mode:
   variations   of useful results: *cdf_nd *cdf_n_d cdf_n_d_d
                *cdf_n
   with respect to varying inputs: xdd xd x *cdf_nd *cdf_n_d *cdf_n
                xd0
   Plus diff mem management of: cdf_nd:in cdf_n_d:in cdf_n:in


  Differentiation of cdf_n_d in forward (tangent) mode:
   variations   of useful results: cdf_n_d *cdf_n
   with respect to varying inputs: xd x *cdf_n
   Plus diff mem management of: cdf_n:in


  Differentiation of cdf_n in forward (tangent) mode:
   variations   of useful results: cdf_n
   with respect to varying inputs: x
*/
double cdf_n_d_d_d_d(double x, double xd2, double xd1, double xd1d, double xd0
        , double xd0d0, double xd0d, double xd0dd, double xd, double xdd1, 
        double xdd0, double xdd0d, double xdd, double xddd0, double xddd, 
        double xdddd, double *cdf_n, double *cdf_nd1, double *cdf_nd0, double 
        *cdf_nd0d, double *cdf_nd, double *cdf_ndd0, double *cdf_ndd, double *
        cdf_nddd, double *cdf_n_d, double *cdf_n_dd0, double *cdf_n_dd, double
        *cdf_n_ddd, double *cdf_n_d_d, double *cdf_n_d_dd, double *cdf_n_d_d_d
) {
    double arg1;
    double arg1d1;
    double arg1d0;
    double arg1d0d;
    double arg1d;
    double arg1dd0;
    double arg1dd;
    double arg1ddd;
    double temp;
    double tempd0;
    double tempd;
    double tempdd;
    double arg10;
    double arg10d0;
    double arg10d;
    double arg10dd;
    double temp0;
    double temp0d;
    double arg11;
    double arg11d;
    double temp1;
    double temp2;
    double temp3;
    arg10dd = -(0.70710678118654746*0.70710678118654746*2*(xd1*xd2+x*xd1d));
    arg10d = -(0.70710678118654746*0.70710678118654746*2*x*xd1);
    arg10d0 = -(0.70710678118654746*0.70710678118654746*2*x*xd2);
    arg10 = -(-(0.70710678118654746*x)*-(0.70710678118654746*x));
    temp0d = exp(arg10)*arg10d0;
    temp0 = exp(arg10);
    temp1 = exp(arg10);
    *cdf_nddd = 0.70710678118654746*0.5*1.1283791671*(xd0*arg10d*exp(arg10)*
        arg10d0+temp1*(arg10d*xd0d0+xd0*arg10dd)+xd0d*temp0d+temp0*xd0dd);
    *cdf_ndd = 0.70710678118654746*0.5*1.1283791671*(temp1*(xd0*arg10d)+temp0*
        xd0d);
    *cdf_ndd0 = 0.70710678118654746*0.5*1.1283791671*(xd0*temp0d+temp0*xd0d0);
    *cdf_nd = 1.1283791671*0.70710678118654746*0.5*(temp0*xd0);
    arg11d = -(0.70710678118654746*0.70710678118654746*2*x*xd2);
    arg11 = -(-(0.70710678118654746*x)*-(0.70710678118654746*x));
    temp1 = exp(arg11);
    *cdf_nd0d = 1.1283791671*0.70710678118654746*0.5*(xd1*exp(arg11)*arg11d+
        temp1*xd1d);
    *cdf_nd0 = 1.1283791671*0.70710678118654746*0.5*(temp1*xd1);
    *cdf_nd1 = 0.5*1.1283791671*exp(-(-(0.70710678118654746*x)*-(
        0.70710678118654746*x)))*0.70710678118654746*xd2;
    *cdf_n = 0.5*erfc(x*-0.70710678118654746);
    arg1ddd = -(0.70710678118654746*0.70710678118654746*2*(xd1*xd0d0+xd0*xd1d+
        xd0d*xd2+x*xd0dd));
    arg1dd = -(0.70710678118654746*0.70710678118654746*2*(xd0*xd1+x*xd0d));
    arg1dd0 = -(0.70710678118654746*0.70710678118654746*2*(xd0*xd2+x*xd0d0));
    arg1d = -(0.70710678118654746*0.70710678118654746*2*x*xd0);
    arg1d0d = -(0.70710678118654746*0.70710678118654746*2*(xd1*xd2+x*xd1d));
    arg1d0 = -(0.70710678118654746*0.70710678118654746*2*x*xd1);
    arg1d1 = -(0.70710678118654746*0.70710678118654746*2*x*xd2);
    arg1 = -(-(0.70710678118654746*x)*-(0.70710678118654746*x));
    temp1 = exp(arg1);
    tempdd = arg1d0*exp(arg1)*arg1d1 + temp1*arg1d0d;
    tempd = temp1*arg1d0;
    tempd0 = exp(arg1)*arg1d1;
    temp = exp(arg1);
    *cdf_n_ddd = 0.5*1.1283791671*0.70710678118654746*(tempd*xdd1+xd*tempdd+
        xdd0*tempd0+temp*xdd0d);
    *cdf_n_dd = 0.70710678118654746*0.5*1.1283791671*(xd*tempd+temp*xdd0);
    *cdf_n_dd0 = 0.70710678118654746*0.5*1.1283791671*(xd*tempd0+temp*xdd1);
    *cdf_n_d = 1.1283791671*0.70710678118654746*0.5*(temp*xd);
    temp0d = exp(arg1)*arg1d1;
    temp0 = exp(arg1);
    *cdf_n_d_dd = 0.5*1.1283791671*0.70710678118654746*(arg1d*(xd*temp0d+temp0
        *xdd1)+temp0*xd*arg1dd0+xdd*tempd0+temp*xddd0);
    *cdf_n_d_d = 0.70710678118654746*0.5*1.1283791671*(temp0*(xd*arg1d)+temp*
        xdd);
    temp1 = exp(arg1);
    temp2 = xd*arg1d*arg1d0;
    temp3 = arg1d*xdd0 + xd*arg1dd;
    *cdf_n_d_d_d = 0.5*1.1283791671*0.70710678118654746*(temp2*temp1+temp0*
        temp3+xdd*tempd+temp*xddd);
    return 0.5*1.1283791671*0.70710678118654746*(temp1*(arg1d0*(arg1d*xdd1+xd*
    arg1dd0)+xd*arg1d*arg1d0d)+temp2*exp(arg1)*arg1d1+temp3*temp0d+temp0*(xdd0
    *arg1dd0+arg1d*xdd0d+arg1dd*xdd1+xd*arg1ddd)+tempd*xddd0+xdd*tempdd+xddd*
    tempd0+temp*xdddd);
}

/*
  Differentiation of call_price_d_d_d in forward (tangent) mode:
   variations   of useful results: *call_price_dd *call_price_d
                *call_priced0 *call_price call_price_d_d_d *call_priced
                *call_price_d_d *call_pricedd
   with respect to varying inputs: Sdd0 Td Sd0 Sd1 Kd0d v Kd0
                Tdd Kd1 Kddd Kd vd0d *call_price_dd Td0d vddd
                *call_price_d Sd0d *call_priced0 Tddd vd0 vd1
                *call_price Sddd vd Sdd *call_priced Td0 Td1 Kdd0
                Sd Kdd K *call_price_d_d S T vdd0 Tdd0 *call_pricedd
                vdd
   RW status of diff variables: Sdd0:in Td:in Sd0:in Sd1:in Kd0d:in
                v:in Kd0:in Tdd:in Kd1:in Kddd:in Kd:in vd0d:in
                call_price_dd:(loc) *call_price_dd:in-out Td0d:in
                vddd:in call_price_d:(loc) *call_price_d:in-out
                Sd0d:in call_priced0:(loc) *call_priced0:in-out
                Tddd:in vd0:in vd1:in call_price:(loc) *call_price:in-out
                Sddd:in vd:in Sdd:in call_price_d_d_d:out call_priced:(loc)
                *call_priced:in-out Td0:in Td1:in Kdd0:in Sd:in
                Kdd:in K:in call_price_d_d:(loc) *call_price_d_d:in-out
                S:in T:in vdd0:in Tdd0:in call_pricedd:(loc) *call_pricedd:in-out
                vdd:in
   Plus diff mem management of: call_price_dd:in call_price_d:in
                call_priced0:in call_price:in call_priced:in call_price_d_d:in
                call_pricedd:in


  Differentiation of call_price_d_d in forward (tangent) mode:
   variations   of useful results: *call_price_d *call_price *call_priced
                call_price_d_d
   with respect to varying inputs: Td Sd0 v Kd0 Tdd Kd *call_price_d
                vd0 *call_price vd Sdd *call_priced Td0 Sd Kdd
                K S T vdd
   RW status of diff variables: Td:in Sd0:in v:in Kd0:in Tdd:in
                Kd:in call_price_d:(loc) *call_price_d:in-out
                vd0:in call_price:(loc) *call_price:in-out vd:in
                Sdd:in call_priced:(loc) *call_priced:in-out Td0:in
                Sd:in Kdd:in K:in call_price_d_d:out S:in T:in
                vdd:in
   Plus diff mem management of: call_price_d:in call_price:in
                call_priced:in


  Differentiation of call_price_d in forward (tangent) mode:
   variations   of useful results: call_price_d *call_price
   with respect to varying inputs: Td v Kd *call_price vd Sd K
                S T
   RW status of diff variables: Td:in v:in Kd:in call_price_d:out
                call_price:(loc) *call_price:in-out vd:in Sd:in
                K:in S:in T:in
   Plus diff mem management of: call_price:in


  Differentiation of call_price in forward (tangent) mode:
   variations   of useful results: call_price
   with respect to varying inputs: v K S T
   RW status of diff variables: v:in call_price:out K:in S:in
                T:in
*/
double call_price_d_d_d_d(double S, double Sd2, double Sd1, double Sd1d, 
        double Sd0, double Sd0d0, double Sd0d, double Sd0dd, double Sd, double
        Sdd1, double Sdd0, double Sdd0d, double Sdd, double Sddd0, double Sddd
        , double Sdddd, double K, double Kd2, double Kd1, double Kd1d, double 
        Kd0, double Kd0d0, double Kd0d, double Kd0dd, double Kd, double Kdd1, 
        double Kdd0, double Kdd0d, double Kdd, double Kddd0, double Kddd, 
        double Kdddd, double v, double vd2, double vd1, double vd1d, double 
        vd0, double vd0d0, double vd0d, double vd0dd, double vd, double vdd1, 
        double vdd0, double vdd0d, double vdd, double vddd0, double vddd, 
        double vdddd, double T, double Td2, double Td1, double Td1d, double 
        Td0, double Td0d0, double Td0d, double Td0dd, double Td, double Tdd1, 
        double Tdd0, double Tdd0d, double Tdd, double Tddd0, double Tddd, 
        double Tdddd, double *call_price, double *call_priced1, double *
        call_priced0, double *call_priced0d, double *call_priced, double *
        call_pricedd0, double *call_pricedd, double *call_priceddd, double *
        call_price_d, double *call_price_dd0, double *call_price_dd, double *
        call_price_ddd, double *call_price_d_d, double *call_price_d_dd, 
        double *call_price_d_d_d) {
    double totalvol;
    double totalvold2;
    double totalvold1;
    double totalvold1d;
    double totalvold0;
    double totalvold0d0;
    double totalvold0d;
    double totalvold0dd;
    double totalvold;
    double totalvoldd1;
    double totalvoldd0;
    double totalvoldd0d;
    double totalvoldd;
    double totalvolddd0;
    double totalvolddd;
    double totalvoldddd;
    double result1;
    double result1d2;
    double result1d1;
    double result1d1d;
    double result1d0;
    double result1d0d0;
    double result1d0d;
    double result1d0dd;
    double result1d;
    double result1dd1;
    double result1dd0;
    double result1dd0d;
    double result1dd;
    double result1ddd0;
    double result1ddd;
    double result1dddd;
    double result2;
    double result2d2;
    double result2d1;
    double result2d1d;
    double result2d0;
    double result2d0d0;
    double result2d0d;
    double result2d0dd;
    double result2d;
    double result2dd1;
    double result2dd0;
    double result2dd0d;
    double result2dd;
    double result2ddd0;
    double result2ddd;
    double result2dddd;
    double temp;
    double tempd1;
    double tempd0;
    double tempd0d;
    double tempd;
    double tempdd0;
    double tempdd;
    double tempddd;
    double temp0;
    double temp0d1;
    double temp0d0;
    double temp0d0d;
    double temp0d;
    double temp0dd0;
    double temp0dd;
    double temp0ddd;
    double temp1;
    double temp1d0;
    double temp1d;
    double temp1dd;
    double temp2;
    double temp2d0;
    double temp2d;
    double temp2dd;
    double temp3;
    double temp3d;
    double temp4;
    double temp4d;
    double temp5;
    double temp5d;
    double temp6;
    double temp7;
    double temp8;
    double temp9;
    temp6 = sqrt(T);
    temp3d = (T == 0.0 ? 0.0 : Td2/(2.0*temp6));
    temp3 = temp6;
    temp6 = Td1/(2.0*temp3);
    temp1dd = (T == 0.0 ? 0.0 : (Td1d-temp6*2.0*temp3d)/(2.0*temp3));
    temp1d = (T == 0.0 ? 0.0 : temp6);
    temp1d0 = temp3d;
    temp1 = temp3;
    temp6 = Td0/(2.0*temp1);
    temp3d = (Td0d0-temp6*2.0*temp1d0)/(2.0*temp1);
    temp3 = temp6;
    temp6 = (Td0d-2.0*temp3*temp1d)/(2.0*temp1);
    tempddd = (T == 0.0 ? 0.0 : (Td0dd-2.0*(temp1d*temp3d+temp3*temp1dd)-temp6
        *2.0*temp1d0)/(2.0*temp1));
    tempdd = (T == 0.0 ? 0.0 : temp6);
    tempdd0 = (T == 0.0 ? 0.0 : temp3d);
    tempd = (T == 0.0 ? 0.0 : temp3);
    tempd0d = temp1dd;
    tempd0 = temp1d;
    tempd1 = temp1d0;
    temp = temp1;
    temp6 = Td/(2.0*temp);
    temp3d = (Tdd1-temp6*2.0*tempd1)/(2.0*temp);
    temp3 = temp6;
    temp6 = (Tdd0-2.0*temp3*tempd0)/(2.0*temp);
    temp1dd = (Tdd0d-2.0*(tempd0*temp3d+temp3*tempd0d)-temp6*2.0*tempd1)/(2.0*
        temp);
    temp1d = temp6;
    temp1d0 = temp3d;
    temp1 = temp3;
    temp6 = (Tdd-2.0*temp1*tempd)/(2.0*temp);
    temp3d = (Tddd0-2.0*(tempd*temp1d0+temp1*tempdd0)-temp6*2.0*tempd1)/(2.0*
        temp);
    temp3 = temp6;
    temp6 = (Tddd-2.0*(tempd*temp1d+temp1*tempdd)-2.0*temp3*tempd0)/(2.0*temp)
    ;
    result1dddd = (T == 0.0 ? 0.0 : (Tdddd-2.0*(temp1d*tempdd0+tempd*temp1dd+
        tempdd*temp1d0+temp1*tempddd)-2.0*(tempd0*temp3d+temp3*tempd0d)-temp6*
        2.0*tempd1)/(2.0*temp));
    result1ddd = (T == 0.0 ? 0.0 : temp6);
    result1ddd0 = (T == 0.0 ? 0.0 : temp3d);
    result1dd = (T == 0.0 ? 0.0 : temp3);
    result1dd0d = (T == 0.0 ? 0.0 : temp1dd);
    result1dd0 = (T == 0.0 ? 0.0 : temp1d);
    result1dd1 = (T == 0.0 ? 0.0 : temp1d0);
    result1d = (T == 0.0 ? 0.0 : temp1);
    result1d0dd = tempddd;
    result1d0d = tempdd;
    result1d0d0 = tempdd0;
    result1d0 = tempd;
    result1d1d = tempd0d;
    result1d1 = tempd0;
    result1d2 = tempd1;
    result1 = temp;
    totalvoldddd = vdd0*result1d0d0 + result1d0*vdd0d + result1d0d*vdd1 + vd*
        result1d0dd + result1d1*vddd0 + vdd*result1d1d + vddd*result1d2 + 
        result1*vdddd + result1dd0*vd0d0 + vd0*result1dd0d + vd0d*result1dd1 +
        result1d*vd0dd + vd1*result1ddd0 + result1dd*vd1d + result1ddd*vd2 + v
        *result1dddd;
    totalvolddd = result1d0*vdd0 + vd*result1d0d + vdd*result1d1 + result1*
        vddd + vd0*result1dd0 + result1d*vd0d + result1dd*vd1 + v*result1ddd;
    totalvolddd0 = result1d0*vdd1 + vd*result1d0d0 + vdd*result1d2 + result1*
        vddd0 + vd0*result1dd1 + result1d*vd0d0 + result1dd*vd2 + v*
        result1ddd0;
    totalvoldd = vd*result1d0 + result1*vdd + result1d*vd0 + v*result1dd;
    totalvoldd0d = result1d1*vdd1 + vd*result1d1d + vdd0*result1d2 + result1*
        vdd0d + vd1*result1dd1 + result1d*vd1d + result1dd0*vd2 + v*
        result1dd0d;
    totalvoldd0 = vd*result1d1 + result1*vdd0 + result1d*vd1 + v*result1dd0;
    totalvoldd1 = vd*result1d2 + result1*vdd1 + result1d*vd2 + v*result1dd1;
    totalvold = result1*vd + v*result1d;
    totalvold0dd = result1d1*vd0d0 + vd0*result1d1d + vd0d*result1d2 + result1
        *vd0dd + vd1*result1d0d0 + result1d0*vd1d + result1d0d*vd2 + v*
        result1d0dd;
    totalvold0d = vd0*result1d1 + result1*vd0d + result1d0*vd1 + v*result1d0d;
    totalvold0d0 = vd0*result1d2 + result1*vd0d0 + result1d0*vd2 + v*
        result1d0d0;
    totalvold0 = result1*vd0 + v*result1d0;
    totalvold1d = vd1*result1d2 + result1*vd1d + result1d1*vd2 + v*result1d1d;
    totalvold1 = result1*vd1 + v*result1d1;
    totalvold2 = result1*vd2 + v*result1d2;
    totalvol = v*result1;
    temp6 = S*Kd0/K;
    temp3d = (Kd0*Sd2+S*Kd0d0-temp6*Kd2)/K;
    temp3 = temp6;
    temp6 = (Sd0-temp3)/K;
    temp4d = (Sd0d0-temp3d-temp6*Kd2)/K;
    temp4 = temp6;
    temp6 = (Kd0*Sd1+S*Kd0d-temp3*Kd1)/K;
    temp7 = (Sd0d-temp6-temp4*Kd1)/K;
    tempddd = (Sd0dd-(Sd1*Kd0d0+Kd0*Sd1d+Kd0d*Sd2+S*Kd0dd-Kd1*temp3d-temp3*
        Kd1d-temp6*Kd2)/K-Kd1*temp4d-temp4*Kd1d-temp7*Kd2)/K;
    tempdd = temp7;
    tempdd0 = temp4d;
    tempd = temp4;
    temp7 = S*Kd1/K;
    temp6 = (Sd1-temp7)/K;
    tempd0d = (Sd1d-(Kd1*Sd2+S*Kd1d-temp7*Kd2)/K-temp6*Kd2)/K;
    tempd0 = temp6;
    tempd1 = (Sd2-S*Kd2/K)/K;
    temp = S/K;
    temp7 = log(temp)/totalvol;
    temp4d = (tempd1/temp-temp7*totalvold2)/totalvol;
    temp4 = temp7;
    temp7 = (tempd0/temp-temp4*totalvold1)/totalvol;
    temp1dd = ((tempd0d-tempd0*tempd1/temp)/temp-totalvold1*temp4d-temp4*
        totalvold1d-temp7*totalvold2)/totalvol;
    temp1d = temp7;
    temp1d0 = temp4d;
    temp1 = temp4;
    temp7 = (tempd/temp-temp1*totalvold0)/totalvol;
    temp4d = ((tempdd0-tempd*tempd1/temp)/temp-totalvold0*temp1d0-temp1*
        totalvold0d0-temp7*totalvold2)/totalvol;
    temp4 = temp7;
    temp7 = tempd*tempd0/temp;
    temp6 = (tempdd-temp7)/temp;
    temp8 = (temp6-totalvold0*temp1d-temp1*totalvold0d-temp4*totalvold1)/
        totalvol;
    temp0ddd = ((tempddd-(tempd0*tempdd0+tempd*tempd0d-temp7*tempd1)/temp-
        temp6*tempd1)/temp-temp1d*totalvold0d0-totalvold0*temp1dd-totalvold0d*
        temp1d0-temp1*totalvold0dd-totalvold1*temp4d-temp4*totalvold1d-temp8*
        totalvold2)/totalvol;
    temp0dd = temp8;
    temp0dd0 = temp4d;
    temp0d = temp4;
    temp0d0d = temp1dd;
    temp0d0 = temp1d;
    temp0d1 = temp1d0;
    temp0 = temp1;
    double d1 = temp0 + 0.5*totalvol;
    double d1d2 = temp0d1 + 0.5*totalvold2;
    double d1d1 = temp0d0 + 0.5*totalvold1;
    double d1d1d = temp0d0d + 0.5*totalvold1d;
    double d1d0 = temp0d + 0.5*totalvold0;
    double d1d0d0 = temp0dd0 + 0.5*totalvold0d0;
    double d1d0d = temp0dd + 0.5*totalvold0d;
    double d1d0dd = temp0ddd + 0.5*totalvold0dd;
    temp8 = (Sd-temp*Kd)/(temp*K);
    temp4d = (Sdd1-Kd*tempd1-temp*Kdd1-temp8*(K*tempd1+temp*Kd2))/(temp*K);
    temp4 = temp8;
    temp8 = K*tempd0 + temp*Kd1;
    temp7 = (Sdd0-Kd*tempd0-temp*Kdd0-temp4*temp8)/(temp*K);
    temp1dd = (Sdd0d-tempd0*Kdd1-Kd*tempd0d-Kdd0*tempd1-temp*Kdd0d-temp8*
        temp4d-temp4*(tempd0*Kd2+K*tempd0d+Kd1*tempd1+temp*Kd1d)-temp7*(K*
        tempd1+temp*Kd2))/(temp*K);
    temp1d = temp7;
    temp1d0 = temp4d;
    temp1 = temp4;
    temp8 = (temp1-temp0*totalvold)/totalvol;
    temp4d = (temp1d0-totalvold*temp0d1-temp0*totalvoldd1-temp8*totalvold2)/
        totalvol;
    temp4 = temp8;
    temp8 = (temp1d-totalvold*temp0d0-temp0*totalvoldd0-temp4*totalvold1)/
        totalvol;
    temp2dd = (temp1dd-temp0d0*totalvoldd1-totalvold*temp0d0d-totalvoldd0*
        temp0d1-temp0*totalvoldd0d-totalvold1*temp4d-temp4*totalvold1d-temp8*
        totalvold2)/totalvol;
    temp2d = temp8;
    temp2d0 = temp4d;
    temp2 = temp4;
    double d1d = temp2 + 0.5*totalvold;
    double d1dd1 = temp2d0 + 0.5*totalvoldd1;
    double d1dd0 = temp2d + 0.5*totalvoldd0;
    double d1dd0d = temp2dd + 0.5*totalvoldd0d;
    temp4d = tempd*Kd2 + K*tempdd0 + Kd0*tempd1 + temp*Kd0d0;
    temp4 = K*tempd + temp*Kd0;
    temp8 = (Sdd-Kd*tempd-temp*Kdd-temp1*temp4)/(temp*K);
    temp3d = (Sddd0-tempd*Kdd1-Kd*tempdd0-Kdd*tempd1-temp*Kddd0-temp4*temp1d0-
        temp1*temp4d-temp8*(K*tempd1+temp*Kd2))/(temp*K);
    temp3 = temp8;
    temp8 = (temp3-totalvold*temp0d-temp0*totalvoldd-temp2*totalvold0)/
        totalvol;
    temp5d = (temp3d-temp0d*totalvoldd1-totalvold*temp0dd0-totalvoldd*temp0d1-
        temp0*totalvolddd0-totalvold0*temp2d0-temp2*totalvold0d0-temp8*
        totalvold2)/totalvol;
    temp5 = temp8;
    double d1dd = temp5 + 0.5*totalvoldd;
    double d1ddd0 = temp5d + 0.5*totalvolddd0;
    temp8 = tempd*Kd1 + K*tempdd + Kd0*tempd0 + temp*Kd0d;
    temp7 = K*tempd0 + temp*Kd1;
    temp6 = (Sddd-tempd*Kdd0-Kd*tempdd-Kdd*tempd0-temp*Kddd-temp4*temp1d-temp1
        *temp8-temp3*temp7)/(temp*K);
    temp9 = (temp6-temp0d*totalvoldd0-totalvold*temp0dd-totalvoldd*temp0d0-
        temp0*totalvolddd-totalvold0*temp2d-temp2*totalvold0d-temp5*totalvold1
        )/totalvol;
    double d1ddd = temp9 + 0.5*totalvolddd;
    double d1dddd = ((Sdddd-Kdd0*tempdd0-tempd*Kdd0d-tempdd*Kdd1-Kd*tempddd-
    tempd0*Kddd0-Kdd*tempd0d-Kddd*tempd1-temp*Kdddd-temp1d*temp4d-temp4*
    temp1dd-temp8*temp1d0-temp1*(Kd1*tempdd0+tempd*Kd1d+tempdd*Kd2+K*tempddd+
    tempd0*Kd0d0+Kd0*tempd0d+Kd0d*tempd1+temp*Kd0dd)-temp7*temp3d-temp3*(
    tempd0*Kd2+K*tempd0d+Kd1*tempd1+temp*Kd1d)-temp6*(K*tempd1+temp*Kd2))/(
    temp*K)-totalvoldd0*temp0dd0-temp0d*totalvoldd0d-temp0dd*totalvoldd1-
    totalvold*temp0ddd-temp0d0*totalvolddd0-totalvoldd*temp0d0d-totalvolddd*
    temp0d1-temp0*totalvoldddd-temp2d*totalvold0d0-totalvold0*temp2dd-
    totalvold0d*temp2d0-temp2*totalvold0dd-totalvold1*temp5d-temp5*totalvold1d
    -temp9*totalvold2)/totalvol + 0.5*totalvoldddd;
    double d2 = d1 - totalvol;
    double d2d2 = d1d2 - totalvold2;
    double d2d1 = d1d1 - totalvold1;
    double d2d1d = d1d1d - totalvold1d;
    double d2d0 = d1d0 - totalvold0;
    double d2d0d0 = d1d0d0 - totalvold0d0;
    double d2d0d = d1d0d - totalvold0d;
    double d2d0dd = d1d0dd - totalvold0dd;
    double d2d = d1d - totalvold;
    double d2dd1 = d1dd1 - totalvoldd1;
    double d2dd0 = d1dd0 - totalvoldd0;
    double d2dd0d = d1dd0d - totalvoldd0d;
    double d2dd = d1dd - totalvoldd;
    double d2ddd0 = d1ddd0 - totalvolddd0;
    double d2ddd = d1ddd - totalvolddd;
    double d2dddd = d1dddd - totalvoldddd;
    result1dddd = cdf_n_d_d_d_d(d1, d1d2, d1d1, d1d1d, d1d0, d1d0d0, d1d0d, 
                                d1d0dd, d1d, d1dd1, d1dd0, d1dd0d, d1dd, 
                                d1ddd0, d1ddd, d1dddd, &result1, &result1d2, &
                                result1d1, &result1d1d, &result1d0, &
                                result1d0d0, &result1d0d, &result1d0dd, &
                                result1d, &result1dd1, &result1dd0, &
                                result1dd0d, &result1dd, &result1ddd0, &
                                result1ddd);
    result2d0d = 0.0;
    result2d0d0 = 0.0;
    result2d0 = 0.0;
    result2dd0d = 0.0;
    result2dd0 = 0.0;
    result2d0dd = 0.0;
    result2d0d = 0.0;
    result2d1d = 0.0;
    result2d1 = 0.0;
    result2ddd0 = 0.0;
    result2dd0d = 0.0;
    result2dd1 = 0.0;
    result2d0dd = 0.0;
    result2d0d0 = 0.0;
    result2d1d = 0.0;
    result2d2 = 0.0;
    result2dddd = cdf_n_d_d_d_d(d2, d2d2, d2d1, d2d1d, d2d0, d2d0d0, d2d0d, 
                                d2d0dd, d2d, d2dd1, d2dd0, d2dd0d, d2dd, 
                                d2ddd0, d2ddd, d2dddd, &result2, &result2d2, &
                                result2d1, &result2d1d, &result2d0, &
                                result2d0d0, &result2d0d, &result2d0dd, &
                                result2d, &result2dd1, &result2dd0, &
                                result2dd0d, &result2dd, &result2ddd0, &
                                result2ddd);
    *call_priceddd = result1d1*Sd0d0 + Sd0*result1d1d + Sd0d*result1d2 + 
        result1*Sd0dd + Sd1*result1d0d0 + result1d0*Sd1d + result1d0d*Sd2 + S*
        result1d0dd - result2d1*Kd0d0 - Kd0*result2d1d - Kd0d*result2d2 - 
        result2*Kd0dd - Kd1*result2d0d0 - result2d0*Kd1d - result2d0d*Kd2 - K*
        result2d0dd;
    *call_pricedd = Sd0*result1d1 + result1*Sd0d + result1d0*Sd1 + S*
        result1d0d - Kd0*result2d1 - result2*Kd0d - result2d0*Kd1 - K*
        result2d0d;
    *call_pricedd0 = Sd0*result1d2 + result1*Sd0d0 + result1d0*Sd2 + S*
        result1d0d0 - Kd0*result2d2 - result2*Kd0d0 - result2d0*Kd2 - K*
        result2d0d0;
    *call_priced = result1*Sd0 + S*result1d0 - result2*Kd0 - K*result2d0;
    *call_priced0d = Sd1*result1d2 + result1*Sd1d + result1d1*Sd2 + S*
        result1d1d - Kd1*result2d2 - result2*Kd1d - result2d1*Kd2 - K*
        result2d1d;
    *call_priced0 = result1*Sd1 + S*result1d1 - result2*Kd1 - K*result2d1;
    *call_priced1 = result1*Sd2 + S*result1d2 - result2*Kd2 - K*result2d2;
    *call_price = S*result1 - K*result2;
    *call_price_ddd = result1d1*Sdd1 + Sd*result1d1d + Sdd0*result1d2 + 
        result1*Sdd0d + Sd1*result1dd1 + result1d*Sd1d + result1dd0*Sd2 + S*
        result1dd0d - result2d1*Kdd1 - Kd*result2d1d - Kdd0*result2d2 - 
        result2*Kdd0d - Kd1*result2dd1 - result2d*Kd1d - result2dd0*Kd2 - K*
        result2dd0d;
    *call_price_dd = Sd*result1d1 + result1*Sdd0 + result1d*Sd1 + S*result1dd0
        - Kd*result2d1 - result2*Kdd0 - result2d*Kd1 - K*result2dd0;
    *call_price_dd0 = Sd*result1d2 + result1*Sdd1 + result1d*Sd2 + S*
        result1dd1 - Kd*result2d2 - result2*Kdd1 - result2d*Kd2 - K*result2dd1
    ;
    *call_price_d = result1*Sd + S*result1d - result2*Kd - K*result2d;
    *call_price_d_dd = result1d0*Sdd1 + Sd*result1d0d0 + Sdd*result1d2 + 
        result1*Sddd0 + Sd0*result1dd1 + result1d*Sd0d0 + result1dd*Sd2 + S*
        result1ddd0 - result2d0*Kdd1 - Kd*result2d0d0 - Kdd*result2d2 - 
        result2*Kddd0 - Kd0*result2dd1 - result2d*Kd0d0 - result2dd*Kd2 - K*
        result2ddd0;
    *call_price_d_d = Sd*result1d0 + result1*Sdd + result1d*Sd0 + S*result1dd 
        - Kd*result2d0 - result2*Kdd - result2d*Kd0 - K*result2dd;
    *call_price_d_d_d = result1d0*Sdd0 + Sd*result1d0d + Sdd*result1d1 + 
        result1*Sddd + Sd0*result1dd0 + result1d*Sd0d + result1dd*Sd1 + S*
        result1ddd - result2d0*Kdd0 - Kd*result2d0d - Kdd*result2d1 - result2*
        Kddd - Kd0*result2dd0 - result2d*Kd0d - result2dd*Kd1 - K*result2ddd;
    return Sdd0*result1d0d0 + result1d0*Sdd0d + result1d0d*Sdd1 + Sd*
    result1d0dd + result1d1*Sddd0 + Sdd*result1d1d + Sddd*result1d2 + result1*
    Sdddd + result1dd0*Sd0d0 + Sd0*result1dd0d + Sd0d*result1dd1 + result1d*
    Sd0dd + Sd1*result1ddd0 + result1dd*Sd1d + result1ddd*Sd2 + S*result1dddd 
    - Kdd0*result2d0d0 - result2d0*Kdd0d - result2d0d*Kdd1 - Kd*result2d0dd - 
    result2d1*Kddd0 - Kdd*result2d1d - Kddd*result2d2 - result2*Kdddd - 
    result2dd0*Kd0d0 - Kd0*result2dd0d - Kd0d*result2dd1 - result2d*Kd0dd - 
    Kd1*result2ddd0 - result2dd*Kd1d - result2ddd*Kd2 - K*result2dddd;
}
