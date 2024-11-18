#include "main.hpp"


int main(){
    CConfigDB IConfigDB;
    // CFirewall IFirewall(IConfigDB);
    CQueueManager IQueueManager;
    CPacketHandler IPacketHander(IQueueManager);

    IPacketHander.GetDeviceName();
    IPacketHander.RunPacketCapture();
    
    return 0;
}