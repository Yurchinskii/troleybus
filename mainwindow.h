#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>

class MainWindow : public QMainWindow {
	Q_OBJECT
	public:
		MainWindow();
		
	protected:

		void paintEvent(QPaintEvent *event);


	private slots:

	private:
		QLabel *position;
		QPushButton *openButton;
};
#endif
