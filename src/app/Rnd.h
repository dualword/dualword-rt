/*
    DualWord-RT : https://github.com/dualword/dualword-rt

    Copyright (C) 2015-2024 Alexander Busorgin

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

#ifndef RND_H_
#define RND_H_

#include <random>
#include <chrono>

using namespace std;

class Rnd {
public:
	Rnd(const int& min, const int& max ) :
		dist(min, max),
		eng(chrono::high_resolution_clock::now().time_since_epoch().count()){

	};
	virtual ~Rnd() {};
	inline int operator() () { return dist(eng);};

private:
	uniform_int_distribution<int> dist;
	mt19937 eng;
};

#endif /* RND_H_ */
