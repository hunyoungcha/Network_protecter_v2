#include "ini.hpp"

#include <condition_variable>
#include <thread>
#include <mutex>


class CPhishingCheck{
    public:

    private:
        std::condition_variable phishingCV;
        std::mutex phishingMutex;
        
};