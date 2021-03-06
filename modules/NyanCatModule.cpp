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

NyanCatModule::NyanCatModule( void ) : MonitorModule(WIDTH + 2, HEIGHT + 2, "Nyan Cat") {
}

NyanCatModule::NyanCatModule( std::string name ) : MonitorModule(WIDTH + 2, HEIGHT + 2, name) {
}

NyanCatModule::NyanCatModule( NyanCatModule const & cpy ) : MonitorModule(WIDTH + 2, HEIGHT + 2, "Nyan Cat") {
	(void)cpy;
}

#define TICK_NB 1250

NyanCatModule::~NyanCatModule( void ) {
}
	
void	NyanCatModule::drawContent( int posX, int posY, int width, int height, Window const & win ) {
	static int frame = 0;
	static int tick = TICK_NB;

	int pos = 0;
	int i = 0;

	for (int y = 0; (y < height); ++y) {
		for (int x = 0; (x < width); ++x) {
			win.print(posX + x, posY + y, ' ', 'b');
		}
	}
	posX += (width - WIDTH) / 2;
	for (int y = 0; (y < height && y <= HEIGHT); ++y) {
		i = pos;
		for (int x = 0; (x < width && x <= WIDTH); ++x) {
			if (frame == 0) {
				if (FRAME0[i] != 'b')
					win.print(posX + x, posY + y, ' ', FRAME0[i]);
				if (--tick == 0) {
					tick = TICK_NB;
					frame = 1;
				}
			}
			else if (frame == 1) {
				if (FRAME1[i] != 'b')
					win.print(posX + x, posY + y, ' ', FRAME1[i]);
				if (--tick == 0) {
					tick = TICK_NB;
					frame = 2;
				}
			}
			else if (frame == 2) {
				if (FRAME2[i] != 'b')
					win.print(posX + x, posY + y, ' ', FRAME2[i]);
				if (--tick == 0) {
					tick = TICK_NB;
					frame = 0;
				}
			}
			++i;
		}
		pos += WIDTH + 1;
	}
}
