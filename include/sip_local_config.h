#ifndef _SIP_LOCAL_CONFIG_H
#define _SIP_LOCAL_CONFIG_H

#include "config_reader.h"
#include "common.h"
#include <list>
#include <algorithm>
#include <queue>


class SipLocalConfig {
private:
    ConfigReader m_conf;
    std::string m_localIp;
    int m_localPort;
    std::string m_sipId;
    std::string m_sipIp;
    int m_sipPort;
    std::string m_usr;
    std::string m_pwd;
    std::string m_sipRealm;
    std::string m_subNodeIp;
    int m_subNodePort;
    int m_subNodePoto;
    int m_subNodeAuth;
    int m_rtpPortBegin;
    int m_rtpPortEnd;
public:
    SipLocalConfig();
    ~SipLocalConfig();
    int readConfig();
};


#endif