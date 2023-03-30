#include <opencv/highgui.h>

int main()
{
    IplImage * img = cvLoadImage("cat.jpg");
    cvShowImage("week07",img);
    cvWaitKey(0);
}
