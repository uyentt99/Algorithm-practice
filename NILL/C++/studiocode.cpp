//
#include <bits/stdc++.h>
#define task "a"
#define Fu(i,a,b) for(int i=(a); i<=(b); ++i)
#define Fd(i,a,b) for(int i=(a); i>=(b); --i)
using namespace std;
typedef long long LL;
void pre(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int a[100];
int main(){
    pre();

}
//launch.json
{
    "version": "0.2.0",
    "configurations": [ 
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/a.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "D:/MinGW/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        },
    ]
}
//
//task.json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build hello world",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g", "main.cpp"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}

