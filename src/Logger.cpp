#include "Logger.h"

Logger(string logfile)
{
	Output.open(logfile.c_str());
}

~Logger()
{
	Output.close();
}

void Logger:Log(string words)
{
	Output << words << endl;
}
