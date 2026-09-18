#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

enum Status{
    OFFLINE = 0,
    IMPAIRED = 1,
    ACTIVE = 2
};

struct Component{
    std::string name;
    double weight;
    Status ComponentStatus;
};

class UAV{
    public:
        std::string name;
        int ID;
        Component components[5];
        int numberOfComponents;
};

std::string statusToString(Status s);
bool canFly(UAV uav);

int main(){

    bool userContinue;
    char userContinueChar;
    const int SIZE = 3;
    UAV Fleet[SIZE];
    int userChoice;
    std::string tempName;
    int tempID;
    Component tempUAVComponent;
    int numberOfComponents = 0;
    int fleetCount = 0;


    std::cout << "**********************************\n";
    std::cout << "****UAV Fleet Database Manager****\n";
    std::cout << "**********************************\n";





    // loop to check if user wants to continue
    do{

        std::cout << "Select an Option: \n";
        std::cout << "Create and add UAV: (1)\n";
        std::cout << "View the Fleet: (2)\n";
        std::cout << "Status overview of Fleet: (3)\n";
        std::cin >> userChoice;
        std::cin.ignore();

        //choose option based off user input
        switch(userChoice){
            case 1:

            int statusChoice;

            if(fleetCount >= SIZE){
                std::cout << "Fleet is full, cannot add another UAV.";
                break;
            }
                std::cout << "Enter the name of your UAV: ";
                std::getline(std::cin, tempName);
                std::cout << '\n';
                Fleet[fleetCount].name = tempName;

                std::cout << "Enter the ID number of your UAV: ";
                std::cin >> tempID;
                std::cout << '\n';
                Fleet[fleetCount].ID = tempID;

                std::cout << "How many components would you like on this UAV? (Max 5): ";
                std::cin >> numberOfComponents;
                Fleet[fleetCount].numberOfComponents = numberOfComponents;

                for(int i=0; i < numberOfComponents; i++){
                    std::cout << "Component " << i + 1 << " name: ";
                    std::cin >> Fleet[fleetCount].components[i].name;

                    std::cout << "Component " << i + 1 << " weight: ";
                    std::cin >> Fleet[fleetCount].components[i].weight;

                    std::cout << "Component " << i + 1 << " status (0 = OFFLINE, 1 = IMPAIRED, 2 = ACTIVE): ";
                    std::cin >> statusChoice;
                    while(statusChoice != 0 && statusChoice != 1 && statusChoice != 2){
                        std::cout << "Please enter a valid character (0, 1, or 2): ";
                        std::cin >> statusChoice;
                    }
                    Fleet[fleetCount].components[i].ComponentStatus = static_cast<Status>(statusChoice);
                }


                fleetCount++;
                break;
            case 2:
                std::cout << "VIEWING FLEET: \n";
                for (int i = 0; i < fleetCount; i++) {
                    std::cout << "UAV #" << i + 1 << " -\n";
                    std::cout << "Name: " << Fleet[i].name << "\n";
                    std::cout << "ID: " << Fleet[i].ID << "\n\n";
                    for (int j = 0; j <= fleetCount; j++) {
                        std::cout << "Component " << j + 1 << ": \n";
                        std::cout << "Name: " << Fleet[i].components[j].name << "\n";
                        std::cout << "Weight: " << Fleet[i].components[j].weight << "Kg" << "\n";
                        std::cout << "Status: " << statusToString(Fleet[i].components[j].ComponentStatus) << "\n\n";
                    }
                    std::cout << "# of Components: " << Fleet[i].numberOfComponents << "\n";
                }

                break;
            case 3:
                std::cout << "STATUS OVERVIEW OF FLEET:" << "\n";
                for (int i = 0; i < fleetCount; i++) {
                    for (int j = 0; j <= fleetCount; j++) {
                        std::cout << "UAV #" << i + 1 << " Component " << j + 1 << " status: " << statusToString(Fleet[i].components[j].ComponentStatus) << "\n";
                    }
                }

                for (int i = 0; i < fleetCount; i++) {
                    if (canFly(Fleet[i])) {
                        std::cout << "UAV #" << i + 1 << " is ready to fly!\n";
                    }
                    else {
                        std::cout << "UAV #" << i + 1 << " needs repairs.\n";
                    }
                }


                break;
            default:
                std::cout << "Please pick a valid option.\n";
                break;

        }


        std::cout << "Would you like to continue adding to or viewing the Fleet? Y or N: \n";
        std::cin >> userContinueChar;

        while(userContinueChar != 'Y' && userContinueChar != 'N'){
            std::cout << "Please enter a valid character.\n";
            std::cout << "Would you like to continue adding to or viewing the Fleet? Y or N: \n";
            std::cin >> userContinueChar;
        }
        if(userContinueChar == 'Y'){
            userContinue = true;
        }
        else if(userContinueChar == 'N'){
            userContinue = false;
            std::cout << "**********Goodbye!*********\n";
        }
    } while(userContinue == true);



    // testing


}

// check if all components in one UAV are active status, and returns accordingly

bool canFly(UAV uav){
    for (int i = 0; i < uav.numberOfComponents; i++){
        if (uav.components[i].ComponentStatus != ACTIVE) {
            return false;
        }
    }
    return true;
}

// return printable values from enum Status

std::string statusToString(Status s) {
    switch (s) {
        case OFFLINE:
            return "OFFLINE";
            break;
        case IMPAIRED:
            return "IMPAIRED";
            break;
        case ACTIVE:
            return "ACTIVE";
            break;
        default:
            return "UNKNOWN";
            break;
    }
}


/* need to add: change status
 *                other stuff idk
 *                total weight
 *
 *
 *
 *
 *
 */