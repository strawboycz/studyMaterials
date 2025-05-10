#include "IdManager.h"
int IdManager::lastAnimalID = 0;
int IdManager::lastZookeeperID = 0;
int IdManager::generateAnimalId()
{
	return ++lastAnimalID;
}
int IdManager::generateZooKeeperId()
{
	return ++lastZookeeperID;
}
