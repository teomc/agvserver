﻿#ifndef MSGCENTER_H
#define MSGCENTER_H

#include <QObject>
#include <QThread>

//这里将会启动一个CPU个数*2的线程，用于处理用户的数据
//保证并发量和响应时间





class MsgCenter : public QObject
{
    Q_OBJECT
public:
    explicit MsgCenter(QObject *parent = nullptr);

    void init();
    QByteArray taskControlCmd(int agvId,bool changeDirect);
signals:

public slots:

private:
    QByteArray auto_instruct_stop(int rfid,int delay);
    QByteArray auto_instruct_forward(int rfid,int speed);
    QByteArray auto_instruct_backward(int rfid,int speed);
    QByteArray auto_instruct_turnleft(int rfid,int speed);
    QByteArray auto_instruct_turnright(int rfid,int speed);
    QByteArray auto_instruct_mp3_left(int rfid,int mp3Id);
    QByteArray auto_instruct_mp3_right(int rfid, int mp3Id);
    QByteArray auto_instruct_mp3_volume(int rfid, int volume);
    QByteArray auto_instruct_wait();
};

#endif // MSGCENTER_H
