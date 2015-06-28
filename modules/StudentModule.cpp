#include "../includes/StudentModule.hpp"

StudentModule::StudentModule( void ):MonitorModule(35, 11, "Student")
{

}

StudentModule::StudentModule( string name ):MonitorModule(35, 11, name)
{

}

StudentModule::StudentModule( StudentModule const& rhs )
{
	*this = rhs;
}

StudentModule::~StudentModule( void ) {}

StudentModule &	StudentModule::operator=( StudentModule const& )
{
	return (*this);
}

#define BSIZE (1024 * 1024)
#define	BNAME ("M")

time_t					StudentModule::_time = 0;
t_content*				StudentModule::_info = new t_content();



int				extractInt(char buffer[BUFF_SIZE]) {
	char	*ptr = buffer;

	while (*ptr) {
		if (*ptr >= '0' && *ptr <= '9')
			return (atoi(ptr));
		++ptr;
	}
	return (0);
}

float			extractDouble(char buffer[BUFF_SIZE]) {
	char	*ptr = buffer;

	while (*ptr) {
		if (*ptr >= '0' && *ptr <= '9')
			return (atof(ptr));
		++ptr;
	}
	return (0);
}

std::string		extractString(char buffer[BUFF_SIZE]) {
	char	*ptr = buffer;

	while (*ptr) {
		if (!strncmp(ptr, INTRO, sizeof(INTRO) - 1)) {
			ptr += sizeof(INTRO) - 1;
			ptr[strlen(ptr) - sizeof(INTRO) - 1] = '\0';
			return std::string(ptr);
		}
		++ptr;
	}
	return (0);
}

void					StudentModule::_update( void )
{
	time_t	cl = clock();
	if (_time == 0)
	{
		_time = cl;
		FILE				*input;
		char				buffer[BUFF_SIZE];


		char	rawUserName[150];


		getlogin_r(rawUserName, 150);
		_info->name = rawUserName;

		input = popen(("curl --silent http://moube.fr/user/" + _info->name + " | grep -A15 '<dt>Âge</dt>'").c_str(), "r");

		// std::cout << "calculating" << std::endl;
		int lineID = 0;
		while (!feof(input))
			if (fgets(buffer, sizeof(buffer), input) != NULL) {
				if (lineID == 1)
					_info->age = extractInt(buffer);
				else if (lineID == 3)
					_info->grade = extractString(buffer);
				else if (lineID == 5)
					_info->liberation = extractString(buffer);
				else if (lineID == 7)
					_info->level = extractDouble(buffer);
				else if (lineID == 9)
					_info->moyenne = extractDouble(buffer);
				else if (lineID == 11)
					_info->moyenneCorrection = extractDouble(buffer);
				else if (lineID == 13)
					_info->correctionPoints = extractInt(buffer);
				else if (lineID == 15)
					_info->wallet = extractInt(buffer);
				++lineID;
			}

		pclose(input);
	}
}

void					StudentModule::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	_update();
	std::stringstream name;
	std::stringstream age;
	std::stringstream grade;
	std::stringstream liberation;
	std::stringstream level;
	std::stringstream moyenne;
	std::stringstream moyenneCorrection;
	std::stringstream wallet;

	(void)height;

	name << "Name: " << _info->name;
	age << "Age: " << _info->age;
	grade << "Grade: " << _info->grade;
	liberation << "Liberation: " << _info->liberation;
	level << "Level: " << _info->level;
	moyenne << "Moyenne: " << _info->moyenne;
	moyenneCorrection << "Corrections: " << _info->moyenneCorrection;
	wallet << "Wallet: " << _info->wallet;

	win.print(posX + width / 2 - 6, posY++, name.str().c_str(), 'G');
	win.print(posX + width / 2 - 5, posY++, age.str().c_str(), 'G');
	win.print(posX + width / 2 - 7, posY++, grade.str().c_str(), 'R');
	win.print(posX + width / 2 - 12, posY++, liberation.str().c_str(), 'Y');
	win.print(posX + width / 2 - 7, posY++, level.str().c_str(), 'G');
	win.print(posX + width / 2 - 9, posY++, moyenne.str().c_str(), 'G');
	win.print(posX + width / 2 - 14, posY++, moyenneCorrection.str().c_str(), 'G');
	win.print(posX + width / 2 - 8, posY++, wallet.str().c_str(), 'Y');

}