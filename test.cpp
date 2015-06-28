#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
int		main(void)
{
	// FILE				*output = popen("curl -v http://moube.fr/user/achazal | grep -A15 '<dt>Âge</dt>'", "r");
	// char				buffer[1024];
	// std::stringstream	total;

	// if (!output)
	// 	return (0);
	// while (!feof(output))
	// 	if (fgets(buffer, sizeof(buffer), output) != NULL)
	// 		total << buffer;
	// pclose(output);
	// std::cout << total << std::endl;
	// int i;
	// while ((i = fread(output, buffer, 1024) > 0))
		// write(1, buffer, i);

	// std::cout << output << std::endl;

	FILE				*input;
    char				buffer[512];
	std::stringstream	result;

	input = popen("curl -v http://moube.fr/user/achazal | grep -A15 '<dt>Âge</dt>'", "r");

	if (!input)
		return (0);
	while (!feof(input))
		if (fgets(buffer, sizeof(buffer), input) != NULL)
			result << buffer;
	pclose(input);
	std::cout << result.str() << std::endl;
}