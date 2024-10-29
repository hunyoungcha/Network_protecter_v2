#include "main.hpp"


int main(){
    CConfigDB IConfigDB;
    // CFirewall IFirewall(IConfigDB);
    CPacketHandler IPacketHander;

    IPacketHander.GetDeviceName();
    IPacketHander.RunPacketCapture();
    
    return 0;
}