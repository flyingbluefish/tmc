#include "blaswrap.h"
#include "f2c.h"

doublereal dsdot_(integer *n, real *sx, integer *incx, real *sy, integer *
	incy)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal ret_val;
    /* Local variables */
    static integer i__, ns, kx, ky;
/*  AUTHORS   
    =======   
    Lawson, C. L., (JPL), Hanson, R. J., (SNLA),   
    Kincaid, D. R., (U. of Texas), Krogh, F. T., (JPL)   
    Purpose   
    =======   
    Compute the inner product of two vectors with extended   
    precision accumulation and result.   
    Returns D.P. dot product accumulated in D.P., for S.P. SX and SY   
    DSDOT = sum for I = 0 to N-1 of  SX(LX+I*INCX) * SY(LY+I*INCY),   
    where LX = 1 if INCX .GE. 0, else LX = 1+(1-N)*INCX, and LY is   
    defined in a similar way using INCY.   
    Arguments   
    =========   
    N      (input) INTEGER   
           number of elements in input vector(s)   
    SX     (input) REAL array, dimension(N)   
           single precision vector with N elements   
    INCX   (input) INTEGER   
            storage spacing between elements of SX   
    SY     (input) REAL array, dimension(N)   
           single precision vector with N elements   
    INCY   (input) INTEGER   
           storage spacing between elements of SY   
    DSDOT  (output) DOUBLE PRECISION   
           DSDOT  double precision dot product (zero if N.LE.0)   
    REFERENCES   
    ==========   
    C. L. Lawson, R. J. Hanson, D. R. Kincaid and F. T.   
    Krogh, Basic linear algebra subprograms for Fortran   
    usage, Algorithm No. 539, Transactions on Mathematical   
    Software 5, 3 (September 1979), pp. 308-323.   
    REVISION HISTORY  (YYMMDD)   
    ==========================   
    791001  DATE WRITTEN   
    890831  Modified array declarations.  (WRB)   
    890831  REVISION DATE from Version 3.2   
    891214  Prologue converted to Version 4.0 format.  (BAB)   
    920310  Corrected definition of LX in DESCRIPTION.  (WRB)   
    920501  Reformatted the REFERENCES section.  (WRB)   
    070118  Reformat to LAPACK style (JL)   
    =====================================================================   
       Parameter adjustments */
    --sy;
    --sx;
    /* Function Body */
    ret_val = 0.;
    if (*n <= 0) {
	return ret_val;
    }
    if (*incx == *incy && *incx > 0) {
	goto L20;
    }
/*     Code for unequal or nonpositive increments. */
    kx = 1;
    ky = 1;
    if (*incx < 0) {
	kx = (1 - *n) * *incx + 1;
    }
    if (*incy < 0) {
	ky = (1 - *n) * *incy + 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ret_val += (doublereal) sx[kx] * (doublereal) sy[ky];
	kx += *incx;
	ky += *incy;
/* L10: */
    }
    return ret_val;
/*     Code for equal, positive, non-unit increments. */
L20:
    ns = *n * *incx;
    i__1 = ns;
    i__2 = *incx;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	ret_val += (doublereal) sx[i__] * (doublereal) sy[i__];
/* L30: */
    }
    return ret_val;
} /* dsdot_ */

