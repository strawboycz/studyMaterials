#pragma once
#include "Habitat.h"

class OutdoorHabitat : public Habitat
{
public:
	string toString() override;
private:
	string biome;
};
