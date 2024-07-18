#include <sys/time.h>
#include <stdio.h>
static struct timeval previousTime;//used for recording the time
float etime() //will be called in other programs
{
    struct timeval currentTime;//current time is the last call to etime
    float elapsed_time;//saves the time 
    gettimeofday(&currentTime, NULL);
    elapsed_time= (currentTime.tv_sec-previousTime.tv_sec) + ((currentTime.tv_usec-previousTime.tv_usec)/1000000.0);
    previousTime = currentTime;
    return elapsed_time;
}
