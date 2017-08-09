#ifndef _MODULE_HPP_
# define _MODULE_HPP_

#include <string>
#include <iostream>
#include "IMonitorModule.hpp"

class		Module : public IMonitorModule
{
private:
  std::string	core;
  std::string	machine_name;
  std::string	user_name;
  std::string	op_sys;
  std::string	v_kernel;
  char		date[35];
  std::string	Etrans;
  std::string	Lotrans;
  std::string	Wtrans;
  std::string	Erece;
  std::string	Lorece;
  std::string	Wrec;
public:
  Module();
  virtual ~Module() {};
  std::string	getNet();
  std::string	getLo();
  std::string	getEnp();
  std::string	getRamtotal();
  std::string	getRamfree();
  std::string	getRamavailable();
  std::string	getRamswap();
  std::string	getNbCore();
  std::string	getHz(int);
  std::string	getModel();
  std::string   getMachine();
  std::string   getUser();
  std::string   getOp();
  std::string   getKernel();
  char*		getDate();
  int		my_str_cmp(char const *, char const *);
  void		setLoTransmit(std::string save);
  void		setETransmit(std::string save);
  void		setWtransmit(std::string save);
  void		setLoRec(std::string save);
  void		setWrec(std::string save);
  void		setErec(std::string save);
  std::string   getLoTransmit() const;
  std::string   getETransmit() const;
  std::string   getWtransmit() const;
  std::string   getLoRec() const;
  std::string   getWrec() const;
  std::string   getErec() const;
};

#endif /* !_MODULE_HPP_*/
