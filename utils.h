#ifndef _UTILS_H_
#define _UTILS_H_
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <math.h>
#include <unistd.h>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/* Dataset */
#define GT_SIZE 100000
typedef struct dataset 
{
  int **gt;
  int npatches;
  std::vector<cv::Mat> patchesCV;
} dataset;
void init_dataset(dataset *A,const char *path);

#endif /* _UTILS_H_ */
