#pragma once
#include "PlayersObj.h"


class Mage :public PlayersObj
{
public:
	using PlayersObj::PlayersObj;
	virtual void go2(const Direction &direction, Board &brd)override;
};

