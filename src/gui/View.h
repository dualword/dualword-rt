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

#ifndef GUI_VIEW_H_
#define GUI_VIEW_H_

#include <QGraphicsView>

class View : public  QGraphicsView {
	Q_OBJECT

public:
    View(QWidget * p = 0 );
	virtual ~View();

protected:
	void resizeEvent(QResizeEvent *event);


};

#endif /* GUI_VIEW_H_ */
