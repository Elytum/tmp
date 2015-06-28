#define WIDTH 27
#define HEIGHT 11

#define FRAME0 \
"bbbbbbbbbbbwwbwwbbbbbbbbbbbb" \
"bbbbbbbbbbbbbwbbbbbbbbbbbbww" \
"bbbbbbb             bbbbbbbb" \
"rrrbbb wwwwwwwwwww   bbb   b" \
"yyyrrr wmmrmmmrmmmw        b" \
"gggyyy wmmmmmrmmmmw  w  w  b" \
"cccggg wwwwwwwwwwww m    m b" \
"bbbccc                    bb" \
"bbbbbb  bb bbbbbbb  bb  bbbw" \
"bbbbbwbbbbbbbbbbbwbbbbbbbbbb"

#define FRAME1 \
"bbbbbbbbbbbbbwbbbbbbbbbbbbbb" \
"wbbbbbbbbbbbbbbbbbbbbbbbbbwb" \
"bbbbbbb              bbb   b" \
"bbbbbb wwwwwwwwwww         b" \
"rrrrrr wmmrmmmrmmmw  w  w  b" \
"yyyyyy wmmmmmrmmmmw m    m b" \
"gggggg wwwwwwwwwwww       bb" \
"cccccc                   bbb" \
"bbbbbbb  bb bbbbbbb  bb  bbb" \
"bbbbbbbbbbbbbbwbbbbbbbbbbbbb"

#define FRAME2 \
"bbbbbbbbbbbbbbbbbbbbbbbbbbbb" \
"bbbbbbbbbbbbbbbbbbbbbbbbbbbb" \
"bbbbbbb             bbbbbbbb" \
"bbbbbb wwwwwwwwwww   bbb   b" \
"bbbrrr wmmrmmmrmmmw        b" \
"rrryyy wmmmmmrmmmmw  w  w  b" \
"yyyggg wwwwwwwwwwww m    m b" \
"gggccc                    bb" \
"ccwbb  bb bbbbbbb  bb  bbbbb" \
"bbbbbbbbbbbbbbbbbbbbbbbbbbbb"

#include <math.h>

#include <NyanCatModule.hpp>

NyanCatModule::NyanCatModule( void ) : MonitorModule(WIDTH + 2, HEIGHT + 2, "NyanCatModule") {
}

NyanCatModule::NyanCatModule( std::string name ) : MonitorModule(WIDTH + 2, HEIGHT + 2, name) {
}

NyanCatModule::NyanCatModule( NyanCatModule const & cpy ) : MonitorModule(WIDTH + 2, HEIGHT + 2, "NyanCatModule") {
	(void)cpy;
}

NyanCatModule::~NyanCatModule( void ) {
}
	
void	NyanCatModule::drawContent( int posX, int posY, int width, int height, Window const & win ) {
	static int frame = 0;
	static int tick = 200000;

	int pos = 0;
	int i = 0;

	for (int y = 0; (y < height && y <= HEIGHT); ++y) {
		i = pos;
		for (int x = 0; (x < width && x <= WIDTH); ++x) {
			if (frame == 0) {
				win.print(posX + x, posY + y, ' ', FRAME0[i]);
				if (--tick == 0) {
					tick = 200000;
					frame = 1;
				}
			}
			else if (frame == 1) {
				win.print(posX + x, posY + y, ' ', FRAME1[i]);
				if (--tick == 0) {
					tick = 200000;
					frame = 2;
				}
			}
			else if (frame == 2) {
				win.print(posX + x, posY + y, ' ', FRAME2[i]);
				if (--tick == 0) {
					tick = 200000;
					frame = 0;
				}
			}
			++i;
		}
		pos += width;
	}
}
