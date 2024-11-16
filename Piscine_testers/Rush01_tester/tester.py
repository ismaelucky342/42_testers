import subprocess
import os
import sys

def compile_program():
    """Compila todos los archivos .c en el directorio y genera el ejecutable rush-01."""
    print("Compiling the program...")

    # Comando para compilar todos los archivos .c y generar el ejecutable rush-01
    compile_command = "gcc -Wall -Wextra -Werror -o rush-01 *.c"
    
    try:
        result = subprocess.run(compile_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if result.returncode != 0:
            print("Error during compilation:")
            print(result.stderr)
            sys.exit(1)  # Terminar si hay error en la compilación
        else:
            print("Compilation successful!")
    except Exception as e:
        print(f"Error compiling the program: {e}")
        sys.exit(1)

def run_program_with_input(input_data):
    """Ejecuta el programa rush-01 con una entrada específica y devuelve la salida."""
    try:
        result = subprocess.run(
            ['./rush-01', input_data],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        return result.stdout, result.stderr, result.returncode
    except Exception as e:
        print(f"Error al ejecutar el programa: {e}")
        return "", str(e), -1


def compare_output(actual_output, expected_output):
    """Compara la salida real del programa con la salida esperada."""
    if actual_output.strip() == expected_output.strip():
        print("Test Passed!")
    else:
        print("Test Failed!")
        print("Expected Output:")
        print(expected_output)
        print("Actual Output:")
        print(actual_output)


def check_memory_leaks(input_data):
    """Verifica si el programa tiene fugas de memoria usando Valgrind."""
    valgrind_command = [
        'valgrind', '--leak-check=full', '--show-leak-kinds=all', '--track-origins=yes', 
        './rush-01', input_data
    ]
    
    try:
        result = subprocess.run(
            valgrind_command,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        if 'definitely lost' in result.stderr or 'indirectly lost' in result.stderr:
            print("Memory leaks detected:")
            print(result.stderr)
        else:
            print("No memory leaks detected!")
    except Exception as e:
        print(f"Error al ejecutar Valgrind: {e}")


def run_tests():
    # Definir casos de prueba: entradas y salidas esperadas
    test_cases = [
        {
            "input": "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2",
            "expected_output": "1 2 3 4\n2 3 4 1\n3 4 1 2\n4 1 2 3\n"
        },
        {
            "input": "1 2 3 4 4 3 2 1 1 2 2 2 4 3 2 1",
            "expected_output": "Error\n"
        }
    ]

    for test in test_cases:
        print(f"Running test with input: {test['input']}")
        
        # Ejecutar el programa y obtener la salida
        actual_output, error_output, return_code = run_program_with_input(test["input"])
        
        # Comparar la salida
        compare_output(actual_output, test["expected_output"])

        # Verificar los leaks de memoria
        check_memory_leaks(test["input"])

        print("-" * 50)

if __name__ == "__main__":
    # Compilar el programa antes de ejecutar las pruebas
    compile_program()
    
    # Ejecutar las pruebas
    run_tests()
