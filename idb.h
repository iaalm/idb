extern int _idb_malloc_free_c;
#define malloc(arg) (++_idb_malloc_free_c,fprintf(stderr,"%s:%d\tmalloc %d byte(s)\n",__FILE__,__LINE__,arg),malloc(arg))
#define free(arg) (--_idb_malloc_free_c,fprintf(stderr,"%s:%d\tfree address %d\n",__FILE__,__LINE__,arg),free(arg))
#define IDB_MALLOC_FREE_BALANCE_ASSERT(arg) (_idb_malloc_free_c == (arg))||(fprintf(stderr,"%s:%d\tIDB_MALLOC_FREE_BALANCE_ASSERT Fail!\n",__FILE__,__LINE__))
