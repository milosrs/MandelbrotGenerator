#include "Bmp.h"

Bitmap::Bitmap(uint32_t width, uint32_t height, uint8_t channels) : width(width), height(height), channels(channels), data(new uint8_t[width * height * 3])
{
}

bool Bitmap::write(std::string filename)
{
	BitmapHeader header;
	BitmapInfoHeader info;
	RBGQUAD rbgquad;
	uint32_t offset = sizeof(BitmapHeader) + sizeof(BitmapInfoHeader) + sizeof(RBGQUAD);
	std::ofstream file;

	header.fileSize = offset + width * height * 3;
	header.dataOffset = offset;
	info.width = width;
	info.height = height;
	file.open(filename, std::ios::out | std::ios::binary);

	if (!file) {
		throw std::exception("Cant create file");
	}

	file.write((char*)&header, sizeof(header));
	file.write((char*)&info, sizeof(info));
	file.write((char*)&rbgquad, sizeof(RBGQUAD));
	file.write((char*)data.get(), width * height * 3);
	file.close();

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
	uint8_t* pixels = data.get();

	pixels += (y * 3) * width + (x * 3);
	pixels[0] = b;
	pixels[1] = g;
	pixels[2] = r;
}

Bitmap::~Bitmap()
{
}
