import os
import subprocess

# Configuración de directorios y archivos
project_directory = '../../ex00'  # Cambiar a la ruta donde están los archivos
required_files = ['main.c', 'ft_putchar.c', 'rush00.c', 'rush01.c', 'rush02.c', 'rush03.c', 'rush04.c']

# Pruebas de ejemplo para rush00
example_tests_rush00 = [
    {"input": "5 3", "expected_output": "o---o\n|   |\no---o\n"},
    {"input": "5 1", "expected_output": "o---o\n"},
    {"input": "1 1", "expected_output": "o\n"},
    {"input": "1 5", "expected_output": "o\n|\n|\n|\no\n"},
    {"input": "4 4", "expected_output": "o--o\n|  |\n|  |\no--o\n"}
]

# Pruebas de ejemplo para rush01
example_tests_rush01 = [
    {"input": "5 3", "expected_output": "/***\\\n*   *\n\\***/\n"},
    {"input": "5 1", "expected_output": "/***\\\n"},
    {"input": "1 1", "expected_output": "/\n"},
    {"input": "1 5", "expected_output": "/\n*\n*\n*\n\\\n"},
    {"input": "4 4", "expected_output": "/**\\\n*  *\n*  *\n\\**/\n"}
]

# Pruebas de ejemplo para rush04
example_tests_rush04 = [
    {"input": "5 3", "expected_output": "ABBBC\nB   B\nCBBBA\n"},
    {"input": "5 1", "expected_output": "ABBBC\n"},
    {"input": "1 1", "expected_output": "A\n"},
    {"input": "1 5", "expected_output": "A\nB\nB\nB\nC\n"},
    {"input": "4 4", "expected_output": "ABBC\nB  B\nB  B\nCBBA\n"}
]

# Función para verificar la existencia de archivos
def check_files_exist(directory, files):
    for file in files:
        if not os.path.isfile(os.path.join(directory, file)):
            print(f"Error: {file} no encontrado en {directory}")
            return False
    print("Todos los archivos requeridos están presentes.")
    return True

# Función para compilar el proyecto con un archivo específico de rush
def compile_project(directory, rush_file):
    compile_command = f"gcc -Wall -Wextra -Werror {directory}/main.c {directory}/ft_putchar.c {directory}/{rush_file} -o output"
    result = subprocess.run(compile_command, shell=True, stderr=subprocess.PIPE)
    if result.returncode != 0:
        print(f"Error en la compilación de {rush_file}:")
        print(result.stderr.decode('utf-8'))
        return False
    print(f"Compilación exitosa de {rush_file}.")
    return True

# Función para ejecutar pruebas de ejemplo
def run_basic_tests(executable, test_cases):
    for test in test_cases:
        process = subprocess.Popen([executable], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        stdout, stderr = process.communicate(input=test["input"])
        if process.returncode != 0 or stderr:
            print(f"Error durante la ejecución: {stderr}")
            continue

        if stdout.strip() == test["expected_output"].strip():
            print(f"Prueba con input {test['input']} pasó.")
        else:
            print(f"Prueba con input {test['input']} falló.")
            print(f"Salida esperada:\n{test['expected_output']}")
            print(f"Salida obtenida:\n{stdout}")

# Verificar la existencia de los archivos necesarios
if check_files_exist(project_directory, required_files):
    # Archivos de rush a compilar y sus pruebas
    rush_files_and_tests = [
        ('rush00.c', example_tests_rush00),
        ('rush01.c', example_tests_rush01),
        ('rush02.c', example_tests_rush00),  # Usa las pruebas adecuadas si son diferentes
        ('rush03.c', example_tests_rush00),  # Usa las pruebas adecuadas si son diferentes
        ('rush04.c', example_tests_rush04)
    ]

    for rush_file, tests in rush_files_and_tests:
        print(f"\nCompilando y ejecutando pruebas para {rush_file}...")
        if compile_project(project_directory, rush_file):
            run_basic_tests('./output', tests)
