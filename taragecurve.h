#ifndef TARAGECURVE_H
#define TARAGECURVE_H

#include <QVector>

class tarageCurve
{
public:
    tarageCurve();
    tarageCurve(int curveNumber);
    void loadPoints (int curveNumber);
    double getSlopeCoeff (double flow);
    double getSlopeOrigin (double flow);

private:
    int m_curveNumber;
    QVector<double> m_XHeigth;
    QVector<double> m_YFlow;
    QVector<double> m_slopeCoeff;
    QVector<double> m_slopeOrigin;

    void slopeCoeffGener (int curveNumber);
    void slopeOriginGener (int curveNumber);
};

#endif // TARAGECURVE_H
