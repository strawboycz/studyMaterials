#pragma once

class IdManager
{
public:
	static int generateAnimalId();
	static int generateZooKeeperId();
private:
	static int lastAnimalID;
	static int lastZookeeperID;
};

