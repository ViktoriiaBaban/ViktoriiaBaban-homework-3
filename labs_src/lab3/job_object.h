#pragma once

#include <iostream>
#include <string>

class JobObject {
private:
    std::string name;
public:
    explicit JobObject(std::string name);
    std::string getName();
    bool operator==(JobObject otherJob);
    ~JobObject();
};
