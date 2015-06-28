#include <math.h>

#include <FooBar.hpp>

FooBar::FooBar( void ) : MonitorModule(45, 10, "FooBar") {
}

FooBar::FooBar( std::string name ) : MonitorModule(45, 10, name) {
}

FooBar::FooBar( FooBar const & cpy ) : MonitorModule(45, 10, "FooBar") {
	(void)cpy;
}

FooBar::~FooBar( void ) {
}
	
void	FooBar::drawContent( int posX, int posY, int width, int height, Window const & win ) {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			win.print(posX + x, posY + y, (std::to_string(rand() % 2)).c_str());
		}
	}
}
