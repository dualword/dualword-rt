/*
    DualWord-RT : https://github.com/dualword/dualword-rt

    Copyright (C) 2015-2025 Alexander Busorgin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TIME_H_
#define TIME_H_

#include <chrono>

using namespace std::chrono;

class Time {

public:
	Time() : t1(), t2(), stopped(false) {};
	virtual ~Time() {};
    inline void start() {t1 = high_resolution_clock::now(); };
    inline void stop() {t2 = high_resolution_clock::now(); stopped = true; };
    inline bool isStopped() {return stopped; };
    inline void reset(){stopped = false;};
    inline int elapsedMilli() { return duration_cast<milliseconds>(t2-t1).count(); };

private:
    time_point<high_resolution_clock> t1,t2;
    bool stopped;

};

#endif /* TIME_H_ */
