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

#include "MainWindow.h"
#include "DualwordRT.h"
#include "global.h"

MainWindow::MainWindow(QWidget *p) : QMainWindow(p), scene(), rand(RT_DMIN,RT_DMAX),
	msg(""){

	setWindowTitle(qApp->applicationName());
    statusBar();
    statusBar()->setSizeGripEnabled(false);
	glview.setScene( &scene );
    glview.setContextMenuPolicy(Qt::CustomContextMenu);
	connect(&glview,SIGNAL(customContextMenuRequested(const QPoint)),
			this,SLOT(contextMenuRequested(QPoint)));

	menu = new QMenu(&glview);
	menu->addSeparator();
	toggle = new QAction(menu);
	toggle->setText(tr("Toggle Full Screen"));
	connect(toggle,SIGNAL(triggered()),this,SLOT(fullScreen()));
	menu->addAction(toggle);
	menu->addSeparator();
	about = new QAction(menu);
	about->setText(tr("About"));
	menu->addAction(about);
	connect(about,SIGNAL(triggered()),this,SLOT(showAbout()));
	setCentralWidget(&glview);
    stateNew();
}

MainWindow::~MainWindow() {

}

void MainWindow::init(){

}

void MainWindow::fullScreen() {
	setWindowState(this->windowState() ^ Qt::WindowFullScreen);
	statusBar()->setVisible(!statusBar()->isVisible());
}

void MainWindow::closeEvent(QCloseEvent *event){
	timer->stop();
    event->accept();
}

void MainWindow::contextMenuRequested(QPoint p){
	menu->popup(mapToGlobal(p));
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	if(! (event->key() == Qt::Key_Q || event->key() == Qt::Key_P) ){
		QMainWindow::keyPressEvent(event);
		return;
	}

	if (state == State::new1){
		stateWait();
	}else if (state == State::wait){
		if( event->key() == Qt::Key_Q){
			tL.stop();
		}else  if( event->key() == Qt::Key_P){
			tR.stop();
		}
		if(tL.isStopped() & tR.isStopped()) stateDone();
	}else if (state == State::notready){
		stateNotReady();
	}
    QMainWindow::keyPressEvent(event);
}

void MainWindow::stateNew(){
	tL=Time(),tR=Time();
	pause = 0;
	state = State::new1;
	scene.printMsg(tr("Press P or Q to start..."));
}

void MainWindow::stateWait(){
	state = State::notready;
	scene.printMsg(tr("Press 2 buttons (P and Q) when you see a yellow circle..."));
    timer.reset(new QTimer());
    timer->setTimerType(Qt::PreciseTimer);
	timer->setSingleShot(true);
    connect(timer.get(), SIGNAL(timeout()), this, SLOT(stateVisual()));
	pause = rand() * 1000;
	timer->start(pause);
}

void MainWindow::stateVisual(){
	scene.showCirle();
	state = State::wait;
	tL.start(), tR.start();
}

void MainWindow::stateDone(){
	tL.reset();
	tR.reset();
	state = State::new1;
    data.append(dat{tL.elapsedMilli(), tR.elapsedMilli()});
    int minl=RT_MAX, minr=RT_MAX, maxl=0, maxr=0, avrgl=0, avrgr=0;
    foreach (const auto& d, data) {
        if(d.left < minl) minl = d.left;
        if(d.right < minr) minr = d.right;
        if(d.left > maxl) maxl = d.left;
        if(d.right > maxr) maxr = d.right;
        avrgl += d.left;
        avrgr += d.right;
    }

    QString msg;
    msg.append("Reaction time: Left hand = " + QString::number(tL.elapsedMilli()) + " ms. ");
    msg.append("Right hand = " + QString::number(tR.elapsedMilli()) + " ms.\n");
    msg.append("               Press P or Q to continue.\n");
    msg.append("Attempts:" + QString::number(data.size()));
    msg.append(" Min:"+QString::number(minl)+"/"+QString::number(minr));
    msg.append(" Max:"+QString::number(maxl)+"/"+QString::number(maxr));
    msg.append(" Average:"+QString::number(avrgl/data.size())+"/"+QString::number(avrgr/data.size()) + " (L/R)");
    scene.printMsg(msg);
}

void MainWindow::stateNotReady(){
	timer->stop();
	state = State::new1;
	scene.printMsg(tr("Error.\nPress P or Q to continue..."));
}

void MainWindow::showAbout(){
	QString str;
	str.append(qApp->applicationName());
	str.append(" ").append(qApp->applicationVersion()).append("<br>");
	str.append("License: GPL v3 <br/>");
	str.append("Website: <a href='http://github.com/dualword/dualword-rt'>Dualword-RT</a> <br/>");
    str.append("&copy;2015-2024 Alexander Busorgin <br/>");
	QMessageBox::about(this, tr("About"), str );
}
