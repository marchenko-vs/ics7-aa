int merge(int *const array, const int begin_pos, const int middle_pos, const int end_pos)
{
    int left_size = middle_pos - begin_pos + 1;          // 1      
    int right_size = end_pos - middle_pos;               // 2
    int i = 0;                                           // 3
    int j = 0;                                           // 4
    int *left_array = malloc(left_size * sizeof(int));   // 5
    int *right_array = malloc(right_size * sizeof(int)); // 6
    for (i = 0; i < left_size; i++)                      
        left_array[i] = array[begin_pos + i];            // 7
    for (i = 0; i < right_size; i++)                     
        right_array[i] = array[middle_pos + i + 1];      // 8
    int k = begin_pos;                                   // 9
    i = 0;                                               // 10
    j = 0;                                               // 11
    while (i < left_size && j < right_size)              
    {
        if (left_array[i] <= right_array[j])             
        {
            array[k] = left_array[i];                    // 12
            k++;                                         // 13
            i++;                                         // 14
        }
        else
        {
            array[k] = right_array[j];                   // 15
            k++;                                         // 16
            j++;                                         // 17
        }
    }
    while (i < left_size)                                
    {
        array[k] = left_array[i];                        // 18
        k++;                                             // 19
        i++;                                             // 20
    }
    while (j < right_size)                               
    {
        array[k] = right_array[j];                       // 21
        k++;                                             // 22
        j++;                                             // 23
    }
    free(left_array);                                    // 24
    free(right_array);
    return 0;
}
