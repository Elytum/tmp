// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeModule.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hmoutaou <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/28 00:51:24 by hmoutaou          #+#    #+#             //
/*   Updated: 2015/06/28 03:20:19 by bwanlin          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

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


class	TimeModule:public MonitorModule
{
public:
	TimeModule( void );
	TimeModule( char * );
	TimeModule( TimeModule const& rhs );
	~TimeModule( void );

	TimeModule &	operator=( TimeModule const& rhs );
// private:
	virtual void		drawContent( int x, int y, int w, int h, Window const& );
};

#endif
