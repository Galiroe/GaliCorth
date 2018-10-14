#ifndef JAUGEAGE_H
#define JAUGEAGE_H

#include <QDateTime>

class jaugeage
{
public:
    jaugeage(QDateTime jStartDate, double jHeight,double jFlow);
    ~jaugeage();
    QDateTime getStartDate () const;
    double getHeight () const;
    double getFlow () const;

//    void setStartDate (QDateTime jStartDate);
//    void setHeight (double jHeigth);
//    void setFlow (double jFlow);

private:
    QDateTime m_jStartDate;
    double m_jHeight;
    double m_jFlow;
};

#endif // JAUGEAGE_H
