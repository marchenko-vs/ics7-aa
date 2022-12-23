static void pos_bucket_sort(std::vector<int> &array, const std::size_t size)
{  
    if (size < 2)
        return;
    double max = get_max(array, size);
    double min = get_min(array, size);
    int range = std::ceil((max - min) / NUM_OF_BUCKETS);
    std::vector<int> buckets[NUM_OF_BUCKETS];
    for (std::size_t i = 0; i < size; i++)
    {
        int bucket_index = std::floor((array[i] - min) / range);
        if (bucket_index == NUM_OF_BUCKETS)
            bucket_index--;
        buckets[bucket_index].push_back(array[i]);
    }
    for (int i = 0; i < NUM_OF_BUCKETS; i++)
        cocktail_sort(buckets[i], buckets[i].size());
    int index = 0;
    for (int i = 0; i < NUM_OF_BUCKETS; i++)
    {
        for (std::size_t j = 0; j < buckets[i].size(); j++)
        {
            array[index] = buckets[i][j];
            index++;
        }
    }
}

void bucket_sort(std::vector<int> &array, const std::size_t size)
{ 
    if (size < 2)
        return;
    int pos_elements_count = 0, neg_elements_count = 0;
    for (std::size_t i = 0; i < size; i++)
    {
        if (array[i] >= 0)
            pos_elements_count++;
        else
            neg_elements_count++;
    }
    std::vector<int> pos_array;
    std::vector<int> neg_array;
    int index = 0;
    if (neg_elements_count > 0)
    {
        for (std::size_t i = 0; i < size; i++)
            if (array[i] < 0)
                neg_array.push_back(-array[i]);
        pos_bucket_sort(neg_array, neg_array.size());
        reverse_array(neg_array, neg_array.size());
    }
    if (pos_elements_count > 0)
    {
        for (std::size_t i = 0; i < size; i++)
            if (array[i] >= 0)
                pos_array.push_back(array[i]);
        pos_bucket_sort(pos_array, pos_array.size());
    }
    if (neg_elements_count > 0)
    {
        for (std::size_t i = 0; i < neg_array.size(); i++)
        {
            array[index] = -neg_array[i];
            index++;
        }
    }
    if (pos_elements_count > 0)
    {
        for (std::size_t i = 0; i < pos_array.size(); i++)
        {
            array[index] = pos_array[i];
            index++;
        }
    }
}
