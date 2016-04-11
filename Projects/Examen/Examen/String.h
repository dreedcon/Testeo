#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

class String{

public:

	char* string;
	int size;


public:

	//constructores\\
		
	String()
	{
		size = 1;
		string = new char[1];
		string[0] = '\0';
	}

	String(const String& _string)
	{
		//strlen:cuenta los caracteres que hay dentro del string
		size = strlen(_string.string) + 1;
		string = new char[size];
		strcpy_s(string, size, _string.string);

	}

	String(const char *format)
	{
		size = 0;
		if (format != NULL)
		{
			static char tmp[4096];
			static va_list ap;
			// Construct the string from variable arguments
			va_start(ap, format);
			int res = vsprintf_s(tmp, 4096, format, ap);
			va_end(ap);
			if (res > 0)
			{
				size = res + 1;
				string = new char[res + 1];
				strcpy_s(string, size, tmp);
			}
		}
		if (size == 0)
		{
			size = 1;
			string = new char[1];
			clear();
		}
	}

	// destructor\\
		
	~String(){ delete[] string; }

	//methods\\

	bool operator== (const String& a)
	{
		//strcmp: compara dos cadenas
		if (strcmp(string, a.string) == 0){

			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!= (const String& a)
	{
		if (strcmp(string, a.string) != 0){

			return true;
		}
		else
		{
			return false;
		}
	}


	bool operator== (const char* a)
	{

		if (strcmp(string, a) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!= (const char* a)
	{

		if (strcmp(string, a) != 0){

			return true;
		}
		else
		{
			return false;
		}
	}

	String operator= (const String& a)
	{

		if (size > strlen(a.string) + 1)
		{
			strcpy_s(string, size, a.string);
		}
		else
		{
			delete[] string;
			string = new char[strlen(a.string) + 1];
			size = strlen(a.string) + 1;
			strcpy_s(string, size, a.string);
		}
		return (*this);
	}

	String operator= (const char* a)
	{
		if (size > strlen(a) + 1)
		{
			strcpy_s(string, size, a);
		}
		else
		{
			delete[] string;
			string = new char[strlen(a) + 1];
			size = strlen(a) + 1;
			strcpy_s(string, size, a);
		}
		return (*this);
	}

	String operator+= (const String& a)
	{
		String tmp(*this);
		delete[] string;
		string = new char[size + strlen(a.string)];
		size = size + strlen(a.string);
		strcpy_s(string, size, tmp.string);
		strcat_s(string, size, a.string);
		return (*this);
	}

	String operator+= (const char* a)
	{
		String tmp(*this);
		delete[] string;
		string = new char[size + strlen(a)];
		size = size + strlen(a);
		strcpy_s(string, size, tmp.string);
		strcat_s(string, size, a);
		return(*this);
	}

	int lenght()
	{
		return strlen(string);
	}

	int capacity()
	{
		return size - 1;
	}

	//getter\\
		
	char* getstring() const{ return string; }

	void clear()
	{
		strcpy_s(string, size, "");
	}

	/*
	void Trim()const
	{

		//turnright cut
		bool a;
		while (a == true)
		{
			for (int i = size - 1; i < 0 && a == false; i--)
			{
				if (string[i] = ' ')
				{
					string[i] = '\0';
					a = false;
				}
				else if (string[i] != ' ')
					a = true;
			}
		}

		//turnleft  cut
		bool a;
		while (a == true)
		{
			for (int z = 0; z < size - 1; z++)
			{
				if (string[z] == ' ')
				{
					string[z] = '\0';

				}
				else if (string[z] != ' ')
					a = false;
			}
		}


	}
	*/

};