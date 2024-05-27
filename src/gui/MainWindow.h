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

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <memory>

#include "Time.h"
#include "Rnd.h"
#include "Scene.h"
#include "View.h"

using namespace std;

struct dat;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  enum State{new1,wait,done,notready};

    MainWindow(QWidget *p = 0);
	virtual ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *);

public slots:
	void stateVisual();
	void contextMenuRequested(QPoint);
	void showAbout();
	void init();
	
private slots:
	void fullScreen();

private:
	void stateNew();
	void stateWait();
	void stateDone();
	void stateNotReady();

	Scene scene;
	View glview;
    State state;
    Time tL, tR;
    QScopedPointer<QTimer> timer;
	QMenu  *menu;
	QAction *toggle, *info, *about;
	int pause;
	Rnd rand;
	QString msg;
    QVector<dat> data;

};

#endif /* MAINWINDOW_H_ */
