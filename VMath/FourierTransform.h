#pragma once
#include "WaveFunction.h"

#include <cmath>
#include <complex>
#include <vector>

typedef std::vector<std::complex<double>> FourierData;
class FourierFunction : public WaveFunction
{
protected: /* data */
	FourierData fdata;

public: /* constructor */
	FourierFunction(const WaveFunction& _wave);

protected: /* parts */
	bool fft();
	bool ifft();
	double getFrequency(unsigned long long _idx) const;

public: /* public use */
	bool setLPF(double _freq, double _brate);
	bool setHPF(double _freq, double _brate);
	bool setBPF(double _freq1, double _freq2, double _brate);

	bool exportWaveSpectrum(const std::string& _fname) const;
};