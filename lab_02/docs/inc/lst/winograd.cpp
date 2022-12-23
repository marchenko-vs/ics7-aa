int winograd_mul(const matrix_t &matrix_1, const matrix_t &matrix_2, matrix_t &matrix_res)
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
    for (std::size_t i = 0; i < rows; i++)
    {
        mul_horizontal.push_back(0);
        for (std::size_t j = 0; j < rows_and_columns / 2; j++)
            mul_horizontal[i] = mul_horizontal[i] +
                                matrix_1.elements[i][2 * j] * 
                                matrix_1.elements[i][2 * j + 1];
    }
    for (std::size_t i = 0; i < columns; i++)
    {
        mul_vertical.push_back(0);
        for (std::size_t j = 0; j < rows_and_columns / 2; j++)
            mul_vertical[i] = mul_vertical[i] +
                              matrix_2.elements[2 * j][i] * 
                              matrix_2.elements[2 * j + 1][i];
    }
    for (std::size_t i = 0; i < rows; i++)
    {
        std::vector<int> row;
        for (std::size_t j = 0; j < columns; j++)
        {
            row.push_back(-mul_horizontal[i] - mul_vertical[j]);
            for (std::size_t k = 0; k < rows_and_columns / 2; k++)
            {
                row[j] = row[j] + (matrix_1.elements[i][2 * k] + 
                matrix_2.elements[2 * k + 1][j]) *
                (matrix_1.elements[i][2 * k + 1] + 
                matrix_2.elements[2 * k][j]);
            }
        }
        matrix_res.elements.push_back(row);
    }
    if (rows_and_columns % 2 != 0)
    {
        for (std::size_t i = 0; i < rows; i++)
        {
            for (std::size_t j = 0; j < columns; j++)
                matrix_res.elements[i][j] = matrix_res.elements[i][j] +
                matrix_1.elements[i][rows_and_columns - 1] *
                matrix_2.elements[rows_and_columns - 1][j];
        }
    }
    return 0;
}
