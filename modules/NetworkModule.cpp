#include "../includes/NetworkModule.hpp"

NetworkModule::NetworkModule( void ):MonitorModule(17, 7, "NETWORK")
{

}

NetworkModule::NetworkModule( string name ):MonitorModule(17, 7, name)
{

}

NetworkModule::NetworkModule( NetworkModule const& rhs )
{
	*this = rhs;
}

NetworkModule::~NetworkModule( void ) {}

NetworkModule &	NetworkModule::operator=( NetworkModule const& )
{
	return (*this);
}

#define BSIZE (1024 * 1024)
#define	BNAME ("M")


string			NetworkModule::offsetStr(string str) const
{
	return (string((getWidth() - str.size()) / 2.0, ' ') + str);
}

time_t					NetworkModule::_time = 0;
std::string				NetworkModule::_result;

void					NetworkModule::_update( void )
{
	time_t	cl = clock();
	(void)_time;
	if (9000 < cl % 10000)
	{
		_time = cl;
		FILE				*input;
		char				buffer[128];

		input = popen("netstat -ib en0 | grep Link#4 | awk '{print $5, $7, $8, $10}'", "r");

		_result.clear();
		if (!input)
			return ;
		while(!feof(input))
			if(fgets(buffer, sizeof(buffer), input) != NULL)
				_result += buffer;
		pclose(input);
	}
}
	
void					NetworkModule::drawContent( int posX, int posY, int width, int height, Window const & win )
{

	_update();
	std::stringstream	result;
	result << NetworkModule::_result;
	long int			pckt_i_data;
	long int			byte_i_data;
	long int			pckt_o_data;
	long int			byte_o_data;

	result >> pckt_i_data;
	result >> byte_i_data;
	result >> pckt_o_data;
	result >> byte_o_data;

	std::stringstream	pckt_i;
	std::stringstream	byte_i;
	std::stringstream	pckt_o;
	std::stringstream	byte_o;

	pckt_i << "I PCKT: " << pckt_i_data ;
	byte_i << "I BYTE: " << (byte_i_data / BSIZE) << BNAME;
	pckt_o << "O PCKT: " << pckt_o_data ;
	byte_o << "O BYTE: " << (byte_o_data / BSIZE) << BNAME;

	posY += (height - 4) / 2;

	int newWidth[4];
	newWidth[0] = pckt_i.str().size();
	newWidth[1] = byte_i.str().size();
	newWidth[2] = pckt_o.str().size();
	newWidth[3] = byte_o.str().size();
	int maxWidth = *std::max_element(newWidth, newWidth + 4);
	if (maxWidth > getWidth())
		setWidth(maxWidth);
	if (maxWidth > width)
		width = maxWidth;
	
	int xoffset = width / 2 - 8;
	// (void)xoffset;
	// (void)win;
	// (void)posX;
	// std::cout << pckt_i.str() << std::endl;
	// std::cout << byte_i.str() << std::endl;
	// std::cout << pckt_o.str() << std::endl;
	// std::cout << byte_o.str() << std::endl;

	win.print(posX + xoffset, posY + 0, pckt_i.str().c_str(), 'G');
	win.print(posX + xoffset, posY + 1, byte_i.str().c_str(), 'G');
	win.print(posX + xoffset, posY + 2, pckt_o.str().c_str(), 'Y');
	win.print(posX + xoffset, posY + 3, byte_o.str().c_str(), 'Y');
	(void)width;
	(void)height;
}