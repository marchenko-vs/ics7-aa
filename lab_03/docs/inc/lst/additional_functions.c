static void reverse_array(std::vector<int> &array, const std::size_t size)
{
    if (size < 2)
        return;
    std::size_t last_elem_index = size / 2;
    for (std::size_t i = 0; i < last_elem_index; i++)
        std::swap(array[i], array[size - i - 1]);
}

static int get_max(const std::vector<int> &array, const std::size_t size)
{
    int max = array[0];
    for (std::size_t i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

static int get_min(const std::vector<int> &array, const std::size_t size)
{
    int min = array[0];
    for (std::size_t i = 1; i < size; i++)
        if (array[i] < min)
            min = array[i];
    return min;
}
