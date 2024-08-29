#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <mach/mach_time.h> //for macos

uint64_t get_time_in_nanos()
{
    static mach_timebase_info_data_t info = {0, 0};
    if (info.denom == 0)
    {
        mach_timebase_info(&info);
    }
    uint64_t time = mach_absolute_time();
    return time * info.numer / info.denom;
}

int main()
{
    uint64_t start, end;
    pid_t pid;

    start = get_time_in_nanos();
    pid = getpid();
    end = get_time_in_nanos();

    printf("Process ID: %d\n", pid);
    printf("Time taken to execute getpid: %llu nanoseconds\n", end - start);

    return 0;
}