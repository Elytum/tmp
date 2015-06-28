// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hmoutaou <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/28 00:51:18 by hmoutaou          #+#    #+#             //
/*   Updated: 2015/06/28 03:19:52 by bwanlin          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "TimeModule.hpp"

#define REQUIRED_WIDTH 22
#define REQUIRED_HEIGHT 5

TimeModule::TimeModule( void ): MonitorModule(REQUIRED_WIDTH, REQUIRED_HEIGHT, "Time & Date") {

}

TimeModule::TimeModule( TimeModule const& rhs )
{
	*this = rhs;
}

TimeModule::~TimeModule( void ) {}

TimeModule &	TimeModule::operator=( TimeModule const& )
{
	return (*this);
}

void		TimeModule::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	if (width < REQUIRED_WIDTH - 3 || height < REQUIRED_HEIGHT - 3)
	{
		return ;
	}

	std::time_t t = std::time(0); 

    struct tm * dt;
    char buffer [30];
    dt = localtime(&t);
    strftime(buffer, sizeof(buffer), "%H:%M:%S %d/%m/%Y", dt);

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
}
