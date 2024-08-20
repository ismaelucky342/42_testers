import subprocess
import random
import sys

INT_MAX = 2147483647
INT_MIN = -2147483648

PUSH_SWAP_EXEC = "./push_swap"

def generate_random_numbers(size):
    return random.sample(range(INT_MIN, INT_MAX), size)

test_cases = [
    [2, 1, 3, 6, 5, 8],  # Caso simple
    [9, 1, 5, 2, 8],     # Otro caso simple
    [3, 2, 1],           # Caso en reversa
    [1, 2, 3, 4, 5],     # Ya ordenado
    [1],                 # Un solo elemento
    [],                  # Entrada vacía
    [INT_MAX, INT_MIN, 0], # Números extremos
    [INT_MAX, INT_MAX, INT_MIN], # Duplicados de máximo
    [INT_MAX + 1, INT_MIN - 1],  # Fuera de rango
]

test_cases.append(generate_random_numbers(100))  # Caso con 100 números
test_cases.append(generate_random_numbers(500))  # Caso con 500 números

def run_push_swap(test_case):
    input_str = ' '.join(map(str, test_case))
    
    try:
        process = subprocess.run(
            [PUSH_SWAP_EXEC] + input_str.split(),
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=10  # Limita el tiempo de ejecución a 10 segundos
        )
    except subprocess.TimeoutExpired:
        return None, "Execution timed out"
    
    return process.stdout, process.stderr

def run_tests():
    for i, test_case in enumerate(test_cases):
        print(f"Running test case {i + 1}: {test_case[:10]}... (total {len(test_case)} numbers)")
        
        output, errors = run_push_swap(test_case)
        
        if errors:
            print(f"Error occurred: {errors}")
        else:
            print(f"Output:\n{output}")
        
        print("-" * 40)

if __name__ == "__main__":
    run_tests()
