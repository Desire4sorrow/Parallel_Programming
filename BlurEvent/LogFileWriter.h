#pragma once
#include <ostream>
#include <fstream>
#include "IncludedElements.h"
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

class LogWriter
{

public:
	LogWriter()
	{
		out = std::ofstream("loggerOut.txt");
	}

	void WriteLogs(LinkedList& memoryBuffer)
	{
		for (auto it : memoryBuffer)
		{
			out << it;
		}

		out << "Буфер заполнен, очистка буфера\n";
		memoryBuffer.Clear();
	}

private:
	std::ofstream out;
};