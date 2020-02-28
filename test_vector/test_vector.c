#include <stdio.h>
#include "vppinfra/vec.h"
int main(){
  u64 elm[1024];
  u64 *vec_u64  = 0;
  u64 *elm_add2 = 0;
  int index = 0;
  u64 *tmp_elm;
  void *mheap;
  //mheap = create_mspace(1024*1024, 0);
  mheap = create_mspace(1, 0);
  clib_mem_set_heap(mheap);
  for (index = 0; index < 16; index++) {
    elm[index] = index;
  }
  index = 0;
  vec_add1(vec_u64, elm[index]);
  index++;
  printf("vec_u64:%p \n", vec_u64);
  printf("vec_len:%d \n", vec_len(vec_u64));
  printf("vec_bytes:%d \n", vec_bytes(vec_u64));
  printf("vec_capacity:%d \n", vec_capacity(vec_u64,0));
  printf("vec_max_len:%d \n ", vec_max_len(vec_u64));
  printf("vec_end:%p \n\n", vec_end(vec_u64));
  vec_add1(vec_u64, elm[index]);
  index++;
  printf("vec_u64:%p\n", vec_u64);
  printf("vec_len:%d\n", vec_len(vec_u64));
  printf("vec_bytes:%d\n", vec_bytes(vec_u64));
  printf("vec_capacity:%d\n", vec_capacity(vec_u64,0));
  printf("vec_max_len:%d\n", vec_max_len(vec_u64));
  printf("vec_end:%p\n\n", vec_end(vec_u64));
  vec_add(vec_u64, &elm[index], 10);
  index+=10;
  printf("vec_u64:%p\n", vec_u64);
  printf("vec_len:%d\n", vec_len(vec_u64));
  printf("vec_bytes:%d\n", vec_bytes(vec_u64));
  printf("vec_capacity:%d \n", vec_capacity(vec_u64,0));
  printf("vec_max_len:%d \n", vec_max_len(vec_u64));
  printf("vec_end:%p \n\n ", vec_end(vec_u64));
  vec_add2(vec_u64, elm_add2, 10);
  for (index = 0; index < 10; index++) {
    elm_add2[index] = index;
  }
  printf("vec_u64:%p, elm_add2:%p\n", vec_u64, elm_add2);
  printf("vec_len:%d\n ", vec_len(vec_u64));
  printf("vec_bytes:%d \n", vec_bytes(vec_u64));
  printf("vec_capacity:%d\n", vec_capacity(vec_u64,0));
  printf("vec_max_len:%d\n", vec_max_len(vec_u64));
  printf("vec_end:%p \n\n ", vec_end(vec_u64));
  vec_add_aligned(vec_u64, &elm[index], 10,32);
  printf("vec_u64:%p, elm_add2:%p\n", vec_u64, elm_add2);
  printf("vec_len:%d\n ", vec_len(vec_u64));
  printf("vec_bytes:%d \n", vec_bytes(vec_u64));
  printf("vec_capacity:%d\n", vec_capacity(vec_u64,0));
  printf("vec_max_len:%d\n", vec_max_len(vec_u64));
  printf("vec_end:%p \n\n ", vec_end(vec_u64));
  if (vec_u64)
    vec_free(vec_u64);
}
