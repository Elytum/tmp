/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:31:37 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 16:20:19 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tools.class.hpp"
#include <string>
Tools::Tools( void ) : MonitorModule(45, 4, "Useful informations")
{
	updateInfo();
}

void Tools::updateInfo( void )
{
	size_t len = sizeof(btime);
	
	int mib[2] = { CTL_KERN, KERN_BOOTTIME };
	sysctl(mib, 2, &btime, &len, NULL, 0);
}

	template< typename T >
void	printType( int posX, int posY, int width, int height, Window const &win, char const *s, T index)
{
	win.print(posX + 1, posY, s);
	win.print(posX + 1 + strlen(s), posY, index);
	width = height = 0;
}

void	Tools::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	printType(posX, posY, width, height, win, "Uptime: ", std::to_string(btime.tv_sec).c_str());
	posY++;	
}

Tools::~Tools( void )
{
}
