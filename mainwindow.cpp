#include <QtGui>
#include "mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QtWidgets>

const QString imagesDir = "images/";
const int squareWidth  = 60;
const int squareHeight = 60;

const int boardWidth = 8;
const int boardHeight = 8;

const int boardMarginX = 40;
const int boardMarginY = 100;


QString board[boardHeight][boardWidth] = {
	{"b5", "b2", "b0", "b4", "b1", "b0", "b2", "b5"},
	{"b3", "b3", "b3", "b3", "b3", "b3", "b3", "b3"},
	{"", "", "", "", "", "", "", ""},
	{"", "", "", "", "", "", "", ""},
	{"", "", "", "", "", "", "", ""},
	{"", "", "", "", "", "", "", ""},
	{"w3", "w3", "w3", "w3", "w3", "w3", "w3", "w3"},
	{"w5", "w2", "w0", "w4", "w1", "w0", "w2", "w5"}
};


MainWindow::MainWindow() {
	setWindowTitle(tr("Шахматы"));
	resize(560, 630);

	position = new QLabel(this);
	position->setGeometry(boardWidth * squareWidth + boardMarginX, boardHeight * squareHeight + boardMarginY, 100, 20);
}

void MainWindow::paintEvent(QPaintEvent *) {
	QPainter p(this);
	int color = 1;

	for (int i = 0; i < boardWidth; i++)
	{
		for (int j = 0; j < boardHeight; j++)
		{
			if (color)
				p.setBrush(Qt::lightGray);
			else
				p.setBrush(Qt::darkGreen);
			int sqX = boardMarginX + j * squareWidth;
			int sqY = boardMarginY + i * squareHeight;

			p.drawRect(sqX, sqY, squareWidth, squareHeight);

			if (board[i][j] != "") {
				QString image = imagesDir + board[i][j] + ".png";
				p.drawImage(sqX, sqY, QImage(image).scaled(squareWidth, squareHeight));
			}

			color = !color;
		}
		color = !color;
	}
}
