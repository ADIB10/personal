#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <limits>
#include <windows.h>
#include <vector>
#include <string>
#include "number.h"
#include "account.h"

using namespace std;

///coment
//test element

string c,line,nam,numb,pas,CC,CK;///info_out()
string number,pass;///login()
char comand;///login()
string RC,ID;///registration()
string per_cmd;

intro()
{
    SetConsoleTextAttribute(hh,10);
    cout<<"WELCOME TO ";SetConsoleTextAttribute(hh,12);cout<<"PERSONAL.IG\n";
    SetConsoleTextAttribute(hh,10);
    cout<<"HERE YOU CAN HAVE\n";
    SetConsoleTextAttribute(hh,11);
    cout<<"1:A CONTACT BOOK\n2:A ACCOUNT BOOK\n3:A PERSONAL DIARY\n\n";
    SetConsoleTextAttribute(hh,10);
    cout<<"PRESS ANY KEY TO CONTINUE";
    system("pause>null");system("cls");
}


registration()
{
    file.open("personal.txt", ios::app);if(file.is_open()){file.close();}
    file.open("account.txt", ios::app);if(file.is_open()){file.close();}
    file.open("personal.txt", ios::in);
    if(file.is_open())
    {
        getline(file,RC);
        if(RC[0]==NULL)
        {
            file2.open("personal.txt", ios::app);
            if(file2.is_open())
            {

            intro();
            while(t!=-1){
            SetConsoleTextAttribute(hh,10);cout<<"NAME: ";
            SetConsoleTextAttribute(hh,12);cin>>ID;
            SetConsoleTextAttribute(hh,10);cout<<"ID NUMBER: ";
            SetConsoleTextAttribute(hh,12);cin>>number;
            if(number.size()>5)
            {SetConsoleTextAttribute(hh,10);cout<<"PASSWPRD: ";
            SetConsoleTextAttribute(hh,12);cin>>pass;
            file2<<'['<<'"'<<ID<<'"'<<','<<'"'<<number<<'"'<<','<<'"'<<pass<<'"'<<']';
            break;}

            else{SetConsoleTextAttribute(hh,15);cout<<"INVALID ID NUMBER";break;}

            }
            }
        }file2.close();
    }file.close();
}


info_out()
{
    int R=0,sr=0,r=0;

    file.open("personal.txt", ios::in);
    if(file.is_open())
    {
        getline(file,numc);
        CC=numc;
        getline(file,numc);
        CC=CC+numc;
    }file.close();
    if(CC[CC.size()-1]==']')
        {
            file.open("personal.txt", ios::app);
            if(file.is_open())
            {
                file<<endl<<'O'<<endl;
            }file.close();
        }file.close();

    file.open("personal.txt", ios::in);
    if(file.is_open())
    {
    for(int n=1;n>0;n++)
    {
        getline(file,c);
        //cout<<c<<n;
if(c[0]==NULL){break;}

        if(c[0]=='[')
    {
        R=0,sr=0,r=0;
        for(int i=0;i<c.size();i++)
        {
        if(c[i]==','&&R==0){nam=c.substr(2,r-3);R=R+1;sr=i;i++;r=0;}
        if(c[i]==','&&R==1){numb=c.substr(sr+2,r-2);sr=i;i++;r=0;}
        if(c[i]==']'&&R==1){pas=c.substr(sr+2,r-2);break;}
        r=r+1;
        }
    }
    }file.close();
    }file.close();
    //cout<<nam<<numb<<pas;

    //cout<<endl<<c<<endl<<line[line.size()-1]<<endl<<line<<endl;
    file.open("personal.txt", ios::in);
    if(file.is_open())
    {
            for(int i=1;i>0;i++)
            {getline(file,numc);line=line+numc;if(numc[0]==NULL){break;}
        }//cout<<line;
        //cout<<"--"<<line[line.size()-1]<<endl;
        file.close();
    }
}


