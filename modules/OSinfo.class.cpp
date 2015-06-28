/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSinfo.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:20:35 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 15:25:03 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSinfo.class.hpp"
#include <string>
OSinfo::OSinfo( void ) : MonitorModule(45, 7, "OS informations")
{
	updateInfo();
}

void	OSinfo::printInfo( void ) const
{
	std::cout << ".Retrieving Data from OSinfo" << std::endl;
	std::cout << "hw.model: " << _info.model << std::endl;
	std::cout << "hw.machine: " << _info.machine << std::endl;
	std::cout << "hw.ostype: " << _info.ostype << std::endl;
	std::cout << "hw.osrelease: " << _info.osrelease << std::endl;
}

void OSinfo::updateInfo( void )
{
	
	size_t	model = sizeof(_info.model);
	size_t	machine = sizeof(_info.machine);
	size_t	ostype = sizeof(_info.ostype);
	size_t	osrelease = sizeof(_info.osrelease);

	sysctlbyname("hw.model", &_info.model, &model, NULL, 0);
	sysctlbyname("hw.machine", &_info.machine, &machine, NULL, 0);
	sysctlbyname("kern.ostype", &_info.ostype, &ostype, NULL, 0);
	sysctlbyname("kern.osrelease", &_info.osrelease, &osrelease, NULL, 0);	
}

template< typename T >
void	printType( int posX, int posY, int width, int height, Window const &win, char const *s, T index)
{
	win.print(posX + 1, posY, s);
	win.print(posX + 1 + strlen(s), posY, index);
	width = height = 0;
}

void	OSinfo::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	printType(posX, posY, width, height, win, "Model: ", _info.model);
	posY++;	
	printType(posX, posY, width, height, win, "Machine: ", _info.machine);
	posY++;
	printType(posX, posY, width, height, win, "OStype: ", _info.ostype);
	posY++;	
	printType(posX, posY, width, height, win, "OSrelease: ", _info.osrelease);
	posY++;
}

OSinfo::~OSinfo( void )
{
}
