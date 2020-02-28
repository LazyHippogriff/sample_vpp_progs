#include <stdio.h>
#include "vppinfra/vec.h"
int main(){
  u64 elm[1024];
  void *vec_u64  = 0;
  u64 *elm_add2 = 0;
  int index = 0;
  u64 *tmp_elm;
  void *mheap;
  struct test{
    int a;
    char b;
  };
  mheap = create_mspace(1024*1024,0);
  clib_mem_set_heap(mheap);
//  printf("vec_len:%d\n",vec_len(tmp_elm));
//  printf("vec_len:%d\n",_vec_len(vec_u64));
  vec_u64 = vec_new(struct test,10);
//  printf("vec_len:%d\n",vec_len(vec_u64));
//  printf("vec_len:%d\n",_vec_len(vec_u64));
//  printf("vec_u64:%p\n", vec_u64);
//  printf("vec_bytes:%d\n\n",vec_bytes(vec_u64));
//  printf("vec_len:%d\n", _vec_len(vec_u64));
//  vec_validate_aligned(vec_u64,4);
//  printf("vec_bytes:%d\n", vec_bytes(vec_u64));
//  printf("vec_capacity:%d \n", vec_capacity(vec_u64,0));
//  printf("vec_max_len:%d \n", vec_max_len(vec_u64));
//  printf("vec_end:%p \n\n ", vec_end(vec_u64));
  vec_validate_aligned(vec_u64,9,0/*CLIB_CACHE_LINE_BYTES*/);
  printf("vec_u64:%p\n", vec_u64);
  printf("vec_len:%d\n", vec_len(vec_u64));
  printf("vec_bytes:%d\n", vec_bytes(vec_u64));
  printf("vec_capacity:%d \n", vec_capacity(vec_u64,0));
  printf("vec_max_len:%d \n", vec_max_len(vec_u64));
  printf("vec_end:%p \n\n ", vec_end(vec_u64));
//  mheap = create_mspace(1024*1024, 0);
//  clib_mem_set_heap(mheap);
  if (vec_u64)
    vec_free(vec_u64);
}
