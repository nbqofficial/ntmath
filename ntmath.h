#pragma once

/*

		LIBRARY FOR DOING BASIC MATH IN KERNEL
		MADE BY NBQ
*/


unsigned int _fltused = 1; // for using floats in kernel

#define X_PI 3.14159f 
#define X_DIV 57.29577f  // value of 180/PI
#define qabs(x) ((x) < 0 ? -(x) : (x))
#define qmax(a, b) (((a) > (b)) ? (a) : (b))
#define qmin(a, b) (((a) < (b)) ? (a) : (b))

float qsqrt(float x)
{
	union
	{
		int i;
		float f;
	} u;

	u.f = x;
	u.i = (1 << 29) + (u.i >> 1) - (1 << 22);

	u.f = u.f + x / u.f;
	u.f = 0.25f * u.f + x / u.f;

	return u.f;
}
float qatan2(float y, float x)
{
	float t0, t1, t3, t4;
	t3 = qabs(x);
	t1 = qabs(y);
	t0 = qmax(t3, t1);
	t1 = qmin(t3, t1);
	t3 = 1 / t0;
	t3 = t1 * t3;

	t4 = t3 * t3;
	t0 = -0.0134804f;
	t0 = t0 * t4 + 0.05747f;
	t0 = t0 * t4 - 0.12123f;
	t0 = t0 * t4 + 0.19563f;
	t0 = t0 * t4 - 0.33299f;
	t0 = t0 * t4 + 0.99999f;
	t3 = t0 * t3;

	t3 = (qabs(y) > qabs(x)) ? 1.57079f - t3 : t3;
	t3 = (x < 0) ? X_PI - t3 : t3;
	t3 = (y < 0) ? -t3 : t3;

	return t3;
}
float qatan(float x)
{
	return qatan2(x, 1);
}
float qacos(float x)
{
	int negate = (x < 0);
	x = qabs(x);
	float ret = -0.01872f;
	ret = ret * x;
	ret = ret + 0.07426f;
	ret = ret * x;
	ret = ret - 0.21211f;
	ret = ret * x;
	ret = ret + 1.57072f;
	ret = ret * qsqrt(1.0f - x);
	ret = ret - 2 * negate * ret;
	return negate * X_PI + ret;
}