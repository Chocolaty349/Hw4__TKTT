#include <stdio.h>

struct activity
{
    int start_time;
    int end_time;
};

int main(int argc, char *argv[])
{
    struct activity activity_array[] = {
        {1,3}, {2,5}, {4,7}, {1,8},
        {5,9}, {8,10}, {9,11}, {11,14},
        {13,16}
    };// data in slide, sorted

    int activity_count = sizeof(activity_array) / sizeof(activity_array[0]);

    int selected_activiti_index = 0;
    printf("The following activities are selected:\n");
    printf("%d ", 0); // activity 0 has earliest finished time 
    
    for (int i = 1; i < activity_count; i++)// consider from activity 1
    {
        if (activity_array[i].start_time > activity_array[selected_activiti_index].end_time)
        {
            printf("%d ", i);
            selected_activiti_index = i;
        }
    }
    
    
    return 0;
}
