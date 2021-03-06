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
static const int DISTANCE_READING = 1039;


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


class VIZService {
public:
    VIZService(std::string ip, std::string groupId);


    std::string leaderIp;
    std::string followerIp;

private:

    std::string myIp;
    std::string myGroupId;
    
    std::shared_ptr<cluon::OD4Session>  motorBroadcast;
    std::shared_ptr<cluon::OD4Session>  visualisation;
    std::shared_ptr<cluon::OD4Session>  internalBroadCast;
    std::shared_ptr<cluon::OD4Session>  broadcast;
};

#endif // VISUALISATION
