#ifndef NYANCATMODULE_HPP
# define NYANCATMODULE_HPP

#include <MonitorModule.hpp>

class NyanCatModule : public MonitorModule
{
public:
	NyanCatModule( void );
	NyanCatModule( std::string name );
	NyanCatModule( NyanCatModule const & cpy );
	virtual	~NyanCatModule( void );
	
	virtual void	drawContent( int posX, int posY, int width, int height, Window const & win );

};

#endif