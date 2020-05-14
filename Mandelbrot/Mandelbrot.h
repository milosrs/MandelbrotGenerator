#pragma once
#include <complex>
#include <cstdio>

class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 1000;

	static int getIterations(double x, double y) {
		std::complex<double> z0 = 0;
		std::complex<double> zn(x, y);
		int i = 0;

		while (i < MAX_ITERATIONS) {
			z0 = z0 * z0 + zn;

			if (abs(z0) > 2) {
				break;
			}

			++i;
		}

		return i;
	};
};