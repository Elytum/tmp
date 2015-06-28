// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PonyModule.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hmoutaou <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/28 10:04:59 by hmoutaou          #+#    #+#             //
/*   Updated: 2015/06/28 15:04:13 by bwanlin          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "PonyModule.hpp"

#define REQUIRED_WIDTH 37
#define REQUIRED_HEIGHT 9
#define TICK_RATE 100

PonyModule::PonyModule( void ): MonitorModule(REQUIRED_WIDTH, REQUIRED_HEIGHT, "Run pony !! Run !!") {

}

PonyModule::PonyModule( PonyModule const& rhs )
{
	*this = rhs;
}

PonyModule::~PonyModule( void ) {}

PonyModule &	PonyModule::operator=( PonyModule const& )
{
	return (*this);
}

void		PonyModule::drawContent( int posX, int posY, int width, int height, Window const & win )
{
	(void)width;
	(void)height;


	static int		gallop_count = -1;
	static int		gallop_tick = TICK_RATE;

	const char			*gallop[48][7];

	gallop[0][0] = "                                   ";
	gallop[0][1] = "~                                  ";
	gallop[0][2] = "\\                                 ";
	gallop[0][3] = "`                                  ";
	gallop[0][4] = "                                   ";
	gallop[0][5] = "                                   ";
	gallop[0][6] = "                                   ";

	gallop[1][0] = "                                   ";
	gallop[1][1] = ",~                                 ";
	gallop[1][2] = "(\\                                ";
	gallop[1][3] = " `                                 ";
	gallop[1][4] = "                                   ";
	gallop[1][5] = "                                   ";
	gallop[1][6] = "                                   ";

	gallop[2][0] = "                                   ";
	gallop[2][1] = " ,~                                ";
	gallop[2][2] = "/(\\                               ";
	gallop[2][3] = "/ `                                ";
	gallop[2][4] = "                                   ";
	gallop[2][5] = "                                   ";
	gallop[2][6] = "                                   ";

	gallop[3][0] = "                                   ";
	gallop[3][1] = " ,~                                ";
	gallop[3][2] = "/(\\                               ";
	gallop[3][3] = "/ `                                ";
	gallop[3][4] = "                                   ";
	gallop[3][5] = " \\                                ";
	gallop[3][6] = "/                                  ";

	gallop[4][0] = "                                   ";
	gallop[4][1] = "  ,~                               ";
	gallop[4][2] = "~/(\\                              ";
	gallop[4][3] = " / `                               ";
	gallop[4][4] = "|_                                 ";
	gallop[4][5] = "_\\/                               ";
	gallop[4][6] = "                                   ";

	gallop[5][0] = "                                   ";
	gallop[5][1] = "   ,~                              ";
	gallop[5][2] = " ~/(\\                             ";
	gallop[5][3] = "/ / `                              ";
	gallop[5][4] = "_|_                                ";
	gallop[5][5] = "_\\/                               ";
	gallop[5][6] = "                                   ";

	gallop[6][0] = "                                   ";
	gallop[6][1] = "    ,~                             ";
	gallop[6][2] = "  ~/(\\                            ";
	gallop[6][3] = "~/ / `                             ";
	gallop[6][4] = "(_|_                               ";
	gallop[6][5] = " _\\ \\                            ";
	gallop[6][6] = "                                   ";

	gallop[7][0] = "                                   ";
	gallop[7][1] = "     ,~                            ";
	gallop[7][2] = "   ~/(\\                           ";
	gallop[7][3] = "_~/ / `                            ";
	gallop[7][4] = "_(_|_                              ";
	gallop[7][5] = "    \\ \\                          ";
	gallop[7][6] = "     \\                            ";

	gallop[8][0] = "                                   ";
	gallop[8][1] = "       ,~                          ";
	gallop[8][2] = "    ~~/(\\                         ";
	gallop[8][3] = "__~~/ / `                          ";
	gallop[8][4] = "__( /                              ";
	gallop[8][5] = " _`/|                              ";
	gallop[8][6] = "   /                               ";

	gallop[9][0] = "                                   ";
	gallop[9][1] = "        ,~                         ";
	gallop[9][2] = "     ~~/(\\                        ";
	gallop[9][3] = "___~~/ / `                         ";
	gallop[9][4] = "___( /                             ";
	gallop[9][5] = "_  _`/|                            ";
	gallop[9][6] = "   '                               ";

	gallop[10][0] = "                                   ";
	gallop[10][1] = "         ,~                        ";
	gallop[10][2] = "      ~~/(\\                       ";
	gallop[10][3] = "____~~/ / `                        ";
	gallop[10][4] = ")___( /                            ";
	gallop[10][5] = " _   `/|                           ";
	gallop[10][6] = "    //                             ";

	gallop[11][0] = "                                   ";
	gallop[11][1] = "         ,~                        ";
	gallop[11][2] = "       ~/(\\                       ";
	gallop[11][3] = "_____~/ / `                        ";
	gallop[11][4] = " )___( |                           ";
	gallop[11][5] = "\\     ` \\                        ";
	gallop[11][6] = "`\\    '/                          ";

	gallop[12][0] = "                                   ";
	gallop[12][1] = "          ,~                       ";
	gallop[12][2] = "        ~/(\\                      ";
	gallop[12][3] = " _____~/ / `                       ";
	gallop[12][4] = "( )___(_|_                         ";
	gallop[12][5] = " \\     _\\/                       ";
	gallop[12][6] = " `\\                               ";

	gallop[13][0] = "                                   ";
	gallop[13][1] = "           ,~                      ";
	gallop[13][2] = "         ~/(\\                     ";
	gallop[13][3] = "~ _____~/ / `                      ";
	gallop[13][4] = "~( )___(_|_                        ";
	gallop[13][5] = "///     _\\/                       ";
	gallop[13][6] = "` \\                               ";

	gallop[14][0] = "                                   ";
	gallop[14][1] = "            ,~                     ";
	gallop[14][2] = "          ~/(\\                    ";
	gallop[14][3] = " ~ _____~/ / `                     ";
	gallop[14][4] = "~~( )___(_|_                       ";
	gallop[14][5] = " / /     _\\ \\                    ";
	gallop[14][6] = "//                                 ";

	gallop[15][0] = "                                   ";
	gallop[15][1] = "             ,~                    ";
	gallop[15][2] = "           ~/(\\                   ";
	gallop[15][3] = "  ~ _____~/ / `                    ";
	gallop[15][4] = "~~~( )___(_|_                      ";
	gallop[15][5] = "  /|/_      \\ \\                  ";
	gallop[15][6] = "  `          \\                    ";

	gallop[16][0] = "                                   ";
	gallop[16][1] = "                ,~                 ";
	gallop[16][2] = "             ~~/(\\                ";
	gallop[16][3] = "   ~~ _____~~/ / `                 ";
	gallop[16][4] = " ~~~~( )___( /                     ";
	gallop[16][5] = "    /|/_  _`/|                     ";
	gallop[16][6] = "      \\    /                      ";

	gallop[17][0] = "                                   ";
	gallop[17][1] = "                 ,~                ";
	gallop[17][2] = "              ~~/(\\               ";
	gallop[17][3] = "    ~~ _____~~/ / `                ";
	gallop[17][4] = "  ~~~~( )___( /                    ";
	gallop[17][5] = "      |\\_  _`/|                   ";
	gallop[17][6] = "       `    '                      ";

	gallop[18][0] = "                                   ";
	gallop[18][1] = "                  ,~               ";
	gallop[18][2] = "               ~~/(\\              ";
	gallop[18][3] = "      ~ _____~~/ / `               ";
	gallop[18][4] = "   ~~~~( )___( /                   ";
	gallop[18][5] = "       |\\_   `/|                  ";
	gallop[18][6] = "        `    //                    ";

	gallop[19][0] = "                                   ";
	gallop[19][1] = "                  ,~               ";
	gallop[19][2] = "                ~/(\\              ";
	gallop[19][3] = "       ~ _____~/ / `               ";
	gallop[19][4] = "     ~~~( )___( |                  ";
	gallop[19][5] = "        |\\     ` \\               ";
	gallop[19][6] = "         `\\    '/                 ";

	gallop[20][0] = "                                   ";
	gallop[20][1] = "                   ,~              ";
	gallop[20][2] = "                 ~/(\\             ";
	gallop[20][3] = "        ~ _____~/ / `              ";
	gallop[20][4] = "     ~~~~( )___(_|_                ";
	gallop[20][5] = "          \\     _\\/              ";
	gallop[20][6] = "          `\\                      ";

	gallop[21][0] = "                                   ";
	gallop[21][1] = "                    ,~             ";
	gallop[21][2] = "                  ~/(\\            ";
	gallop[21][3] = "         ~ _____~/ / `             ";
	gallop[21][4] = "       ~~~( )___(_|_               ";
	gallop[21][5] = "         ///     _\\/              ";
	gallop[21][6] = "         ` \\                      ";

	gallop[22][0] = "                                   ";
	gallop[22][1] = "                     ,~            ";
	gallop[22][2] = "                   ~/(\\           ";
	gallop[22][3] = "          ~ _____~/ / `            ";
	gallop[22][4] = "        ~~~( )___(_|_              ";
	gallop[22][5] = "          / /     _\\ \\           ";
	gallop[22][6] = "         //                        ";

	gallop[23][0] = "                                   ";
	gallop[23][1] = "                      ,~           ";
	gallop[23][2] = "                    ~/(\\          ";
	gallop[23][3] = "           ~ _____~/ / `           ";
	gallop[23][4] = "         ~~~( )___(_|_             ";
	gallop[23][5] = "           /|/_      \\ \\         ";
	gallop[23][6] = "           `          \\           ";

	gallop[24][0] = "                                   ";
	gallop[24][1] = "                        ,~         ";
	gallop[24][2] = "                     ~~/(\\        ";
	gallop[24][3] = "           ~~ _____~~/ / `         ";
	gallop[24][4] = "         ~~~~( )___( /             ";
	gallop[24][5] = "            /|/_  _`/|             ";
	gallop[24][6] = "              \\    /              ";

	gallop[25][0] = "                                   ";
	gallop[25][1] = "                         ,~        ";
	gallop[25][2] = "                      ~~/(\\       ";
	gallop[25][3] = "            ~~ _____~~/ / `        ";
	gallop[25][4] = "          ~~~~( )___( /            ";
	gallop[25][5] = "              |\\_  _`/|           ";
	gallop[25][6] = "               `    '              ";

	gallop[26][0] = "                                   ";
	gallop[26][1] = "                          ,~       ";
	gallop[26][2] = "                       ~~/(\\      ";
	gallop[26][3] = "              ~ _____~~/ / `       ";
	gallop[26][4] = "           ~~~~( )___( /           ";
	gallop[26][5] = "               |\\_   `/|          ";
	gallop[26][6] = "                `    //            ";

	gallop[27][0] = "                                   ";
	gallop[27][1] = "                          ,~       ";
	gallop[27][2] = "                        ~/(\\      ";
	gallop[27][3] = "               ~ _____~/ / `       ";
	gallop[27][4] = "             ~~~( )___( |          ";
	gallop[27][5] = "                |\\     ` \\       ";
	gallop[27][6] = "                 `\\    '/         ";

	gallop[28][0] = "                                   ";
	gallop[28][1] = "                           ,~      ";
	gallop[28][2] = "                         ~/(\\     ";
	gallop[28][3] = "                ~ _____~/ / `      ";
	gallop[28][4] = "             ~~~~( )___(_|_        ";
	gallop[28][5] = "                  \\     _\\/      ";
	gallop[28][6] = "                  `\\              ";

	gallop[29][0] = "                                   ";
	gallop[29][1] = "                            ,~     ";
	gallop[29][2] = "                          ~/(\\    ";
	gallop[29][3] = "                 ~ _____~/ / `     ";
	gallop[29][4] = "               ~~~( )___(_|_       ";
	gallop[29][5] = "                 ///     _\\/      ";
	gallop[29][6] = "                 ` \\              ";

	gallop[30][0] = "                                   ";
	gallop[30][1] = "                             ,~    ";
	gallop[30][2] = "                           ~/(\\   ";
	gallop[30][3] = "                  ~ _____~/ / `    ";
	gallop[30][4] = "                ~~~( )___(_|_      ";
	gallop[30][5] = "                  / /     _\\ \\   ";
	gallop[30][6] = "                 //                ";

	gallop[31][0] = "                                   ";
	gallop[31][1] = "                              ,~   ";
	gallop[31][2] = "                            ~/(\\  ";
	gallop[31][3] = "                   ~ _____~/ / `   ";
	gallop[31][4] = "                 ~~~( )___(_|_     ";
	gallop[31][5] = "                   /|/_      \\ \\ ";
	gallop[31][6] = "                   `          \\   ";

	gallop[32][0] = "                                   ";
	gallop[32][1] = "                                ,~ ";
	gallop[32][2] = "                             ~~/(\\";
	gallop[32][3] = "                   ~~ _____~~/ / ` ";
	gallop[32][4] = "                 ~~~~( )___( /     ";
	gallop[32][5] = "                    /|/_  _`/|     ";
	gallop[32][6] = "                      \\    /      ";

	gallop[33][0] = "                                   ";
	gallop[33][1] = "                                 ,~";
	gallop[33][2] = "                              ~~/( ";
	gallop[33][3] = "                    ~~ _____~~/ / `";
	gallop[33][4] = "                  ~~~~( )___( /    ";
	gallop[33][5] = "                      |\\_  _`/|   ";
	gallop[33][6] = "                       `    '      ";

	gallop[34][0] = "                                   ";
	gallop[34][1] = "                                  ,";
	gallop[34][2] = "                               ~~/(";
	gallop[34][3] = "                      ~ _____~~/ / ";
	gallop[34][4] = "                   ~~~~( )___( /   ";
	gallop[34][5] = "                       |\\_   `/|  ";
	gallop[34][6] = "                        `    //    ";

	gallop[35][0] = "                                   ";
	gallop[35][1] = "                                  ,";
	gallop[35][2] = "                                ~/(";
	gallop[35][3] = "                       ~ _____~/ / ";
	gallop[35][4] = "                     ~~~( )___( |  ";
	gallop[35][5] = "                        |\\     `  ";
	gallop[35][6] = "                         `\\    '/ ";

	gallop[36][0] = "                                   ";
	gallop[36][1] = "                                   ";
	gallop[36][2] = "                                 ~/";
	gallop[36][3] = "                        ~ _____~/ /";
	gallop[36][4] = "                     ~~~~( )___(_|_";
	gallop[36][5] = "                          \\     _\\";
	gallop[36][6] = "                          `\\      ";

	gallop[37][0] = "                                   ";
	gallop[37][1] = "                                   ";
	gallop[37][2] = "                                  ~";
	gallop[37][3] = "                         ~ _____~/ ";
	gallop[37][4] = "                       ~~~( )___(_|";
	gallop[37][5] = "                         ///     _\\";
	gallop[37][6] = "                         ` \\      ";

	gallop[38][0] = "                                   ";
	gallop[38][1] = "                                   ";
	gallop[38][2] = "                                   ";
	gallop[38][3] = "                          ~ _____~/";
	gallop[38][4] = "                        ~~~( )___(_";
	gallop[38][5] = "                          / /     _";
	gallop[38][6] = "                         //        ";

	gallop[39][0] = "                                   ";
	gallop[39][1] = "                                   ";
	gallop[39][2] = "                                   ";
	gallop[39][3] = "                           ~ _____~";
	gallop[39][4] = "                         ~~~( )___(";
	gallop[39][5] = "                           /|/_    ";
	gallop[39][6] = "                           `       ";

	gallop[40][0] = "                                   ";
	gallop[40][1] = "                                   ";
	gallop[40][2] = "                                   ";
	gallop[40][3] = "                           ~~ _____";
	gallop[40][4] = "                         ~~~~( )___";
	gallop[40][5] = "                            /|/_  _";
	gallop[40][6] = "                              \\   ";

	gallop[41][0] = "                                   ";
	gallop[41][1] = "                                   ";
	gallop[41][2] = "                                   ";
	gallop[41][3] = "                            ~~ ____";
	gallop[41][4] = "                          ~~~~( )__";
	gallop[41][5] = "                              |\\_ ";
	gallop[41][6] = "                               `   ";

	gallop[42][0] = "                                   ";
	gallop[42][1] = "                                   ";
	gallop[42][2] = "                                   ";
	gallop[42][3] = "                              ~ ___";
	gallop[42][4] = "                           ~~~~( )_";
	gallop[42][5] = "                               |\\_";
	gallop[42][6] = "                                `  ";

	gallop[43][0] = "                                   ";
	gallop[43][1] = "                                   ";
	gallop[43][2] = "                                   ";
	gallop[43][3] = "                               ~ __";
	gallop[43][4] = "                             ~~~( )";
	gallop[43][5] = "                                |\\";
	gallop[43][6] = "                                 `\\";

	gallop[44][0] = "                                   ";
	gallop[44][1] = "                                   ";
	gallop[44][2] = "                                   ";
	gallop[44][3] = "                                ~ _";
	gallop[44][4] = "                             ~~~~( ";
	gallop[44][5] = "                                  \\";
	gallop[44][6] = "                                  `";

	gallop[45][0] = "                                   ";
	gallop[45][1] = "                                   ";
	gallop[45][2] = "                                   ";
	gallop[45][3] = "                                 ~ ";
	gallop[45][4] = "                               ~~~(";
	gallop[45][5] = "                                 //";
	gallop[45][6] = "                                 ` ";

	gallop[46][0] = "                                   ";
	gallop[46][1] = "                                   ";
	gallop[46][2] = "                                   ";
	gallop[46][3] = "                                  ~";
	gallop[46][4] = "                                ~~~";
	gallop[46][5] = "                                  /";
	gallop[46][6] = "                                 //";

	gallop[47][0] = "                                   ";
	gallop[47][1] = "                                   ";
	gallop[47][2] = "                                   ";
	gallop[47][3] = "                                   ";
	gallop[47][4] = "                                 ~~";
	gallop[47][5] = "                                   ";
	gallop[47][6] = "                                   ";




	gallop_tick = gallop_tick + 1;
	if (gallop_tick >= TICK_RATE + 1)
	{
		gallop_tick = 0 ;

		gallop_count = gallop_count + 1;
		if (gallop_count >= 48)
		{
			gallop_count = 0;
		}
	}

	//win.print(posX + (width - 35) / 2, posY - 1, gallop[gallop_count][0]);
	win.print(posX + (width - 35) / 2, posY + 0, gallop[gallop_count][1]);
	win.print(posX + (width - 35) / 2, posY + 1, gallop[gallop_count][2]);
	win.print(posX + (width - 35) / 2, posY + 2, gallop[gallop_count][3]);
	win.print(posX + (width - 35) / 2, posY + 3, gallop[gallop_count][4]);
	win.print(posX + (width - 35) / 2, posY + 4, gallop[gallop_count][5]);
	win.print(posX + (width - 35) / 2, posY + 5, gallop[gallop_count][6]);

};
