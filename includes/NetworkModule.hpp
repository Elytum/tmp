#ifndef NETWORK_MODULE_HPP
# define NETWORK_MODULE_HPP

# include <string>
# include <iostream>
# include "MonitorModule.hpp"
# include <sstream>
# include <cstdio>


typedef std::string string;
typedef unsigned int uint;


class	NetworkModule:public MonitorModule
{
public:
	NetworkModule( void );
	NetworkModule( string name );
	NetworkModule( NetworkModule const& rhs );
	~NetworkModule( void );

	NetworkModule &	operator=( NetworkModule const& rhs );
	string			offsetStr(string str) const;
	
	// virtual void	draw( int x, int y, int w, Window const& ) const;
	virtual void	drawContent( int posX, int posY, int width, int height, Window const & win );
private:

};

#endif
