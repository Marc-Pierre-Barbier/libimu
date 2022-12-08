#include "imu_math.h"

////////////////////////////////////////////

#if defined(WIN32) || defined(__unix__)
//most x86 cpus contains dedicated hardware to compute square root
//which is faster and more precise than the fast inverse square root hack
#include <math.h>

float imu_math_fast_inv_sqrt(float n) {
	return 1 / sqrt(n);
}

#else

float imu_math_fast_inv_sqrt(float n)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = n * 0.5F;
	y  = n;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration

	return y;
}
#endif

////////////////////////////////////////////


float imu_math_map_value(float value, float min, float max, float mapped_min, float mapped_max)
{
	return mapped_min + (value - min) * (mapped_max - mapped_min) / (max - min);
}


////////////////////////////////////////////
