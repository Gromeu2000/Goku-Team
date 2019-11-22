#ifndef __TIMER_H__
#define __TIMER_H__

#include "p2Defs.h"

class Timer
{
public:

	// Constructor
	Timer();

	void Start();
	uint Read() const;
	float ReadSec() const;

private:
	uint	started_at;
};

#endif //__TIMER_H__
