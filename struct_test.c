#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct test_mem {
	int fd;
	int pages;
};

struct ram {
	//struct test_mem *p[MAX];
	struct test_mem p[MAX];
};

int main() {
	struct ram *r; 
	r = (struct ram *) malloc(sizeof(struct ram) * MAX);
	int i =0;
	for(i=0;i<MAX;i++) {
		r->p[i].fd = 10;
		r->p[i].pages = 144;
	}


	for(i=0;i<MAX;i++) {
		//printf("\n fd = %d and pages = %d \n",r->p[i]->fd,r->p[i]->pages); 
		printf("\n fd = %d and pages = %d \n",r->p[i].fd,r->p[i].pages); 
	}

}
