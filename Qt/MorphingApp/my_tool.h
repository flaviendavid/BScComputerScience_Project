#ifndef MY_TOOL_H
#define MY_TOOL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QVector>

class my_tool : public QLabel
{
    Q_OBJECT
public:
    explicit my_tool(QWidget *parent = 0);
    ~my_tool();

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    //void paintEvent(QPaintEvent *e);

    int x,y;
    QVector <int> Coord_X;
    QVector <int> Coord_Y;

signals:
    void Sig_Mouse_Pressed();
    void Sig_pos();
    void Sig_Mouse_Left();
};

#endif // MY_TOOL_H
