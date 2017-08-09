#include <ctime>
#include <fstream>
#include "Module.hpp"

int     Module::my_str_cmp(char const *str, char const *str1)
{
  int   i;

  i = 0;
  while(str[i] != '\0')
    {
      if (str[i] != str1[i])
	return (1);
      i = i + 1;
    }
  return (0);
}

std::string             Module::getRamtotal()
{
  std::ifstream file;
  std::string line;

  file.open("/proc/meminfo");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  if (this->my_str_cmp("MemTotal", line.c_str()) == 0)
	    break;
	}
    }
  file.close();
  return line;
}

std::string             Module::getRamfree()
{
  std::ifstream file;
  std::string line;

  file.open("/proc/meminfo");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  if (this->my_str_cmp("MemFree", line.c_str()) == 0)
	    break;
	}
    }
  file.close();
  return line;
}

std::string             Module::getRamavailable()
{
  std::ifstream file;
  std::string line;

  file.open("/proc/meminfo");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  if (this->my_str_cmp("MemAvailable", line.c_str()) == 0)
	    break;
	}
    }
  file.close();
  return line;
}

std::string             Module::getRamswap()
{
  std::ifstream file;
  std::string line;

  file.open("/proc/meminfo");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  if (this->my_str_cmp("SwapTotal", line.c_str()) == 0)
	    break;
	}
    }
  file.close();
  return line;
}

std::string Module::getHz(int nb)
{
  std::string	line;
  std::string	num;
  std::ifstream	file;
  int		cmp = 0;

  file.open("/proc/cpuinfo");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  if (this->my_str_cmp("cpu MHz", line.c_str()) == 0)
	    {
	      if (cmp == nb)
		break;
	      ++cmp;
	    }
	}
    }
  num = nb + 48;
  line.insert(3, num);
  file.close();
  return line;
}

Module::Module() : IMonitorModule()
{
  std::cout << this->machine_name << std::endl;
}

std::string	Module::getNbCore()
{
  std::string line;
  std::ifstream file;

  file.open("/proc/cpuinfo");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  if (this->my_str_cmp("cpu cores", line.c_str()) == 0)
	    break;
	}
    }
  file.close();
  return line;
}

std::string	Module::getModel()
{
  std::string line;
  std::ifstream file;

  file.open("/proc/cpuinfo");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  if (this->my_str_cmp("model name", line.c_str()) == 0)
	    break;
	}
    }
  file.close();
  return line;
}


std::string	Module::getMachine()
{
  std::ifstream file("/proc/sys/kernel/hostname", std::ios::in);
  if (file)
    {
      std::string str;
      getline(file, str);
      this->machine_name = str;
      file.close();
    }
  else
    this->machine_name = "";
  return (this->machine_name);
}

std::string	Module::getUser()
{
  this->user_name = getenv("USER");
  return (this->user_name);
}

std::string	Module::getOp()
{
  std::ifstream file("/proc/sys/kernel/ostype", std::ios::in);
  if (file)
    {
      std::string str;
      getline(file, str);
      this->op_sys = str;
      file.close();
    }
  else
    this->op_sys = "";
  return (this->op_sys);
}

std::string	Module::getKernel()
{
  std::ifstream file("/proc/version", std::ios::in);
  if (file)
    {
      std::string str;
      getline(file, str);
      str.erase(str.find('('));
      this->v_kernel = str;
      file.close();
    }
  else
    this->v_kernel = "";
  return (this->v_kernel);
}

char*	Module::getDate()
{
  time_t temps;
  struct tm datetime;

  time(&temps);
  datetime = *localtime(&temps);
  strftime(this->date, 35, "%Y-%m-%d %H-%M-%S", &datetime);
  return (this->date);
}

std::string     Module::getNet()
{
  std::ifstream file;
  std::string line;

  file.open("/proc/net/dev");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  int	i = 0;
	  int	count = 0;
	  while (line[i])
	    {
	      if ((line[i] >= '0' && line[i] <= '9') && (line[i - 1] == ' ' || line[i - 1] == '\t'))
		{
		  count += 1;
		  if (count == 2)
		    {
		      std::string save;
		      while (line[i] != ' ')
			save += line[i++];
		      this->setWtransmit(save);
		    }
		  if (count == 10)
		    {
		      std::string save1;
		      while (line[i] != ' ')
			save1 += line[i++];
		      this->setWrec(save1);
		      break;
		    }
		}
	      i += 1;
	    }
	  if (my_str_cmp("  wlo1", line.c_str()) == 0)
	    {
	      file.close();
	      line.erase(line.find(':'));
	      break;
	    }
	}
    }
  return (line);
}

std::string	Module::getLo()
{
  std::ifstream file;
  std::string line;

  file.open("/proc/net/dev");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  int i = 0;
	  int count = 0;
	  while (line[i])
	    {
	      if ((line[i] >= '0' && line[i] <= '9') && (line[i - 1] == ' ' || line[i - 1] == '\t'))
		{
		  count += 1;
		  if (count == 2)
		    {
		      std::string save;
		      while (line[i] != ' ')
			save += line[i++];
		      this->setLoTransmit(save);
		    }
		  if (count == 10)
		    {
		      std::string save1;
		      while (line[i] != ' ')
			save1 += line[i++];
		      this->setLoRec(save1);
		      break;
                    }
		}
	      i += 1;
	    }
	  if (my_str_cmp("    lo", line.c_str()) == 0)
	    break;
	}
    }
  file.close();
  line.erase(line.find(':'));
  return (line);
}

void		Module::setLoTransmit(std::string save)
{
  this->Lotrans = save;
}

void		Module::setETransmit(std::string save)
{
  this->Etrans = save;
}

void		Module::setWtransmit(std::string save)
{
  this->Wtrans = save;
}

void		Module::setLoRec(std::string save)
{
  this->Lorece = save;
}

void		Module::setWrec(std::string save)
{
  this->Wrec = save;
}

void		Module::setErec(std::string save)
{
  this->Erece = save;
}

std::string		Module::getLoTransmit() const
{
  return (this->Lotrans);
}

std::string		Module::getETransmit() const
{
  return (this->Etrans);
}

std::string		Module::getWtransmit() const
{
  return (this->Wtrans);
}

std::string		Module::getLoRec() const
{
  return (this->Lorece);
}

std::string		Module::getWrec() const
{
  return (this->Wrec);
}

std::string		Module::getErec() const
{
  return (this->Erece);
}


std::string	Module::getEnp()
{
  std::ifstream file;
  std::string line;

  file.open("/proc/net/dev");
  if (file)
    {
      while (!file.eof())
	{
	  std::getline(file, line);
	  int	i = 0;
	  int	count = 0;
	  while (line[i])
	    {
	      if ((line[i] >= '0' && line[i] <= '9') && line[i - 1] == ' ')
		{
		  count += 1;
		  if (count == 2)
		    {
		      std::string save;
		      while (line[i] != ' ')
			save += line[i++];
		      this->setETransmit(save);
		    }
		  if (count == 10)
		    {
		      std::string save1;
		      while (line[i] != ' ')
			save1 += line[i++];
		      this->setErec(save1);
		      break;
		    }
		}
	      i += 1;
	    }
	  if (my_str_cmp("enp0s25", line.c_str()) == 0)
	    break;
	}
    }
  file.close();
  line.erase(line.find(':'));
  return (line);
}
