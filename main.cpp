#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main()
{
    std::ifstream participantsFile{"participants.txt"};
    std::string participant;
    std::vector<std::string> participants;

    std::random_device random_device;
    std::mt19937 random_number_generator{random_device()};

    while(participantsFile >> participant)
        participants.emplace_back(std::move(participant));

    std::vector partners{participants};

    std::shuffle(partners.begin(), partners.end(), random_number_generator);

    for(std::size_t i = 0; i < participants.size(); ++i)
        if(participants[i] == partners[i])
            std::rotate(partners.rbegin(), partners.rbegin() + 1, partners.rend());

    std::ofstream output{"draw.txt"};
    for(std::size_t i = 0; i < participants.size(); ++i)
    {
        std::cout << "Couple #" << i + 1 << ": " << participants[i] << " " << partners[i] << std::endl;
        output << "Couple #" << i + 1 << ": " << participants[i] << " " << partners[i] << std::endl;
    }
}
