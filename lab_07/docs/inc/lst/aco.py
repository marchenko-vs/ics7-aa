import random
import numpy as np
import ioTools as io
import tsp


MIN_PHEROMONE = 0.01


def get_q(matrix, size):
    q = 0
    count = 0
    for i in range(size):
        for j in range(size):
            if i != j:
                q += matrix[i][j]
                count += 1
    return q / count


def get_pheromone_matrix(size):
    pheromone_matrix = [[1 for i in range(size)] 
                        for j in range(size)]
    return pheromone_matrix


def get_visible_matrix(matrix, size):
    visible_matrix = [[(1.0 / matrix[i][j] if (i != j) else 0) 
                        for j in range(size)] 
                            for i in range(size)]
    return visible_matrix


def get_visited_vertices(way, colony):
    visited_array = [[] for i in range(colony)]
    for i in range(colony):
        visited_array[i].append(way[i])
    return visited_array


def update_pheromone_matrix(matrix, size, visited_array, pheromone_matrix, q, evaporation):
    colony = size
    for i in range(size):
        for j in range(size):
            delta = 0
            for colony in range(colony):
                length = tsp.get_length(matrix, size, visited_array[colony])
                delta += q / length
            pheromone_matrix[i][j] *= (1 - evaporation)
            pheromone_matrix[i][j] += delta
            if pheromone_matrix[i][j] < MIN_PHEROMONE:
               pheromone_matrix[i][j] = MIN_PHEROMONE
    return pheromone_matrix


def get_next_vertex(array):
    size = len(array)
    numb = 0
    i = 0
    probability = random.random()
    while numb < probability and i < size:
        numb += array[i]
        i += 1
    return i


def get_probability(pheromone_matrix, visible_matrix, visited_array, size, colony, alpha, beta):
    array = [0] * size
    for i in range(size):
        if i not in visited_array[colony]:
            colony_i = visited_array[colony][-1]
            array[i] = pow(pheromone_matrix[colony_i][i], alpha) * \
                    pow(visible_matrix[colony_i][i], beta)
        else:
            array[i] = 0
    array_sum = sum(array)
    for i in range(size):
        array[i] /= array_sum  
    return array


def aco_algorithm(matrix, size, alpha, beta, evaporation, days):
    pheromone_matrix = get_pheromone_matrix(size)
    visible_matrix  = get_visible_matrix(matrix, size)
    q = get_q(matrix, size)
    shortest_way = []
    min_length = float("inf")
    for j in range(days):
        visited_array = get_visited_vertices(np.arange(size), size)
        for i in range(size):
            while len(visited_array[i]) != size:
                array = get_probability(pheromone_matrix, visible_matrix, visited_array, size, i, alpha, beta)  
                next_place = get_next_vertex(array)
                visited_array[i].append(next_place - 1)
            visited_array[i].append(visited_array[i][0])
            length = tsp.get_length(matrix, size, visited_array[i])
            if length < min_length:
                min_length = length
                shortest_way = visited_array[i]
        pheromone_matrix = update_pheromone_matrix(matrix, size, visited_array, pheromone_matrix, q, evaporation)
    for i in range(len(shortest_way)):
        shortest_way[i] += 1
    return min_length, shortest_way
    