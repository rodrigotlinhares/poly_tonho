#include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;

// Workaround. Had to do this because OpenCV can't get the camera properties.
#define OUTPUT_CODEC 1145656920
#define OUTPUT_FPS 10

class ViolaJonesDetector {
public:
  Mat detect(Mat img);
  void setHandClassifier(string handXml);
  void setFaceClassifier(string faceXml);
  void setScale(float scale);

  CascadeClassifier handClassifier, faceClassifier;
  double scale;
};
