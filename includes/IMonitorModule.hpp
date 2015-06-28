#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

#include <iostream>

class IMonitorModule
{
public:
	virtual	~IMonitorModule( void ) {}
	virtual void					setHeight( int height ) = 0;
	virtual int						getHeight( void ) const = 0;
	virtual void					setWidth( int width ) = 0;
	virtual int						getWidth( void ) const = 0;
	virtual const std::string		getTitle( void ) const = 0;
};

#endif