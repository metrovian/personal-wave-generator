#include "BowStringLP.h"

BowStringLP::BowStringLP(double _namp, double _freq, double _dura, unsigned int _srate, unsigned short _sbit)
{
    synthesis(_namp, _freq, _dura, _srate, _sbit);
}

bool BowStringLP::synthesis(double _namp, double _freq, double _dura, unsigned int _srate, unsigned short _sbit)
{
    setWaveHeader(_srate, _sbit);

    WaveData dat(calcWaveDataSize(_dura, _srate));
    DelayData train = calcBandLimDelayLine(_namp, _freq, band);

    if (train.size() > 0)
    {
        DelayData proc1 = passStringPositionCF(train, pos);
        DelayData proc2;
        
        dat[0] = 0;
        for (unsigned long long i = 1; i < dat.size(); ++i)
        {
            //dat[i] = passDynamicLPF(proc1, dat[i - 1], _freq);
            //dat[i] = passAutoRegressionLPC(proc1, 40);
            dat[i] = proc1.front();

            proc1.push(proc1.front());
            proc1.pop();
        }
    }

    setWaveData(passAutoRegressionLPC(dat, 40));
    return true;
}
