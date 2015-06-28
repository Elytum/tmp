#ifndef MODULEROW_HPP
# define MODULEROW_HPP

#include <MonitorModule.hpp>
#include <Config.hpp>

#include <iostream>
#include <Vector>

class ModuleRow
{
public:
	ModuleRow( void );
	~ModuleRow( void );
	void								addModule( MonitorModule * mod );
	const std::vector<MonitorModule *>	getModules( void ) const;
	int									getWidth( void ) const;
	MonitorModule&						operator[]( int pos );
	void								draw( int x, int y, Window const & win );
private:
	int								width;
	std::vector<MonitorModule *>	modules;
};

#include <Window.hpp>

#endif
