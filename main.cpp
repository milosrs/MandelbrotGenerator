#include <iostream>
#include <cstdint>
#include <memory>
#include "ImageData/Bmp.h"
#include "Mandelbrot/Mandelbrot.h"

void redBmp(Bitmap&, uint32_t, uint32_t);
void mandelbrotImage(Bitmap&, uint32_t, uint32_t);

int main(int argc, char** argv) {
	const uint32_t width = 1024;
	const uint32_t height = 860;
	Bitmap mandelbrot(width, height, 3);

	mandelbrotImage(mandelbrot, width, height);
	mandelbrot.write("RixonbrotHistogram.bmp");

	std::cout << "Size of Bitmap Header: " << sizeof(BitmapHeader) << std::endl;;
	std::cout << "Size of Bitmap Info Header: " << sizeof(BitmapInfoHeader) << std::endl;;
	std::cout << "Size of RBGQUAD: " << sizeof(RBGQUAD) << std::endl;;
	return 0;
}

void redBmp(Bitmap& bmp, uint32_t width, uint32_t height) {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			bmp.setPixel(x, y, 255, 0, 0);
		}
	}
}

void mandelbrotImage(Bitmap& bmp, uint32_t width, uint32_t height) {
	double min = 999999;
	double max = -999999;
	int total = 0;
	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 });
	std::unique_ptr<int[]> iterations(new int[width * height]{ 0 });

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			double xFrac = (x - (double)width / 2 - 200) * 2.0 / height;
			double yFrac = (y - (double)height / 2) * 2.0 / height;
			int i = Mandelbrot::getIterations(xFrac, yFrac);

			iterations[y * width + x] = i;
			
			if (i != Mandelbrot::MAX_ITERATIONS) {
				histogram[i]++;
			}			
		}

		if (y % 100 == 0) {
			std::cout << "Row " << y << " of " << height << std::endl;
		}
	}

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
		total += histogram[i];
	}

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			int i = iterations[y * width + x];
			double hue = 0.0;
			uint32_t r = 0, g = 0, b = 0;

			for (int iter = 0; iter <= i; ++iter) {
				hue += ((double)histogram[iter]) / total;
			}

			g = hue * 255;

			bmp.setPixel(x, y, r, g, b);

			if (r < min) min = r;
			if (r > max) max = r;
		}
	}

	std::cout << std::endl;
}

void validateHistogram(int* histogram, double min, double max) {
	for (int h = 0; h < Mandelbrot::MAX_ITERATIONS; ++h) {
		std::cout << histogram[h] << (h == Mandelbrot::MAX_ITERATIONS - 1 ? ", " : " ") << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "MIN: " << min << ", MAX: " << max << std::endl;
}