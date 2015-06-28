// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NameModule.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hmoutaou <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/28 03:58:25 by hmoutaou          #+#    #+#             //
//   Updated: 2015/06/28 03:58:26 by hmoutaou         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NAMEMODULE_HPP
# define NAMEMODULE_HPP

# include <string>
# include <iostream>
# include <ctime>
# include "MonitorModule.hpp"

typedef std::string string;
typedef unsigned int uint;

#include <sys/types.h>
#include <sys/sysctl.h>

#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>


class	NameModule:public MonitorModule
{
public:
	NameModule( void );
	NameModule( char * );
	NameModule( NameModule const& rhs );
	~NameModule( void );

	NameModule &	operator=( NameModule const& rhs );
	virtual void		drawContent( int x, int y, int w, int h, Window const& );
};

#endif
