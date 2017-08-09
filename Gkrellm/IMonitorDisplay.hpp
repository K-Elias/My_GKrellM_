#ifndef _IMONITORDISPLAY_HPP_
# define _IMONITORDISPLAY_HPP_

class		IMonitorDisplay
{
public:
  virtual ~IMonitorDisplay() {}
  virtual void windows_print() = 0;
};

#endif /* !_IMONITORDISPLAY_HPP_ */
