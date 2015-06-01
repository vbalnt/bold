#include "utils.h"
#include "bold.hpp"

int main(int argc, char *argv[])
{
  /* init data */
  dataset data;
  init_dataset(&data,(char*) "dataset/notredame/");

  /* init BOLD */
  BOLD bold;

  /* get descriptors for patch pairs */
  for (int i = 0; i < GT_SIZE; i++) {
    int id1 = data.gt[i][0];
    int id2 = data.gt[i][3];
    int label = data.gt[i][1]==data.gt[i][4];

    cv::Mat desc_boldL,desc_boldR,mask_boldL,mask_boldR;
    bold.compute_patch(data.patchesCV[id1], desc_boldL, mask_boldL) ;
    bold.compute_patch(data.patchesCV[id2], desc_boldR, mask_boldR) ;

    uchar *l = desc_boldL.ptr<uchar>(0);
    uchar *ml = mask_boldL.ptr<uchar>(0);
    uchar *r = desc_boldR.ptr<uchar>(0);
    uchar *mr = mask_boldR.ptr<uchar>(0);

    /* dfull: no masking */
    /* dbold : masking */
    int dbold = bold.hampopmaskedLR(l,ml,r,mr);
    int dfull = bold.hampop(l,r);
    
    printf("%d %d %d\n",label,dfull,dbold);
  }

  /* cleanup */
  for (int i=0; i<GT_SIZE; ++i) {
    free(data.gt[i]);
  }
  free(data.gt);

  return 0;
}
