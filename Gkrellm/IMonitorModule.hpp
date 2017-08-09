#ifndef _IMONITORMODULE_HPP_
# define _IMONITORMODULE_HPP_

class		IMonitorModule
{
private:

  bool                          user;
  bool                          machine;
  bool                          date;
  bool                          kernel;
  bool                          os;
  bool                          cpu;
  bool                          ram;
  bool                          net;

public:
  IMonitorModule();
  virtual ~IMonitorModule() {};

  void setUser();
  void setMachine();
  void setDate();
  void setKernel();
  void setOs();
  void setCPU();
  void setRAM();
  void setNet();
  bool getUs() const;
  bool getMa() const;
  bool getDa() const;
  bool getKe() const;
  bool getOS() const;
  bool getCPU() const;
  bool getRAM() const;
  bool getNET() const;
};

#endif /* _IMONITORMODULE_HPP_ */
