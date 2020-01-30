#include <stdio.h>
#include <iostream>

// Namespace where all the C++ OpenCV functionality resides
using namespace cv;

using namespace std;

// We can also use 'namespace std' if need be.

int main() // Main function
{
    // read the image data in the file "MyPic.JPG" and 
    // store it in 'img'
    Mat image = imread("bat.jpg", CV_LOAD_IMAGE_UNCHANGED); 
   
    // Mat object is a basic image container.
    // imread: first argument denotes the image to be loaded
    // the second arguments specifies the image format.
    // CV_LOAD_IMAGE_UNCHANGED (<0) loads the image as is
    // CV_LOAD_IMAGE_GRAYSCALE ( 0) loads the image as an
    //                         intensity one
    // CV_LOAD_IMAGE_COLOR (>0) loads the image in the 
    //                          BGR format
    // If the second argument is not specified, it is 
    // implied CV_LOAD_IMAGE_COLOR

    // Check for no data
    if (! image.data ) 
    {
        cout << "Could not open or find the image.\n";
        return -1; // unsuccessful
    }
 
    // Function to blur the image
    // first argument: input source
    // second argument: output source
    // third argument: blurring kernel size
    blur(image,image,Size(10,10)); 

    // Create a window
    // first argument: name of the window
    // second argument: flag- types:
    // WINDOW_NORMAL If this is set, the user can resize the 
    //                window.
    // WINDOW_AUTOSIZE If this is set, the window size is 
    //                 automatically adjusted to fit the 
    //                 displayed image() ), and you cannot 
    //                 change the window size manually.
    // WINDOW_OPENGL If this is set, the window will be
    //              created with OpenGL support.
    namedWindow( "bat", CV_WINDOW_AUTOSIZE ); 

    // Displays an image in the specified window.
    // first argument: name of the window
    // second argument: image to be shown(Mat object)
    imshow( "bat", image ); 

    waitKey(0); // Wait infinite time for a keypress
    
    return 0; // Return from the main function
}
