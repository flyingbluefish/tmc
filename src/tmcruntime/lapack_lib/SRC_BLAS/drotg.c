#include "blaswrap.h"
#include "f2c.h"

/* Subroutine */ int drotg_(doublereal *da, doublereal *db, doublereal *c__, 
	doublereal *s)
{
    /* Table of constant values */
    static doublereal c_b4 = 1.;
    
    /* System generated locals */
    doublereal d__1, d__2;
    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);
    /* Local variables */
    static doublereal r__, z__, roe, scale;
/*  Purpose   
    =======   
       construct givens plane rotation.   
       jack dongarra, linpack, 3/11/78. */
    roe = *db;
    if (abs(*da) > abs(*db)) {
	roe = *da;
    }
    scale = abs(*da) + abs(*db);
    if (scale != 0.) {
	goto L10;
    }
    *c__ = 1.;
    *s = 0.;
    r__ = 0.;
    z__ = 0.;
    goto L20;
L10:
/* Computing 2nd power */
    d__1 = *da / scale;
/* Computing 2nd power */
    d__2 = *db / scale;
    r__ = scale * sqrt(d__1 * d__1 + d__2 * d__2);
    r__ = d_sign(&c_b4, &roe) * r__;
    *c__ = *da / r__;
    *s = *db / r__;
    z__ = 1.;
    if (abs(*da) > abs(*db)) {
	z__ = *s;
    }
    if (abs(*db) >= abs(*da) && *c__ != 0.) {
	z__ = 1. / *c__;
    }
L20:
    *da = r__;
    *db = z__;
    return 0;
} /* drotg_ */


