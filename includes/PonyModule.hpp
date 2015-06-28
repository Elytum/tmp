// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PonyModule.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hmoutaou <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/28 10:05:40 by hmoutaou          #+#    #+#             //
//   Updated: 2015/06/28 10:05:40 by hmoutaou         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONYMODULE_HPP
# define PONYMODULE_HPP

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


class	PonyModule:public MonitorModule
{
public:
	PonyModule( void );
	PonyModule( char * );
	PonyModule( PonyModule const& rhs );
	~PonyModule( void );

	PonyModule &	operator=( PonyModule const& rhs );
// private:
	virtual void		drawContent( int x, int y, int w, int h, Window const& );
};

#endif
