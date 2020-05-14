#pragma once
#pragma pack(2)
struct BitmapHeader {
	char header[2]{ 'B', 'M' };
	int32_t fileSize;
	int16_t reserved1{ 0 };
	int16_t reserved2{ 0 };
	int32_t dataOffset;
};

struct BitmapInfoHeader {
	int32_t headerSize{ 40 };
	int32_t width;
	int32_t height;
	int16_t planes{ 1 };
	int16_t bitsPerPixel{ 24 };
	int32_t compression{ 0 };
	int32_t dataSize{ 0 };
	int32_t horizontalResolution{ 2400 };
	int32_t verticalResolution{ 2400 };
	int32_t colors{ 0 };
	int32_t importantColors{ 0 };
};

struct RBGQUAD {
	char a;
	char b;
	char c;
	char d;
};

struct Pixel {
    uint8_t r{ 0 }, g{ 0 }, b{ 0 };
    uint32_t x{ 0 }, y{ 0 };
};