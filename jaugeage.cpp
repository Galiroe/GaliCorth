#include "jaugeage.h"


jaugeage::jaugeage(QDateTime jStartDate, double jHeight, double jFlow)
{
    m_jStartDate = jStartDate;
    m_jHeight = jHeight;
    m_jFlow = jFlow;
}

jaugeage::~jaugeage() {
}

QDateTime jaugeage::getStartDate () const {
    return m_jStartDate;
}

double jaugeage::getHeight () const {
    return m_jHeight;
}

double jaugeage::getFlow () const {
    return m_jFlow;
}
