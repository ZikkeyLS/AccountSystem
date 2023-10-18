#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <bitset>

class Utility 
{
public:
	static std::vector<std::string> split(const std::string& input, char split = ' ') {
        std::vector<std::string> elements = std::vector<std::string>();
        std::stringstream ss(input);
        std::string item;
        while (std::getline(ss, item, split)) {
            elements.push_back(item);
        }
        return elements;
    }

    static std::string textToBinary(std::string value) {
        std::string binaryString = "";
        for (char& _char : value) {
            binaryString += std::bitset<8>(_char).to_string();
        }
        return binaryString;
    }

    static std::string binaryToText(std::string str) {
        std::stringstream sstream(str);
        std::string output;
        while (sstream.good())
        {
            std::bitset<8> bits;
            sstream >> bits;
            char c = char(bits.to_ulong());
            output += c;
        }

        return output;
    }
};