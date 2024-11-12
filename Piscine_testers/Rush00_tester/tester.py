import os
import subprocess
import time

# Colores ANSI para salida de terminal
RESET = "\033[0m"
BOLD = "\033[1m"
GREEN = "\033[32m"
RED = "\033[31m"
BLUE = "\033[34m"

# Espacio para poner un encabezado inicial
def print_header():
    print(BLUE + BOLD + """
	██╗  ██╗██████╗     ██████╗ ██╗   ██╗███████╗██╗  ██╗ ██████╗  ██████╗     ████████╗███████╗███████╗████████╗███████╗██████╗ 
	██║  ██║╚════██╗    ██╔══██╗██║   ██║██╔════╝██║  ██║██╔═████╗██╔═████╗    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗
	███████║ █████╔╝    ██████╔╝██║   ██║███████╗███████║██║██╔██║██║██╔██║       ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝
	╚════██║██╔═══╝     ██╔══██╗██║   ██║╚════██║██╔══██║████╔╝██║████╔╝██║       ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗
	     ██║███████╗    ██║  ██║╚██████╔╝███████║██║  ██║╚██████╔╝╚██████╔╝       ██║   ███████╗███████║   ██║   ███████╗██║  ██║
	     ╚═╝╚══════╝    ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝        ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
                                                                2024/11/12 - ismherna@student.42.fr - 42 Madrid - Ismael Hernández                                                    

	""" + RESET)

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

# Pruebas de ejemplo para rush02
example_tests_rush02 = [
    {"input": "5 3", "expected_output": "ABBBA\nB   B\nCBBBC\n"},
    {"input": "5 1", "expected_output": "ABBBA\n"},
    {"input": "1 1", "expected_output": "A\n"},
    {"input": "1 5", "expected_output": "A\nB\nB\nB\nC\n"},
    {"input": "4 4", "expected_output": "ABBA\nB  B\nB  B\nCBBC\n"}
]

# Pruebas de ejemplo para rush03
example_tests_rush03 = [
    {"input": "5 3", "expected_output": "ABBBC\nB   B\nABBBC\n"},
    {"input": "5 1", "expected_output": "ABBBC\n"},
    {"input": "1 1", "expected_output": "A\n"},
    {"input": "1 5", "expected_output": "A\nB\nB\nB\nA\n"},
    {"input": "4 4", "expected_output": "ABBC\nB  B\nB  B\nABBC\n"}
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
            print(f"{RED}Error: {file} no encontrado en {directory}{RESET}")
            return False
    print(f"{GREEN}Todos los archivos requeridos están presentes.{RESET}")
    return True

# Función para compilar el proyecto con un archivo específico de rush
def compile_project(directory, rush_file):
    # Usar el nombre del archivo de rush para evitar sobrescribir el ejecutable
    output_file = rush_file.replace('.c', '')
    compile_command = f"gcc -Wall -Wextra -Werror {directory}/main.c {directory}/ft_putchar.c {directory}/{rush_file} -o {output_file}"
    result = subprocess.run(compile_command, shell=True, stderr=subprocess.PIPE)
    if result.returncode != 0:
        print(f"{RED}Error en la compilación de {rush_file}:{RESET}")
        print(result.stderr.decode('utf-8'))
        return False
    print(f"{GREEN}Compilación exitosa de {rush_file}.{RESET}")
    return True

# Función para ejecutar pruebas de ejemplo
def run_basic_tests(executable, test_cases):
    for test in test_cases:
        input_data = test["input"].split()  # Separamos el input en x y y
        process = subprocess.Popen([executable] + input_data, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        stdout, stderr = process.communicate()

        if process.returncode != 0 or stderr:
            print(f"{RED}Error durante la ejecución: {stderr}{RESET}")
            continue

        # Comparar salida esperada y obtenida
        if stdout.strip() == test["expected_output"].strip():
            print(f"{GREEN}Prueba con input {test['input']} pasó.{RESET}")
            print(f"{BLUE}Salida esperada:{RESET}\n{test['expected_output']}")
            print(f"{BLUE}Salida obtenida:{RESET}\n{stdout}")
        else:
            print(f"{RED}Prueba con input {test['input']} falló.{RESET}")
            print(f"{BLUE}Salida esperada:{RESET}\n{test['expected_output']}")
            print(f"{BLUE}Salida obtenida:{RESET}\n{stdout}")
# Mostrar el header
print_header()

# Retraso de 3 segundos después de mostrar el header
time.sleep(3)

# Verificar la existencia de los archivos necesarios
if check_files_exist(project_directory, required_files):

    # Archivos de rush a compilar y sus pruebas
    rush_files_and_tests = [
        ('rush00.c', example_tests_rush00),
        ('rush01.c', example_tests_rush01),
        ('rush02.c', example_tests_rush02),  # Corregir para usar las pruebas adecuadas para rush02
        ('rush03.c', example_tests_rush03),  # Corregir para usar las pruebas adecuadas para rush03
        ('rush04.c', example_tests_rush04)
    ]

    for rush_file, tests in rush_files_and_tests:
        print(f"\nCompilando y ejecutando pruebas para {rush_file}...")
        if compile_project(project_directory, rush_file):
            # Usar el nombre del archivo de rush para ejecutar las pruebas con el ejecutable correcto
            output_file = rush_file.replace('.c', '')
            run_basic_tests(f'./{output_file}', tests)
