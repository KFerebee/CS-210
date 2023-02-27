// Name        : ClockProj1KendallFerebee.cpp
// Author      : Kendall Ferebee
// SNHU Class  : CS210
// Description : 12 and 24 hour clock in C++


#define _CRT_SECURE_NO_WARNINGS		// <-- define "_CRT_SECURE_NO_WARNINGS" te resolve 02 Errors I kept recieving 

#include<iostream>
#include<ctime>
#include<iomanip>


using namespace std;

class time_sim {	// Time inputs 
public:
	int hour;
	int minute;
	int seconds;
};

class hours_12_format :public time_sim {	// 12 hour clock format 
public:
	string meridian;
	hours_12_format()
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);
		hour = ltm->tm_hour;
		minute = ltm->tm_min;
		seconds = ltm->tm_sec;
		if (hour >= 12)
		{
			meridian = "P M";
			hour -= 12;
		}
		else
			meridian = "A M";

	}

	void add_hour(int h)
	{
		hour += h;
		if (hour > 12)
		{
			hour -= 12;
		}
		else if (hour >= 12)
		{
			if (meridian == "A M")
			{
				meridian = "P M";
			}
			else if (meridian == "P M")
			{
				meridian = "A M";
			}
		}

	}
	void add_minute(int min)
	{
		minute += min;
		if (minute >= 60)
		{
			int h = minute / 60;
			minute -= 60 * h;
			add_hour(h);
		}
	}

	void add_seconds(int sec)
	{
		seconds += sec;
		if (seconds >= 60)
		{
			int m = seconds / 60;
			seconds -= 60 * m;
			add_minute(m);
		}
	}
};

class hours_24_format :public time_sim {		// 24 hour clock format 
public:											// Clock inputs 
	int hour;
	int minute;
	int seconds;
	hours_24_format()
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);
		hour = ltm->tm_hour;
		minute = ltm->tm_min;
		seconds = ltm->tm_sec;
	}
	void add_hour(int h)
	{
		hour += h;
		if (hour >= 24)
		{
			hour -= 24;
		}
	}
	void add_minute(int min)
	{
		minute += min;
		if (minute >= 60)
		{
			int h = minute / 60;
			minute -= 60 * h;
			add_hour(h);
		}
	}

	void add_seconds(int sec)
	{
		seconds += sec;
		if (seconds >= 60)
		{
			int m = seconds / 60;
			seconds -= 60 * m;
			add_minute(m);
		}
	}
};
