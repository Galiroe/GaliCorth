#include "taragecurve.h"

tarageCurve::tarageCurve() {
     m_curveNumber = -1;
     m_XHeigth = QVector<double> (0);
     m_YFlow = QVector<double> (0);
     m_slopeCoeff = QVector<double> (0);
     m_slopeOrigin = QVector<double> (0);
}

tarageCurve::tarageCurve(int curveNumber) {
    m_curveNumber = curveNumber;
    //Chargement des points de la courbe n°"curveNumber" depuis la base bareme
    loadPoints (m_curveNumber);
    //Coefficients a calculer a partir des points de la courbe
    slopeCoeffGener (m_curveNumber);
    slopeOriginGener (m_curveNumber);
}

void tarageCurve::loadPoints (int curveNumber) {
    m_XHeigth = QVector<double> (0);
    m_YFlow = QVector<double> (0);
}

double tarageCurve::getSlopeCoeff (double flow) {

}

double tarageCurve::getSlopeOrigin (double flow) {

}

void slopeCoeffGener (int curveNumber) {
    m_slopeCoeff = QVector<double> (0);
}

void slopeOriginGener (int curveNumber) {
    m_slopeOrigin = QVector<double> (0);
}
