#ifndef FOOBAR_HPP
# define FOOBAR_HPP

#include <MonitorModule.hpp>

class FooBar : public MonitorModule
{
public:
	FooBar( void );
	FooBar( std::string name );
	FooBar( FooBar const & cpy );
	virtual	~FooBar( void );
	
	virtual void	drawContent( int posX, int posY, int width, int height, Window const & win );

};

#endif