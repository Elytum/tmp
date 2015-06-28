#include <Window.hpp>

Window::Window() : opened(false),
	window_white(NULL), main_window(NULL) {
		modules.resize(MAX_WIDTH_MODULES);
}

Window::~Window() {
	if (main_window)
		delwin(main_window);
}

int			Window::getSeenWidth() const {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	return (w.ws_col);
}

int			Window::getSeenHeight() const {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	return (w.ws_row);
}

void	Window::open( void ) {
	if (opened == true)
		return ;
	opened = true;
	initscr();


	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	main_window = newwin(w.ws_row, w.ws_col, 0, 0);
	keypad(main_window, TRUE);

	window_white = derwin(main_window, w.ws_row, w.ws_col, 0, 0);

	start_color();

	init_color(COLOR_ORANGE, 1000, 549, 0);
	init_color(COLOR_VIOLET, 580, 0, 827);
	init_color(COLOR_GREY, 302, 302, 302);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_YELLOW);
	init_pair(12, COLOR_BLACK, COLOR_WHITE);
	init_pair(13, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(14, COLOR_BLACK, COLOR_CYAN);

	init_pair(15, COLOR_ORANGE, COLOR_BLACK);
	init_pair(16, COLOR_BLACK, COLOR_ORANGE);

	init_pair(17, COLOR_VIOLET, COLOR_BLACK);
	init_pair(18, COLOR_BLACK, COLOR_VIOLET);

	init_pair(19, COLOR_GREY, COLOR_BLACK);
	init_pair(20, COLOR_BLACK, COLOR_GREY);


	noecho();
	curs_set(FALSE);
	nodelay(main_window, TRUE);
}

void				Window::close( void )	{
	if (opened == false)
		return ;
	endwin();
}

void		Window::clr( void ) const {
	werase(main_window);
}

void		Window::print( int x, int y, char const *c ) const {
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	doPrint(x, y, c, WHITE);
}

void		Window::print( int x, int y, char const c ) const {
	static char tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	doPrint(x, y, tmp, WHITE);
}

void		Window::doPrint(int x, int y, const char *str, colorsKind color) const {
	if (color) {
		wattron(main_window, COLOR_PAIR(color));
		mvwprintw(main_window, y, x, str);
		wattroff(main_window, COLOR_PAIR(color));
	} else
		mvwprintw(main_window, y, x, str);
}

static colorsKind	getColor(char color) {
	if (color == 'R')
		return (RED);
	else if (color == 'G')
		return (GREEN);
	else if (color == 'B')
		return (BLUE);
	else if (color == 'Y')
		return (YELLOW);
	else if (color == 'W')
		return (WHITE);
	else if (color == 'M')
		return (MAGENTA);
	else if (color == 'C')
		return (CYAN);
	else if (color == 'r')
		return (REVERSE_RED);
	else if (color == 'g')
		return (REVERSE_GREEN);
	else if (color == 'b')
		return (REVERSE_BLUE);
	else if (color == 'y')
		return (REVERSE_YELLOW);
	else if (color == 'w')
		return (REVERSE_WHITE);
	else if (color == 'm')
		return (REVERSE_MAGENTA);
	else if (color == 'c')
		return (REVERSE_CYAN);
	else if (color == 'O')
		return (ORANGE);
	else if (color == 'o')
		return (REVERSE_ORANGE);
	else if (color == 'V')
		return (VIOLET);
	else if (color == 'v')
		return (REVERSE_VIOLET);
	else if (color == 'E')
		return (GREY);
	else if (color == 'e')
		return (REVERSE_GREY);
	return (BLACK);
}

void		Window::print( int x, int y, char const *c, char const color ) const {
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	doPrint(x, y, c, getColor(color));
}

void		Window::print( int x, int y, char const c, char const color ) const {
	static char tmp[2] = {'\0'};

	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	tmp[0] = c;
	tmp[1] = '\0';
	doPrint(x, y, tmp, getColor(color));
}

void		Window::printBox(int x, int y, int w, int h) const {
	mvwaddch(window_white, y, x, ACS_PLUS);
	mvwaddch(window_white, y, x + w, ACS_PLUS);
	mvwaddch(window_white, y + h, x, ACS_PLUS);
	mvwaddch(window_white, y + h, x + w, ACS_PLUS);
	mvwhline(window_white, y, x + 1, ACS_HLINE, w - 1);
	mvwhline(window_white, y + h, x + 1, ACS_HLINE, w - 1);
	mvwvline(window_white, y + 1, x, '|', h - 1);
	mvwvline(window_white, y + 1, x + w, '|', h - 1);
}

void		Window::printHLine(int x, int y, int w) const
{
	mvwaddch(window_white, y, x, ACS_PLUS);
	mvwaddch(window_white, y, x + w, ACS_PLUS);
	mvwhline(window_white, y, x + 1, ACS_HLINE, w - 1);
};

void	Window::flush( void )	{
	touchwin(main_window);
	wrefresh(main_window);
}

void		Window::addModule( MonitorModule * module, int row ) {
	modules[row].addModule(module);
}

void		Window::refresh( void ) {
	int	i = modules.size();
	int p = 0;
	int posX = 0;

	while (p < i) {
		modules[p].draw(posX, 0, *this);
		posX += modules[p].getWidth();
		++p;
	}
}

WINDOW*		Window::getWindow( void ) const {
	return main_window;
}
























