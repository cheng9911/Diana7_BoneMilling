#pragma once
#include "DianaAPIDef.h"
#include "DianaAPI.h"
#include <cstring>
#include <iostream>
#include <sri/ftsensor.hpp>
#include <sri/commethernet.hpp>
class platmotion
{
private:
    /* data */
public:
    platmotion(/* args */);
    ~platmotion();
    double x;
    double y;
    double z;
    double mx;
    double mz;
    double my;
    double gravity=9.81;
    SRI::FTSensor *sensor;
    const char *strIpAddress = "192.168.100.75";
    srv_net_st *pinfo;
    std::vector<double> K;
    std::vector<double> M;
    std::vector<double> B;
    std::vector<double> pose_stop;
    std::vector<double> ZeroOffset;
    

};

platmotion::platmotion(/* args */)
{
}

platmotion::~platmotion()
{
}
