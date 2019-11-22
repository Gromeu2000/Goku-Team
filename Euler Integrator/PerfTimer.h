#ifndef __PERFTIMER_H__
#define __PERFTIMER_H__

#include "p2Defs.h"

class PerfTimer
{
public:

	// Constructor
	PerfTimer();

	void Start();
	double ReadMs() const;
	uint ReadTicks() const;

private:
	uint	started_at;
	static uint frequency;
};

#endif //__PERFTIMER_H__