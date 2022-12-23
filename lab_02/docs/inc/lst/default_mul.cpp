int default_mul(const matrix_t &matrix_1, const matrix_t &matrix_2, matrix_t &matrix_res)
{
    if (matrix_1.columns != matrix_2.rows)
        return 1;
    matrix_res.rows = matrix_1.rows;
    matrix_res.columns = matrix_2.columns;
    std::size_t rows = matrix_1.rows;
    std::size_t rows_and_columns = matrix_1.columns;
    std::size_t columns = matrix_2.columns;
    for (std::size_t i = 0; i < rows; i++)
    {
        std::vector<int> row;
        for (std::size_t j = 0; j < columns; j++)
        {
            int sum = 0;
            for (std::size_t k = 0; k < rows_and_columns; k++)
                sum += matrix_1.elements[i][k] * matrix_2.elements[k][j];
            row.push_back(sum);
        }
        matrix_res.elements.push_back(row);
    }
    return 0;
}
