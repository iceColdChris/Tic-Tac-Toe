
#include <time.h>
#include "Board.h"

#ifndef AI_H
#define AI_H

template<typename T>
class AI
{
public:
	AI();
	~AI() {};
	void turnDecision(T&);

private:
	void doCornerStart(T&);
	void doCenterStart(T&);
	void doEdgeStart(T&);
	
};
#endif
