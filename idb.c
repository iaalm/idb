#include <stdio.h>
#include <stdlib.h>
static int idb_mf_c = 0;	//malloc free count

void *idb_malloc(size_t size,char* file,unsigned int line){
	void *t;
	t = malloc(size);
	if(t)
		++idb_mf_c;	//if malloc fail , don't count
	fprintf(stderr,"%s:%d\tmalloc %d byte(s):%X\n",file,line,size,t);
	return t;
}
void idb_free(void *ptr,char* file,unsigned int line){
	if(ptr)
		--idb_mf_c;	//if free null , don't count
	free(ptr);
	fprintf(stderr,"%s:%d\tfree %X\n",file,line,ptr);
}

void idb_mf_assert(int val,char* file,unsigned int line){
	if(idb_mf_c != val){
		fprintf(stderr,"%s:%d\tidb_mf_assert fail! idb_mf_c is %d not %d !\n",__FILE__,__LINE__,idb_mf_c,val);
		exit(-1);
	}
}

int idb_mf_count(char* file,unsigned int line){
	fprintf(stderr,"%s:%d\tidb_mf_count is %d\n",file,line,idb_mf_c);
	return idb_mf_c;
}
