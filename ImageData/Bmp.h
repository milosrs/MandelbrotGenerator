#pragma once

#include <memory>
#include <string>
#include <fstream>

#include "ImageData.h"

class Bitmap {
private:
	uint32_t width{ 0 };
	uint32_t height{ 0 };
	uint32_t channels{ 0 };
	std::unique_ptr<Pixel[]> pixel{ nullptr };
	std::unique_ptr<uint8_t[]> data{ nullptr };
public:
	Bitmap(uint32_t, uint32_t, uint8_t);
	bool write(std::string filename);
	void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
	virtual ~Bitmap();
};