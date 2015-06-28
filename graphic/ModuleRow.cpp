#include <ModuleRow.hpp>

ModuleRow::ModuleRow( void ) : width(0) {
}

ModuleRow::~ModuleRow( void ) {
	for (unsigned int i = 0; i < modules.size(); ++i) {
		delete modules[i];
	}
}

void								ModuleRow::addModule( MonitorModule * mod ) {
	modules.push_back(mod);
	for (unsigned int i = 0; i < modules.size(); ++i) {
		if (modules[i]->getWidth() > width)
			width = modules[i]->getWidth();
	}
}

const std::vector<MonitorModule *>	ModuleRow::getModules( void ) const {
	return modules;
}

int									ModuleRow::getWidth( void ) const {
	return width;
}

MonitorModule&						ModuleRow::operator[](int pos)	{
	if (pos < 0)
		throw std::exception();
	else if (pos >= static_cast<int>(modules.size()))
		modules.resize(pos + 1);
	return *modules[pos];
};

void								ModuleRow::draw( int x, int y, Window const & win ) {
	int s = modules.size();
	int i = 0;

	while (i < s) {
		modules[i]->draw(x, y, width, win);
		y += modules[i]->getHeight();
		++i;
	}
}