#include "time.h"

std::chrono::time_point<clock_> Time::beg_ = clock_::now();
double Time::delta = 0;