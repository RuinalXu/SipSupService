#include <fmt/base.h>

#include "common.h"
#include "log_manager.h"
#include "sip_local_config.h"


int main(int argc, char ** argv) {
    fmt::print("Hello SipSupService");

    // 忽略control+c的信号
    signal(SIGINT, SIG_IGN);
    
    loger::GlogInitializer glogInit(0);
    
    SipLocalConfig* config = new SipLocalConfig();

    int ret = config -> readConfig();

    fmt::print("ret = {}", ret);


    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    
    return 0;
}