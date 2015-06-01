#ifndef BOLD_H
#define BOLD_H
#include "utils.h"
#include <opencv2/opencv.hpp>

#define NTESTS 768
#define DIMS 512
#define NROTS 3

class BOLD {
public:
  BOLD(void);
  ~BOLD();
  
  void compute_patch(cv::Mat image, cv::Mat& descrs,cv::Mat& masks);
  int hampopmaskedLR(uchar *a,uchar *ma,uchar *b,uchar *mb);
  int hampop(uchar *a,uchar *b);

  int **bin_tests;
  int rotations[2];
};

#endif /* BOLD_H */
