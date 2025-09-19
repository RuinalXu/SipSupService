#include <fmt/base.h>

#include "common.h"
#include "log_manager.h"
#include "sip_local_config.h"
#include "global_controller.h"

int main(int argc, char ** argv) {
    fmt::print("Hello SipSupService\n");

    // 忽略control+c的信号
    signal(SIGINT, SIG_IGN);
    
    loger::GlogInitializer glogInit(0);
    
    SipLocalConfig* config = new SipLocalConfig();
    int ret = config -> readConfig();
    if (ret == -1) {
        LOG(ERROR) << "read config error";
        return ret;
    }
    bool re = GlobalController::instance() -> init(config);
    if (re == false) {
        LOG(ERROR) << "init error";
        return -1;
    }
    LOG(INFO) << GBOJ(g_config) -> localIp();

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    
    return 0;
}