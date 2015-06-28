// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NameModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hmoutaou <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/28 03:58:10 by hmoutaou          #+#    #+#             //
//   Updated: 2015/06/28 03:58:10 by hmoutaou         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NameModule.hpp"

#define REQUIRED_WIDTH 28
#define REQUIRED_HEIGHT 5

NameModule::NameModule( void ): MonitorModule(REQUIRED_WIDTH, REQUIRED_HEIGHT, "HostName & UserName") {

}

NameModule::NameModule( NameModule const& rhs )
{
	*this = rhs;
}

NameModule::~NameModule( void ) {}

NameModule &	NameModule::operator=( NameModule const& )
{
	return (*this);
}

void		NameModule::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	std::string		hostname;
	std::string		username;

	char	rawHostName[150];
	char	rawUserName[150];
	int		i = 0;

	gethostname(rawHostName, 150);
	getlogin_r(rawUserName, 150);

	while ( rawHostName[i] != '\0' )
	{
		hostname += rawHostName[i];
		i = i + 1;
	}
	i = 0;

	while ( rawUserName[i] != '\0' )
	{
		username += rawUserName[i];
		i = i + 1;
	}

	char		strHost[100];
	char		strUser[100];


	strcpy(strHost, "Hostname : ");
	strcat(strHost, hostname.c_str());

	strcpy(strUser, "Username : ");
	strcat(strUser, username.c_str());

	if (width < REQUIRED_WIDTH - 1 || height < REQUIRED_HEIGHT - 3)
	{
		return ;
	}

	win.print(posX + (width - strlen(strHost)) / 2, posY + 0, strHost);
	win.print(posX + (width - strlen(strHost)) / 2, posY + 1, strUser);
}