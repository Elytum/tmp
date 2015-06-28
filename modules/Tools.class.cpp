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
Tools::Tools( void ) : MonitorModule(14, 5, "Uptime")
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
	win.print(posX, posY, s);
	win.print(posX + strlen(s), posY, index);
	width = height = 0;
}

void	Tools::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	char		buffer[30];
	struct tm *dt;
	(void)height;

	dt = localtime(&btime.tv_sec);

	strftime(buffer, sizeof(buffer), "%H:%M:%S %d/%m/%Y", dt);
	//printType(posX, posY, width, height, win, "Uptime: ", buffer);

	char		time1[9];
    char		date1[11];

    time1[0] = buffer[0];
    time1[1] = buffer[1];
    time1[2] = buffer[2];
    time1[3] = buffer[3];
    time1[4] = buffer[4];
    time1[5] = buffer[5];
    time1[6] = buffer[6];
    time1[7] = buffer[7];
    time1[8] = '\0';

    date1[0] = buffer[9];
    date1[1] = buffer[10];
    date1[2] = buffer[11];
    date1[3] = buffer[12];
    date1[4] = buffer[13];
    date1[5] = buffer[14];
    date1[6] = buffer[15];
    date1[7] = buffer[16];
    date1[8] = buffer[17];
    date1[9] = buffer[18];
    date1[10] = '\0';

    win.print(posX + (width - strlen(date1)) / 2, posY, date1);
	win.print(posX + (width - strlen(time1)) / 2, posY + 1, time1);
	//posY++;
}

Tools::~Tools( void )
{
}
