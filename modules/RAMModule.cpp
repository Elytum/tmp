#include "RAMModule.hpp"

RAMModule::RAMModule( void ):MonitorModule(17, 6, "RAM USAGE")
{

}

RAMModule::RAMModule( string name ):MonitorModule(17, 6, name)
{

}

RAMModule::RAMModule( RAMModule const& rhs )
{
	*this = rhs;
}

RAMModule::~RAMModule( void ) {}

RAMModule &	RAMModule::operator=( RAMModule const& )
{
	return (*this);
}

#define BSIZE (1024 * 1024)
#define	BNAME ("M")


string			RAMModule::offsetStr(string str) const
{
	return (string((getWidth() - str.size()) / 2.0, ' ') + str);
}
	
void		RAMModule::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	string maxmem;
	string freemem;
	string usedmem;
	string maxswap;
	//string usedswap;

	(void)width;
	(void)height;

	int64_t mem;
	size_t len = sizeof(int64_t);

	sysctlbyname("hw.memsize", &mem, &len, NULL, 0);
	maxmem = std::to_string(mem / BSIZE) + BNAME;

	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
										(host_info64_t)&vm_stats, &count))
	{
		long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

		long long used_memory = ((int64_t)vm_stats.active_count +
								 (int64_t)vm_stats.inactive_count +
								 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;	
		freemem = std::to_string(free_memory / BSIZE) + BNAME;
		usedmem = std::to_string(used_memory / BSIZE) + BNAME;
	}
	else
	{
		freemem = std::string('X', width);
		usedmem = std::string('x', width);
	}

	// struct statfs stats;
	// if (0 == statfs("/", &stats))
	// {
	// 	uint64_t maxswapsize = stats.f_bsize * stats.f_bfree;
	// 	maxswap = std::to_string(maxswapsize / BSIZE) + BNAME;
	// }

	// xsw_usage vmusage = xsw_usage();
	// size_t size = sizeof(vmusage);
	// if( sysctlbyname("vm.swapusage", &vmusage, &size, NULL, 0)!=0 )
	// 	usedswap = std::string('x', width);
	// else
	// 	usedswap = std::to_string(vmusage.xsu_used);

	posY += (height - 3) / 2;

	int newWidth[3];
	newWidth[0] = 11 + maxmem.size();
	newWidth[1] = 11 + freemem.size();
	newWidth[2] = 11 + usedmem.size();
	int maxWidth = *std::max_element(newWidth, newWidth + 3);
	if (maxWidth < getWidth())
		setWidth(maxWidth);

	maxmem = "TOTAL MEM: " + maxmem;
	freemem = "FREE MEM:  " + freemem;
	usedmem = "USED MEM:  " + usedmem;
	
	int xoffset[3];
	xoffset[0] = (width - maxmem.size()) / 2;
	xoffset[1] = (width - freemem.size()) / 2;
	xoffset[2] = (width - usedmem.size()) / 2;

	win.print(posX + xoffset[0], posY + 0, maxmem.c_str());
	//win.print(posX, posY + 1, offsetStr(maxmem).c_str());
	win.print(posX + xoffset[1], posY + 1, freemem.c_str());
	//win.print(posX, posY + 3, offsetStr(freemem).c_str());
	win.print(posX + xoffset[2], posY + 2, usedmem.c_str());
	//win.print(posX, posY + 5, offsetStr(usedmem).c_str());
	// win.print(posX, posY + 6, "maxswap");
	// win.print(posX, posY + 7, maxswap.c_str());
	// win.print(posX, posY + 8, "usedswap");
	// win.print(posX, posY + 9, usedswap.c_str());
}











