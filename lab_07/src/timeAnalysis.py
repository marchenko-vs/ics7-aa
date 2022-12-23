import aco
import random
import time
import tsp
import numpy as np


def generate_matrix(size, start_random, end_random):
    matrix = np.zeros((size, size), dtype=int)
    for i in range(size):
        for j in range(size):
            if i == j:
                num = 0
            else:
                num = random.randint(start_random, end_random)
            matrix[i][j] = num
            matrix[j][i] = num
    return matrix


def compare_time():
    time_tsp = []
    time_aco = []
    size_array = [5, 6, 7, 8, 9, 10]
    for size in size_array:
        matrix = generate_matrix(size, 1, 2)
        start = time.process_time_ns()
        tsp.tsp_algorithm(matrix, size)
        end = time.process_time_ns()
        print(f"Время работы алгоритма полного перебора для {size} вершин: {end - start} мс.")
        start = time.process_time_ns()
        aco.aco_algorithm(matrix, size, 0.5, 0.5, 0.5, 20)
        end = time.process_time_ns()
        print(f"Время работы муравьиного алгоритма для {size} вершин: {end - start} мс.")
