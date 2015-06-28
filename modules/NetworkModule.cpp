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
	
void					NetworkModule::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	FILE				*input;
    char				buffer[512];
	std::stringstream	result;

	input = popen("netstat -ib en0 | grep Link#4 | awk '{print $5, $7, $8, $10}'", "r");

	if (!input)
		return ;
	while(!feof(input))
		if(fgets(buffer, sizeof(buffer), input) != NULL)
			result << buffer;
	pclose(input);

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
	newWidth[2] = byte_o.str().size();
	int maxWidth = *std::max_element(newWidth, newWidth + 4);
	if (maxWidth > getWidth())
		setWidth(maxWidth);
	if (maxWidth > width)
		width = maxWidth;
	
	int xoffset[4];
	xoffset[0] = (width - pckt_i.str().size()) / 2;
	xoffset[1] = (width - byte_i.str().size()) / 2;
	xoffset[2] = (width - pckt_o.str().size()) / 2;
	xoffset[3] = (width - byte_o.str().size()) / 2;

	win.print(posX + xoffset[0], posY + 0, pckt_i.str().c_str());
	win.print(posX + xoffset[1], posY + 1, byte_i.str().c_str());
	win.print(posX + xoffset[2], posY + 2, pckt_o.str().c_str());
	win.print(posX + xoffset[3], posY + 3, byte_o.str().c_str());
}











