#include "f2c.h"
#ifdef __cplusplus
extern "C" {
#endif

#ifdef KR_headers
double f__cabs();
double z_abs(z) doublecomplex *z;
#else
doublereal f__cabs(doublereal, doublereal);
doublereal z_abs(doublecomplex *z)
#endif
{
return( f__cabs( z->r, z->i ) );
}
#ifdef __cplusplus
}
#endif
