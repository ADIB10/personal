#pragma once
#include<ctime>
#include"intstr.h"
string sfdate,sftime;
void tim()
{
    time_t now;
    struct tm nowloc;
    now=time(NULL);
    nowloc=*localtime(&now);
    int day,mon,year,minit,seco,hour;
    day=nowloc.tm_mday;
    mon=nowloc.tm_mon+1;
    year=nowloc.tm_year+1900;
    minit=nowloc.tm_min;
    seco=nowloc.tm_sec;
    hour=nowloc.tm_hour;
    ///cout<<day<<"/"<<mon<<"/"<<year<<endl;
    ///cout<<hour<<":"<<minit<<":"<<seco<<endl;
    string sday,smon,syear,sminit,sseco,shour;
    int_str(day);
    sday=str;
    int_str(mon);
    smon=str;
    int_str(year);
    syear=str;
    int_str(minit);
    sminit=str;
    int_str(seco);
    sseco=str;
    int_str(hour);
    shour=str;
    sfdate=sday+'/'+smon+'/'+syear;
    sftime=shour+':'+sminit+':'+sseco;
    ///cout<<sday<<"/"<<smon<<"/"<<syear<<endl;
    ///cout<<shour<<":"<<sminit<<":"<<sseco<<endl;
}
