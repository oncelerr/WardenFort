#include "loginsession.h"

loginsession::loginsession() {

}

void loginsession::sessionStart(const QString name){
    this->username = name;
}

void loginsession::sessionEnd(){
    username = NULL;
}
