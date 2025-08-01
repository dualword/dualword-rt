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

#ifndef GUI_SCENE_H_
#define GUI_SCENE_H_

#include <QtWidgets>
#include <memory>

class Scene  : public QGraphicsScene {
	Q_OBJECT

public:
	Scene(QObject *p = 0);
	Scene( qreal x, qreal y, qreal width, qreal height, QObject *p = 0);
	virtual ~Scene();
	void printMsg(const QString& str);
	void showCirle();

private:
	void setup();

    QScopedPointer<QGraphicsEllipseItem> dot, circle;
    QScopedPointer<QGraphicsSimpleTextItem> txt;

};

#endif /* GUI_SCENE_H_ */
