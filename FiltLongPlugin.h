#ifndef FILTLONGPLUGIN_H
#define FILTLONGPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class FiltLongPlugin : public Plugin
{
public: 
 std::string toString() {return "FiltLong";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::string fastqGZfile;
 std::map<std::string, std::string> parameters;
};

#endif
