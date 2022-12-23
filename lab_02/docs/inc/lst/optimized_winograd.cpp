int optimized_winograd_mul(const matrix_t &matrix_1, const matrix_t &matrix_2, matrix_t &matrix_res)
{
    if (matrix_1.columns != matrix_2.rows)
        return 1;
    matrix_res.rows = matrix_1.rows;
    matrix_res.columns = matrix_2.columns;
    std::vector<int> mul_horizontal;
    std::vector<int> mul_vertical;
    std::size_t rows = matrix_1.rows;
    std::size_t rows_and_columns = matrix_1.columns;
    std::size_t columns = matrix_2.columns;
    std::size_t d = rows_and_columns / 2;
    for (std::size_t i = 0; i < rows; i++)
    {
        mul_horizontal.push_back(0);
        for (std::size_t j = 0; j < d; j++)
        {
            std::size_t index = j << 1;
            mul_horizontal[i] += matrix_1.elements[i][index] * 
            matrix_1.elements[i][index + 1];
        }
    }
    for (std::size_t i = 0; i < columns; i++)
    {
        mul_vertical.push_back(0);
        for (std::size_t j = 0; j < d; j++)
        {
            std::size_t index = j << 1;
            mul_vertical[i] += matrix_2.elements[index][i] * 
            matrix_2.elements[index + 1][i];
        }
    }
    for (std::size_t i = 0; i < rows; i++)
    {
        std::vector<int> row;
        for (std::size_t j = 0; j < columns; j++)
        {
            row.push_back(-mul_horizontal[i] - mul_vertical[j]);
            for (std::size_t k = 0; k < d; k++)
            {
                std::size_t index = k << 1;
                row[j] += (matrix_1.elements[i][index] + 
                matrix_2.elements[index + 1][j]) *
                (matrix_1.elements[i][index + 1] + 
                matrix_2.elements[index][j]);
            }
        }
        matrix_res.elements.push_back(row);
    }
    if (rows_and_columns % 2 != 0)
    {
        for (std::size_t i = 0; i < rows; i++)
        {
            for (std::size_t j = 0; j < columns; j++)
            {
                std::size_t index = rows_and_columns - 1;
                matrix_res.elements[i][j] += 
                matrix_1.elements[i][index] *
                matrix_2.elements[index][j];
            }
        }
    }
    return 0;
}
