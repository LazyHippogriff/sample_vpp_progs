#include <stdio.h>
#include "vppinfra/vec.h"
#include <pthread.h>
#include <unistd.h>
void fun(u64 * vec){
  int index = 0;
  u64* tmp_elm;
  vec_foreach(tmp_elm, vec) {
      printf("vec[%d]:%d \n ", index++, *tmp_elm);
  }
}
void sub(u64 *vec)
{
  int i;
  for(i=0;i<vec_len(vec);i++)
  vec[i] -=1;
}
void add(u64 *vec)
{
  int i;
  for(i=0;i<vec_len(vec);i++)
  vec[i] +=1;
}
int main(){
  u64 elm[1024];
  u64 *vec_u64  = 0;
  u64 *elm_add2 = 0;
  int index = 0;
  u64 *tmp_elm;
  void *mheap;
  pthread_t t1,t2,t3;
  mheap = create_mspace(1024*1024, 0);
  clib_mem_set_heap(mheap);
  for (index = 0; index < 10; index++) {
      elm[index] = 0;
  }
  index = 0;
  vec_add(vec_u64, &elm[index], 10);
/*
  index = 0;
  vec_foreach(tmp_elm, vec_u64) {
      printf("vec_u64[%d]:%d \n ", index++, *tmp_elm);
  }*/
   pthread_create(&t1, NULL,fun, vec_u64);
  pthread_create(&t2,NULL,sub, vec_u64);
  pthread_create(&t3,NULL,add, vec_u64);
 //  int i;
   //for(i=0;i<101;i++){
  // vec_u64[i]+=1;
  // }
   pthread_join(t1, NULL);
   pthread_join(t2,NULL);
  pthread_join(t3,NULL);
  if (vec_u64)
      vec_free(vec_u64);
}
