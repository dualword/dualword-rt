/*
	DualWord-RT : http://github.com/dualword/dualword-rt

	Copyright (C) 2015 Alexander Busorgin

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

#ifndef DUALWORDRT_H_
#define DUALWORDRT_H_

#include <QApplication>
#include <QScopedPointer>

class MainWindow;

class DualwordRT : public QApplication {
    Q_OBJECT

public:
	DualwordRT(int &argc, char **argv);
	virtual ~DualwordRT();
    static DualwordRT *instance() {return (static_cast<DualwordRT *>(QCoreApplication::instance()));};

public Q_SLOTS:
	void start();

private:
	QScopedPointer<MainWindow> win;

};

#endif /* DUALWORDRT_H_ */
