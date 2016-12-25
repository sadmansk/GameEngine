/*
   A test game engine with C++ and OpenGL
   Copyright (C) 2015  Sadman Kazi

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   */
#ifndef TIME_H_
#define TIME_H_

#include <ctime>
#include <chrono>

#define SECOND 1000000000


typedef std::chrono::high_resolution_clock clock_;

class Time
{
public:

    inline Time() {}

    inline static void reset() { beg_ = clock_::now(); }

    inline static long long elapsed() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(clock_::now() - beg_).count();
    }


    static inline void setDelta(double newDelta) { Time::delta = newDelta; };
    static inline double getDelta() { return Time::delta; }

    inline virtual ~Time() {}

private:
    static std::chrono::time_point<clock_> beg_; //save the starting time
    static double delta;
};

#endif // TIME_H_
