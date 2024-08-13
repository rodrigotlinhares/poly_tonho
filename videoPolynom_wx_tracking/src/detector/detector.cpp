#include "detector.h"
//#include "opencv2/objdetect/objdetect.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//
//#include <iostream>
//#include <stdio.h>

//Point detect(Mat& img, CascadeClassifier& cascade, double scale, Scalar color, Point reference);
//int euclidean_distance(Point a, Point b);

Mat ViolaJonesDetector::detect(Mat img) {
//  Point closest(-1, -1);
//  int shortest_distance = INT_MAX;
//  int radius;
//  vector<Rect> detections;
//  Mat gray, smallImg(cvRound(img.rows / scale), cvRound(img.cols / scale), CV_8UC1);
//
//  cvtColor(img, gray, CV_BGR2GRAY);
//  resize(gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR);
//  equalizeHist(smallImg, smallImg);
//
//  hand_classifier.detectMultiScale(smallImg, detections,
//                                   1.1, 2, 0
//                                   //| CV_HAAR_FIND_BIGGEST_OBJECT
//                                   //| CV_HAAR_DO_ROUGH_SEARCH
//                                   | CV_HAAR_SCALE_IMAGE
//                                   ,
//                                   Size(30, 30));
//
//  for(vector<Rect>::const_iterator r = detections.begin(); r != detections.end(); r++) {
//    Mat smallImgROI;
//    Point center;
//    center.x = cvRound((r->x + r->width * 0.5) * scale);
//    center.y = cvRound((r->y + r->height * 0.5) * scale);
//    int distance = euclidean_distance(center, reference);
//    if(distance < shortest_distance) {
//      shortest_distance = distance;
//      closest = center;
//      radius = cvRound((r->width + r->height) * 0.25 * scale);
//    }
//  }
//  if(closest != Point(-1, -1)) {
//    circle(img, closest, radius, color, 2, 8, 0);
//    return closest;
//  }
//  return reference;
  return img;
}

void ViolaJonesDetector::setHandClassifier(string handXml) {
  handClassifier.load(handXml);
}

void ViolaJonesDetector::setFaceClassifier(string faceXml) {
  faceClassifier.load(faceXml);
}

void ViolaJonesDetector::setScale(float scale) {
  this->scale = scale;
}

