#include "MSysInfo.h"

MSysInfo* MSysInfo::instance_ = nullptr;

MSysInfo::MSysInfo(){

}

MSysInfo::~MSysInfo(){
    if(nullptr != instance_){
        delete  instance_;
        instance_ = nullptr;
    }
}

MSysInfo* MSysInfo::Instance(){
    if(nullptr == instance_){
        instance_ = new MSysInfo;
    }
    return instance_;
}

void MSysInfo::Init(){

}

void MSysInfo::Open(){

}
