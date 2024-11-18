#include "main.hpp"


int main(){
    // CConfigDB IConfigDB;
    // CFirewall IFirewall(IConfigDB);

    CQueueManager IQueueManager;
    CPacketHandler IPacketHander(IQueueManager);
    CPhishingCheck IPhishingCheck(IQueueManager);

    IPacketHander.GetDeviceName();
    std::thread phishingThread(&CPhishingCheck::tmp, &IPhishingCheck);

    IPacketHander.RunPacketCapture();
    

    return 0;
}