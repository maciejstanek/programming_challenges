#include <stdlib.h>
#include <stdio.h>

void sqrseq(int pos, int *seq, int lim, int *sqr, int sqrn, int *curmax) {
  if(pos > *curmax) {
    *curmax = pos;
    printf("SEQ{%02d}:", pos);
    for(int j = 0; j < lim; j++) {
    printf(" %02d", seq[j]);
    }
    printf("\n");
  }
  if(pos == lim) {
    free(seq);
    return;
  }
  for(int i = pos; i < lim; i++) {
    if(pos > 0) {
      int sum = seq[pos - 1] + seq[i];
      int in = 0;
      for(int j = 0; j < sqrn; j++) {
        if(sqr[j] == sum) {
          in = 1;
          break;
        }
      }
      if(!in) {
        continue;
      }
    }
    int *nseq = malloc(lim * sizeof(int));
    for(int j = 0; j < pos; j++) {
      nseq[j] = seq[j];
    }
    nseq[pos] = seq[i];
    int offset = -1;
    for(int j = pos + 1; j < lim; j++) {
      if(seq[i] == seq[j - 1])
        offset = 0;
      nseq[j] = seq[j + offset];
    }
    sqrseq(pos + 1, nseq, lim, sqr, sqrn, curmax);
  }
  free(seq);
}

int main(int argc, char **argv) {
  if(argc < 2) {
    return 1;
  }
  int lim = atoi(argv[1]);
  if(lim < 2) {
    return 1;
  }
  int i = 1, i2 = 1;
  int *sqr = malloc(sizeof(int)), sqrn = 0;
  while(i2 <= 2 * lim - 1) {
    sqr = (int*) realloc(sqr, (sqrn + 1) * sizeof(int));
    sqr[sqrn++] = i2;
    i++;
    i2 = i * i;
  }
  int *seq = malloc(lim * sizeof(int));
  for(int i = 0; i < lim; i++) {
    seq[i] = i + 1;
  }
  int curmax = 0;
  sqrseq(0, seq, lim, sqr, sqrn, &curmax);
  free(sqr);
  return 0;
}
