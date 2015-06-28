#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <iostream>
# include <list>
# include <vector>
# include <sys/ioctl.h>
# include <unistd.h>
# include <ncurses.h>

# include <ModuleRow.hpp>
# include <MonitorModule.hpp>
# include <IMonitorDisplay.hpp>
# include <Config.hpp>

# define COLOR_ORANGE 101
# define COLOR_VIOLET 102
# define COLOR_GREY   103

class Window : public IMonitorDisplay
{
public:
	Window();
	virtual ~Window();

	virtual int			getSeenWidth() const;
	virtual int			getSeenHeight() const;
	virtual void		open( void );
	virtual void		close( void );
	virtual void		clr( void ) const;
	virtual void		print( int x, int y, char const *c ) const;
	virtual void		print( int x, int y, char const c ) const;
	virtual void		print( int x, int y, char const *c, char const color ) const;
	virtual void		print( int x, int y, char const c, char const color ) const;
	virtual void		doPrint( int x, int y, char const *c, colorsKind color ) const;
	virtual void		printBox(int x, int y, int w, int h) const;
	virtual void		printHLine(int x, int y, int w) const;
	virtual void		flush( void );
	virtual void		addModule( MonitorModule * module, int row );
	virtual void		refresh( void );
	WINDOW*				getWindow( void ) const;

private:
	bool						opened;
	std::vector<ModuleRow>		modules;

	WINDOW		*window_white;
	WINDOW		*main_window;
	int			height;
	int			width;
	
};

#endif