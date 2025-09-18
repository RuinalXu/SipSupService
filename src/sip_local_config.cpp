#include "sip_local_config.h"

#define CONFIG_FILE_PATH "config/SipSupService.conf"
#define LOCAL_SECTION "localserver"
#define SIP_SECTION "sipserver"

static const std::string keyLocalIp      = "local_ip";
static const std::string keyLocalPort    = "local_port";
static const std::string keySipId        = "sip_id";
static const std::string keySipIp        = "sip_ip";
static const std::string keySipPort      = "sip_port";
static const std::string keySipRealm     = "sip_realm";
static const std::string keySipUsr       = "sip_usr";
static const std::string keySipPwd       = "sip_pwd";
static const std::string keyRtpPortBegin = "rtp_port_begin";
static const std::string keyRtpPortEnd   = "rtp_port_end";

static const std::string keySubNodeNum   = "subnode_num";
static const std::string keySubNodeId    = "sip_subnode_id";
static const std::string keySubNodeIp    = "sip_subnode_ip";
static const std::string keySubNodePort  = "sip_subnode_port";
static const std::string keySubNodePoto  = "sip_subnode_poto";
static const std::string keySubNodeAuth  = "sip_subnode_auth";

SipLocalConfig::SipLocalConfig()
: m_conf(CONFIG_FILE_PATH) {
    m_localIp = "";
    m_localPort = 0;
    m_sipId = "";
    m_sipIp = "";
    m_sipPort = 0;
    m_usr = "";
    m_pwd = "";
    m_sipRealm = "";
    m_subNodeIp = "";
    m_subNodePort = 0;
    m_subNodePoto = 0;
    m_subNodeAuth = 0;
    m_rtpPortBegin = 0;
    m_rtpPortEnd = 0;
}

SipLocalConfig::~SipLocalConfig(){}

int SipLocalConfig::readConfig() {
    int ret = 0;
    m_conf.setSection(LOCAL_SECTION);
    m_localIp = m_conf.readStr(keyLocalIp);
    if(m_localIp.empty())
    {
        ret = -1;
        LOG(ERROR)<<"localIp is wrong";
        return ret;
    }
    
    return ret;
}