//int main(int argc, const char** argv) {
//  VideoCapture capture;
//  VideoWriter recorder;
//  String hand_path, face_path, device_name, record_path;
//  const String scale_opt = "--scale=";
//  const String hand_opt = "--hand=";
//  const String face_opt = "--face=";
//  const String device_opt = "--device=";
//  const String record_opt = "--record=";
//  bool record = false;
//  int device_index = 0;
//
//  help();
//
//  CascadeClassifier hand_classifier, face_classifier;
//  double scale = 1;
//
//  // Reads arguments and initializes variables.
//  for(int i = 1; i < argc; i++) {
//    if(hand_opt.compare(0, hand_opt.size(), argv[i], hand_opt.size()) == 0)
//      hand_path.assign(argv[i] + hand_opt.size());
//
//    else if(face_opt.compare(0, face_opt.size(), argv[i], face_opt.size()) == 0)
//      face_path.assign(argv[i] + face_opt.size());
//
//    else if(device_opt.compare(0, device_opt.size(), argv[i], device_opt.size()) == 0) {
//      device_name.assign(argv[i] + device_opt.size());
//      device_index = atoi(&device_name[0]);
//    }
//
//    else if(scale_opt.compare(0, scale_opt.size(), argv[i], scale_opt.size()) == 0) {
//      if(!sscanf(argv[i] + scale_opt.length(), "%lf", &scale) || scale < 1)
//        scale = 1;
//    }
//
//    else if(record_opt.compare(0, record_opt.size(), argv[i], record_opt.size()) == 0) {
//      record_path.assign(argv[i] + record_opt.size());
//      record = true;
//    }
//
//    else
//      cout << "WARNING: Unknown option " << argv[i] << endl;
//  }
//
//  if(hand_path.empty() || !hand_classifier.load(hand_path)) {
//    cout << "ERROR: could not load hand cascade" << endl;
//    return -1;
//  }
//  cout << "Loaded hand cascade: " << hand_path << endl;
//
//  if(face_path.empty() || !face_classifier.load(face_path)) {
//    cout << "ERROR: could not load face cascade" << endl;
//    return -1;
//  }
//  else
//    cout << "Loaded face cascade: " << face_path << endl;
//
//  capture.open(device_index);
//  if(!capture.isOpened()) {
//    cout << "ERROR: capture from device " << device_index << " failed" << endl;
//    return -1;
//  }
//  cout << "Loaded device " << device_index << endl;
//
//  if(!record_path.empty()) {
////    int codec = static_cast<int>(capture.get(CV_CAP_PROP_FOURCC));
////    int fps = (int)capture.get(CV_CAP_PROP_FPS);
//    Size res((int)capture.get(CV_CAP_PROP_FRAME_WIDTH), (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));
//    recorder.open(record_path, OUTPUT_CODEC, OUTPUT_FPS, res);
//
//    if(!recorder.isOpened()) {
//      cout << "ERROR: recording failed." << endl;
//      return -1; 
//    }
//    cout << "Recording to " << record_path << endl;
//  }
//
//  cvNamedWindow("Result", 1);
//
//  // Capture and detection loop.
//  Mat frame, frameCopy;
//  while(true) {
//    capture >> frame;
//    if(frame.empty())
//      break;
//
//    double time = cvGetTickCount();
//
//    Point center(frame.cols / 2, frame.rows / 2);
//    Point face_position = detect(frame, face_classifier, scale, CV_RGB(255, 0, 0), center);
//    detect(frame, hand_classifier, scale, CV_RGB(0, 0, 255), face_position);
//    flip(frame, frame, 1);
//    detect(frame, hand_classifier, scale, CV_RGB(0, 255, 0), face_position);
//    flip(frame, frame, 1);
//    imshow("Result", frame);
//
//    if(record)
//      recorder << frame;
//
//    time = (double)cvGetTickCount() - time;
//    cout << "Detection time = " << time / cvGetTickFrequency() / 1000 << " ms" << endl;
//
//    if(waitKey(10) >= 0)
//      break;
//  }
//
//  // Cleanup
//  capture.release();
//  cvDestroyWindow("Result");
//
//  return 0;
//}
//
//Point detect(Mat& img, CascadeClassifier& cascade, double scale, Scalar color, Point reference) {
//  Point closest(-1, -1);
//  int shortest_distance = INT_MAX;
//  int radius;
//  vector<Rect> detections;
//  Mat gray, smallImg(cvRound(img.rows/scale), cvRound(img.cols/scale), CV_8UC1);
//
//  cvtColor(img, gray, CV_BGR2GRAY);
//  resize(gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR);
//  equalizeHist(smallImg, smallImg);
//
//  cascade.detectMultiScale(smallImg, detections,
//                           1.1, 2, 0
//                           //| CV_HAAR_FIND_BIGGEST_OBJECT
//                           //| CV_HAAR_DO_ROUGH_SEARCH
//                           | CV_HAAR_SCALE_IMAGE
//                           ,
//                           Size(30, 30));
//
//  for(vector<Rect>::const_iterator r = detections.begin(); r != detections.end(); r++) {
//    Mat smallImgROI;
//    Point center;
//    center.x = cvRound((r->x + r->width * 0.5) * scale);
//    center.y = cvRound((r->y + r->height * 0.5) * scale);
//    int distance = euclidean_distance(center, reference);
//    if(distance < shortest_distance) {
//      shortest_distance = distance;
//      closest = center;
//      radius = cvRound((r->width + r->height) * 0.25 * scale);
//    }
//  }
//  if(closest != Point(-1, -1)) {
//    circle(img, closest, radius, color, 2, 8, 0);
//    return closest;
//  }
//  return reference;
//}
//
//int euclidean_distance(Point a, Point b) {
//  int diff_x = a.x - b.x;
//  int diff_y = a.y - b.y;
//  return sqrt(diff_x * diff_x + diff_y * diff_y);
//}