personalize()
{
    info_out();

    ID=nam;
    number=numb;
    pass=pas;
    system("cls");
    cout<<">>";cin>>per_cmd;
    if(per_cmd[0]=='1'){SetConsoleTextAttribute(hh,10);cout<<"NAME: ";SetConsoleTextAttribute(hh,12);cin>>ID;}
    if(per_cmd[1]=='1')
    {
        SetConsoleTextAttribute(hh,10);cout<<"ID NUMBER: ";SetConsoleTextAttribute(hh,12);cin>>number;
    }
    if(per_cmd[2]=='1'){SetConsoleTextAttribute(hh,10);cout<<"PASSWPRD: ";SetConsoleTextAttribute(hh,12);cin>>pass;}
    cout<<"DATA UPDATING...\n";
    file.open("personal.txt", ios::app);
    if(file.is_open())
    {
    file<<'['<<'"'<<ID<<'"'<<','<<'"'<<number<<'"'<<','<<'"'<<pass<<'"'<<']'<<endl;
    file.close();
    }
    Sleep(200);
    cout<<"PROCESS FINISH";
}


logout()
{
        SetConsoleTextAttribute(hh,15);
        if(line[line.size()-1]=='O'){cout<<"ALREADY LOGOUT";}
        if(line[line.size()-1]!='O')
        {
            file.open("personal.txt", ios::app);
            if(file.is_open())
            {
                file<<"O"<<endl;
                SetConsoleTextAttribute(hh,15);
                cout<<"LOGOUT SUCCESSFUL";
                file.close();
            }
        }
}


login()
{
    SetConsoleTextAttribute(hh,10);
    cout<<"1:LOGIN"<<endl<<"2:LOGOUT"<<endl;
    int a=line.size()-1;
    cout<<'>';cin>>comand;
    if(comand=='1')
    {
        SetConsoleTextAttribute(hh,15);
        if(line[line.size()-1]=='L'){cout<<"ALREADY IN"<<endl;}
        if(line[line.size()-1]!='L')
        {
            SetConsoleTextAttribute(hh,10);cout<<"NUMBER: ";SetConsoleTextAttribute(hh,12);cin>>number;
            SetConsoleTextAttribute(hh,10);cout<<"PASSWORD: ";SetConsoleTextAttribute(hh,12);cin>>pass;
            SetConsoleTextAttribute(hh,15);
            if(number==numb&&pass==pas){cout<<"WELCOME["<<nam<<"]";

            file.open("personal.txt", ios::app);
            if(file.is_open())
            {
                file<<"L"<<endl;
                file.close();
                SetConsoleTextAttribute(hh,15);
            }}else{cout<<"ACCESS DENIED";}
        }
    }

    if(comand=='2'){logout();}
}


acc_info()
{
    info_out();
    SetConsoleTextAttribute(hh,10);cout<<"PASSWORD: ";SetConsoleTextAttribute(hh,12);cin>>pass;
    if(pass==pas)
    {
        SetConsoleTextAttribute(hh,10);cout<<"ACCOUNT NAME :";
        SetConsoleTextAttribute(hh,11);cout<<nam<<endl;
        SetConsoleTextAttribute(hh,10);cout<<"PASSWORD :";
        SetConsoleTextAttribute(hh,11);cout<<pas<<endl;
        SetConsoleTextAttribute(hh,10);cout<<"ID NO :";
        SetConsoleTextAttribute(hh,11);cout<<numb<<endl;
    }
}


after_log()
{
    registration();
    SetConsoleTextAttribute(hh,11);
    cout<<"0:LOG OUT"<<endl<<"1:PHONE BOOK"<<endl<<"2:BANK DETAILS"<<endl<<"3:ACCOUNT INFO"<<endl<<"4:PERSONALIZE"<<endl;
    SetConsoleTextAttribute(hh,12);
    cout<<">>";SetConsoleTextAttribute(hh,11);cin>>comand;
    if(comand=='0'){logout();}
    else if(comand=='1'){phone();}
    else if(comand=='2'){changes();}
    else if(comand=='3'){acc_info();}
    else if(comand=='4'){personalize();}
    else{SetConsoleTextAttribute(hh,15);
    cout<<"WRONG COMMAND...";}
    file.open("personal.txt", ios::app);
            if(file.is_open()&&comand!='0')
            {file<<'L'<<endl;
            }file.close();
}


int main()
{
    int t=0;
    while(t!=-1)
    {
       // personalize();
        system("cls");
        info_out();
        registration();
        if(line[line.size()-1]=='O'){login();}
        if(line[line.size()-1]=='L')
            {SetConsoleTextAttribute(hh,15);cout<<"WELCOME["<<nam<<"]"<<endl;after_log();}
        system("pause>null");
    }

    return 0;
}
