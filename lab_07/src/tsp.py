import numpy as np
import itertools as it
import ioTools as io


def get_length(matrix, size, way):
    length = 0
    for i in range(size):
        beg_city = way[i]
        end_city = way[i + 1]
        length += matrix[beg_city][end_city]
    return length


def tsp_algorithm(matrix, size):
    cities = np.arange(size)
    cities_combs = []
    for combination in it.permutations(cities):
        cities_combs.append(list(combination))
    shortest_way = []
    min_length = float("inf")
    for i in range(len(cities_combs)):
        cities_combs[i].append(cities_combs[i][0])
        length = get_length(matrix, size, cities_combs[i])
        if length < min_length:
            min_length = length
            shortest_way = cities_combs[i]
    for i in range(len(shortest_way)):
        shortest_way[i] += 1
    return min_length, shortest_way


def get_way():
    size, matrix = io.get_matrix()
    if size == 0:
        return
    min_length, shortest_way = tsp_algorithm(matrix, size)
    print(f"Минимальная длина пути: {min_length}.\n"
          f"Минимальный путь: {shortest_way}.")
