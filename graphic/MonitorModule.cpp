#include <MonitorModule.hpp>
#include <Window.hpp>
#include <string.h>

MonitorModule::MonitorModule( void ) : _height(DEFAULT_HEIGHT), _title("")	{
}

MonitorModule::MonitorModule( int width, int height ) : _width(width), _height(height), _title("")	{
}

MonitorModule::MonitorModule( std::string title ) : _height(DEFAULT_HEIGHT), _title(title)	{
}

MonitorModule::MonitorModule( int width, int height, std::string title ) : _width(width), _height(height), _title(title)	{
}

MonitorModule::MonitorModule( MonitorModule const & cpy ) : _title(cpy._title) {
	*this = cpy;
}

MonitorModule::~MonitorModule( void ) {
}

void	MonitorModule::setHeight( int height ) {
	_height = height;
}

int		MonitorModule::getHeight( void ) const {
	return _height;
}

void				MonitorModule::setWidth( int width ) {
	_width = width;
}

int					MonitorModule::getWidth( void ) const {
	return _width;
}


const std::string MonitorModule::getTitle( void ) const {
	return _title;
}

MonitorModule&		MonitorModule::operator=(MonitorModule const & cpy) {
	_height = cpy.getHeight();
	return *this;
}

void		MonitorModule::draw( int posX, int posY, int width, Window const & win ) {
	const int	bufSize = 1024;
	static char	tmp[bufSize];

	win.printBox(posX, posY, width, _height);

	if (_title.size()) {
		win.printHLine(posX, posY + 2, width);
		int diff = width - 2 - _title.size();
		if (diff > 0) {
			win.print(posX + 1 + diff / 2, posY + 1, _title.c_str(), RED);
			drawContent(posX + 1, posY + 3, width - 1, _height - 3, win);
		}
		else if (diff == 0) {
			win.print(posX + 1, posY + 1, _title.c_str(), RED);
			drawContent(posX + 1, posY + 3, width - 1, _height - 3, win);
		}
		else if (bufSize >= 2 && width - 2 < bufSize) {
				memcpy(tmp, _title.c_str(), bufSize);
				tmp[width - 2] = '.';
				tmp[width - 1] = '\0';
				win.print(posX + 1, posY + 1, tmp, RED);
				drawContent(posX + 1, posY + 1, width - 1, _height - 3, win);
		}
	}
	else
		drawContent(posX + 1, posY + 1, width - 1, _height - 1, win);
}
