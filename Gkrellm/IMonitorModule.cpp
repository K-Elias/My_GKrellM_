#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule()
{
  this->user = true;
  this->machine = true;
  this->date = true;
  this->kernel = true;
  this->os = true;
  this->cpu = true;
  this->ram = true;
  this->net = true;
}

void	IMonitorModule::setUser()
{
  if (this->user == true)
    this->user = false;
  else
    this->user = true;
}

void	IMonitorModule::setMachine()
{
  if (this->machine == true)
    this->machine = false;
  else
    this->machine = true;
}

void	IMonitorModule::setDate()
{
  if (this->date == true)
    this->date = false;
  else
    this->date = true;
}

void	IMonitorModule::setKernel()
{
  if (this->kernel == true)
    this->kernel = false;
  else
    this->kernel = true;
}

void	IMonitorModule::setOs()
{
  if (this->os == true)
    this->os = false;
  else
    this->os = true;
}

void	IMonitorModule::setCPU()
{
  if (this->cpu == true)
    this->cpu = false;
  else
    this->cpu = true;
}

void	IMonitorModule::setRAM()
{
  if (this->ram == true)
    this->ram = false;
  else
    this->ram = true;
}


void	IMonitorModule::setNet()
{
  if (this->net == true)
    this->net = false;
  else
    this->net = true;
}

bool	IMonitorModule::getUs() const
{
  return (this->user);
}

bool	IMonitorModule::getMa() const
{
  return (this->machine);
}

bool	IMonitorModule::getOS() const
{
  return (this->os);
}

bool	IMonitorModule::getKe() const
{
  return (this->kernel);
}

bool	IMonitorModule::getDa() const
{
  return (this->date);
}

bool	IMonitorModule::getRAM() const
{
  return (this->ram);
}

bool	IMonitorModule::getCPU() const
{
  return (this->cpu);
}

bool	IMonitorModule::getNET() const
{
  return (this->net);
}
