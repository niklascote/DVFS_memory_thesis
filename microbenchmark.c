#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <pthread.h>

//#define NUM_THREADS 1
int main(int argc, char *argv[]){
        //pthread_t threads[NUM_THREADS];
        int* ptr;
        time_t t;
        /* Intializes random number generator */
        srand((unsigned) time(&t));


        int i,j, MEMBOUND;
        //INPUT MEMORY-BOUND PERCENTAGE WHEN EXECUTING
        MEMBOUND = atoi(argv[1]);

        int r=0;
        int tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,tmp10,tmp11,tmp12,tmp13,tmp14,tmp15,tmp16,tmp17,tmp18,tmp19,tmp20,tmp21,tmp22,tmp23,tmp24;
        int working_set_size=128*1024*1024*sizeof(int);
        ptr = (int*)malloc(working_set_size);
        if (ptr == NULL) {
                printf("Memory not allocated.\n");
                exit(0);
        }
        else {

                printf("Memory successfully allocated using malloc.\n");
                memset(ptr,1234,working_set_size);


                switch (MEMBOUND){
                        case 70:
                        for(j=0;j<1000;j++){                                                             
                                for (i = 0; i < working_set_size/sizeof(int);i+=1024) {
                                        ptr[i+65]=ptr[i];
                                        ptr[i+129]=ptr[i+64];
                                        ptr[i+193]=ptr[i+128];
                                        ptr[i+257]=ptr[i+192];
                                        ptr[i+321]=ptr[i+256];
                                        ptr[i+385]=ptr[i+320];
                                        ptr[i+449]=ptr[i+384];
                                        ptr[i+513]=ptr[i+448];
                                        ptr[i+577]=ptr[i+512];
                                        ptr[i+641]=ptr[i+576];
                                        ptr[i+705]=ptr[i+640];
                                        ptr[i+769]=ptr[i+704];
                                        ptr[i+833]=ptr[i+768];
                                        ptr[i+897]=ptr[i+832];
                                        ptr[i+961]=ptr[i+896];
                                        ptr[i+1025]=ptr[i+960];
                                }

                        }
                        printf("MEMBOUND 70%% \n");
                        break;
                        case 60:
                        for(j=0;j<1000;j++){
                                for (i = 0; i < working_set_size/sizeof(int);i+=128) {
                                        ptr[i+65]=ptr[i];
                                        ptr[i+17]=ptr[i];
                                        ptr[i+33]=ptr[i];
                                        ptr[i+34]=ptr[i];
                                }
                        }


                        printf("MEMBOUND 60%% \n");
                        break;
                        case 50:
                        for(j=0;j<1000;j++){
                                for (i = 0; i < working_set_size/sizeof(int);i+=64) {                    
                                        ptr[i+64]=ptr[i];
                                }
                        }
                        printf("MEMBOUND 50%% \n");
                        break;
                        case 40:
                        for(j=0;j<1000;j++){
                                for (i = 0; i < working_set_size/sizeof(int);i+=128) {
                                        ptr[i+65]=ptr[i];
                                        tmp1=rand();
                                }
                        }
                        printf("MEMBOUND 40%% \n");
                        break;
                        case 30:
                        for(j=0;j<100;j++){
                                for (i = 0; i < working_set_size/sizeof(int);i+=256) {
                                    ptr[i+65]=ptr[i];
                                    tmp2=rand();
                                    tmp3=rand();
                                    tmp4=rand();
                                    tmp5=rand();
                                    tmp6=rand();
                                    tmp7=rand();
                                    tmp8=rand();
                                    tmp9=rand();
                                    tmp10=rand();
                            }
                        }
                        printf("MEMBOUND 20%% \n");
                        break;

                        case 20:
                        for(j=0;j<100;j++){                                                              
                            for (i = 0; i < working_set_size/sizeof(int);i+=128) {
                                    ptr[i+65]=ptr[i];
                                    tmp2=rand();
                                    tmp3=rand();
                                    tmp4=rand();
                                    tmp5=rand();
                                    tmp6=rand();
                                    tmp7=rand();
                                }
                        }
                        printf("MEMBOUND 20%% \n");
                        break;
                        case 10:

                        for(j=0;j<100;j++){
                                for (i = 0; i < working_set_size/sizeof(int);i+=128) {
                                        ptr[i+65]=ptr[i];
                                        tmp2=rand();
                                        tmp3=rand();
                                        tmp4=rand();
                                        tmp5=rand();
                                        tmp6=rand();
                                        tmp7=rand();
                                        tmp8=rand();
                                        tmp9=rand();
                                        tmp10=rand();
                                        tmp11=rand();
                                        tmp12=rand();
                                        tmp13=rand();
                                        tmp14=rand();
                                        tmp15=rand();
                                        tmp16=rand();
                                        tmp17=rand();
                                        tmp18=rand();
                                        tmp19=rand();
                                        tmp20=rand();
                                        tmp21=rand();
                                        tmp22=rand();
                                }
                        }
                        printf("MEMBOUND 10%% \n");
                        break;

                        case 0:
                        for(j=0;j<1000;j++){                                                                                                         
                            for (i = 0; i < working_set_size/sizeof(int);i+=1024) {
                                        tmp1=rand();
                                        tmp2=rand();
                                        tmp3=rand();
                                        tmp4=rand();
                                        tmp5=rand();
                                        tmp6=rand();
                                        tmp7=rand();
                                        tmp8=rand();
                                        tmp9=rand();
                                        tmp10=rand();
                                        tmp11=rand();
                                        tmp12=rand();
                                        tmp13=rand();
                                        tmp14=rand();
                                        tmp15=rand();
                                        tmp16=rand();
                                }
                        }
                        printf("MEMBOUND 0%% \n");
                        break;

                        default:
                        for(j=0;j<1000;j++){                                                                                                         
                            for (i = 0; i < working_set_size/sizeof(int);i+=1024) {                                                              
                                ptr[i+65]=ptr[i];                                                                                                    
                                ptr[i+129]=ptr[i+64];                                                                                                
                                ptr[i+193]=ptr[i+128];                                                                                               
                                ptr[i+257]=ptr[i+192];                                                                                               
                                ptr[i+321]=ptr[i+256];                                                                                               
                                ptr[i+385]=ptr[i+320];                                                                                               
                                ptr[i+449]=ptr[i+384];                                                                                               
                                ptr[i+513]=ptr[i+448];                                                                                               
                                ptr[i+577]=ptr[i+512];                                                                                               
                                ptr[i+641]=ptr[i+576];                                                                                               
                                ptr[i+705]=ptr[i+640];                                                                                               
                                ptr[i+769]=ptr[i+704];                                                                                               
                                ptr[i+833]=ptr[i+768];                                                                                               
                                ptr[i+897]=ptr[i+832];
                                ptr[i+961]=ptr[i+896]; 
                                ptr[i+1025]=ptr[i+960];                                                                                              
                                }                                                                                                            
                            }
                                printf("No MEMBOUND value choosen, highest MEMBOUND used");
                }
        printf ("final value of tmp1 = %d tmp2 = %d tmp3 = %d tmp4 = %d tmp5 = %d tmp6 = %d tmp7 = %d tmp8 = %d\n", tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8);
        printf ("final value of tmp9 = %d tmp10 = %d tmp11 = %d tmp12 = %d tmp13 = %d tmp14 = %d tmp15 = %d tmp16 = %d\n", tmp9, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16);
                free(ptr);
        }

}