#include "fileReader.h"

enum class LO
{
    ORIGIN,
    DESTINATION,
    COLOR,
    TYPE
};

FileReader::FileReader(std::string file, Graph<char, Link>& graph)
{

    std::ifstream fileStreamIn(file);
    std::string line;
    for (int a1 = 0; std::getline(fileStreamIn, line); a1++) {
        //devide it into 2 on the white space

        std::istringstream iss(line);
        std::vector<std::string> result;

        for (std::string s; iss >> s;)
            result.push_back(s);


        try {
            //we may try to access something that doesn't exist
            if (a1 == 0) {
                //there should be two numbers
                this->stationCount = std::stoi(result[0]);
                this->connectionCount = std::stoi(result[1]);
            }
            else {
                //there should be "station type color station"
                //take the first char
                Color color;
                Transport transport;


                //transportation
                switch (result[(int)LO::TYPE][0]) {
                case 'H': 
                    transport = Transport::HORSE;
                    break;
                case 'C': 
                    transport = Transport::CABLECAR;
                    break;
                case 'T': 
                    transport = Transport::TROLLY;
                    break;
                case 'B':
                    transport = Transport::BUS;
                    break;
                default:
                    throw std::out_of_range("File Missing Info");
                }

                switch (result[(int)LO::COLOR][0]) {
                case 'R':
                    color = Color::RED;
                    break;
                case 'G':
                    color = Color::GREEN;
                    break;
                case 'B':
                    color = Color::BLUE;
                    break;
                default:
                    throw std::out_of_range("File Missing Info");
            }
                
                graph.addEdge(Link(color, transport), 
                    result[(int)LO::ORIGIN][0], 
                    result[(int)LO::DESTINATION][0]);
            }
        }
        catch (const std::out_of_range& oor){
            printf("Error reading file\n");
        }

    }

}

//returns the station count
unsigned int long long FileReader::satC()
{
    return this->stationCount;
}

//returns the connection count
unsigned int long long FileReader::conC()
{
    return this->connectionCount;
}
