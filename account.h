#pragma once
#include "intstr.h"
#include "Mtime.h"
#include <stdlib.h>
int cmd, withdraw, diposite, total;
string check,tot,wit,dip;
string totl,witl,dipl;///last();
string outing;
fstream file2,filel;
out()
{
    file2.close();
    for(int fl=1;fl>0;fl++)
    {
        file2.open("account.txt", ios::in);
        if(file2.is_open())
        {
            GotoLine(file2,2);
            file2>>outing;
            check=" ";
            GotoLine(file2,fl);
            file2>>check;

            //cout<<check<<endl<<fl;
            if(check[0]=='T')
            {
                tot=check.substr(1,check.size()-1);
            }
            else if(check[0]=='W')
            {
                wit=check.substr(1,check.size()-1);
            }
            else if(check[0]=='D')
            {
                dip=check.substr(1,check.size()-1);
            }
            else if(check[0]=='-'){}
            else{break;}
        }file2.close();
    }file2.close();

}
last()
{
    filel.close();
    for(int fl=1;fl>0;fl++)
    {
    filel.open("account.txt", ios::in);
        if(filel.is_open())
        {
            check=" ";
            GotoLine(filel,fl);
            filel>>check;
            if(check[0]=='T'){totl=check.substr(1,check.size()-1);}
            else if(check[0]=='W'){witl=check.substr(1,check.size()-1);}
            else if(check[0]=='D'){dipl=check.substr(1,check.size()-1);}
            else if(check[0]=='-'){}
                else{break;}
        }filel.close();
    }
    SetConsoleTextAttribute(hh,9);cout<<"BALANCE:";
    SetConsoleTextAttribute(hh,11);cout<<totl<<endl;
    SetConsoleTextAttribute(hh,9);cout<<"LAST WITHDRAW:";
    SetConsoleTextAttribute(hh,11);cout<<witl<<endl;
    SetConsoleTextAttribute(hh,9);cout<<"LAST DIPOSITE:";
    SetConsoleTextAttribute(hh,11);cout<<dipl<<endl;

}
changes()
{
    while(t!=-1)
{
    system("cls");
    SetConsoleTextAttribute(hh,10);cout<<"0:QUIT"<<endl<<"1:DIPOSITE"<<endl<<"2:WITHDRAW"<<endl<<"3:HISTORY"<<endl;
    tim();
    dip="";tot="";wit="";str="";
    last();
    out();
    string cmdc;
    cout<<'>';cin>>cmdc;
    if(cmdc=="1")
    {
        SetConsoleTextAttribute(hh,10);cout<<"DIPOSITE:";
        file2.open("account.txt", ios::app);
        if(file2.is_open())
        {
            //cout<<outing;
            if(outing[0]!='T')
            {
                SetConsoleTextAttribute(hh,11);cin>>diposite;
                int_str(diposite);
                dip=str;
                file2<<'-'<<sfdate<<'['<<sftime<<']'<<endl;
                file2<<'T'<<dip<<endl;
                SetConsoleTextAttribute(hh,15);cout<<"ACCOUNT CREAED";
            }

            if(outing[0]=='T')
            {

                SetConsoleTextAttribute(hh,11);cin>>diposite;

                int_str(diposite);dip=str;
                file2<<'-'<<sfdate<<'['<<sftime<<']'<<endl<<"D"<<dip<<endl;
                total=str_int(tot);
                total=total+diposite;
                int_str(total);tot=str;
                file2<<'T'<<tot<<endl;
                SetConsoleTextAttribute(hh,15);cout<<"YOUR CURRENT BALANCE:"<<tot<<endl;
            }
        }file2.close();
    }

    else if(cmdc=="2")
    {
        SetConsoleTextAttribute(hh,10);cout<<"WITHDRAW:";
        file2.open("account.txt", ios::app);
        if(file2.is_open())
        {
            SetConsoleTextAttribute(hh,11);cin>>withdraw;
            int_str(withdraw);wit=str;
            file2<<'-'<<sfdate<<'['<<sftime<<']'<<endl<<"W"<<wit<<endl;
            total=str_int(tot);
            if(total>withdraw)
            {
                total=total-withdraw;
                int_str(total);tot=str;
                file2<<'T'<<tot<<endl;

            }
            if(total<withdraw)
            {
                total=(total-withdraw)*-1;
                int_str(total);tot=str;
                file2<<"T-"<<tot<<endl;
            }

            SetConsoleTextAttribute(hh,15);cout<<"YOUR CURRENT BALANCE:"<<tot<<endl;
        }file2.close();
    }

    else if(cmdc=="3")
    {
        SetConsoleTextAttribute(hh,10);cout<<"INFORMATION"<<endl;
        file2.open("account.txt", ios::in);
        if(file2.is_open())
        {
            getline(file2,outing);
            SetConsoleTextAttribute(hh,15);cout<<"ACCOUNT CREATED :"<<outing.substr(1,outing.size()-1)<<endl;
        }file2.close();

        SetConsoleTextAttribute(hh,10);cout<<"CURRENT BALANCE:";
        SetConsoleTextAttribute(hh,11);cout<<totl<<endl;
        for(int fl=2;fl>0;fl++)
    {
        file2.open("account.txt", ios::in);
        if(file2.is_open())
        {

            check=" ";
            GotoLine(file2,fl);
            file2>>check;
            if(check[0]=='T'){}
            else if(check[0]=='-')
            {
                SetConsoleTextAttribute(hh,15);
                string ime=check.substr(1,check.size()-1);
                cout<<ime<<endl;
            }

            else if(check[0]=='W')
            {
                wit=check.substr(1,check.size()-1);

                SetConsoleTextAttribute(hh,12);cout<<"WITHDRAW:";
                SetConsoleTextAttribute(hh,11);cout<<wit<<endl;
            }
            else if(check[0]=='D')
            {
                dip=check.substr(1,check.size()-1);

                SetConsoleTextAttribute(hh,9);cout<<"DIPOSITE:";
                SetConsoleTextAttribute(hh,11);cout<<dip<<endl;
            }
            else{break;}
        }file2.close();
    }
    }
    else if(cmdc=="0"){break;}
    else{SetConsoleTextAttribute(hh,15);cout<<"WRONG COMMAND...";}//cout<<total<<diposite<<withdraw<<endl;
    system("pause>null");
}
}
