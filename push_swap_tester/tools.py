import os
import math
import random
import subprocess

def check_system():
    system_type = os.uname().sysname
    if system_type == "Linux":
        return "Linux"
    elif system_type == "Darwin":
        return "Mac"

def all_combinations(x):
    from itertools import permutations
    return list(permutations(range(1, x + 1)))

def generate_sequence(tot):
    phi = (math.sqrt(5) - 1) / 2 * tot
    sequence = [0] * tot
    result = []
    i = 0
    nd = phi

    while i < tot:
        rounded_value = round(nd)
        if sequence[rounded_value] == 0:
            result.append(rounded_value)
            sequence[rounded_value] = 1
            i += 1
        nd += phi
        if nd > tot:
            nd %= tot
    
    return result

def generate_random_sequence(x):
    if x in [1, 2, 3]:
        return random.sample(range(1, x + 1), x)
    elif x in [35, 100, 150, 500]:
        return random.sample(range(1, 1001), x)
    else:
        return random.sample(range(1, x + 1), x)

def check_moves(x, moves_count, checker_output, exit_status):
    moves_count = int(moves_count)
    exit_status = int(exit_status)
    
    if x == 1:
        result = "\tOK" if moves_count == 0 and checker_output == "OK" else "\tKO"
    elif x in [2, 3]:
        result = "\tOK" if moves_count <= 3 and checker_output == "OK" else "\tKO"
    elif x in [4, 5]:
        result = "\tOK" if moves_count <= 12 and checker_output == "OK" else "\tKO"
    elif x == 100:
        if moves_count < 700:
            result = "\t5 Points!"
        elif moves_count < 900:
            result = "\t4 Points!"
        elif moves_count < 1100:
            result = "\t3 Points!"
        elif moves_count < 1300:
            result = "\t2 Points!"
        elif moves_count < 1500:
            result = "\t1 Points!"
        else:
            result = "\tKO"
    elif x == 500:
        if moves_count < 5500:
            result = "\t5 Points!"
        elif moves_count < 7000:
            result = "\t4 Points!"
        elif moves_count < 8500:
            result = "\t3 Points!"
        elif moves_count < 10000:
            result = "\t2 Points!"
        elif moves_count < 11500:
            result = "\t1 Points!"
        else:
            result = "\tKO"
    else:
        result = "\tKO"

    if checker_output != "OK":
        result = "\tKO"
    
    if exit_status == 139:
        print("\033[1;31m\tSegmentation fault 💀\033[0m")
    elif result == "\tKO":
        print(f"\033[1;31m{result}\033[0m")
    else:
        print(f"\033[1;32m{result}\033[0m")

def set_size(x):
    if x == 1:
        return 1
    elif x == 2:
        return 2
    elif x == 3:
        return 10
    elif x == 5:
        return 20
    elif x in [100, 500]:
        return 50
    else:
        return 10


def norminette():
    norminette_output = subprocess.getoutput("norminette ../ | grep Error | wc -l | tr -d ' ' | tr -d '\n'")
    if int(norminette_output) == 0:
        print("\033[1;42mNORMINETTE OK\033[0m")
    else:
        print("\033[1;41mNORMINETTE KO\033[0m")