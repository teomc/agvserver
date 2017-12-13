﻿#ifndef MSGCENTER_H
#define MSGCENTER_H

#include <QObject>
#include <QThread>
#include "agvpositionpublisher.h"
#include "agvstatuspublisher.h"
#include "agvtaskpublisher.h"
#include "fileuploadserver.h"
//这里将会启动一个CPU个数*2的线程，用于处理用户的数据
//保证并发量和响应时间

enum AGV_HAND_TYPE{
    AGV_HAND_TYPE_STOP = 0,//停止移动
    AGV_HAND_TYPE_FORWARD = 0x1,//前进
    AGV_HAND_TYPE_BACKWARD = 0x2,//后退
    AGV_HAND_TYPE_TURNLEFT = 0x3,//左转
    AGV_HAND_TYPE_TURNRIGHT = 0x4,//右转
};

class MsgCenter : public QObject
{
    Q_OBJECT
public:
    explicit MsgCenter(QObject *parent = nullptr);
    ~MsgCenter();
    void init();

    bool addAgvPostionSubscribe(int subscribe);
    bool removeAgvPositionSubscribe(int subscribe);
    bool addAgvStatusSubscribe(int subscribe);
    bool removeAgvStatusSubscribe(int subscribe);
    bool addLogSubscribe(int subscribe,int agvId);
    bool removeLogSubscribe(int subscribe,int agvId = 0);
    bool addAgvTaskSubscribe(int subscribe);
    bool removeAgvTaskSubscribe(int subscribe);

    //上传文件，其功能主要用于设置背景图片
    void uploadFile(std::string _ip, int _port, QString _filename, int _length);

    QString downloadFile(std::string _ip, int _port, int &_length);
signals:

public slots:
    //文件上传结束
    void onUploadFinish(std::string _ip,int _port,QString _filename,QByteArray _data);
private:
    AgvPositionPublisher *positionPublisher;
    AgvStatusPublisher *statusPublisher;
    AgvTaskPublisher *taskPublisher;
    FileTransferServer *fileUploadServer;
};

#endif // MSGCENTER_H
