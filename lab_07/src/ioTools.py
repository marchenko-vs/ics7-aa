import aco
import numpy as np
import tsp


def parameterization():
    alpha_array = [num / 10 for num in range(1, 10)]
    evaporation_array = [num / 10 for num in range(1, 10)]
    days_array = [50, 100, 200]
    size = 10
    size, matrix = get_matrix()
    if size == 0:
        return
    optimal = tsp.tsp_algorithm(matrix, size)
    file = open("parameterization.txt", "w")
    count = 0
    count_all = len(alpha_array) * len(evaporation_array)
    counter = 0
    file.write('\\begin{table}[H]\n'
                '\\caption{Параметры для класса данных №2}\n'
                '\\label{tabular:params2}\n'
                '\\begin{tabular}{|>{\\raggedleft}p{1cm}|>{\\raggedleft}p{1cm}|'
                '>{\\raggedleft}p{1cm}|>{\\raggedleft}p{4cm}|>{\\raggedleft}p{3cm}|>{\\raggedleft}p{3cm}|}\n'
                '\\hline\n'
                '$\\alpha$ & $\\beta$ & $p$ & Количество дней & Результат & Ошибка\n'
                '\\tabularnewline\n'
                '\\hline\n')
    for alpha in alpha_array:
        beta = 1 - alpha
        for k_eva in evaporation_array:
            count += 1
            for days in days_array:
                if counter == 15:
                    counter = 0
                    file.write('\\end{tabular}\n'
                               '\\end{table}\n\n')
                    file.write('\\pagebreak\n')
                    file.write('\\noindent Продолжение таблицы~\\ref{tabular:params2}\n'
                                '\\begin{table}[H]\n'
                                '\\begin{tabular}{|>{\\raggedleft}p{1cm}|>'
                                '{\\raggedleft}p{1cm}|>{\\raggedleft}p{1cm}|>'
                                '{\\raggedleft}p{4cm}|>{\\raggedleft}p{3cm}|>'
                                '{\\raggedleft}p{3cm}|}\n'
                                '\\hline\n'
                                '$\\alpha$ & $\\beta$ & $p$ & Количество дней '
                                '& Результат & Ошибка\n'
                                '\\tabularnewline\n'
                                '\\hline\n')
                res = aco.aco_algorithm(matrix, size, alpha, beta, k_eva, days)
                sep = "&"
                end = "\\\\"
                row = "%.1f %s %.1f %s %.1f %s %d %s %d %s %d %s\n" \
                    % (alpha, sep, beta, sep, k_eva, sep, days, sep, optimal[0], 
                    sep, res[0] - optimal[0], end)
                file.write(row)
                file.write("\\tabularnewline\n\\hline\n")
                counter += 1
    file.write('\\end{tabular}\n\
\\end{table}\n')
    file.close()


def get_option():
    try:
        command = int(input("Меню.\n"
                            "1. Алгоритм полного перебора.\n"
                            "2. Муравьиный алгоритм.\n"
                            "3. Автоматическая параметризация.\n"
                            "4. Временной анализ.\n"
                            "0. Выход.\n"
                            "Выбор: "))
    except ValueError:
        command = -1
    if command < 0 or command > 4:
        print("Ошибка: неверный тип данных.")
    return command


def get_matrix():
    filename = input("Введите путь к файлу: ")
    try:
        file = open(filename, "r")
        size = len(file.readline().split())
        matrix = np.zeros((size, size), dtype=int)
        file.seek(0)
        i = 0
        for line in file.readlines():
            j = 0
            for num in line.split():
                matrix[i][j] = int(num)
                j += 1
            i += 1
        file.close()
        print("Матрица расстояний: ")
        for i in range(size):
            for j in range(size):
                print("%5d" %(matrix[i][j]), end=" ")
            print('')
    except:
        size = 0
        matrix = [[]]
        print("Ошибка: невозможно прочитать данные файла.")
    return size, matrix


def get_coefficients():
    try:
        alpha = float(input("Введите коэффициент alpha: "))
        beta = beta = 1 - alpha
        print("Коэффициент beta = ", beta)
        evaporation = float(input("Введите коэффициент evaporation: "))
        days = int(input("Введите количество дней: "))
    except:
        print("Ошибка: введены неверные коэффициенты.")
        alpha = beta = evaporation = days = -1
    return alpha, beta, evaporation, days
