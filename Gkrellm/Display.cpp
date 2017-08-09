#include "Display.hpp"

Display::Display() {}

void             Display::windows_print()
{
  char		c;

  c = 0;
  initscr();
  raw();
  noecho();
  curs_set(0);
  start_color();
  nodelay(stdscr, true);
  while (c != 'q')
    {
      c = getch();
      clear();
      check_get(c);
      assume_default_colors(COLOR_BLACK,COLOR_WHITE);
      this->initialisation();
      this->my_sleep();
      refresh();
    }
  refresh();
  endwin();
}

void	Display::my_sleep() const
{
  int	i = 0;
  while (i != SLEEP)
    ++i;
}

void	Display::check_get(char c)
{
  if (c == 'u')
    this->module.setUser();
  else if (c == 'm')
    this->module.setMachine();
  else if (c == 'o')
    this->module.setOs();
  else if (c == 'k')
    this->module.setKernel();
  else if (c == 'd')
    this->module.setDate();
  else if (c == 'c')
    this->module.setCPU();
  else if (c == 'r')
    this->module.setRAM();
  else if (c == 'n')
      this->module.setNet();
}

void	Display::init_stock()
{
  this->stock.push_back(this->module.getETransmit());
  this->stock.push_back(this->module.getErec());
  this->stock.push_back(this->module.getEnp());
  this->stock.push_back(this->module.getWtransmit());
  this->stock.push_back(this->module.getWrec());
  this->stock.push_back(this->module.getNet());
  this->stock.push_back(this->module.getLoTransmit());
  this->stock.push_back(this->module.getLoRec());
  this->stock.push_back(this->module.getLo());
  this->stock.push_back(this->module.getRamswap());
  this->stock.push_back(this->module.getRamavailable());
  this->stock.push_back(this->module.getRamfree());
  this->stock.push_back(this->module.getRamtotal());
  this->stock.push_back(this->module.getHz(3));
  this->stock.push_back(this->module.getHz(2));
  this->stock.push_back(this->module.getHz(1));
  this->stock.push_back(this->module.getHz(0));
  this->stock.push_back(this->module.getNbCore());
  this->stock.push_back(this->module.getModel());
  this->stock.push_back(this->module.getDate());
  this->stock.push_back(this->module.getKernel());
  this->stock.push_back(this->module.getOp());
  this->stock.push_back(this->module.getUser());
  this->stock.push_back(this->module.getMachine());
}

void    Display::Usage(WINDOW *left)
{
  mvwprintw(left, 1, 8, "Display");
  mvwprintw(left, 4, 1, "-Machine Name: m");
  mvwprintw(left, 5, 1, "-User Name: u");
  mvwprintw(left, 6, 1, "-Operating System: o");
  mvwprintw(left, 7, 1, "-Kernel Version: k");
  mvwprintw(left, 8, 1, "-Date: d");
  mvwprintw(left, 9, 1, "-CPU: c");
  mvwprintw(left, 10, 1, "-RAM: r");
  mvwprintw(left, 11, 1, "-Network: n");
  mvwprintw(left, 12, 1, "-Quitter: q");
}

void	Display::Display_CPU(WINDOW *down)
{
  int	i;

  i  = 7;
  if (this->module.getCPU() == true)
    {
      mvwprintw(down, 6, 5, "CPU:", this->stock.back().c_str());
      while (i != 9)
	{
	  mvwprintw(down, i, 5, "%s", this->stock.back().c_str());
	  this->stock.pop_back();
	  i = i + 1;
	}
      mvwprintw(down, i++, 5, "Number of threads:");
      while (i != 14)
	{
	  mvwprintw(down, i, 5, "%s", this->stock.back().c_str());
	  this->stock.pop_back();
	  i = i + 1;
	}
    }
  else
    {
       while (i != 13)
	{
	  this->stock.pop_back();
	  i = i + 1;
	}
    }
}

void	Display::Display_RAM(WINDOW *down)
{
  int	i;

  i = 16;
  if (this->module.getRAM() == true)
    {
      mvwprintw(down, 15, 5, "RAM:", this->stock.back().c_str());
      while (i != 20)
	{
	  mvwprintw(down, i, 5, "%s", this->stock.back().c_str());
	  this->stock.pop_back();
	  i = i + 1;
	}
    }
  else
    {
      while (i != 20)
	{
	  this->stock.pop_back();
	  i = i + 1;
	}
    }
}

void	Display::Display_System(WINDOW *down)
{
  mvwprintw(down, 1, 5, "System:", this->stock.back().c_str());
  if (this->module.getOS() == true)
    mvwprintw(down, 2, 5, "Operating System: %s", this->stock.back().c_str());
  this->stock.pop_back();
  if (this->module.getKe() == true)
    mvwprintw(down, 3, 5, "Kernel Version: %s", this->stock.back().c_str());
  this->stock.pop_back();
  if (this->module.getDa() == true)
    mvwprintw(down, 4, 5, "Date: %s", this->stock.back().c_str());
  this->stock.pop_back();
}

void	Display::Display_User(WINDOW *up)
{
  if (this->module.getMa() == true)
    mvwprintw(up, 1, 7, "Machine Name: %s", this->stock.back().c_str());
  this->stock.pop_back();
  if (this->module.getUs() == true)
    mvwprintw(up, 2, 7, "User Name: %s", this->stock.back().c_str());
  this->stock.pop_back();
}

void	Display::Display_Net(WINDOW *down)
{
  if (this->module.getNET() == true)
    {
      mvwprintw(down, 21, 5, "Network:", this->stock.back().c_str());
      mvwprintw(down, 22, 1, "%s", this->stock.back().c_str());
      this->stock.pop_back();
      mvwprintw(down, 22, 20, "%s", this->stock.back().c_str());
      this->stock.pop_back();
      mvwprintw(down, 22, 30, "%s", this->stock.back().c_str());
      this->stock.pop_back();
      mvwprintw(down, 23, 3, "%s", this->stock.back().c_str());
      this->stock.pop_back();
      mvwprintw(down, 23, 20, "%s", this->stock.back().c_str());
      this->stock.pop_back();
      mvwprintw(down, 23, 30, "%s", this->stock.back().c_str());
      this->stock.pop_back();
      mvwprintw(down, 24, 5, "%s", this->stock.back().c_str());
      this->stock.pop_back();
      mvwprintw(down, 24, 20, "%s", this->stock.back().c_str());
      this->stock.pop_back();
      mvwprintw(down, 24, 30, "%s", this->stock.back().c_str());
      this->stock.pop_back();
    }
  else
    {
      this->stock.pop_back();
      this->stock.pop_back();
      this->stock.pop_back();
    }
}

void    Display::initialisation()
{
  WINDOW *up, *down, *left;

  up= subwin(stdscr, LINES / 5, COLS / 2, 0, COLS / 3);
  down= subwin(stdscr, LINES / 1.5, COLS, LINES / 3, 0);
  left= subwin(stdscr, LINES / 3, COLS / 3, 0, 0);
  box(up, ACS_VLINE, ACS_HLINE);
  box(down, ACS_VLINE, ACS_HLINE);
  box(left, ACS_VLINE, ACS_HLINE);
  this->init_stock();
  this->Display_User(up);
  this->Display_System(down);
  this->Display_CPU(down);
  this->Display_RAM(down);
  this->Display_Net(down);
  this->Usage(left);
}
