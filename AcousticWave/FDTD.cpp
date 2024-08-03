#include "FDTD.h"

bool FDTD::setBasicCondition(double _wspeed, double _length, double _period, unsigned long long _numx, unsigned long long _numt)
{
    if (_length < 0) return false;
    if (_period < 0) return false;
    if (_wspeed < 0) return false;
    if (_numx == 0) return false;
    if (_numt == 0) return false;
    
    length = _length;
    period = _period;
    wspeed = _wspeed;
    numx = _numx;
    numt = _numt;

    dx = length / (double)numx;
    dt = period / (double)numt;

    courant = wspeed * dt / dx;

    wave.resize(numt);
    for (auto& psi : wave)
    {
        psi.resize(numx);
    }

    if (courant < 1.0) return true;
    return false;
}

WaveFunction FDTD::castWaveFunction(double _namp, double _inspt, unsigned int _srate, unsigned short _sbit)
{
    WaveFunction ret;
    WaveData dat;
    unsigned long long idx = (unsigned long long)((double)numx * _inspt);
    double ramp = _namp * pow(2.0, (double)_sbit - 1.0);

    assert(idx < numx);

    double sfreq = 1.0 / dt;
    double sinc = sfreq / (double)_srate;

    for (double i = 0; i < (double)numt; i = i + sinc)
    {
        dat.push_back((short)(ramp * wave[(unsigned long long)i][idx]));
    }

    ret.setWaveFunction(dat, _srate, _sbit);

    return ret;
}
