#pragma once
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <Eigen/Dense>

enum class MODE
{
	TRANSVERSE_ELECTRIC,
	TRANSVERSE_MAGNETIC,
};

class WaveField
{
private: /* data */
	Eigen::Vector3d** field;

private: /* config */
	MODE mode;
	double lenx;
	double leny;
	unsigned long long numx;
	unsigned long long numy;

private: /* derived */
	double dx;
	double dy;

public: /* constructor */
	WaveField(MODE _mode, double _lenx, double _leny, unsigned long long _numx, unsigned long long _numy);
	~WaveField();

private: /* memory */
	bool mallocWaveField();
	bool clear();
	bool check(unsigned long long _idx, unsigned long long _idy) const;

public: /* public use */
	bool setField(Eigen::Vector3d _field, unsigned long long _idx, unsigned long long _idy);

	Eigen::Vector3d getField(unsigned long long _idx, unsigned long long _idy);
	Eigen::Vector3d getPoyntingVector(unsigned long long _idx, unsigned long long _idy);
};