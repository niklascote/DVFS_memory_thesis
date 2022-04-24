#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>


int main(int argc, char *argv[]){
        time_t t;
        int num_threads;
        /* Intializes random number generator */
        srand((unsigned) time(&t));

        int i,j,k,MEMBOUND;
        //INPUT MEMORY-BOUND PERCENTAGE WHEN EXECUTING
        //MEMBOUND = atoi(argv[1]);
        omp_set_num_threads(4);
        #pragma omp parallel
        {
                #pragma omp single
                num_threads= omp_get_num_threads();
                printf("Number of threads = %d \n", omp_get_num_threads());
        }

        int* ptr[omp_get_num_threads()];
        int r=0;
        int tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,tmp10,tmp11,tmp12,tmp13,tmp14,tmp15,tmp16,tmp17,tmp18,tmp19,tmp20,tmp21,tmp22,tmp23,tmp24;
        int working_set_size=128*1024*1024*sizeof(int)/num_threads;
        for(int k=0;k<num_threads; k++){
                ptr[k] = (int*)malloc(working_set_size);
                if (ptr[k] == NULL) {
                        printf("Memory not allocated.\n");
                        exit(0);
                }
                printf("Memory successfully allocated using malloc.\n");
                memset(ptr[k],1234,working_set_size);
        }
                #pragma omp parallel for private(i,j,k)
                for(j=0;j<1000;j++){
                k = omp_get_thread_num();
                        for (i = 0; i < working_set_size/sizeof(int);i+=1024) {
                                ptr[k][i+65]=ptr[k][i];
                                ptr[k][i+129]=ptr[k][i+64];
                                ptr[k][i+193]=ptr[k][i+128];
                                ptr[k][i+257]=ptr[k][i+192];
                                ptr[k][i+321]=ptr[k][i+256];
                                ptr[k][i+385]=ptr[k][i+320];
                                ptr[k][i+449]=ptr[k][i+384];
                                ptr[k][i+513]=ptr[k][i+448];
                                ptr[k][i+577]=ptr[k][i+512];
                                ptr[k][i+641]=ptr[k][i+576];
                                ptr[k][i+705]=ptr[k][i+640];
                                ptr[k][i+769]=ptr[k][i+704];
                                ptr[k][i+833]=ptr[k][i+768];
                                ptr[k][i+897]=ptr[k][i+832];
                                ptr[k][i+961]=ptr[k][i+896];
                                ptr[k][i+1025]=ptr[k][i+960];
                        }
                }

                printf("MEMBOUND 70%% \n");
                #pragma omp parallel for private(i,j,k)
                for(j=0;j<1000;j++){
                        k = omp_get_thread_num();
                        for (i = 0; i < working_set_size/sizeof(int);i+=256) {
                                ptr[k][i+65]=ptr[k][i];
                                ptr[k][i+17]=ptr[k][i];
                                ptr[k][i+129]=ptr[k][i+64];
                                ptr[k][i+33]=ptr[k][i];
                                }
                        }
                printf("MEMBOUND 60%% \n");
                #pragma omp parallel for private(i,j,k)
                        for(j=0;j<1000;j++){
                                k = omp_get_thread_num();
                                for (i = 0; i < working_set_size/sizeof(int);i+=256) {
                                        ptr[k][i+65]=ptr[k][i];
                                        ptr[k][i+129]=ptr[k][i];
                                        ptr[k][i+65]=ptr[k][i];
                                        ptr[k][i+129]=ptr[k][i];
                                }
                        }
                printf("MEMBOUND 55%%  \n");
                #pragma omp parallel for private(i,j,k)
                for(j=0;j<1000;j++){
                        k = omp_get_thread_num();
                        for (i = 0; i < working_set_size/sizeof(int);i+=256) {
                                ptr[k][i+65]=ptr[k][i];
                                ptr[k][i+33]=ptr[k][i];
                                ptr[k][i+66]=ptr[k][i];
                                ptr[k][i+34]=ptr[k][i];
                                ptr[k][i+129]=ptr[k][i];
                                ptr[k][i+36]=ptr[k][i];
                                }
                        }
                printf("MEMBOUND 50%%  \n");
                #pragma omp parallel for private(i,j,k)
                    for(j=0;j<1000;j++){
                            k = omp_get_thread_num();
                            for (i = 0; i < working_set_size/sizeof(int);i+=64) {
                                    ptr[k][i+65]=ptr[k][i];
                            }
                    }
                printf("MEMBOUND 45%%  \n");
                #pragma omp parallel
                        {
                        unsigned int seed = omp_get_thread_num();
                        #pragma omp for private(i,j,k)
                        for(j=0;j<1000;j++){
                                k = omp_get_thread_num();
                                for (i = 0; i < working_set_size/sizeof(int);i+=128) {
                                        ptr[k][i+65]=ptr[k][i];
                                        tmp1=rand_r(&seed);
                                }
                        }
                        }
                printf("MEMBOUND 40%% \n");
                #pragma omp parallel for private(i,j,k)
                    for(j=0;j<1000;j++){
                            k = omp_get_thread_num();
                            for (i = 0; i < working_set_size/sizeof(int);i+=128) {
                                    ptr[k][i+32]=ptr[k][i];
                                    ptr[k][i+34]=ptr[k][i];
                                    ptr[k][i+129]=ptr[k][i];
                                }
                        }
                printf("MEMBOUND 35%%  \n");
                #pragma omp parallel for private(i,j,k)
                    for(j=0;j<1000;j++){
                            k = omp_get_thread_num();
                            for (i = 0; i < working_set_size/sizeof(int);i+=64) {
                                    ptr[k][i+1]=ptr[k][i];
                                    ptr[k][i+2]=ptr[k][i];
                            }
                    }
                printf("MEMBOUND 30%%  \n");
                
                #pragma omp parallel for private(i,j,k)
                    for(j=0;j<1000;j++){
                            k = omp_get_thread_num();
                            for (i = 0; i < working_set_size/sizeof(int);i+=128) {
                                    ptr[k][i+1]=ptr[k][i];
                                    ptr[k][i+2]=ptr[k][i];
                                    ptr[k][i+3]=ptr[k][i];
                                    ptr[k][i+4]=ptr[k][i];
                            }
                    }
                printf("MEMBOUND 25%%  \n");

                #pragma omp parallel for private(i,j,k)
                    for(j=0;j<1000;j++){
                            k = omp_get_thread_num();
                            for (i = 0; i < working_set_size/sizeof(int);i+=128) {
                                    ptr[k][i+1]=ptr[k][i];
                                    ptr[k][i+2]=ptr[k][i];
                                    ptr[k][i+3]=ptr[k][i];
                                    ptr[k][i+4]=ptr[k][i];
                                    ptr[k][i+65]=ptr[k][i];
                                }
                        }
                printf("MEMBOUND 23%%  \n");

                #pragma omp parallel
                        {
                        unsigned int seed = omp_get_thread_num();
                        #pragma omp for private(i,j,k,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7)
                        for(j=0;j<1000;j++){
                                k = omp_get_thread_num();
                                for (i = 0; i < working_set_size/sizeof(int);i+=128) {
                                        ptr[k][i+65]=ptr[k][i];
                                        tmp2=rand_r(&seed);
                                        tmp3=rand_r(&seed);
                                        tmp4=rand_r(&seed);
                                        tmp5=rand_r(&seed);
                                        tmp6=rand_r(&seed);
                                        tmp7=rand_r(&seed);
                                }
                        }
                        }
                printf("MEMBOUND 20%% \n");
                #pragma omp parallel
                        {
                        unsigned int seed = omp_get_thread_num();
                        #pragma omp for private(i,j,k,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,tmp10,tmp11,tmp12,tmp13,tmp14,tmp15,tmp16,tmp17,tmp18,tmp19,tmp20,tmp21,tmp22)
                        for(j=0;j<1000;j++){
                            k = omp_get_thread_num();
                            for (i = 0; i < working_set_size/sizeof(int);i+=128) {                                        
                                ptr[k][i+65]=ptr[k][i];
                                tmp2=rand_r(&seed);
                                tmp3=rand_r(&seed);
                                tmp4=rand_r(&seed);
                                tmp5=rand_r(&seed);
                                tmp6=rand_r(&seed);
                                tmp7=rand_r(&seed);
                                tmp8=rand_r(&seed);
                                tmp9=rand_r(&seed);
                                tmp10=rand_r(&seed);
                                tmp11=rand_r(&seed);                                        
                                tmp12=rand_r(&seed);
                                tmp13=rand_r(&seed);
                                tmp14=rand_r(&seed);
                                tmp15=rand_r(&seed);
                                tmp16=rand_r(&seed);
                                tmp17=rand_r(&seed);
                                tmp18=rand_r(&seed);
                                tmp19=rand_r(&seed);
                                tmp20=rand_r(&seed);
                                tmp21=rand_r(&seed);
                                tmp22=rand_r(&seed);
                            }
                    }
                    }
                printf("MEMBOUND 10%% \n");

                #pragma omp parallel
                    {
                    unsigned int seed = omp_get_thread_num();
                    #pragma omp for private(i,j,k,tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,tmp10,tmp11,tmp12,tmp13,tmp14,tmp15,tmp16)
                    for(j=0;j<1000;j++){
                            k = omp_get_thread_num();
                            for (i = 0; i < working_set_size/sizeof(int);i+=1024) {
                                    tmp1=rand_r(&seed);
                                    tmp2=rand_r(&seed);
                                    tmp3=rand_r(&seed);
                                    tmp4=rand_r(&seed);
                                    tmp5=rand_r(&seed);
                                    tmp6=rand_r(&seed);
                                    tmp7=rand_r(&seed);
                                    tmp8=rand_r(&seed);
                                    tmp9=rand_r(&seed);
                                    tmp10=rand_r(&seed);
                                    tmp11=rand_r(&seed);
                                    tmp12=rand_r(&seed);
                                    tmp13=rand_r(&seed);
                                    tmp14=rand_r(&seed);
                                    tmp15=rand_r(&seed);
                                    tmp16=rand_r(&seed);
                            }
                    }
                    }
                printf("MEMBOUND 0%% \n");
                printf ("final value of tmp1 = %d tmp2 = %d tmp3 = %d tmp4 = %d tmp5 = %d tmp6 = %d tmp7 = %d tmp8 = %d\n", tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8);
                printf ("final value of tmp9 = %d tmp10 = %d tmp11 = %d tmp12 = %d tmp13 = %d tmp14 = %d tmp15 = %d tmp16 = %d\n", tmp9, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16);
                for(int k=0;k<num_threads;k++) {
                        free(ptr[k]);
                }
}