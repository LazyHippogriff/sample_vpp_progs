#include "vppinfra/bihash_8_8.h"
#include "vppinfra/bihash_template.c"

typedef struct{

  clib_bihash_8_8_t hash;

}my_main_t;

int main()
{
  my_main_t my_main;
  my_main_t* mm =&my_main;
  void *mheap;
  mheap = create_mspace(1024*1024,0);
  clib_mem_set_heap(mheap);
  clib_bihash_8_8_t *h;
  h= &mm->hash;
  clib_bihash_init_8_8(h,"hash1",4,1024);
  clib_bihash_kv_8_8_t kv;
  kv.key = 123;
  kv.value = 321;
  clib_bihash_add_del_8_8(h,&kv,1);
  printf("ended");
//  hash_foreach(s,m,h,printf("%d,%d\n",s,m));
//  clib_bihash_free_8_8(h);
}
