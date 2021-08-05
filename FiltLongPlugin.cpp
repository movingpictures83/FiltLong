#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FiltLongPlugin.h"


void FiltLongPlugin::input(std::string file) {
	 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);

 ifile >> fastqGZfile; // kmer length
  while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   if (key.length() != 0)
   parameters[key] = value;
 }
}

void FiltLongPlugin::run() {
   
}

void FiltLongPlugin::output(std::string file) {
	 std::string outputfile = file;
	 //iltlong --min_length 1000 --mean_q_weight 10 --keep_percent 90 --target_bases 500000000 preLongReads.fastq.gz | gzip > LongReads.fastq.gz
	 std::string command = "filtlong ";
	 std::map<std::string, std::string>::iterator i;
	 for (i = parameters.begin(); i != parameters.end(); i++) {
		 command += "--";
	         command += i->first;
		 command += " ";
		 command += i->second;
		 command += " ";
	 }
         command += std::string(PluginManager::prefix())+"/"+fastqGZfile;
	 command += " | gzip > ";
         command += file;
	 std::cout << command << std::endl;
	 system(command.c_str());
}

PluginProxy<FiltLongPlugin> FiltLongPluginProxy = PluginProxy<FiltLongPlugin>("FiltLong", PluginManager::getInstance());
