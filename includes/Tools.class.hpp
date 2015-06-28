/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:32:26 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 16:17:11 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP
# include <iostream>
# include <sys/types.h>
# include <sys/sysctl.h>
# include "MonitorModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>



class Tools : public MonitorModule
{

	public:
		Tools(void);
		virtual ~Tools(void);

		void	updateInfo( void );
		virtual void 	drawContent( int posX, int posY, int width, int height, Window const & win );
	
	private:
		struct timeval	btime;
};

#endif /* TOOLS_HPP */

