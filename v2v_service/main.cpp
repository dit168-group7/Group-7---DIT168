#include <iostream>
#include <set>
#include "v2v/v2v.hpp"
#include <map>


using namespace std;
int main(int /*argc*/, char** /*argv*/) {
    shared_ptr<V2VService> v2vService = make_shared<V2VService>();
    
    
    while (true) {
        unsigned int choice;
        cout << "Which message would you like to send?" << std::endl;
        cout << "(1) AnnouncePresence" << std::endl;
        cout << "(2) FollowRequest" << std::endl;
        cout << "(3) FollowResponse" << std::endl;
        cout << "(4) StopFollow" << std::endl;
        cout << "(5) LeaderStatus" << std::endl;
        cout << "(6) FollowerStatus" << std::endl;
        cout << "(7) AnnouncedIps" << std::endl;
        cout << "(#) Nothing, just quit." << std::endl;
        cout << ">> ";
        cin >> choice;
        
        
        map<std::string, std::string> myMap = v2vService->getMapOfIps();
        
        
        
        //set<string> ips = v2vService->getAnnouncedIps();
        map<std::string, std::string>::iterator it;
        unsigned int index = 1;
        switch (choice) {
            case 1: v2vService->announcePresence(); break;
            case 2:
                if (myMap.size() < 1) {
                    cout << "There are no IPs to choose from, wait for someone to announce themselves!" << endl;
                    break;
                }
                
                cout << "Which vehicle would you like to follow?" << endl;
                for(std::map<std::string, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
                    cout << "(" << index << ") " << it->first << " " << it->second << endl;
                    index++;
                }
                cin >> choice;
                if (choice > myMap.size()) break;

                it = myMap.begin();
                while (true) {
                    choice--;
                    if (choice == 0) break;
                    ++it;
                }

                cout << "You chose: " << it->first << endl;

                v2vService->followRequest(it->second);

                break;
            case 3: v2vService->followResponse(); break;
            case 4: v2vService->stopFollow(); break;
            case 5: v2vService->leaderStatus(50, 0, 100); break;
            case 6: v2vService->followerStatus(50, 0, 10, 100); break;
            case 7:
                for(std::map<std::string, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
                    cout << it->first << " " << it->second << endl;
                }
                break;
            default: return 0;
        }
    
    }
}
