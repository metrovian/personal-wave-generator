#pragma once
#include "FDTD.h"

class TestFDTD : public FDTD
{
	// FDTD��(��) ���� ��ӵ�
	bool solve() override;
};