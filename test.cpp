//OpenCV headers
#include "opencv2/videoio.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

//C++ headers
#include "iostream"
#include "string"
#include "test.h"

//hello world this is from ubuntu 16.04.4

int main(int argc, char* argv[])
{
    help();
    option();
    //if
    if(op == 1) {
        std::cout << "\n";
         
     pathCall();
    cv::VideoCapture cap(pathP);

    if(cap.isOpened() == false) {
        std::cout << "404 rong path" << std::endl;
        std::cin.get();

        return -1; //error callout -1
    }
    //fps 
    double fps = cap.get(cv::CAP_PROP_FPS);
    std::cout << "fps for the input file" << fps << std::endl;

    std::string window_name = "INPUT_FILE";

    cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    while(true) {
        cv::Mat frame;
        int count = -1;
        bool bSucess = cap.read(frame);

        if(bSucess == false) {
            std::cout << "end point discovered " << std::endl;
            break;
        }
        cv::imshow(window_name, frame);

        
        
        //exit key is ESC
        if(cv::waitKey(10) == 27) {
            std::cout << "esc ' ed" << std::endl;
            break;
            } 

            for(;;) {
            cap >> frame;
            ++count;
            std::string name = "out_" + std::to_string(count) + ".png";
            cv::imwrite("/home/rayyan/out_dir/" + name, frame);
            }
          
        }
    }

    //else op
    else if(op == 2) {
        cv::VideoCapture cap(0);

 // if not success, exit program
 if (cap.isOpened() == false)  
 {
  std::cout << "Cannot open the video camera" << std::endl;
  std::cin.get(); //wait for any key press
  return -1;
 } 

 double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
 double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

 std::cout << "Resolution of the video : " << dWidth << " x " << dHeight << std::endl;

 std::string window_name = "My Camera Feed";
 cv::namedWindow(window_name); //create a window called "My Camera Feed"

 while (true)
 {
  cv::Mat frame;
  bool bSuccess = cap.read(frame); // read a new frame from video 

  //Breaking the while loop if the frames cannot be captured
  if (bSuccess == false) 
  {
   std::cout << "Video camera is disconnected" << std::endl;
   std::cin.get(); //Wait for any key press
   break;
  }

  //show the frame in the created window
  cv::imshow(window_name, frame);

  if (cv::waitKey(10) == 27)
  {
   std::cout << "Esc key is pressed by user. Stopping the video" << std::endl;
   break;
  }
        }
    }
    return 0;
}
