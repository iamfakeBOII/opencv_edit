#include "iostream"
#include "string"

//ayy yo! guys

//Public def
std::string pathP;
int op;

void help(){
        std::cout << "\n";
        std::cout <<  "THIS PROGRAM INPUTS A VIDEO AND FINDS THE SUPERIOR " << std::endl;  
        std::cout <<  "FRAMES AND DELETES THE INFERIOR ONES AND THEN STITCHES " << std::endl;
        std::cout <<  "THE WHOLE VIDEO TO FORM A SEQUENCE WITHOUT AUDIO" << std::endl;         
}

//func to call path IO
void pathCall() {
    std::cout << "\n";
    std::cout << "PLS ENTER THE PATH STARTING WITH /" << std::endl;
    std::cin >> pathP;
    
}

void option() {
    std::cout << "\n";
    std::cout << "1. play a video saved on this computer" << std::endl;
    std::cout << "2. input == webcam if avaliable" << std::endl;
    std::cout << "you chose option: ";
    std::cin >> op;
}
