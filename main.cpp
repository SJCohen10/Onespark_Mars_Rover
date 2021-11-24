//Onespark Coding challenge
//Mars Rover Problem
//Samuel Cohen

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int boardx, boardy, x, y, constDir, i;
    char dir, finalDir;
    string path, message1,message2;
    ifstream indata;
    indata.open("input.txt");

    while(!indata.eof())
    {
        indata>>boardx>>boardy>>x>>y>>dir>>path;


        switch (dir)
        {
        case 'N':
            constDir = 0;
            break;
        case 'E':
            constDir = 1;
            break;
        case 'S':
            constDir = 2;
            break;
        case 'W':
            constDir = 3;
            break;
        }

        for (i = 0; i<path.length(); i++)
        {
            if(path[i]=='L')
            {
                if(constDir==0)
                {
                    constDir=3;
                }
                else
                {
                    constDir--;
                }
            }
            if(path[i]=='R')
            {
                if(constDir==3)
                {
                    constDir=0;
                }
                else
                {
                    constDir++;
                }
            }
            if(path[i]=='M')
            {
                switch (constDir)
                {
                case 0:
                    y +=1;
                    break;
                case 1:
                    x +=1;
                    break;
                case 2:
                    y -=1;
                    break;
                case 3:
                    x -=1;
                    break;
                }
            }
        }
        switch (constDir)
        {
        case 0:
            finalDir = 'N';
            break;
        case 1:
            finalDir = 'E';
            break;
        case 2:
            finalDir = 'S';
            break;
        case 3:
            finalDir = 'W';
            break;
        }

        cout<<x<<" "<<y<<" "<<finalDir<<endl;
        while(!indata.eof())
        {

            indata>>x>>y>>dir>>path;
            switch (dir)
            {
            case 'N':
                constDir = 0;
                break;
            case 'E':
                constDir = 1;
                break;
            case 'S':
                constDir = 2;
                break;
            case 'W':
                constDir = 3;
                break;
            }

            for (i = 0; i<path.length(); i++)
            {
                if(path[i]=='L')
                {
                    if(constDir==0)
                    {
                        constDir=3;
                    }
                    else
                    {
                        constDir--;
                    }
                }
                if(path[i]=='R')
                {
                    if(constDir==3)
                    {
                        constDir=0;
                    }
                    else
                    {
                        constDir++;
                    }
                }
                if(path[i]=='M')
                {
                    switch (constDir)
                    {
                    case 0:
                        y +=1;
                        break;
                    case 1:
                        x +=1;
                        break;
                    case 2:
                        y -=1;
                        break;
                    case 3:
                        x -=1;
                        break;
                    }
                }
            }
            switch (constDir)
            {
            case 0:
                finalDir = 'N';
                break;
            case 1:
                finalDir = 'E';
                break;
            case 2:
                finalDir = 'S';
                break;
            case 3:
                finalDir = 'W';
                break;
            }

            cout<<x<<" "<<y<<" "<<finalDir<<endl;
        }
        break;
    }


    indata.close();

    return 0;
}
