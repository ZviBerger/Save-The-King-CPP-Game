#pragma once
#include "PlayersObj.h"

class Giant :public PlayersObj
{
public:
	using PlayersObj::PlayersObj;
	virtual void go2(const Direction &direction, Board &brd)override;
	bool notAloud(std::string objName);
};

