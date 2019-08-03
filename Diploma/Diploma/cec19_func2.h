#pragma once
class cec19_func2
{
private:
#define INF 1.0e99
#define EPS 1.0e-14
#define E  2.7182818284590452353602874713526625
#define PI 3.1415926535897932384626433832795029

	double *OShift, *M, *y, *z, *x_bound;
	int ini_flag = 0, n_flag, func_flag, *SS;
	void Lennard_Jones(double *, int, double *); /* Lennard Jones */
	void Hilbert(double *, int, double *); /* Hilbert */
	void Chebyshev(double *, int, double *); /* Chebyshev */
	void schaffer_F7_func(double *, double *, int, double *, double *, int, int); /* Schwefel's F7 */
	void ackley_func(double *, double *, int, double *, double *, int, int); /* Ackley's */
	void rastrigin_func(double *, double *, int, double *, double *, int, int); /* Rastrigin's  */
	void weierstrass_func(double *, double *, int, double *, double *, int, int); /* Weierstrass's  */
	void schwefel_func(double *, double *, int, double *, double *, int, int); /* Schwefel's */
	void escaffer6_func(double *, double *, int, double *, double *, int, int); /* Expanded Scaffer¡¯s F6  */
	void happycat_func(double *, double *, int, double *, double *, int, int); /* HappyCat */
	void griewank_func(double *, double *, int, double *, double *, int, int); /* Griewank's  */

	void shiftfunc(double*, double*, int, double*);
	void rotatefunc(double*, double*, int, double*);
	void sr_func(double *, double *, int, double*, double*, double, int, int); /* shift and rotate */
	void asyfunc(double *, double *x, int, double);
	void oszfunc(double *, double *, int);

	
public:
	void cec19_test_func(double *, double *, int, int, int);
};

