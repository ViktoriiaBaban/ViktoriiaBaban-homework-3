#include "job_object.h"

JobObject::JobObject(std::string name) {
    this->name = name;
}

std::string JobObject::getName() {
    return this->name;
}

JobObject::~JobObject() = default;

bool JobObject::operator==(JobObject otherJob) {
    return this->getName() == otherJob.getName();
}
