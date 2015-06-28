#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define INTRO "<dd>"

struct	content {
	int				age;
	std::string*		grade;
	std::string*		liberation;
	float			level;
	float			moyenne;
	float			moyenneCorrection;
	int				correctionPoints;
	int				wallet;
};

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

std::string*		extractString(char buffer[BUFF_SIZE]) {
	char	*ptr = buffer;

	while (*ptr) {
		if (!strncmp(ptr, INTRO, sizeof(INTRO) - 1)) {
			ptr += sizeof(INTRO) - 1;
			ptr[strlen(ptr) - sizeof(INTRO) - 1] = '\0';
			return new std::string(ptr);
		}
		++ptr;
	}
	return (0);
}

int		main(void)
{
	FILE				*input;
    char				buffer[BUFF_SIZE];
	std::stringstream	result;

	input = popen("curl --silent http://moube.fr/user/achazal | grep -A15 '<dt>Âge</dt>'", "r");

	if (!input)
		return (0);

	int lineID = 0;
	content	info;

	while (!feof(input))
		if (fgets(buffer, sizeof(buffer), input) != NULL) {
			if (lineID == 1)
				info.age = extractInt(buffer);
			else if (lineID == 3)
				info.grade = extractString(buffer);
			else if (lineID == 5)
				info.liberation = extractString(buffer);
			else if (lineID == 7)
				info.level = extractDouble(buffer);
			else if (lineID == 9)
				info.moyenne = extractDouble(buffer);
			else if (lineID == 11)
				info.moyenneCorrection = extractDouble(buffer);
			else if (lineID == 13)
				info.correctionPoints = extractInt(buffer);
			else if (lineID == 15)
				info.wallet = extractInt(buffer);
			++lineID;
		}
	pclose(input);

	std::cout
		<< "Age: " << info.age << std::endl
		<< "Grade: " << *info.grade << std::endl
		<< "Liberation: " << *info.liberation << std::endl
		<< "Level: " << info.level << std::endl
		<< "Moyenne: " << info.moyenne << std::endl
		<< "Moyenne Correction: " << info.moyenneCorrection << std::endl
		<< "Wallet: " << info.wallet << std::endl;

	delete info.grade;
	delete info.liberation;
}