#ifndef STUDENT_MODULE_HPP
# define STUDENT_MODULE_HPP

# include <string>
# include <iostream>
# include "MonitorModule.hpp"
# include <sstream>
# include <cstdio>


typedef std::string string;
typedef unsigned int uint;

typedef struct		content {
	std::string		name;
	int				age;
	std::string		grade;
	std::string		liberation;
	float			level;
	float			moyenne;
	float			moyenneCorrection;
	int				correctionPoints;
	int				wallet;
}					t_content;

#define BUFF_SIZE 1024
#define INTRO "<dd>"

class	StudentModule:public MonitorModule
{
public:
	StudentModule( void );
	StudentModule( string name );
	StudentModule( StudentModule const& rhs );
	~StudentModule( void );

	StudentModule &	operator=( StudentModule const& rhs );
	string			offsetStr(string str) const;
	
	// virtual void	draw( int x, int y, int w, IMonitorDisplay const& ) const;
	virtual void	drawContent( int posX, int posY, int width, int height, Window const & win );
private:
	static time_t					_time;
	static t_content				*_info;
	static void						_update( void );

};

#endif