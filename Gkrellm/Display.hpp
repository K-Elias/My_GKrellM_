#ifndef _DISPLAY_HPP_
# define _DISPLAY_HPP_

#include <vector>
#include <curses.h>
#include "Module.hpp"
#include "IMonitorDisplay.hpp"
#define SLEEP 100000000

class		Display : public IMonitorDisplay
{

private:
  Module			module;
  std::vector<std::string>	stock;

public:
  Display();
  virtual ~Display() {};
  virtual void windows_print();
  void		init_stock();
  void		Display_User(WINDOW *up);
  void		Display_System(WINDOW *down);
  void		Display_CPU(WINDOW *down);
  void		Display_RAM(WINDOW *down);
  void		Display_Net(WINDOW *down);
  void		Usage(WINDOW *left);
  void		initialisation();
  void		check_get(char c);
  void		my_sleep() const;
};

#endif /* !_DISPLAY_HPP_ */
