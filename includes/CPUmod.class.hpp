/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmod.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwanlin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:21:20 by bwanlin           #+#    #+#             */
/*   Updated: 2015/06/28 14:33:40 by bwanlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMOD_HPP
# define CPUMOD_HPP
# include <iostream>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <vector>
# include <sstream>
# include <mach/mach.h>
# include <mach/mach_error.h>
# include "MonitorModule.hpp"

struct CPUcontainer
{
	char				brand[256];
	int					cpuLoad;
	int					cpuFree;
	int					coreNB;
	int					byteOrder;
	struct clockinfo	clockinfo;
};

class CPUmod : public MonitorModule
{

	public:
		CPUmod(void);
		CPUmod( std::string );
		virtual ~CPUmod(void);

		void			printInfo( void ) const;
		void			updateInfo( void );
		float			GetCPULoad();
		long			ft_sysctl_int(int sys, int flag);
		void			ft_sysctl_clock(int sys, int flag);
		float			CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);

		virtual void 	drawContent( int posX, int posY, int width, int height, Window const & win );

	private:
		CPUcontainer _info;
};

#endif /* CPUMOD_HPP */

