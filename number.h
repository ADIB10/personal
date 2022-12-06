#pragma once
#include<string>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
///stack overflow
fstream& GotoLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}
fstream file;
string name,num,kk,C; int t,s; bool n_line=true;///add
string numc,N,HH;int B,g;///see

HANDLE hh=GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x,int y)
{
    COORD coord={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

add()
{
    {t=1;
    while(t!=-1)
    {
        file.open("personal.txt", ios::in);
        if(file.is_open())
        {
            GotoLine(file,2);
            file>>kk;
            file.close();
        }
        if(kk[0]!=NULL){n_line=false;}
        name="";num="";
        SetConsoleTextAttribute(hh,10);cout<<"NAME: ";
        SetConsoleTextAttribute(hh,11);cin>>name;
        if(name=="Q"){break;}
        SetConsoleTextAttribute(hh,10);cout<<"NUMBER: ";
        SetConsoleTextAttribute(hh,11);cin>>num;
        s=12-name.size();
        if(name.size()<=12&&name.size()!=0){for(int i=0;i<=s;i++){name=name+' ';}}
        if(name.size()>12&&name.size()!=0){name=name.substr(0,12);}
        if(num.size()<11){cout<<"THE NUMBER IS INCORRECT"<<endl;}
        file.open("personal.txt", ios::app);
        if(file.is_open()&&num.size()==11)
        {
            if(n_line==true){file<<"\n";}
            file<<name<<num<<endl;
            file.close();
            cout<<"NUMBER ADDED"<<endl;
        }
    }
    }
}
see()
{
    file.close();
    g=0;
    file.open("personal.txt", ios::in);
    if(file.is_open())
    {
        getline(file,numc);
            for(int i=1;i>0;i++)
            {getline(file,numc);HH=HH+numc;if(numc[0]==NULL){break;}
            if(numc.size()>1&&numc[0]!='[')
            {numc=numc.substr(0,23);
            g++;
            SetConsoleTextAttribute(hh,15);
            if(g<10){cout<<g<<"  :";}if(g<100&&g>9){cout<<g<<" :";}if(g<1000&&g>99){cout<<g<<":";}
            if(g%2==0){SetConsoleTextAttribute(hh,9);}
            else{SetConsoleTextAttribute(hh,11);}
            cout<<numc<<endl;
            }
        }

    }file.close();

}
serch()
{
    g=0;
    string fnd;
    SetConsoleTextAttribute(hh,10);
    cout<<"SEARCH: ";cin>>fnd;
    file.open("personal.txt", ios::in);
    if(file.is_open())
    {
        getline(file,numc);
            for(int i=1;i>0;i++)
            {

                getline(file,numc);
                if(numc[0]==NULL){break;}
                int s=fnd.size();
                if(fnd==numc.substr(0,s))
                {
                    g=g+1;
                    if(g%2==0){SetConsoleTextAttribute(hh,10);}
                    else{SetConsoleTextAttribute(hh,14);}
                    cout<<g<<':'<<numc<<endl;
                }
            }
    }file.close();
}
phone()
{
    char com;
    while(t!=-1)
    {
    system("cls");
    SetConsoleTextAttribute(hh,15);cout<<"PHONE\n";
    SetConsoleTextAttribute(hh,10);
    cout<<"0:QUIT"<<endl<<"1:ADD"<<endl<<"2:SEE"<<endl<<"3:SEARCH"<<endl;
    SetConsoleTextAttribute(hh,12);cout<<'>';SetConsoleTextAttribute(hh,11);cin>>com;
    if(com=='1'){add();}
    else if(com=='2'){see();}
    else if(com=='3'){serch();}
    else if(com=='0'){break;}
    else{SetConsoleTextAttribute(hh,15);cout<<"WRONG COMMAND...";}
    system("pause>null");
    }
}
