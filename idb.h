#define malloc(arg) idb_malloc(arg,__FILE__,__LINE__)
#define free(arg) idb_free(arg,__FILE__,__LINE__)
#define idb_malloc_free_assert(arg) idb_mf_assert(arg,__FILE__,__LINE__)
#define idb_all_free() idb_mf_assert(0,__FILE__,__LINE__)
#define idb_malloc_free_count() idb_mf_count(__FILE__,__LINE__)

void *idb_malloc(size_t,char*,unsigned int);
void idb_free(void *,char*,unsigned int);
void idb_mf_assert(int,char*,unsigned int);
int idb_mf_count(char*,unsigned int);
