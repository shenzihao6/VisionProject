#include "MSettings.h"

MSettings::MSettings(){

}

MSettings::~MSettings(){

}

MSettings::MSettings(const MSettings &rhs){


}

MSettings& MSettings::operator=(const MSettings &rhs){
    return *this;
}

bool MSettings::operator == (const MSettings &rhs){
    return true;
}

bool MSettings::operator !=(const MSettings &rhs){
     return !(*this == rhs);
}
