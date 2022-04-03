/*
* @fichier: AsciiArt.h
* @auteurs:
* @date:
* @description: La classe art ascii
*/
#pragma once
#include<string>

using namespace std;

class AsciiArt {
public:
    string polyland() { return polyland_; };

private:
    string polyland_ = R"EOF(
8888888b.          888          888                             888 
888   Y88b         888          888                             888 
888    888         888          888                             888 
888   d88P .d88b.  888 888  888 888       8888b.  88888b.   .d88888 
8888888P" d88""88b 888 888  888 888          "88b 888 "88b d88" 888 
888       888  888 888 888  888 888      .d888888 888  888 888  888 
888       Y88..88P 888 Y88b 888 888      888  888 888  888 Y88b 888 
888        "Y88P"  888  "Y88888 88888888 "Y888888 888  888  "Y88888 
                            888                                     
                       Y8b d88P                                     
                        "Y88P"                                      
)EOF";
};