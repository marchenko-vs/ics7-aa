void cocktail_sort(std::vector<int> &array, const std::size_t size)
{
    if (size < 2)
        return;
    bool flag = true;
    int start = 0, end = size - 1;
    while (flag)
    {
        flag = false;
        for (int i = start; i < end; ++i)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
        flag = false;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
                flag = true;
            }
        }
        ++start;
    }
}
