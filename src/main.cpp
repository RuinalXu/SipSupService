#include <signal.h>
#include <filesystem>

#include <glog/logging.h>
#include <fmt/base.h>

#include "common.h"

#define LOG_DIR "./logs"
#define LOG_GILE_NAME "SipServer.log"


class SetGlogLevel{
public:
    SetGlogLevel(const int type) {
        // 将日志重定向到指定文件中
        google::InitGoogleLogging(LOG_GILE_NAME);
        // 创建日志目录
        std::filesystem::create_directories(LOG_DIR);
        // 设置输出到控制台的log等级
        FLAGS_stderrthreshold = type;
        FLAGS_colorlogtostderr = true;
        FLAGS_logbufsecs = 0;
        FLAGS_log_dir = LOG_DIR;
        FLAGS_max_log_size = 4;
        google::SetLogDestination(google::GLOG_WARNING, "");
        google::SetLogDestination(google::GLOG_ERROR, "");
        signal(SIGPIPE, SIG_IGN);
    }
    ~SetGlogLevel(){
        google::ShutdownGoogleLogging();
    }
};


int main(int argc, char ** argv) {

    // 忽略control+c的信号
    signal(SIGINT, SIG_IGN);

    SetGlogLevel glog(0);
    LOG(INFO) << "==> this is INFO glog";
    LOG(WARNING) << "==> this is WARNING glog";
    LOG(ERROR) << "==> this is ERROR glog";
    fmt::print("Hello SipSupService");

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    
    return 0;
}