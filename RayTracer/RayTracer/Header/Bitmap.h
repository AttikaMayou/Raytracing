#pragma once

#include <fstream>

struct Bitmap
{
	// http://tfc.duke.free.fr/coding/tga_specs.pdf
#pragma pack(push, 1)
	struct TGAHeader
	{
		uint8_t  identsize;          // size of ID field that follows 18 byte header (0 usually)
		uint8_t  colourmaptype;      // type of colour map 0=none, 1=has palette
		uint8_t  imagetype;          // type of image 0=none,1=indexed,2=rgb,3=grey,+8=rle packed

		uint16_t colourmapstart;     // first colour map entry in palette
		uint16_t colourmaplength;    // number of colours in palette
		uint8_t  colourmapbits;      // number of bits per palette entry 15,16,24,32

		uint16_t xstart;             // image x origin
		uint16_t ystart;             // image y origin
		uint16_t width;              // image width in pixels
		uint16_t height;             // image height in pixels
		uint8_t  bits;               // image bits per pixel 8,16,24,32
		uint8_t  descriptor;         // image descriptor bits (vh flip bits)
	};
#pragma pack(pop)

	std::ofstream file;

	Bitmap();
	~Bitmap();
	void SetHeader(const int width, const int height);
	void OutputColor(const int ir, const int ig, const int ib);
};