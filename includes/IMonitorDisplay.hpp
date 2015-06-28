#ifndef IMONITOR_DISPLAY_HPP
# define IMONITOR_DISPLAY_HPP

# include <ModuleRow.hpp>
# include <MonitorModule.hpp>

enum colorsKind {
	BLACK = 1,
	RED = 1,
	GREEN = 2,
	BLUE = 3,
	YELLOW = 4,
	WHITE = 5,
	MAGENTA = 6,
	CYAN = 7,
	REVERSE_RED = 8,
	REVERSE_GREEN = 9,
	REVERSE_BLUE = 10,
	REVERSE_YELLOW = 11,
	REVERSE_WHITE = 12,
	REVERSE_MAGENTA = 13,
	REVERSE_CYAN = 14,
	ORANGE = 15,
	REVERSE_ORANGE = 16,
	VIOLET = 17,
	REVERSE_VIOLET = 18,
	GREY = 19,
	REVERSE_GREY = 20, 
};

class ModuleRow;

class IMonitorDisplay
{

public:
	virtual	~IMonitorDisplay( void ) {}

	virtual int			getSeenWidth() const = 0;
	virtual int			getSeenHeight() const = 0;
	virtual void		open( void ) = 0;
	virtual void		close( void ) = 0;
	virtual void		clr( void ) const = 0;
	virtual void		print( int x, int y, char const *c ) const = 0;
	virtual void		print( int x, int y, char const c ) const = 0;
	virtual void		print( int x, int y, char const *c, char const color ) const = 0;
	virtual void		print( int x, int y, char const c, char const color ) const = 0;
	virtual void		doPrint( int x, int y, char const *c, colorsKind color ) const = 0;
	virtual void		printBox(int x, int y, int w, int h) const = 0;
	virtual void		printHLine(int x, int y, int w) const = 0;
	virtual void		flush( void ) = 0;
	virtual void		addModule( MonitorModule * module, int row ) = 0;
	virtual void		refresh( void ) = 0;
};

#endif
