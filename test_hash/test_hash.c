#include <stdio.h>
#include "vppinfra/hash.h"
int main()
{
  void *mheap;
  mheap = create_mspace(1024*1024,0);
  clib_mem_set_heap(mheap);
  int s = 10 ;
  uword *h;
  uword m = 1;
  h = hash_create(32,sizeof (uword));
  hash_set(h,s,m);
//ash_resize(h,64);
  hash_set(h,11,2000);
  uword *p;
//  p =  hash_get(h,k);
//  printf("%d",*p);
  hash_foreach(s,m,h,printf("%d,%d\n",s,m));
  hash_free(h);
}
