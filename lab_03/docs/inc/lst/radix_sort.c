static void counting_sort(std::vector<int> &array, const std::size_t size, int exp)
{
    if (size < 2)
        return;
    std::vector<int> output_array(size, 0);
    std::vector<int> count(10, 0);
    for (std::size_t i = 0; i < size; i++)
    {
        int index = (array[i] / exp) % 10;
        count[index]++;
    }
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {
        int index = (array[i] / exp) % 10;
        output_array[count[index] - 1] = array[i];
        count[index]--;
    }
    for (std::size_t i = 0; i < size; i++)
        array[i] = output_array[i];
}
 
void radix_sort(std::vector<int> &array, const std::size_t size)
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
        int max = get_max(neg_array, neg_array.size());
        for (int exp = 1; max / exp > 0; exp *= 10)
            counting_sort(neg_array, neg_array.size(), exp);
        reverse_array(neg_array, neg_array.size());
    }
    if (pos_elements_count > 0)
    {
        for (std::size_t i = 0; i < size; i++)
            if (array[i] >= 0)
                pos_array.push_back(array[i]);
        int max = get_max(pos_array, pos_array.size());
        for (int exp = 1; max / exp > 0; exp *= 10)
            counting_sort(pos_array, pos_array.size(), exp);
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
