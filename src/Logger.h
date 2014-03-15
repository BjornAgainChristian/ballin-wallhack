#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <fstream>

#include "Globals.h"

class Logger
{
	public:
		Logger(string logfile);
		~Logger();

		void Log(string words);

	private:
		ofstream Output;

};

#endif
