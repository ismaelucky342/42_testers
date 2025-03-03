import subprocess
import os
import glob
import time  # Importamos el módulo time

# Colores ANSI para salida de terminal
RESET = "\033[0m"
BOLD = "\033[1m"
GREEN = "\033[32m"
RED = "\033[31m"
BLUE = "\033[34m"

# Configuración del programa
EXECUTABLE = "./rush-01"
TEST_CASES = [
    (" " "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", "1 2 3 4\n2 3 4 1\n3 4 1 2\n4 1 2 3\n"),
    ("1 2 2 2 4 3 2 1 1 2 2 2 4 3 2 1", "Error\n"),
    ("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", "1 2 3 4\n2 3 4 1\n3 4 1 2\n4 1 2 3\n"),
    ("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", "1 2 3 4\n2 3 4 1\n3 4 1 2\n4 1 2 3\n"),
    ("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", "1 2 3 4\n2 3 4 1\n3 4 1 2\n4 1 2 3\n"),
    ("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", "1 2 3 4\n2 3 4 1\n3 4 1 2\n4 1 2 3\n"),
    ("1 2 2 2 4 3 2 1 1 2 2 2 4 3 2 1", "Error\n"),
    ("2 2 1 3 3 1 2 2 2 1 3 2 1 3 2 2", "Error\n"),
    ("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1", "Error\n"),
    ("4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4", "Error\n"),
    ("2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2", "Error\n"),
    ("4 1 4 1 1 4 1 4 4 1 4 1 1 4 1 4", "Error\n"),
    ("1 1 2 2 2 2 1 1 1 2 2 2 2 1 1 2", "Error\n"),
    ("0 5 2 3 1 2 4 6 1 2 3 4 1 2 3 4", "Error\n"),
    ("4 3 2 1 1 2 2 2 4 3 2 1", "Error\n"),
    ("a b c d e f g h i j k l m n o p", "Error\n"),
]

def compile_program():
    print("Compilando el programa...")
    source_files = glob.glob("*.c")  # Encuentra todos los archivos .c en el directorio actual
    if not source_files:
        print("No se encontraron archivos .c para compilar.")
        return False
    result = subprocess.run(
        ["gcc", "-Wall", "-Wextra", "-Werror", "-o", EXECUTABLE] + source_files,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    if result.returncode != 0:
        print("Error al compilar:")
        print(result.stderr.decode())
        return False
    print("Compilación exitosa.")
    return True

def compile_with_sanitize():
    print("Compilando con sanitizers...")
    source_files = glob.glob("*.c")  # Encuentra todos los archivos .c en el directorio actual
    if not source_files:
        print("No se encontraron archivos .c para compilar.")
        return False
    result = subprocess.run(
        ["gcc", "-Wall", "-Wextra", "-Werror", "-fsanitize=address", "-o", EXECUTABLE] + source_files,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    if result.returncode != 0:
        print("Error al compilar con sanitize:")
        print(result.stderr.decode())
        return False
    print("Compilación exitosa con sanitizers.")
    return True

# Función para ejecutar pruebas
def run_tests():
    print("Ejecutando pruebas...")
    for idx, (input_data, expected_output) in enumerate(TEST_CASES):
        try:
            # Ejecutar el programa
            process = subprocess.run(
                [EXECUTABLE, input_data],
                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
            )
            output = process.stdout
            if output == expected_output:
                print(f"Prueba {idx + 1}: ✅ Pasó")
            else:
                print(f"Prueba {idx + 1}: ❌ Falló")
            
            # Mostrar resultados esperados y obtenidos
            print(f"Entrada: {input_data}")
            print(f"Esperado:\n{expected_output}")
            print(f"Obtenido:\n{output}")
        except Exception as e:
            print(f"Prueba {idx + 1}: ❌ Error de ejecución - {e}")

# Comprobación de fugas con valgrind
def check_memory_leaks():
    print("Comprobando fugas de memoria con valgrind...")
    for idx, (input_data, _) in enumerate(TEST_CASES):
        try:
            valgrind_result = subprocess.run(
                ["valgrind", "--leak-check=full", "--error-exitcode=1", EXECUTABLE, input_data],
                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
            )
            if valgrind_result.returncode == 0:
                print(f"Prueba {idx + 1} (valgrind): ✅ Sin fugas")
            else:
                print(f"Prueba {idx + 1} (valgrind): ❌ Fugas detectadas")
                print(valgrind_result.stderr)
        except Exception as e:
            print(f"Prueba {idx + 1} (valgrind): ❌ Error de ejecución - {e}")

# Main
if __name__ == "__main__":
    # Mostrar mensaje 'rush 01' durante 3 segundos
    print(GREEN + BOLD + """
	
██████╗ ██╗   ██╗███████╗██╗  ██╗         ██████╗  ██╗    ████████╗███████╗███████╗████████╗███████╗██████╗ 
██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔═████╗███║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗
██████╔╝██║   ██║███████╗███████║        ██║██╔██║╚██║       ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝
██╔══██╗██║   ██║╚════██║██╔══██║        ████╔╝██║ ██║       ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗
██║  ██║╚██████╔╝███████║██║  ██║███████╗╚██████╔╝ ██║       ██║   ███████╗███████║   ██║   ███████╗██║  ██║
╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝ ╚═════╝  ╚═╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
                                                                                                            
                                         2024/11/12 - ismherna@student.42.fr - 42 Madrid - Ismael Hernández                                                    

	""" + RESET)
    time.sleep(1)  # Esperar 3 segundos

    mode = input(GREEN + BOLD +"Compilation Options:\n \n(1: standard, 2: Sanitize, 3: Valgrind):\n \n"+ RESET).strip()
    if mode == "1":
        if compile_program():
            run_tests()
    elif mode == "2":
        if compile_with_sanitize():
            run_tests()
    elif mode == "3":
        if compile_program():
            run_tests()
            check_memory_leaks()
    else:
        print("Opción no válida.")
