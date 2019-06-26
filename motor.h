#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>

class Motor : public QObject{

    Q_OBJECT

public:
    Motor(): id_(0),vol_(0),cur_(0),spd_(0),acc_(0.1),setSpd_(0)
    {

    }


    ~Motor(){

    }
signals:
    void sendMoTorSpd(double spd,double acc);

public slots:
    void setSetSpeed(const double spd){
        this->setSpd_ = spd;
        emit sendMoTorSpd(setSpd_,acc_);
    }
    void setSpeed(const double spd){
        this->spd_ = spd;
    }
    void setCurrent(const double cur){
        this->cur_ = cur;
    }
    void setVoltage(const double vol){
        this->vol_ = vol;
    }
    void setAccelerate(const double acc){
        this->acc_ = acc;
        emit sendMoTorSpd(setSpd_,acc_);
    }
public:
    //设置速度
    double getSetSpeed() const{
        return this->setSpd_;
    }

    //实时速度
    double getSpeed() const{
        return this->spd_;
    }

    //电流
    double getCurrent() const{
        return this->cur_;
    }

    //电压
    double getVoltage() const{
        return this->vol_;
    }

    //ID
    bool setId(const uint id){
        this->id_ = id;
        return true;
    }
    uint getID() const{
        return this->id_;
    }
    //ACC
    double getAccelerate() const{
        return this->acc_;
    }


private:
    uint id_;
    double vol_;
    double cur_;
    double spd_;
    double acc_;
    double setSpd_;




};


#endif // MOTOR_H
