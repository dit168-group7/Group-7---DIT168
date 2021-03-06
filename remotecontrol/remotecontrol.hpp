#ifndef REMOTE_CONTROL
#define REMOTE_CONTROL

#include <cstdint>
#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>


#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"

#include "messages.hpp"

static const int INTERNAL_CHANNEL = 181;

// groupid specifies which car to send the follow request to
static const int INTERNAL_FOLLOW_REQUEST = 4000;

// The follow response indicates 
// 1. Which group the follow request was sent to and 
// 2. If the request was successful (1), or unsuccessful (0)
static const int INTERNAL_FOLLOW_RESPONSE = 4001;

// Stop follow needs to point out which car to send it to, if empty both follower and leader will receive it
static const int INTERNAL_STOP_FOLLOW_REQUEST = 4002;

// Follow response will indicate which car was sent the stop follow message
static const int INTERNAL_STOP_FOLLOW_RESPONSE = 4003;

// Send message to announce our own presence in the network
static const int INTERNAL_ANNOUNCE_PRESENCE = 4007;

// Send this message to V2V in order to get all announced cars
static const int INTERNAL_GET_ALL_GROUPS_REQUEST = 4004;

/* The get all groups response will contain the groupid of a car in the network.
   Upon the V2V receiving a get all groups request, V2V will send one message per
   announced car in the network. */
static const int INTERNAL_GET_ALL_GROUPS_RESPONSE = 4005;

// Emergency brake should tell all services to stop sending commands to the motor and steering.
static const int INTERNAL_EMERGENCY_BRAKE = 4006;

class remoteControl{

	
private:

	std::shared_ptr<cluon::OD4Session> InternalChannel;

};


#endif
