import aco
import ioTools as io
import timeAnalysis as ta
import tsp

option = -1
while option != 0:
    option = io.get_option()
    if option == 1:
        tsp.get_way()
    elif option == 2:
        aco.get_way()
    elif option == 3:
        io.parameterization()
    elif option == 4:
        ta.compare_time()
