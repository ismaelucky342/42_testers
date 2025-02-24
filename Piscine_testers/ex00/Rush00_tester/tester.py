import os
import subprocess
import time

# Colores ANSI para salida de terminal
RESET = "\033[0m"
BOLD = "\033[1m"
GREEN = "\033[32m"
RED = "\033[31m"
BLUE = "\033[34m"

# Encabezado inicial
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
project_directory = '../../ex00'  # Cambiar según sea necesario
rush_files_and_tests = {
    'rush00.c': [
        {"input": "5 3", "expected_output": "o---o\n|   |\no---o\n"},
    {"input": "5 1", "expected_output": "o---o\n"},
    {"input": "1 1", "expected_output": "o\n"},
    {"input": "1 5", "expected_output": "o\n|\n|\n|\no\n"},
    {"input": "4 4", "expected_output": "o--o\n|  |\n|  |\no--o\n"}
    ],
    'rush01.c': [
        {"input": "5 3", "expected_output": "/***\\\n*   *\n\\***/\n"},
    {"input": "5 1", "expected_output": "/***\\\n"},
    {"input": "1 1", "expected_output": "/\n"},
    {"input": "1 5", "expected_output": "/\n*\n*\n*\n\\\n"},
    {"input": "4 4", "expected_output": "/**\\\n*  *\n*  *\n\\**/\n"}
    ],
    'rush02.c': [
        {"input": "5 3", "expected_output": "ABBBA\nB   B\nCBBBC\n"},
    {"input": "5 1", "expected_output": "ABBBA\n"},
    {"input": "1 1", "expected_output": "A\n"},
    {"input": "1 5", "expected_output": "A\nB\nB\nB\nC\n"},
    {"input": "4 4", "expected_output": "ABBA\nB  B\nB  B\nCBBC\n"}
    ],
    'rush03.c': [
        {"input": "5 3", "expected_output": "ABBBC\nB   B\nABBBC\n"},
    {"input": "5 1", "expected_output": "ABBBC\n"},
    {"input": "1 1", "expected_output": "A\n"},
    {"input": "1 5", "expected_output": "A\nB\nB\nB\nA\n"},
    {"input": "4 4", "expected_output": "ABBC\nB  B\nB  B\nABBC\n"}
    ],
    'rush04.c': [
        {"input": "5 3", "expected_output": "ABBBC\nB   B\nCBBBA\n"},
    {"input": "5 1", "expected_output": "ABBBC\n"},
    {"input": "1 1", "expected_output": "A\n"},
    {"input": "1 5", "expected_output": "A\nB\nB\nB\nC\n"},
    {"input": "4 4", "expected_output": "ABBC\nB  B\nB  B\nCBBA\n"}
    ]
}

def compile_project(directory, rush_file):
    output_file = rush_file.replace('.c', '')
    compile_command = f"gcc -Wall -Wextra -Werror {directory}/main.c {directory}/ft_putchar.c {directory}/{rush_file} -o {output_file}"
    result = subprocess.run(compile_command, shell=True, stderr=subprocess.PIPE)
    if result.returncode != 0:
        print(f"{RED}Error en la compilación de {rush_file}:{RESET}\n{result.stderr.decode('utf-8')}")
        return None
    return output_file

def run_tests(executable, test_cases):
    for test in test_cases:
        input_data = test["input"].split()
        process = subprocess.Popen([f"./{executable}"] + input_data, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        stdout, stderr = process.communicate()
        
        if stderr:
            print(f"{RED}Error durante la ejecución: {stderr}{RESET}")
        elif stdout.strip() == test["expected_output"].strip():
            print(f"{GREEN}Prueba {test['input']} pasó.{RESET}")
        else:
            print(f"{RED}Prueba {test['input']} falló.{RESET}\nEsperado:\n{test['expected_output']}\nObtenido:\n{stdout}")

def main():
    print_header()
    time.sleep(1)
    
    print("Selecciona el rush a probar:")
    for i, rush in enumerate(rush_files_and_tests.keys()):
        print(f"{i}: {rush}")
    
    choice = input("Ingresa el número del rush: ")
    
    try:
        choice = int(choice)
        rush_file = list(rush_files_and_tests.keys())[choice]
    except (ValueError, IndexError):
        print(f"{RED}Selección inválida. Saliendo...{RESET}")
        return
    
    print(f"Compilando y probando {rush_file}...")
    executable = compile_project(project_directory, rush_file)
    if executable:
        run_tests(executable, rush_files_and_tests[rush_file])

if __name__ == "__main__":
    main()
