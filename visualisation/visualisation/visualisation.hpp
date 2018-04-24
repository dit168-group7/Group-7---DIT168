#ifndef VISUALISATION
#define VISUALISATION

#include <iomanip>
#include <cstdint>
#include <sys/time.h>
#include <map>
#include <string>
#include <pthread.h>

#include "cluon/OD4Session.hpp"
#include "cluon/UDPSender.hpp"
#include "cluon/UDPReceiver.hpp"
#include "cluon/Envelope.hpp"
#include "messages.hpp"

// V2V external
static const int BROADCAST_CHANNEL = 250;
static const int VISUALIZATION_CHANNEL = 182;
static const int DEFAULT_PORT = 50001;

static const int ANNOUNCE_PRESENCE = 1001;
static const int FOLLOW_REQUEST = 1002;
static const int FOLLOW_RESPONSE = 1003;
static const int STOP_FOLLOW = 1004;
static const int LEADER_STATUS = 2001;
static const int FOLLOWER_STATUS = 3001;

// STS internal
static const int INTERNAL_BROADCAST_CHANNEL = 181;

static const int INTERNAL_FOLLOW_REQUEST = 4000;
static const int INTERNAL_FOLLOW_RESPONSE = 4001;
static const int INTERNAL_STOP_FOLLOW_REQUEST = 4002;
static const int INTERNAL_STOP_FOLLOW_RESPONSE = 4003;
static const int INTERNAL_GET_ALL_GROUPS_REQUEST = 4004;
static const int INTERNAL_GET_ALL_GROUPS_RESPONSE = 4005;
static const int INTERNAL_EMERGENCY_BRAKE = 4006;
static const int INTERNAL_ANNOUNCE_PRESENCE = 4007;

// Motor Proxy
static const int MOTOR_BROADCAST_CHANNEL = 180;

static const int PEDAL_POSITION_READING = 1041;
static const int GROUND_STEERING_READING = 1045;


struct CarStatus {
    float speed;
    float steeringAngle;
    uint8_t distanceTraveled;
    uint8_t distanceFront;
};


class V2VService1 {
public:
    V2VService1(std::string ip, std::string groupId);


    std::string leaderIp;
    std::string followerIp;

    uint32_t lastFollowerUpdate;
    uint32_t lastLeaderUpdate;

private:


    std::map<std::string, std::string> mapOfIps;
    std::map<std::string, std::string> mapOfIds;

    std::string myIp;
    std::string myGroupId;
    
    std::shared_ptr<cluon::OD4Session>  motorBroadcast;
    std::shared_ptr<cluon::OD4Session>  visualisation;
    std::shared_ptr<cluon::OD4Session>  internalBroadCast;
    std::shared_ptr<cluon::OD4Session>  broadcast;
    
    std::shared_ptr<cluon::UDPReceiver> incoming;
    std::shared_ptr<cluon::UDPSender>   toLeader;
    std::shared_ptr<cluon::UDPSender>   toFollower;

    static std::pair<int16_t, std::string> extract(std::string data);
    template <class T>
    static std::string encode(T msg);
    template <class T>
    static T decode(std::string data);
};

#endif // VISUALISATION