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

#include "Scene.h"

Scene::Scene( QObject *p) : QGraphicsScene(p) {
	setup();
}

Scene::Scene( qreal x, qreal y, qreal w, qreal hh, QObject *p) : QGraphicsScene(x,y,w,hh,p) {
	setup();
}

Scene::~Scene() {

}

void Scene::setup(){
	setBackgroundBrush(QBrush(QColor("#d4d4d4")));

	setSceneRect(0,0,600,400);

	int side = std::min(width(),height()) * 0.2;
	int left = width() / 2 - side/2, top = height() / 2 - side/2;

	circle.reset(new QGraphicsEllipseItem( QRect( left, top, side, side ),0));
	circle->setPen( QPen(Qt::black) );
	circle->setBrush( Qt::yellow );
	addItem(circle.data());
	circle->setVisible(false);

	side = std::min(width(),height()) * 0.01;
	left = width() / 2 - side/2, top = height() / 2 - side/2;
	dot.reset(new QGraphicsEllipseItem( QRect( left, top, side, side ),0));
	dot->setPen( QPen(Qt::black) );
	dot->setBrush( Qt::black );
	addItem(dot.data());

	ti.reset(new QGraphicsSimpleTextItem( "" ));
	ti->setPos(width() / 2 - ti->boundingRect().width() / 2,top);
	ti->setFont(QFont("Times", 18, QFont::Normal));
	addItem(ti.data());
	ti->setVisible(false);

}

void Scene::printMsg(const QString& str){
	circle->setVisible(false);
	ti->setVisible(true);
	ti->setText(str);

	ti->setPos(width() / 2 - ti->boundingRect().width() / 2,
			height()/2 + ti->boundingRect().height());

}

void Scene::showCirle(){
	circle->setVisible(true);
	circle->setZValue(1);
	ti->setVisible(false);
}
