/*
	QTFFmpegWrapper Demo
	Copyright (C) 2009,2010:
			Daniel Roggen, droggen@gmail.com

	All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE FREEBSD PROJECT OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QVideoEncoder.h"
#include "QVideoDecoder.h"


namespace Ui {
	 class MainWindow;
}

class MainWindow : public QMainWindow {
	 Q_OBJECT
public:
	 MainWindow(QWidget *parent = 0);
	 ~MainWindow();

protected:
	 QVideoDecoder decoder;


	 void changeEvent(QEvent *e);

	 // Helper

	 void image2Pixmap(QImage &img,QPixmap &pixmap);

	 // Decoder demo
	 void displayFrame();
	 void loadVideo(QString fileName);
	 void errLoadVideo();
	 bool checkVideoLoadOk();
	 void nextFrame();

	 // Encoder demo
	 void GenerateSyntheticVideo(QString filename,bool vfr=false);


private:
	 Ui::MainWindow *ui;



private slots:
	 void on_actionSave_synthetic_video_triggered();
	 void on_pushButtonNextFrame_clicked();
	 void on_pushButtonSeekMillisecond_clicked();
	 void on_pushButtonSeekFrame_clicked();
	 void on_actionLoad_video_triggered();
	 void on_actionQuit_triggered();
	 void on_actionSave_synthetic_variable_frame_rate_video_triggered();
};

#endif // MAINWINDOW_H
