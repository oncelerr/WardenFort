#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>

struct User {
    int userId = 1;
    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QString gender;
    QString dateOfBirth;
    QString phoneNumber;
    QString profilePic;
    QString email;
};

extern User loggedInUser;

#endif // GLOBALS_H
