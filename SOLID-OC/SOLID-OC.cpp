// SOLID-OC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class IGrade {
public:
    virtual void setGrade(int gradeValue) = 0;
    virtual int getGradeValue() = 0;
    virtual std::string getGradeString() = 0;
    virtual void setSubject(std::string newSubjectName) = 0;
    virtual std::string getSubject() = 0;
};

class AbstractGrade : IGrade {
private:    
    std::string subjectName;
protected:
    int numericGradeValue;

public:
    
    void setGrade(int gradeValue) override {
        numericGradeValue = gradeValue;
    };
    
    int getGradeValue() override {
        return numericGradeValue;
    };

    void setSubject(std::string newSubjectName) override {
        subjectName = newSubjectName;
    };

    std::string getSubject() override { 
        return subjectName; 
    };

    virtual std::string getGradeString() = 0;
};

class btec60CreditL3Grade : public AbstractGrade {

private:
    std::string  getBtecGrade() {
        if (numericGradeValue == 16) return "D";
        if (numericGradeValue == 10) return "M";
        if (numericGradeValue == 6) return "P";
        if (numericGradeValue == 0) return "U";

        return "Invalid Grade";
    };

public:
    std::string getGradeString() override {
        return getBtecGrade();
    }

};

class bscGrade : public AbstractGrade {

private:

    std::string  getBscGrade() {
        if (numericGradeValue >= 70) return "1st";
        if (numericGradeValue >= 60) return "2.1";
        if (numericGradeValue >= 50) return "2.2";
        if (numericGradeValue >= 40) return "3rd";
        if (numericGradeValue >= 35) return "Grade decided at the exam board";
        if (numericGradeValue >= 0) return "Fail";

        return "Invalid Grade";
    };

public:
    std::string getGradeString() override {
        return getBscGrade();
    }

    void setGrade(float gradeValue) {
        AbstractGrade::setGrade(static_cast<int>(ceil(gradeValue)));
    };
};


int main() {
    btec60CreditL3Grade btec;
    bscGrade bsc;

    btec.setSubject("Computer Games Programming");
    btec.setGrade(16);

    bsc.setSubject("OOP - Object Oriented Programming");
    bsc.setGrade(55.7);

    std::cout << std::setw(40)
              << btec.getSubject() << "\tGrade " 
              << btec.getGradeString() << std::endl;

    std::cout << std::setw(40)
              << bsc.getSubject() << "\tGrade " 
              << bsc.getGradeString() << std::endl;

    return 0;
};